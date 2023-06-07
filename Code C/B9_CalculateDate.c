#include <stdio.h>
#include <stdbool.h>

int day, month, year;

//kiem tra ngay
bool CheckDate(int day, int month){
    if ((month == 2) && (day > 0) && (day > 30)){
        return true; //check thang 2
    }

    if ((month ==1) || (month ==2) || (month ==3) || (month == 4) ||
    (month == 5 ) || (month == 6 ) || (month == 7 ) || (month == 8)
    (month == 9) || (month ==10) || (month ==11) || (month == 12))
    && (day > 0) && (day < 32)
    {
        return true; //check all 12 thang
    }

    if ((month ==4) || (month == 6) || (month == 9) || (month == 11)) 
    && (day > 0) && (day < 31)
    {
        return true; //thang co 30 ngay
    }
    return false; 
}
//kiem tra thang
bool CheckMonth(int month){
    if ((month > 0) && (month < 13)){
        return true;
    }
    else{
        return false;
    }
}

//kiem tra nam nhuan
bool CheckLeapYear(int year){
    if (((year % 4) == 0) && (year % 100) != 0) {
        return true;
    }
    else {
        return false;
    }
}




int main(int argc, char const * argv[]){

    printf("\nNhap ngay : ");
    scanf(" %d", &day);
    


    return 0;
}