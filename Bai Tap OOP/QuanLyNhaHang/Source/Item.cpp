/*
  * File: Item.cpp
  * Author: Dat Pham
  * Date: 8/7/2023
  * Description: This is a source file for the class "Item"
*/

#include "../Header/Item.hpp"

//Initialize static variable id
int Item::count = 1;

/*
  * Constructor: Item
  * Description: Constructor of class "Item"
  * Input: 
  * Output: 
*/
Item::Item(){
    //set automatically when you create a object of class "Item"
    this->id = count;
    ++count;
    //set default name and price
    name = " ";
    price = 0;
}

/*
  * Method: setName
  * Description: Set the name of the item
  * Input: name - string
  * Output: none
*/

void Item::setName(string name){
    //set name
    this->name = name;
}

/*
  * Method: setPrice
  * Description: Set the price of the item
  * Input: price - double
  * Output:
*/
void Item::setPrice(double price)
{
    //set price
    this->price = price;
}

/*
  * Method: getName
  * Description: get the name of the item
  * Input: 
  * Output: name - string
*/
string Item::getName()
{
    //get name
    return this->name;
}

/*
  * Method: getId
  * Description: get ID of the item
  * Input:
  * Output: Id - int 
*/
int Item::getId(){
    //get ID
    return this->id;
}

/*
  * Method: getPrice
  * Description: get the price of the item 
  * Input:
  * Output: price - double
*/
double Item::getPrice(){
    //get price
    return this->price;
}

