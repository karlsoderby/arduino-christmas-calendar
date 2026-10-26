# Day 19 - Guess the Present 📦

Shake the presents! Each button on the Modulino Buttons makes the Modulino Vibro shake in a different way. Can a friend guess which present it is with their eyes closed?

| Button | Present | Feels like |
|--------|---------|------------|
| A | Teddy bear | One soft, long rumble |
| B | Drum | Four short, hard taps |
| C | Toy train | Chug-chug, chug-chug |

## You Need

- Arduino UNO Q
- Modulino Buttons
- Modulino Vibro
- 2x Qwiic cables

## Connect

1. Plug the Modulino Buttons into the **Qwiic connector** on the UNO Q.
2. Plug the Modulino Vibro into the free Qwiic connector on the Modulino Buttons (daisy chain).

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Hold the Modulino Vibro in your hand and press **A**, **B** or **C**.

## How It Works

- `buttons.update()` and `buttons.isPressed()` check which button was pressed.
- Each button runs its own function: `teddyBear()`, `drum()` or `toyTrain()`.
- `vibro.on(time, true, power)` vibrates for `time` milliseconds at a power level from `GENTLE` to `MAXIMUM`.
- Changing the length, power and pauses between vibrations makes each present feel different.
