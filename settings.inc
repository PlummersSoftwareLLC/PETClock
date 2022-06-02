COLUMNS         = 40    ; Screen width, either 40 or 80
DEBUG           = 0     ; Enable code that only is included for debug builds
DEVICE_NUM      = 9     ; Device number of the petSD+; only used if PETSDPLUS=1
EPROM           = 0     ; When TRUE, no BASIC stub, no load address in file
PETSDPLUS       = 0     ; When TRUE, read RTC from petSD+. Only supported on PET
SHOWAMDEFAULT   = 1     ; Use a dot separator for AM and colon for PM
COLOR           = 5     ; Color to use for the clock characters
JIFFYLAGCOMP    = 28    ; Jiffy lag compensation value

; --- Uncomment one of the following two lines to select the build target.
;     Alternatively, either symbol can be defined using the ca65/cl65 command line.

;C64             = 1     ; Set to 1 to build for C64. Either this or PET must be 1
;PET             = 1     ; Set to 1 to build for PET. Either this or C64 must be 1
