# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       |To check power_calc function|  90,10| 900.00| 900.00| Requirement based |


## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       | To check islanded mode 1 working|  1200.00,200.00,1000 |400.00|400.00|Scenario based |
|  L_02       | To check islanded mode 2 working|  90.00,1600.00,1000 |600.00|600.00|Scenario based    |
|  L_03       | To check islanded mode 3 working|  1500.00,1200.00,2000 |2700|2700|Scenario based    |
|  L_04       |To check grid mode working| 2500.00,2000|500|500|Scenario based    |
