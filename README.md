# Mini Golf 3D Simulator

## Authors
- Szymon Korus
- Bartosz Mroczkowski
- Kacper Świątek

## Project Description
The Mini Golf Simulator is a game developed using C++ and the OpenGL graphics API. The game allows players to aim, choose the strength of their shot, and navigate the scene to hit the ball into the hole with as few strokes as possible. Project uses **dynamic pipeline**. Key features of the simulator include:
- **Two Camera Movement Modes** - the first one allows for free movement around the scene, and the second controls the camera movement around the ball.
- **Textures blending**
- **Dynamic Lighting** - lighting simulation using Phong shading models
- **Game Physics** - ball movement based on real-world physics principles

## Libraries
- **GLEW**
- **GLM**
- **GLFW3**
  
## Controls
### Aiming Mode:
- **A** - move the camera left
- **D** - move the camera right
- **Space** - holding increases shot power; release to hit the ball

### Free Movement Mode:
- **W** - move forward
- **A/D** - move left/right
- **Mouse** - rotate the camera

### Other Controls:
- **C** - switch camera modes
- **R** - reset ball position
- **V** - toggle wireframe mode
- **Esc** - exit the game

## Preview
<img src="Images/Screenshot1.png" alt="Screenshot" width="500"/> <img src="Images/Screenshot2.png" alt="Screenshoot" width="500"/>
<img src="Images/Screenshot3.png" alt="Screenshot" width="500"/> <img src="Images/Gameplay.gif" alt="Gameplay GIF" width="500"/>

## Installation
1. Clone the repository
2. Open the project in Microsoft Visual Studio 2022.
3. Set the build configuration to x86.
4. Build and run the project.
