
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

# Others

## Build system [internal]

- Moved CMake files - moved board, device and target CMake files to BSP
- Reversed test-target specification - previously each test had list of devices that support it. It was changed so that now each device has a list of tests that are supported.

Action: adding support for new platform should be done now by adding test name to `DEVICE_SUPPORTED_TESTS` list in device CMake file (`bsp/<bsp_name>/device/<device_name>.cmake`). Additionally, when adding new test one should remember to add its name to its CMake file and then add it to `DEVICE_SUPPORTED_TESTS` list for devices that support that test.
