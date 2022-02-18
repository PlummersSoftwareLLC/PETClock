# PET Clock for PET or Commodore 64

[![CI](https://github.com/PlummersSoftwareLLC/PETClock/actions/workflows/CI.yml/badge.svg)](https://github.com/PlummersSoftwareLLC/PETClock/actions/workflows/CI.yml)

Source code to [Dave's Garage](https://www.youtube.com/c/DavesGarage/featured) video discussing a complete application in 6502 assembly.

[![Assembly Language Snow Day! Learn ASM Now! | Dave's Garage](https://img.youtube.com/vi/CfbciNZvg0o/0.jpg)](https://youtu.be/CfbciNZvg0o)

## Configuring and building

In the [`settings.inc`](settings.inc) file, a number of symbols are defined that can be used to configure the build:
|Name|Possible values|Mandatory|Meaning|
|-|-|-|-|
|C64|0 or 1|No|Configure build for the Commodore 64. Exactly one of C64 or PET **must** be defined to equal 1.|
|COLOR|1 to 15|On C64|Color code to use for the characters of the clock. Only used and needed on the Commodore 64. A reference for the color C64 codes can be found [here](https://www.c64-wiki.com/wiki/Color).|
|COLUMNS|40 or 80|Yes|Screen width of the target machine, in columns.|
|DEBUG|0 or 1|Yes|Set to 1 to enable code that only is included for debug builds.|
|DEVICE_NUM|8 to 15|With petSD+|Device number of the petSD+. Only used if PETSDPLUS=1.|
|EPROM|0 or 1|Yes|When set to 1, the BASIC stub and load address will not be included in the build output.|
|PET|0 or 1|No|Configure build for the PET. Exactly one of C64 or PET **must** be defined to equal 1.|
|PETSDPLUS|0 or 1|Yes|When set to 1, the clock will read RTC from [petSD+](http://petsd.net/) instead of the jiffy timer. Currently, the petSD+ is only supported on the PET.|
|SHOWAMDEFAULT|0 or 1|Yes|Set to 1 to use a dot separator for AM and colon for PM. Otherwise, the separator is a colon at all times.|

Note that the PET and C64 symbols are not set by default. The reason is that the assembly target is a prime candidate to be set via the command line.

This repository's code targets the ca65 assembler and cl65 linker that are part of the [cc65](https://cc65.github.io/) GitHub project. You will need a fairly recent build of cc65 for assembly of this repository's contents to work.

With the cc65 toolkit installed and in your PATH, you can build the application using any of the following commands:

* If the assembly target is set in `settings.inc`:

  ```text
  cl65 -o petclock.prg -t none petclock.asm
  ```

* For the PET:

  ```text
  cl65 -o petclock.prg --asm-define PET=1 -t none petclock.asm
  ```

* For the Commodore 64:

  ```text
  cl65 -o petclock.prg --asm-define C64=1 -t none petclock.asm
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
|C|Switch to the next character color in the palette (on C64 builds, only)|
|SHIFT-C|Switch to the previous character color in the palette (on C64 builds, only)|

You can stop the clock and return to BASIC by pressing RUN/STOP.

## 6502 assembly

For those who would like more information about the 6502 CPU and/or about writing assembly code for it, the folks at [6502.org](http://www.6502.org) have compiled a lot of resources on the topic. Amongst others, there is a page that contains [links to tutorials and primers](http://www.6502.org/tutorials/), which itself links to a [detailed description of the 6502 opcodes](http://www.6502.org/tutorials/6502opcodes.html) used in the PET clock source code.
