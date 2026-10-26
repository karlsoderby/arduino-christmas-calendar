# Day 10 - Advent Countdown 📅

How many days until Christmas? Python checks the date on the UNO Q and the LED matrix scrolls the countdown.

## You Need

- Arduino UNO Q (connected to the internet, so the clock is correct)

## Connect

Nothing to connect! The LED matrix is on the board.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Watch the LED matrix scroll, for example, `12 DAYS TO CHRISTMAS`.

## How It Works

- `main.py` counts the days to 25 December and sends the number with `Bridge.notify("set_days", days)`.
- `sketch.ino` receives it in `set_days()` and scrolls the text on the matrix.
