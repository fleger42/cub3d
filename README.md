# **Cub3D:** 
## ***A 42 project... :***
[Subject][1]
## Requirement:
- You must be on a linux distribution and you have to install [minilibx][2].
- mlx.h must be placed in /usr/local/include/
- libmlx.a must be placed in /usr/local/lib/
### Usage:
Launch make and than ./Cub3d with a map `Exemple: ./Cub3D map.cub`
You can create or edit freely .cub file. See [Subject][1] for more details about .cub configurations
## Goal:

- [x] No memory leaks
- [x] Norm
- [x] Minilibx

The goal of this project is to make our own version of [Wolfenstein 3D][3]. 
The project use a raycasting algorithm to be able to create a maze. For each column on your screen, the programm will send a ray and draw a wall based on the distance the ray traveled.
![alt text](wolfeinsted)

The longer the distance, the tiniest the wall will be. My Cub3D support the following basic features:
- You can walk in a maze like terrain with W A S D
- Collision with wall is enabled
- Use 4 different texture for N,S,O,E (You can change the texture in .cub file)
- Sprite are supported (You can change the texture and the position of sprite in .cub file)
- Different colors for floor and ceiling (You can change the color in .cub file)
- --save argument
- And more.. (See [Subject][1] for more details)

## Final grade:
102/100

[1]: https://github.com/fleger42/cub3d/blob/master/cub3d.pdf
[2]: https://github.com/42Paris/minilibx-linux
[3]: https://fr.wikipedia.org/wiki/Wolfenstein_3D
