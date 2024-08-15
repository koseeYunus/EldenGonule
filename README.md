# Elden Gonule Project

This Arduino project implements a multilingual touch-activated audio device with LCD display support. The device allows users to play audio messages in different languages (Turkish, English, and Spanish) by touching various combinations of sensors.

## Features

- Supports multiple languages (Turkish, English, Spanish)
- Touch-activated audio playback
- LCD display for visual feedback
- DFPlayer Mini MP3 module for audio output
- Language selection buttons
- 24 touch sensors (12 right, 12 left) for various combinations

## Hardware Requirements

- Arduino board (compatible with the used pins)
- DFPlayer Mini MP3 module
- 20x4 I2C LCD display
- 24 touch sensors
- Speaker for audio output

## Libraries Used

- Wire.h
- LiquidCrystal_I2C.h
- SoftwareSerial.h
- DFPlayer_Mini_Mp3.h

## Pin Configuration

- LCD I2C: SDA and SCL pins (address 0x27)
- DFPlayer Mini: pins 10 (RX) and 11 (TX)
- Touch sensors: pins 22-45
- Language selection buttons: pins 2, 3, 4

## Setup

1. Connect all hardware components according to the pin configuration.
2. Install the required libraries in your Arduino IDE.
3. Upload the provided code to your Arduino board.
4. Prepare an SD card with MP3 files numbered according to the code's audio mappings.
5. Insert the SD card into the DFPlayer Mini module.

## Usage

1. Power on the device.
2. Select the desired language using the language selection buttons.
3. Touch the sensors in various combinations to play different audio messages.
4. The LCD display will show relevant information for each action.

## Customization

- Modify the `TurkceKonus()`, `IngilizceKonus()`, and `IspanyolcaKonus()` functions to change or add new touch combinations and corresponding audio messages.
- Adjust the `lcdYaz()` function calls to change the displayed text for each action.

## Note

Ensure that your MP3 files are properly numbered and stored on the SD card according to the audio mappings in the code.
