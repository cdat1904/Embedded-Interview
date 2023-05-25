#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b10110010;
uint8_t PORTB = 0b11111111;
void ReadByte(uint8_t byte){            
    
    uint8_t temp = 0b10000000;          
    uint8_t Val;
    printf("0b");
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
    printf("\n");
}    

typedef  enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}pins;

typedef enum{
    LOW,
    HIGH,

}status; 

void pinHigh(pins pin){
   	PORTA = PORTA | (0b10000000 >> pin);   //PORTA = 0b10110010
}                                              //OR  0b10000000

void pinLow(pins pin){
   PORTA = PORTA &  ~(0b10000000 >> pin);    //PORTA = 0b10110010
                                             //AND & ~ 0b10000000
}

void digitalWrite(pins pin, status status){
    if(status == HIGH)
        pinHigh(pin);
        else 
        pinLow(pin);
    

}

int main(int argc, char const *argv[])
{
    //PORTA = 0b10110010
    digitalWrite(PIN0,LOW);
    digitalWrite(PIN5,HIGH);
    digitalWrite(PIN7,HIGH);
    ReadByte(PORTA);
 

    return 0;
}