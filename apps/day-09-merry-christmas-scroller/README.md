# Day 09 - Merry Christmas Scroller 📜

Scroll "MERRY CHRISTMAS!" across the built-in LED matrix.

## You Need

- Arduino UNO Q

## Connect

Nothing to connect! The LED matrix is on the board.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Read the greeting as it scrolls across the LED matrix.

## How It Works

- Including the `ArduinoGraphics` library lets the LED matrix draw text.
- `matrix.textFont(Font_5x7)` picks a font that is 7 LEDs tall.
- `beginText()`, `print()` and `endText(SCROLL_LEFT)` scroll the text from right to left.
- `textScrollSpeed()` sets how fast it moves. A lower number scrolls faster.

## Try This

Change the text inside `matrix.print("...")` to your own message, like `"GOD JUL"` or `"HO HO HO"`.
