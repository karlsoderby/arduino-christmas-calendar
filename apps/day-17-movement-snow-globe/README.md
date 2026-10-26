# Day 17 - Shake the Snow Globe 🔮

Turn your UNO Q into a snow globe. Shake the Modulino Movement and snow falls on the LED matrix.

## You Need

- Arduino UNO Q
- Modulino Movement
- Qwiic cable

## Connect

Plug the Modulino Movement into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Shake the Modulino Movement and watch it snow on the LED matrix.

## How It Works

- `movement.getX()`, `getY()` and `getZ()` return the acceleration on each axis, in g.
- When it is still, the total acceleration is about 1 g (gravity). Shaking makes it much bigger.
- When the total is above `1.8`, `snowTime` is set to 40 steps of snowfall.
- While `snowTime` is above 0, new snowflakes appear on the top row. Every loop, the snow moves one row down, the same way as on Day 08.

## Try This

Change `1.8` to a lower number (like `1.4`) if you need to shake less, or higher if it snows too easily.
