# Day 20 - Rudolph's Star Hunt 🦌

A tiny game! Steer Rudolph (the bright dot) around the LED matrix with the Modulino Joystick and catch the blinking stars.

## You Need

- Arduino UNO Q
- Modulino Joystick
- Qwiic cable

## Connect

Plug the Modulino Joystick into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the **Serial Monitor** in App Lab to see your score.
4. Move the joystick to steer Rudolph onto the blinking star.

## How It Works

- `joystick.getX()` and `getY()` return a value around 0 in the middle, and up to about ±128 when pushed all the way.
- When the stick is pushed past 60, Rudolph moves one LED in that direction. The sketch stops him at the edges.
- When Rudolph lands on the star, the score goes up and `random()` places a new star.
- Each loop, the `frame` array is cleared, the star (dim and blinking) and Rudolph (bright) are drawn, and `matrix.draw()` shows them.

## Note

If Rudolph moves in the wrong direction, turn the Modulino Joystick around, or swap the `+` and `-` in the movement code.
