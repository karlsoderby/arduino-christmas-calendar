# Day 16 - Santa Detector 🎅

Catch Santa in the act! When something comes closer than 20 cm to the Modulino Distance, the Modulino Buzzer sounds the alarm.

## You Need

- Arduino UNO Q
- Modulino Distance
- Modulino Buzzer
- 2x Qwiic cables

## Connect

1. Plug the Modulino Distance into the **Qwiic connector** on the UNO Q.
2. Plug the Modulino Buzzer into the free Qwiic connector on the Modulino Distance (daisy chain).

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the **Serial Monitor** in App Lab.
4. Move your hand in front of the sensor. The buzzer beeps and `HO HO HO! Santa spotted` is printed.

## How It Works

- The Modulino Distance measures distance with an invisible infrared laser (time-of-flight).
- `distance.available()` checks for a new measurement, and `distance.get()` returns it in millimeters.
- If the distance is below `TRIGGER_MM`, the sketch prints a message and plays two beeps with `buzzer.tone(frequency, duration)`.

## Try This

Change `TRIGGER_MM` to make the detector more or less sensitive.
