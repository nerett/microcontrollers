# MC-4sem
This repo contains project for the cource of **Microcontrollers** (4 semester of MIPT DREC) which is actually something like stopwatch. When measurement starts, the led wents on and the timer starts ticking. The result (current loop and the best result) is displayed right after the measurement stops.

## Usage
*Single-click* on button starts the measurement. Another one stops it.

## Building from source & flashing
#### Downloading
Download this repository with

```bash
git clone https://github.com/nerett/mc-4sem.git
```

#### Installing dependencies
It's necessary to flash special **dfu bootloader** (you can get one from [here](https://github.com/rogerclarkmelbourne/STM32duino-bootloader), we used [this](https://github.com/rogerclarkmelbourne/STM32duino-bootloader/blob/master/binaries/generic_boot20_pc13.bin) one) to your **stm32** (we used *stm32f103c8 "BluePill"*). You also need to have **Arduino IDE** installed and configured (see [here](https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki)).

Also see [*Dependencies*](https://github.com/nerett/mc-4sem#dependencies) section for more information.

#### Building
Disclaimer: I'm not going to cover the process of building via *cross-compiler*, flashing directly via `dfu-util` or something. You can build the project and flash the binary to your **stm32** with the help of **Arduino IDE**. The process of building is trivial; to flash the binary you have to put *jumpers* into undocumented position: "**0**" and "**1**" ("**0**" "**0**" is default), press **reset** and then load the binary via **Arduino IDE**.

#### Running
To make your **stm32** load this program automatically, you need to put jumpers into default ("**0** and "**0**") position. Press **reset** to restart the program.

## Dependencies
 - Arduino IDE (see configuration process [here](https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki))
 - STM32duino bootloader (get it from [here](https://github.com/rogerclarkmelbourne/STM32duino-bootloader))
 - supported board (we used **smt32f103c8 BluePill**, see the full [list](https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki/Supported-hardware))
 
## Documentation
This section isn't done yet.

## About project
This project was created during **Microcontrollers** cource (4th semester of MIPT DREC) by [nerett](https://github.com/nerett) and [vihlancevk](https://github.com/vihlancevk). Special thanks to the [rogerclarkmelbourne](https://github.com/rogerclarkmelbourne).
