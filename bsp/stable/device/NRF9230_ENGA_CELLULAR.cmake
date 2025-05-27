###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf9230_enga_cellcore.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf9230_enga_cellcore.s")
endif()

set(SYSTEM_FILE "system_nrf92.c")
set(SVD_FILE    "nrf9230_enga_cellcore.svd")

set(NORDIC_DEVICE "NRF9230_ENGA_XXAA")
set(NORDIC_DOMAIN "NRF_CELLCORE")

set(FLAG_CORE "cortex-m33")

if (NOT FLAG_FPU)
  set(FLAG_FPU  "hard")
endif()

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x0E066000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0x400000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x24000000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x80000)
endif()

set(FLASHING_COMMAND echo "Not supported - HALTIUM targets work only on PALLADIUM emulator")
set(RESETTING_COMMAND)
