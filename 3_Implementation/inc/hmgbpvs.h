/**
 * @file hmgbpvs.h
 * @author Deepak
 * @brief All the Header file required 
 * @version 0.1
 * @date 2021-07-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __HMGBPVS_H__
#define __HMGBPVS_H__

#include<stdio.h>
# include <stdlib.h>
//# include <stdbool.h>
//# include <stdio_ext.h> //not supported by the vcode command line
//# include <time.h>
//# include <conio.h> //not supported by the linux command line
#include<unistd.h>
//# include <dos.h> //not supported by the linux command line

int main(void);
int power(float,float); 
int islanded_m1(float,float,int);
int islanded_m2(float,float,int);
int islanded_m3(float,float,int);
int grid_mode(float,int);

#endif /* #define __HMGBPVS_H__ */