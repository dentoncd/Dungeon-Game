# Dungeon Game

A small terminal-based C++ dungeon exploration game where the player navigates through a dark dungeon in search of treasure while avoiding walls, monsters, and pits.

The dungeon is represented as a 5×5 grid containing floor tiles, walls, a pit, a monster, and treasure.

## How to Play

Your character starts inside the dungeon and can move in four directions using:

* `W` — Move north
* `A` — Move west
* `S` — Move south
* `D` — Move east

Both uppercase and lowercase letters are accepted.

Before each move, the game describes what is located to the north, south, east, and west of your current position. These descriptions give hints about nearby walls, pits, monsters, and treasure.

## Goal

Your goal is to successfully navigate through the dungeon and reach the treasure.

Be careful:

* Running into a **wall** ends the game.
* Encountering the **monster** ends the game.
* Falling into the **pit** ends the game.
* Reaching the **treasure** wins the game.

## Features

* Terminal-based dungeon exploration
* WASD movement
* Environmental hints before each move
* Multiple dungeon hazards
* ASCII-art animations
* Treasure/win animation
* Game-over animations
* Works with terminal clearing on Windows and Unix-like systems

The game includes custom ASCII graphics for events such as hitting a wall, encountering a monster, falling into a pit, finding treasure, and winning the game.

## Project Files

```text
game.cpp
graphics.h
```

### `game.cpp`

Contains the main game logic, including:

* Dungeon layout
* Player movement
* Tile detection
* Direction input
* Environmental descriptions
* Win and loss conditions

### `graphics.h`

Contains the terminal graphics and animations used throughout the game.

## Running the Game

Compile the project with a C++ compiler such as `g++`:

```bash
g++ game.cpp -o game
```

Then run it:

### Windows

```bash
./game.exe
```

### macOS/Linux

```bash
./game
```

## Example Controls

```text
Where would you like to go? (W/A/S/D)

W = North
A = West
S = South
D = East
```

Entering anything other than `W`, `A`, `S`, or `D` causes the game to reject the input and end the run.

## Technologies

* C++
* `iostream`
* `vector`
* `chrono`
* `thread`
* ASCII terminal graphics

## Objective

Explore carefully, use the environmental clues to determine what is around you, avoid the dungeon's dangers, and find the treasure.
