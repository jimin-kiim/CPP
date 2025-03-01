## Arkanoid Game using OpenGL

### Environment
The project is for MacOS, Linux and Windows. 

### Installation
1. Make sure the apt package manager is up to date.
```
sudo apt-get update
```

2. install required packages to open the project. 
```
sudo apt install g++ 
sudo apt install freeglut3-dev freeglut3
sudo apt install binutils-gold
```

### Build and Open 
1. create execution file with Makefile
- use make in the directory where the Makefile exists with main.cpp

  ```
  make
  ```
   or
- use CMake in the directory where the CMakeLists.txt exists with main.cpp

  ```
  mkdir build
  cd build
  cmake ..
  make 
  ```

2. Open the execution file.
- `main.mac.out` or `main.exe` or `main.linux.out` (when built only with Makefile) 
-  `ArkanoidGame`; inside the build directory (when used CMake)

