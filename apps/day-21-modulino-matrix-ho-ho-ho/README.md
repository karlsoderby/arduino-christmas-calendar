# Day 21 - Ho Ho Ho Sign 🪧

Make a Christmas sign! The Modulino LED Matrix scrolls `HO HO HO!` and `MERRY CHRISTMAS`.

## You Need

- Arduino UNO Q
- Modulino LED Matrix
- Qwiic cable

## Connect

Plug the Modulino LED Matrix into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Read the messages on the Modulino LED Matrix.

## How It Works

- `ModulinoLEDMatrix` controls the Modulino LED Matrix over the Qwiic connection.
- Including `ArduinoGraphics` lets the matrix draw text, the same way as on the built-in matrix on Day 09.
- The `scrollText()` function sets the font and speed, then scrolls the text from right to left.
- `loop()` calls `scrollText()` once for each message.

## Try This

Add another `scrollText("...")` line in `loop()` with your own greeting.
