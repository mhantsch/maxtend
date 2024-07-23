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
   (achieved via AutoHotKey (Windows), Kanata (Windows & Linux, experimental), keyd (Linux), or xkb (Linux, deprecated))
4. external keyboard - giving extended functionality even if your host computer does not have `maxtend` installed, and extends it further

These stages can work independently, but also combine on top of each other for best functionality.

## Installation
Depending on your OS and preferred setup, find the configuration for each of the different tools in the corresponding subdirectories. 
- For Windows, install the Colemak keyboard layout from [Windows - Colemak](https://colemak.com/Windows) first. I recommend the [version which maps CapsLock to Backspace](https://colemak.com/File:Colemak-caps.zip). Then, pick between the [ahk configuration](ahk/) (and load via [AutoHotKey](https://www.autohotkey.com/)), or try [Kanata](https://github.com/jtroo/kanata) with the corresponding [kanata configuration](kanata/) (_experimental!_).
- For Linux, choose between either [xkb](xkb/) ([how to configure](xkb/HOWTO), deprecated) or [keyd](keyd/) (recommended, using [the keyd service](https://github.com/rvaiya/keyd)), or try [Kanata](https://github.com/jtroo/kanata) with the corresponding [kanata configuration](kanata/) (_experimental!_).
- Check out a matching [uhk configuration](uhk/) for the [Ultimate Hacking Keyboard](https://ultimatehackingkeyboard.com) (an external programmable keyboard).

If you are unsure which to install, try Kanata. It works both in Windows and Linux, and it is what I have been using lately. It also supports home-row mods quite well (in case you are interested in that).

## Credits & Inspiration
- [The inventor of Colemak, shai coleman](https://colemak.com).
- [DreymaR and his Big Bag of Keyboard Tricks](https://dreymar.colemak.org/).
