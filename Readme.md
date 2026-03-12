This project has been created as part of the 42 curriculum by aozkaya.

# so_long - 2D Side-Scroller Physics Edition 🐬

This project is a completely customized rewrite of the classic 42 `so_long` project. Instead of a standard top-down 2D grid game, this is a **side-scrolling platformer** featuring a real-time pixel-perfect physics engine!

## Description
The player is subjected to gravity and must jump from platform to platform to collect all the coins (`C`) before proceeding to the exit (`E`).

* **Mandatory part**: Real-time loop using `mlx_loop_hook`, gravity, Axis-Aligned Bounding Box (AABB) collision, jumping, and horizontal movement with friction/momentum. 
* **Bonus part**: All of the above PLUS sprite animation spanning multiple frames, an on-screen move and coin counter, and enemies that intelligently patrol their platform ledges!

## Instructions

### 1. Initialization
Because this project relies on customized `minilibx-linux` and `libft` repositories as submodules, you **must** initialize them before compiling:
```bash
make get_libs
```

### 2. Compilation
To compile the sleek mandatory version:
```bash
make
```
To compile the fully animated, enemy-infested bonus version:
```bash
make bonus
```

### 3. Execution (Playing the Game)
You can launch the game using the included wrapper targets which load customized side-scroller maps:
```bash
make run        # Runs mandatory part
make run_bonus  # Runs bonus part
```
Alternatively, run it manually:
```bash
./so_long assets/maps/valid/platform1.ber
./so_long_bonus assets/maps/valid/bonus/platform_bonus1.ber
```

**Controls**:
* `W` or `Up Arrow` - Jump
* `A` or `Left Arrow` - Move Left
* `D` or `Right Arrow` - Move Right
* `ESC` - Quit cleanly

## Resources
* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
* Submodules used: Custom `libft` and standard `minilibx-linux`.
* AI was used to assist in designing the physics continuous loop (`physics.c` and `enemy_ai.c`) to upgrade from the standard block-by-block movement schema.
