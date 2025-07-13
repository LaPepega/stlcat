# stlcat

A simple, small, terminal based, stl viwer written in C

## About

***This is a personal project so don't expect much***
(Though I would love to hear about any bugs/problems/requests/etc. in Github issues <3)

Lets you render and view an stl file in your terminal. The model is on coordinates `(0,0,0)`, upward axis is `Z` `(0,0,1)` (same as Blender). Currently only supports binary stl format and only renders the points of a mesh. Requires ANSI and 256 color support (which your terminal probably has), tested with `kitty`.

## Usage

```txt
Usage: stlcat [OPTION...] <path/to/file.stl>
Render an .stl file right into your terminal

  -f, --fov=FOV              Camera's FOV (smaller number = wider angle)
                             default: 20
  -h, --height=HEIGHT        Render height in pixels            default: 100
  -s, --stats                Show render stats
  -w, --width=WIDTH          Render width in pixels             default: 100
  -x, --camX=CAMX            Camera's position along X axis     default: 2
  -y, --camY=CAMY            Camera's position along Y axis     default: 0
  -z, --camZ=CAMZ            Camera's position along Z axis     default: 0
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version
```

## Building

### On linux

CD into the cloned repository

```
cd /path/to/stlcat
```

Configure with

```bash
cmake -DCMAKE_BUILD_TYPE:STRING=Release -S . -B ./build -G Ninja
```

Then build with

```bash
cmake --build ./build --config Release --target all
```

#### For debugging

Configure with

```bash
cmake -DCMAKE_BUILD_TYPE:STRING=Debug -S . -B ./build -G Ninja
```

Then build with

```bash
cmake --build ./build --config Debug --target all
```

### On windows

Good luck :)

## Contributing

Any contributions/issues/etc. are highly appreciated <3
