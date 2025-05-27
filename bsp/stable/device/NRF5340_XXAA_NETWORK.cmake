###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf5340_network.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf5340_network.s")
endif()

set(SYSTEM_FILE "system_nrf5340_network.c")

set(NORDIC_DEVICE "NRF5340_XXAA")
set(NORDIC_DOMAIN "NRF_NETWORK")

set(FLAG_CORE "cortex-m33")
set(FLAG_FPU  "soft")

set(FLASH_START_ADDR 0x01000000)
set(FLASH_SIZE       0x100000)
set(RAM_START_ADDR   0x21000200)
set(RAM_SIZE         0xfe00)

set(FLASHING_COMMAND nrfjprog --coprocessor CP_NETWORK --sectorerase --program)
set(RESETTING_COMMAND nrfjprog --pinreset)
