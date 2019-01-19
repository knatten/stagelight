Build:
```
arduino-cli compile --fqbn arduino:avr:leonardo && arduino-cli upload -p /dev/cu.usbmodem* --fqbn arduino:avr:leonardo
```

Monitor:
- `screen /dev/cu.usbmodem* 115200`
- `Ctrl+a, Ctrl+\, y` to quit
