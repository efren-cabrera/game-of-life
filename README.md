# ![ezgif com-gif-maker (6)](https://user-images.githubusercontent.com/13933998/211692798-dc7fe512-590b-481a-9f6c-5ced719f3641.gif) Game of life

Personal implmentation of [Game of Life  game of John Horton Conway](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life). This project is planned to be used to compare performance when using GPU.

## ![ezgif com-gif-maker (5)](https://user-images.githubusercontent.com/13933998/211692781-4469e5fe-8247-4dee-901b-fa93d251aaed.gif) Compile 

You need to have cmake installed.

* How to test
  
```bash
mkdir build && cd build
cmake ..
cmake --build . 
ctest --output-on-failure
```

* How to build

```bash
mkdir build && cd build
cmake ..
cmake --build . 
./app/GameOfLife
```

## ![ezgif com-gif-maker (4)](https://user-images.githubusercontent.com/13933998/211692760-598cfaef-791f-4559-b5ad-88b0a36c9af1.gif) Result

Result using a grid of 600 x 800


<p align="center">
  <img src="https://user-images.githubusercontent.com/13933998/212559871-6495246b-f778-489e-ae86-2e4884a4fc91.gif"
  alt="Game of Life"
 width=800 height=600/>
</p>


