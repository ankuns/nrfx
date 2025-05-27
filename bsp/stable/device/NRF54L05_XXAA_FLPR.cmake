###############################################################################
#  CPU & BOARD info
#

ARCH_SET("RISC-V")

set(STARTUP_FILE "gcc_startup_nrf54l05_flpr.S")
set(SYSTEM_FILE "system_nrf54l.c")

set(NORDIC_DEVICE "NRF54L05_XXAA")
set(NORDIC_DOMAIN "NRF_FLPR")

set(FLAG_RISCV_ARCH "rv32emc_zicsr")
set(FLAG_RISCV_ABI  "ilp32e")

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x00040000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0x0003D000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x20010000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x8000)
endif()

set(FLASHING_COMMAND nrfjprog --family NRF54L --sectorerase --verify --program)
set(RESETTING_COMMAND nrfjprog --family NRF54L --pinreset)
