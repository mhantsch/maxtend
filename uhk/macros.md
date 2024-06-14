$onInit:
```
clearStatus
unToggleLayer
setVar count 0
set backlight.strategy constantRgb
set backlight.constantRgb.rgb 64 64 64
set leds.brightness 1
set leds.fadeTimeout 300
set module.trackpoint.baseSpeed 0
set module.trackpoint.speed 0.7
set module.trackpoint.xceleration 0.7
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
setLedTxt 100 ':::'
setLedTxt 100 '-::'
setLedTxt 100 ':-:'
setLedTxt 100 '::-'
setLedTxt 100 ':::'
```

$onKeymapChange ---:
```
replaceLayer mod CMX mod
replaceLayer mouse CMX mouse
replaceLayer fn CMX fn
replaceLayer fn2 CMX fn2
replaceLayer fn5 CMX fn5
set keymapAction.fn.b macro initCMX
fork keepAlive
```

$onKeymapChange CM2:
```
replaceLayer mod CMX mod
replaceLayer mouse CMX mouse
replaceLayer fn CMX fn
replaceLayer fn2 CMX fn2
replaceLayer fn5 CMX fn5
set keymapAction.fn5.isoKey macro initCMX
set secondaryRole.defaultStrategy advanced
set secondaryRole.advanced.timeout 250
set secondaryRole.advanced.timeoutAction secondary
set secondaryRole.advanced.triggerByRelease 1
// positive values for savetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +10
```

$onKeymapChange CMX:
```
setLedTxt 5000 CMX
set secondaryRole.defaultStrategy advanced
set secondaryRole.advanced.timeout 250
set secondaryRole.advanced.timeoutAction secondary
set secondaryRole.advanced.triggerByRelease 1
// positive values for savetyMargin favour primary role, negative favour secondary role
set secondaryRole.advanced.safetyMargin +5
set backlight.keyRgb.base.128 128 128 128
set backlight.keyRgb.base.129 128 128 128
set backlight.keyRgb.base.130 128 128 128
set backlight.keyRgb.mod.128 0 128 0
set backlight.keyRgb.mod.129 0 128 0
set backlight.keyRgb.mod.130 0 128 0
set backlight.keyRgb.mouse.128 0 128 128
set backlight.keyRgb.mouse.129 0 128 128
set backlight.keyRgb.mouse.130 0 128 128
set backlight.keyRgb.fn.128 128 0 0
set backlight.keyRgb.fn.129 128 0 0
set backlight.keyRgb.fn.130 128 0 0
set backlight.keyRgb.fn5.128 128 128 0
set backlight.keyRgb.fn5.129 128 128 0
set backlight.keyRgb.fn5.130 128 128 0
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

$onLayerChange base:
```
setLedTxt 1 ':::'
```

$onLayerChange fn:
```
#setLedTxt 0 FN
```

$onLayerChange fn2:
```
setLedTxt 0 XMC
```

$onLayerChange fn5:
```
setLedTxt 0 '123'

```

$onLayerChange mod:
```
setLedTxt 0 MAX
```

$onLayerChange mouse:
```
setLedTxt 0 MSE
```

clearStatus:
```
clearStatus
```

countdown:
```
if ( $count > 0 ) final setVar count 0
setVar count 30
loop:
setLedTxt 1000 $count
repeatFor count loop
toggleLayer fn
unToggleLayer
```

fn:
```
holdLayer fn
```

Go to UHK site in browser:
key ...
text ...
key ...

initCMX:
```
switchKeymap CMX

```

keepAlive:
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
moveMouse ...
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
moveMouse ...
```
ifNotKeymap --- goTo final
```
delay ...
moveMouse ...
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
moveMouse ...
```
ifNotKeymap --- goTo final
```
delay ...
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

maxtend:
```
ifLayer fn goTo altMaxtend
ifShift goTo shiftMaxtend
ifAlt goTo altMaxtend
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
tapKey backspace
setLedTxt 500 "<--"
goTo finish

secondaryaction:
holdLayer mod
break

shiftMaxtend:
setLedTxt 0 "<--"
suppressMods holdKey backspace
ifNotPlaytime 300 setLedTxt 300 "<--"
goTo finish

altMaxtend:
setLedTxt 0 "DEL"
suppressMods holdKey delete
ifNotPlaytime 300 setLedTxt 300 "DEL"
goTo finish

# restore Lcd display for current layer
finish:
ifLayer fn final setLedTxt 1 "FN"
toggleLayer mod
unToggleLayer
break

```

maxtend-simple:
```
ifShift goTo shiftMaxtend
//ifAlt final suppressMods holdKey delete
setLedTxt 0 MAX
holdLayer mod
ifReleased setLedTxt 1 MAX
ifInterrupted break
ifPlaytime 300 break
tapKey backspace
setLedTxt 500 <--
break
shiftMaxtend:
setLedTxt 0 <--
suppressMods holdKey backspace
ifReleased setLedTxt 1 MAX

```

mirror:
```
#setLedTxt 0 'XMC'
holdLayer fn2
#setLedTxt 1 'XMC'
```

mod:
```
ifLayer mod unToggleLayer
holdLayer mod
ifDoubletap toggleLayer mod

```

mousetend:
```
ifSecondary goTo secondaryaction
primaryaction: final tapKey space
secondaryaction: final holdLayer mouse

```

mute-unmute:
```
ifSecondary final holdKey LC-space
tapKey LCLS-m
ifNotShift break
delayUntil 300
tapKey LCLS-semicolonAndColon

```

nextKeyID:
```
resolveNextKeyId
```

numtab:
```
ifAlt final holdKey tab
ifSecondary advancedStrategy goTo secondaryaction

primaryaction:
ifShift goTo shiftTab
tapKey tab
setLedTxt 500 "->|"
break

secondaryaction:
ifShift goTo shiftTabSecondary
holdLayer fn5
break   

shiftTabSecondary:
ifNotLayer fn5 final toggleLayer fn5
unToggleLayer
break

shiftTab:
setLedTxt 0 "|<-"
holdKey tab
setLedTxt 500 "|<-"
break
```

numtab-toggle:
```
setLedTxt 0 "NUM"
toggleLayer fn5
```

printstatus:
```
printStatus
```
