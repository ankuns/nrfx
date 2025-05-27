###############################################################################
#  CPU & BOARD info
#

ARCH_SET("RISC-V")

set(STARTUP_FILE "gcc_startup_nrf7140_umac.S")
set(SYSTEM_FILE "system_nrf71.c")

set(NORDIC_DEVICE "NRF7140_XXAA")
set(NORDIC_DOMAIN "NRF_UMAC")

set(FLAG_RISCV_ARCH "rv32emc_zicsr")
set(FLAG_RISCV_ABI  "ilp32e")

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x0E09A000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0x79000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x28100000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x90000)
endif()

set(FLASHING_COMMAND echo "Not supported - HALTIUM targets work only on PALLADIUM emulator")
set(RESETTING_COMMAND)
