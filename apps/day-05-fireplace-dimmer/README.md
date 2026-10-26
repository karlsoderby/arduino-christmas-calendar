# Day 05 - Fireplace Dimmer 🔥

Turn the potentiometer to make the "fire" brighter or dimmer. The LED flickers a little, like a real fireplace.

## You Need

- Arduino UNO Q
- Breadboard
- 5x jumper wires
- 1x LED (yellow, orange or red)
- 1x 220 Ω resistor
- 1x potentiometer (10 kΩ)

## Connect

**LED**

1. Place the LED and the 220 Ω resistor on the breadboard, with one resistor leg in the same row as the LED **long leg** (+).
2. Connect a jumper wire from UNO Q **D9** to the row with the free resistor leg.
3. Connect a jumper wire from the row with the LED **short leg** (-) back to UNO Q **GND**.

| From | To |
|------|----|
| UNO Q **D9** | Jumper wire to the resistor on the breadboard |
| Resistor (other leg) | LED **long leg** (+) |
| LED **short leg** (-) | Jumper wire back to UNO Q **GND** |

**Potentiometer**

1. Place the potentiometer on the breadboard so each of its three legs is in its own row.
2. Connect a jumper wire from UNO Q **3.3V** to the row with the left leg.
3. Connect a jumper wire from UNO Q **A0** to the row with the middle leg.
4. Connect a jumper wire from the row with the right leg back to a UNO Q **GND** pin.

| Potentiometer pin | UNO Q |
|-------------------|-------|
| Left leg | Jumper wire to **3.3V** |
| Middle leg (wiper) | Jumper wire to **A0** |
| Right leg | Jumper wire to **GND** |

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Turn the potentiometer to adjust the fire.

## How It Works

- `analogRead(A0)` reads the potentiometer as a number from 0 to 1023.
- `map()` scales it to 0-255, the range used by `analogWrite()`.
- `analogWrite()` uses PWM (switching the pin on and off very fast) on D9 to dim the LED.
- A small `random()` value is added to the brightness, and the `delay()` is random too, so the LED flickers like a fire.
