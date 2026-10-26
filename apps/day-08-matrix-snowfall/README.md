# Day 08 - Matrix Snowfall 🌨️

Let it snow! Random snowflakes fall down the built-in LED matrix.

## You Need

- Arduino UNO Q

## Connect

Nothing to connect! The LED matrix is on the board.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Watch the snow fall on the LED matrix.

## How It Works

- The `snow` array holds the brightness of all 104 LEDs (8 rows x 13 columns).
- Each loop, every row is copied one row down, so the snowflakes fall.
- The top row is then filled with new random snowflakes with random brightness.
- `matrix.draw(snow)` shows the result, and `delay(200)` sets the speed.

## Try This

- Change `random(6)` to `random(2)` for a blizzard, or `random(15)` for light snow.
- Change `delay(200)` to make the snow fall faster or slower.
