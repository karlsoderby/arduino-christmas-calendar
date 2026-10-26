# Day 06 - Python Elf
# Python (running on Linux) tells the microcontroller when to switch the LED on and off.
import time

from arduino.app_utils import App, Bridge

led_on = False


def loop():
    global led_on
    led_on = not led_on
    Bridge.call("set_led", led_on)
    print("Elf says: LED", "ON" if led_on else "OFF")
    time.sleep(1)


App.run(user_loop=loop)
