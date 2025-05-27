###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf9120.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf9120.s")
endif()

set(SYSTEM_FILE "system_nrf91.c")

set(NORDIC_DEVICE "NRF9120_XXAA")
set(NORDIC_DOMAIN "NRF_APPLICATION")

set(FLAG_CORE "cortex-m33")
set(FLAG_FPU  "hard")

set(FLASH_START_ADDR 0x0)
set(FLASH_SIZE       0x100000)
set(RAM_START_ADDR   0x20000200)
set(RAM_SIZE         0x3fe00)

set(FLASHING_COMMAND nrfjprog --sectorerase --program)
set(RESETTING_COMMAND nrfjprog --pinreset)
