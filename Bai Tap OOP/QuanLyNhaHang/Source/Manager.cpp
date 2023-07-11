/*
   * File: Manager.cpp
   * Author: Dat Pham
   * Date: 9/7/2023
   * Description: This is a source file for the class "Manager"
*/

#include <iostream>
#include <iomanip>
#include "../Header/Manager.hpp"

#define NOT_EMPTY true
#define EMPTY false

#define HEADER_LIST_ITEM \
    cout << setw(5) << "ID" << setw(10) << "Name" << setw(10) << "Price" << endl;

#define INFO_ITEM(item) \
    cout << setw(5) << (int)item.getId() << setw(10) << item.getName() << setw(10) << item.getPrice() << endl;

//Intialize static variable = 0
list<Table> Manager::_list_Table(0);
list<Item> Manager::_list_Item(0);

/*
  * Method: setNumberTable
  * Class: Manager
  * Description: set number of table
  * Input: 
      <1> d_Numbertable - const int : desired number of table to set
  * Output:
*/

void Manager::setNumberTable(const int d_Numbertable)
{
    //add each table to the list of tables
    for(int i = 0; i < d_Numbertable; i++)
    {
        Table table;
        this->_list_Table.push_back(table);
    }
}

/*
   * Method: addItem
   * Class: Manager
   * Description: Add a new item to the list 
   * Input: 
      <1> name_Item - const string
      <2> price - const double
   * Output:
*/
void Manager::addItem(const string name_Item, const double price)
{
    //create a new item
    Item n_item;
    n_item.setName(name_Item);
    n_item.setPrice(price);

    //add to the list
    this->_list_Item.push_back(n_item);
}

/*
   * Method: changeItem
   * Class: Manager
   * Description: change id of the item
   * Input:
      <1> id - const int 
   * Output:
*/
void Manager::changeItem(const int id)
{
    //find id in the list item
    for(auto &item : Manager::_list_Item)
    {
        if(item.getId() == id)
        {
            string name;
            double price;
            cout << "\t\t\t Current info of the item" << endl;
            HEADER_LIST_ITEM;
            INFO_ITEM(item);
            cout << "Enter the new info" << endl;
            cout << "Enter the new name : ";
            getline(cin, name);
            cout << "Enter the new price : ";
            cin >> price;
            cin.ignore(255, '\n');
            item.setName(name);
            item.setPrice(price);
            return;

        }
    }
    //if not
    cout << "ID not found" << endl;
}

/*
   * Method: deleteItem
   * Class: Manager
   * Description : delete the item from the list
   * Input: 
      <1> id - const int
   * Output:
*/
void Manager::deleteItem(const int id)
{
    Manager manager;
    list<Item> itemList = manager.getList_Item();

    int index = 0;
    for (auto & item : Manager::_list_Item)
    {
        if (item.getId() == id)
        {
            cout << "Deleting this item..." << endl;
            this->_list_Item.erase(itemList.begin());
            cout << "Deleted !!";
            return;

        }
        ++index;
    }
    //if not
    cout << "ID not found !!" << endl; 
}

/*
  * Method: showListItem
  * Class: Manager
  * Desription: Show the list of items
  * Input:
  * Output:
*/

void showListItem()
{
    Manager manager;
    //show info of items
    HEADER_LIST_ITEM;
    for (Item item : manager.getList_Item())
    {
        INFO_ITEM(item);
    }
}

list<Item> Manager::getList_Item()
{
    return this->_list_Item;
}
   
list<Table> Manager::getList_Table()
{
    return this->_list_Table;
}