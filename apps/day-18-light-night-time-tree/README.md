# Day 18 - Night-time Tree 🌙

Tree lights that turn on by themselves when it gets dark. The Modulino Light measures the light level, and the Modulino Pixels glow warm white when it is dark.

## You Need

- Arduino UNO Q
- Modulino Light
- Modulino Pixels
- 2x Qwiic cables

## Connect

1. Plug the Modulino Light into the **Qwiic connector** on the UNO Q.
2. Plug the Modulino Pixels into the free Qwiic connector on the Modulino Light (daisy chain).

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the **Serial Monitor** in App Lab to see the light level in lux.
4. Cover the Modulino Light with your hand. The tree lights turn on!

## How It Works

- `light.update()` reads the sensor, and `light.getLux()` returns the light level in lux.
- If the light level is below `DARK_LUX`, all 8 Modulino Pixels LEDs are set to a warm white color.
- Otherwise, the LEDs are switched off with `pixels.clear()`.
- The light level is printed to the Serial Monitor every half second.

## Try This

Change `DARK_LUX` to match the light in your room.
