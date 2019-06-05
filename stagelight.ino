#include "MIDIUSB.h"

const uint8_t NAME_A0 = A0;
const uint8_t NAME_A1 = A1;
const uint8_t NAME_A2 = A2;
const uint8_t NAME_A3 = A3;
const uint8_t NAME_4 = A6;
const uint8_t NAME_6 = A7;
const uint8_t NAME_8 = A8;
const uint8_t NAME_9 = A9;
const uint8_t NAME_10 = A10;
const int NO_PIN = -1;

const uint8_t NOTE_C1 = 0x24;
const uint8_t NOTE_CS1 = 0x25;
const uint8_t NOTE_D1 = 0x26;
const uint8_t NOTE_DS1 = 0x27;
const uint8_t NOTE_E1 = 0x28;
const uint8_t NOTE_F1 = 0x29;
const uint8_t NOTE_FS1 = 0x2A;
const uint8_t NOTE_G1 = 0x2B;
const uint8_t NOTE_GS1 = 0x2C;
const uint8_t NOTE_A1 = 0x2D;
const uint8_t NOTE_AS1 = 0x2E;
const uint8_t NOTE_B1 = 0x2F;

void setup() {
  pinMode(NAME_A0, OUTPUT);
  pinMode(NAME_A1, OUTPUT);
  pinMode(NAME_A2, OUTPUT);
  pinMode(NAME_A3, OUTPUT);
  pinMode(NAME_4, OUTPUT);
  pinMode(NAME_6, OUTPUT);
  pinMode(NAME_8, OUTPUT);
  pinMode(NAME_9, OUTPUT);
  pinMode(NAME_10, OUTPUT);
}

int noteToPin(uint8_t note) {
  Serial.println();
  Serial.print("note : ");
  Serial.print(note, HEX);
  if (note == NOTE_C1)
    return NAME_A0;
  if (note == NOTE_CS1)
    return NAME_8;
  if (note == NOTE_D1)
    return NAME_A3;

  if (note == NOTE_E1)
    return NAME_A1;
  if (note == NOTE_F1)
    return NAME_9;
  if (note == NOTE_FS1)
    return NAME_4;

  if (note == NOTE_GS1)
    return NAME_A2;
  if (note == NOTE_A1)
    return NAME_10;
  if (note == NOTE_AS1)
    return NAME_6;

  return -1;
}

void noteOn(uint8_t note) {
  int pin = noteToPin(note);
  if (pin != -1) {
    digitalWrite(pin, HIGH);
  }
}

void noteOff(uint8_t note) {
  int pin = noteToPin(note);
  if (pin != -1) {
    digitalWrite(pin, LOW);
  }
}

void loop() {
  /* Serial.println(); */
  /* Serial.println("loop"); */
  midiEventPacket_t rx = MidiUSB.read();
  if (rx.header != 0) {
    if (rx.header == 0x09) {
      noteOn(rx.byte2);
    }
    if (rx.header == 0x08) {
      noteOff(rx.byte2);
    }
  }
}
