###############################################################################
#  CPU & BOARD info
#

ARCH_SET("ARM Cortex-M")

if(IS_LINKER_TOOLCHAIN)
  set(STARTUP_FILE "gcc_startup_nrf54lm20a_enga_application.S")
elseif(IS_SCATTER_TOOLCHAIN)
  set(STARTUP_FILE "arm_startup_nrf54lm20a_enga_application.s")
endif()

set(SYSTEM_FILE "system_nrf54l.c")
set(SVD_FILE    "nrf54lm20a_enga_application.svd")

set(NORDIC_DEVICE "NRF54LM20A_ENGA_XXAA")
set(NORDIC_DOMAIN "NRF_APPLICATION")

set(FLAG_CORE "cortex-m33")

if (NOT FLAG_FPU)
    set(FLAG_FPU  "hard")
endif()

if (NOT FLASH_START_ADDR)
  set(FLASH_START_ADDR 0x00000000)
endif()

if (NOT FLASH_SIZE)
  set(FLASH_SIZE       0x100000)
endif()

if (NOT RAM_START_ADDR)
  set(RAM_START_ADDR   0x20000000)
endif()

if (NOT RAM_SIZE)
  set(RAM_SIZE         0x20000)
endif()

if (NOT UICR_ADDRESS)
  set(UICR_ADDRESS     0x00FFE000)
endif()

set(FLASHING_COMMAND nrfutil device program --firmware)
set(RESETTING_COMMAND nrfjprog --family NRF54L --pinreset)
