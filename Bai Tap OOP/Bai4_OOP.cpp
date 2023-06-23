#include <stdio.h>
#include <string>
#include <iostream>


//Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các động vật khác nhau.
using namespace std;
class Animals{
    private:
       string ten;
       uint8_t tuoi;
       uint8_t chieucao;
       float trongluong;
    public:
       void setThongTin(string ten, uint8_t tuoi, uint8_t chieucao, float trongluong );
       uint8_t getTuoi();
       uint8_t getChieuCao();
       string getTen();
       float getTrongLuong();
};
void Animals::setThongTin(string ten, uint8_t tuoi, uint8_t chieucao, float trongluong )
{
    Animals::ten = ten;
    Animals::tuoi = tuoi;
    Animals::chieucao = chieucao;
    Animals::trongluong = trongluong;
}
uint8_t Animals::getTuoi(){
    return Animals::tuoi;
}
uint8_t Animals::getChieuCao(){
    return Animals::chieucao;
}
string Animals::getTen(){
    return Animals::ten;
}
float Animals::getTrongLuong(){
    return Animals::trongluong;
}

class TinhToan{
    private:
       Animals dv1;
       Animals dv2;
       typedef enum{
           CHI_SO_BMI,
           SO_SANH_TUOI,
           SO_SANH_TRONG_LUONG
       } LuaChon;
  LuaChon luachon;
    public:
       TinhToan(Animals dv1, Animals dv2);
       TinhToan(Animals dv1);
       float getBMI();
       void SoSanhTuoi();
       void SoSanhTrongLuong();
};

TinhToan::TinhToan(Animals dv1, Animals dv2){
    TinhToan::dv1 = dv1;
    TinhToan::dv2 = dv2;
}

TinhToan::TinhToan(Animals dv1){
    luachon = CHI_SO_BMI;
    TinhToan::dv1 = dv1;
}

float TinhToan::getBMI(){
    if (luachon == CHI_SO_BMI){
        return dv1.getTrongLuong()/(dv1.getChieuCao()*dv1.getChieuCao());
    }
    else{
        printf("khong the tinh toan BMI");
    }
}

void TinhToan::SoSanhTuoi(){
    if (dv1.getTuoi() < dv2.getTuoi()){
       cout << "" << dv1.getTen() << " "<< "nho tuoi hon" << " " <<dv2.getTen() << endl;
    }else if (dv1.getTuoi() > dv2.getTuoi()){
        cout << "" << dv1.getTen() << " "<< "lon tuoi hon" << " "<< dv2.getTen() << endl;
    }else{
        cout << "" << dv1.getTen() << " "<< "bang tuoi " << " " << dv2.getTen() << endl;
    }

}
void TinhToan::SoSanhTrongLuong(){
     if (dv1.getTrongLuong() < dv2.getTrongLuong()){
        cout<< dv1.getTen() << " "<< "co trong luong be hon " << " " << dv2.getTen()<<endl;
    }else if (dv1.getTrongLuong() > dv2.getTrongLuong()){
        cout<< dv1.getTen() << " "<< "co trong luong lon hon " << " " << dv2.getTen()<<endl;
    }else{
        cout<< dv1.getTen() << " "<< "co trong luong bang voi " << " " << dv2.getTen()<<endl;
    }
}
int main(int argc, char const * argv[]){

    Animals dv1, dv2;
    dv1.setThongTin("Cho", 3, 30, 25);
    dv2.setThongTin("Meo", 5, 20, 15);
    TinhToan tt(dv1,dv2);
    TinhToan tt2(dv1);
    tt.SoSanhTuoi();
    tt.SoSanhTrongLuong();
    cout<<"Chi so BMI cua "<<dv1.getTen()<<" la "<<tt2.getBMI()<< endl;
    
    return 0;
}