# maxtend

Extended keyboard layers for easy navigation and functionality from a Colemak base layout.
(Possibly can be applied to other base layouts, too).

This repository contains various configurations and tooling to create an extended keyboard setup for both Windows and Linux, and a matching configuration for the [Ultimate Hacking Keyboard](https://ultimatehackingkeyboard.com). The configurations start from a Colemak base layout, but the concepts behind the navigation and numpad layers also work with other base layouts.

Read more about the [Background](BACKGROUND.md) of this setup.

## Main features of this layout

- a navigation layer (called *maxtend*) for cursor movement, text selection and cut/copy/paste
- a numpad layer (called *numtab*) for entering numbers in forms, sheets, calculators
- mouse support (on systems that support it) for clicking and scrolling

![Overview of the layout of a maxtended keyboard.](images/Maxtend-black.png)

## Documentation

[Full description of layers and functionality](documentation/documentation.md)

[Keycaps layout visualising layers and functions](documentation/keycaps-layout.md)

The configuration is setup in three stages:

1. base OS setup - giving a standard Colemak layout without extended functionality
2. maxtend layer - giving extended functionality such as navigation, mouse scrolling etc.;  
   (achieved via AutoHotKey (Windows, deprecated), Kanata (Windows & Linux, *recommended*), keyd (Linux), or xkb (Linux, deprecated))
3. external keyboard - giving extended functionality even if your host computer does not have `maxtend` installed, and extends it further  
  (implemented for UHK, QMK, and ZMK)

These stages can work independently, but also combine on top of each other for best functionality.

## Installation

Depending on your OS and preferred setup, find the configuration for each of the different tools in the corresponding subdirectories.

- For Windows:
  1. Install the Colemak keyboard layout from [Windows - Colemak](https://colemak.com/Windows) first. I recommend the [version which maps CapsLock to Backspace](https://colemak.com/File:Colemak-caps.zip).
  2. Then, pick between the [ahk configuration](ahk/) (and load via [AutoHotKey](https://www.autohotkey.com/)), or try [Kanata](https://github.com/jtroo/kanata) with the corresponding [kanata configuration](kanata/) (*recommended*).
- For Linux:
  1. Switch your keyboard layout to Colemak (via keyboard settings of your distribution).
  2. Then, choose between either [xkb](xkb/) ([how to configure](xkb/HOWTO), deprecated) or [keyd](keyd/) (using [the keyd service](https://github.com/rvaiya/keyd)), or try [Kanata](https://github.com/jtroo/kanata) with the corresponding [kanata configuration](kanata/) (*recommended*).
- For an external keyboard:
  - Ultimate Hacking Keyboard: Check out a matching [uhk configuration](uhk/) for the [Ultimate Hacking Keyboard](https://ultimatehackingkeyboard.com) (an external programmable keyboard).
  - QMK: Check out a configuration for a wired ErgoTravel keyboard using QMK on ProMicro controllers in the [qmk](qmk/) folder.
  - ZMK: Configuration for a wireless ErgoTravel keyboard (BLE) as well as an Eyelash Peripherals Corne using ZMK on nice!nano controllers in the [zmk](zmk/) folder. Check out the [README-ZMK](zmk/README-ZMK.md) for more information, or go directly to the ZMK builds for [ErgoTravel](https://github.com/mhantsch/ergotravel-zmk-module) and [Eyelash Corne](https://github.com/mhantsch/zmk-new_corne).

If you are unsure which option to install in step 2, try Kanata. Check out the [Quick install instructions](kanata/HOWTO-INSTALL.md). It works both in Windows and Linux, is super powerful, and it is what I am now using. It also supports home-row mods quite well (in case you are interested in that).

## Credits & Inspiration

- [The inventor of Colemak, shai coleman](https://colemak.com).
- [DreymaR and his Big Bag of Keyboard Tricks](https://dreymar.colemak.org/).
