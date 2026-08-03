*This project has been created as part of the 42 curriculum by malaimo, neda-sil.

# cub3D

## Description

**cub3D** is a raycasting engine written in C, inspired by the pseudo-3D rendering
technique used in *Wolfenstein 3D*. The goal of the project is to build, from
scratch and without any external 3D graphics library, a first-person 3D view of
a 2D maze described in a custom map file.

The project relies on the **MinilibX** graphics library for window management
and pixel-level display, and on a **raycasting algorithm** (based on the
Digital Differential Analysis method) to project a 2D grid map into a real-time
3D perspective.

Main features:
- Custom `.cub` map file parsing, with full validation of:
  - the four wall textures (North, South, East, West)
  - the floor and ceiling colors (RGB)
  - the map itself (valid characters, closed borders, single player spawn point)
- A raycasting engine computing, for each column of the screen, the distance to
  the nearest wall and the exact point of impact
- Textured walls, with the correct texture selected depending on which face of
  the wall was hit (North/South/East/West), and correct texture orientation
- Solid-colored floor and ceiling
- Real-time player movement (forward/backward/strafe) and rotation (view
  direction), with collision detection against walls
- A custom tracked memory allocator (a lightweight garbage-collector-like
  system) used throughout the parsing to guarantee clean memory management,
  including on error paths

## Instructions

### Compilation

```make```

This will:
- clone and build **MinilibX** if it is not already present
- build the project's internal libraries (`libft`, `get_next_line`, `ft_printf`)
- compile the `cub3D` executable

Other available targets:

```
make clean    # remove object files
make fclean   # remove object files and the executable
make re       # fclean + make
```

### Execution

```./cub3D <path_to_map.cub>```

The program expects a single argument: the path to a valid `.cub` map file.

### Map file format (`.cub`)

A valid map file must define, in any order, before the map itself:

```
NO <path_to_texture>      # North wall texture (.xpm)
SO <path_to_texture>      # South wall texture (.xpm)
WE <path_to_texture>      # West wall texture (.xpm)
EA <path_to_texture>      # East wall texture (.xpm)

F <R>,<G>,<B>              # Floor color
C <R>,<G>,<B>               # Ceiling color
```

followed by the map layout itself, using:
- `1` for a wall
- `0` for an empty (walkable) space
- `N`, `S`, `E`, `W` for the player's starting position and orientation
- spaces for space outside the map

The map must be surrounded by walls (no leaks), and must contain exactly one
player starting position.

### Controls

| Key            | Action                     |
|----------------|-----------------------------|
| `W`            | Move forward                |
| `S`            | Move backward                |
| `A`            | Strafe left                  |
| `D`            | Strafe right                 |
| `←` / `→`      | Turn the camera left/right   |
| `ESC` / close window | Quit the program       |

## Resources

- [Lode's Computer Graphics Tutorial – Raycasting](https://lodev.org/cgtutor/raycasting.html) — the reference article explaining the Digital Differential Analysis (DDA) algorithm used to compute wall distances and texture mapping
- [42 MiniLibX documentation and source (42Paris fork)](https://github.com/42Paris/minilibx-linux)
- [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) — the original game that popularized the raycasting rendering technique this project is inspired by
- The subject and evaluation sheet of the *cub3D* project, provided by 42

### AI usage

Ai has been used in order to comprehend the subject and the mathematicals formulas.
