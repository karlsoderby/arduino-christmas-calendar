# Day 25 - Christmas Jukebox
# Each button on the web page sends a song number to the sketch.
from arduino.app_utils import App, Bridge
from arduino.app_bricks.web_ui import WebUI

ui = WebUI()


def on_play_song(client, data):
    song = int(data.get("song", 1))
    print(f"Playing song {song}")
    Bridge.notify("play_song", song)


ui.on_message("play_song", on_play_song)

App.run()
