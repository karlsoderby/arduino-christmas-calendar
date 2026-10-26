# Day 07 - Matrix Christmas Tree 🎄

Draw a Christmas tree on the built-in 8x13 LED matrix, with ornaments that twinkle.

## You Need

- Arduino UNO Q

## Connect

Nothing to connect! The LED matrix is on the board.

## Run

1. Import the App into Arduino App Lab.
2. Click **Run**.
3. Look at the LED matrix: a tree with blinking ornaments appears.

## How It Works

- The LED matrix has 8 rows and 13 columns, so 104 LEDs.
- `treeA` and `treeB` are two pictures (frames) of the tree, with the ornaments in different places.
- `matrix.setGrayscaleBits(3)` lets each LED use a brightness from 0 to 7.
- `loop()` draws the two frames one after the other with `matrix.draw()`, so the ornaments look like they twinkle.

## Try This

Each number in `treeA` and `treeB` is one LED (0 = off, 7 = brightest). Change the numbers to move the ornaments or decorate your own tree.
