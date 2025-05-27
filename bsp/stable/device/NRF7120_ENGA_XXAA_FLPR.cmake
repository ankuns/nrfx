###############################################################################
#  CPU & BOARD info
#

ARCH_SET("RISC-V")

set(STARTUP_FILE "gcc_startup_nrf7120_enga_flpr.S")
set(SYSTEM_FILE "system_nrf7120_enga.c")

set(NORDIC_DEVICE "NRF7120_ENGA_XXAA")
set(NORDIC_DOMAIN "NRF_FLPR")

set(FLAG_RISCV_ARCH "rv32emc_zicsr")
set(FLAG_RISCV_ABI  "ilp32e")

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x00100000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0x00020000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x200E0000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x20000)
endif()

set(FLASHING_COMMAND echo "No hardware available yet")
set(RESETTING_COMMAND)
