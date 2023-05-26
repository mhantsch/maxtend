## Intro
Some years ago, I decided to switch my keyboard layout to [Colemak](https://colemak.org), and re-learn my typing. I was decent at touch-typing qwerty, but I decided my typing experience could be better. Thus, the rabbit hole of keyboard layouts, mechanical keyboards, and keyboard layers.

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

Why this flexibility? Imagine you are used to a specific keyboard layout including extended functionality. You work on several computers, sometimes on Windows, sometimes on Linux, sometimes on an external keyboard, and sometimes on the internal keyboard of a laptop. You will want that layout to be identical across all these setups. On computers where your layout and your extended layers are installed, you can work without an external keyboard, but it will not hurt to also use it. On computers where your setup has not been installed, the external keyboard will give you the full functionality.

## Staged Setup
We are addressing the setup in three stages:
1. base OS setup - giving a Colemak layout without extended functionality
2. maxtend layer - giving extended functionality such as navigation, mouse scrolling etc.
3. external keyboard - giving extended functionality even if your host computer does not have `maxtend` installed


### OS setup
A Colemak layout. With this step, your keyboard will be colemak (including multilingual characters, but no other special layers). This is the base for the subsequent maps in AutoHotKey, xkb, keyd, and the UHK.
#### Linux
This is available out of the box in all distributions. Just select it as your layout.

#### Windows
This requires installation of an additional [Colemak keyboard layout](https://colemak.com/Windows). I recommend [a version that remaps Caps Lock to Backspace](https://forum.colemak.com/topic/1621-colemak-for-windows-with-capslock-to-backspace/).

On Windows 10 or later, install the ‘en’ version, not the ‘co’ version. It will remap the CapsLock to backspace, and install a generic Colemak layout (including AltGr layer for multilingual characters). After installation, make sure you configure the Colemak keyboard in the Language options for your language, and then select it in the language toolbar.

![image](https://github.com/mhantsch/maxtend/assets/591785/0d160419-8be4-4351-b54d-f350c7eb4ae9)
![image](https://github.com/mhantsch/maxtend/assets/591785/ddbcd435-5e2e-489a-9d0b-fbe39b8a3378)

This is the keymap you should now have:
![image](https://github.com/mhantsch/maxtend/assets/591785/71e4b0b3-5269-4c73-b54a-581b075aa8ec)

The right-hand side symbols show what the key will produce when pressed with AltGr. \\

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

### AutoHotKey keymap

### xkb

### keyd

### Ultimate Hacking Keyboard


