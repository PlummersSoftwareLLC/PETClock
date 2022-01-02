# PET Clock

Source code to [Dave's Garage](https://www.youtube.com/c/DavesGarage/featured) video discussing a complete application in 6502 assembly.

[![Assembly Language Snow Day! Learn ASM Now! | Dave's Garage](https://img.youtube.com/vi/CfbciNZvg0o/0.jpg)](https://youtu.be/CfbciNZvg0o)

## Building

This repository's code targets the ca65 assembler and cl65 linker that are part of the [cc65](https://cc65.github.io/) GitHub project. You will need a fairly recent build of cc65 for assembly of this repository's contents to work.

With the cc65 toolkit installed and in your PATH, you can build the application using the following command:

```text
cl65 -o petclock.prg -t none petclock.asm
```

## 6502 assembly

For those who would like more information about the 6502 CPU and/or about writing assembly code for it, the folks at [6502.org](http://www.6502.org) have compiled a lot of resources on the topic. Amongst others, there is a page that contains [links to tutorials and primers](http://www.6502.org/tutorials/), which itself links to a [detailed description of the 6502 opcodes](http://www.6502.org/tutorials/6502opcodes.html) used in the PET clock source code.
