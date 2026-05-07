*This project has been created as part of the 42 curriculum by aozkaya.*

# So Long

## Description

So Long is a small 2D top-down game built in C with MiniLibX. The player must collect every collectible on the map and then reach the exit while avoiding walls. The project focuses on window management, image rendering, input handling, map parsing, and clean memory management.

The repository includes both the mandatory game and a bonus version with extra features such as enemies, sprite animations, and on-screen movement feedback.

## Instructions

### Requirements
- Linux environment
- `make`
- MiniLibX dependencies available for your system

### Build
```bash
make
make bonus
```

### Run
```bash
./so_long ./assets/maps/valid/map1.ber
./so_long_bonus ./assets/maps/valid/bonus/map5.ber
```

### Clean
```bash
make clean
make fclean
make re
```

## Resources

- MiniLibX documentation and examples
- `man 2 open`, `man 2 read`, `man 3 malloc`, `man 3 free`
- The 42 So Long subject
- Map validation and flood-fill algorithm references
- Libft project sources used in this repository

### AI Usage

AI was used only as a reference while learning some algorithms and checking ideas during development. It was not used to write the project code itself.
