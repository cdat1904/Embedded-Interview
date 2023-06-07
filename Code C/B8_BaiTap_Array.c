#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

//cho một chuỗi ngẫu nhiên vd: char arr[] = "mot hai mot hai mot mot, ba bon ba hai mot";
//đếm xem một từ xuất hiện bn lần
//"mot" xuat hien 4 lan
//"hai" xuat hien 3 lan 
//"ba "xuat hien 1 lan

bool isEqual(const char arr1[], const char arr2[]){
    uint8_t i = 0;
    while(arr1[i] == arr2[i]){
        if (arr1[i] == '\0'){
            return true;
        }
        i++;
    }
    return false;
}

int main(int argc, char const * argv[]){

    char arr1[] = "hello world";
    char arr2[] = "hello world";
    printf("test : %d\n" , isEqual(arr1,arr2));
    return 0;
}