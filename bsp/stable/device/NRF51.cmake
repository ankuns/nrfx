###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf51.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf51.s")
endif()

set(SYSTEM_FILE "system_nrf51.c")

set(NORDIC_DEVICE "NRF51")
list(APPEND C_DEFINES "NRF51422_XXAC")

set(FLAG_CORE "cortex-m0")
set(FLAG_FPU  "soft")

set(FLASH_START_ADDR 0x0)
set(FLASH_SIZE       0x40000)
set(RAM_START_ADDR   0x20000200)
set(RAM_SIZE         0x7e00)

set(FLASHING_COMMAND nrfjprog --sectorerase --program)
set(RESETTING_COMMAND nrfjprog --pinreset)
