# Day 11 - Christmas Lights 💡

Turn the Modulino Pixels into a string of red, green and white Christmas lights that chase each other.

## You Need

- Arduino UNO Q
- Modulino Pixels
- Qwiic cable

## Connect

Plug the Modulino Pixels into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Watch the lights chase along the Modulino Pixels.

## How It Works

- `Modulino.begin()` starts the Qwiic connection, and `pixels.begin()` finds the Modulino Pixels.
- The `colors` list holds red, green and white.
- `pixels.set()` gives each of the 8 LEDs a color from the list, shifted by `offset`.
- `pixels.show()` sends the colors to the LEDs. Increasing `offset` each loop moves the pattern one step.

## Try This

- Add `YELLOW` or `BLUE` to the `colors` list (and change `% 3` to match the number of colors).
- Change the brightness value `10` (0 - 100).
