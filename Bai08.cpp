#include <bits/stdc++.h>
using namespace std;

class cNhanVienSX {
    private:
        string MaNV, HoTen, NgaySinh;
        int SoSanPham;
        double DonGia;
    public:
        cNhanVienSX();
        ~cNhanVienSX();
        string getMaNV();
        void setMaNV(string value);
        string getHoTen();
        void setHoTen(string value);
        string getNgaySinh();
        void setNgaySinh(string value);
        int getSoSanPham();
        void setSoSanPham(int value);
        double getDonGia();
        void setDonGia(double value);
        double getLuong(); 
        void Nhap();
        void Xuat();
        friend class cDanhSach;
};

cNhanVienSX::cNhanVienSX() {
    MaNV = "";
    HoTen = "";
    NgaySinh = "";
    SoSanPham = 0;
    DonGia = 0.0;
}

cNhanVienSX::~cNhanVienSX() {}

string cNhanVienSX::getMaNV() { 
    return MaNV; 
}

void cNhanVienSX::setMaNV(string value) { 
    MaNV = value; 
}

string cNhanVienSX::getHoTen() { 
    return HoTen; 
}

void cNhanVienSX::setHoTen(string value) { 
    HoTen = value; 
}

string cNhanVienSX::getNgaySinh() { 
    return NgaySinh; 
}

void cNhanVienSX::setNgaySinh(string value) { 
    NgaySinh = value; 
}

int cNhanVienSX::getSoSanPham() { 
    return SoSanPham; 
}

void cNhanVienSX::setSoSanPham(int value) { 
    SoSanPham = value; 
}

double cNhanVienSX::getDonGia() { 
    return DonGia; 
}

void cNhanVienSX::setDonGia(double value) { 
    DonGia = value; 
}

double cNhanVienSX::getLuong() {
    return SoSanPham * DonGia;
}

void cNhanVienSX::Nhap() {
    cout << "Nhap ma nhan vien: ";
    getline(cin, MaNV);
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap ngay sinh (yyyy/mm/dd): ";
    getline(cin, NgaySinh);
    cout << "Nhap so san pham da gia cong: ";
    cin >> SoSanPham;
    cout << "Nhap don gia moi san pham: ";
    cin >> DonGia;
    cin.ignore();
}

void cNhanVienSX::Xuat() {
    cout << MaNV << " - " << HoTen << " - " << NgaySinh << " - So SP: " << SoSanPham 
         << " - Don gia: " << DonGia << " - Luong: " << getLuong() << " VND\n";
}

class cDanhSach {
    private:
        vector<cNhanVienSX*> DanhSach;
    public:
        void Nhap();
        void Xuat();
        void NVLuongThapNhat();
        double TongLuong();
        void NVCaoTuoiNhat();
        void SapXepLuongTG();
        ~cDanhSach();
};

cDanhSach::~cDanhSach() {
    for (cNhanVienSX *Temp : DanhSach) {
        delete Temp;
    }
}

void cDanhSach::Nhap() {
    cout << "Nhap so luong nhan vien: ";
    int SoLuong;
    cin >> SoLuong;
    cin.ignore();
    for (int i = 0; i < SoLuong; i++) {
        cNhanVienSX *Temp = new cNhanVienSX;
        Temp->Nhap();
        DanhSach.push_back(Temp);
    }
}

void cDanhSach::Xuat() {
    for (cNhanVienSX *Temp : DanhSach) {
        Temp->Xuat();
    }
}

void cDanhSach::NVLuongThapNhat() {
    double MinLuong = DBL_MAX;
    for (cNhanVienSX *Temp : DanhSach) {
        if (Temp->getLuong() < MinLuong) {
            MinLuong = Temp->getLuong();
        }
    }
    cout << "\nNhan vien co luong thap nhat:\n";
    for (cNhanVienSX *Temp : DanhSach) {
        if (Temp->getLuong() == MinLuong) {
            Temp->Xuat();
        }
    }
}

double cDanhSach::TongLuong() {
    double Tong = 0;
    for (cNhanVienSX *Temp : DanhSach) {
        Tong += Temp->getLuong();
    }
    return Tong;
}

void cDanhSach::NVCaoTuoiNhat() {
    cNhanVienSX *NhanVien = DanhSach[0];
    for (cNhanVienSX *Temp : DanhSach) {
        if (Temp->getNgaySinh() < NhanVien->getNgaySinh()) {
            NhanVien = Temp;
        }
    }
    cout << "\nNhan vien co tuoi cao nhat:\n";
    NhanVien->Xuat();
}

void cDanhSach::SapXepLuongTG() {
    sort(DanhSach.begin(), DanhSach.end(), [](cNhanVienSX* x, cNhanVienSX* y){
        return x->getLuong() < y->getLuong();
    });
    cout << "\nDanh sach sau khi sap xep tang dan theo luong:\n";
    Xuat();
}

int main() {
    cDanhSach DanhSach;
    DanhSach.Nhap();
    DanhSach.Xuat();
    DanhSach.NVLuongThapNhat();
    cout << "\nTong luong cong ty phai tra: " << DanhSach.TongLuong() << " VND\n";
    DanhSach.NVCaoTuoiNhat();
    DanhSach.SapXepLuongTG();
}