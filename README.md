

*This project has been created as part of the 42 curriculum by aozkaya.*

# so_long - 2D Top-Down Adventure 🐬

A small 2D game built with the MiniLibX library. The player must collect all collectibles and reach the exit with the minimum number of moves.

## Description
In this game, you control a character in a top-down environment. Your goal is to gather all fish/coins scattered across the map and reach the exit. 

### Features
* **Mandatory part**: 
    - Smooth 2D movement (WASD or Arrow keys).
    - Map parsing and validation (.ber files).
    - Wall collision detection.
    - Movement counter in the terminal.
* **Bonus part**:
    - Sprite animations for coins, walls, and player.
    - Enemy patrols (static and wandering).
    - On-screen movement counter.

## Instructions

### 1. Initialization
You must initialize the submodules (minilibx and libft) before compiling:
```bash
make get_libs
```

### 2. Compilation
To compile the mandatory version:
```bash
make
```
To compile the bonus version:
```bash
make bonus
```

### 3. Execution
```bash
./so_long assets/maps/valid/map1.ber
./so_long_bonus assets/maps/valid/bonus/platform_bonus1.ber
```

**Controls**:
* `W/A/S/D` or `Arrow Keys` - Movement
* `ESC` or `Q` - Quit cleanly

## Resources
* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
* AI was used to assist in organizing the animation logic and refactoring the map validation structures.

