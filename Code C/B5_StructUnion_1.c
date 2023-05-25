#include <stdio.h>
#include <stdint.h>

struct typeDate
{
    uint16_t arr1[7];
    uint8_t arr2[5];
    uint64_t arr3[5];
    uint32_t arr[3];
};

int main(int argc, char const *argv[])
{
    printf("Size : %lu\n", sizeof(struct typeDate));

    return 0;
}