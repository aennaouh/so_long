# so_long - **MiniLibX :**   is an easy way to create graphical software,  MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens . It provides so-called simple window creation,

**the why to see the man of minilibx** : man  /usr/share/man/man3/mlx.1. (using flagc)

cc -I /usr/local/include so_long.c -L /usr/local/lib/ -lmlx -framework openGl -framework AppKit :

This command is using the cc (C compiler) to compile the file "so_long.c" and include the header files located in "/usr/local/include". The "-L" flag is specifying the directory "/usr/local/lib/" where the library "libmlx" is located, and the "-lmlx" flag is linking that library to the compiled program. The "-framework" flags are linking the "OpenGL" and "AppKit" frameworks to the program as well. The resulting executable file will be able to use functions and methods from those frameworks and the "libmlx" library.

# **Initialization**

Before we can do anything with the MiniLibX library we must include the `<mlx.h>` header to access all the functions and we should execute the `mlx_init` function. This will establish a connection to the correct graphical system and will return a `void *` which holds the location of our current MLX instance. To initialize MiniLibX one could do the following:

`#include <mlx.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}`

***Backtracking** can be defined as a general algorithmic technique that considers searching every possible combination in order to solve a computational problem.*

1. **`map`**: This is a 2D character array that represents a map or a grid. The characters in the map represent different types of terrain, objects, or symbols.

2  . size : This is a structure or an object of type **`t_point`**
 that represents the size of the map. **`t_point`**
 is a custom data structure that holds two values, usually called **`x`**
 and **`y,`**which represent the number of rows and columns in the map, respectively.

1. 1. **`cur`**: This is a structure or an object of type **`t_point`** that represents the current position or starting point in the map. **`t_point`** is a custom data structure that holds two values, usually called **`x`** and **`y`**, which represent the row and column indices of the starting point, respectively.

4. **`to_fill`**: This is a character that represents the new value that should be used to fill the connected component starting from the current position **`cur`**.

1. The function **`fill`**
 is likely implementing a flood fill algorithm to change the value of all connected cells in the **`map`**
 starting from the **`cur`**
 position to the **`to_fill`**
 character. The function uses the **`map`**, **`size`**, **`cur`**, and **`to_fill`**  values as input to fill the connected component in the map.

It is possible that the implementation of this function is using either depth-first search or breadth-first search to traverse the connected cells and change their values. However, without the full code, I cannot be certain of the exact implementation details.

`mlx_init`
 function. This will establish a connection to the correct graphical system and will return a `void *`
 which holds the location of our current MLX instance. To initialize MiniLibX one could do the following:
