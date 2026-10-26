# Day 15 - Snow Forecast 🌡️

Is it cold enough for snow? The Modulino Thermo measures the temperature and the LED matrix scrolls the forecast.

## You Need

- Arduino UNO Q
- Modulino Thermo
- Qwiic cable

## Connect

Plug the Modulino Thermo into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Read the temperature on the LED matrix.
4. Take the board outside (or hold the Modulino Thermo next to something cold) and see if the forecast changes to `SNOW!`.

## How It Works

- `thermo.getTemperature()` reads the temperature in °C from the Modulino Thermo.
- `String(temperature, 1)` turns the number into text with one decimal.
- An `if` statement adds `SNOW!` below 2 °C, or `NO SNOW` otherwise.
- The `ArduinoGraphics` library scrolls the text across the built-in LED matrix, then the sketch reads the temperature again.
