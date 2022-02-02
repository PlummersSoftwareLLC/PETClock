# PET Clock

[![CI](https://github.com/PlummersSoftwareLLC/PETClock/actions/workflows/CI.yml/badge.svg)](https://github.com/PlummersSoftwareLLC/PETClock/actions/workflows/CI.yml)

Source code to [Dave's Garage](https://www.youtube.com/c/DavesGarage/featured) video discussing a complete application in 6502 assembly.

[![Assembly Language Snow Day! Learn ASM Now! | Dave's Garage](https://img.youtube.com/vi/CfbciNZvg0o/0.jpg)](https://youtu.be/CfbciNZvg0o)

## Configuring and building

Towards the top of the [`petclock.asm`](petclock.asm) file, a number of symbols are defined that can be used to configure the build:
|Name|Possible values|Meaning|
|-|-|-|
|COLUMNS|40 or 80|Screen width of the target machine, in columns.|
|DEBUG|0 or 1|Set to 1 to enable code that only is included for debug builds.|
|EPROM|0 or 1|When set to 1, the BASIC stub and load address will not be included in the build output.|
|PET|1|Configure build for the PET. Always set to 1.|
|PETSDPLUS|0 or 1|When set to 1, the clock will read RTC from petSD+ instead of the jiffy timer.|
|SHOWAMDEFAULT|0 or 1|Set to 1 to use a dot separator for AM and colon for PM. Otherwise, the separator is a colon at all times.|

This repository's code targets the ca65 assembler and cl65 linker that are part of the [cc65](https://cc65.github.io/) GitHub project. You will need a fairly recent build of cc65 for assembly of this repository's contents to work.

With the cc65 toolkit installed and in your PATH, you can build the application using the following command:

```text
cl65 -o petclock.prg -t none petclock.asm
```

## Loading and running

Assuming the petclock.prg file is on a disk in device 8, the clock can be loaded using the following command:

```text
LOAD "PETCLOCK.PRG",8
```

If the clock has been assembled without petSD+ support, the clock's time will be loaded from the system clock (jiffy timer). The system clock can be set in BASIC using the following command, replacing `HH`, `MM` and `SS` with hours, minutes and seconds respectively:

```text
TI$="HHMMSS"
```

The hours can/should be specified in 24-hour time. The clock will always show 12-hour notation.
Upon exit, the system clock will be set to the time that is then on the clock. The AM/PM state of the clock will then be considered.

The clock can be started with:

```text
RUN
```

## Usage

When the clock is running, some actions can be taken by pressing certain keys on the keyboard:
|Key(s)|Action|
|-|-|
|H|Increment hours|
|SHIFT+H|Decrement hours|
|M|Increment minutes|
|SHIFT+M|Decrement minutes|
|Z|Set (hidden) second counter to 0|
|U|Update clock immediately|
|S|Toggle showing whether it's AM or PM. When this setting is ON, the number separator will be a dot in AM, and a colon in PM. When the setting is OFF, the separator is a colon at all times.|
|L|Load the current time from the petSD+ (on petSD+ builds, only)|

You can stop the clock and return to BASIC by pressing RUN/STOP.

## 6502 assembly

For those who would like more information about the 6502 CPU and/or about writing assembly code for it, the folks at [6502.org](http://www.6502.org) have compiled a lot of resources on the topic. Amongst others, there is a page that contains [links to tutorials and primers](http://www.6502.org/tutorials/), which itself links to a [detailed description of the 6502 opcodes](http://www.6502.org/tutorials/6502opcodes.html) used in the PET clock source code.
