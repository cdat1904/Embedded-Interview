#include <iostream>
#include <string>

using namespace std;

class Bank{
    private:
        string soTK;
        string tenTK;
        float sodu;

    public:
        void setThongtin(string stk, string tentk, float t_du);
        float rutTien(float tien);
        float nopTien(float tien);
        float Kiemtrasodu();
        
};


void Bank::setThongtin(string stk, string tentk, float t_du){
    soTK = stk;
    tenTK = tentk;
    sodu = t_du;
}

float Bank::rutTien(float tien){
    sodu = sodu-tien;
    return sodu;
}

float Bank::nopTien(float tien){
    sodu = sodu + tien;
    return sodu;
}

float Bank::Kiemtrasodu(){
    return sodu;
}


int main(int argc, char const *argv[])
{
    Bank tk;
    tk.setThongtin("abc123", "DAT", 5000);
    tk.rutTien(300);
    cout << "So du hien tai la " << tk.kiemtrasodu() << endl;
    tk.nopTien(2500);
    cout << "So du hien tai la " << tk.kiemtrasodu() << endl;
    return 0;
}