#include <iostream>

using namespace std;
class Phanso{
    private:
        uint8_t tuso;
        uint8_t mauso;
    public:
        void setTuso(uint8_t ts);
        uint8_t getTuso();
        void setMauso(uint8_t ms);
        uint8_t getMauso();
        
};

void Phanso::setTuso(uint8_t ts){
    tuso = ts;
}

uint8_t Phanso::getTuso(){
    return Phanso::tuso;
}

void Phanso::setMauso(uint8_t ms){
    mauso = ms;
}

uint8_t Phanso::getMauso(){
    return Phanso::mauso;
}

class PhepToan{
    private:
        Phanso ps1;
        Phanso ps2;
    public:
        PhepToan(Phanso ps1, Phanso ps2);
        float cong();
        float tru();
        float nhan();
        float chia();
};

PhepToan::PhepToan(Phanso ps1, Phanso ps2){
    PhepToan::ps1 = ps1;
    PhepToan::ps2 = ps2;
}

float PhepToan::cong(){
    return (float)(ps1.getTuso() * ps2.getMauso() + ps2.getTuso()*ps1.getMauso())/(ps1.getMauso()*ps2.getMauso());
}

float PhepToan::tru(){
    return (float)(ps1.getTuso() * ps2.getMauso() - ps2.getTuso()*ps1.getMauso())/(ps1.getMauso()*ps2.getMauso());
}

float PhepToan::nhan(){
    return (float)( ps1.getTuso() * ps2.getTuso())/ ( ps1.getMauso() * ps2.getMauso());
}

float PhepToan::chia(){
    return (float)(ps1.getTuso() * ps2.getMauso())/ ( ps1.getMauso() * ps2.getTuso());
}


int main(int argc, char const *argv[])
{
    Phanso ps1, ps2;
    ps1.setTuso(5);
    ps1.setMauso(3);
    ps2.setTuso(1);
    ps2.setMauso(4);
    PhepToan pt(ps1,ps2);
    cout << "Ket qua phep cong = " << pt.cong() <<endl;
    cout << "Ket qua phep tru = " << pt.tru() <<endl;
    cout << "Ket qua phep nhan = " << pt.nhan() <<endl;
    cout << "Ket qua phep chia = " << pt.chia() <<endl;
}