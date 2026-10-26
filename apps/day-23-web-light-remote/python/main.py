# Day 23 - Christmas Light Remote
# A web page with buttons. Each click sends a light mode to the sketch,
# which animates the Modulino Pixels.
from arduino.app_utils import App, Bridge
from arduino.app_bricks.web_ui import WebUI

ui = WebUI()


def on_set_mode(client, data):
    mode = int(data.get("mode", 0))
    print(f"Light mode: {mode}")
    Bridge.notify("set_mode", mode)


ui.on_message("set_mode", on_set_mode)

App.run()
