Config is for UHK userConfig v7.1.0

**$onInit:**
```
clearStatus
setVar count 0
setVar snap_running 0
// set emergencyKey $keyId.0
// set keystrokeDelay 10
set backlight.strategy constantRgb
set backlight.constantRgb.rgb 64 64 64
set leds.fadeTimeout 300
set module.trackpoint.baseSpeed 0
set module.trackpoint.speed 0.5
set module.trackpoint.xceleration 2.0
set module.touchpad.invertScrollDirectionX 1
set module.touchpad.navigationMode.mouse caret
set module.touchpad.holdContinuationTimeout 500
set module.keycluster.navigationMode.mouse caret
// set secondaryRole.defaultStrategy advanced
// set secondaryRole.advanced.timeout 250
// set secondaryRole.advanced.timeoutAction secondary
// set secondaryRole.advanced.triggerByRelease 1
// positive values for savetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +1
call hrm-init
setLedTxt 300 ':::'
```

**$onKeymapChange ---:**
```
replaceLayer mod CMX mod
replaceLayer mouse CMX mouse
replaceLayer fn CMX fn
replaceLayer fn2 CMX fn2
replaceLayer fn3 CMX fn3
replaceLayer fn4 CMX fn4
replaceLayer fn5 CMX fn5
set keymapAction.fn.isoKey macro initCMX
set keymapAction.fn.b macro Pause-or-b
fork keepAlive
```

**$onKeymapChange CMX:**
```
setVar c 20
setLedTxt 1 CMX
startloop: delayUntil 250
ifNotKeymap CMX break
repeatFor c startloop
set backlight.keyRgb.base.128 128 128 128
set backlight.keyRgb.base.129 128 128 128
set backlight.keyRgb.base.130 128 128 128
set backlight.keyRgb.mod.128 0 128 0
set backlight.keyRgb.mod.129 0 128 0
set backlight.keyRgb.mod.130 0 128 0
set backlight.keyRgb.mouse.128 0 0 0
set backlight.keyRgb.mouse.129 0 128 128
set backlight.keyRgb.mouse.130 0 128 128
set backlight.keyRgb.fn.128 255 64 32
set backlight.keyRgb.fn.129 255 64 32
set backlight.keyRgb.fn.130 255 64 32
set backlight.keyRgb.fn5.128 128 128 128
set backlight.keyRgb.fn5.129 0 0 0
set backlight.keyRgb.fn5.130 0 0 0
ifKeymap CMX setLedTxt 200 "::C"
ifKeymap CMX setLedTxt 200 ":C:"
ifKeymap CMX setLedTxt 200 "C:M"
ifKeymap CMX setLedTxt 200 ":M:"
ifKeymap CMX setLedTxt 200 "M:X"
ifKeymap CMX setLedTxt 200 ":X:"
ifKeymap CMX setLedTxt 200 ":::"
ifKeymap CMX setLedTxt 200 "::C"
ifKeymap CMX setLedTxt 200 ":CM"
ifKeymap CMX setLedTxt 200 "CMX"
ifKeymap CMX setLedTxt 300 ":::"
ifKeymap CMX setLedTxt 300 "CMX"
ifKeymap CMX setLedTxt 300 ":::"
ifKeymap CMX setLedTxt 200 "CMX"

```

**$onKeymapChange NMX:**
```
replaceLayer mod CMX mod
replaceLayer mouse CMX mouse
replaceLayer fn CMX fn
replaceLayer fn2 CMX fn2
replaceLayer fn3 CMX fn3
replaceLayer fn4 CMX fn4
replaceLayer fn5 CMX fn5
set keymapAction.fn.isoKey macro initCMX
set keymapAction.fn.slashAndQuestionMark macro initCMX
set keymapAction.fn3.isoKey macro initCMX

```

**atquote:**
```
ifGesture timeoutIn 250 $thisKeyId final tapKey S-2
ifSecondary advancedStrategy final holdLayer mod
holdKey apostropheAndQuote

```

**chordscape:**
```
setVar hrm_tick 0
ifKeyActive q {
    ifShortcut timeoutIn 100 w final holdKey escape
    else final holdKey q
}
ifKeyActive w {
    ifShortcut timeoutIn 100 q final holdKey escape
    else final holdKey w
}

```

**clearStatus:**
```
clearStatus
```

**countdown:**
```
if ( $count > 0 ) final setVar count 0
setVar count 30
loop:
setLedTxt 1000 $count
repeatFor count loop
ifLayer fn5 final setLedTxt 0 "NUM"
```

**diagnose:**
```
diagnose
unToggleLayer
unToggleLayer
unToggleLayer
stopAllMacros
```

**fn:**
```
ifShortcut timeoutIn 50 $keyId.rightSpace exec fn2-fkeys
holdLayer fn
```

**fn2-fkeys:**
```
setLedTxt 0 F12
holdLayer fn2
ifLayer fn4 final setLedTxt 0 '0-9'
setLedTxt 1 F12
```

**hrm-auto:**
```
setVar hrm_active 1
setVar hrm_timer_active 0
setVar hrm_tick 0
setVar hrm_tick_delay 10
setVar hrm_tick_active 10
setVar hrm_avoid_same 100
overlayLayer base HRM mod
setLedTxt 666 'H+-'
if ($hrm_timer_active == 0) fork hrm-timer

```

**hrm-b:**
```
setVar hrm_tick 0
holdKey b

```

**hrm-c:**
```
setVar hrm_tick 0
holdKey c

```

**hrm-e:**
```
setVar hrm_tick 0
holdKey e

```

**hrm-i:**
```
setVar hrm_tick 0
holdKey i

```

**hrm-init:**
```
setLedTxt 666 'H-I'
exec hrm-auto

```

**hrm-LA-;:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume y u i o p h j k l semicolonAndColon n m commaAndLessThanSign dotAndGreaterThanSign goTo primary
if ($hrm_active > 0) ifSecondary final holdKey leftAlt
primary:
setVar hrm_tick 0
holdKey semicolonAndColon

```

**hrm-LA-a:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume q w e r t a s d f g z x c v b goTo primary
if ($hrm_active > 0) ifSecondary final holdKey leftAlt
primary:
setVar hrm_tick 0
holdKey a

```

**hrm-LC-f:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume q w e r t a s d f g z x c v b goTo primary
if ($hrm_active > 0) ifSecondary final holdKey leftControl
primary:
setVar hrm_tick 0
holdKey f

```

**hrm-LG-g:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume q w e r t a s d f g z x c v b goTo primary
if ($hrm_active > 0) ifSecondary final holdKey leftGui
primary:
setVar hrm_tick 0
holdKey g

```

**hrm-LS-d:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume q w e r t a s d f g z x c v b goTo primary
if ($hrm_active > 0) ifSecondary final holdKey leftShift
primary:
setVar hrm_tick 0
holdKey d

```

**hrm-m:**
```
setVar hrm_tick 0
holdKey m

```

**hrm-n:**
```
setVar hrm_tick 0
holdKey n

```

**hrm-o:**
```
setVar hrm_tick 0
holdKey o

```

**hrm-off:**
```
setVar hrm_timer_active 0
setVar hrm_active 0
setVar hrm_avoid_same 50
overlayLayer base HRM base
setLedTxt 666 'H--'
```

**hrm-on:**
```
setVar hrm_timer_active 0
setVar hrm_active 1
setVar hrm_avoid_same 50
overlayLayer base HRM mod
setLedTxt 666 'H++'
```

**hrm-p:**
```
setVar hrm_tick 0
holdKey p

```

**hrm-q:**
```
setVar hrm_tick 0
holdKey q

```

**hrm-r:**
```
setVar hrm_tick 0
holdKey r

```

**hrm-RA-/:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume y u i o p h j k l semicolonAndColon n m commaAndLessThanSign dotAndGreaterThanSign goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightAlt
primary:
setVar hrm_tick 0
holdKey slashAndQuestionMark

```

**hrm-RA-ISO:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume q w e r t a s d f g z x c v b goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightAlt
primary:
setVar hrm_tick 0
holdKey backslashAndPipeIso

```

**hrm-RA-l:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume y u i o p h j k l semicolonAndColon n m commaAndLessThanSign dotAndGreaterThanSign goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightAlt
primary:
setVar hrm_tick 0
holdKey l

```

**hrm-RA-s:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume q w e r t a s d f g z x c v b goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightAlt
primary:
setVar hrm_tick 0
holdKey s

```

**hrm-RC-j:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume y u i o p h j k l semicolonAndColon n m commaAndLessThanSign dotAndGreaterThanSign goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightControl
primary:
setVar hrm_tick 0
holdKey j

```

**hrm-RG-h:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume y u i o p h j k l semicolonAndColon n m commaAndLessThanSign dotAndGreaterThanSign goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightGui
primary:
setVar hrm_tick 0
holdKey h

```

**hrm-RS-k:**
```
ifShortcut timeoutIn $hrm_avoid_same orGate noConsume y u i o p h j k l semicolonAndColon n m commaAndLessThanSign dotAndGreaterThanSign goTo primary
if ($hrm_active > 0) ifSecondary final holdKey rightShift
primary:
setVar hrm_tick 0
holdKey k

```

**hrm-t:**
```
setVar hrm_tick 0
holdKey t

```

**hrm-timer:**
```
setVar hrm_timer_active 1
setVar hrm_active_state $hrm_active
setLedTxt 800 '+T+'
// if tick is < tick_active, hrm should be inactive
// if tick is >= tick_active, hrm should be active
// primary key activations will reset tick => fast typing streak keeps hrm inactive
loop:
    setVar hrm_tick ($hrm_tick + 1)
    // setLedTxt 0 "T$hrm_tick"
    if ($hrm_active > 0) { // if hrm are active and we are in the pause interval, deactivate hrm
        if ($hrm_tick < $hrm_tick_active) setVar hrm_active 0
    }
    else {  // if not active and no primary has been activated for more than 30 ms, activate hrm
        if ($hrm_tick >= $hrm_tick_active) setVar hrm_active 1
    }
    // the next section is just about showing state changes on LED display
    if ($hrm_active_state == 0) {
        if ($hrm_active > 0) {
            setLedTxt 0 'H++'
            setVar hrm_active_state 1
        }
    }
    else {
        if ($hrm_active == 0) {
            setLedTxt 0 'H--'
            setVar hrm_active_state 0
        }
    }
    // --- ^^^ ---
    if ($hrm_tick == 500) ifLayer base setLedTxt 0 'H+-'
    if ($hrm_tick == 1000) ifLayer base setLedTxt 1 'H+-'
    if ($hrm_tick >= 1500) setVar hrm_tick 499
    else delayUntil $hrm_tick_delay
    ifKeymap NMX setVar hrm_timer_active 0 // emergency break out
if ($hrm_timer_active > 0) goTo loop
delayUntil 777
setLedTxt 800 '-T-'
```

**hrm-u:**
```
setVar hrm_tick 0
holdKey u

```

**hrm-v:**
```
setVar hrm_tick 0
holdKey v

```

**hrm-w:**
```
setVar hrm_tick 0
holdKey w

```

**hrm-x:**
```
setVar hrm_tick 0
holdKey x

```

**hrm-y:**
```
setVar hrm_tick 0
holdKey y

```

**hrm-z:**
```
setVar hrm_tick 0
holdKey z

```

**initCMX:**
```
switchKeymap CMX
```

**keepAlive:**
```
setVar count 6
startloop:
ifKeymap --- setLedTxt 200 "`-'"
ifKeymap --- setLedTxt 200 "---"
ifKeymap --- repeatFor count startloop
clearStatus
```
```
keepalive:
```
> moveMouse ...
```
ifNotKeymap --- goTo final
ifKeymap --- setLedTxt 200 "---"
ifLayer mod goTo modLayerPt1
ifLayer fn5 goTo numLayerPt1
ifKeymap --- setLedTxt 200 "}--"
ifKeymap --- setLedTxt 200 "-}-"
ifKeymap --- setLedTxt 200 "--}"
goTo numLayerPt1End
numLayerPt1:
ifKeymap --- setLedTxt 200 "1--"
ifKeymap --- setLedTxt 200 "-2-"
ifKeymap --- setLedTxt 200 "--3"
goTo numLayerPt1End
modLayerPt1:
ifKeymap --- setLedTxt 200 "M--"
ifKeymap --- setLedTxt 200 "-A-"
ifKeymap --- setLedTxt 200 "--X"
numLayerPt1End:
```
> moveMouse ...
```
ifNotKeymap --- goTo final
```
> delay ...
> moveMouse ...
```
ifNotKeymap --- goTo final
ifKeymap --- setLedTxt 200 "---"
ifLayer mod goTo modLayerPt2
ifLayer fn5 goTo numLayerPt2
ifKeymap --- setLedTxt 200 "--{"
ifKeymap --- setLedTxt 200 "-{-"
ifKeymap --- setLedTxt 200 "{--"
goTo endPt2
numLayerPt2:
ifKeymap --- setLedTxt 200 "--3"
ifKeymap --- setLedTxt 200 "-2-"
ifKeymap --- setLedTxt 200 "1--"
goTo endPt2
modLayerPt2:
ifKeymap --- setLedTxt 200 "--X"
ifKeymap --- setLedTxt 200 "-A-"
ifKeymap --- setLedTxt 200 "M--"
endPt2:
```
> moveMouse ...
```
ifNotKeymap --- goTo final
```
> delay ...
```
ifKeymap --- goTo keepalive

```
```
final: 
setLedTxt 800 "[-]"
setLedTxt 200 "[\\]"
setLedTxt 200 "[|]"
setLedTxt 200 "[/]"
setLedTxt 200 "[-]"
setLedTxt 200 "[\\]"
setLedTxt 200 "[|]"
setLedTxt 200 "[/]"
setLedTxt 200 "[-]"
setLedTxt 200 "[*]"
setLedTxt 200 "|_|"

```

**keytest:**
```
setLedTxt 0 'KEY'
ifGesture timeoutIn 200 $thisKeyId final setLedTxt 999 'GST'
ifDoubletap final setLedTxt 999 'DBL'
delayUntilReleaseMax 500
ifInterrupted final setLedTxt 999 '2ND'
ifPlaytime 450 final setLedTxt 999 'HLD'
setLedTxt 999 'TAP'
#tapKey backslashAndPipe
#write Sheet #1
#tapKey enter
#write Sheet \1
#tapKey enter
#write Dhkkf \\1
#tapKey enter

```

**maxtend:**
```
ifDoubletap goTo doubleMaxtend
ifLayer fn goTo altMaxtend
ifShift goTo shiftMaxtend
ifAlt goTo altMaxtend
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
tapKey backspace
setLedTxt 500 "<--"
ifLayer fn5 final setLedTxt 0 "NUM"
break

secondaryaction:
setLedTxt 0 "MAX"
holdLayer mod
ifLayer fn5 final setLedTxt 0 "NUM"
setLedTxt 1 "MAX"
break

doubleMaxtend:
fork maxtend_showbackspace
shiftMaxtend:
setLedTxt 0 "<--"
suppressMods holdKey backspace
ifNotPlaytime 300 setLedTxt 300 "<--"
ifLayer fn5 final setLedTxt 0 "NUM"
setLedTxt 1 "<--"
break

altMaxtend:
setLedTxt 0 "DEL"
suppressMods holdKey delete
ifNotPlaytime 300 setLedTxt 300 "DEL"
ifLayer fn5 final setLedTxt 0 "NUM"
setLedTxt 1 "DEL"
break
```

**maxtend_showbackspace:**
```
setLedTxt 450 "<--"
ifReleased break
setLedTxt 0 "<<-"
```

**mousetend:**
```
ifDoubletap final holdKey space
ifSecondary goTo secondaryaction
primaryaction: final tapKey space
secondaryaction: 
setLedTxt 0 MSE
holdLayer mouse
setLedTxt 200 "MSE"
setLedTxt 200 "---"
setLedTxt 200 "___"
setLedTxt 300 ":::"
ifLayer fn5 final setLedTxt 0 "NUM"
```

**mute-unmute:**
```
ifSecondary final suppressMods holdKey LC-space
suppressMods tapKey LCLS-m
ifNotShift break
delayUntil 600
suppressMods tapKey LCLS-semicolonAndColon // CS-o on Colemak host
```

**nextKeyID:**
```
resolveNextKeyId
```

**numspace:**
```
#ifDoubletap final holdKey space
ifSecondary goTo secondaryaction
primaryaction: final holdKey space
secondaryaction:
setLedTxt 0 '0-9'
holdLayer fn4
ifLayer fn5 final setLedTxt 0 "NUM"
setLedTxt 1 '0-9'

```

**numtab:**
```
ifDoubletap final holdKey tab
ifAlt final holdKey tab
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
ifShift goTo shiftTab
tapKey tab
setLedTxt 500 "->|"
ifLayer fn5 final setLedTxt 0 "NUM"
break

secondaryaction:
ifShift goTo shiftTabSecondary
setLedTxt 0 "NUM"
holdLayer fn5
delayUntil 100
ifLayer fn5 final setLedTxt 0 "NUM"
setLedTxt 1 "NUM"
break

shiftTabSecondary:
setLedTxt 0 "NUM"
ifNotLayer fn5 final toggleLayer fn5
unToggleLayer
setLedTxt 1 "NUM"
break

shiftTab:
setLedTxt 0 "|<-"
holdKey tab
setLedTxt 500 "|<-"
ifLayer fn5 final setLedTxt 0 "NUM"
break

```

**numtab3:**
```
ifAlt final holdKey tab
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
ifShift goTo shiftTab
tapKey tab
setLedTxt 500 "->|"
ifLayer fn3 final setLedTxt 0 "123"
break

secondaryaction:
ifShift goTo shiftTabSecondary
setLedTxt 0 "123"
holdLayer fn3
delayUntil 100
ifLayer fn3 final setLedTxt 0 "123"
setLedTxt 1 "123"
break

shiftTabSecondary:
setLedTxt 0 "123"
ifNotLayer fn3 final toggleLayer fn3
unToggleLayer
setLedTxt 1 "123"
break

shiftTab:
setLedTxt 0 "|<-"
holdKey tab
setLedTxt 500 "|<-"
ifLayer fn3 final setLedTxt 0 "123"
break
```

**numthumb:**
```
setLedTxt 0 '123'
holdLayer fn3
setLedTxt 1 '123'
```

**Pause-or-b:**
```
ifKeyActive $keyId.leftFn final {
    ifKeymap --- switchKeymap CMX
    else switchKeymap ---
}
holdKey b

```

**printstatus:**
```
printStatus
```

**run_once:**
```
if ($has_run == 0) {
    setVar has_run 1
    setLedTxt 999 '1ST'
}
else {
    setLedTxt 999 '2+'
}

```

**safetyMargin-down:**
```
setVar safetyMargin ($safetyMargin - 5)
set secondaryRole.advanced.safetyMargin $safetyMargin
if ( $safetyMargin < 0 ) final setLedTxt 500 "$safetyMargin"
setLedTxt 500 "+$safetyMargin"
```

**safetyMargin-up:**
```
setVar safetyMargin ($safetyMargin + 5)
set secondaryRole.advanced.safetyMargin $safetyMargin
if ( $safetyMargin < 0 ) final setLedTxt 500 "$safetyMargin"
setLedTxt 500 "+$safetyMargin"
```

**snap-leftright:**
```
if ($thisKeyId == $keyId.j) setVar snap_mode 1
else if ($thisKeyId == $keyId.l) setVar snap_mode 2
else setVar snap_mode 0
if ($snap_running == 0) fork snap-leftright-worker
delayUntilRelease
ifKeyActive $keyId.j final setVar snap_mode 1
ifKeyActive $keyId.l final setVar snap_mode 2
setVar snap_mode 0
```

**snap-leftright-worker:**
```
setVar snap_running 1
setVar snap_state 0
setLedTxt 0 '<->'
// snap_state: current state of left/right movement
// snap_mode: target state of left/right movement
// The worker will send key press/release actions to move
// the current state to the target state.
loop:
if ($snap_state == 0) {
    if ($snap_mode == 1) {
        releaseKey right
        pressKey left
    }
    else if ($snap_mode == 2) {
        releaseKey left
        pressKey right
    }
}
else if ($snap_state == 1) {
    if ($snap_mode == 0) {
        releaseKey left
        releaseKey right
    }
    else if ($snap_mode == 2) {
        releaseKey left
        pressKey right
    }
}
else if ($snap_state == 2) {
    if ($snap_mode == 0) {
        releaseKey right
        releaseKey left
    }
    else if ($snap_mode == 1) {
        releaseKey right
        pressKey left
    }
}
setVar snap_state $snap_mode
if ($snap_mode != 0) goTo loop
ifNotPlaytime 5000 goTo loop
setVar snap_running 0
setLedTxt 1 '<->'

```

**spaceback:**
```
setLedTxt 1 'CMX'
// switchKeymap CMX
untoggleLayer
holdKey space
```

**spacetapper:**
```
setLedTxt 500 'SPC'
loop:
delayUntil 4000
ifInterrupted final setLedTxt 1500 'OFF'
tapKey space
setLedTxt 1000 'SPC'
goTo loop

```

**test-enter-return:**
```
tapKeySeq 1 a b c return return d e f space
delayUntil 999
tapKey return
delayUntil 2000
tapKeySeq 2 a b c enter enter d e f space
delayUntil 999
tapKey enter
delayUntil 2000
tapKeySeq 3 a b c keypadEnter keypadEnter d e f space
delayUntil 999
tapKey keypadEnter
delayUntil 2000
tapKeySeq d o n e dotAndGreaterThanSign
```

**xtend-xecute:**
```
ifGesture timeoutIn 1500 a final setLedTxt 666 'X-A'
ifGesture timeoutIn 1500 b final setLedTxt 666 'X-B'
ifGesture timeoutIn 1500 c 1 final setLedTxt 666 'XC1'
ifGesture timeoutIn 1500 c 2 final setLedTxt 666 'XC2'
ifGesture timeoutIn 1500 noConsume orGate j k l u i o 7 8 9 m final {
    //switchKeymap NMX
    toggleLayer fn5
    set keymapAction.fn5.leftSpace macro spaceback
    set keymapAction.fn5.rightSpace macro spaceback
    setLedTxt 0 '1NM'
}
ifGesture timeoutIn 1500 k final tapKey x
ifGesture timeoutIn 1500 orGate l final tapKey y
setLedTxt 666 'NON'

```

