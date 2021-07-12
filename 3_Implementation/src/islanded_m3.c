/**
 * @file islanded_m2.c
 * @author Deepak
 * @brief Islanded mode 3 operation.
 * @version 0.1
 * @date 2021-07-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"hmgbpvs.h"

//In this mode of operation both pv power and battery power is less than load deamand.
// So, both pv and battery together fullfill load demand.

int islanded_m3(float pv_power,float bat_power, int load_demand_max)
{
   printf("PV power is :  %.2f\n",pv_power);
   printf("Battery power is :  %.2f\n",bat_power);
 
   int total_power = pv_power + bat_power;

   if(total_power >= load_demand_max)
   {
       printf("Dear user according to your input, currently Islanded mode 3 is operating.\n");
       printf("\nTotal power produced by pv and battery is : %d\n ",total_power);
    }
  
 return total_power;
}