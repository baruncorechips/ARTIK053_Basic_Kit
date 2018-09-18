/****************************************************************************
*
* Copyright 2018 baruncorechips All Rights Reserved.
*
* Filename: hexagon.h
* Author: sj.yang
* Release date: 2018/09/18
* Version: 1.2
*
****************************************************************************/

#ifndef HEXAGON_H_
#define HEXAGON_H_

int hexagon_main(int argc, FAR char *argv[]);

static void show_help_usage_hexagon(FAR char *argv[]);
static void show_help_basic_hexagon(FAR char *argv[]);
static void show_help_app_hexagon(FAR char *argv[]);

int hexagon_led_main(int argc, FAR char *argv[]);
int hexagon_switch_main(int argc, FAR char *argv[]);
int hexagon_light_main(int argc, FAR char *argv[]);
int hexagon_ir_main(int argc, FAR char *argv[]);
int hexagon_temp_main(int argc, FAR char *argv[]);
int hexagon_buzzer_main(int argc, FAR char *argv[]);
int hexagon_pwmled_main(int argc, FAR char *argv[]);
int hexagon_servo_main(int argc, FAR char *argv[]);

int hexagon_ledsw_main(int argc, FAR char *argv[]);
int hexagon_toggle_main(int argc, FAR char *argv[]);
int hexagon_dimming_main(int argc, FAR char *argv[]);
int hexagon_autotemp_main(int argc, FAR char *argv[]);

#endif /* HEXAGON_H_ */
