# Day 23 - Christmas Light Remote 🎮

The UNO Q hosts a festive web page. Open it on your phone or computer and pick a light show for the Modulino Pixels.

| Button | Light show |
|--------|------------|
| 🎄 Classic | Red and green swapping places |
| 🍭 Candy Cane | Moving red and white stripes |
| ❄️ Snow Twinkle | Random white sparkles |
| ✨ Golden Glow | Warm gold light |
| 🌙 Lights Off | All off |

## You Need

- Arduino UNO Q
- Modulino Pixels
- Qwiic cable

## Connect

Plug the Modulino Pixels into the **Qwiic connector** on the UNO Q with the Qwiic cable.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the web page: App Lab opens it automatically, or browse to `http://<UNO-Q-IP-ADDRESS>:7000` from a device on the same network.
4. Click the buttons to change the light show.

## How It Works

1. `assets/index.html` is the web page, served by the **Web UI** brick. Each button has a mode number.
2. When you click a button, `assets/app.js` sends a `set_mode` message to Python.
3. `main.py` receives it and sends the mode to the sketch with `Bridge.notify("set_mode", mode)`.
4. `sketch.ino` stores the mode and `loop()` animates the Modulino Pixels for that mode.
