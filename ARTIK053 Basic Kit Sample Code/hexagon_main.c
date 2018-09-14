/****************************************************************************
*
* Copyright 2018 baruncorechips All Rights Reserved.
*
* Filename: hexagon_main.h
* Author: sj.yang
* Release date: 2018/07/06
* Version: 1.0
*
****************************************************************************/

#include <tinyara/config.h>
#include <apps/shell/tash.h>
#include <stdio.h>
#include "hexagon.h"


int main(int argc, FAR char *argv[])
{
	tash_cmd_install("hexagon",hexagon_main,TASH_EXECMD_SYNC);
	return 0;
}


