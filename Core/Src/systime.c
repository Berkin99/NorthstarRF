/**
 *    __  __ ____ _  __ ____ ___ __  __
 * 	  \ \/ // __// |/ //  _// _ |\ \/ /
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

#include <system.h>
#include <sysconfig.h>
#include <systime.h>


#ifndef SYSTIME
#error "/SYSTEM> SYSTIME Timer should be defined !!! How to define->(syscheck md.3)"
#else

uint32_t millis(void){
	return SYSTIME.Instance->CNT/1000;
}

uint32_t micros(void){
	return SYSTIME.Instance->CNT;
}

void delay(uint32_t ms){
	uint32_t dt = millis() + ms;
	while (millis() < dt);
}

void delayMicroseconds(uint32_t us){
	uint32_t dt = micros() + us;
	while (micros() < dt);
}

#endif
