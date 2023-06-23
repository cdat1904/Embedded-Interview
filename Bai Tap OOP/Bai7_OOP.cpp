#include <iostream>

using namespace std;

class NgayThangNam{
    private:
        uint8_t ngay;
        uint8_t thang;
        int nam;
        int namsinh;
    public:
        void setDate(uint8_t ngay, uint8_t thang, int nam);
        void setNamsinh(int namsinh);
        void testDate(uint8_t testngay, uint8_t testthang, int testnam);
        int getTuoi();
};

void NgayThangNam::setDate(uint8_t ngay, uint8_t thang, int nam){
    NgayThangNam::ngay = ngay;
    NgayThangNam::thang = thang;
    NgayThangNam::nam = nam;
}

void NgayThangNam::setNamsinh(int namsinh){
    NgayThangNam::namsinh = namsinh;
}

int NgayThangNam::getTuoi(){
    return NgayThangNam::nam - NgayThangNam::namsinh;
}



int main(int argc, char const *argv[])
{
    NgayThangNam Date;
    Date.setDate(23,6,2023);
    Date.setNamsinh(2001);
    cout<<"Tuoi la "<<Date.getTuoi()<<endl;
    return 0;
}