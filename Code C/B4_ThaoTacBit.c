#include <stdio.h>
#include <stdint.h>


void ReadByte(uint8_t byte){            
    
    uint8_t temp = 0b10000000;          
    uint8_t Val;
    
    for (uint8_t i = 0; i < 8; i++)
    {
        Val = byte & temp;
        if(Val == 0){
            printf("0");
        }else{
            printf("1");
        }
        byte = byte << 1;
    }
}    


int main(int argc, char const *argv[])
{
    uint8_t test = 0b11001011;
    printf("0b");
    ReadByte(test);
    printf("\n");

    return 0;
}