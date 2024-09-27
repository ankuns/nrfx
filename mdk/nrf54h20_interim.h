/*

Copyright (c) 2010 - 2024, Nordic Semiconductor ASA All rights reserved.

SPDX-License-Identifier: BSD-3-Clause

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of Nordic Semiconductor ASA nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef NRF54H20_INTERIM_H__
#define NRF54H20_INTERIM_H__

#include "haltium_interim.h"

#if defined(NRF54H20_XXAA)

    #if defined(NRF_TRUSTZONE_NONSECURE)
        #if defined(NRF_APPLICATION)
            #define GRTC_IRQ_GROUP 2
            #define GPIOTE_IRQ_GROUP 2
        #elif defined(NRF_RADIOCORE)
            #define GRTC_IRQ_GROUP 4
            #define GPIOTE_IRQ_GROUP 4
        #endif
    #elif defined(NRF_PPR)
        #define GRTC_IRQ_GROUP 8
        #define GPIOTE_IRQ_GROUP 2
    #elif defined(NRF_FLPR)
        #define GRTC_IRQ_GROUP 9
        #define GPIOTE_IRQ_GROUP 2
    #else
        #if defined(NRF_APPLICATION)
            #define GRTC_IRQ_GROUP 3
            #define GPIOTE_IRQ_GROUP 3
        #elif defined(NRF_RADIOCORE)
            #define GRTC_IRQ_GROUP 5
            #define GPIOTE_IRQ_GROUP 5
        #endif
    #endif

    #define P0_PIN_NUM P0_PIN_NUM_SIZE
    #define P1_PIN_NUM P1_PIN_NUM_SIZE
    #define P2_PIN_NUM P2_PIN_NUM_SIZE
    #define P6_PIN_NUM P6_PIN_NUM_SIZE
    #define P7_PIN_NUM P7_PIN_NUM_SIZE
    #define P9_PIN_NUM P9_PIN_NUM_SIZE

    #define DPPI_CH_NUM 8

    #undef ETM_TRCRSCTLR_MaxCount
    #undef RADIO_PENALTYREG_PCP_MaxCount

    #define ETM_TRCRSCTLR_MaxCount (32UL)                          /*!< Max size of TRCRSCTLR[32] array.            */
    #define RADIO_PENALTYREG_PCP_MaxCount (5UL)                    /*!< Max size of PCP[5] array.                   */

    #define EASYVDMA_PRESENT

    #define RTC_CC_NUM    RTC_CC_NUM_SIZE
    #define RTC130_CC_NUM RTC130_CC_NUM_SIZE
    #define RTC131_CC_NUM RTC131_CC_NUM_SIZE

    #define TIMER020_MAX_SIZE TIMER020_MAX_SIZE_SIZE
    #define TIMER021_MAX_SIZE TIMER021_MAX_SIZE_SIZE
    #define TIMER022_MAX_SIZE TIMER022_MAX_SIZE_SIZE
    #define TIMER120_MAX_SIZE TIMER120_MAX_SIZE_SIZE
    #define TIMER121_MAX_SIZE TIMER121_MAX_SIZE_SIZE
    #define TIMER130_MAX_SIZE TIMER130_MAX_SIZE_SIZE
    #define TIMER131_MAX_SIZE TIMER131_MAX_SIZE_SIZE
    #define TIMER132_MAX_SIZE TIMER132_MAX_SIZE_SIZE
    #define TIMER133_MAX_SIZE TIMER133_MAX_SIZE_SIZE
    #define TIMER134_MAX_SIZE TIMER134_MAX_SIZE_SIZE
    #define TIMER135_MAX_SIZE TIMER135_MAX_SIZE_SIZE
    #define TIMER136_MAX_SIZE TIMER136_MAX_SIZE_SIZE
    #define TIMER137_MAX_SIZE TIMER137_MAX_SIZE_SIZE

    #define TIMER020_CC_NUM TIMER020_CC_NUM_SIZE
    #define TIMER021_CC_NUM TIMER021_CC_NUM_SIZE
    #define TIMER022_CC_NUM TIMER022_CC_NUM_SIZE
    #define TIMER120_CC_NUM TIMER120_CC_NUM_SIZE
    #define TIMER121_CC_NUM TIMER121_CC_NUM_SIZE
    #define TIMER130_CC_NUM TIMER130_CC_NUM_SIZE
    #define TIMER131_CC_NUM TIMER131_CC_NUM_SIZE
    #define TIMER132_CC_NUM TIMER132_CC_NUM_SIZE
    #define TIMER133_CC_NUM TIMER133_CC_NUM_SIZE
    #define TIMER134_CC_NUM TIMER134_CC_NUM_SIZE
    #define TIMER135_CC_NUM TIMER135_CC_NUM_SIZE
    #define TIMER136_CC_NUM TIMER136_CC_NUM_SIZE
    #define TIMER137_CC_NUM TIMER137_CC_NUM_SIZE

    #define DPPIC020_CH_NUM DPPIC020_CH_NUM_SIZE
    #define DPPIC030_CH_NUM DPPIC030_CH_NUM_SIZE
    #define DPPIC120_CH_NUM DPPIC120_CH_NUM_SIZE
    #define DPPIC130_CH_NUM DPPIC130_CH_NUM_SIZE
    #define DPPIC131_CH_NUM DPPIC131_CH_NUM_SIZE
    #define DPPIC132_CH_NUM DPPIC132_CH_NUM_SIZE
    #define DPPIC133_CH_NUM DPPIC133_CH_NUM_SIZE
    #define DPPIC134_CH_NUM DPPIC134_CH_NUM_SIZE
    #define DPPIC135_CH_NUM DPPIC135_CH_NUM_SIZE
    #define DPPIC136_CH_NUM DPPIC136_CH_NUM_SIZE

    #define DPPIC020_GROUP_NUM DPPIC020_GROUP_NUM_SIZE
    #define DPPIC030_GROUP_NUM DPPIC030_GROUP_NUM_SIZE
    #define DPPIC120_GROUP_NUM DPPIC120_GROUP_NUM_SIZE
    #define DPPIC130_GROUP_NUM DPPIC130_GROUP_NUM_SIZE
    #define DPPIC131_GROUP_NUM DPPIC131_GROUP_NUM_SIZE
    #define DPPIC132_GROUP_NUM DPPIC132_GROUP_NUM_SIZE
    #define DPPIC133_GROUP_NUM DPPIC133_GROUP_NUM_SIZE
    #define DPPIC134_GROUP_NUM DPPIC134_GROUP_NUM_SIZE
    #define DPPIC135_GROUP_NUM DPPIC135_GROUP_NUM_SIZE
    #define DPPIC136_GROUP_NUM DPPIC136_GROUP_NUM_SIZE

    #define EGU020_CH_NUM EGU020_CH_NUM_SIZE
    #define EGU130_CH_NUM EGU130_CH_NUM_SIZE


#endif

#endif // NRF54H20_INTERIM_H__
