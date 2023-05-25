#include <stdio.h>

void tong(int a, int b){
    printf("tong %d va %d = %d\n",a,b,a+b);
}

void hieu(int a, int b){
    printf("hieu %d va %d = %d\n",a,b,a-b);
}

void tich(int a, int b){
    printf("tich %d va %d = %d\n",a,b,a*b);
}
void thuong(int a, int b){
    printf("thuong %d va %d = %f\n",a,b,(float)a/b);
}

void tinhtoan(int a, int b, void (*ptr)(int , int )){
    printf("chuong trinh toan");
    ptr(a, b);
}
int main(int argc, char *argv[]){

    char *array = "hello";
    char array1[] = "hello";
    char *array2[] = {"hi","hello","world"};

    printf("test: %c\n", *(*array2+1));

    int a =15;
    int *ptr = &a;
    int **ptp = &ptr;
    printf("test: %d\n", **ptp);
    return 0;
}