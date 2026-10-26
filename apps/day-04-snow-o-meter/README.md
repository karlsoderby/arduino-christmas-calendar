# Day 04 - Snow-o-Meter ❄️

Turn a potentiometer into a snow forecast. Turn the knob to go from "no snow" to "blizzard".

## You Need

- Arduino UNO Q
- Breadboard
- 3x jumper wires
- 1x potentiometer (10 kΩ)

## Connect

1. Place the potentiometer on the breadboard so each of its three legs is in its own row.
2. Connect a jumper wire from UNO Q **3.3V** to the row with the left leg.
3. Connect a jumper wire from UNO Q **A0** to the row with the middle leg.
4. Connect a jumper wire from the row with the right leg back to UNO Q **GND**.

| Potentiometer pin | UNO Q |
|-------------------|-------|
| Left leg | Jumper wire to **3.3V** |
| Middle leg (wiper) | Jumper wire to **A0** |
| Right leg | Jumper wire to **GND** |

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the **Serial Monitor** in App Lab.
4. Turn the potentiometer and read the forecast.

## How It Works

- The potentiometer works as a voltage divider: turning it changes the voltage on the middle leg between 0 V and 3.3 V.
- `analogRead(A0)` turns that voltage into a number from 0 to 1023.
- `map()` converts the number to a 0-100 % "snow level".
- `if` / `else if` statements pick the forecast text, which `Monitor.println()` prints every half second.
