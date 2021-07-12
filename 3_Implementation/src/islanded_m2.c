/**
 * @file islanded_m2.c
 * @author Deepak
 * @brief Islanded mode 2 operation
 * @version 0.1
 * @date 2021-07-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"hmgbpvs.h"

// In this mode of operation Battery power > Normal load demand.
// So, the full load deaman will be fulfilled by battery.

int islanded_m2(float pv_power,float bat_power, int load_demand_normal)
{
    printf("PV power is :  %.2f\n",pv_power);
    printf("Battery power is :  %.2f\n",bat_power);
    printf("Dear user according to your input, currently Islanded mode 2 is operating.\n");
    printf("\n \n");
    printf("Battery is discharging...\n");

    bat_power-=load_demand_normal;

    printf("Remaning battery power is : %0.2f\n",bat_power);

    printf("\nBattery is discharged. Not able to fullfill load demand.");
  
    /**
    * @brief logic to call other function if battery is discharge.
    * 
    */

    if( (bat_power < load_demand_normal) && (pv_power >= load_demand_normal))
    {
       islanded_m1(pv_power,bat_power,load_demand_normal);
    }
    
 return bat_power;
}
