#include <iostream>
#include <math.h>

using namespace std;

//Tạo một lớp hình chữ nhật với các thuộc tính chiều dài, chiều rộng và các phương thức để tính chu vi, diện tích, đường chéo và kiểm tra xem nó có phải là hình vuông hay không.

class hinhChuNhat{
    private:
        uint8_t Chieudai;
        uint8_t Chieurong;
    public:
        hinhChuNhat(uint8_t cd = 0, uint8_t cr = 0);
        uint16_t getChieuDai();
        uint16_t getChieuRong();
        uint16_t getChuVi();
        uint16_t getDienTich();
        uint16_t getDuongCheo();
        void Kiemtra();
};

hinhChuNhat::hinhChuNhat(uint8_t cd, uint8_t cr){
    Chieudai = cd;
    Chieurong = cr;
}

uint16_t hinhChuNhat::getChieuDai(){
    uint16_t cd;
    printf("Nhap chieu dai la : ");
    scanf("%d", &cd);
    Chieudai = cd;
    return Chieudai;
}

uint16_t hinhChuNhat::getChieuRong(){
    uint16_t cr;
    printf("Nhap chieu rong la : ");
    scanf("%d", &cr);
    Chieurong = cr;
    return Chieurong;
}

uint16_t hinhChuNhat::getChuVi(){
    return 2*(Chieudai + Chieurong);
}

uint16_t hinhChuNhat::getDienTich(){
    return (Chieudai * Chieurong);
}

uint16_t hinhChuNhat::getDuongCheo(){
    return sqrt((Chieudai*Chieudai) + (Chieurong*Chieurong));
}

void hinhChuNhat::Kiemtra(){
    if (Chieudai == Chieurong)
    {
        printf("Day la hinh vuong\n");
    }else{
        printf("Day khong phai la hinh vuong\n");
    }
    
}

int main(int argc, char const *argv[])
{
    hinhChuNhat hcn;
    hcn.getChieuDai();
    hcn.getChieuRong();
    printf("Chu vi la %d\n", hcn.getChuVi());
    printf("Dien tich la %d\n", hcn.getDienTich());
    printf("Duong cheo la %d\n", hcn.getDuongCheo());
    hcn.Kiemtra();
    return 0;
}