# Day 13 - Gift Picker 🎁

Press a button on the Modulino Buttons to pick what is shown on the LED matrix:

| Button | Shows |
|--------|-------|
| A | Christmas tree |
| B | Star |
| C | Gift |

## You Need

- Arduino UNO Q
- Modulino Buttons
- Qwiic cable

## Connect

Plug the Modulino Buttons into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Press **A**, **B** or **C** and look at the LED matrix.

## How It Works

- `tree`, `star` and `gift` are three pictures for the 8x13 LED matrix.
- `buttons.update()` returns `true` when a button changes state.
- `buttons.isPressed('A')` (or `'B'`, `'C'`) checks which button is pressed, and `matrix.draw()` shows the matching picture.
- `buttons.setLeds()` lights the small LED above the button you picked.
