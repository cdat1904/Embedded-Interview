#include <iostream>
#include <math.h>

//Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba điểm.

class Diem{
    private:
        int8_t toaDoX;
        int8_t toaDoY;
    public:
        Diem(int8_t x = 0, int8_t y = 0);
        void setToaDoX();
        int8_t getToaDoX();
        void setToaDoY();
        int8_t getToaDoY();
};

Diem::Diem(int8_t x, int8_t y){
    toaDoX = x;
    toaDoY = y;
}

void Diem::setToaDoX(){
    int8_t x;
    printf("Toa do X la ");
    scanf("%d", &x);
    toaDoX = x;
}

int8_t Diem::getToaDoX(){
    return toaDoX;
}

void Diem::setToaDoY(){
    int8_t y;
    printf("Toa do Y la ");
    scanf("%d", &y);
    toaDoY = y;
}

int8_t Diem::getToaDoY(){
    return toaDoY;
}

class PhepToanOXY{
    private:
        Diem diemA;
        Diem diemB;
        Diem diemC;
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH_TAM_GIAC
        }TypePheptoan;
        TypePheptoan pheptoan;
    public:
        PhepToanOXY(Diem A, Diem B);
        PhepToanOXY(Diem A, Diem B, Diem C);
        float getKhoangcach();
        float getDientich();
};

PhepToanOXY::PhepToanOXY(Diem A, Diem B){
    pheptoan = KHOANG_CACH;
    diemA = A;
    diemB = B;
}

PhepToanOXY::PhepToanOXY(Diem A, Diem B, Diem C){
    pheptoan = DIEN_TICH_TAM_GIAC;
    diemA = A;
    diemB = B;
    diemC = C;
}

float PhepToanOXY::getKhoangcach(){
    if (pheptoan == KHOANG_CACH)
    {
        return sqrt((diemB.getToaDoX() - diemA.getToaDoX())*(diemB.getToaDoX() - diemA.getToaDoX()) + (diemB.getToaDoY() - diemA.getToaDoY())*(diemB.getToaDoY() - diemA.getToaDoY()));
    }else
    {
        printf("Khong tinh duoc khoang cach\n");
    }
    
}

float PhepToanOXY::getDientich(){
    if (pheptoan == DIEN_TICH_TAM_GIAC)
    {
        return fabs(0.5 * ((diemB.getToaDoX() - diemA.getToaDoX()) * (diemC.getToaDoY() - diemA.getToaDoY()) - (diemC.getToaDoX() - diemA.getToaDoX()) * (diemB.getToaDoY() - diemA.getToaDoY())));
    }else{
        printf("Khong tinh duoc dien tich\n");
    }
    
}

int main(int argc, char const *argv[])
{
    Diem diemA, diemB, diemC;
    diemA.setToaDoX();
    diemA.setToaDoY();

    diemB.setToaDoX();
    diemB.setToaDoY();

    diemC.setToaDoX();
    diemC.setToaDoY();


    PhepToanOXY PhepToan1(diemA,diemB);
    printf("Ket qua la %f\n", PhepToan1.getKhoangcach());

    PhepToanOXY PhepToan2(diemA,diemB,diemC);
    printf("Ket qua la %f\n", PhepToan2.getDientich());

    return 0;
}