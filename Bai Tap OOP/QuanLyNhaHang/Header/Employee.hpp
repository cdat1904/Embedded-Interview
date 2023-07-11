/*
    * File: Employee.hpp
    * Author: Dat Pham
    * Date: 8/7/2023
    * Description: This is a header file for class "Employee"
*/
#ifndef Employee_

#pragma once   //la directive c++ dam bao 1 header file chi dc include 1 lan
#include "../Header/Manager.hpp"
class Employee 
{
    private:
    public:
       void mainScreen();
       void selectTable(int tableNumber);
       void takeOrder(int tableNumber, int itemID, int quantity);
       void showBill(int tableNumber);
       void checkOut(int tableNumber);
    
};

#endif // Employee_