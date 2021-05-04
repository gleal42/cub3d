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


## Text Extraction

To extract the text there are several things to consider:

- Tabs need to be replaced with 4 spaces (Thank you [Dimitri](https://github.com/DimitriDaSilva)) for the tip.

- If there is a line break in the middle of the map strings we need to be able to identify it (for this reason using the libft ft_split function may not be the best option).

But the process of extraction is really flexible. You could extract the whole thing to a string and then add an improved split that doesnt ignore if there are multiple line breaks, you could use linked lists instead of reallocating an array of strings constantly, you could even do reallocs letter by letter. It's up to you.

In my case I just used the get_next_line function we created in a previous project and reallocated memory to add a new string each time it was needed.
[Check my functions to see what I mean](extract_and_parse/text_extract.c)

## Cub parsing

If someone writes an invalid .cub file the program must stop, free the memory allocated up until that point and show some sort of error message.
So basically we need to imagine all the ways that things can go wrong. Not only that but we should be saving the information as we go.

A few things to test:
- Resolution values that are bigger that the screens that we have in school or non-digit numbers or more than 2 values (width and height)
- Textures are a file that doesnt exist (open function would fail) or not a xpm file.
- There are multiple textures for the same wall (north wall texture).
- RGBs dont have 3 numbers, are separated by an invalid character (not a comma) or have values below 0 or above 255.
- There are invalid characters in the cub.

On the map:
- Multiple players or no player.
- Invalid characters.
- Map not closed (again thank you [Dimitri](https://github.com/DimitriDaSilva) for suggesting me to go over the map check if each map character (0, N, S, E, W, 2) didn't have a space character around it (check [check_all_sides function](extract_and_parse/ft_parse_map.c))).

You you can see [all the checks](extract_and_parse/ft_parse_cub.c) I did and think of new ones.

## Understanding the minilibx tool:

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

### Images

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

### Events

[harms-smiths](https://harm-smits.github.io/42docs/libs/minilibx/events.html) has a great example of an event hook.

`mlx_hook(vars.win, 2, 1L<<0, close, &vars);` 
In this example we us the X11 Keypress event (02) and Keypress Mask (1L<<0) so that everytime we press any key it will activate the close function and it will receive t_vars \*vars as a parameter(You can choose any pointer you want instead of t_vars *):
`int             close(int keycode, t_vars *vars)`

But maybe I just want an event to happen when I press the arrow key. How can I find out this value? There's nothing online:
This may seem obvious for most people but you can just do a `printf("%d\n", keycode)` and if you press the keycode while looking at the window you created there will be numbers printing out in the console_log, which will be the keycodes to the buttons you pushed.

**NOW THIS IS IMPORTANT:** Don't forget to put a *LINE BREAK* after %d. The computers at 42 weren't printing anything if there was no line break. Thank you tisantos for the tip!

After you know the keycodes it's relatively easy. Just do a if keycode == ARROW_UP_KEYCODE and then you choose what you want to happen.

I believe these were the main problems I faced (apart from sometimes the functions not working for some reason and then working if I placed them in a different function).

Now that we understand a little bit more about the minilibx tool we can move on to the raycasting part, which will be super exciting! Defitely the coolest part of the subject.

## Raycasting Part and Drawing calculations

Okay so for the raycasting part the main resources that I followed were the following:

To create a minimap and use trigonometrics for raycasting:
- [Pikuma Javascript Raycasting Introduction](https://courses.pikuma.com/courses/take/raycasting/lessons/7485598-introduction-and-learning-outcomes)
(Before the course was free)

To understand the calculations behind the projection itself:
- [Permadi's Raycasting Tutorial](https://www.permadi.com/tutorial/raycast/rayc1.html)

For a fun Youtube video implementing Raycasting in C:
- I watched [this video](https://www.youtube.com/watch?v=gYRrGTC7GtA)

- And I also peaked a lot on [Dimitri's](https://github.com/DimitriDaSilva) code, haha.


I will try to simplify it as much as possible:

Raycasting is basically taking your field of view, dividing it by your window width and calculating the distance from your face to the wall strip in each one of these divisions. (Explanations are clearer in Pikuma's Javascript tutorial).


### Drawing calculations

Let's picture this:
- Our window is 500 pixels width and 500 pixels height.
- We pick a [field of view](https://en.wikipedia.org/wiki/Field_of_view) of 60 degrees (usual in FPS games). The bigger your field of view the more you can see around you and the closest you get to a 360 picture. With a field of view of 60 you just see what's in front of you.
- Our height is 1,5meters.
- The wall's height is 3 meters.
- The wall is 6 meters away from us.

Okay, now I will help you calculate the size that the walls will have on the screen (a simplified version to be better understood).

In order to calculate them I will use the concept of triangle similarity and the [Projection Plane](https://www.permadi.com/tutorial/raycast/rayc9.html):

This concept is in my opinion the most important to grasp in order to draw not only the walls but also the sprites, floor and ceiling.
Using our screen and field of view we have 2 similar triangles.

> One triangle is between our face and the projection plane (the screen) and we can [calculate](https://www.permadi.com/tutorial/raycast/rayc5.html) this distance.
Half the screen size / tan(half our field of view)
(500/2) / tan(30 degrees) = 433.012701892
Our face is 433.012701892 pixels away from the screen. 

I know.. I know... pixels is not really a measurement of distance outside the screen, but it doesnt matter. What matters is this distance in pixels from our face to the projection plane/screen is proportional to the distance in meters from our face to the wall (6 meters).

> The other triangle is between our face and the wall (which we know is 6 meters away).

Okay now look at [this](https://www.permadi.com/tutorial/raycast/rayc9.html).

Projected wall height = wall actual height / distance to the wall * distance to projection plane

Projected wall height = (3 meters / 6 meters) * 433.012701892 = 216.506350946 ≈ 216 pixels.

GREAT!! We now know the height in pixels that our wall will have on our screen! Yay.

Now were do we place this line?

As we said in the beggining our player is 1,5 meters tall.
(1.5/3) * 500 = 250 we will draw (3-1.5)/3 = 0.5 = the middle of our wall. (Don't worry about these calculations. In the Wolfenstein game the player was half of the walls so the middle of the screen will always correspond with the middle of the wall/sprites.

So the wall line has to be centered on the screen.
The beggining of the wall strip will be on 250 - (216/2) = 142nd pixel
The end of the wall strip will be on the 250 + (216/2) = 358th pixel

We draw a line from the 142nd pixel to the 358th and booom. We have a wall strip.

Now we just have to repeat this process for each collumn/width pixel on our screen. To do this we use the raycasting principle.

### Raycasting

Okay for this part I really suggest following [Pikuma's Tutorial](https://courses.pikuma.com/courses/take/raycasting/lessons/7485598-introduction-and-learning-outcomes).

The main challenge was converting the Javascript code into C. Here are the main things to consider:
- Instead of classes for variables just create structs, create the same functions.
- Using double data type for calculations (If you use integer you will lose all decimal point information). Also, <math.h> functions take double as parameters.
- Converting double to int to change the values of the actual coordinates of the pixels (there is no 2.4123, 3.124124 coordinate).
- To avoid overflows do a simple protection like this:

```
if (x < 0)
	x = 0;
if (y < 0)
	y = 0;
if (x >= img_width)
	x = img_width - 1.0;
if (y >= img_width)
	x = img_width - 1.0;
```

This will grant that if when converting to integer if the values are not valid (below zero or above the maximum width) it will fix them and put the first and last value respectively, when needed. 

After you finish the tutorial you will understand how to use the player rotation in radians, you will have a cute minimap, and the distances for each one of the rays. You will then use these distances to draw lines the way I just described.

### Wall textures

Okay once we followed Pikuma's tutorial these are the things we still have left to do:

1. Draw the walls using the distances of the rays (don't forget to correct the [fisheye effect](https://permadi.com/1996/05/ray-casting-tutorial-8/)
2. Assign each texture to the correct wall.
3. Find out which part of the wall we are hitting so we know the correct part of the texture to assign to that wall strip.

To find the correct wall using the ray angle and the wall orientation (Horizontal or Vertical).

For example if the ray rotation angle is 0 radians (looking to the right) and we hit a vertical wall we know that the texture we will choose is the East side texture.

To find which part of the wall we are hitting I suggest looking at [Permadi's](https://www.permadi.com/tutorial/raycast/rayc10.html) explanation.

But summing up.
We define how wide we want the walls to be:

Following the previous example in which the walls were 3 meters, maybe we want the walls width to be 3 meters as well so that the three dimensional space is divided in squares/cubes and to make it easier to imagine.

Imagine this map:
```
Imagine this map:
  _
11111
10001
10001
10N01
11111
```
It is definitely easier to imagine if each represents a 3 meters square, right? What is great about Pikuma's tutorial is that we can use the tile_size to visualize this and just use the distance in pixels on the map as the way to do the raycasting.

So in this case our player would be:
In 2.5 * 3 = 7.5 x position ('1' & '0' full squares and half the 'N' square)
In 3.5 * 3 = 10.5 y position ('1' & '0' & '0' full squares and half the 'N' square)

Okay, hopefully this makes sense because with this scale we can now calculate the corresponding texture strip.

Imagine our ray hits a wall in the (7.5, 3) position (in the middle of third wall (I put an underscore above it to show which wall I'm talking about)).

We can do a while loop

```
while (x >= 3)
	x-=3
```
We will end up with 1.5. This represent half the square size on our map.

To find the corresponding slice on the texture we can calculate this through:
1.5/3 * texture_width.

If a texture is 64 pixels. the wall strip's texture will be drawn with the 32nd texture strip (x = 32).


### Sprites

The major difficulties about sprites were:

1. Reorganizing sprites drawing order based on distance (Sprites thar are further away must be drawn first).
2. Comparing each wall ray distance with the sprite distance to check if the sprite is closer or further away compared to the wall ray distance (if there is a wall strip closer to the player than the sprite we draw the wall. If the sprite distance is closer than the wall ray distance we draw the sprite.

We can calculate the height, width, the position on the screen and the corresponding texture strip of the sprite based on the principles we talked about for the walls.

### Floor

For the floor we find the bottom of the wall lines we drew before and we draw a line imediatly below it.
The only challenge is to find which part of the texture we need to draw for each texture. We must find the x and y positions on the map (as seen from above)and find the corresponding texture coordinates. I followed [these](https://www.permadi.com/tutorial/raycast/rayc12.html) calculations and saw [this Stackoverflow post](https://gamedev.stackexchange.com/questions/159285/ray-casting-floor-casting-part-fails).

## Creeper Textures

In order to create my creeper sprites I first found images online of creepers, I tried to add a black background around the creeper and I finally[converted](https://convertio.co/png-xpm/) it to xpm. After that most images were not perfect so I had to use vim and manually substitute the pixel colors on the xpm file.

It's really intuitive. Usually spaces represent the black color so, to make a particular pixel black we can simply replace the letter that represents a different color with a space. If you look at one of my [xpm pictures](textures/creeper.xpm) you can see what I mean. Before there were random letters around the creeper. I just replace them with spaces.

## Animation

For the animation I just created 2 variables:
- Start_animation
- Animation_counter

If I click on the space bar it changes the start_animation variable to one. If that value is 1 I replace the normal_torch texture with the attack_torch texture and leave it on the screen while the animation_counter doesnt reach a random number (I chose 5 but it will depend on how fast the game is running).

## BMP Screenshot

So to create a bmp screenshot you will need to run your program but without a loop hook to create an image with the correct colors.

You then need to open a new xpm file with the apropriate flags, create the appropriate [Bitmap file header and BITMAPINFOHEADER](https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header) and then copy the pixel colors from the image and you created previously to the bmp file (using the write function, basically the same way you would do to copy the textures to the walls).

One side note if you have implemented transparency then if you copy my code it won't work for the screenshot. As you can see in my [screenshot file](mandatory_game/bmp_screenshot.c) I specified a 24 bit color depth, which is why I was only copying 3 characters instead of 4 (no alpha).

Hopefully these tips are helpful for you to develop the project. Any implementation doubt feel free to look at my code or shoot me a message on slack or send me an email(check my profile).
