/*$$$LICENCE_NORDIC_STANDARD<2025>$$$*/

#ifndef NRFX_SOC_DEFINES_H__
#define NRFX_SOC_DEFINES_H__

#include <nrfx.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(NRF54LV10A_ENGA_XXAA)
#define ANALOG_REF_INTERNAL_VAL 1300
#elif defined(HALTIUM_XXAA) || defined(NRF7120_ENGA_XXAA) || defined(NRF54LS05B_ENGA_XXAA)
#define ANALOG_REF_INTERNAL_VAL 1024
#elif defined(LUMOS_XXAA)
#define ANALOG_REF_INTERNAL_VAL 900
#else
#define ANALOG_REF_INTERNAL_VAL 600
#endif

#if defined(HALTIUM_XXAA)
    #define COMP_EXTERNAL_AIN_PSELS        \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1)
#elif defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    #define COMP_EXTERNAL_AIN_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(13U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(14U, 1)
#elif defined(NRF54LM20A_ENGA_XXAA)
    #define COMP_EXTERNAL_AIN_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(31U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(30U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(29U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1)
#elif defined(NRF54LV10A_ENGA_XXAA)
    #define COMP_EXTERNAL_AIN_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(10U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1)
#elif defined(NRF54LS05B_ENGA_XXAA)
    #define COMP_EXTERNAL_AIN_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1)
#elif defined(NRF7120_ENGA_XXAA)
    #define COMP_EXTERNAL_AIN_PSELS                     \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 0),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(8U, 0),              \
        (nrf_comp_input_t)NRFX_COMP_INPUT_NOT_PRESENT,  \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 4),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 4),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 4),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 4),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 4),              \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 4)
#else /* legacy platforms */
    #define COMP_EXTERNAL_AIN_PSELS                                             \
        NRF_COMP_INPUT_0,                                                       \
        NRF_COMP_INPUT_1,                                                       \
        NRF_COMP_INPUT_2,                                                       \
        NRF_COMP_INPUT_3,                                                       \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_PSEL_PSEL_AnalogInput4), \
            (NRF_COMP_INPUT_4,), ())                                            \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_PSEL_PSEL_AnalogInput5), \
            (NRF_COMP_INPUT_5,), ())                                            \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_PSEL_PSEL_AnalogInput6), \
            (NRF_COMP_INPUT_6,), ())                                            \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_PSEL_PSEL_AnalogInput7), \
            (NRF_COMP_INPUT_7,), ())
#endif

#if defined(HALTIUM_XXAA)
    #define COMP_EXTERNAL_REF_PSELS        \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    #define COMP_EXTERNAL_REF_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(13U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(14U, 1),
#elif defined(NRF54LM20A_ENGA_XXAA)
    #define COMP_EXTERNAL_REF_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(31U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(30U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(29U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),
#elif defined(NRF54LV10A_ENGA_XXAA)
    #define COMP_EXTERNAL_REF_PSELS         \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(10U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1),
#elif defined(NRF54LS05B_ENGA_XXAA)
    #define COMP_EXTERNAL_REF_PSELS        \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF7120_ENGA_XXAA)
    #define COMP_EXTERNAL_REF_PSELS                      \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(8U, 0),               \
        (nrf_comp_ext_ref_t)NRFX_COMP_INPUT_NOT_PRESENT, \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 4),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 4),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 4),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 4),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 4),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 4),
#else /* legacy platforms */
    #define COMP_EXTERNAL_REF_PSELS                                                           \
        NRF_COMP_EXT_REF_0,                                                                   \
        NRF_COMP_EXT_REF_1,                                                                   \
        NRF_COMP_EXT_REF_2,                                                                   \
        NRF_COMP_EXT_REF_3,                                                                   \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_EXTREFSEL_EXTREFSEL_AnalogReference4), \
            (NRF_COMP_EXT_REF_4,), ())                                                        \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_EXTREFSEL_EXTREFSEL_AnalogReference5), \
            (NRF_COMP_EXT_REF_5,), ())                                                        \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_EXTREFSEL_EXTREFSEL_AnalogReference6), \
            (NRF_COMP_EXT_REF_6,), ())                                                        \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(COMP_EXTREFSEL_EXTREFSEL_AnalogReference7), \
            (NRF_COMP_EXT_REF_7,), ())
#endif

#if defined(HALTIUM_XXAA)
    #define LPCOMP_EXTERNAL_AIN_PSELS      \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    #define LPCOMP_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(13U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(14U, 1),
#elif defined(NRF54LM20A_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(31U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(30U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(29U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),
#elif defined(NRF54LV10A_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(10U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1),
#elif defined(NRF54LS05B_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_AIN_PSELS      \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF7120_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_AIN_PSELS                      \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 0),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(8U, 0),                 \
        (nrf_lpcomp_input_t)NRFX_LPCOMP_INPUT_NOT_PRESENT, \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 4),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 4),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 4),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 4),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 4),                 \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 4),
#else /* legacy platforms */
    #define LPCOMP_EXTERNAL_AIN_PSELS \
        NRF_LPCOMP_INPUT_0,           \
        NRF_LPCOMP_INPUT_1,           \
        NRF_LPCOMP_INPUT_2,           \
        NRF_LPCOMP_INPUT_3,           \
        NRF_LPCOMP_INPUT_4,           \
        NRF_LPCOMP_INPUT_5,           \
        NRF_LPCOMP_INPUT_6,           \
        NRF_LPCOMP_INPUT_7,
#endif

#if defined(HALTIUM_XXAA)
    #define LPCOMP_EXTERNAL_REF_PSELS      \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    #define LPCOMP_EXTERNAL_REF_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(13U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(14U, 1),
#elif defined(NRF54LM20A_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_REF_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(31U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(30U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(29U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),
#elif defined(NRF54LV10A_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_REF_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(10U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1),
#elif defined(NRF54LS05B_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_REF_PSELS      \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF7120_ENGA_XXAA)
    #define LPCOMP_EXTERNAL_REF_PSELS                    \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 0),               \
        NRF_PIN_PORT_TO_PIN_NUMBER(8U, 0),               \
    (nrf_lpcomp_ext_ref_t)NRFX_LPCOMP_INPUT_NOT_PRESENT, \
    NRF_PIN_PORT_TO_PIN_NUMBER(0U, 4),                   \
    NRF_PIN_PORT_TO_PIN_NUMBER(1U, 4),                   \
    NRF_PIN_PORT_TO_PIN_NUMBER(2U, 4),                   \
    NRF_PIN_PORT_TO_PIN_NUMBER(3U, 4),                   \
    NRF_PIN_PORT_TO_PIN_NUMBER(4U, 4),                   \
    NRF_PIN_PORT_TO_PIN_NUMBER(5U, 4),
#else /* legacy platforms */
    #define LPCOMP_EXTERNAL_REF_PSELS \
        NRF_LPCOMP_EXT_REF_REF0,      \
        NRF_LPCOMP_EXT_REF_REF1,
#endif

#if defined(HALTIUM_XXAA)
    #define SAADC_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 9), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 9), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 9), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 9), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 9), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 9),
#elif defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    #define SAADC_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(13U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(14U, 1),
#elif defined(NRF54LM20A_ENGA_XXAA)
    #define SAADC_EXTERNAL_AIN_PSELS        \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(31U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(30U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(29U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),
#elif defined(NRF54LV10A_ENGA_XXAA)
    #define SAADC_EXTERNAL_AIN_PSELS        \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),  \
        NRF_PIN_PORT_TO_PIN_NUMBER(10U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(11U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(12U, 1),
#elif defined(NRF54LS05B_ENGA_XXAA)
    #define SAADC_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 1), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 1),
#elif defined(NRF7120_ENGA_XXAA)
    #define SAADC_EXTERNAL_AIN_PSELS       \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(6U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(7U, 0), \
        NRF_PIN_PORT_TO_PIN_NUMBER(8U, 0), \
        NRFX_SAADC_INPUT_NOT_PRESENT,      \
        NRF_PIN_PORT_TO_PIN_NUMBER(0U, 4), \
        NRF_PIN_PORT_TO_PIN_NUMBER(1U, 4), \
        NRF_PIN_PORT_TO_PIN_NUMBER(2U, 4), \
        NRF_PIN_PORT_TO_PIN_NUMBER(3U, 4), \
        NRF_PIN_PORT_TO_PIN_NUMBER(4U, 4), \
        NRF_PIN_PORT_TO_PIN_NUMBER(5U, 4),
#else /* legacy platforms */
    #define SAADC_EXTERNAL_AIN_PSELS                                                   \
        NRF_SAADC_INPUT_AIN0,                                                          \
        NRF_SAADC_INPUT_AIN1,                                                          \
        NRF_SAADC_INPUT_AIN2,                                                          \
        NRF_SAADC_INPUT_AIN3,                                                          \
        NRF_SAADC_INPUT_AIN4,                                                          \
        NRF_SAADC_INPUT_AIN5,                                                          \
        NRF_SAADC_INPUT_AIN6,                                                          \
        NRF_SAADC_INPUT_AIN7,                                                          \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_AnalogInput8),  \
            (NRF_SAADC_INPUT_AIN8,), ())                                               \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_AnalogInput9),  \
            (NRF_SAADC_INPUT_AIN9,), ())                                               \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_AnalogInput10), \
            (NRF_SAADC_INPUT_AIN10,), ())                                              \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_AnalogInput11), \
            (NRF_SAADC_INPUT_AIN11,), ())                                              \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_AnalogInput12), \
            (NRF_SAADC_INPUT_AIN812,), ())                                             \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_AnalogInput13), \
            (NRF_SAADC_INPUT_AIN13,), ())
#endif

#if defined(NRF54L05_XXAA) || defined(NRF54L10_XXAA) || defined(NRF54L15_XXAA)
    #define SAADC_INTERNAL_AIN_PSELS                                     \
        NRF_SAADC_INPUT_VDD,                                             \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRF_SAADC_INPUT_AVDD,                                            \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(NRF_SAADC_INPUT_DVDD), \
            (NRF_SAADC_INPUT_DVDD,), (NRFX_SAADC_INPUT_NOT_PRESENT,))
#elif defined(NRF54LM20A_ENGA_XXAA)
    #define SAADC_INTERNAL_AIN_PSELS                                     \
        NRF_SAADC_INPUT_VDD,                                             \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRF_SAADC_INPUT_AVDD,                                            \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(NRF_SAADC_INPUT_DVDD), \
            (NRF_SAADC_INPUT_DVDD,), (NRFX_SAADC_INPUT_NOT_PRESENT,))
#elif defined(NRF54LV10A_ENGA_XXAA)
    #define SAADC_INTERNAL_AIN_PSELS                                     \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(NRF_SAADC_INPUT_DVDD), \
            (NRF_SAADC_INPUT_DVDD,), (NRFX_SAADC_INPUT_NOT_PRESENT,))    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRF_SAADC_INPUT_VDDL,                                            \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRF_SAADC_INPUT_VSS,
#elif defined(NRF54LS05B_ENGA_XXAA)
    #define SAADC_INTERNAL_AIN_PSELS                                     \
        NRF_SAADC_INPUT_DECB,                                            \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(NRF_SAADC_INPUT_DVDD), \
            (NRF_SAADC_INPUT_DVDD,), (NRFX_SAADC_INPUT_NOT_PRESENT,))    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                    \
        NRF_SAADC_INPUT_VSS,
#elif defined(NRF7120_ENGA_XXAA)
    #define SAADC_INTERNAL_AIN_PSELS  \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRFX_SAADC_INPUT_NOT_PRESENT, \
        NRF_SAADC_INPUT_INTERNAL0,    \
        NRF_SAADC_INPUT_INTERNAL1,    \
        NRF_SAADC_INPUT_INTERNAL2,    \
        NRF_SAADC_INPUT_INTERNAL3,
#else  /* legacy platforms */
    #define SAADC_INTERNAL_AIN_PSELS                                              \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_VDD),      \
            (NRF_SAADC_INPUT_VDD,), (NRFX_SAADC_INPUT_NOT_PRESENT,))              \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                             \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                             \
        NRFX_SAADC_INPUT_NOT_PRESENT,                                             \
        NRFX_COND_CODE_1(NRFX_ARG_HAS_PARENTHESIS(SAADC_CH_PSELP_PSELP_VDDHDIV5), \
            (NRF_SAADC_INPUT_VDDHDIV5,), (NRFX_SAADC_INPUT_NOT_PRESENT,))
#endif


#ifdef __cplusplus
}
#endif

#endif /* NRFX_SOC_DEFINES_H__ */
