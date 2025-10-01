/*$$$LICENCE_NORDIC_STANDARD<2025>$$$*/

#ifndef NRFX_INTERCONNECT_IPCT_H__
#define NRFX_INTERCONNECT_IPCT_H__


#include <stable/soc/interconnect/ipct/nrfx_interconnect_apb_haltium_global.h>
#include <stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_global.h>

#if defined(NRF_RADIOCORE)
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_apb_haltium_radiocore.h>
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_radiocore.h>
#elif defined(NRF_APPLICATION)
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_apb_haltium_application.h>
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_application.h>
#elif defined(NRF_PPR)
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_apb_haltium_ppr.h>
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_ppr.h>
#elif defined(NRF_FLPR)
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_apb_haltium_flpr.h>
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_flpr.h>
#else
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_apb_haltium_ext.h>
    #include <stable/soc/interconnect/ipct/nrfx_interconnect_ipct_haltium_ext.h>
#endif



#endif // NRFX_INTERCONNECT_IPCT_H__
