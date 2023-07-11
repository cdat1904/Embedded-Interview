/*
   * File: Table.cpp
   * Athor: Dat Pham
   * Date: 8/7/2023
   * Description: This is a source for the class "Table"
*/

#include "Table.hpp"
#include "Manager.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

#define AVAILABLE true
#define OCCUPIED false
#define NOT_EMPTY true
#define EMPTY false

#define HEADER_LIST_ITEM \
    do { \
        std::cout << std::setw(5) << "ID" << std::setw(15) << "Name" << std::setw(15) << "Unit price"; \
        std::cout << std::setw(10) << "Quantity" << std::setw(10) << "Total" << std::endl; \
    } while (false)

#define INFO_ITEM(d_item) \
    do \
    { \
        std::cout << std::setw(5) << (int)d_item.first.getId() << std::setw(15) << d_item.first.getName(); \
        std::cout << std::setw(15) << d_item.first.getPrice() << std::setw(10) << d_item.second << std::endl; \
        std::cout << std::setw(10) << (d_item.first.getPrice() * d_item.second) << std::endl; \
    } while (false)
   
//table number begins from 1
int Table::count = 1;

/*
   * Constructor: Table
   * Description: set status of the table
   * Acess: Public
   * Class: Table
   * Input: none
*/
Table::Table()
{
   //set available status for each object
   this->status = AVAILABLE; //available
   list<pair<int, pair<string, int>>> _list_Items[0];
   //Table number increses automatically and fixed
   this->tableNumber = count;
   ++count;
}

/*
   * Method: setStatus
   * Class: Table
   * Description: set status for the selected table 
   * Acess: Public 
   * Input: status - bool
   * Output: none
*/

void Table::setStatus(bool status)
{
   this->status = status;
}

/*
   * Method: addItemToList
   * Class: Table
   * Description: add item to list
   * Acess: Public
   * Input:
         <1> id - int
         <2> name - string
         <3> quantity - int
   * Output: none
*/

void Table::addItemTolist(int id, string name, int quantity)
{
   for (auto &item :_list_Item)
   {
      if (item.first == id ){
         item.second.second += quantity;
         return;
      }
   }
   _list_Item.push_back(make_pair(id, make_pair(name,quantity)));
}

/*
   * Method: deleteItemList
   * Class: Table
   * Description: delete item list 
   * Acess: Public
   * Input:
   * Output:
*/
void Table::deleteItemList()
{
   this->_list_Item.clear();
}

/*
   * Method: getStatus
   * Class: Table 
   * Description: get current status of the table
   * Acess: Public
   * Input:
   * Output:
*/
bool Table::getStatus()
{
   return this->status;
}

/*
   * Method: getTableNumber
   * Class: Table
   * Description: get table number
   * Acess: Public
   * Input:
   * Output:
*/
int Table::getTableNumber()
{
   return this->tableNumber;
}

/*
   * Method: get_list_Item
   * Class: Table
   * Description: get list od order item
   * Acess: Public
   * Input: 
   * Output:
*/

list<pair<int, pair<string, int>>> Table::get_list_Item()
{
   return this->_list_Item;
}

/*
   * Method: getId
   * Class: Table
   * Description: getId
   * Acess: Public
   * Input: 
   * Output:
*/
int Table::getId()
{
   return id;
}
