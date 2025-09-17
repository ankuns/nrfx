
nrfx 4.0 introduces API changes. This guide lists actions required to make your code compatible with these changes.

# BSP

- Added new directory that contains:
    - MDK
    - SoC-specific templates
    - SoC-specific defines from nrfx drivers
    - Soc-specific files from `soc/` directory (IRQ handlers and interconnect)
    - board, device and target CMake files [internal]

- Added support for more that one BSP - by default stable BSP is used, which contains BSP files for public SoCs. However, there is an option to add another BSP, next to stable.

Action: no action required from user's side.
Action [internal]: there are several things to remember when adding new BSP:
 - all BSP's files need to be in `bsp` directory and each BSP has its own subdirectory. This means that a new BSP should be placed in `bsp/<bsp_name>`
 - BSPs with internal SoCs should not be a part of nrfx. They should be placed in separate repositories and added to `west.yml` in nrfx-verification.
 - when adding new BSP, one should remember to add `change_bsp(<bsp_name>)` to all device CMake files in the new BSP, where `bsp_name` is name of directory, in which it is placed. Example: [link](https://github.com/nrfconnect/nrfx/blob/nrfx-bsp-lumos/device/NRF54L10_XXAA_APPLICATION.cmake#L19)
 - if any Soc in the new BSP needs some files from stable BSP, then those files need to be copied to the new BSP and have the same relative path.


# Errata rework
Reworked the errata system.
The workarounds for unsupported SoCs were removed.
Summary table [Doxygen file](errata.dox) was created, which presents the currently implemented workarounds in nrfx.

Added the following errata workarounds:
- nRF52 Series:
    - 58,
    - 173,
    - 174,
    - 214,
- nRF53 Series:
    - 65,
    - 119,
- nRF91 Series:
    - 7 (added `nrfx_nvmc_uicr_word_write()` and fixed `nrfx_nvmc_otp_halfword_read()`).

Some errata are now disabled by default, even if the chip should apply them.
They should be carefully enabled by the user on a case-by-case manner.
The list includes:
- nRF52 Series erratum 58,
- nRF52 Series erratum 109.

Action:
- Remove fixes for errata now handled internally by the nrfx,
- If required, explicitly enable nRF52 Series erratum 58 workaround, by defining `NRF52_ERRATA_58_ENABLE_WORKAROUND` to `1`,
- If required, explicitly enable nRF52 Series erratum 109 workaround, by defining `NRF52_ERRATA_109_ENABLE_WORKAROUND` to `1`.

## nRF52840 erratum 174
Implemented erratum 174 handling on nRF52840.
Now, the PPI driver will internally swap the pointers for SPIM3 `ENDTX` and `ENDRX` events.

Action: If you're passing manually swapped pointers for SPIM3 `ENDTX` and `ENDRX` event endpoints
to `nrfx_gppi_channel_endpoints_setup()` function, you need to revert your modifications.

## Rework internals [internal]
Added new macros for unified errata checks:
- `NRF_ERRATA_STATIC_CHECK(series, erratum)` -- compile-time check for compile target chip,
- `NRF_ERRATA_DYNAMIC_CHECK(series, erratum)` -- runtime check for the chip's hardware revision.

These macros are used across nrfx to check whether the SoC is affected by a given erratum.
Old `USE_WORKAROUND_*` macros were cleaned up and are no longer used.

A new file named `nrfx_errata.h` was added.
It disables certain errata workarounds even if the chip should apply them.
Cases listed there use multiple peripherals to circumvent erratum consequences,
using up too much resources to be enabled by default.
They should be carefully enabled by the user on a case-by-case manner.

# Others

## Build system [internal]

- Moved CMake files - moved board, device and target CMake files to BSP
- Reversed test-target specification - previously each test had list of devices that support it. It was changed so that now each device has a list of tests that are supported.

Action: adding support for new platform should be done now by adding test name to `DEVICE_SUPPORTED_TESTS` list in device CMake file (`bsp/<bsp_name>/device/<device_name>.cmake`). Additionally, when adding new test one should remember to add its name to its CMake file and then add it to `DEVICE_SUPPORTED_TESTS` list for devices that support that test.
