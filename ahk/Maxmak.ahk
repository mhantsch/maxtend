;
; Copyright (C) 2017-2023 Maximilian Hantsch
; Released under CC BY 4.0 Licence. See https://creativecommons.org/licenses/by/4.0/
;

; This AHK script will enrich a base Colemak keymap with additional Meta functions.
; Meta keymap triggered by holding CapsLock (Colemak Backspace) key.
;
; Please note that you need a Colemak keymap as a base for this AHK script.
; (There are Colemak keyboard drivers available that you need to install separately.)
;

; Short summary:
; - A short press and release of CapsLock will work as Backspace, as in original Colemak.
; - Holding CapsLock together with other keys works as an additional Function layer.
; - Holding Tab, switching on ScrollLock, or toggling with CapsLock+Tab will enable a virtual number pad.
; - [not implemented] The Space key together with other keys also works as an additonal layer (like CapsLock).
; - [not implemented] Holding both CapsLock & Space together with other keys triggers an additional Meta layer.
;
; See below for the exact maps for each layer.
;
; More details:
;
; (1) FUNCTION layer
; Keeping CapsLock held down in combination with other keys works as an additional layer
; (Think: CapsLock held down = FUNCTION layer).
; As soon as a second key has been pressed while CapsLock is held down, or when CapsLock
; has been held down for more than half a second, releasing CapsLock will not Backspace.
; (In the case of CapsLock being held down longer without any other key pressed, a short
; high-pitch beep will sound, or the screen will flash briefly, reminding the user that 
; Backspace will not be triggered.)
;
; (2) NUMBER pad
; Holding down Tab, active ScrollLock, or use CapsLock+Tab to turn the keys below 7-8-9 
; into a number pad. (Think: hold Tab for NUMPAD, CapsLock+Tab toggles NUMPAD). 
; Useful for keyboards without numpad.
; If you have a TKL keyboard with cursor keys and Print/ScrLock/Pause/Ins/Del/Home/End/PgUp/PgDn
; keys, those will emulate a number pad too in this mode.
;
; (3) SPACE layer - experimental and disabled by default
; Similar to the FUNCTION layer, there are extra combinations available if the SPACE key
; is held down while other keys are pressed.
; Quickly pressing and releasing SPACE will work normally. Holding SPACE without other keys
; will auto-repeat.
;
; (4) META layer - not implemented yet
; Holding down CapsLock + Space triggers an additional META layer, offering even more 
; shortcuts and special functions.
;
;
; Colemak (base layer):
; q    w    f    p    g    j    l    u    y    ;
;  a    r    s    t    d    h    n    e    i    o
;   z    x    c    v    b    k    m    ,    .    /
;
; Function layer (CapsLock held):
; ESC  WlUp Back Fwd  g    PgUp Home Up   End  Del
;  Ctrl WlDn Shft Alt  d    PgDn Left Down Rght BkSp Ins
;   C-Z  C-X  C-C  C-V  b    k    m    ,    .    /
;
; The Function layer will also map CapsLock + number keys to F1-F12. Useful for 60% keyboards
; (keyboards without a function key row).
;
; Number layer (CapsLock+Tab held):
; ESC  WlUp Back Fwd  g    PgUp 4    5    6    Del
;  Ctrl WlDn Shft Alt  d    PgDn 1    2    3    BkSp Ins
;   C-Z  C-X  C-C  C-V  b    k    0    ,    .    /
;
; Number layer (ScrollLock on):
; q    w    f    p    g    j    4    5    6    ;
;  a    r    s    t    d    h    1    2    3    o
;   z    x    c    v    b    k    0    ,    .    /
; 
; Space layer (Space held):
; ESC  WlUp Back Fwd  g    PgUp Home Up   End  Del
;  Ctrl WlDn Shft Alt  d    PgDn Left Down Rght BkSp Ins
;   C-Z  C-X  C-C  C-V  b    k    m    ,    .    /
;
; Number layer - additional mappings (for TKL keyboards):
; PrSc ScLk Paus   =>   7    8    9
; Ins  Home PgUp   =>   4    5    6
; Del  End  PgDn   =>   1    2    3
;      Up          =>        -
; Left Down Right  =>   0    ,    .

#SingleInstance Force
#InstallKeybdHook
#NoEnv

global ShiftStates := Object()
global isSuperLargeScreen := false

Return

;
; Base handling of the CapsLock key to enable FUNCTION and META layers
;
; Pressing and releasing within 0.5s will produce a Backspace.
; Holding down and pressing another key will trigger the FUNCTION layer.
; Holding down for more than 0.5s and then releasing without another key 
; press will result in no action. A brief flash of the screen will signal 
; that the Backspace has been cancelled. (Alternatively the signal can 
; be changed to a high-pitched short beep or a tray tip in the code below.)
;

!SC03A::SendInput, {Del}

;SC03A down::
SC03A::
	HadTimeout := 0
	CombinedSequenceTriggered := 0
	KeyWait, SC03A, T0.5
	If ( ErrorLevel = 1 ) {
		If ( CombinedSequenceTriggered = 0) {
			;-- indicate timeout with high-pitched short beep
			;SoundBeep 8800, 10
			;-- indicate timeout with a Tray Tip (quite annoying)
			;TrayTip, , Backspace reached timeout - now in Meta Mode.`n%TheWindowTitle%, 2, 17
			;-- indicate timeout with a screen flash
			;SplashImage,,B w%A_ScreenWidth% h%A_ScreenHeight% cwBlack NA
			SplashImage,,B w%A_ScreenWidth% h%A_ScreenHeight% cwSilver
			Sleep,50
			SplashImage,off
			;-- end of choices
		}
		;TrayTip, Meta Key, The keyboard is now in Meta mode., 11, 17
		HadTimeout := 1
		KeyWait, SC03A
	}
	If ( HadTimeout = 0 and CombinedSequenceTriggered = 0 ) {
		Send, {Backspace}
	}
Return

SC03A up::
	ForgetShiftStates()
Return

;
; NUMPAD (NUMBER layer) handling
;

global NumSequenceTriggered := 0

Tab::
	Numlayer := 1
	NumSequenceTriggered := 0
Return

Tab up::
	if( NumSequenceTriggered = 0 ) {
		Send, {Tab}
	}
	Numlayer := 0
Return

SendNum(key) {
	NumSequenceTriggered := 1
	SendInput, %key%
}

#if 0
;
; Space layer:
;
; This is tricky because space is often used together with n-key rollover
; in which case we don't want to trigger the combined sequences!
; So, after we detect Space we wait a short moment before we allow
; combined sequences. But if we don't register a combined sequences
; within a reasonable amount of 0.5 seconds, then we switch to autorepeat.
;
Space::
	HadTimeout := 0
	CombinedSequenceTriggered := 0
	KeyWait, Space, T0.1
	If ( ErrorLevel = 1 ) {
		; timeout 1 - Space was held down for more than 0.1 seconds
		AllowSpaceCombinations := 1
		KeyWait, Space, T0.4
		If ( ErrorLevel = 1 ) {
			; timeout 2 - Space was held down for more than 0.5 seconds
			If ( CombinedSequenceTriggered = 0) {
				While GetKeyState("Space", "P") {
					SendInput, {Space}
					Sleep 25
					;Send, {Space}
				}
			}
			;TrayTip, Meta Key, The keyboard is now in Meta mode., 11, 17
			HadTimeout := 1
			KeyWait, Space
		}
	}
	If ( HadTimeout = 0 and CombinedSequenceTriggered = 0 ) {
		Send, {Space}
	}
Return

Space up::
	AllowSpaceCombinations := 0
	ForgetShiftStates()
Return
#if


ForgetShiftStates() {
	ShiftStates := Object()
}

IsKeyInShiftStates(key) {
	return ShiftStates.HasKey(key)
}

RememberShiftState(key) {
	ShiftStates[key]:=1
}

ForgetShiftState(key) {
	ShiftStates.Delete(key)
}

IsShift() {
	return ( GetKeyState("Shift") or IsKeyInShiftStates("shft") )
}

IsCtrl() {
	return ( GetKeyState("Ctrl") or IsKeyInShiftStates("ctrl") )
}

IsAlt() {
	return ( GetKeyState("Alt") or IsKeyInShiftStates("alt") )
}

; send a key with any modifiers (Ctrl/Shift/Alt) or as a number (NumLock Mode)
;
MetaSend2(sendstring, num) {
	global CombinedSequenceTriggered := 1
	Modifiers := ( IsShift() ? "+" : "" )
		. ( IsCtrl() ? "^" : "" )
		. ( IsAlt() ? "!" : "" )
	If ( GetKeyState("ScrollLock", "T") ) {
		Send, %Modifiers%%num%
	} Else {
		Send, %Modifiers%%sendstring%
	}
}

MetaSend(sendstring) {
	MetaSend2(sendstring, sendstring)
}

; It should be possible to modify this script for various International or Dvorak keyboards
; (base mappings) by changing the mappings below.

~SC03A & a::RememberShiftState("alt")
;~a::RememberShiftState("alt")
~a up::ForgetShiftState("alt")
~SC03A & s::RememberShiftState("shft")
;~s::RememberShiftState("shft")
~s up::ForgetShiftState("shft")
~SC03A & t::RememberShiftState("ctrl")
;~t::RememberShiftState("ctrl")
~t up::ForgetShiftState("ctrl")

; Turn NUMBER layer on/off
~SC03A & Tab::
	global CombinedSequenceTriggered = 1
	if (GetKeyState("Scrolllock","T")) {
		SetScrollLockState, Off
	} else {
		SetScrollLockState, On
	}
Return

~SC03A & ScrollLock::MetaSend("{ScrollLock}")

; ~!SC03A::MetaSend("{Delete}")

; List of NUMBER layer functions
;
#If GetKeyState("Scrolllock","T")
m::0
n::1
e::2
i::3
l::4
u::5
y::6
Delete::1
End::2
PgDn::3
Ins::4
Home::5
PgUp::6
PrintScreen::7
ScrollLock::8
Pause::9
Left::0
Down::,
Right::.
Up::-
o::+
`;::-
h::*
j::/
#If

~Tab & m::SendNum("0")
~Tab & n::SendNum("1")
~Tab & e::SendNum("2")
~Tab & i::SendNum("3")
~Tab & l::SendNum("4")
~Tab & u::SendNum("5")
~Tab & y::SendNum("6")
~Tab & 7::SendNum("7")
~Tab & 8::SendNum("8")
~Tab & 9::SendNum("9")
~Tab & 0::SendNum("0")
~Tab & o::SendNum("{+}")
~Tab & `;::SendNum("-")
~Tab & h::SendNum("*")
~Tab & j::SendNum("/")

; List of FUNCTION layer functions
;
#if not GetKeyState("Space","p")
~SC03A & q::MetaSend("{Escape}")
~SC03A & f::MetaSend("{Browser_Back}")
~SC03A & p::MetaSend("{Browser_Forward}")
~SC03A & l::MetaSend("{Home}")
~SC03A & u::MetaSend("{Up}")
~SC03A & y::MetaSend("{End}")
~SC03A & n::MetaSend("{Left}")
~SC03A & e::MetaSend("{Down}")
~SC03A & i::MetaSend("{Right}")
~SC03A & j::MetaSend("{PgUp}")
~SC03A & h::MetaSend("{PgDn}")
~SC03A & `;::MetaSend("{Delete}")
~SC03A & '::MetaSend("{Insert}")
~SC03A & o::MetaSend("{Backspace}")
~SC03A & w::MetaSend("{WheelDown}")
~SC03A & r::MetaSend("{WheelUp}")
~SC03A & g::MouseMove, 0, IsShift() ? -2 : -30, ,R
~SC03A & d::MouseMove, 0, IsShift() ? 2 : 30, ,R
~SC03A & z::MetaSend("^z")
~SC03A & x::MetaSend("^x")
~SC03A & c::MetaSend("^c")
~SC03A & v::MetaSend("^v")
~SC03A & b::MetaSend("{Click}")
~SC03A & k::MetaSend("{Click Middle}")
~SC03A & m::MetaSend2("{Click Right}","0")
; ~SC03A & ,::MetaSend2(",",",")
; ~SC03A & .::MetaSend2(".",".")
#If
#If not GetKeyState("Scrolllock", "T")
~SC03A & ,::MouseMove, IsShift() ? -2 : -30, 0, ,R
~SC03A & .::MouseMove, IsShift() ? 2 : 30, 0, ,R
#If

;
; META layer extensions (CapsLock & Space held down); 
;
#if GetKeyState("Space","p")
;
; Make sure that CapsLock+Space does not send a Space.
~SC03A & Space::return
;
; List of META layer functions
;
#if
#if 0
~SC03A & q::MetaSend("{Escape}")
~SC03A & w::MetaSend("^w")
~SC03A & f::MetaSend("PgUp ")
~SC03A & p::MetaSend("PgDn ")
~SC03A & g::MetaSend("^t")
~SC03A & c::MetaSend("ceh ")
~SC03A & v::MetaSend("vau ")
;
#if

#if 0
;
; SPACE layer extensions
;
; This is tricky because space is often typed together with n-key rollover
; in which case we don't want to trigger the combined sequences!
;
~Space & q::MetaSend("{Escape}")
~Space & f::MetaSend("{Browser_Back}")
~Space & p::MetaSend("{Browser_Forward}")
~Space & l::MetaSend2("{Home}","4")
~Space & u::MetaSend2("{Up}","5")
~Space & y::MetaSend2("{End}","6")
~Space & n::MetaSend2("{Left}","1")
~Space & e::MetaSend2("{Down}","2")
~Space & i::MetaSend2("{Right}","3")
~Space & j::MetaSend("{PgUp}")
~Space & h::MetaSend("{PgDn}")
~Space & `;::MetaSend("{Delete}")
~Space & '::MetaSend("{Insert}")
~Space & o::MetaSend("{Backspace}")
~Space & w::MetaSend("{WheelUp}")
~Space & r::MetaSend("{WheelDown}")
#if

~SC03A & 1::MetaSend2("{F1}","1")
~SC03A & 2::MetaSend2("{F2}","2")
~SC03A & 3::MetaSend2("{F3}","3")
~SC03A & 4::MetaSend2("{F4}","4")
~SC03A & 5::MetaSend2("{F5}","5")
~SC03A & 6::MetaSend2("{F6}","6")
~SC03A & 7::MetaSend2("{F7}","7")
~SC03A & 8::MetaSend2("{F8}","8")
~SC03A & 9::MetaSend2("{F9}","9")
~SC03A & 0::MetaSend2("{F10}","0")
~SC03A & -::MetaSend("{F11}")
~SC03A & =::MetaSend("{F12}")

;
; --- end of Colemak meta functions ahk script ---

;
; Toggle 'mic mute' in the new Microsoft Teams
; (which does not support universal mic mute functionality of Windows 10/11).
; Press Ctrl-Shift-M to activate the Teams window (bringing it to foreground)
; and toggle the mic mute.
;

^+m::
{
   WinActivate, ahk_class TeamsWebView
   WinWait, ahk_class TeamsWebView
   if ( ErrorLevel=0 ) {
      Send ^+m
   }
;    ControlSend , ahk_class TeamsWebView, ^+m, 
}
