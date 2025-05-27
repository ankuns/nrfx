###############################################################################
#  CPU & BOARD info
#

ARCH_SET("RISC-V")

set(STARTUP_FILE "gcc_startup_nrf54h20_flpr.S")
set(SYSTEM_FILE "system_nrf54h.c")

set(NORDIC_DEVICE "NRF54H20_XXAA")
set(NORDIC_DOMAIN "NRF_FLPR")

set(FLAG_RISCV_ARCH "rv32emc_zicsr")
set(FLAG_RISCV_ABI  "ilp32e")

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x0E120000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0xA000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x2F890000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x10000)
endif()

set(FLASHING_COMMAND echo "Not supported - HALTIUM targets work only on PALLADIUM emulator")
set(RESETTING_COMMAND)
