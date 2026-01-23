Config is for UHK userConfig v13.0.0

**$onInit:**
```
clearStatus
setVar count 0
setVar snap_running 0
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
// positive values for safetyMargin favour primary role, negative favour secondary role
// set secondaryRole.advanced.safetyMargin +1
set holdTimeout 350
call hrm-on // hrm-off | hrm-on
setLedTxt 300 abbrev 'OK ' leftStatus 'OK '
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
ifKeymap CMX setLedTxt 200 leftStatus "  C" abbrev "  C"
ifKeymap CMX setLedTxt 200 leftStatus " C " abbrev " C "
ifKeymap CMX setLedTxt 200 leftStatus "C M" abbrev "C M"
ifKeymap CMX setLedTxt 200 leftStatus " M " abbrev " M "
ifKeymap CMX setLedTxt 200 leftStatus "M X" abbrev "M X"
ifKeymap CMX setLedTxt 200 leftStatus " X " abbrev " X "
ifKeymap CMX setLedTxt 200 leftStatus "   " abbrev "   "
ifKeymap CMX setLedTxt 200 leftStatus "  C" abbrev "  C"
ifKeymap CMX setLedTxt 200 leftStatus " CM" abbrev " CM"
ifKeymap CMX setLedTxt 200 leftStatus "CMX" abbrev "CMX"
ifKeymap CMX setLedTxt 300 leftStatus "   " abbrev "   "
ifKeymap CMX setLedTxt 300 leftStatus "CMX" abbrev "CMX"
ifKeymap CMX setLedTxt 300 leftStatus "   " abbrev "   "
ifKeymap CMX setLedTxt 200 leftStatus "CMX" abbrev "CMX"

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
set keymapAction.mod.tab macro initCMX
```

**$onKeymapLayerChange CMX base:**
```
setLedTxt 1 leftStatus "   " abbrev ":::"
```

**$onKeymapLayerChange CMX fn:**
```
setLedTxt 0 leftStatus "FUN" abbrev "FUN"
```

**$onKeymapLayerChange CMX fn2:**
```
setLedTxt 0 leftStatus 'F12' abbrev 'F12'
```

**$onKeymapLayerChange CMX fn3:**
```
setLedTxt 0 leftStatus '123' abbrev '123'
```

**$onKeymapLayerChange CMX fn4:**
```
setLedTxt 0 leftStatus '0-9' abbrev '0-9'
```

**$onKeymapLayerChange CMX fn5:**
```
setLedTxt 0 leftStatus "NUM" abbrev "NUM"
```

**$onKeymapLayerChange CMX mod:**
```
setLedTxt 0 leftStatus "MAX" abbrev "MAX"
```

**$onKeymapLayerChange CMX mouse:**
```
setLedTxt 0 leftStatus "MSE" abbrev "MSE"
```

**bt-off:**
```
set bluetooth.enabled false
```

**bt-on:**
```
set bluetooth.enabled true
// set bluetooth.alwaysAdvertiseHid true
bluetooth advertise
```

**bt-pair:**
```
bluetooth pair
```

**bt-toggle-advertise:**
```
bluetooth toggle advertise
```

**chordscape:**
```
# args: thisKey, otherKey
ifShortcut timeoutIn 100 &macroArg.2 final holdKey escape
holdKey &macroArg.1
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
setLedTxt 1000 leftStatus $count abbrev $count
repeatFor count loop
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
ifShortcut timeoutIn 50 orGate $keyId.leftMod $keyId.rightSpace exec fn2-fkeys
holdLayer fn
```

**fn2-fkeys:**
```
holdLayer fn2
```

**graveTilde:**
```
ifShortcut timeoutIn 200 1 exec quoteLong
//ifHold exec quoteLong
holdKey graveAccentAndTilde
```

**hrm-off:**
```
overlayLayer base HRM base
set secondaryRole.advanced.acceptTriggersFromSameHalf true
set secondaryRole.advanced.minimumHoldTime 0
setLedTxt 666 leftStatus 'H--' abbrev 'H--'
```

**hrm-on:**
```
overlayLayer base HRM mod
set secondaryRole.advanced.acceptTriggersFromSameHalf false
set secondaryRole.advanced.minimumHoldTime 50
setLedTxt 666 leftStatus 'H++' abbrev 'H++'
```

**initCMX:**
```
switchKeymap CMX
```

**keepAlive:**
```
setVar count 6
startloop:
ifKeymap --- setLedTxt 200 leftStatus "`-'" abbrev "`-'"
ifKeymap --- setLedTxt 200 leftStatus "---" abbrev "---"
ifKeymap --- repeatFor count startloop
clearStatus
```
```
keepalive:
```
> moveMouse ...
```
ifNotKeymap --- goTo final
ifKeymap --- setLedTxt 200 leftStatus "---" abbrev "---"
ifLayer mod goTo modLayerPt1
ifLayer fn5 goTo numLayerPt1
ifKeymap --- setLedTxt 200 leftStatus "}--" abbrev "}--"
ifKeymap --- setLedTxt 200 leftStatus "-}-" abbrev "-}-"
ifKeymap --- setLedTxt 200 leftStatus "--}" abbrev "--}"
goTo numLayerPt1End
numLayerPt1:
ifKeymap --- setLedTxt 200 leftStatus "1--" abbrev "1--"
ifKeymap --- setLedTxt 200 leftStatus "-2-" abbrev "-2-"
ifKeymap --- setLedTxt 200 leftStatus "--3" abbrev "--3"
goTo numLayerPt1End
modLayerPt1:
ifKeymap --- setLedTxt 200 leftStatus "M--" abbrev "M--"
ifKeymap --- setLedTxt 200 leftStatus "-A-" abbrev "-A-"
ifKeymap --- setLedTxt 200 leftStatus "--X" abbrev "--X"
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
ifKeymap --- setLedTxt 200 leftStatus "---" abbrev "---"
ifLayer mod goTo modLayerPt2
ifLayer fn5 goTo numLayerPt2
ifKeymap --- setLedTxt 200 leftStatus "--{" abbrev "--{"
ifKeymap --- setLedTxt 200 leftStatus "-{-" abbrev "-{-"
ifKeymap --- setLedTxt 200 leftStatus "{--" abbrev "{--"
goTo endPt2
numLayerPt2:
ifKeymap --- setLedTxt 200 leftStatus "--3" abbrev "--3"
ifKeymap --- setLedTxt 200 leftStatus "-2-" abbrev "-2-"
ifKeymap --- setLedTxt 200 leftStatus "1--" abbrev "1--"
goTo endPt2
modLayerPt2:
ifKeymap --- setLedTxt 200 leftStatus "--X" abbrev "--X"
ifKeymap --- setLedTxt 200 leftStatus "-A-" abbrev "-A-"
ifKeymap --- setLedTxt 200 leftStatus "M--" abbrev "M--"
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
setLedTxt 800 leftStatus '[-]' abbrev '[-]'
setLedTxt 200 leftStatus '[\]' abbrev '[\]'
setLedTxt 200 leftStatus '[|]' abbrev '[|]'
setLedTxt 200 leftStatus '[/]' abbrev '[/]'
setLedTxt 200 leftStatus '[-]' abbrev '[-]'
setLedTxt 200 leftStatus '[\]' abbrev '[\]'
setLedTxt 200 leftStatus '[|]' abbrev '[|]'
setLedTxt 200 leftStatus '[/]' abbrev '[/]'
setLedTxt 200 leftStatus '[-]' abbrev '[-]'
setLedTxt 200 leftStatus '[*]' abbrev '[*]'
setLedTxt 200 leftStatus '|_|' abbrev '|_|'

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

```

**maxtend:**
```
ifDoubletap goTo doubleMaxtend
ifLayer fn goTo altMaxtend
ifShift goTo shiftMaxtend
ifAlt goTo altMaxtend
ifSecondary acceptTriggersFromSameHalf goTo secondaryaction

primaryaction:
tapKey backspace
setLedTxt 500 leftStatus "<--" abbrev "<--"
break

secondaryaction:
holdLayer mod
break

doubleMaxtend:
fork maxtend_showbackspace
shiftMaxtend:
setLedTxt 0 leftStatus "<--" abbrev "<--"
suppressMods holdKey backspace
ifNotPlaytime 300 setLedTxt 300 leftStatus "<--" abbrev "<--"
setLedTxt 1 leftStatus "<--" abbrev "<--"
break

altMaxtend:
setLedTxt 0 leftStatus "DEL" abbrev "DEL"
suppressMods holdKey delete
ifNotPlaytime 300 setLedTxt 300 leftStatus "DEL" abbrev "DEL"
setLedTxt 1 leftStatus "DEL" abbrev "DEL"
break
```

**maxtend_showbackspace:**
```
setLedTxt 450 leftStatus "<--" abbrev "<--"
ifReleased break
setLedTxt 0 leftStatus "<<-" abbrev "<<-"
```

**mousetend:**
```
ifDoubletap final holdKey space
ifSecondary acceptTriggersFromSameHalf final holdLayer mouse
final tapKey space
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
ifSecondary acceptTriggersFromSameHalf final holdLayer fn4
final holdKey space
```

**numspace-micro:**
```
ifPrimary acceptTriggersFromSameHalf final holdKey space
holdLayer fn4
```

**numtab:**
```
ifDoubletap final holdKey tab
ifAlt final holdKey tab
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
ifShift goTo shiftTab
tapKey tab
setLedTxt 500 leftStatus "->|" abbrev "->|"
break

secondaryaction:
ifShift goTo shiftTabSecondary
holdLayer fn5
delayUntil 100
break

shiftTabSecondary:
ifNotLayer fn5 final toggleLayer fn5
unToggleLayer
break

shiftTab:
setLedTxt 0 leftStatus "|<-" abbrev "|<-"
holdKey tab
setLedTxt 500 leftStatus "|<-" abbrev "|<-"
break

```

**numtab3:**
```
ifShortcut timeoutIn 50 orGate $keyId.leftMod $keyId.rightSpace exec fn2-fkeys

ifAlt final holdKey tab
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
ifShift goTo shiftTab
tapKey tab
setLedTxt 500 leftStatus "->|" abbrev "->|"
break

secondaryaction:
ifShift goTo shiftTabSecondary
holdLayer fn3
delayUntil 100
break

shiftTabSecondary:
ifNotLayer fn3 final toggleLayer fn3
unToggleLayer
break

shiftTab:
setLedTxt 0 leftStatus "|<-" abbrev "|<-"
holdKey tab
setLedTxt 500 leftStatus "|<-" abbrev "|<-"
break
```

**numthumb:**
```
setLedTxt 0 leftStatus '123' abbrev '123'
holdLayer fn3
setLedTxt 1 leftStatus '123' abbrev '123'
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

**quoteLong:**
```
tapKeySeq graveAccentAndTilde graveAccentAndTilde graveAccentAndTilde
tapKeySeq enter enter
tapKeySeq graveAccentAndTilde graveAccentAndTilde graveAccentAndTilde enter
tapKeySeq up up
```

**reboot:**
```
reboot
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
setLedTxt 0 leftStatus '<->' abbrev '<->'
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
setLedTxt 1 leftStatus '<->' abbrev '<->'

```

**spacetapper:**
```
setLedTxt 500 leftStatus 'SPC' abbrev 'SPC'
loop:
delayUntil 4000
ifInterrupted final setLedTxt 1500 leftStatus 'OFF' abbrev 'OFF'
tapKey space
setLedTxt 1000 leftStatus 'SPC' abbrev 'SPC'
goTo loop
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

**zephyr connections:**
```
zephyr uhk connections
```

