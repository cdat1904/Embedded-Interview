#include <iostream>

//Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi và diện tích của hình tròn.


class HinhTron{
    private:
        uint8_t BanKinh;
    public:
        HinhTron(uint8_t R = 0);
        uint8_t getBankinh();
        float getChuVi();
        float getDienTich();
};

HinhTron::HinhTron(uint8_t R){
    BanKinh = R;
}

uint8_t HinhTron::getBankinh(){
    printf("Nhap ban kinh la ");
    scanf("%d", &BanKinh);
    return BanKinh;
}

float HinhTron::getChuVi(){
    return 3.14 * 2 * BanKinh;
}

float HinhTron::getDienTich(){
    return 3.14*BanKinh*BanKinh;
}

int main(int argc, char const *argv[])
{
    HinhTron ht;
    ht.getBankinh();
    printf("Chu vi la %f\n", ht.getChuVi());
    printf("Dien tich la %f\n", ht.getDienTich());
    return 0;
}