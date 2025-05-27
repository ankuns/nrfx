###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf52840.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf52840.s")
endif()

set(SYSTEM_FILE "system_nrf52840.c")

set(NORDIC_DEVICE "NRF52840_XXAA")

set(FLAG_CORE "cortex-m4")
set(FLAG_FPU  "hard")

set(FLASH_START_ADDR 0x0)
set(FLASH_SIZE       0x100000)
set(RAM_START_ADDR   0x20000200)
set(RAM_SIZE         0x3fe00)

set(FLASHING_COMMAND nrfjprog --sectorerase --program)
set(RESETTING_COMMAND nrfjprog --pinreset)
