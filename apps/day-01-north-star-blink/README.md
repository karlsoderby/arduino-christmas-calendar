# Day 01 - North Star Blink ⭐

Make the built-in LED on the UNO Q twinkle like the North Star.

## You Need

- Arduino UNO Q

## Connect

Nothing to connect! The LED is already on the board.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Watch the built-in LED twinkle: two quick flashes, then a pause.

## How It Works

- `pinMode(LED_BUILTIN, OUTPUT)` sets the built-in LED pin as an output.
- The built-in LED is *active low*: `LOW` turns it on and `HIGH` turns it off.
- `loop()` turns the LED on and off twice with short `delay(150)` pauses, then waits one second with `delay(1000)` before starting again.

## Try This

Change the `delay()` values to make the star twinkle faster or slower.
