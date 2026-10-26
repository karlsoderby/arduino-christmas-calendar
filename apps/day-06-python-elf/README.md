# Day 06 - Python Elf 🧝

The UNO Q has two brains: a Linux computer running Python, and a microcontroller running the sketch. In this App, a little Python elf tells the microcontroller when to blink the built-in LED, using the **Bridge**.

## You Need

- Arduino UNO Q

## Connect

Nothing to connect! The LED is already on the board.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. The LED blinks every second, and the Python console shows `Elf says: LED ON / OFF`.

## How It Works

- `sketch.ino` registers a function called `set_led` with `Bridge.provide()`.
- `main.py` calls it with `Bridge.call("set_led", True/False)`.
