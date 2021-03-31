# cub3d - School 42
## Wolfenstein3d inspired Raycasting project

### **Final Score** - 103/100

My Raycaster Project:
XPM textures created from Minecraft content

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


And now the minilibx gives you 2 options to draw on the screen:
- You can either use the mlx_put_pixel for every pixel you want to change,
or
- You can create an image, change all the pixel colors you want and use the mlx_put_image_to_window a single time.

So, in terms of time and resource efficiency we can agree that using images, especially for a big screen would be preferable, right?

I'm going to assume that you agree with me so that I only need to explain images and not pixels, haha.

#### Images

After reading [Gontjarow's](https://github.com/Gontjarow/MiniLibX/blob/master/docs/mlx-tutorial-create-image.md) explanation this is what I got:

Imagine you want to create a 3x3 pink square in an image. I like [this](https://www.color-hex.com/color/ffdae9) shade. Sounds easy, huh? WRONG!

First you must create an image:

All the images to be created will need these variables so you might as well create a struct to hold them

```
typedef struct		s_img
{
	void		*ptr;
	char		*addr;		// In my code I changed this to int *, which I will explain in a second
	int		bitsinpixel;	//when using ARGB this value is always 32
	int		line_bytes;	//This value represents (your image width) * 4 which I will also explain after
	int		endian;		//This value can be either 0 or 1 and will indicate how the ARGB bytes are organized (from front to back or back to front)
}			t_img;
```

So the first thing you need to do is create an image:

```
t_img pink_cube;
pink_cube.ptr = mlx_new_image(mlx_ptr, 3, 3);
```

Then in order to change the pixels in the image you just created you need to do this function:

```
pink_cube.addr = mlx_get_data_addr(pink_cub.ptr, &img.bitsinpixel, &line_bytes, &img.endian);
```
This is what just happened:
- img.bitsinpixel is now = 32
- line_bytes = 3 * 4 = 12
- img.endian = 1 (As long as we use ARGB color layout)

And now we are pointing to a string that looks like this:

> |0|0|0|0| |0|0|0|0| |0|0|0|0| |0|0|0|0| |0|0|0|0| |0|0|0|0| |0|0|0|0| |0|0|0|0| |0|0|0|0|

And we want it to look like this:

> |0|255|218|233| |0|255|218|233| |0|255|218|233| ***|0|255|218|233|*** |0|255|218|233| |0|255|218|233| |0|255|218|233| |0|255|218|233| |0|255|218|233|

The string created has 9 * 4 = 36 characters and character represents either Alpha, Red, Green or Blue values.


I want you to look at the 4 characters that are in bold an italics.

That is the 4th pixel represented on the string.
However we have a 3x3 cube so what is this 4th pixel pointing to?

It is pointing at the first pixel on the second line of our pink cube.

So the imagine this. Everytime the string reaches the end of the line. The next pixel is the first one of the next line:

- 4th pixel on string = 1st pixel second line
- 5th pixel on string = 2nd pixel second line
- 6th pixel on string = 3rd pixel second line

 **AND**
- 7th pixel on string = 1st pixel third line


Okay now that we got this down, it's time to understand why people are using 	int	*addr instead of char *addr and why it works:

Things that we know:
- The size of a pixel using ARGB is 32 bits (4 bytes)
- The size of a character is 1 byte.
- The size of an int is 4 bytes.
- The reason why the max value of an unsigned char is 255 is because the maximum value 8 bits can represent in bynary: 
  - 1111|1111 
    - Which in decimal system is (2^8 - 1) = 255
    - Which in hexadecimal system is 0XFF
- The reason why the max value of an unsigned int is 42949672955 is because the maximum value 32 bits can represent in bynary:
  - 1111|1111|1111|1111|1111|1111|1111|1111
    - Which in decimal system is (2^32 - 1) = 42949672955
    - Which in hexadecimal system is 0XFFFFFFFF

So, in memory an int is 32 bits standing side by side and 4 chars are also 32 bits standing side by side and a pixel in ARGB is also 32 bits.

Essencially what this all means is that if we have the values for each one of the 4 characters that represent colors (Alpha, Red, Green or BLue) we can convert it to an int using bit operations (I know, these sound pretty scary).

So when we look that the color operations that [harms-smith](https://harm-smits.github.io/42docs/libs/minilibx/colors.html) did, this is what is happening

Let's look at our [pink color](https://www.color-hex.com/color/ffdae9):
Hexadecimal value: 0x00ffdae9
Alpha Value: 0x00 (Not transparent)
Red Value: 255 = 0xff
Green Value: 218 = 0xda
Blue Value: 233 = 0xe9

I want you to look at each of the numbers:

> Notice how the color is composed of 8 hexadecimal digits
> Each of the components (A, R, G, B) is composed of 2 hexadecimal digits.


```
int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}
```
So analyzing [this operation](https://harm-smits.github.io/42docs/libs/minilibx/colors.html) this is what is happening:

1. We get the red value (255).
2. Our int is now 0x000000FF
3. We want the red value to be in the red character position (second set of 2 digits)
4. We perform the opeartion r << 16, which means we are multiplying the value by 2^16 or by 256^2, shifting the binary values 16 spaces to the left or shifting the hexadecimal values 4 digits to the left or even say shifting 2 bytes to the left or 2 characters to the left (These all mean more or less the same thing so don't worry if you dont get one of these opeartions, it will make more sense as you think about them).
5. Now our int is 0x00FF0000, which means that the red component is in the right place and we can now do the same for each of the other components (Alpha, Green, blue).

So now, hopefully you understand a little better how the ARGB components can easily be converted to an int.
So instead of this:
> |0|255|218|233| |0|255|218|233| |0|255|218|233| ***|0|255|218|233|*** |0|255|218|233| |0|255|218|233| |0|255|218|233| |0|255|218|233| |0|255|218|233|

We can have this:
0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9 | 0x00ffdae9

We now can go to our struct and replace **char	\*addr** by **int \*addr** and just place the color value directly in each one of the pixels.

We can do this with a small while loop

```
int color = create_trgb(0, 255, 218, 233) = 0x00ffdae9
int width;
int height = 0;

while (height < 3)
{
	width = 0;
	while (width < 3)
	{
		pink_cube.addr(height * 3 + width) = color;
		width++;
	}
	height++;
}
```
Now that the address is filled with the cute pink color that I chose for you it's time to put it on the screen.
```
		mlx_put_image_to_window(mlx_ptr, win_ptr, pink_cube.ptr, 0, 0); \\ These zeroes are the coordinates of the window in which you want to place the first pixel of our cute pink cube. Try changing its values to check different coordinates.
		mlx_loop(mlx);
```

Another topic that was difficult for me to understand was how events and hooking events worked.

#### Events

[harms-smiths](https://harm-smits.github.io/42docs/libs/minilibx/events.html) has a great example of an event hook.

`mlx_hook(vars.win, 2, 1L<<0, close, &vars);` 
Now that we understand a little bit more about the minilibx tool we can move on to the raycasting part, which will be super exciting! Defitely the coolest part of the subject.


### Understanding the minilibx tool:
