#include <stdio.h>
#include <stdint.h>


// Đảo chiều một mảng bất kỳ
void reverse(char array[],int size)
{
    for (int i = size; i >= 0; i--) {
        if (array[i] == ' ') {
            array[i] = '\0';
            printf("%s ", &(array[i]) + 1);
        }
    }
    printf("%s", array);
}

int main()
{
    char array[] = "mot hai ba bon nam ";
    int size = sizeof(array) / sizeof(array[0]);
    reverse(array, size);
    return 0;
}
