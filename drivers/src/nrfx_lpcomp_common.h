/*$$$LICENCE_NORDIC_STANDARD<2025>$$$*/

#ifndef NRFX_LPCOMP_COMMON_H__
#define NRFX_LPCOMP_COMMON_H__

#include <helpers/nrfx_analog_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_lpcomp_common Generic LPCOMP inputs layer.
 * @{
 * @ingroup nrfx
 * @ingroup nrf_lpcomp
 *
 * @brief Helper layer that provides the common functionality of LPCOMP driver.
 */

/** @brief Symbol specifying not existing analog input. */
#define NRFX_LPCOMP_INPUT_NOT_PRESENT UINT32_MAX

 /** @brief LPCOMP external analog input pins mapping table. */
static const nrf_lpcomp_input_t nrfx_lpcomp_psels[] =
{
    LPCOMP_EXTERNAL_AIN_PSELS
};

/** @brief LPCOMP external analog reference pins mapping table. */
static const nrf_lpcomp_ext_ref_t nrfx_lpcomp_external_ref_psels[] =
{
    LPCOMP_EXTERNAL_REF_PSELS
};

/**
 * @brief Function for getting the LPCOMP input configuration for given generic analog input.
 *
 * @param[in] input The generic analog input to get the configuration for.
 *
 * @return The LPCOMP input configuration for the given analog input.
 *
 * @note The function returns NRFX_LPCOMP_INPUT_NOT_PRESENT for analog inputs that are not
 *       supported by the given device.
 */
NRFX_STATIC_INLINE nrf_lpcomp_input_t nrfx_lpcomp_ain_get(nrfx_analog_input_t input)
{
    if (input < NRFX_ARRAY_SIZE(nrfx_lpcomp_psels))
    {
        return nrfx_lpcomp_psels[input];
    }

    return (nrf_lpcomp_input_t)NRFX_LPCOMP_INPUT_NOT_PRESENT;
}

/**
 * @brief Function for getting the LPCOMP external reference input configuration
 *        for given generic analog input.
 *
 * @param[in] input The generic analog input to get the configuration for.
 *
 * @return The LPCOMP external reference input configuration for the given analog input.
 *
 * @note The function returns NRFX_LPCOMP_INPUT_NOT_PRESENT for reference inputs that are not
 *       supported by the given device.
 */
NRFX_STATIC_INLINE nrf_lpcomp_ext_ref_t nrfx_lpcomp_ext_ref_get(nrfx_analog_input_t input)
{
    if ((uint8_t)input < NRFX_ARRAY_SIZE(nrfx_lpcomp_external_ref_psels))
    {
        return nrfx_lpcomp_external_ref_psels[input];
    }

    return (nrf_lpcomp_ext_ref_t)NRFX_LPCOMP_INPUT_NOT_PRESENT;
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* NRFX_LPCOMP_COMMON_H__ */
