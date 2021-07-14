/**
 * @file main.c
 * @author Deepak
 * @brief To start the process and take input from user.
 * @version 0.1
 * @date 2021-07-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */


 #include"hmgbpvs.h"

/**
 * @brief To start with Welcome meassage. 
 * 
 */

int main(void)
{
 
 printf("\n**************************************************************");
 printf("\n                  * ((Welcome Dear User)) *                   ");
 printf("\n**************************************************************");
 printf("\n \n");
 printf("\n       HYBRID MICROGRID WITH BATTERY SUPPORTED PV SYSTEM       ");
 printf("\n \n");
 sleep(2);

 //To take PV solar input.
 
 printf("\nPlease provide PV Solar input.");
 
 printf("\nRated power of pv is 2Kw for this system.");
 printf("\nVoltage must be between 0-100 volte.\n");
        
 //voltage input
 float pv_voltage;
 printf("\nProvide PV Solar voltage : ");
 scanf("%f",&pv_voltage);

 // current input
 printf("\nCurrent must be between 0-20 Ampere\n");
 float pv_current;
 printf("\nProvide PV Solar current : ");
 scanf("%f",&pv_current);

 float pv_power;
 pv_power= power(pv_voltage , pv_current);
 printf("\nPower delivered by pv is %0.2f\n",pv_power);
    
 // To take battery input
 printf("\nPlease provide Battery input\n");

 //voltage input
 printf("Rated battery voltage is 100 volte. voltage must be below 100\n");

 float bat_voltage;
 printf("\nProvide Battery voltage : ");
 scanf("%f",&bat_voltage);

 //current input
 printf("Rated batter current is 20 Ah.\nCurrent must be below 20 Ampere\n");

 float bat_current;
 printf("\nProvide Battery current : ");
 scanf("%f",&bat_current);

 float bat_power;
 bat_power = power(bat_voltage , bat_current);
 printf("\nBattery power is %.2f",bat_power);
         

 // we know normal load demand and maximum load demand of house
 int load_demand_normal = 1000;  // in watt (1 Kw)
 int load_demand_max = 2000;  // in watt (2 Kw)

 printf("\nPlease select your load demand from normal and max load\n");

 /**
  * @brief to check which load is operating.
  * 
  */

 int load_condition;
 printf("\nEnter 1 if system operating at normal load condition.");
 printf("\nEnter 2 if system operating at maximum load condition.\n");
 scanf("%d",&load_condition);


 if(load_condition == 1) 
   { 
    /**
     * @brief function to determine which mode is going to operate
     * 
     */
    // islanded mode condition

      if(pv_power >= load_demand_normal)
      {
       // during day time
       islanded_m1(pv_power,bat_power,load_demand_normal);

      }
      else if((pv_power < 100) && (bat_power>= load_demand_normal))
      {
       // During cloudy or night times
       //pv power will be neglgible

       islanded_m2(pv_power,bat_power,load_demand_normal);

      }

      if((pv_power==0) && (bat_power<400))   //grid connected mode
      {
       //at night irradiance is 0. so pv power = 0
       //battery is also discharge(i.e. SOC is <20)(10 percentage soc = 200 watt)

       printf("Please give grid power :");
       float power_g;
       scanf("%f",&power_g);

       bat_power +=   grid_mode(power_g,load_demand_normal);
    
         if(bat_power>1800 && bat_power <=2000 )
         {
          printf("Battery is fully charged. \n");
          return 0;
         }
         else
         {
          printf("\nBattery is Charging....");
          sleep(3);
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

             if((bat_power>= load_demand_normal))
             {
             // During cloudy or night times
             //pv power will be neglgible

             islanded_m2(pv_power,bat_power,load_demand_normal);

            }
         }
      }
   }
   else if(load_condition == 2)
   {
      if((pv_power < load_demand_max) && (bat_power < load_demand_max))
      {    
       // if Both pv and battery not able to fullfill load demand alone 
       //Load demand Between 4 pm and 6 pm

       islanded_m3(pv_power,bat_power,load_demand_max);

      }

      if((pv_power==0) && (bat_power<400))   //grid connected mode
      {
          //at night irradiance is 0. so pv power = 0
          //battery is also discharge(i.e. SOC is <20)(10 percentage soc = 200 watt)
     
          printf("Please give grid power :");
          float power_g;
          scanf("%f",&power_g);

          bat_power +=   grid_mode(power_g,load_demand_max);
    
         if(bat_power>1800 && bat_power <=2000 )
         {
          printf("Battery is fully charged. \n");
          return 0;
         }
         else
         {
          printf("\nBattery is Charging....");
          sleep(3);
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
         
         if((bat_power>= load_demand_normal))
             {
             // During cloudy or night times
             //pv power will be neglgible

             islanded_m2(pv_power,bat_power,load_demand_normal);

            }
      }
   }
 return 0;
};