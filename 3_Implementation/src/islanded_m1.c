/**
 * @file islanded_m1.c
 * @author Deepak
 * @brief Islanded Mode 1 implementation
 * @version 0.1
 * @date 2021-07-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include"hmgbpvs.h"

// In this mode of operation PV power > Normal load demand.
// So, the remaning power will help to charge the battery.

int islanded_m1(float pv_power,float bat_power, int load_demand_normal)
    {

     printf("PV power is :  %.2f\n",pv_power);
     printf("Battery power is :  %.2f\n",bat_power);
     printf("Dear user according to your input, currently Islanded mode 1 is operating.\n");
     float power_extra;     // to sotore extra power

     power_extra = pv_power - load_demand_normal;

     if(bat_power>1800 && bat_power <=2000 )
        {
             printf("Battery is fully charged. \n");
             return 0;
        }
        else
        {
             printf("\nBattery is Charging....");
             sleep(3);
             bat_power += power_extra;
             /**
              * @brief function to protect overcharge of battery.
              * 
              */
             if(bat_power >= 2000)
                {
    
                 float power_remove;
                 power_remove= bat_power - 2000;
                 bat_power -= power_remove;
                 printf("\nBattery Power is : %0.2f",bat_power);
                 printf("\n Your battery is fully charged.");
                }
             else
              printf("\nBattery Power is : %0.2f\n",bat_power);
        }

     return bat_power;
    }