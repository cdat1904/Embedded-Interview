/*
    * File: Table.hpp
    * Author: Dat Pham
    * Date: 8/7/2023
    * Description: This is a header file for the class "Table" that
*/

#pragma once 

#include <list>
#include <iostream>
#include <utility>

using namespace std;

class Table
{
    private:
       int id; 
       int tableNumber;
       bool status;
       list<pair<int, pair<string, int>>> _list_Item; //Id, name, quantity
       // pair : 1 cap gia tri thanh 1 doi tuong ( 2 gia tri ko cung kieu du lieu voi nhau)   
    public:
       static int count;
       Table();
       //setter
       void setStatus(bool status);
       void addItemTolist(int id, string name, int quantity);
       void deleteItemList();
       //getter
       bool getStatus();
       int getId();
       string getName();
       int getTableNumber();
       list<pair<int, pair<string,int >>> get_list_Item();
       
       

};
