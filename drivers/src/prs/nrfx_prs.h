/*$$$LICENCE_NORDIC_STANDARD<2017>$$$*/

#ifndef NRFX_PRS_H__
#define NRFX_PRS_H__

#include <nrfx_prs_boxes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrfx_prs Peripheral Resource Sharing (PRS)
 * @{
 * @ingroup nrfx
 *
 * @brief Peripheral Resource Sharing interface (PRS).
 */

/**
 * @brief Function for acquiring shared peripheral resources associated with
 *        the specified peripheral.
 *
 * Certain resources and registers are shared among peripherals that have
 * the same ID (for example: SPI0, SPIM0, SPIS0, TWI0, TWIM0, and TWIS0 in
 * nRF52832). Only one of them can be utilized at a given time. This function
 * reserves proper resources to be used by the specified peripheral.
 * If NRFX_PRS_ENABLED is set to a non-zero value, IRQ handlers for peripherals
 * that are sharing resources with others are implemented by the @ref nrfx_prs
 * module instead of individual drivers. The drivers must then specify their
 * interrupt handling routines and register them by using this function.
 *
 * @param[in] p_base_addr Requested peripheral base pointer.
 * @param[in] irq_handler Interrupt handler to register.
 *
 * @retval NRFX_SUCCESS    If resources were acquired successfully or the
 *                         specified peripheral is not handled by the PRS
 *                         subsystem and there is no need to acquire resources
 *                         for it.
 * @retval NRFX_ERROR_BUSY If resources were already acquired.
 */
nrfx_err_t nrfx_prs_acquire(void       const * p_base_addr,
                            nrfx_irq_handler_t irq_handler);

/**
 * @brief Function for acquiring shared peripheral resources associated with
 *        the specified peripheral using instance pointer.
 *
 * Certain resources and registers are shared among peripherals that have
 * the same ID (for example: SPI0, SPIM0, SPIS0, TWI0, TWIM0, and TWIS0 in
 * nRF52832). Only one of them can be utilized at a given time. This function
 * reserves proper resources to be used by the specified peripheral.
 * If NRFX_PRS_ENABLED is set to a non-zero value, IRQ handlers for peripherals
 * that are sharing resources with others are invoked by the @ref nrfx_prs
 * module instead of the user code. The drivers must then specify their
 * interrupt handling routines with instance pointer and register them by using this function.
 *
 * @param[in] p_base_addr Requested peripheral base pointer.
 * @param[in] irq_handler Interrupt handler to register.
 * @param[in] p_instance  Pointer to shared peripheral instance structure used in
 *                        interrupt handling.
 *
 * @retval NRFX_SUCCESS    If resources were acquired successfully or the
 *                         specified peripheral is not handled by the PRS
 *                         subsystem and there is no need to acquire resources
 *                         for it.
 * @retval NRFX_ERROR_BUSY If resources were already acquired.
 */
nrfx_err_t nrfx_new_prs_acquire(void const *           p_base_addr,
                                nrfx_new_irq_handler_t irq_handler,
                                void *                 p_instance);

/**
 * @brief Function for releasing shared resources reserved previously by
 *        @ref nrfx_prs_acquire() for the specified peripheral.
 *
 * @param[in] p_base_addr Released peripheral base pointer.
 */
void nrfx_prs_release(void const * p_base_addr);

/** @} */

/*
 * Declare interrupt handlers for all enabled driver instances in the following format:
 * nrfx_\<periph_name\>_\<idx\>_irq_handler (for example, nrfx_prs_box_0_irq_handler).
 *
 * A specific interrupt handler for the driver instance can be retrieved by using
 * the NRFX_PRS_BOX_INST_HANDLER_GET macro.
 *
 * Here is a sample of using the NRFX_PRS_BOX_INST_HANDLER_GET macro to map an interrupt handler
 * in a Zephyr application:
 *
 * IRQ_CONNECT(NRFX_IRQ_NUMBER_GET(NRF_PRS_BOX_INST_GET(\<instance_index\>)), \<priority\>,
 *                    NRFX_PRS_BOX_INST_HANDLER_GET(\<instance_index\>), 0, 0);
 */
NRFX_INSTANCE_IRQ_HANDLERS_DECLARE(PRS_BOX_, prs_box)

#ifdef __cplusplus
}
#endif

#endif // NRFX_PRS_H__
