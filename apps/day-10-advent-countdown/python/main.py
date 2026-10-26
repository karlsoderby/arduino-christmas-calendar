# Day 10 - Advent Countdown
# Python checks today's date, counts the days until Christmas Day (25 December),
# and sends the number to the sketch, which scrolls it on the LED matrix.
import time
from datetime import date

from arduino.app_utils import App, Bridge


def days_to_christmas():
    today = date.today()
    christmas = date(today.year, 12, 25)
    if today > christmas:
        christmas = date(today.year + 1, 12, 25)
    return (christmas - today).days


def loop():
    days = days_to_christmas()
    print(f"{days} days to Christmas")
    Bridge.notify("set_days", days)
    time.sleep(10)


App.run(user_loop=loop)
