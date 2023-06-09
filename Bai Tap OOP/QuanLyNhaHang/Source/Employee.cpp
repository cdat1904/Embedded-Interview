/*
   * File: Employee.cpp
   * Author: Dat Pham
   * Date: 8/7/2023
   * Description: This is source file for class Employee  
*/

#include <../Header/Employee.hpp>
#include <../Header/Manager.hpp>
#include <iostream>
#include <iomanip>

using namespace std;

#define AVAILABLE true
#define OCCUPIED false
#define NOT_EMPTY true
#define EMPTY true
#define PAID 1
#define UNPAID 2

#define HEADER_LIST_ITEM \
    do { \
        cout << setw(5) << "ID" << setw(10) << "Name" << setw(10) << "Quantity"; \
        cout << setw(10) << "Amount" << endl; \
    } while (0)

#define INFO_LIST_ITEM(d_item) \
    do { \
        cout << setw(5) << (int)d_item.first << setw(10) << d_item.second.first; \
        cout << setw(10) << d_item.second.second; \
        cout << setw(10) << itemTotalCost << endl; \
    } while (0)

/*
  * Method: mainScreen
  * Class: Employee
  * Description: display list of table and table status
  * Acess: public
  * Input: none
  * Output: none
*/
void Employee::mainScreen()
{
    Manager manager;
    //display list of table
    for (int i = 1; i <= manager.getList_Table().size(); ++i)
    {
        if(i == 1)
        {
            cout << "Table : |";
        }
        else{
            cout << " " << setw(3) << i << " |";
        }
    }
    cout << endl;

    // display status of table
    for (auto it = manager.getList_Table().begin(); it != manager.getList_Table().end(); ++it)
{
    if (it == manager.getList_Table().begin()) cout << "Status : |";
    if ((*it).getStatus() == AVAILABLE)
    {
        cout << "     " << " |";
    }
    else
    {
        cout << " x " << " |";
    }
}

    cout << endl;
}

/*
  * Method: selectTable
  * Class: Employee
  * Description: set status "OCCUPIED" for the table
  * Acess: public
  * Input: 
       <1> tableNumber - select the table number
  * Output: none
*/
void Employee::selectTable(int tableNumber)
{
    Manager manager;
    //go through each element in the list of table
    for(auto &item : manager.getList_Table())
    {
        if (item.getTableNumber() == tableNumber)
        {
            if (item.getStatus() == AVAILABLE)
            {
                item.setStatus(OCCUPIED);
                cout << "Selected table " << item.getTableNumber() <<endl;
                return;
            }
        }
    }
    //if not find the table number
    cout << "Cannot find the table number" << endl;

}

/*
   * Method: takeOrder
   * Class: Employee
   * Acess: public
   * Description: take the order
   * Input:
        <1> tableNumber - int
        <2> itemID - int
        <3> quantity - int
   * Output: 
*/
void Employee::takeOrder(int tableNumber, int itemID,int quantity)
{
    Manager manager;
    //go through each element in the list of table
    for(auto &item : manager.getList_Table())
    {
        if(item.getTableNumber() == tableNumber)
        {
            for(auto &item : manager.getList_Table())
            {
                // check the item ID
                if(item.getId() == itemID)
                {
                    //push information of the item to the list
                    string itemName = item.getName();
                    item.addItemTolist(itemID, itemName, quantity);
                    return;

                }
            }
        }
    }
    //if cannot find the table number
    cout << "cannot find the table number" << endl;
}

/*
   * Method: showBill
   * Class: Employee
   * Access: public
   * Description: Show the bill information
   * Input: 
       <1> table number - int
   * Output:
*/
void Employee::showBill(int tableNumber)
{
    Manager manager;
    //go though each element of the list
    for (auto &item : manager.getList_Table())
    {
        if(item.getTableNumber() == tableNumber)
        {
            // check table is ordered or not
            if(item.get_list_Item().size() == EMPTY)
            {
                cout << "The table is not ordered" << endl;
                return;
            }
            int isPaid = UNPAID;
            double totalBill = 0;
            
            //display the list of the ordered item with each item's total price
            HEADER_LIST_ITEM;
            auto itemList = manager.getList_Item();
            auto itemIterator = itemList.begin();

            for (auto orderedItem : item.get_list_Item()) {
            std::advance(itemIterator, orderedItem.first - 1);
            double itemTotalCost = itemIterator->getPrice() * orderedItem.second.second;
            totalBill += itemTotalCost;
            INFO_LIST_ITEM(itemIterator);   
            }  



            //display the total cost of the table
            do
            {
                cout << "======= TOTAL COST =======" << endl;
                cout << "Total cost = " << totalBill << endl;
                cout << "1. Paid / 2. Unpaid";
                cout << "=> Your selection : ";
                cin >> isPaid;
                cin.ignore(256, '\n');
                //select paid or unpaid
                if (isPaid != UNPAID && isPaid != PAID)
                {
                    cout << "Invalid select. Please select again." << endl;
                }

            } while (isPaid != UNPAID && isPaid != PAID);

            //if paid, set status AVAILABLE for the table and delete list of order
            if(isPaid == PAID)
            {
                //Update status
                auto list_Table = manager.getList_Table();
                auto tableIterator = list_Table.begin();
                std::advance(tableIterator, tableNumber - 1);
                tableIterator->setStatus(AVAILABLE);

                //Update List
                list<Table> tableList = manager.getList_Table();
                int tableIndex = tableNumber - 1;

                auto it = std::next(tableList.begin(), tableIndex);

                if (it != tableList.end()) {
                tableList.erase(it);

                // Update list
                manager.setList_Table(tableList);
                } else {
                     cout << "Invalid !!!" << endl; //Wrong case
                }
            }
            return;
            

        }       
    }
    //if cannot find the table 
    cout << "Invalid table number" << endl;
}

/* 
  /*
   * Method: chekOut
   * Class: Employee
   * Access: public
   * Description: check out
   * Input: 
       <1> table number - int
   * Output:
*/
*/
void Employee::checkOut(int tableNumber)
{
    Manager manager;
    // go through each element in the list of table
    for (auto item : manager.getList_Table())
    {
        if (item.getTableNumber() == tableNumber)
        {
            //Check if this table is ordered yet
            if(item.get_list_Item().size() == EMPTY) {
                cout << "The table has not been ordered yet!" << endl;
                return;
            }
            int isPaid = UNPAID;
            double totalBill = 0;

            // display the list of the ordered item with each item's total price
            HEADER_LIST_ITEM;
            int currentIndex = 0;
            for (auto it = item.get_list_Item().begin(); it != item.get_list_Item().end(); ++it)
            {
                if (currentIndex == it->first - 1)
                {
                    Item& orderedItem = *it;
                    double itemTotalCost = orderedItem.getPrice() * orderedItem.second.second;
                    totalBill += itemTotalCost;
                    INFO_LIST_ITEM(itemTotalCost);
                }
                currentIndex++;
            }

            // display the total cost of the table
            do
            {
                cout << "______________________TOTAL COST: " << totalBill << endl;
                cout << "1: Paid\n2: Unpaid\n";
                cout << "--> Your select: ";
                cin >> isPaid;
                cin.ignore(256, '\n');
                // select to paid or unpaid
                if(isPaid != UNPAID && isPaid != PAID)
                {
                    cout << "Invalid selection! Please select again." << endl;
                }
            } while (isPaid != UNPAID && isPaid != PAID);

            // if paid, set status "AVAILABLE" for the table and delete the list of the ordered item of the table
            if(isPaid == PAID)
            {
                manager.getList_Table().at(tableNumber - 1).setStatus(AVAILABLE);
                manager.getList_Table().at(tableNumber - 1).deleteListOrderedItem();
            }
            return;
        }
    }
    // when table number is not valid
    cout << "Invalid table number!" << endl;
}

