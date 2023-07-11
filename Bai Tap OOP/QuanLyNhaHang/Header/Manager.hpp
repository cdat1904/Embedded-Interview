/*
    * File: Manager.hpp
    * Author: Dat Pham
    * Date: 8/7/2023
    * Description: This is a header file for the class "Manager"
*/

#pragma once

#include <string>
#include <list>
#include "../Header/Item.hpp"
#include "../Header/Table.hpp"

using namespace std;

class Manager
{
    private: 
       static list<Table> _list_Table;
       static list<Item> _list_Item;
    public:
       void setNumberTable(const int d_Numbertable);
       void addItem(const string name_Item, const double price);
       void changeItem(const int id);
       void deleteItem(const int id);
       void showListItem();

       list<Item> getList_Item();
       list<Table> getList_Table();
       
};