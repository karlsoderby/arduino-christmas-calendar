# Day 14 - Light Up the Tree 🎛️

Turn the Modulino Knob to switch on the tree lights on the Modulino Pixels, one by one. Press the knob to switch them all off.

## You Need

- Arduino UNO Q
- Modulino Knob
- Modulino Pixels
- 2x Qwiic cables

## Connect

1. Plug the Modulino Knob into the **Qwiic connector** on the UNO Q.
2. Plug the Modulino Pixels into the free Qwiic connector on the Modulino Knob (daisy chain).

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Turn the knob clockwise to add lights, counter-clockwise to remove them.
4. Press the knob to turn all lights off.

## How It Works

- `knob.get()` returns a number that goes up or down as you turn the knob.
- The sketch keeps the number between 0 and 8 with `knob.set()`, one step for each LED.
- `knob.isPressed()` checks for a press and sets the number back to 0.
- In the `for` loop, LEDs below the number turn on in red and green, and the rest are switched off with `pixels.clear()`.
