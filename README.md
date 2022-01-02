# PET Clock

Source code to [Dave's Garage](https://www.youtube.com/c/DavesGarage/featured) video discussing a complete application in 6502 assembly.

[![Assembly Language Snow Day! Learn ASM Now! | Dave's Garage](https://img.youtube.com/vi/CfbciNZvg0o/0.jpg)](https://youtu.be/CfbciNZvg0o)

## Building

This repository's code targets the ca65 assembler and cl65 linker that are part of the [cc65](https://cc65.github.io/) GitHub project. You will need a fairly recent build of cc65 for assembly of this repository's contents to work.
With the cc65 toolkit installed and in your PATH, you can build the application using the following command:
```
cl65 -o petclock.prg -t none petclock.asm
```