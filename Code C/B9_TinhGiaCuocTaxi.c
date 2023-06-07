#include <stdio.h>

//tinh gia cuoc taxi
//di taxi duoi 1 km gia 14 nghin
// di <= 30km gia 10 nghin
//di hon 30km gia 8 nghin
void caculateTaxiFee(){
    int TotalKm;
    int Cost;
    printf("\nNhap vao so km : ");
    scanf("%d", &TotalKm);
    printf("\nGia tien : ");
    if (TotalKm <= 1){
        Cost = TotalKm * 14000;
    }
    else if (TotalKm <= 30 && TotalKm > 1){
        Cost = (TotalKm - 1) * 10000 + 1 * 14000;
    }
    else{
        Cost = 1 * 14000 + 29 * 10000 + (TotalKm -30) * 8000;
    }
    printf("%d", Cost);

}
int main(int argc, char const * argv[]){

    caculateTaxiFee();

    return 0;


}