# Day 03 - Present Button 🎁

Every press of the button "opens a present". The built-in LED lights up and the number of opened presents is printed.

## You Need

- Arduino UNO Q
- Breadboard
- 2x jumper wires
- 1x push button

## Connect

1. Place the push button across the gap in the middle of the breadboard.
2. Connect a jumper wire from UNO Q **D2** to the row with one button leg.
3. Connect a jumper wire from the row with the diagonally opposite button leg back to UNO Q **GND**.

| From | To |
|------|----|
| UNO Q **D2** | Jumper wire to button leg 1 on the breadboard |
| Button leg 2 (diagonal) | Jumper wire back to UNO Q **GND** |

No resistor needed: the sketch uses the internal pull-up resistor.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the **Serial Monitor** in App Lab.
4. Press the button and watch the present counter go up.

## How It Works

- `pinMode(buttonPin, INPUT_PULLUP)` turns on a resistor inside the board that keeps D2 `HIGH` when the button isn't pressed.
- Pressing the button connects D2 to GND, so `digitalRead()` returns `LOW`.
- The sketch counts a present only when the state changes from `HIGH` to `LOW`, so holding the button counts as one press.
- `Monitor.println()` prints the count to the App Lab Serial Monitor.
- `delay(20)` gives the button time to settle (debounce).
