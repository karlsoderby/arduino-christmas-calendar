# Day 25 - Christmas Jukebox 🎶

Merry Christmas! The grand finale: the UNO Q hosts a festive jukebox web page. Pick a song and the Modulino Buzzer plays it while the Modulino Pixels flash along to the beat.

Songs:

- 🔔 Jingle Bells
- 🎁 We Wish You a Merry Christmas
- 🌟 Silent Night

## You Need

- Arduino UNO Q
- Modulino Buzzer
- Modulino Pixels
- 2x Qwiic cables

## Connect

1. Plug the Modulino Buzzer into the **Qwiic connector** on the UNO Q.
2. Plug the Modulino Pixels into the free Qwiic connector on the Modulino Buzzer (daisy chain).

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Open the web page: App Lab opens it automatically, or browse to `http://<UNO-Q-IP-ADDRESS>:7000` from a device on the same network.
4. Click a song and enjoy the show!

## How It Works

1. The web page sends the song number to Python.
2. `main.py` forwards it to the sketch with `Bridge.notify("play_song", song)`.
3. `sketch.ino` plays the notes and lights one LED per note.
