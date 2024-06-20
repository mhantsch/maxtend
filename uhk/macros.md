Config is for UHK userConfig v7.1.0

**$onInit:**
```
clearStatus
setVar count 0
setVar unpause 0
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
set secondaryRole.defaultStrategy advanced
set secondaryRole.advanced.timeout 250
set secondaryRole.advanced.timeoutAction secondary
set secondaryRole.advanced.triggerByRelease 1
// positive values for savetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +5
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
set keymapAction.fn.isoKey macro initCM3
if ( $unpause == 3 ) { 
    set keymapAction.fn.b macro initCM3 
}
else if ( $unpause == 2 ) {
    set keymapAction.fn.b macro initCM2
}
else { 
    set keymapAction.fn.b macro initCMX
}
call keepAlive
```

**$onKeymapChange CM2:**
```
setVar unpause 2
setLedTxt 10 CM2
replaceLayer mod CMX mod
replaceLayer mouse CMX mouse
replaceLayer fn CMX fn
replaceLayer fn2 CMX fn2
replaceLayer fn3 CMX fn3
replaceLayer fn4 CMX fn4
replaceLayer fn5 CMX fn5
set keymapAction.fn.isoKey macro initCM3
set keymapAction.fn3.isoKey macro initCM3
set keymapAction.fn5.isoKey macro initCM3
set secondaryRole.defaultStrategy advanced
set secondaryRole.advanced.timeout 450
set secondaryRole.advanced.timeoutAction secondary
set secondaryRole.advanced.triggerByRelease 1
// positive values for safetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +30
```

**$onKeymapChange CM3:**
```
setVar unpause 3
setLedTxt 10 CM3
replaceLayer mod CMX mod
replaceLayer mouse CMX mouse
replaceLayer fn CMX fn
replaceLayer fn2 CMX fn2
replaceLayer fn3 CMX fn3
replaceLayer fn4 CMX fn4
replaceLayer fn5 CMX fn5
set keymapAction.fn.isoKey macro initCMX
set keymapAction.fn3.isoKey macro initCMX
set keymapAction.fn5.isoKey macro initCMX
set secondaryRole.defaultStrategy advanced
set secondaryRole.advanced.timeout 350
set secondaryRole.advanced.timeoutAction secondary
set secondaryRole.advanced.triggerByRelease 1
// positive values for safetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +10
```

**$onKeymapChange CMX:**
```
setVar unpause 1
setVar c 20
setLedTxt 1 CMX
startloop: delayUntil 250
ifNotKeymap CMX break
repeatFor c startloop
set secondaryRole.defaultStrategy advanced
set secondaryRole.advanced.timeout 250
set secondaryRole.advanced.timeoutAction secondary
set secondaryRole.advanced.triggerByRelease 1
// positive values for safetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +5
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

**fn:**
```
holdLayer fn
```

**initCM2:**
```
switchKeymap CM2
```

**initCM3:**
```
switchKeymap CM3
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
ifLayer fn5 goTo numLayerPt1
ifKeymap --- setLedTxt 200 "}--"
ifKeymap --- setLedTxt 200 "-}-"
ifKeymap --- setLedTxt 200 "--}"
goTo numLayerPt1End
numLayerPt1:
ifKeymap --- setLedTxt 200 "1--"
ifKeymap --- setLedTxt 200 "-2-"
ifKeymap --- setLedTxt 200 "--3"
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
ifLayer fn5 goTo numLayerPt2
ifKeymap --- setLedTxt 200 "--{"
ifKeymap --- setLedTxt 200 "-{-"
ifKeymap --- setLedTxt 200 "{--"
goTo numLayerPt2End
numLayerPt2:
ifKeymap --- setLedTxt 200 "--3"
ifKeymap --- setLedTxt 200 "-2-"
ifKeymap --- setLedTxt 200 "1--"
numLayerPt2End:
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

**maxtend:**
```
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

**mirror:**
```
setLedTxt 0 XMC
holdLayer fn2
setLedTxt 1 XMC
```

**mousetend:**
```
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
ifSecondary final holdKey LC-space
tapKey LCLS-m
ifNotShift break
delayUntil 300
tapKey LCLS-semicolonAndColon
```

**nextKeyID:**
```
resolveNextKeyId
```

**numspace:**
```
ifSecondary goTo secondaryaction
primaryaction: final tapKey space
secondaryaction: 
setLedTxt 0 '0-9'
holdLayer fn4
ifLayer fn5 final setLedTxt 0 "NUM"
setLedTxt 1 '0-9'

```

**numtab:**
```
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
ifDoubletap final switchKeymap NM2
switchKeymap NM2
delayUntilRelease
switchKeymap CM2
```

**printstatus:**
```
printStatus
```

