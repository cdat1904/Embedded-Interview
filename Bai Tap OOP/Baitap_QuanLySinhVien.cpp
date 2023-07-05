#include <iostream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

typedef enum {
    NAM, //Nam
    NU //Nữ
} TypeGioiTinh; // giới tính

typedef enum {
    GIOI, //Giỏi
    KHA, //Khá
    TRUNG_BINH,  //Trung bình
    YEU  //Yếu
} TypeHocLuc; //Học lực

class SinhVien {
private:
    int ID; //ID của sinh viên
    string TEN; //Tên
    TypeGioiTinh GIOI_TINH; //giới tính
    float TOAN; //Điểm toán
    float LI;  //Điểm lí
    float HOA; //Điểm hóa
    float DIEM_TRUNG_BINH;  //Điểm trung bình 3 môn toán, lí, hóa
    TypeHocLuc HOC_LUC; //Học lực

public:
    void ThemSinhVien(); //Nhập sinh viên
    string getTen(); //Lấy tên sinh viên
    int getID(); //Lấy ID
    void setID(int id); //Đặt tên
    float getDiemTB(); //Lấy điểm trung bình
    void getHocLuc(); //Tính điểm trung bình và lấy loại học lực
    void inThongTin(); //In thông tin
    void setTen(string ten);
};

void SinhVien::ThemSinhVien() {
    string ten;
    TypeGioiTinh gioi_tinh;
    float DiemToan;
    float DiemLi;
    float DiemHoa;

    cout << "Ten: ";
    cin >> ten;
    cout << endl;

    cout << "Gioi tinh (0-Nam, 1-Nu): ";
    int gioiTinhInput;
    cin >> gioiTinhInput;
    gioi_tinh = static_cast<TypeGioiTinh>(gioiTinhInput);
    cout << endl;
    
    do{
    cout << "Diem Toan: ";
    cin >> DiemToan;
    cout << endl;
    }while (DiemToan < 0 || DiemToan > 10);

    do{ 
    cout << "Diem Li: ";
    cin >> DiemLi;
    cout << endl;
    }while(DiemLi < 1 || DiemLi > 10);
    
    do{
    cout << "Diem Hoa: ";
    cin >> DiemHoa;
    cout << endl;
    }while(DiemHoa < 1 || DiemHoa > 10);

    TEN = ten;
    GIOI_TINH = gioi_tinh;
    TOAN = DiemToan;
    LI = DiemLi;
    HOA = DiemHoa;

    getHocLuc(); // Tính điểm trung bình
};

string SinhVien::getTen() {
    return TEN;
}

int SinhVien::getID() {
    return ID;
}

void SinhVien::setID(int id) {
    ID = id;
}

void SinhVien::getHocLuc() { 
    DIEM_TRUNG_BINH = (TOAN + LI + HOA) / 3;
    if(DIEM_TRUNG_BINH>=8){
        HOC_LUC = GIOI;
    }
    if((DIEM_TRUNG_BINH>=6.5)&&(DIEM_TRUNG_BINH<8)){
        HOC_LUC = KHA;
    }
    if((DIEM_TRUNG_BINH>=5)&&(DIEM_TRUNG_BINH<6.5)){
        HOC_LUC = TRUNG_BINH;
    }
    if(DIEM_TRUNG_BINH<5){
        HOC_LUC = YEU;
    }
}

float SinhVien::getDiemTB(){
    return DIEM_TRUNG_BINH;
}

void SinhVien::inThongTin() {
    cout << "ID: " << ID << endl;
    cout << "Ten: " << TEN << endl;
    cout << "Gioi tinh: " << (GIOI_TINH == NAM ? "Nam" : "Nu") << endl;
    cout << "Diem Toan: " << TOAN << endl;
    cout << "Diem Li: " << LI << endl;
    cout << "Diem Hoa: " << HOA << endl;
    cout << "Diem trung binh: " << DIEM_TRUNG_BINH << endl;
    cout << "Hoc luc: ";
    switch (HOC_LUC) {
        case GIOI:
            cout << "Gioi" << endl;
            break;
        case KHA:
            cout << "Kha" << endl;
            break;
        case TRUNG_BINH:
            cout << "Trung binh" << endl;
            break;
        case YEU:
            cout << "Yeu" << endl;
            break;
    }
    cout << endl;
}

void SinhVien::setTen(string ten) {
    TEN = ten;
}

class Menu {
    private:
        list<SinhVien> Database;

    public:
        void themSinhVien(SinhVien sv); //Thêm sinh viên
        void CapNhatThongTin(int id); //Cập nhật thông tin sinh viên bởi ID
        void XoaSinhVien(int id); //Xóa sinh viên khỏi Database theo ID
        void TimKiemTheoTen(string ten); //Tìm kiếm sinh viên theo tên
        void SapXepTheoGPA(); //Sắp xếp sinh viên theo điểm trung bình (GPA)
        void SapXepTheoTen(); //Sắp xếp inh viê theo tên
        void HienThiDanhSach(); //Hiển thị danh sách sinh viên
};

void Menu::themSinhVien(SinhVien sv) {
    static int id = 1;
    sv.setID(id);
    id++;
    Database.push_back(sv);
    SinhVien& newStudent = Database.back();
    newStudent.inThongTin();
}

void Menu::CapNhatThongTin(int id) {
    bool found = false;
    for (SinhVien& item : Database) {
        if (item.getID() == id) {
            found = true;
            item.ThemSinhVien();
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ID " << id << endl;
    }
}

void Menu::XoaSinhVien(int id) {
    bool found = false;
    for (auto it = Database.begin(); it != Database.end(); ++it) {
        if (it->getID() == id) {
            found = true;
            Database.erase(it);
            break;
        }
    }
    static int id1 = 1;
    for (SinhVien& sv : Database) {
        sv.setID(id1);
        id1++;
    }
    if (found) {
        cout << "Da xoa sinh vien co ID " << id << endl;
    } else {
        cout << "Khong tim thay sinh vien co ID " << id << endl;
    }
}

void Menu::TimKiemTheoTen(string Ten) {
    bool found = false;
    for (SinhVien& sv : Database) {
        if (sv.getTen() == Ten) {
            found = true;
            sv.inThongTin();
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ten " << Ten << endl;
    }
}


void Menu::SapXepTheoGPA() {
    for (auto it1 = Database.begin(); it1 != Database.end(); ++it1) {
        for (auto it2 = next(it1); it2 != Database.end(); ++it2) {
            if (it1->getDiemTB() < it2->getDiemTB()) {
                iter_swap(it1, it2);
            }
        }
    }
    static int id = 1;
    for (SinhVien& sv : Database) {
        sv.setID(id);
        id++;
    }
    cout << "Da sap xep danh sach sinh vien theo diem trung binh." << endl;
} 

void Menu::SapXepTheoTen() {
    for (auto it1 = next(Database.begin()); it1 != Database.end(); ++it1) {
        auto key = *it1;
        auto it2 = prev(it1);
        while (it2 != Database.begin() && key.getTen() < it2->getTen()) {
            iter_swap(it2, next(it2));
            --it2;
        }
        if (key.getTen() < it2->getTen()) {
            iter_swap(it2, next(it2));
        }
    }
    static int id = 1;
    for (SinhVien& sv : Database) {
        sv.setID(id);
        id++;
    }
     cout << "Da sap xep danh sach sinh vien theo ten." << endl;
}

void Menu::HienThiDanhSach() {
    if (Database.empty()) {
        cout << "DANH SACH SINH VIEN RONG." << endl; //Danh sách sinh viên rỗng
    } else {
        cout << "DANH SACH SINH VIEN: " << endl;
        for (SinhVien& sV : Database) {
            sV.inThongTin();
        }
    }
}

int main() {
    int a=0, b=0;
    SinhVien SV;
    Menu MN;
    while(a==0){
        int LuaChon1, LuaChon2;
        int b=0;

        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin sinh vien boi ID" << endl;
        cout << "3. Xoa sinh vien boi ID" << endl;
        cout << "4. Tim kiem sinh vien theo ten" << endl;
        cout << "5. Sap xep sinh vien theo diem trung binh" <<endl;
        cout << "6. Sap xep sinh vien theo diem ten" <<endl;
        cout << "7. Hien thi danh sach sinh vien" << endl;

        cout << "Nhan: ";
        cin >> LuaChon1;
        cin.ignore();
        cout <<endl;

        while(b==0){
            switch (LuaChon1) {
                case 1: {
                    //SinhVien SV;
                    SV.ThemSinhVien();
                    MN.themSinhVien(SV);
                    LuaChon1 = 1;
                    break;
                }
                case 2: {
                    int id;
                    cout << "Nhap ID sinh vien can cap nhat: ";
                    cin >> id;
                    cout << endl;
                    MN.CapNhatThongTin(id);
                    LuaChon1 = 2;
                    break;
                }
                case 3: {
                    int id;
                    cout << "Nhap ID sinh vien can xoa: ";
                    cin >> id;
                    cout << endl;
                    MN.XoaSinhVien(id);
                    LuaChon1 = 3;
                    break;
                }
                case 4: {
                    string ten;
                    cout << "Nhap ten sinh vien can tim kiem: ";
                    cin >> ten;
                    cout << endl;
                    MN.TimKiemTheoTen(ten);
                    LuaChon1 = 3;
                    break;
                }
                case 5: {
                    MN.SapXepTheoGPA();
                    LuaChon1 = 5;
                    break;
                }
                case 6: {
                    MN.SapXepTheoTen();
                    LuaChon1 = 6;
                    break;
                }
                case 7: {
                    MN.HienThiDanhSach(); 
                    LuaChon1 = 7;
                    break;
                }

            }
            cout<<"0. Tiep tuc"<<endl;
            cout<<"1. Quay lai"<<endl;
            cout<<"Nhan: ";
            cin>>LuaChon2;
            cin.ignore();
            if(LuaChon2==0){
                b=0;
            }
            else if(LuaChon2==1){
                b=1;
            }
            else{
                cout <<"Lua chon khong hop le"<<endl;
                b=1;
            }
        }
    }
    return 0;
}