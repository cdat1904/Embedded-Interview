#include <stdio.h>
#include <stdint.h>

typedef union 
{
    uint8_t a;
    uint16_t b;
    uint32_t c;

}typeData;

void hienthi(typeData data){
    printf("a : %d, b : %d, c : %d\n", data.a, data.b, data.c);

}

int main(int argc, char const * argv[]){

    typeData data;

    data.a = 12;
    data.b = 21;
    data.c = 37;

    hienthi(data);

    return 0;
}