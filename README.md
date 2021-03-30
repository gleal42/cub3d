# cub3d - School 42
## Wolfenstein3d inspired Raycasting project

**Final Score** - 103/100

My Raycaster Project:

![](https://media.giphy.com/media/1PO14pi2J8nwflaMSc/giphy.gif)

In this 42 project we are asked to extract information from a .cub file and use that information to draw a 3d maze on the screen using raycasting principles.

Example of cub file information
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
[text_extracting file](docs/CONTRIBUTING.md)
