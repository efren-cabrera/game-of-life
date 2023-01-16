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

### Some common patterns

<p align="center">
  <img src="https://user-images.githubusercontent.com/13933998/212586435-d6c47e19-b173-4bee-8095-ca306fe85286.gif"
  alt="Game of Life"
 width=30 height=40/>
 <img src="https://user-images.githubusercontent.com/13933998/212586888-2cb6d153-98b6-4ec3-a788-ec6f1d07a185.gif"
  alt="Game of Life"
 width=30 height=40/>
 <img src="https://user-images.githubusercontent.com/13933998/212587135-3e66d2a2-736d-4b5e-85ca-7cb58b8c233a.gif"
  alt="Game of Life"
 width=30 height=40/>
 <img src="https://user-images.githubusercontent.com/13933998/212587590-64da714f-945b-4f71-ae0a-73f73b5d0567.gif"
  alt="Game of Life"
 width=30 height=40/>
</p>
