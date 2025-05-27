###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf9220_cellrf.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf9220_cellrf.s")
endif()

set(SYSTEM_FILE "system_nrf92.c")

set(NORDIC_DEVICE "NRF9220_XXAA")
set(NORDIC_DOMAIN "NRF_CELLRF")

set(FLAG_CORE "cortex-m33")

if (NOT FLAG_FPU)
    set(FLAG_FPU  "soft")
endif()

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x00000000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0x00040000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x26000000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x0001C000)
endif()

set(FLASHING_COMMAND echo "No hardware available yet")
set(RESETTING_COMMAND)
