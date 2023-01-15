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

![ezgif com-gif-maker (7)](https://user-images.githubusercontent.com/13933998/211696545-02ba0861-2b96-4aca-8ee8-93c77b01a4c2.gif)

