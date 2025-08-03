# 🧊 Rubik's Cube Move Testing & Visualization

This C++ project allows you to **simulate**, **test**, and soon **visualize** Rubik’s Cube moves like `R`, `L`, `U`, `D`, etc. It is modularized and prepared for 3D visualization using OpenGL. The goal is to simulate and debug standard cube solving algorithms phase-by-phase, starting with move testing and later moving into GUI rendering.

---

## ✅ Features

- Modular C++ code to simulate cube states.
- Test individual Rubik's Cube moves (R, L, U, D, etc.).
- Supports phase-wise development (e.g., white cross, yellow cross, etc.).

---

## ⚙️ Prerequisites

- C++ compiler (like g++) supporting C++17  
- VS Code installed  
- `g++` in your system PATH  
- Recommended: Install **C++ Extension Pack** in VS Code

---

## 🚀 How to Build & Run

### 1. Open VS Code
- Navigate to the project folder.
- Open the integrated terminal:  
  Press Ctrl + ` (backtick) or go to Terminal > New TerminaL.

### 2. Compile the Program


g++ -std=c++17 main.cpp CubeState.cpp CubeRotations.cpp MoveTest.cpp -o CubeSolver

### 3.Run the Program
 CubeSolver.exe

### 4.Enter the below Scrambled State as an input
    -Front:GGGYRWBBB
    -Back:BBBYOWGGG
    -Right:YRWBBBYOW
    -Left:YOWGGGYRW
    -Up:OOOYYYRRR
    -Down:RRRWWWOOO
### 5.You will get an Solved States with above scrambled only because i have developed only rotations of the cube by completing the logic of the layer-by-layer approach call from the main.cpp to do the full Solver of the cube.
