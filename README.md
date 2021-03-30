# cub3d - School 42
## Wolfenstein3d inspired Raycasting project

### **Final Score** - 103/100

My Raycaster Project:

![](https://media.giphy.com/media/1PO14pi2J8nwflaMSc/giphy.gif)

In this 42 project we are asked to extract information from a .cub file and use that information to draw a 3d maze on the screen using raycasting principles.

Example of a valid cub file's information:
```
R 1920 1080

NO ./textures/greystone.xpm
SO ./textures/purplestone.xpm
WE ./textures/redbrick.xpm
EA ./textures/wood.xpm

S ./textures/creeper.xpm
F 77,92,53
C 163,208,230

		1111111111111111111111111
		1000000000110000000000001
		1011000001110000002000001
		1001000000000000000002001
111111111011000001110000000000001
100000000011000001110111110111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

I believe this project has several challenges

1. Finding the right way to extract the cub information.
1. Parsing the cub correctly.
1. Using and understanding the minilibx drawing tool.
1. Understanding raycasting and the DDA algorithm.
1. Creating the bmp screenshot file.


### Text Extraction

To extract the text there are several things to consider:
-Tabs need to be replaced with 4 spaces (Thank you [Dimitri](https://github.com/DimitriDaSilva)) for the tip.
-If there is a line break in the middle of the map strings we need to be able to identify it (for this reason using the libft ft_split function may not be the best option).

In my case I just used the get_next_line function we created in a previous project and reallocated memory to add a new string each time it was needed.
[Check my functions to see what I mean](extract_and_parse/text_extract.c)

### Cub parsing

If someone writes an invalid .cub file the program must stop, free the memory allocated up until that point and show some sort of error message.
So basically we need to imagine all the ways that things can go wrong. Not only that but we should be saving the information as we go.

A few things to test:
-Resolution values that are bigger that the screens that we have in school or non-digit numbers or more than 2 values (width and height)
-Textures are a file that doesnt exist (open function would fail) or not a xpm file.
-There are multiple textures for the same wall (north wall texture).
-RGBs dont have 3 numbers, are separated by an invalid character (not a comma) or have values below 0 or above 255.
-There are invalid characters in the cub.

On the map:
-Multiple players or no player.
-Invalid characters.
-Map not closed (again thank you [Dimitri](https://github.com/DimitriDaSilva) for suggesting me to go over the map check if each map character (0, N, S, E, W, 2) didn't have a space character around it (check [check_all_sides function](extract_and_parse/ft_parse_map.c))).

### Understanding the minilibx tool:

First here are the best resources I found:
- https://github.com/taelee42/mlx_example
- https://harm-smits.github.io/42docs/libs/minilibx
- https://github.com/Gontjarow/MiniLibX

Here are the main considerations and most difficult concepts explained:

We need to initiate and save the pointer to several things:
- The minilibx itself:
  - `void *mlx_ptr = mlx_init();`
- The window you will draw in:
  - `void    *win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Name of the window");`
