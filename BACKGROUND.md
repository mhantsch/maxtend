## Intro
Some years ago, I decided to switch my keyboard layout to [Colemak](https://colemak.org), and re-learn my typing. I was decent at touch-typing qwerty, but I decided my typing experience could be better. Thus, the rabbit hole of keyboard layouts, mechanical keyboards, and keyboard layers. I also switched to ten-key-less (TKL) and 60% keyboards, adding the need for layers (navigation, numpad).

This repository contains various configurations and tooling that I have used to create my setup for both Windows and Linux, and also my configuration for the [Ultimate Hacking Keyboard](https://ultimatehackingkeyboard.com).

### Credits & Inspiration
- [The inventor of Colemak, shai coleman](https://colemak.com).
- [DreymaR and his Big Bag of Keyboard Tricks](https://dreymar.colemak.org/).

## The Goal
* Typing on standard Colemak layout including international symbols (via AltGr combinations)
* An extend layer (called `maxtend`) closely resembling DreymaR's `extend` layer
* Easy installation and as much as possible identical functionality across
  - Windows (without or with installation of additional tools)
  - Linux (without or with installation of additional tools)
  - Other computers which do not or cannot have additional tools installed (using an external programmable keyboard)

These setups need to be compatible with each other, i.e. a machine already setup (without or with additional tools) should work the same way with and without the external programmable keyboard. The added functionality between keyboard and host setup must not cause conflicts. A machine not setup should also work with the external keyboard, and will gain the extended functionality.

Why this flexibility? Imagine you are used to a specific keyboard layout including extended functionality. You work on several computers, sometimes on Windows, sometimes on Linux, sometimes on an external keyboard, and sometimes on the internal keyboard of a laptop. You will want that layout to be identical across all these setups. On computers where your layout and your extended layers are installed, you can work without an external keyboard, but it will not hurt to also use one. On computers where your setup has not been installed, the external keyboard will give you the full functionality.

## Staged Setup
The configuration is setup in three stages:
1. base OS setup - giving a standard Colemak layout without extended functionality
2. maxtend layer - giving extended functionality such as navigation, mouse scrolling etc.
3. external keyboard - giving extended functionality even if your host computer does not have `maxtend` installed
These stages can work independently, but also combine on top of each other for best functionality.

### OS setup
A Colemak layout. With this step, your keyboard will be colemak (including multilingual characters, but no other special layers). This is the base for the subsequent maps in AutoHotKey, xkb, keyd, and the UHK.

#### Linux
This is available out of the box in all distributions. Just select US Colemak as your layout.

#### Windows
This requires installation of an additional [Colemak keyboard layout](https://colemak.com/Windows). I recommend [a version that remaps Caps Lock to Backspace](https://forum.colemak.com/topic/1621-colemak-for-windows-with-capslock-to-backspace/).

On Windows 10 or later, install the ‘en’ version, not the ‘co’ version. It will remap the CapsLock to backspace, and install a generic Colemak layout (including AltGr layer for multilingual characters). After installation, make sure you configure the Colemak keyboard in the Language options for your language, and then select it in the language toolbar.

![image](https://github.com/mhantsch/maxtend/assets/591785/0d160419-8be4-4351-b54d-f350c7eb4ae9)
![image](https://github.com/mhantsch/maxtend/assets/591785/ddbcd435-5e2e-489a-9d0b-fbe39b8a3378)

This is the keymap you should now have:
![image](https://github.com/mhantsch/maxtend/assets/591785/71e4b0b3-5269-4c73-b54a-581b075aa8ec)

The right-hand side symbols show what the key will produce when pressed with AltGr.

Note that this keymap also has several dead keys:
* AltGr-r is ` – to give letters like à è ò etc.
* AltGr-t is ´ – to give letters like á é ó etc.
* AltGr-d is ¨ – to give letters such as ä ö ü ÿ etc.
* AltGr-h is ˇ – to give letters such as ǎ ǔ č ť š ř etc.
* AltGr-x is ^ – to give letters such as ĉ â û ŷ etc.
* AltGr-b is ˘ – to give letters such as ă ŭ ĕ etc.
* AltGr-k is ˚ – to give letters such as å ů ẙ etc.
* AltGr-m is ¯ – to give letters such as ā ō ū ȳ ḡ etc.
* AltGr-, is ¸ – to give letters such as ç ş ţ ģ ļ ŗ ḑ ḩ ņ ȩ ķ etc.
* AltGr-\ is * – to give letters such as ¶ ™ © ® № µ etc.

More information on multilingual support in the Colemak keymap: https://colemak.com/Multilingual

### Maxtend Layer

#### AutoHotKey keymap (Windows)
Install AutoHotKey from https://autohotkey.com/download/. It’s free.

Load the AutoHotKey script from the [ahk/](ahk) folder; it will add the `maxtend` layer (called FUNCTION layer) and a NUMPAD. Please note that the FUNCTION layer is very similar to DreymaR’s “Extend” layer from https://forum.colemak.com/topic/2014-extend-extra-extreme/ with only a few twists.

The script is designed to work on a colemak base layout (as configured in the previous step).

After activation of the AutoHotKey script, you have the colemak layout from the base keyboard plus the FUNCTION layer and the NUMPAD. This will work independent of your physical (hardware) keyboard; so for example, it works on the built-in keyboard on my Windows laptop, or any external keyboard.

#### xkb (Linux)
This is my first variant for Linux, similar to DreymaR's `extend` xkb configuration with some improvements. Unfortunately, xkb is really not good at user-level extensions, so you will have to modify system files. I do not recommend this variant; it has been superceded by keyd.

#### keyd (Linux)
This is the recommended variant for Linux.

### External Keyboard
Gain the functionality of `maxtend` - and even more - without any of ahk, xkb, or keyd by typing on an external keyboard.

#### Ultimate Hacking Keyboard
The Ultimate Hacking Keyboard (UHK, see https://ultimatehackingkeyboard.com/) offers layers and configurability. I have modified the base keymaps that come with the UHK to resemble the layers from the AutoHotKey script. In addition, the UHK offers mouse control.

Download the UHK configuration from the [uhk/](uhk) folder, import it into Agent, and save it to your UHK keyboard.

This maps the Mod layer of the UHK to the secondary action of the CapsLock (“Mouse”) key, and maps the Mouse layer of the UHK to the secondary action of the Left Space (“Mod”) key.

This allows you to use the FUNCTION and NUMPAD layers anywhere where you cannot run AutoHotKey (or keyd/xkb), but have a base Colemak keyboard. For example, on MacOS or Linux or Chromebooks where you cannot install AutoHotKey.

The layers on the UHK are modelled to use the same shortcuts and keys as the AutoHotKey script; so as long as you have either AHK/keyd/xkb running, or use the UHK, you can use the same key combinations.

If you have neither AHK, keyd, xkb nor UHK, then at least you will still have a Colemak layout (from the base OS setup).

MacOS, Linux, ChromeOS and Android all come with Colemak layouts that just need to be switched on. Only Microsoft Windows does not ship with a Colemak keymap, so it will need the installation of the OS base layer (see previous section).

To emulate NUMPAD on the UHK, a slightly different approach than with AHK was chosen: The Fn-ISO and Fn-/ keys on the UHK keymaps rotate through CMX, NMX, and NM2 keymaps. You can switch between those keymaps with Fn-ISO or Fn-/. The UHK display will show me which map is currently active. So, if you need to type a bunch of numbers, I just switch to NMX or NM2. (I haven’t figured out which one I like more, so for now, both are provided.)

Also, the NMX and NM2 layers on the UHK add a “cursor pad” using the / (up), R-Alt (left), R-Win (down) and R-Control (right) keys.

![image](https://github.com/mhantsch/maxtend/assets/591785/0445a8a2-d7b6-4227-ac7e-af582ac268ec)

![image](https://github.com/mhantsch/maxtend/assets/591785/dee35957-749c-4c02-81bb-beab7a133817)

Please note that the Mod layer is very similar to DreymaR’s “Extend” layer from https://forum.colemak.com/topic/2014-extend-extra-extreme/ with only minor tweaks.

![image](https://github.com/mhantsch/maxtend/assets/591785/b5138ec6-4ec1-4142-9814-d4d5f9cbccf3)

![image](https://github.com/mhantsch/maxtend/assets/591785/1bb891c9-3055-4f8a-9fc7-1a084e162141)

![image](https://github.com/mhantsch/maxtend/assets/591785/8dc4dab1-90cb-4f09-b22d-77a01749b15d)

![image](https://github.com/mhantsch/maxtend/assets/591785/54c3e3b5-b4c1-435c-a198-a49bd767bfee)
