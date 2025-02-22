/**
 *    __  __ ____ _  __ ____ ___ __  __
 * 	  \ \/ // __// |/ //  _// _ |\ \/ /
 *     \  // _/ /    /_/ / / __ | \  /
 *     /_//___//_/|_//___//_/ |_| /_/
 *
 *      Yeniay Northstar RF Firmware
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

#include <system.h>
#include <systime.h>
#include <sysconfig.h>
#include "spi.h"
#include "led.h"
#include "RF24.h"

#define RF24_RX_ADDRESS		{0xE7,0xE7,0xE7,0xE3,0x00}
#define RF24_TX_ADDRESS		{0xE7,0xE7,0xE7,0xE3,0x01}

static uint8_t rxaddress[] = RF24_RX_ADDRESS;
static uint8_t txaddress[] = RF24_TX_ADDRESS;

static char buffer [32];

void systemLaunch(void){

// 	usbInit();
	spiInit();

	RF24_Init(&RF24_SPI, RF24_CE_GPIO, RF24_CE, RF24_CS_GPIO, RF24_CS);


	if(!RF24_begin())systemErrorCall();

	RF24_setDataRate(RF24_2MBPS);

	RF24_openWritingPipe(	txaddress); 		/*Always uses Pipe 0*/ /*301*/
	RF24_openReadingPipe(1, rxaddress);					   	           /*300*/

	RF24_startListening();

	ledSet(LED_2, 1);

	while(1){
		if(RF24_available()){
			RF24_read(buffer, 32);
			ledToggle(LED_2);
		}

		delay(100);
	}

}

void systemTask(void){


}

void systemErrorCall(void){

	ledSet(LED_2, 0);
	while(1){
		ledToggle(LED_1);
		delay(1000);
	}
}


