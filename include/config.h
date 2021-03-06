/****************************************************************************
 * Copyright (C) 2019 by Anna Sopdia Schröck                                *
 *                                                                          *
 * This file is part of ess.                                                *
 *                                                                          *
 *   ess is free software: you can redistribute it and/or modify it         *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   ess is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

/**
 * @file config.h
 * @author Anna Sopdia Schröck
 * @date 30 Januar 20119
 * @brief File containing configurations
 *
 */

#ifndef __ESS_CONFIG_H__
#define __ESS_CONFIG_H__



#define ESS_PROTOCOL_UDP							1
#define ESS_PROTOCOL_TCP							2
#define ESS_PROTOCOL_UDP_LITE		3

#define ESS_FAMILY_IP4											4
#define ESS_FAMILY_IP6											6
#define ESS_FAMILY_BOTH 							46

/* Main config */

#define ESS_PLATFORM_ESP32	/** @brief If defined compiled backend for esp32 */
//#define ESS_PLATFORM_RPI 			/** @brief If defined compiled backend for Raspberry PI (linux) */
//#define ESS_PLATFORM_LINUX /** @brief If defined compiled backend for generic linux (openal) */
//#define ESS_PLATFORM_WINDOWS /** @brief If defined compiled backend for  generic windows (openal, wasapi) */

#define ESS_DEFAULT_SERVER_PORT 16001
#define ESS_DEFAULT_SERVER_PROTOCOL ESS_PROTOCOL_TCP
#define ESS_DEFAULT_SERVER_FAMILY ESS_FAMILY_BOTH


#ifdef ESS_PLATFORM_ESP32
	#define ESS_CONFIG_SEMAPHORE_ESP32
	//#define ESS_CONFIG_SEMAPHORE_GENERIC
	#define ESS_CONFIC_TASK_ESP32
	//#define ESS_CONFIC_TASK_GENERIC
	#define ESS_CONFIG_RINGBUFFER_ESP32
	/** @brief If defined then UART backend available */
	#define ESS_ENABLE_BACKEND_UART
	/** @brief If defined then I2S backend available */
	#define ESS_ENABLE_BACKEND_I2S
	/** @brief If defined then UDP backend available */
	#define ESS_ENABLE_BACKEND_UDP

	#define ESS_DEFAULT_SERVER_NAME "OpenEssD-esp32"
#endif // ESS_PLATFORM_ESP32

#ifdef ESS_PLATFORM_RPI
	#define ESS_CONFIG_SEMAPHORE_GENERIC
	#define ESS_CONFIC_TASK_GENERIC
	#define ESS_CONFIG_RINGBUFFER_GENERIC
	/** @brief If defined then OpenAL backend available */
	#define ESS_ENABLE_BACKEND_OPENAL
	/** @brief If defined then UDP backend available */
	#define ESS_ENABLE_BACKEND_UDP
	#define ESS_DEFAULT_SERVER_NAME "OpenEssD-rpi"
#endif //ESS_PLATFORM_RPI

#ifdef ESS_PLATFORM_LINUX
	#define ESS_CONFIG_SEMAPHORE_GENERIC
	#define ESS_CONFIC_TASK_GENERIC
	#define ESS_CONFIG_RINGBUFFER_GENERIC
	#define ESS_CONFIG_RINGBUFFER_GENERIC
	/** @brief If defined then OpenAL backend available */
	#define ESS_ENABLE_BACKEND_OPENAL
	/** @brief If defined then Pulseaudio backend available */
	#define ESS_ENABLE_BACKEND_PULSEAUDIO
	/** @brief If defined then ALSA backend available */
	#define ESS_ENABLE_BACKEND_ALSA
	/** @brief If defined then UDP backend available */
	#define ESS_ENABLE_BACKEND_UDP
	#define ESS_DEFAULT_SERVER_NAME "OpenEssD-linux"
#endif //ESS_PLATFORM_LINUX

#ifdef ESS_PLATFORM_WINDOWS
	#define ESS_CONFIG_SEMAPHORE_WINDOWS
	#define ESS_CONFIC_TASK_WINDOWS
	#define ESS_CONFIG_RINGBUFFER_WINDOWS
	#define ESS_CONFIG_RINGBUFFER_WINDOWS
	/** @brief If defined then OpenAL backend available */
	#define ESS_ENABLE_BACKEND_OPENAL
	/** @brief If defined then OpenAL backend available */
	#define ESS_ENABLE_BACKEND_WASAPI
	/** @brief If defined then UDP backend available */
	#define ESS_ENABLE_BACKEND_UDP
	#define ESS_DEFAULT_SERVER_NAME "OpenEssD-windows"
#endif //ESS_PLATFORM_WINDOWS


//-------------------------------------------------------------------------------------------------------

#ifdef ESS_ENABLE_BACKEND_UART
	#define ESS_BACKEND_UART_BAUDRAT 115200
	#define ESS_BACKEND_UART_TXD  (GPIO_NUM_4)
	#define ESS_BACKEND_UART_RXD  (GPIO_NUM_5)
	#define ESS_BACKEND_UART_RTS  (UART_PIN_NO_CHANGE)
	#define ESS_BACKEND_UART_CTS  (UART_PIN_NO_CHANGE)
#endif

#ifdef ESS_ENABLE_BACKEND_UDP
	#define ESS_BACKEND_UDP_PORT 17000
	#define ESS_BACKEND_UDP_FAMILY ESS_FAMILY_BOTH
#endif

#ifdef ESS_ENABLE_BACKEND_I2S
	#define I2S_EXTERNAL_DAC_BCK 26
	#define I2S_EXTERNAL_DAC_LRCLK 25
	#define I2S_EXTERNAL_DAC_DOUT 22
	#define  I2S_EXTERNAL_DAC_DIN   -1                                                    //Not used

  #define ESS_BACKEND_I2S_FORMAT ESS_FORMAT_STEREO_96000_16
	#define ESS_BACKEND_I2S_DMA_BUF_SIZE	64
	#define ESS_BACKEND_I2S_DMA_BUF_COUNT 6
#endif

#endif
