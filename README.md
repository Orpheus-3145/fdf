# FdF
fdf, or ’fil de fer' (wireframe model), is a graphic mapping application designed to render a set of 3D points in isometric projection.
The input is a map (file .fdf inside folder maps/ ), every map has some rows an columns of numbers: the row and column of the number is going to be the y and x coordinates, the value of that number is the z value.


# Overview
The program works as follows:
- first thing the map is going to be parsed and checked if it satisfies the requirements:
	- .fdf extension and inside map folder
	- the map hase the same numbers of columns and rows
	- restrictions of values: 
		- symbols allowed, except for digits: '+' '-' ',' '.' (and hexadecimal symbols, see later)
		- decimal or hexadecimal format, in the latter the number must begin with '0x' or have '0x' after the comma/point (in that case the whole part is going to be considered as decimal, the decimal part as hexadecimal)
- every 3D point parsed must be rotated, because right now the map is in front of us, perpendicular to our sight: we would see just a flat rectangule/square with no elevation, the rotation we are going to apply are:
    rotate by -45° along the z-axis (the one that goes perpenicularly from the monitor towards us)
    rotate byt 60° along the x axis (goes increasingly from left to rigth)
    Matrix rotations::
    alpha roation on x-axis:            alpha roation on y-axis:             alpha roation on z-axis:
    |--------|--------|---------|       |---------|--------|--------|        |--------|---------|--------|
    | 1      | 0      | 0       |       | cos(a)  | 0      | sin(a) |        | cos(a) | -sin(a) | 0      |
    | 0      | cos(a) | -sin(a) |       | 0       | 1      | 0      |        | sin(a) | cos(a)  | 0      |
    | 0      | sin(a) | cos(a)  |       | -sin(a) | 0      | cos(a) |        | 0      | 0       | 1      |
- now that every point is correctly rotated the rendering starts: for every point only the (x,y) tuple is going to be considered, also the whole se will be shifted, so it is going to be printed in the middle of the white image (80% of the size) which is centered in the windows (again, 80% of the size).   
        

# Requirements:
The graphic part relies of the MLX42 library (Codam) which in turn depends on GLFW (see #Recerences for info).
My project Libft is also included in Fdf as a submodule (as for MLX42) do `git submodule update --init [--remote]` if necessary, feel free to text me (again, see #References) if some piece of Libft is in conflit with FdF. 


# Execute
 - the command `make` creates the executable
 - the executables runs with a parameter, which is the path of the .fdf file (there are some of them inside the maps/ folder)
 - INSTURCTIONS:
    - key ESC -> kills the app
    - key WASD -> moves the subject in the window
    - mouse drag-and-drop -> rotates the subject on X or Y axis
    - (resizable window)

 - other make commands: `re`, `clean`, `fclean`


# Structure
    include/	--> header files
    libft/		--> libft directory with auxiliary functions (git submodule)
    maps/		--> files to render
    MLX42/		--> graphic library (git submodule)
    objects/	--> deposit for object files
    tmp/		--> working examples provided
    sources/	--> source files:
    	- app.c				--> higher level functions to manage the MLX42 library and the map parsed (open, close, draw, ...)
    	- draw.c			--> draws the single pixel, a line from p1 to p2, and the whole graph
    	- fdf.c				--> main file 
    	- finder.c			--> functions to find certain target inside the map
    	- hooks.c			--> callbacks binded to the presson of certain keys
    	- manipulate_map.c	--> middle-level operations on map (rotate, shift, resize)
    	- map.c				--> functions to manage maps objects (create, deallocate, render, ...)
    	- rotations.c		--> low-level rotations (matrix rotations)
    	- tools.c			--> checks and helper functions
	
# References
- About [MLX42 library](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) library
- 42 project: [FdF](https://cdn.intra.42.fr/pdf/pdf/73983/en.subject.pdf)
- By: Francesco Aru, francesco.aru25@gmail.com, intra42/slack nickname: @faru, Codam, Amsterdam