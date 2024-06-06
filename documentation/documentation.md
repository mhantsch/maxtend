# maxtend User Documentation

## Overview

Maxtend is designed to minimise hand movements and enable keyboard operations mostly 
from the home row hand positions. It is optimised for 60% keyboards (no number pad, 
no navigation cluster, no function row), but works equally well on TKL or even full
keyboards.

- A short press and release of CapsLock (labelled "Maxtend") will work as Backspace, 
as in original Colemak.
- Holding CapsLock ("Maxtend") together with other keys works as an additional function layer, and 
contains useful navigation functions, e.g. cursor movement.
- Holding Tab ("Numtab") enables a virtual number pad, allowing easy number entry.

### Base layer

A maxtended keyboard features a base layer in [Colemak](https://colemak.com/) layout.

The base [Colemak](https://colemak.com/) layout has some of the alphabet characters on 
different keys than the well-known US-QWERTY layout, but all the special characters 
(symbols, punctuation, brackets, parenthesis etc.) are on the same positions as US-QWERTY. 
In addition, it features a comprehensive set of 
[international multilingual characters](https://colemak.com/Multilingual) 
(for latin alphabets) through use of the AltGr (right alt) key.

As in standard Colemak, the `CapsLock` key is used as Backspace. It is labeled `Maxtend`.
A simple tap on `Maxtend` will produce a backspace, erasing the character to the left of the cursor.

```
; Colemak (base layer):
; q    w    f    p    g    j    l    u    y    ;
;  a    r    s    t    d    h    n    e    i    o
;   z    x    c    v    b    k    m    ,    .    /
```

### Maxtend layer

When the `Maxtend` key is held down, the Maxtend layer is activated. The main purpose of this layer is 
cursor and document navigation, and edit control.

This layer features useful navigation functions such as:
- cursor navigation (up/down/left/right, home/end, page up/down)
- insert/backspace/delete
- back/forward browser navigation
- escape
- undo/cut/copy/paste
- scroll up/down

The number row also turns into a function key row. (`Maxtend`+`1`=`F1`, `Maxtend`+`2`=`F2`, ... 
`Maxtend`+`-`=`F11`, `Maxtend`+`=`=`F12`), 
and the key to the left of `1` (usually labelled `` `~ ``) becomes Escape.

On the top (number) row, you can reach Escape and the function keys F1-F12. 
Backspace becomes Delete.

__Escape:__ It is difficult to press `Maxtend` and the top left `` `~ `` key at the same time. 
Most likely you have to move the left hand out of the home position. Therefore, Escape can also be found 
on `Maxtend`+`q` (reached using the pinky+ring fingers oft he left hand.

__Navigation:__ Directly in the home row position for your right hand you find cursor up/down/left/right. 
Other navigation and editing controls (home, end, backspace, delete, insert, page up, page down) 
are placed closely around this position.

|   |   |   |   |   |
| --- | --- | --- | --- | --- |
|  `6`  |  `7`  |  `8`  |  `9`  |  `0` |
| `j` pageup | `l` home | `u` up | `y` end | `;` delete |
| `h` pagedn | `n` left | `e` down | `i` right | `o` backspace |
| `k` | `m` | `,<` | `.>` | `/?` |

(keys labelled according to Colemak)

*Note:* Although Backspace is already the primary function of the `Maxtend` key, its function is duplicated on this layer. There are two reasons:

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

__Browser navigation:__ `Maxtend`+`F` and `Maxtend`+`P` (qwerty positions: E, R) move backward and forward through browser history (they send Alt-CursorLeft and Alt-CursorRight keys). Compare this to the Mouse layer where these buttons cycle backward and forward through tabs.

**TODO** (continue here)

*Note:* As soon as a second key has been pressed while `Maxtend` is held down, or when `Maxtend` has been held down for more than half a second, releasing `Maxtend` will not Backspace. In this case, an indication will remind the user that Backspace will not be triggered. On AHK configurations, the screen will flash briefly. On UHK keyboards, the segment display will show **`MAX`** (and the _`mod`_ indicator will turn on), indicating that the Maxtend layer has become active. The user can then safely release `Maxtend` without triggering any action.

```
; Maxtend layer (CapsLock held):
; ESC  WlUp Back Fwd  g    PgUp Home Up   End  Del
;  Ctrl WlDn Shft Alt  d    PgDn Left Down Rght BkSp Ins
;   C-Z  C-X  C-C  C-V  b    k    m    ,    .    /
;
; The Function layer will also map CapsLock + number keys to F1-F12. Useful for 60% keyboards
; (keyboards without a function key row).
```
### Number layer


```
;
; (2) NUMBER pad
; Holding down Tab, active ScrollLock, or use CapsLock+Tab to turn the keys below 7-8-9 
; into a number pad. (Think: hold Tab for NUMPAD, CapsLock+Tab toggles NUMPAD). 
; Useful for keyboards without numpad.
; If you have a TKL keyboard with cursor keys and Print/ScrLock/Pause/Ins/Del/Home/End/PgUp/PgDn
; keys, those will emulate a number pad too in this mode.
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
;
; Number layer - additional mappings (for TKL keyboards):
; PrSc ScLk Paus   =>   7    8    9
; Ins  Home PgUp   =>   4    5    6
; Del  End  PgDn   =>   1    2    3
;      Up          =>        -
; Left Down Right  =>   0    ,    .

```
