#include <iostream>
#include <string>
using namespace std;

class DoiTuong{
    public:
      void  setthongtin(string ten, int tuoi);
      void hienthi();//menthod
    protected:
      int TUOI;   //property
      string TEN;  //property
};
void DoiTuong::hienthi(){
               
        cout << "Ten : " << TEN << endl;
        cout << "Tuoi : " << TUOI << endl;
        cout << "MSSV : " << MSSV << endl;
      
}
void DoiTuong::setthongtin(string ten, int tuoi){
    TEN  = ten;
    TUOI = tuoi;
    
};
class SinhVien : public DoiTuong{
    public:
      void setthongtin(string ten, int tuoi,int MSSV);
      void hienthi();//menthod
    private:
      int MSSV;
    

};
void SinhVien::setthongtin(string ten, int tuoi, int MSSV){
    TEN =ten;
    TUOI = tuoi;
    MSSV = MSSV;

};
int main( int argc, char const * argv[] ){

    DoiTuong dt;  //object sv thuoc class SinhVien


    dt.setthongtin("hoang", 17);

    
    dt.hienthi();    

    SinhVien sv;
    sv.setthongtin("toan ", 17);
    sv.hienthi();
    
    return 0;
}