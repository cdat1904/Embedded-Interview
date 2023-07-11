/*
   * File: Main.cpp
   * Author: Dat Pham'
   * Date: 9/7/2023
   * Description: This is the main program
*/

#include "Header\Manager.hpp"
#include "Header\Employee.hpp"
#include <iomanip>

using namespace std;

//main screen
#define EXIT 0
#define MANAGER 1
#define EMPLOYEE 2

//Manager macros
#define RETURN 0
#define SET_MUM_TABLE 1
#define ADD_ITEM 2
#define CHANGE_ITEM 3
#define DEL_ITEM 4
#define LIST_ITEM 5

//Employee macros
#define TAKE_ORDER 1
#define SHOW_BILL 2
#define CHECK_OUT 3

//Addition macros
#define CONTINUE 1
#define NONE  -1
#define INVALID -1
#define AVAILABLE true
#define OCCUPIED false
#define NOT_EMPTY true
#define EMPTY false

/*
   * Function: checkListTable
   * Description: Check if the list table empty or not
   * Input:
   * Output:
*/

bool checkListTable()
{
    Manager manager;
    int tableSize = manager.getList_Table().size();
    if (tableSize == 0)
    {
        cout << "The list of table is EMPTY !!!"<< endl;
        return EMPTY;
    }
    else{
        return NOT_EMPTY;
    }
}

/*
   * Function: checkListItem
   * Description: Check if the list item is empty or not
   * Input:
   * Output:
*/

bool checkListItem()
{
    Manager manager;
    int itemSize = manager.getList_Item().size();
    if(itemSize == 0)
    {
        cout << "The list item is EMPTY !!!"<< endl;
        return EMPTY;
    }
    else{
        return NOT_EMPTY;
    }
}

/*
 * Function: isContinue
 * Description: check if the user want to continue this option or not
 * Input: 
 *     <1> option - option "return" or "continue"
 * Output: 
 *     returns the selection of user
 */

int isContinue(int option){
    int key;
    do
    {
        cout << "0. Return" << endl;
        cout << "Your selection : ";
        cin >> key;
        cin.ignore(255, '\n');
        //if the key invalid
        if (key != option)
        {
            cout << "Invalid select. Please try again ";
        }
    } while (key != option);
    return key;
    
}

/*
 * Function: isContinue
 * Description: check if the user want to continue this option or not
 * Input: 
 *     <1> option1 - option "return" or "continue"
 *     <1> option2 - option "return" or "continue"
 * Output: 
 *     returns the selection of user
 */

int isContinue(int option1, int option2)
{
    int key;
    do
    {
        cout << "1. Continue " << endl;
        cout << "0 . Return " << endl;
        cout << "=> Your selection : ";
        cin >> key;
        cin.ignore(255, '\n');
        if(key != option1 && key != option2)
        {
            cout << "Invalid select. Please try again try again";

        }
    } while (key != option1 && key != option2);
    return key;
    
}

/*==================== MAIN FUNCTION =====================*/
int main(int argc, char const * argv[])
{
    int key;   //input the key for option
    Manager manager;    //manager
    Employee employee;
    Table table;   //employee
    int a_key;

    do
    {
        cout << "========== MAIN SCREEN ===========";
        cout << "1. MANAGER\n2.EMPLOYEE\n0.EXIT";
        cout << "=> Your selection : ";
        cin >> key;   //select option
        cin.ignore(255,'\n');
        switch(key)
        {
            case MANAGER:
               do
               {
                  cout << "============= MANAGER ============";
                  cout << "1.Set number of table\n2.Add a new item\n3.Change Item";
                  cout << "4.Delete Item\n5.List items\0.Return";
                  cout << "==> Your selection: ";
                  cin >> key;
                  cin.ignore(255,'\n');


                  switch(key)
                  {
                    case RETURN:
                       break;  //select to return
                    case SET_MUM_TABLE:
                       int num_table;
                       cout << "Enter the number of table: ";
                       cin >> num_table;               //enter the number of table
                       cin.ignore(255,'\n');
                       manager.setNumberTable(num_table);    //set number of tables
                       break;

                    case ADD_ITEM:
                       
                       
                       do
                       {
                       cout << "========= ADD NEW ITEM =================" << endl; 
                       string name_item;
                       double price;
                       cout << "Enter the name : ";
                       getline(cin, name_item);
                       cout << "Enter the price : ";
                       cin >> price;
                       cin.ignore(255,'\n');
                       manager.addItem(name_item, price);  //add the item 

                       //continue of not
                       a_key = isContinue(RETURN, CONTINUE);
                       break;
                       
                       }while(a_key == CONTINUE);
                       break;
                    
                    case CHANGE_ITEM:
                       int a_key;
                       do{
                        cout << "========= CHANGE ITEM =================";
                        if (checkListItem() == EMPTY) break;
                        int id;
                        cout << "Enter the ID : ";
                        cin >> id;
                        cin.ignore(255,'\n');
                        manager.changeItem(id);

                        //continue or not
                        a_key = isContinue(RETURN, CONTINUE);

                       }while(a_key == CONTINUE);
                       break;
                    
                    case DEL_ITEM:
                       
                        do{
                        cout << "=========== DELETE ITEM =============";
                        if (checkListItem() == EMPTY)
                        {
                            break;
                        }
                        int id;
                        cout << "Enter the item ID : ";
                        cin >> id;
                        cin.ignore(255,'\n');
                        manager.deleteItem(id);

                        //continue or not
                        a_key = isContinue(RETURN, CONTINUE);
                        }while(a_key == CONTINUE);
                        break;
                    

                    case LIST_ITEM:
                        cout << "============== LIST ITEM =============" << endl;
                        if(checkListItem() == EMPTY) break;
                        manager.showListItem();

                        //continue or not
                        isContinue(RETURN);
                        break;
                    default:
                        cout << "Invalid select. Please try again." << endl;
                        break;
                  }
               } while (key != RETURN);
               key = -1;
               break;




            case EMPLOYEE:
            {
                int tableNumber;
                do
                {
                    cout << "=========== EMPLOYEE =========" << endl;
                    if(checkListTable() == EMPTY) break;
                    if(checkListItem() == EMPTY) break;
                    employee.mainScreen();           //display main screen
                    cout << "0. Return\nSelect table: ";
                    cin >> tableNumber;              //enter table number
                    cin.ignore(255,'\n');
                    
                    int tableSize = manager.getList_Table().size();
                    //if invalid table number
                    if(tableNumber < 0 || tableNumber > tableSize);
                    {
                        cout << "Invalid select. Please try again.";

                    }
                    if(tableNumber == 0) break;
                    else
                    {
                        employee.selectTable(tableNumber);
                        do
                        {
                            cout << "============ TABLE ====================";
                            cout << "1. Take order" << endl;
                            cout << "2. Show the list of oreder items" << endl;
                            cout << "3. Check out " << endl;
                            cout << "==> Your selection: ";
                            cin >> key;
                            cin.ignore(255,'\n');

                            switch(key)
                            {
                                case RETURN:
                                   break;
                                case TAKE_ORDER:
                                   int a_key;
                                   do
                                   {
                                      cout << "============ TAKE ORDER =================" << endl;
                                      int id, quantity;
                                      cout << "Enter the ID: ";
                                      cin >> id;
                                      cout << "Enter the quantity: ";
                                      cin >> quantity;
                                      cin.ignore(255,'\n');
                                      employee.takeOrder(tableNumber, id, quantity);

                                      //continue or not
                                      isContinue(RETURN, CONTINUE);
                                   } while (a_key == CONTINUE);
                                   break;


                                case SHOW_BILL:
                                    cout << "============= BILL =================" << endl;
                                    employee.showBill(tableNumber);

                                    isContinue(RETURN, CONTINUE);
                                    break;

                                case CHECK_OUT:
                                    cout << "============ CHECK OUT =================" << endl;
                                    employee.checkOut(tableNumber);
                                    key = RETURN;
                                    break;
                                default:
                                    cout << "Invalid select. Please try again. "<< endl;
                                    break;

                                   
                            }
                        }while(key != RETURN);
                    }
                } while (tableNumber != 0);

                
            } 

            case EXIT:
               break;
            default:
               cout << "Invalid selection. Please try again." << endl;
               break;  
        }


    } while (key != EXIT);

    return 0;
    
}