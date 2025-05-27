###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf5340_application.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf5340_application.s")
endif()

set(SYSTEM_FILE "system_nrf5340_application.c")

set(NORDIC_DEVICE "NRF5340_XXAA")
set(NORDIC_DOMAIN "NRF_APPLICATION")

set(FLAG_CORE "cortex-m33")
set(FLAG_FPU  "hard")

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x0)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE 0x100000)
endif()

set(RAM_START_ADDR 0x20000200)
set(RAM_SIZE       0x3fe00)

set(FLASHING_COMMAND nrfjprog --coprocessor CP_APPLICATION --sectorerase --program)
set(FLASHING_QSPI_COMMAND nrfjprog --coprocessor CP_APPLICATION --qspisectorerase --program)
set(RESETTING_COMMAND nrfjprog --pinreset)
