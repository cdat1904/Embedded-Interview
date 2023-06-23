#include <iostream>
#include <string>


using namespace std;

class Person{
    private:
        string ten;
        int tuoi;
        string diachi;
    public:
        void setThongTin(string Ten, int Tuoi, string DiaChi);
        void getThongTin();
};

void Person::setThongTin(string Ten, int Tuoi, string DiaChi){
    ten = Ten;
    tuoi = Tuoi;
    diachi = DiaChi;
}

void Person::getThongTin(){
    cout<<"Ten : "<<Person::ten<<endl;
    cout << "Tuoi :"<< Person::tuoi<<endl;
    cout<<"Dia chi : "<<Person::diachi<<endl;

}



int main(int argc, char const *argv[])
{
    Person pp;
    pp.setThongTin("Dat", 21, "DA NANG");
    pp.getThongTin();
    return 0;
}