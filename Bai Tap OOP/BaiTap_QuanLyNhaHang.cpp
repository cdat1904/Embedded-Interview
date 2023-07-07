#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

typedef enum{
    KET_THUC,
    QUAN_LY,
    NHAN_VIEN
}TypeOptions;

class MonAn
{
    private:
       int ID;
       string TEN;
       float GIA;
    public:
       MonAn();
       void setTen(string ten);
       void setGia(float gia);
       int getID();
       string getTen();
       float getGia();
       void HienThi();
};

MonAn::MonAn(){
    static int id = 1;
    ID = id;
    id++;
}

int MonAn::getID(){
    return ID;
}

void MonAn::setTen(string ten){
    MonAn::TEN = ten;
}
void MonAn::getTen(){
    return MonAn::TEN;
}
void MonAn::setGia(float gia){
    MonAn::GIA = gia;
}
void MonAn::getGia(){
    return MonAn::GIA;
}

void MonAn::HienThi(){
    cout << "==================" << endl;
    cout << "ID |  Ten         |  Gia " <<endl;
    cout <<" " << MonAn::getID() << "   " << MonAn::getTen() << MonAn::getGia() << endl;
}


class QuanLy
{
    private:
       int luachon;
       string TEN;
       float GIA;
       int soBan;
       list<MonAn> Database;
       void ThucHien();
       void ThemMon();
       void SuaMon();
       void HienThiDanhSach();
       void XoaMon();
       void ThietLapSoBan();
    public:
       QuanLy();
       int getSoBan();
       list<MonAn> getDatabase();
};
QuanLy::QuanLy(){
    cout << "======== QUAN LY =============" << endl;
    cout << "1. Them Mon " << endl;
    cout << "2. Sua mon " << endl;
    cout << "3. Xoa mon " << endl;
    cout << "4. Danh sach mon " << endl;
    cout << "5. Thiet lap so ban " << endl;
    cout << "0. Quay lai "<< endl;
    cout << "==============================="<< endl;

    int key = 0;
    do{
        cout << "Nhap lua chon : ";
        cin >> key;

    }while(key > 6 || key < 0);
    switch (key)
    {
    case 1:
        ThemMon();
        break;
    case 2:
        SuaMon();
        break;
    case 3:
        XoaMon();
        break;
    case 4:
        HienThiDanhSach();
        break;
    case 5:
        ThietLapSoBan();
        break;
    case 0:
        QuanLy();
        break;   
    
    default:
        break;
    }
}
list<MonAn> QuanLy::getDatabase()
{
    return this->Database;
}
void QuanLy::ThemMon(){
    MonAn mon;
    string ten;
    float gia;
    cout << "===== THEM MON ==========" << endl;
    cout << "Nhap ten mon : ";
    cin >> ten;
    mon.setTen(ten);

    cout << "Nhap gia : " ;
    cin >> gia;
    mon.setGia();
    Database.push_back(mon);

    int option;

    cout << "==========================" << endl;
    cout << " Lua chon " << endl;
    cout << "1. Tiep tuc them mon "<< endl;
    cout << "0. Quay lai " << endl;
    cin >> option;
    if (option == 1)
    {
        QuanLy::ThemMon();
    }
    else if (option == 0)
    {
        QuanLy::HienThiDanhSach();
        QuanLy();
    }
    
}
void QuanLy::HienThiDanhSach(){
    int stt = 1;
    cout << "======= DANH SACH ============"<< endl;
    cout << "STT   |  ID |   Ten         | Gia" << endl;
    for(auto item : Database)
    {
        cout << stt << "    " << item.getID() << "    " << item.getTen() << "             " << item.getGia() << endl;
        stt++;
    }

}

void QuanLy::SuaMon()
{
    QuanLy::HienThiDanhSach();

    int ID;
    cout << "Nhap ID mon : " ;
    cin >> ID;
    cout << "1. Sua ten " << endl;
    cout << "2. Sua gia " << endl;
    cout << "0. Quay lai " << endl;

    int luachon;
    cout << "Nhap vao : ";
    cin >> luachon;
    if (luachon == 1){
        for (auto item : Database){
            if(item.getID() == ID)
            {
                string ten_moi;
                cout << "Nhap ten thay doi : ";
                cin >> ten_moi;
                item.setTen(ten_moi);
                cout << "Ban da thay doi thanh cong "<< endl;
                QuanLy::HienThiDanhSach();
                QuanLy();

            }
        }
    }
    else if(luachon == 2)
    {
        for (auto item : Database)
        {
            if (item.getID() == ID)
            {
                float gia_moi;
                cout << "Nhap gia thay doi : ";
                cin >> gia_moi;
                item.setGia(gia_moi);
                cout << "Ban da thay doi thanh cong " << endl;
                QuanLy::HienThiDanhSach();
                QuanLy();
            }
        }
    }
    else if(luachon == 0)
    {
        QuanLy();
    }
}
void QuanLy::XoaMon(){
    QuanLy::HienThiDanhSach();
    int ID;
    cout << "Nhap ID : ";
    cin >> ID;
    list<MonAn>::iterator position = Database.begin();

    for (auto item : Database){
        position++;
        if(item.getID() == ID)
        {
            Database.erase(position);
        }
    }
    QuanLy::HienThiDanhSach();
    QuanLy();
}
void QuanLy::ThietLapSoBan()
{
    cout << "========= THIET LAP SO BAN ===========";
    cout << "1. Nhap so ban : ";
    cout << "0. Quay lai " << endl;
    int soBan;
    cout << "Nhap lua chon : ";
    cin >> soBan;
    if (soBan == 1){
        cout << "Nhap so ban : " << endl;
        cin >> soBan ;
        QuanLy();
    }
    else if(soBan == 0){
        QuanLy();
    }
}
int QuanLy::getSoBan(){
    return soBan;
}

class ThongTinBan
{
    private:
       int soBan;
       bool status;
       typedef struct {
            MonAn Mon_An;
            int soLuong;
       }TypeDish;

       list<TypeDish> Database_MonAn;
    public:
        ThongTinBan(int soBan, bool status);
        int getSoBan();
        void setStatus(bool status);
        bool getStatus();
        void DanhSachMon();
        void ThemMon();
        void SuaMon();
        void XoaMon();
        void ThanhToan();
       
       
};
void ThongTinBan::DanhSachMon(){
    float tong_tien = 0;
    cout << "Tong thanh toan : " << endl;
    for (auto item : Database_MonAn){
        tong_tien += item.Mon_An.getGia() * item.soLuong + item.soLuong;
    }

}
void ThongTinBan::ThemMon(){
    MonAn mon;
    int soLuong;
    cout << "So luong : ";
    cin >> soLuong;
    TypeMon MON;
    MON.Mon_An = mon;
    MON.soLuong = soLuong;
    Database_MonAn.push_back(MON);

}

void ThongTinBan::SuaMon(){
    int soLuong;
    int id;
    cout << "Nhap id : ";
    cin >> id;
    for(auto item : Database){
        if (item.Mon_An.getID() == id){
            cout << "Nhap so luong : ";
            cin >> soLuong;
            item.soLuong = soLuong;
        }
    }
}
void ThongTinBan::XoaMon(){
    int id;
    cout <<"Nhap id : ";
    cin >> id;
    auto position = Database_MonAn.begin();
    for (auto item : Database_MonAn){
        if (item.Mon_An.getID() == id){
            Database_MonAn.erase(position);
        }
        position++;
    }
}
int ThongTinBan::getSoBan(){
    return soBan;

}
void ThongTinBan::setStatus(bool status){
    status = status;
}
class NhanVien
{
    private:
       list<MonAn> Database_NhanVien;
       list<ThongTinBan> Database_Ban;
       void themMon();
       void suaMon();
       void xoaMon();
       void thanhToan();
       void luachonBan();
       void danhsachMon();
    public:
       NhanVien(list<MonAn> database, int soBan);
};

NhanVien::NhanVien(list<MonAn> database, int soban)
{
    Database_NhanVien.assign(database.begin(), database.end());
    for (int i = 1; i <= soban; i++)
    {
        ThongTinBan ban(i, false);
        Database_Ban.push_back(ban);
    }
    cout << " =========LUA CHON ===========" << endl;
    cout << " 1. Them mon " << endl;
    cout << " 2. Sua mon " << endl;
    cout << " 3. Xoa mon " << endl;
    cout << " 4. Danh sach mon " << endl;
    cout << " 5. Thanh toan " << endl;
    cout << " 0. Quay lai " << endl;
    cout << "" << endl;
}

void NhanVien::luachonBan(){
    int soBan;
    cout << "Nhap so ban : " ;
    cin >> soBan;
    for(auto item : Database_Ban){
        item.getSoBan() == soBan;
        int key;
        do{
            cout << "Nhap lua chon : ";
            cin >> key;
        }while(key > 5 || key < 0);
        switch(key){
            case 1:
               themMon();
               break;
            case 2:
               suaMon();
               break;
            case 3:
               xoaMon();
               break;
            case 4:
               danhsachMon(); 
               break;
            case 5:
               thanhToanMon(); 
               break;
            default:
               break;
               
        }
    }
}

void NhanVien::themMon(){
    int soBan;
    cout << "Nhap so ban : ";
    cin >> soBan;
    for(auto item : Database_Ban){
        if(item.getSoBan() == soBan)
        {
            item.ThemMon();
        }
    }
}
void NhanVien::suaMon(){
    int soBan;
    cout << "Nhap so ban : ";
    cin >> soBan;
    for (auto item : Database_Ban){
        if (item.getSoBan() == soBan)
        {
            int id;
            cout << "Nhap id mon : ";
            cin >> id;
            item.SuaMon();
        }
    }
}
void NhanVien::xoaMon()
{
    int soBan;
    cout << "Nhap so ban : ";
    cin >> soBan;

    for (auto item : Database_Ban)
    {
        if (item.getSoBan() == soBan)
        {
            item.XoaMon();
        }
    }
}

void NhanVien::thanhToan(){
    int soBan;
    cout <<"Nhap so ban : ";
    cin >> soBan;
    for(auto item : Database_Ban){
        if(item.getSoBan() == soBan)
        {
            item.DanhSachMon(); 
            item.ThanhToan();
        }
    } 
}

int main(int argc, char const *argv[]){

    cout << "========== LUA CHON ===============";
    cout << " 1. Quan Ly " << endl;
    cout << " 2. Nhan vien" << endl;
    cout << " 0. Ket thuc" << endl;
    int key;
    cout << "====================================";
    cout <<"Nhap lua chon : ";
    cin >> key;
    switch ((TypeOptions)key)
    {
    case QUAN_LY:
        QuanLy();
        break;
    case NHAN_VIEN:
        NhanVien();
        break;
    case KET_THUC:
        cout << "Ket thuc chuong trinh ";
        break;
    
    default:
        cout << "Ban da nhap sai "; 
        break;
    }

    return 0;
}
