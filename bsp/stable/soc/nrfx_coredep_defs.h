/*$$$LICENCE_NORDIC_STANDARD<2018>$$$*/

#ifndef NRFX_COREDEP_DEFS_H__
#define NRFX_COREDEP_DEFS_H__

#if !defined(__NRFX_DOXYGEN__)

#if defined(NRFX_DELAY_CPU_FREQ_MHZ) && defined(NRFX_DELAY_DWT_PRESENT)
    /* Do nothing. */
#elif defined(NRF51)
    #define NRFX_DELAY_CPU_FREQ_MHZ 16
    #define NRFX_DELAY_DWT_PRESENT  0
#elif defined(NRF52805_XXAA) || defined(NRF52810_XXAA) || \
      defined(NRF52811_XXAA) || defined(NRF52820_XXAA)
    #define NRFX_DELAY_CPU_FREQ_MHZ 64
    #define NRFX_DELAY_DWT_PRESENT  0
#elif defined(NRF52832_XXAA) || defined(NRF52832_XXAB) || \
      defined(NRF52833_XXAA) || defined(NRF52840_XXAA) || \
      defined(NRF9120_XXAA)  || defined(NRF9160_XXAA)
    #define NRFX_DELAY_CPU_FREQ_MHZ 64
    #define NRFX_DELAY_DWT_PRESENT  1
#elif defined(NRF5340_XXAA_APPLICATION)
    #define NRFX_DELAY_CPU_FREQ_MHZ (SystemCoreClock / 1000000)
    #define NRFX_DELAY_DWT_PRESENT  1
#elif defined(NRF5340_XXAA_NETWORK)
    #define NRFX_DELAY_CPU_FREQ_MHZ 64
    #define NRFX_DELAY_DWT_PRESENT  1
#elif defined(NRF54H20_XXAA) || defined(NRF9230_ENGB_XXAA)
    #define NRFX_DELAY_CPU_FREQ_MHZ (SystemCoreClock / 1000000)
    #define NRFX_DELAY_DWT_PRESENT  0
#elif defined(LUMOS_XXAA)
    #define NRFX_DELAY_CPU_FREQ_MHZ (SystemCoreClock / 1000000)
    #define NRFX_DELAY_DWT_PRESENT  1
#elif defined(NRF7120_ENGA_XXAA)
    #define NRFX_DELAY_CPU_FREQ_MHZ (SystemCoreClock / 1000000)
    #define NRFX_DELAY_DWT_PRESENT  1
#else
    #error "Unknown device"
#endif
#endif

#ifndef NRFX_COREDEP_DELAY_US_LOOP_CYCLES
    // Allow overriding the number of cycles per loop iteration, in case it is
    // needed to adjust this number externally (for example, when the SoC is
    // emulated).
    #if NRFX_CHECK(ISA_ARM)
        #if defined(NRF51)
            // The loop takes 4 cycles: 1 for SUBS, 3 for BHI.
            #define NRFX_COREDEP_DELAY_US_LOOP_CYCLES  4
        #elif defined(NRF52805_XXAA) || defined(NRF52810_XXAA) || \
              defined(NRF52811_XXAA) || defined(NRF52820_XXAA)
            // The loop takes 7 cycles: 1 for SUBS, 2 for BHI, 2 wait states
            // for each instruction.
            #define NRFX_COREDEP_DELAY_US_LOOP_CYCLES  7
        #else
            // The loop takes 3 cycles: 1 for SUBS, 2 for BHI.
            #define NRFX_COREDEP_DELAY_US_LOOP_CYCLES  3
        #endif
    #endif
#endif // NRFX_COREDEP_DELAY_US_LOOP_CYCLES

#endif // NRFX_COREDEP_DEFS_H__
