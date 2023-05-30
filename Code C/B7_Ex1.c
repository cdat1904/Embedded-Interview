#include <stdio.h>
#include <stdint.h>
#include <string.h>

// cho mang ngau nhien vd : uint 8_t array[] = {1,3,5,2,3,3,6,7,9,8}
//so 1 : xuat hien n lan
//so 2 : xuat hien n lan
//...


//Sắp xếp theo thứ tự tăng dần
void sortList(uint8_t array[], uint8_t size){
    uint8_t temp;
    for (uint8_t i = 0; i < size -1; i++)
    {
        for (uint8_t j = size - 1; j > i; j--)
        {
            if(array[j] < array[j-1]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }       
    } 
    printf("\nMang da duoc sap xep tang dan: ");
    for(uint8_t i = 0; i < size; i++){
        printf("%5d", array[i]);
    }
}


//Đếm số lần xuất hiện trong mảng
int CountMember(uint8_t arr[],uint8_t size)
{
    uint8_t count = 0;
    uint8_t Value = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == Value)
		{
			count++;
		}
		if (Value != arr[i])
		{
			printf("\nSo %d xuat hien %d lan", arr[i-1], count);
			Value = arr[i];
			count = 1;
		}
		if (i == size-1)
		{
			printf("\nSo %d xuat hien %d lan\n", arr[i], count);

		}
	}
}

int main(int argc, char const *argv[])
{

   
   uint8_t arr[] = {1,4,2,5,3,6,1,2,3,3,1,6,4};
   char array[] = "mot hai ba bon nam";
   uint8_t size = sizeof(arr)/sizeof(arr[0]);
   
   sortList(arr,size);
   CountMember(arr,size);
   
   
   return 0;
}