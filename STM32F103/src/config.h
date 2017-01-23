/*
 * Copyright (C) 2014-2015 Joerg Riechardt
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* MACRO_SLOTS x (MACRO_DEPTH + 1) + WAKE_SLOTS < 85
 * Eeprom page size = 1kB - 4, 255 pairs of 16bit variable + address,
 * IRdata needs 3 variables, 255 / 3 = 85
 */
#define MACRO_SLOTS	8
#define MACRO_DEPTH	8
#define WAKE_SLOTS	8
#define SIZEOF_IR	6

/* uncomment this for CooCox */
//#define FW_STR "2015-10-26_00-00_Blue_SC_BL_jrie"

#define MIN_REPEATS	2  // TODO make configurable & use Eeprom

/* uncomment this, if you use the blue ST-Link */
//#define BlueLink

/* uncomment this, if you use the red ST-Link */
//#define RedLink

/* uncomment this in order to pull down the "active" pin of the mainboard power button connector directly */
//#define SimpleCircuit

#if defined(BlueLink) || defined(RedLink)
	#define ST_Link
#endif

/* B11 IRMP (irmpconfig.h), B6 IRSND (irsndconfig.h) , B10 Logging (irmp.c) */

#ifdef STM32F103C8T6 /* STM32F103C8T6 developer board */
	#define OUT_PORT	     GPIOB
	#define LED_PORT 	     GPIOC
	#define LED_PIN		     GPIO_Pin_13
	#define IR_IN_PORT	     B
	#define IR_IN_PIN	     9
	#define WAKEUP_PIN	     GPIO_Pin_14
	#define RESET_PORT	     GPIOB
	#define WAKEUP_RESET_PIN GPIO_Pin_12
	#define USB_DISC_PORT    GPIOB
	#define USB_DISC_PIN     GPIO_Pin_15
	#define USB_DISC_RCC_APB2Periph RCC_APB2Periph_GPIOB /* TODO use concat */
#elif BlueLink /* blue ST-Link */
	#define OUT_PORT	     GPIOA
	#define LED_PORT	     GPIOA
	#define LED_PIN		     GPIO_Pin_14
	#define IR_IN_PORT       B
	#define IR_IN_PIN        11
	#define WAKEUP_PIN	     GPIO_Pin_13
	#define RESET_PORT	     GPIOB
	#define WAKEUP_RESET_PIN GPIO_Pin_14
	#define USB_DISC_PORT    GPIOB
	#define USB_DISC_PIN     GPIO_Pin_13
	#define USB_DISC_RCC_APB2Periph RCC_APB2Periph_GPIOB /* TODO use concat */
#elif RedLink /* red ST-Link */
	#define OUT_PORT	     GPIOB
	#define LED_PORT	     GPIOB
	#define LED_PIN		     GPIO_Pin_13
	#define IR_IN_PORT	     B
	#define IR_IN_PIN	     11
	#define WAKEUP_PIN	     GPIO_Pin_14
	#define RESET_PORT	     GPIOA
	#define WAKEUP_RESET_PIN GPIO_Pin_14
	#define USB_DISC_PORT    GPIOA
	#define USB_DISC_PIN     GPIO_Pin_13
	#define USB_DISC_RCC_APB2Periph RCC_APB2Periph_GPIOA /* TODO use concat */
#else /* developer board */
	#define OUT_PORT	     GPIOB
	#define LED_PORT	     GPIOB
	#define LED_PIN		     GPIO_Pin_13
	#define IR_IN_PORT	     B
	#define IR_IN_PIN	     11
	#define WAKEUP_PIN	     GPIO_Pin_14
	#define RESET_PORT	     GPIOB
	#define WAKEUP_RESET_PIN GPIO_Pin_12
	#define USB_DISC_PORT    GPIOB
	#define USB_DISC_PIN     GPIO_Pin_15
	#define USB_DISC_RCC_APB2Periph RCC_APB2Periph_GPIOB /* TODO use concat */
#endif
#endif /* __CONFIG_H */
