/**
 * @file power_calc.c
 * @author Deepak
 * @brief to calculate power of pv/battery
 * @version 0.1
 * @date 2021-07-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"hmgbpvs.h"

 int power(float v,float i)
 {
    float power_c;
    power_c = v * i;
    return power_c;
}