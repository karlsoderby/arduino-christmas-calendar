# Day 02 - Tree Light 🎄

Blink an LED on a breadboard, just like a light on the Christmas tree.

## You Need

- Arduino UNO Q
- Breadboard
- 2x jumper wires
- 1x LED (red or green is extra festive)
- 1x 220 Ω resistor

## Connect

1. Place the LED and the 220 Ω resistor on the breadboard, with one resistor leg in the same row as the LED **long leg** (+).
2. Connect a jumper wire from UNO Q **D2** to the row with the free resistor leg.
3. Connect a jumper wire from the row with the LED **short leg** (-) back to UNO Q **GND**.

| From | To |
|------|----|
| UNO Q **D2** | Jumper wire to the resistor on the breadboard |
| Resistor (other leg) | LED **long leg** (+) |
| LED **short leg** (-) | Jumper wire back to UNO Q **GND** |

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. The LED blinks on and off every half second.

## How It Works

- `pinMode(ledPin, OUTPUT)` sets pin D2 as an output.
- `digitalWrite(ledPin, HIGH)` sends 3.3 V to D2, so current flows through the resistor and LED to GND, and the LED turns on.
- `digitalWrite(ledPin, LOW)` sets D2 to 0 V and the LED turns off.
- `delay(500)` waits half a second between each change.
- The resistor limits the current so the LED doesn't burn out.

## Try This

Add a second LED on pin D3 and make the two LEDs blink one after the other.
