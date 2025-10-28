/*$$$LICENCE_NORDIC_STANDARD<2025>$$$*/

#ifndef NRFX_USED_RESOURCES_H
#define NRFX_USED_RESOURCES_H

#include <nrfx.h>

/**
 * @defgroup nrfx_used_resources nrfx_used_resources.h
 * @{
 * @ingroup nrfx
 *
 * @brief This file contains macros that provide information to the nrfx
 *        drivers about fixed resources used by modules external to nrfx.
 *
 * If any modules that use a fixed set of peripherals exist in a target build,
 * (like fixed set of PPI/DPPI channels, PPI/DPPI groups, etc.), then provide the
 * @c NRFX_USED_RESOURCES_INCLUDE_FILE macro to the build. This macro should
 * expand to a header file name in quotes that is included included into
 * the @c nrfx_used_resources.h file and is responsible for defining appropriate
 * macros informing about fixed resources used by modules external to nrfx.
 *
 * @note This file is not included by nrfx.h. Relevant drivers include it
 * separately.
 */

#ifdef   NRFX_USED_RESOURCES_INCLUDE_FILE
#include NRFX_USED_RESOURCES_INCLUDE_FILE
#endif

#ifndef NRFX_DPPI_CHANNELS_USED
/** @brief Bitmask that defines DPPI channels that are reserved for use outside of the nrfx library. */
#define NRFX_DPPI_CHANNELS_USED   0
#endif

#ifndef NRFX_DPPI_GROUPS_USED
/** @brief Bitmask that defines DPPI groups that are reserved for use outside of the nrfx library. */
#define NRFX_DPPI_GROUPS_USED     0
#endif

#ifndef NRFX_PPI_CHANNELS_USED
/** @brief Bitmask that defines PPI channels that are reserved for use outside of the nrfx library. */
#define NRFX_PPI_CHANNELS_USED    0
#endif

#ifndef NRFX_PPI_GROUPS_USED
/** @brief Bitmask that defines PPI groups that are reserved for use outside of the nrfx library. */
#define NRFX_PPI_GROUPS_USED      0
#endif

#ifndef NRFX_GPIOTE_CHANNELS_USED
/** @brief Bitmask that defines GPIOTE channels that are reserved for use outside of the nrfx library. */
#define NRFX_GPIOTE_CHANNELS_USED 0
#endif

#ifndef NRFX_EGUS_USED
/** @brief Bitmask that defines EGU instances that are reserved for use outside of the nrfx library. */
#define NRFX_EGUS_USED            0
#endif

#ifndef NRFX_TIMERS_USED
/** @brief Bitmask that defines TIMER instances that are reserved for use outside of the nrfx library. */
#define NRFX_TIMERS_USED          0
#endif

/** @} */

#endif // NRFX_USED_RESOURCES_H
