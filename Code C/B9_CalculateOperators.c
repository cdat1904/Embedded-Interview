#include <stdio.h>
#include <stdint.h>
//Nhap vao ban phim sau do tinh + - * /
typedef enum{
    NUMBER,
    OPERATOR,
}TypeMath;

typedef struct{
    TypeMath key;
    union 
    {
       uint16_t number;
       char operator;
    }value;
}TypeMaths;

void stringToDec(char input[],TypeMaths output[]){
    uint16_t number = 0;
    uint8_t i = 0;
    
    while (*(input) != '\0')
    {
        if( *input >= '0' && *input <= '9'){
        uint8_t temp = *input - '0';
        number = 10 * number + temp;
        input++;
        continue;
      }
      else if (*input == '+' || *input == '-' || *input == '*' || *input == '/')
      {
          output[i].key = OPERATOR;
          output[i].value.operator = *input;
          i++;
          input++;
          continue;
      }
      else{
        if (number != 0) {
            output[i].key = NUMBER;
            output[i].value.number = number;
            number = 0;
            i++;
            }
      } 
      input++;
    }
    output[i].key = NUMBER;
    output[i].value.number = number;
}


int main( int argc, char const * agrv[]){

    char input[] = "10 + 8 - 614 + 7 - 532 * 2";
    TypeMaths output[20];

    stringToDec(input,output);
    for (int i = 0; i < 20; i++){
        if (output[i].key == NUMBER){
            printf("key : NUMBER, value : %d\n",output[i].value.number);
        }else{
            
            printf("key : OPERATOR, value : %c\n",output[i].value.operator);

        }
    }
    
    stringToDec(input, output);
       
  
    return 0;
    
    
}