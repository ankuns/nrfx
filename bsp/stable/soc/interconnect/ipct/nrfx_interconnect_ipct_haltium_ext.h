/*$$$LICENCE_NORDIC_STANDARD<2023>$$$*/

#ifndef NRFX_INTERCONNECT_IPCT_HALTIUM_EXT_H__
#define NRFX_INTERCONNECT_IPCT_HALTIUM_EXT_H__

#if defined(NRF_CELLCORE)
    #include "stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_cellcore.h"
#elif defined(NRF_SYSCTRL)
    #include "stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_sysctrl.h"
#elif defined(NRF_SECURE)
    #include "stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_secure.h"
#elif defined(NRF_LMAC)
    #include "stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_lmac.h"
#elif defined(NRF_UMAC)
    #include "stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_umac.h"
#else
    #error "Unknown device."
#endif

#endif // NRFX_INTERCONNECT_IPCT_HALTIUM_EXT_H__
