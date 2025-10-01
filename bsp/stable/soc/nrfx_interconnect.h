/*$$$LICENCE_NORDIC_STANDARD<2025>$$$*/

#ifndef NRFX_INTERCONNECT_H__
#define NRFX_INTERCONNECT_H__

#if defined(DPPI_TYPE_PPIB)
#include "stable/soc/interconnect/ppib/nrfx_interconnect_ppib.h"
#elif defined(DPPI_TYPE_IPCT)
#include "stable/soc/interconnect/ipct/nrfx_interconnect_ipct.h"
#endif

#endif // NRFX_INTERCONNECT_H__
