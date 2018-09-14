/****************************************************************************
 *
 * Copyright 2018 baruncorechips All Rights Reserved.
 * Filename : A053BasicKit.h
 * Author : Seon-Je Yang
 * Created on: 2018. 8. 30.
 * Version : 1.0
 *
****************************************************************************/

#ifndef A053BASICKIT_H_
#define A053BASICKIT_H_

#include <fcntl.h>
#include <tinyara/gpio.h>	// for GPIO control
#include <tinyara/pwm.h>	// for PWM control
#include <tinyara/analog/adc.h>	// for ADC control
#include <tinyara/analog/ioctl.h>	// for ADC control
#include <errno.h>	// for ADC control

#define	HIGH	1
#define	LOW		0
#define ENABLE	1
#define DISABLE	0
#define S5J_ADC_MAX_CHANNELS	4

//GPIO function
void gpio_write(int port, int value);
int gpio_read(int port);

//PWM function
int pwm_open (int port);
void pwm_write(int fd, int period, int duty_cycle);
void pwm_close (int fd);

//ADC function
int read_adc(int channel);

#endif /* A053BASICKIT_H_ */
