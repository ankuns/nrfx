/*$$$LICENCE_NORDIC_STANDARD<2025>$$$*/

#ifndef NRFX_IRQS_NRF54LS05B_ENGA_APPLICATION_H__
#define NRFX_IRQS_NRF54LS05B_ENGA_APPLICATION_H__

#ifdef __cplusplus
extern "C" {
#endif

// SWI00_IRQHandler

// SWI01_IRQHandler

// SWI02_IRQHandler

// SWI03_IRQHandler

// SPU00_IRQHandler

// MPC00_IRQHandler

// AAR00_CCM00_IRQHandler

// ECB00_IRQHandler

// RRAMC_IRQHandler
#define nrfx_rramc_irq_handler          RRAMC_IRQHandler

// CTRLAP_IRQHandler

// CM33SS_IRQHandler

// TIMER00_IRQHandler
#define nrfx_timer_00_irq_handler       TIMER00_IRQHandler

// EGU00_IRQHandler
#define nrfx_egu_00_irq_handler         EGU00_IRQHandler

// TRNG_IRQHandler

// ECCRAMC_IRQHandler

// SPU10_IRQHandler

// TIMER10_IRQHandler
#define nrfx_timer_10_irq_handler       TIMER10_IRQHandler

// EGU10_IRQHandler
#define nrfx_egu_10_irq_handler         EGU10_IRQHandler

// RADIO_0_IRQHandler

// RADIO_1_IRQHandler

// SPU20_IRQHandler

// SERIAL20_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_0_ENABLED)
#define nrfx_prs_box_0_irq_handler      SERIAL20_IRQHandler
#else
#define nrfx_spim_20_irq_handler        SERIAL20_IRQHandler
#define nrfx_spis_20_irq_handler        SERIAL20_IRQHandler
#define nrfx_twim_20_irq_handler        SERIAL20_IRQHandler
#define nrfx_twis_20_irq_handler        SERIAL20_IRQHandler
#define nrfx_uarte_20_irq_handler       SERIAL20_IRQHandler
#endif

// SERIAL21_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_1_ENABLED)
#define nrfx_prs_box_1_irq_handler      SERIAL21_IRQHandler
#else
#define nrfx_spim_21_irq_handler        SERIAL21_IRQHandler
#define nrfx_spis_21_irq_handler        SERIAL21_IRQHandler
#define nrfx_twim_21_irq_handler        SERIAL21_IRQHandler
#define nrfx_twis_21_irq_handler        SERIAL21_IRQHandler
#define nrfx_uarte_21_irq_handler       SERIAL21_IRQHandler
#endif

// SERIAL22_IRQHandler
#if NRFX_CHECK(NRFX_PRS_ENABLED) && NRFX_CHECK(NRFX_PRS_BOX_2_ENABLED)
#define nrfx_prs_box_2_irq_handler      SERIAL22_IRQHandler
#else
#define nrfx_spim_22_irq_handler        SERIAL22_IRQHandler
#define nrfx_spis_22_irq_handler        SERIAL22_IRQHandler
#define nrfx_twim_22_irq_handler        SERIAL22_IRQHandler
#define nrfx_twis_22_irq_handler        SERIAL22_IRQHandler
#define nrfx_uarte_22_irq_handler       SERIAL22_IRQHandler
#endif

// EGU20_IRQHandler
#define nrfx_egu_20_irq_handler         EGU20_IRQHandler

// TIMER20_IRQHandler
#define nrfx_timer_20_irq_handler       TIMER20_IRQHandler

// PWM20_IRQHandler
#define nrfx_pwm_20_irq_handler         PWM20_IRQHandler

// SAADC_IRQHandler
#define nrfx_saadc_irq_handler          SAADC_IRQHandler

// TEMP_IRQHandler
#define nrfx_temp_irq_handler           TEMP_IRQHandler

// GPIOTE20_0_IRQHandler
#define nrfx_gpiote_20_irq_handler      GPIOTE20_0_IRQHandler

// TAMPC_IRQHandler

// QDEC20_IRQHandler
#define nrfx_qdec_20_irq_handler        QDEC20_IRQHandler

// GRTC_0_IRQHandler
// GRTC_1_IRQHandler
// GRTC_2_IRQHandler
// GRTC_3_IRQHandler
#define nrfx_grtc_irq_handler           GRTC_IRQHandler

// SPU30_IRQHandler

// WDT30_IRQHandler
#define nrfx_wdt_30_irq_handler         WDT30_IRQHandler

// GPIOTE30_0_IRQHandler
#define nrfx_gpiote_30_irq_handler      GPIOTE30_0_IRQHandler

// CLOCK_POWER_IRQHandler
#define nrfx_power_clock_irq_handler    CLOCK_POWER_IRQHandler

#ifdef __cplusplus
}
#endif

#endif // NRFX_IRQS_NRF54LS05B_ENGA_APPLICATION_H___
