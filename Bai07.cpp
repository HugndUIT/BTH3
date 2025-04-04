#include <bits/stdc++.h>
using namespace std;

class cNhanVienVP {
    private:
        string MaNV, HoTen, NgaySinh;
        double Luong;
    public:
        cNhanVienVP();
        ~cNhanVienVP();
        string getMaNV();
        void setMaNV(string value);
        string getHoTen();
        void setHoTen(string value);
        string getNgaySinh();
        void setNgaySinh(string value);
        double getLuong();
        void setLuong(double value);
        void Nhap();
        void Xuat();
        friend class cDanhSach;
};

cNhanVienVP::cNhanVienVP() {
    MaNV = "";
    HoTen = "";
    NgaySinh = "";
    Luong = 0.0;
}

cNhanVienVP::~cNhanVienVP() {}

string cNhanVienVP::getMaNV() {
    return MaNV;
}

string cNhanVienVP::getHoTen() {
    return HoTen;
}

string cNhanVienVP::getNgaySinh() {
    return NgaySinh;
}

double cNhanVienVP::getLuong() {
    return Luong;
}

void cNhanVienVP::setMaNV(string value) {
    MaNV = value;
}

void cNhanVienVP::setHoTen(string value) {
    HoTen = value;
}

void cNhanVienVP::setNgaySinh(string value) {
    NgaySinh = value;
}

void cNhanVienVP::setLuong(double value) {
    Luong = value;
}

void cNhanVienVP::Nhap() {
    cout << "Nhap ma nhan vien: ";
    getline(cin, MaNV);
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap ngay sinh (yyyy/mm/dd): ";
    getline(cin, NgaySinh);
    cout << "Nhap luong: ";
    cin >> Luong;
    cin.ignore();
}

void cNhanVienVP::Xuat() {
    cout << MaNV << " - " << HoTen << " - " << NgaySinh << " - " << Luong << " VND\n";
}

class cDanhSach {
    private:
        vector<cNhanVienVP*> DanhSach;
    public:
        void Nhap();
        void Xuat();
        void NVLuongCaoNhat();
        double TongLuong();
        void NVCaoTuoiNhat();
        void SapXepLuongTG();
        ~cDanhSach();
};

cDanhSach::~cDanhSach() {
    for (cNhanVienVP *Temp : DanhSach) {
        delete Temp;
    }
}

void cDanhSach::Nhap() {
    cout << "Nhap so luong nhan vien: ";
    int SoLuong;
    cin >> SoLuong;
    cin.ignore();
    for (int i = 0; i < SoLuong; i++) {
        cNhanVienVP *Temp = new cNhanVienVP;
        Temp->Nhap();
        DanhSach.push_back(Temp);
    }
}

void cDanhSach::Xuat() {
    for (cNhanVienVP *Temp : DanhSach) {
        Temp->Xuat();
    }
}

void cDanhSach::NVLuongCaoNhat() {
    double MaxLuong = -1;
    for (cNhanVienVP *Temp : DanhSach) {
        if (Temp->Luong > MaxLuong) {
            MaxLuong = Temp->Luong;
        }
    }
    cout << "\nNhan vien co luong cao nhat:\n";
    for (cNhanVienVP *Temp : DanhSach) {
        if (Temp->Luong == MaxLuong) {
            Temp->Xuat();
        }
    }
}

double cDanhSach::TongLuong() {
    double Tong  = 0;
    for (cNhanVienVP *Temp : DanhSach) {
        Tong += Temp->Luong;
    }
    return Tong;
}

void cDanhSach::NVCaoTuoiNhat() {
    cNhanVienVP *NhanVien = DanhSach[0];
    for (cNhanVienVP *Temp : DanhSach) {
        if (Temp->NgaySinh < NhanVien->NgaySinh) {
            NhanVien = Temp;
        }
    }
    cout << "\nNhan vien co tuoi cao nhat:\n";
    NhanVien->Xuat();
}

void cDanhSach::SapXepLuongTG() {
    sort(DanhSach.begin(), DanhSach.end(), [](cNhanVienVP* x, cNhanVienVP* y){
        return x->Luong < y->Luong;
    });
    cout << "\nDanh sach sau khi sap xep tang dan theo luong:\n";
    Xuat();
}

int main() {
    cDanhSach DanhSach;
    DanhSach.Nhap();
    DanhSach.Xuat();
    DanhSach.NVLuongCaoNhat();
    cout << "\nTong luong cong ty phai tra: " << DanhSach.TongLuong() << " VND\n";
    DanhSach.NVCaoTuoiNhat();
    DanhSach.SapXepLuongTG();
}