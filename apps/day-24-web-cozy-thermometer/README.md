# Day 24 - Cozy Christmas Thermometer 🧣

The UNO Q hosts a snowy web dashboard that shows the temperature and humidity from the Modulino Thermo, plus a little Christmas "mood" for the room.

## You Need

- Arduino UNO Q
- Modulino Thermo
- Qwiic cable

## Connect

Plug the Modulino Thermo into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the web page: App Lab opens it automatically, or browse to `http://<UNO-Q-IP-ADDRESS>:7000` from a device on the same network.
4. Breathe on the sensor and watch the values change.

## How It Works

1. `sketch.ino` reads the sensor and sends the values with `Bridge.notify("thermo", ...)`.
2. `main.py` receives them and passes them to the web page with `ui.send_message()`.
3. `assets/app.js` updates the numbers and picks a mood: ☃️ 🧤 🎄 🔥
