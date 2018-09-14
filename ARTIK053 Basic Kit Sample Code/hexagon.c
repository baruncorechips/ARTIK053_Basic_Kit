/****************************************************************************
*
* Copyright 2018 baruncorechips All Rights Reserved.
*
* Filename: hexagon.c
* Author: sj.yang
* Release date: 2018/08/20
* Version: 1.1
*
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "A053BasicKit.h"

// Hexagon GPIO Pin number
#define PIN_D2 46
#define PIN_D4 47
#define PIN_D7 48
#define PIN_D8 50

// Hexagon ADC Pin number
#define A0 0
#define A1 1
#define A2 2
#define A3 3

// Hexagon PWM Pin number
#define PWM0 0
#define PWM1 1
#define PWM2 2
#define PWM4 4

// octave_chord period[us] // frequency[hz]
#define O5_DO 1911 // 523.251[hz]
#define O5_RE 1703 // 587.330[hz]
#define O5_MI 1517 // 659.254[hz]
#define O5_FA 1432 // 698.456[hz]
#define O5_SO 1276 // 783.990[hz]
#define O5_LA 1136 // 880.000[hz]
#define O5_TI 1012 // 987.766[hz]

#define O6_DO 956 // 1046.502[hz]
#define O6_RE 851 // 1174.659[hz]
#define O6_MI 758 // 1318.510[hz]
#define O6_FA 716 // 1396.913[hz]
#define O6_SO 638 // 1567.982[hz]
#define O6_LA 568 // 1760.000[hz]
#define O6_TI 506 // 1975.533[hz]


//static void show_help_usage_hexagon(FAR char *argv[])
//{
//	printf("|---------------------------------------------------------|\n");
//	printf("| %s basic : Sample programs of ARTIK053 Basic Kit   |\n", argv[0]);
//	printf("| %s app : Application programs of ARTIK053 Basic Kit|\n", argv[0]);
//	printf("|---------------------------------------------------------|\n");
//}

//static void show_help_basic_hexagon(FAR char *argv[])
static void show_help_usage_hexagon(FAR char *argv[])
{
	printf("|--------------------------------------------|\n");
	printf("| *** ARTIK053 BASIC KIT SAPMLE PROGRAMS *** |\n");
	printf("| %s led     | gpio[#]  | [#]TURNS |    |\n", argv[0]);
	printf("| %s switch  | gpio[#]  | [#]TURNS |    |\n", argv[0]);
	printf("| %s light   |  adc[#]  | [#]TURNS |    |\n", argv[0]);
	printf("| %s ir      |  adc[#]  | [#]TURNS |    |\n", argv[0]);
	printf("| %s temp    |  adc[#]  | [#]TURNS |    |\n", argv[0]);
	printf("| %s buzzer  |  pwm[#]  | [#]TURNS |    |\n", argv[0]);
	printf("| %s pwmled  |  pwm[#]  | [#]TURNS |    |\n", argv[0]);
	printf("|--------------------------------------------|\n");
	printf("| GPIO[0] (D2, D4),     GPIO[1](D7, D8)      |\n");
	printf("|  ADC[0] (A0, A1),      ADC[1](A2, A3)      |\n");
	printf("|  PWM[0] (PWM0, PWM1),  PWM[1](PWM2, PWM4)  |\n");
	printf("|--------------------------------------------|\n");
}

int hexagon_main(int argc, FAR char *argv[])
{
	if ( (argc==4) && (strcmp(argv[1],"led")==0) ) {hexagon_led_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"switch")==0) ) {hexagon_switch_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"light")==0) ) {hexagon_light_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"ir")==0) ) {hexagon_ir_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"temp")==0) ) {hexagon_temp_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"buzzer")==0) ) {hexagon_buzzer_main(argc,argv);}
	else if ( (argc==4) && (strcmp(argv[1],"pwmled")==0) ) {hexagon_pwmled_main(argc,argv);}

	else if ( (argc==2) && (strcmp(argv[1],"ledsw")==0) ) {hexagon_ledsw_main(argc,argv);}
	else if ( (argc==2) && (strcmp(argv[1],"toggle")==0) ) {hexagon_toggle_main(argc,argv);}
	else if ( (argc==2) && (strcmp(argv[1],"dimming")==0) ) {hexagon_dimming_main(argc,argv);}
	else if ( (argc==2) && (strcmp(argv[1],"autotemp")==0) ) {hexagon_autotemp_main(argc,argv);}

	else if ( (argc==2) && (strcmp(argv[1],"help")==0) ) {show_help_usage_hexagon(argv);}

	else show_help_usage_hexagon(argv);

	return 0;
}


int hexagon_led_main(int argc, FAR char *argv[])
{
	int i= 0;
	int pin_red = 0;
	int pin_gre= 0;
	int max = 0;
	char *gpio0 = "0";
	char *gpio1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], gpio0)==0 )
	{
		pin_red = PIN_D2;
		pin_gre = PIN_D4;
	}
	else if (strcmp(argv[2], gpio1)==0 )
	{
		pin_red = PIN_D7;
		pin_gre = PIN_D8;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}


	printf("*********** HEXAGON LED BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		printf("|--- (%2d/%d) LEDs blink \n",(i+1),max);
		gpio_write(pin_red,HIGH); // RED LED ON
		gpio_write(pin_gre,HIGH); // GREEN LED ON
		up_mdelay(500);

		gpio_write(pin_red,LOW); // RED LED OFF
		gpio_write(pin_gre,LOW); // GREEN LED OFF
		up_mdelay(500);
	}

	gpio_write(pin_red,LOW); // RED LED OFF
	gpio_write(pin_gre,LOW); // GREEN LED OFF

	printf("************ HEXAGON LED BOARD TEST END ************\n");

	return 0;
}

int hexagon_switch_main(int argc, FAR char *argv[])
{
	int i= 0;
	int pin_sw1 = 0;
	int pin_sw2 = 0;
	int val1=0;
	int val2=0;
	int max = 0;
	char *gpio0 = "0";
	char *gpio1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], gpio0) == 0 )
	{
		pin_sw1 = PIN_D2;
		pin_sw2 = PIN_D4;
	}
	else if (strcmp(argv[2], gpio1)==0 )
	{
		pin_sw1 = PIN_D7;
		pin_sw2 = PIN_D8;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}

	printf("*********** HEXAGON SWITCH BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		val1 = gpio_read(pin_sw1);
		val2 = gpio_read(pin_sw2);

		if(val1==1) { printf("|--- (%2d/%d) SW1(%d)    connected, ",i+1,max,val1 );}
		else  { printf("|--- (%2d/%d) SW1(%d) disconnected, ",i+1,max,val1);}

		if(val2==1) { printf("SW2(%d)    connected\n",val2);}
		else { printf("SW2(%d) disconnected\n",val2);}
		up_mdelay(1000);
	}

	printf("************ HEXAGON SWITCH BOARD TEST END ************\n");

	return 0;
}

int hexagon_light_main(int argc, FAR char *argv[])
{
	int32_t val;
	int i;
	int pin_cds;
	int max = 0;
	char *adc0 = "0";
	char *adc1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], adc0)==0 )
	{
		pin_cds = A0;
	}
	else if (strcmp(argv[2], adc1)==0 )
	{
		pin_cds = A2;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}

	printf("*********** HEXAGON LIGHT BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		val = read_adc(pin_cds);
		printf("|--- (%2d/%d) Light Sensor value(ADC %d):%d\n", i+1, max, pin_cds, val);
		up_mdelay(1000);
	}

	printf("************ HEXAGON LIGHT BOARD TEST END ************\n");

	return 0;
}

int hexagon_ir_main(int argc, FAR char *argv[])
{
	int32_t val;
	int i;
	int pin_ir;
	int max = 0;
	char *adc0 = "0";
	char *adc1 = "1";

	max = atoi(argv[3]);

	if (strcmp(argv[2], adc0)==0 )
	{
		pin_ir = A0;
	}
	else if (strcmp(argv[2], adc1)==0 )
	{
		pin_ir = A2;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}

	printf("*********** HEXAGON IR SENSOR BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		val = read_adc(pin_ir);
		printf("|--- (%2d/%d) IR Sensor Value(ADC %d):%d\n", i+1, max, pin_ir, val);
		up_mdelay(1000);
	}

	printf("************ HEXAGON IR SENSOR BOARD TEST END ************\n");

	return 0;
}

int hexagon_temp_main(int argc, FAR char *argv[])
{
	int32_t val;
	int i;
	int pin_temp;
	int max = 0;
	char *adc0 = "0";
	char *adc1 = "1";
	int temp = 0;

	max = atoi(argv[3]);

	if (strcmp(argv[2], adc0)==0 )
	{
		pin_temp = A0;
	}
	else if (strcmp(argv[2], adc1)==0 )
	{
		pin_temp = A2;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}

	printf("*********** HEXAGON TEMPERATURE SENSOR BOARD TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		val = read_adc(pin_temp);
		temp = val*330/4096-50;
		printf("|--- (%2d/%d) Temperature Sensor Value(ADC %d):%d\n", i+1, max, pin_temp, temp);
		up_mdelay(1000);
	}

	printf("************ HEXAGON TEMPERATURE SENSOR BOARD TEST END ************\n");

	return 0;
}

int hexagon_buzzer_main(int argc, FAR char *argv[])
{
	int i;
	int fd;
	int pin_buzzer;
	int max = 0;
	char *pwm0 = "0";
	char *pwm1 = "1";
	int dutycycle=100;

	max = atoi(argv[3]);

	if (strcmp(argv[2], pwm0)==0 )
	{
		pin_buzzer = PWM0;
	}
	else if (strcmp(argv[2], pwm1)==0 )
	{
		pin_buzzer = PWM2;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}

	printf("*********** HEXAGON BUZZER BOARD TEST START ***********\n");
	fd = pwm_open(pin_buzzer);

	for(i=0 ; i<max ; i++)
	{
		printf("|--- (%2d/%d) Do Re Mi Fa So La Ti Do ~ \n", i+1, max);
		pwm_write(fd, O5_DO, dutycycle); up_mdelay(300);

		pwm_write(fd, O5_RE, dutycycle); up_mdelay(300);

		pwm_write(fd, O5_MI, dutycycle); up_mdelay(300);

		pwm_write(fd, O5_FA, dutycycle); up_mdelay(300);

		pwm_write(fd, O5_SO, dutycycle); up_mdelay(300);

		pwm_write(fd, O5_LA, dutycycle); up_mdelay(300);

		pwm_write(fd, O5_TI, dutycycle); up_mdelay(300);

		pwm_write(fd, O6_DO, dutycycle); up_mdelay(300);
	}
	printf("************ HEXAGON BUZZER BOARD TEST END ************\n");
	pwm_write(fd, O5_DO, 0);
	pwm_close(fd);

	return 0;
}

int hexagon_pwmled_main(int argc, FAR char *argv[])
{
	int i,j;
	int fd_red, fd_gre;
	int pin_red = 0;
	int pin_gre = 0;
	int max = 0;
	char *pwm0 = "0";
	char *pwm1 = "1";
	int PERIOD=1000;

	max = atoi(argv[3]);

	if (strcmp(argv[2], pwm0)==0 )
	{
		pin_red = PWM0;
		pin_gre = PWM1;
	}
	else if (strcmp(argv[2], pwm1)==0 )
	{
		pin_red = PWM2;
		pin_gre = PWM4;
	}
	else
	{
		show_help_usage_hexagon(argv);
	}

	fd_red = pwm_open(pin_red);
	fd_gre = pwm_open(pin_gre);

	printf("*********** HEXAGON LED PWM TEST START ***********\n");

	for(i=0 ; i<max ; i++)
	{
		printf("|--- Light Control (%2d/%d)\n", i+1, max);
		for (j=0 ; j<PERIOD ; j=j+20)
		{
			pwm_write(fd_red, PERIOD, j);
			pwm_write(fd_gre, PERIOD, j);
			up_mdelay(50);
		}
		for (j=980 ; j>0 ; j=j-20)
		{
			pwm_write(fd_red, PERIOD, j);
			pwm_write(fd_gre, PERIOD, j);
			up_mdelay(50);
		}
	}

	printf("************ HEXAGON LED PWM TEST END ************\n");
	pwm_write(fd_red, PERIOD, 0);
	pwm_write(fd_gre, PERIOD, 0);
	pwm_close(fd_red);
	pwm_close(fd_gre);

	return 0;
}

int hexagon_ledsw_main(int argc, FAR char *argv[])
{
	// Switch board -> GPIO 0 port, LED board -> GPIO 1 port
	int i= 0;
	int pin_sw1 = 0;
	int pin_sw2 = 0;
	int pin_red = 0;
	int pin_gre = 0;

	pin_sw1 = PIN_D2;
	pin_sw2 = PIN_D4;
	pin_red = PIN_D7;
	pin_gre = PIN_D8;

	printf("*********** HEXAGON LED-SW PROGRAM START ***********\n");

	while(1)
	{
		gpio_write(pin_red, gpio_read(pin_sw1));
		gpio_write(pin_gre, gpio_read(pin_sw2));

		if(gpio_read(pin_sw1)==1 && gpio_read(pin_sw2) == 1)
		{
			gpio_write(pin_red, LOW);
			gpio_write(pin_gre, LOW);
			break;
		}
	}

	printf("************ HEXAGON LED-SW PROGRAM END ************\n");

	return 0;
}

int hexagon_toggle_main(int argc, FAR char *argv[])
{
	// Switch board -> GPIO 0 port, LED board -> GPIO 1 port
	int i= 0;
	int pin_sw1 = 0;
	int pin_sw2 = 0;
	int pin_red = 0;
	int state = 0; // state 0 : red led Off, state 1 : red led On
	int val = 0;

	pin_sw1 = PIN_D2;
	pin_sw2 = PIN_D4;
	pin_red = PIN_D7;

	printf("*********** HEXAGON LED-SW PROGRAM START ***********\n");

	while(1)
	{
		val = gpio_read(pin_sw1);
		up_mdelay(100);

		if (state==0)
		{
			if(val == 1)
			{
				gpio_write(pin_red, HIGH);
				state = 1;
				printf("|--- RED LED ON\n");
			}
			else gpio_write(pin_red, LOW);
		}


		else if (state==1)
		{
			if(val == 1)
			{
				gpio_write(pin_red, LOW);
				state = 0;
				printf("|--- RED LED OFF\n");
			}
			else gpio_write(pin_red, HIGH);
		}


		if(gpio_read(pin_sw2) == 1)
		{
			gpio_write(pin_red, LOW);
			break;
		}
	}

	printf("************ HEXAGON LED-SW PROGRAM END ************\n");

	return 0;
}

int hexagon_dimming_main(int argc, FAR char *argv[])
{
	// Switch board -> GPIO 0 port, LED board -> PWM 0 port
	int pin_sw1 = 0;
	int pin_sw2 = 0;
	int pin_red = 0;
	int fd_red;
	int val1 = 0;
	int val2 = 0;
	int PERIOD = 1000;
	int DUTY_CYCLE = 0;

	pin_sw1 = PIN_D2;
	pin_sw2 = PIN_D4;
	pin_red = PWM0;

	printf("*********** HEXAGON LED DIMMING PROGRAM START ***********\n");

	fd_red = pwm_open(pin_red);
	while(1)
	{
		val1 = gpio_read(pin_sw1);
		val2 = gpio_read(pin_sw2);
		up_mdelay(100);

		if (val1 == 1)
		{
			DUTY_CYCLE = DUTY_CYCLE + 50;
			if(DUTY_CYCLE >= PERIOD) {DUTY_CYCLE = PERIOD;}
			printf("|--- Duty Cycle : %d/%d \n",DUTY_CYCLE, PERIOD);
		}
		else {}
		if (val2 == 1)
		{
			DUTY_CYCLE = DUTY_CYCLE - 50;
			if ( DUTY_CYCLE <= 0 ) {DUTY_CYCLE = 0;}
			printf("|--- Duty Cycle : %d/%d \n",DUTY_CYCLE, PERIOD);
		}
		else {}

		pwm_write(fd_red, PERIOD, DUTY_CYCLE-1);

		if(val1 == 1 && val2 == 1)
		{
			pwm_write(fd_red, PERIOD, 0);
			break;
		}
	}
	pwm_close(pin_red);

	printf("************ HEXAGON LED DIMMING PROGRAM END ************\n");

	return 0;
}

int hexagon_autotemp_main(int argc, FAR char *argv[])
{
	// Temperature board -> ADC 0 port, LED board -> GPIO 0 port
	// Switch board -> GPIO 1 port, for stop
	int pin_red = 0;
	int pin_gre = 0;
	int pin_sw1 = 0;
	int pin_temp = 0;
	int temperature = 0;

	pin_temp = A0;
	pin_red = PIN_D2;
	pin_gre = PIN_D4;
	pin_sw1 = PIN_D7;

	printf("**** HEXAGON AUTO TEMPERATURE CONTROL PROGRAM START ****\n");

	while(1)
	{
		temperature = read_adc(pin_temp)*330/4096-50;
		up_mdelay(500);

		if(temperature > 27)
		{
			gpio_write(pin_red,HIGH);
			gpio_write(pin_gre,LOW);
			printf("|--- Temp. : %d, red LED ON\n",temperature);
		}
		else
		{
			gpio_write(pin_red,LOW);
			gpio_write(pin_gre,HIGH);
			printf("|--- Temp. : %d, green LED ON\n",temperature);
		}

		if(gpio_read(pin_sw1)==1)
		{
			gpio_write(pin_red,LOW);
			gpio_write(pin_gre,LOW);
			break;
		}
	}

	printf("***** HEXAGON AUTO TEMPERATURE CONTROL PROGRAM END *****\n");

	return 0;
}

