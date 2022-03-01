;-----------------------------------------------------------------------------------
; Large Text Clock for CBM/PET and C64 6502
;-----------------------------------------------------------------------------------
; (c) Dave Plummer, 2016. If you can read it, you can use it! No warranties!
; Includes contributions from Rutger van Bergen
;-----------------------------------------------------------------------------------

; System selection -----------------------------------------------------------------

.ifndef C64
    C64         = 0
.endif

.ifndef PET
    PET         = 0
.endif

.if (.not (PET .xor C64))
    .fatal "Define exactly one of PET or C64 to equal 1."
.endif

.if (C64 .and PETSDPLUS)
    .fatal "petSD+ is currently not supported on the C64."
.endif

; Definitions ----------------------------------------------------------------------

.if C64
    __C64__         = 1

    .include "c64.inc"

    .if EPROM
        BASE        = $8000     ; Open C64 ROM space (not re)
    .else
        BASE        = $0801     ; C64 Start of BASIC
    .endif

    zptmp           = $FB
    zptmpB          = $FD
    zptmpC          = $22

    SCRATCH_START   = $033C   ; Second cassette buffer on PET
    SCRATCH_END     = $03FB   ; End of cassette buffer
    SCREEN_MEM      = $0400   ; Screen buffer of 1000 bytes

    TEXT_COLOR      = $0286

    COLOR_BLACK     = 0
.endif

.if PET
    .include "pet.inc"

    .if EPROM
        BASE        = $B000     ; Open PET ROM space
    .else
        BASE        = $0401     ; PET Start of BASIC
    .endif

    zptmp           = $BD
    zptmpB          = $00
    zptmpC          = $1F

    SCRATCH_START   = $033A   ; Second cassette buffer on PET
    SCRATCH_END     = $03F9   ; End of cassette buffer
    SCREEN_MEM      = $8000

    CLRSCR          = $E015

.endif

; Includes -------------------------------------------------------------------------

.include "cbm_kernal.inc"

; System Definition ----------------------------------------------------------------

    SECOND_JIFFIES  = 60                  ; Number of jiffies in a second
    MINUTE_JIFFIES  = 60 * SECOND_JIFFIES ; Number of jiffies in a minute
    MESSAGE_START   = SCREEN_MEM + 22 * COLUMNS

;-----------------------------------------------------------------------------------
; Common definitions for all Commodore BASICs
;-----------------------------------------------------------------------------------
    CR              = $0D ; CARRIAGE RETURN
    QUOT            = $22 ; Quote characarter
    CURDN           = $11 ; cursor down
;---------- tokens -----------------------------------------------------------------
    TK_MUL          = $AC ; *
    TK_POW          = $AE ; ^
    TK_GT           = $B1 ; >
    TK_EQU          = $B2 ; =
    TK_LT           = $B3 ; <
    TK_IF           = $8B ; IF
    TK_REM          = $8F ; REM
    TK_PRINT        = $99 ; PRINT
    TK_SYS          = $9E ; SYS
    TK_NEW          = $A2 ; NEW
    TK_THEN         = $A7 ; THEN
    TK_PEEK         = $C2 ; PEEK