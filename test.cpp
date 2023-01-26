#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "excursion.hpp"
#include "clutch_table.hpp"
#include "interface.hpp"

using namespace std;

//excursion

Excursion *excursion1 = new One_day_excursion;
Excursion *excursion3 = new One_day_excursion;
Excursion *excursion2 = new Multi_day_excursion;
Excursion *excursion4 = new Multi_day_excursion;

int num1 = 111;
int num2 = 222;
int num3 = 333;
int num4 = 444;


string date1 = "30.03.2003";
string date2 = "12.12.2012";
string date3 = "10.01.2001";
string date4 = "11.11.2011";


TEST(my_lib, Test_excursion_001){
    excursion1->set_sell_count(num1);
    ASSERT_EQ(excursion1->get_sell_count(), num1);
    
    excursion2->set_sell_count(num2);
    ASSERT_EQ(excursion2->get_sell_count(), num2);
    

    excursion1->set_date_start(date1);
    ASSERT_EQ(excursion1->get_date_start(), date1);
 
    excursion2->set_date_start(date2);
    ASSERT_EQ(excursion2->get_date_start(), date2);
    
    excursion1->set_code(num1);
    ASSERT_EQ(excursion1->get_code(), num1);
 
    excursion2->set_code(num2);
    ASSERT_EQ(excursion2->get_code(), num2);    
}

TEST(my_lib, Test_excursion_002){

}

TEST(my_lib, Test_excursion_003){
}

//clutch_table

Clutch_Table table;

TEST(my_lib, Test_clutch_table_001){
    table.insert(num1, date1, excursion1);
    table.insert(num2, date2, excursion2);
    ASSERT_TRUE(table.find(excursion1->get_code(), excursion1->get_date_start()));
    ASSERT_TRUE(table.find(excursion2->get_code(), excursion2->get_date_start()));
    ASSERT_FALSE(table.find(excursion3->get_code(), excursion3->get_date_start()));
    ASSERT_FALSE(table.find(excursion4->get_code(), excursion4->get_date_start()));
}

TEST(my_lib, Test_clutch_table_002){
    table.erase(num1, date1);
    table.erase(num2, date2);
    ASSERT_FALSE(table.find(excursion1->get_code(), excursion1->get_date_start()));
    ASSERT_FALSE(table.find(excursion2->get_code(), excursion2->get_date_start()));    
}


