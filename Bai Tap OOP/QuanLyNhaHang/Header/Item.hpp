/*
   * File: Item.hpp
   * Author: Dat Pham
   * Date: 8/7/2023
   * Description: This is a header file for class "Item"
*/

#pragma once

#include <string>

using namespace std;

class Item
{
    private:
       int id;
       string name;
       double price;
    public:
       static int count;
       Item();
       //setter
       void setName(string name);
       void setPrice(double price);
       //getter
       string getName();
       int getId();
       double getPrice();
};