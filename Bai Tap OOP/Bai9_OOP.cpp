#include <iostream>
#include <string>

using namespace std;

class Car{
    private:
        string mausac;
        string kieuDongco;
        static int soKm;
    public:
        void setThongtin(string ms, string kdc, int skm);
        void getThongtin();
        int getSoKm();
        float BaoTri();
};

int Car::soKm = 0;

void Car::setThongtin(string ms, string kdc, int skm){
    Car::mausac = ms;
    Car::kieuDongco = kdc;
    Car::soKm = skm;
}

void Car::getThongtin(){
    cout<<"Mau cua o to la "<< Car::mausac<<endl;
    cout<<"Kieu dong co cua o to la " << Car::kieuDongco << endl;
    cout<<"So km da di la "<< Car::soKm << endl;
}

int Car::getSoKm(){
    return Car::soKm;
}


float Car::BaoTri(){
    if (Car::soKm <= 1000){
        cout << "Tien bao tri la 15000"<< endl;
    }
    else(Car::soKm > 1000 );
    {
       cout << "Tien bao tri la 30000" << endl;
    }
}
int main(int argc, char const *argv[])
{
    Car car;
    car.setThongtin("Red", "8 xi lanh", 1500);
    car.getThongtin();
    car.BaoTri();
    cout<<"So km la "<<car.getSoKm()<<endl;
    return 0;
}