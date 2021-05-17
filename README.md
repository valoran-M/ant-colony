<h1 align="center">
  ant-colony
  <br>
    <img src="logo.png" alt="ant-colony-logo" width="256">
  <br>

  <a href="https://lgtm.com/projects/g/Valeran-MAYTIE/ant-colony/alerts/">
  <img alt="Total alerts" src="https://img.shields.io/lgtm/alerts/g/Valeran-MAYTIE/ant-colony.svg?logo=lgtm&logoWidth=18"/>
  </a>
  
  <a href="https://lgtm.com/projects/g/Valeran-MAYTIE/ant-colony/context:cpp">
  <img alt="Language grade: C/C++" src="https://img.shields.io/lgtm/grade/cpp/g/Valeran-MAYTIE/ant-colony.svg?logo=lgtm&logoWidth=18"/>
  </a>

</h1>

## Get ant colony
#### Required libs and tools:
- cmake
- pkg-config
- sfml 

> If you are using nixos, you can just type ``nix-shell`` inside the directory to open a preconfigured shell

#### Compilation
```sh
cmake .
make
```

#### Launching ant colony
```
./ant_colony [OPTION] ...
```

|commande|dedescriptions|
|:-:|:-:|
| -h / --help | show command |
| -t / --textures | active textures |
| -m / --man | place colony manualy |
| -c / --colony *number* | number of colony |
| -s / --sugar *number* | number of sugar |
| -l / --largeness *number* | cell dimension |
| -d / --dimension *number number* | grid dimension |

## Code conventions

#### Docstrings
We followed javadocs guidelines with an additional decorator:
``@confidence 0-5``
- 0: it doesn't work
- 1: it "works" with known bugs
- 3: it works but can't be tested
- 4: it works and has been been tested
- 5: it works, it has been tested and it is so simple that there is no doubt about it
