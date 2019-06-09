Build:

For the Leonardo:
```
arduino-cli compile --fqbn arduino:avr:leonardo && arduino-cli upload -p /dev/cu.usbmodem* --fqbn arduino:avr:leonardo
```

For the 3,3V pro micro:
```
arduino-cli compile --fqbn SparkFun:avr:promicro:cpu=8MHzatmega32U4 && arduino-cli upload -p /dev/cu.usbmodem* --fqbn SparkFun:avr:promicro:cpu=8MHzatmega32U4
```

Monitor:
- `screen /dev/cu.usbmodem* 115200`
- `Ctrl+a, Ctrl+\, y` to quit
