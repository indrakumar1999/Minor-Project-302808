/**
 * @file test_hmgbpvs.c
 * @author Deepak
 * @brief To test every parameter taken into account 
 * @version 0.1
 * @date 2021-07-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"hmgbpvs.h"
#include"unity.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Prototypes for all the test functions */
int power(float,float); 
int islanded_m1(float,float,int);
int islanded_m2(float,float,int);
int islanded_m3(float,float,int);
int grid_mode(float,int);

/* Write all the test functions */ 
/**
 * @brief To check for system parameter, please use exit command after the system checks run once to head towards the test case evaluation
 * 
 */
void test_power(void) 
{
  
  TEST_ASSERT_EQUAL((500.00), power(50,10));
}
void test_islanded_m1(void)
{

  TEST_ASSERT_EQUAL((400.00), islanded_m1(1200.00,200.00,1000));

}
void test_islanded_m2(void)
{

  TEST_ASSERT_EQUAL((600.00), islanded_m2(90.00,1600.00,1000));

}
void test_islanded_m3(void)
{

  TEST_ASSERT_EQUAL((2700), islanded_m3(1500.00,1200.00,2000));

}
void test_grid_mode(void)
{
    TEST_ASSERT_EQUAL((500), grid_mode(2500.00,2000));
}


/* Start of the application test */
int main(void)
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */
  RUN_TEST(test_power);
  RUN_TEST(test_islanded_m1);
  RUN_TEST(test_islanded_m2);
  RUN_TEST(test_islanded_m3);
  RUN_TEST(test_grid_mode);
  /* Close the Unity Test Framework */
  return UNITY_END();
}