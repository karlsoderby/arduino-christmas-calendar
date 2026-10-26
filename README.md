# Arduino UNO Q Christmas Calendar 🎄

25 small, Christmas-themed Apps for the **Arduino UNO Q**, one for every day of advent. They start with simple breadboard basics, move on to the built-in LED matrix, then to Modulino nodes, and finish with festive web pages hosted by the UNO Q.

## Material

- Arduino UNO Q
- Modulino nodes: Buttons, Buzzer, Distance, Joystick, Knob, Light, LED Matrix, Movement, Pixels, Thermo, Vibro
- Qwiic cables
- Breadboard and jumper wires
- For days 2-5: 1x LED, 1x 220 Ω resistor, 1x push button, 1x 10 kΩ potentiometer
- For day 22: 1x small hobby servo motor (for example SG90), paper or thin cardboard, scissors and tape

## How to Use

Each day has two versions:

- `apps/<day>/` - the source code, with a short `README.md` explaining how to connect and run it.
- `zips/<day>.zip` - the same App packaged for **import into Arduino App Lab**.

To import an App in Arduino App Lab:

1. Open any App.
2. Select the arrow (**▼**) next to the App name near the top left corner.
3. Select **Import App**.
4. Drag and drop the `.zip` file into the import area, or select **Import from computer**.
5. Select **Open**.

## The Calendar

| Day | App | Hardware |
|-----|-----|----------|
| 01 | [⭐ North Star Blink](apps/day-01-north-star-blink) | Built-in LED |
| 02 | [🎄 Tree Light](apps/day-02-tree-light) | LED + resistor on breadboard |
| 03 | [🎁 Present Button](apps/day-03-present-button) | Push button on breadboard |
| 04 | [❄️ Snow-o-Meter](apps/day-04-snow-o-meter) | Potentiometer on breadboard |
| 05 | [🔥 Fireplace Dimmer](apps/day-05-fireplace-dimmer) | LED + potentiometer on breadboard |
| 06 | [🧝 Python Elf](apps/day-06-python-elf) | Built-in LED, controlled from Python |
| 07 | [🎄 Matrix Christmas Tree](apps/day-07-matrix-christmas-tree) | Built-in LED matrix |
| 08 | [🌨️ Matrix Snowfall](apps/day-08-matrix-snowfall) | Built-in LED matrix |
| 09 | [📜 Merry Christmas Scroller](apps/day-09-merry-christmas-scroller) | Built-in LED matrix |
| 10 | [📅 Advent Countdown](apps/day-10-advent-countdown) | Built-in LED matrix + Python |
| 11 | [💡 Christmas Lights](apps/day-11-pixels-christmas-lights) | Modulino Pixels |
| 12 | [🔔 Jingle Bells](apps/day-12-buzzer-jingle-bells) | Modulino Buzzer |
| 13 | [🎁 Gift Picker](apps/day-13-buttons-gift-picker) | Modulino Buttons + LED matrix |
| 14 | [🎛️ Light Up the Tree](apps/day-14-knob-light-up-the-tree) | Modulino Knob + Pixels |
| 15 | [🌡️ Snow Forecast](apps/day-15-thermo-snow-forecast) | Modulino Thermo + LED matrix |
| 16 | [🎅 Santa Detector](apps/day-16-distance-santa-detector) | Modulino Distance + Buzzer |
| 17 | [🔮 Shake the Snow Globe](apps/day-17-movement-snow-globe) | Modulino Movement + LED matrix |
| 18 | [🌙 Night-time Tree](apps/day-18-light-night-time-tree) | Modulino Light + Pixels |
| 19 | [📦 Guess the Present](apps/day-19-vibro-guess-the-present) | Modulino Buttons + Vibro |
| 20 | [🦌 Rudolph's Star Hunt](apps/day-20-joystick-rudolph-star-hunt) | Modulino Joystick + LED matrix |
| 21 | [🪧 Ho Ho Ho Sign](apps/day-21-modulino-matrix-ho-ho-ho) | Modulino LED Matrix |
| 22 | [� Waving Santa](apps/day-22-servo-waving-santa) | Servo motor + Modulino Buttons + paper cut-out |
| 23 | [🎮 Christmas Light Remote](apps/day-23-web-light-remote) | Web UI + Modulino Pixels |
| 24 | [🧣 Cozy Christmas Thermometer](apps/day-24-web-cozy-thermometer) | Web UI + Modulino Thermo |
| 25 | [🎶 Christmas Jukebox](apps/day-25-web-christmas-jukebox) | Web UI + Modulino Buzzer + Pixels |

## Calendar Website

The `site/` folder is a web page built around the calendar picture. Click the board at the top for the introduction, or click a door to open that day's instructions.

1. After editing any `README.md` (or `site/intro.md`), rebuild the content:

   ```bash
   python3 site/build.py
   ```

2. Serve the **repository root** (so the download links to `zips/` work) and open `/site/`:

   ```bash
   python3 -m http.server 8000
   ```

   Then browse to `http://localhost:8000/site/`.

3. **Live site:** [karlsoderby.github.io/arduino-christmas-calendar](https://karlsoderby.github.io/arduino-christmas-calendar/). It's hosted on GitHub Pages, and every push to `main` rebuilds and redeploys it automatically (see `.github/workflows/pages.yml`).

## App Structure

```
day-XX-name/
├── app.yaml          # App name, icon, description and bricks
├── README.md         # How to connect and run
├── python/main.py    # Python code (runs on the Linux side)
├── sketch/
│   ├── sketch.ino    # Arduino sketch (runs on the microcontroller)
│   └── sketch.yaml   # Platform and library versions
└── assets/           # Web page (only for days 23-25)
```

## Resources

- [Arduino_Modulino library](https://github.com/arduino-libraries/Arduino_Modulino)
- [App Bricks (source code)](https://github.com/arduino/app-bricks-py)
- [App Bricks examples](https://github.com/arduino/app-bricks-examples)
