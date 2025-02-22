/**
 *    __  __ ____ _  __ ____ ___ __  __
 *    \ \/ // __// |/ //  _// _ |\ \/ /
 *     \  // _/ /    /_/ / / __ | \  /
 *     /_//___//_/|_//___//_/ |_| /_/
 *
 *         Yeniay System Firmware
 *
 *       Copyright (C) 2024 Yeniay
 *
 * This  program  is  free software:   you
 * can  redistribute it  and/or  modify it
 * under  the  terms of  the  GNU  General
 * Public  License as  published  by   the
 * Free Software Foundation, in version 3.
 *
 * You  should  have  received  a  copy of
 * the  GNU  General  Public License along
 * with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */

/*
 * @return HAL_StatusTypeDef
 * @retval 0 -> HAL_OK
 * @retval 1 -> HAL_ERROR
 * @retval 2 -> HAL_BUSY
 * @retval 3 -> HAL_TIMEOUT
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include "system.h"

void   spiInit(void);
int8_t spiIndex           (SPI_HandleTypeDef* hspi);
void   spiBeginTransaction(SPI_HandleTypeDef* hspi);
void   spiEndTransaction  (SPI_HandleTypeDef* hspi);
int8_t spiReceive         (SPI_HandleTypeDef* hspi, uint8_t* pRxData, uint8_t len);
int8_t spiTransmit        (SPI_HandleTypeDef* hspi, uint8_t* pTxData, uint8_t len);
int8_t spiTransmitReceive (SPI_HandleTypeDef* hspi, uint8_t* pRxData, uint8_t* pTxData, uint8_t len);

#endif /* SPI_H_ */
