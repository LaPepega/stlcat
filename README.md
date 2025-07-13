# stlcat

A simple, small, terminal based .stl file renderer written in C

## About

***This is a personal project so don't expect much***
(Though I would love to hear about any bugs/problems/requests/etc. in Github issues <3)

Lets you render and view an stl file in your terminal. The model is on coordinates `(0,0,0)`, upward axis is `Z` `(0,0,1)` (same as Blender). Currently only supports binary stl format and only renders the points of a mesh. Requires ANSI and 256 color support (which your terminal probably has), tested with `kitty`.

## Example renders:

Human:

<img width="1972" height="1315" alt="image" src="https://github.com/user-attachments/assets/904a16fd-f21c-423a-80c1-d60178aefe10" />

Human with camera on it's hand:

<img width="1113" height="827" alt="image" src="https://github.com/user-attachments/assets/667c3094-8057-489f-8c0d-66935f02115b" />

UV Sphere:

<img width="802" height="786" alt="image" src="https://github.com/user-attachments/assets/22059516-390b-4aba-afa1-9e58fdcb7e39" />

UV Sphere from further away:

<img width="573" height="524" alt="image" src="https://github.com/user-attachments/assets/844406dc-3917-412b-80fa-e1a39bc5b486" />

Suzanne:

<img width="662" height="651" alt="image" src="https://github.com/user-attachments/assets/6484a90f-cd87-4666-9bea-47fbf304371a" />

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
