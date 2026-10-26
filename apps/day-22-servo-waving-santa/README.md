# Day 22 - Waving Santa 👋

Make a paper Santa that waves at you! A servo motor moves Santa's paper arm when you press a button on the Modulino Buttons.

| Button | Santa does |
|--------|------------|
| A | Waves hello (fast) |
| B | Waves goodbye (slow) |

## You Need

- Arduino UNO Q
- Modulino Buttons
- Qwiic cable
- 1x small hobby servo motor (for example SG90), with a servo horn (the plastic arm)
- 3x jumper wires (male-to-male)
- Paper or thin cardboard, colored pens, scissors and tape

## Make the Paper Santa

1. Draw Santa's body (hat, face, beard and red coat) on paper or cardboard, about 10-15 cm tall, and cut it out.
2. Draw and cut out one arm with a mitten, about 6-8 cm long.
3. Make a small hole in Santa's shoulder and push the servo shaft through it from behind, so the servo sits behind Santa. Tape the servo in place.
4. Press the servo horn onto the shaft from the front, and tape the paper arm to the horn.

## Connect

**Servo motor**

1. Connect a jumper wire from the servo **signal** wire (orange or yellow) to UNO Q **D9**.
2. Connect a jumper wire from the servo **power** wire (red) to UNO Q **5V**.
3. Connect a jumper wire from the servo **ground** wire (brown or black) back to UNO Q **GND**.

| Servo wire | UNO Q |
|------------|-------|
| Signal (orange / yellow) | Jumper wire to **D9** |
| Power (red) | Jumper wire to **5V** |
| Ground (brown / black) | Jumper wire to **GND** |

**Modulino Buttons**

Plug the Modulino Buttons into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**. The servo moves to its resting position (90°).
3. If the arm doesn't point the way you want, pull off the servo horn and press it back on at a better angle.
4. Press **A** or **B** and watch Santa wave!

## How It Works

- The `Servo` library controls the servo motor on D9. `arm.write(angle)` turns the servo to an angle between 0° and 180°.
- The `wave()` function moves the arm between `ARM_LEFT` and `ARM_RIGHT` a number of times, then back to `ARM_DOWN`.
- The `speedMs` value sets how long to wait at each side, so a smaller number gives a faster wave.
- `buttons.update()` and `buttons.isPressed()` check which button was pressed, and `buttons.setLeds()` lights the LED above it while Santa waves.

## Try This

- Change `ARM_LEFT` and `ARM_RIGHT` to make bigger or smaller waves.
- Make a paper reindeer that nods its head, or a Christmas tree that spins its star.
