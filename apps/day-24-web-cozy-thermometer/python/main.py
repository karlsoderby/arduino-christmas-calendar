# Day 24 - Cozy Christmas Thermometer
# The sketch sends temperature and humidity every 2 seconds.
# Python forwards the values to the web page.
from arduino.app_utils import App, Bridge
from arduino.app_bricks.web_ui import WebUI

ui = WebUI()


def on_thermo(temperature: float, humidity: float):
    ui.send_message("thermo", {"temperature": temperature, "humidity": humidity})


Bridge.provide("thermo", on_thermo)

App.run()
