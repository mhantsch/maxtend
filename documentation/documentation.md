# Maxtend User Documentation

## Overview

![Overview of the layout of a maxtended keyboard.](../images/Maxtend-black.png)

*Maxtend* is designed to minimise hand movements and enable keyboard operations mostly from the home row hand positions. It is optimised for 60% keyboards (no number pad, no navigation cluster, no function row), but works equally well on TKL[^tkl] or full-size keyboards. *Maxtend* uses layers for the functionality traditionally bound to specific keys (cursor navigation, editing, number entry, function keys etc.), which are not present on a 60% keyboard.

- A short press and release of CapsLock (labelled `Maxtend`) will work as Backspace, as in original Colemak.
- Holding CapsLock (`Maxtend`) together with other keys works as an additional function layer, and contains useful navigation functions, e.g. cursor movement.
- Holding Tab (`Numtab`) enables a virtual number pad, allowing easy number entry.

On a UHK[^uhk], additional functionality is available, e.g. mouse control, 2-axis scrolling, mouse jitter keep-alive, media and volume control.

### Notation conventions

* `a` a key
* `[{` also a key
* `Shift`+`a` two keys pressed together (the first key being pressed first)
* _Maxtend_ an emphasis
* **Escape** a different emphasis
* _**`LED`**_ (bold, italics, upper case) something displayed on the UHK LED display
* _**`mod`**_ (bold, italics, lower case) an indicator on the UHK LED display

### Base layer

A maxtended keyboard features a base layer in [Colemak](https://colemak.com/) layout.

```
Colemak base layer:
`~    1!   2@   3#   4$   5%   6^   7&   8*   9(   0)   -_   =+  Bkspc
Numtab  q    w    f    p    g    j    l    u    y    ;:   [{   ]}   \|
Maxtend  a    r    s    t    d    h    n    e    i    o    '"   Return
Shift      z    x    c    v    b    k    m    ,<   .>   /?       Shift
```
The base [Colemak](https://colemak.com/) layout has a number of alphabet characters on different keys than the well-known US-QWERTY layout, but all the special characters (symbols, punctuation, brackets, parenthesis etc.) are on the same positions as US-QWERTY (the only exception being `;:`). In addition, it features a comprehensive set of [international multilingual characters](https://colemak.com/Multilingual) (for latin alphabets) through use of the `AltGr` (right alt) key.

As in standard Colemak, the `CapsLock` key is used as Backspace. On *Maxtend*, it is labeled `Maxtend`. A simple tap on `Maxtend` produces a backspace, erasing the character to the left of the cursor. See below for layer switching when `Maxtend` is held down.

#### Layer switching

The base layer has three layer-switching keys. When held down and pressed together with other keys, they will activate other layers:
- holding `Maxtend` (CapsLock) will activate the Maxtend layer
- holding `NumTab` (Tab) will activate the Number layer
- holding `AltGr` (right Alt) will activate the AltGr layer 

_Note:_ `AltGr` comes with the Colemak keymap (configured in the OS keyboard layout). `Maxtend` and `NumTab` are enabled through the AHK, keyd, xkb or UHK configuration.

### AltGr layer

```
Colemak AltGr layer:
(~)   ¡¹   º²   ª³   ¢£   €¥   ħĦ   ðÐ   þÞ   ‘“   ’”   – —  ×÷  Bkspc
Numtab  äÄ   åÅ   ãÃ   øØ   (˛)  đĐ   łŁ   úÚ   üÜ   öÖ   «‹   »›   ~~
Maxtend  áÁ   (`)  ßẞ   (´)  (¨)  (ˇ)  ñÑ   éÉ   íÍ   óÓ   '"   Return
Shift      æÆ   (^)  çÇ   œŒ   (˘)  (°)  (¯)  (¸)  (˙)  ¿~       Shift
```

Note: the AltGr layer contains several dead keys[^deadkey], indicated by parentheses, e.g. `(˘)`. Typing one of these keys will modify the next letter:
- `AltGr`+`~` is ~ – to produce ã ẽ õ ñ etc.
- `AltGr`+`r` is ` – to produce à è ò etc.
- `AltGr`+`t` is ´ – to produce á é ó etc.
- `AltGr`+`d` is ¨ – to produce ä ö ü ÿ etc.
- `AltGr`+`h` is ˇ – to produce ǎ ǔ č ť š ř etc.
- `AltGr`+`x` is ^ – to produce ĉ â û ŷ etc.
- `AltGr`+`b` is ˘ – to produce ă ŭ ĕ etc.
- `AltGr`+`k` is ˚ – to produce å ů ẙ etc.
- `AltGr`+`m` is ¯ – to produce ā ō ū ȳ ḡ etc.
- `AltGr`+`,` is ¸ – to produce ç ş ţ ģ ļ ŗ ḑ ḩ ņ ȩ ķ etc.
- `AltGr`+`\` is * – to produce ¶ ™ © ® № µ etc. (_Windows only_)

[^deadkey]: A dead key does not immediately produce a character (“it’s dead”), but it will modify the next character. The accent symbol on the dead key "combines" with the symbol on the next key to produce an accented character. If you want the "dead" symbol on its own, you need to press the dead key first, then type Space.

### Maxtend layer

When the `Maxtend` key is held down, the Maxtend layer is activated[^maxtend-release]. The main purpose of this layer is cursor and document navigation, and editing.

```
Maxtend layer:
Esc    F1   F2   F3   F4   F5   F6   F7   F8   F9   F10  F11  F12  Delete
Numtab  Esc  WhUp Back Fwd  -    PgUp Home Up   End  Del  PrSc ScLk Pause
         Alt  WhDn Shft Ctrl -    PgDn Left Down Rght Bksp Ins     Return
Shift      C-z  C-x  C-c  C-v  b    k    m    ,<   .>   Menu        Shift
```

This layer features useful navigation functions such as:
- cursor navigation (up/down/left/right, home/end, page up/down)
- insert/backspace/delete
- back/forward browser navigation
- escape
- undo/cut/copy/paste
- scroll up/down

On the top (number) row, you can reach Escape (`Maxtend`+`` `~ ``) and the function keys F1-F12 (`Maxtend`+`1` ...  `Maxtend`+`=`). `Maxtend`+`Backspace` becomes Delete.

__Escape:__ It is difficult to press `Maxtend` and the top left `` `~ `` key at the same time. Most likely you have to move the left hand out of the home position. Therefore, Escape can also be found on `Maxtend`+`q` (reached using the pinky+ring fingers of the left hand.

__Navigation:__ Directly in the home row position for your right hand you find cursor up/down/left/right. Other navigation and editing controls (home, end, backspace, delete, insert, page up, page down) are placed closely around this position.

|  `6`  |  `7`  |  `8`  |  `9`  |  `0` | |
| --- | --- | --- | --- | --- | --- |
| `j` pageup | `l` home | `u` up | `y` end | `;` delete | |
| `h` pagedn | `n` left | `e` down | `i` right | `o` backspace | `'"` insert |
| `k` | `m` | `,<` | `.>` | `/?` menu |

(keys labelled according to Colemak)

*Note:* Although Backspace is already the primary function of the `Maxtend` key, its function is duplicated on this layer (`Maxtend`+`o`). There are two reasons:

  1. While holding the `Maxtend` key and using cursor navigation, removal of incorrect characters is instantly available without needing to release `Maxtend`. And you can immediately continue to navigate.
  2. Backspace through a tap on the `Maxtend` key does not autorepeat (due to secondary function as the Maxtend layer switch). Backspace on the Maxtend layer auto-repeats, and can thus be used to Backspace over larger areas of text.

__Modifiers:__ During cusor navigation, shift, alt and control modifiers are often used to select larger parts of text, navigate by word, sentence, paragraph etc. It is difficult to reach the standard modifier keys while holding `Maxtend` with your pinky. For this reason, the modifiers are replicated on the home row for your left hand, next to the `Maxtend` key. To aid memorisation, the modifiers correspond to Colemak letters: `a`=Alt, `s`=Shift, `t`=conTrol.

For example, you can hold `Maxtend` + `t` (conTrol), and then use left/right cursor functions of the right hand to navigate by word. Similarily, `Maxtend` + `s` (Shift) + `t` (conTrol) + cursor navigation can be used to select by word, etc. The modifiers are all on the left hand, so while you are holding some chords for layer switch and modifiers with your left hand, your right hand is free to tap all the navigation keys. After a short practice, this feels very natural.

__Undo/Cut/Copy/Paste:__ these often used text editing functions are available on their usual Z/X/C/V positions. `Maxtend` + `z`/`x`/`c`/`v` is the same as `Control` + `z`/`x`/`c`/`v`. The idea is that during typical editing, every needed function (movement, selection, cut/copy/paste, undo) can be accessed from the same layer, all while simply holding down `Maxtend`.

__Scrolling:__ to move the document up/down during editing, mouse wheel up/down (to scroll the page) can be accessed with the left hand. This helps when navigating or reading a document.

__Enter:__ when the right hand is resting on the mouse, Enter can be obtained with only the left hand using `Maxtend' + Space.

__PrScr/ScrLk/Pause:__ these are available on the `[{`, `]}` and  `\|` keys. 
Mnemonic: the F-row continues to those buttons.

__Menu:__ on the right side, the `/?` key activates the menu function. With `Maxtend` held down, the user immediately has access to cursor movement to select an entry in the menu.

__Browser navigation:__ `Maxtend`+`F` and `Maxtend`+`P` move backward and forward through browser history (they send Alt-CursorLeft and Alt-CursorRight keys). _(UHK-only:_ Compare this to the Mouse layer where these buttons cycle backward and forward through tabs, and the Fn layer where they send History-back and History-forward.)

#### `Maxtend`, extended

* A short tap on `Maxtend` produces Backspace.
* `Shift`+`Maxtend` also produces Backspace, but with autorepeat (same as `Maxtend`+`o`).
* `Alt`+`Maxtend` (or `AltGr`+`Maxtend`) produces Delete, also with autorepeat (same as `Maxtend`+`;:`).
* _(UHK-only)_ `Fn`+`Maxtend` also produces Delete, also with autorepeat (same as `Maxtend`+`;:`).

[^maxtend-release]: *Note:* As soon as a second key has been pressed while `Maxtend` is held down, or when `Maxtend` has been held down for more than ~300ms, the Maxtend layer will activate. Releasing `Maxtend` will then no longer Backspace. Additionally, an indication will remind the user that Backspace will not be triggered. On AHK configurations, the screen will flash briefly. On UHK keyboards, the LED segment display will show *`MAX`* (and the _`mod`_ indicator will turn on), indicating that the Maxtend layer has become active. The user can then safely release `Maxtend` without triggering any action.

### Number layer

When the `NumTab` key (tab) is held down, the Number layer is activated. The main purpose of this layer is number entry via a simulated number pad.

```
Number layer:
Esc   ˙    ˙    ˙    ˙    ˙    ˙    7    8    9    0    -_   =+  Bkspc
Numtab  Esc  ˙    ¡    ¿    ˙    /    4    5    6    –    [{   ]}   \|
Maxtend  Alt  ˙    Shft Ctrl ˙    *    1    2    3    +    '"   Return
Shift      C-z  C-x  C-c  C-v  NumLk ˙   0    ,<   .    Enter    Shift
```
(a single ˙ indicates a key with no function)

Tapping `Maxtend`+`NumTab` or holding `Shift`+`NumTab` for a little while locks the number layer. Use the same combination to unlock. While the number layer is locked, you can use `Maxtend` to activate keys from the Maxtend layer; it will revert back to the (locked) number layer when you release `Maxtend`.

For TKL keyboards[^tkl] (featuring a navigation cluster) another simulated number pad is provided:

```
Number layer - additional mappings (for TKL keyboards):
PrSc ScLk Paus   =>   7    8    9
Ins  Home PgUp   =>   4    5    6
Del  End  PgDn   =>   1    2    3

     Up          =>        -
Left Down Right  =>   0    ,    .

```

## UHK functionality

The following features are only available with the external Ultimate Hacking Keyboard.

### General
The base layer contains a normal US keymap (mapped to Colemak by the OS keymap). As standard in Colemak, the CapsLock key functions as Backspace; it carries `Maxtend` as a secondary function. The left space bar switches to the Mouse layer when held down; it still functions as Space when tapped on its own.

I deliberately kept the primary functions of `Maxtend` (Backspace), `Numtab` (Tab) and the left space bar (Space), and switch layers only as a secondary function (when these buttons are held down and combined with other keys). The usual primary function of these keys is unmodified.

The right Space bar is kept without any secondary function because the secondary function can conflict with n-key rollover when typing fast, and I noticed that I mostly type space with my right thumb. If that is different for you, and you mainly type Space with your left thumb, you may want to move the secondary Mouse layer switch (*Mousetend* macro) from the left Space to the right Space.

### `Maxtend` functions
Activation of the different functions of the `Maxtend` key will be visualised on the LED display:

| Key combination | short tap | hold | LED display |
| --- | --- | --- | --- |
| `Maxtend` | Backspace | Maxtend layer | _**`<--`**_ / _**`MAX`**_+_**`mod`**_ |
| `Shift`+`Maxtend` | Backspace | Backspace (autorepeat) | _**`<--`**_ |
| `Alt`+`Maxtend`<br/>`AltGr`+`Maxtend`<br/>`Fn`+`Maxtend` | Delete | Delete (autorepeat) | _**`DEL`**_ |

### `NumTab` functions
Activation of the different functions of the `Numtab` key will be visualised on the LED display:

| Key combination | short tap | hold | LED display |
| --- | --- | --- | --- |
| `NumTab`         | Tab           | Number layer             | _**`->\|`**_ / _**`NUM`**_ |
| `Shift`+`NumTab` | Shift+Tab     | lock/unlock Number layer | _**`\|<-`**_ / _**`NUM`**_ |
| `Alt`+`NumTab`<br/>`Fn`+`NumTab` | Alt+Tab<br/>_(switches windows)_ | Alt+Tab (autorepeat) |  |

### Mouse layer
Holding left Space activates the Mouse layer. The UHK display will briefly show _**`MSE`**_, and the _**`mouse`**_ indicator will turn on.

The left case key functions as a left mouse button. This is useful if you do not have a key cluster module connected (which has mouse buttons), but a mouse module (e.g. trackpad) on the right side. You can use the left case button to click items while steering the mouse pointer with the right module.

### Media layer
Holding either Fn key activates the Media layer (and the _**`fn`**_ indicator will turn on). This layer offers features to control media playback, volume control, speaker and mic mute, as well as some compatibility with the Colemak AltGr layer.

### Mirror layer

### Additional features
CapsLock on ISO: On the UHK, `Maxtend`+`ISO` (the ISO key sitting between the left `Shift` and `z` keys) can be used to send an actual CapsLock. However, with AHK in place (Windows), or keyd (Linux), this will just trigger the corresponding layer on AHK/keyd. The net effect is that it is the same as just using `Maxtend` (Mod,CapsLock). (It can be used to test the AHK/keyd configuration, though, without the UHK logic interfering.)

For cursor control using only the right hand, Mod (the Maxtend layer) is also available on the right case button, and it's a secondary function on the `'"` key. The layer can also be locked on the UHK by double-tapping the right case button.

#### `Maxtend`, extended, visualised

* A short tap on `Maxtend` produces Backspace, and the LCD display will briefly show *`<--`*.
* `Shift`+`Maxtend` also produces Backspace, but with autorepeat (same as `Maxtend`+`o`), and the LCD display will show *`<--`* as long as the keys are held down.
* `Alt`+`Maxtend` (or `AltGr`+`Maxtend`) produces Delete, also with autorepeat (same as `Maxtend`+`;:`), and the LCD display will show *`DEL`*.
* `Fn`+`Maxtend` also produces Delete, also with autorepeat (same as `Maxtend`+`;:`), and the LCD display will show *`DEL`*.
* holding `Maxtend` will activet the *Maxtend* layer, and the LCD display will show *`MAX`*

#### Keepalive

#### Numpad Enter (wide Enter)
Numpad Enter is mapped onto the right `Control` key; it still acts as RCtrl as a secondary function. Here is my reasoning:
- `Control` only makes sense as a modifier and needs to be typed together with another key.
- If you really need only a tap on `Control`, you can use the left `Control`.
- the size of the right `Control` key on the UHK is identical to a standard US-keyboard `Return` key. I swapped the keycaps on my UHK, and to populate the right `Control` position, I usually install an `Enter` key there. Because it is labelled “Enter”, it makes only sense that it also functions as Enter when the user taps it.

![image](https://github.com/mhantsch/maxtend/assets/591785/c5bfe3c7-5109-4859-9af7-b06dd78cde6e)

(This is only on the UHK. The AHK script does not modify right Control.)

-----
[^tkl]: Ten-Key-Less. A keyboard that does not have a "number pad" key cluster for number entry. There is still a navigation cluster with cursor keys, Ins/Del/Home/End/PgUp/PgDn, and PrScr/ScrLk/Break keys. Also often referred to as an "80%" keyboard.

[^uhk]: [Ultimate Hacking Keyboard](https://www.ultimatehackingkeyboard.com), an external, split USB keyboard with optional extra modules. The UHK offers advanced key configuration, layers, programming capabilities via a macro programming language, and mouse control.
