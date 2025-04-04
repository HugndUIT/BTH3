#include <bits/stdc++.h>
using namespace std;

class cCandidate {
    private:
        string Ma, Ten, NgaySinh;
        double DiemToan, DiemVan, DiemAnh;
    public:
        cCandidate();
        ~cCandidate();
        friend istream& operator >> (istream &, cCandidate &);
        friend ostream& operator << (ostream &, cCandidate);
        double TongDiem();
        friend class cListCandidate;
};

cCandidate::cCandidate() {
    Ma = Ten = NgaySinh = "";
    DiemToan = DiemVan = DiemAnh = 0;
}

cCandidate::~cCandidate() {}

istream& operator >> (istream &in, cCandidate &x) {
    cout << "Nhap ma: ";
    getline(in, x.Ma);
    cout << "Nhap ten: ";
    getline(in, x.Ten);
    cout << "Nhap ngay sinh: ";
    getline(in, x.NgaySinh);
    cout << "Nhap diem toan: ";
    in >> x.DiemToan;
    cout << "Nhap diem van: ";
    in >> x.DiemVan;
    cout << "Nhap diem anh: ";
    in >> x.DiemAnh;
    in.ignore();
    return in;
}

ostream& operator << (ostream &out, cCandidate x) {
    out << "Ma: " << x.Ma << endl;
    out << "Ten: " << x.Ten << endl;
    out << "Ngay sinh: " << x.NgaySinh << endl;
    out << "Diem Toan: " << x.DiemToan << endl;
    out << "Diem Van: " << x.DiemVan << endl;
    out << "Diem Anh: " << x.DiemAnh << endl;
    out << "Tong diem: " << x.TongDiem() << endl;
    return out;
}

double cCandidate::TongDiem() {
    return DiemAnh + DiemToan + DiemVan;
}

class cListCandidate {
    private:
        vector<cCandidate*> DSThiSinh;
    public:
        friend istream& operator >> (istream &, cListCandidate &);
        friend ostream& operator << (ostream &, cListCandidate);
        ~cListCandidate();
};

istream& operator >> (istream &in, cListCandidate &x) {
    int SoLuong;
    cout << "Nhap so luong thi sinh: ";
    in >> SoLuong;
    in.ignore();
    for (int i = 0; i < SoLuong; i++) {
        cCandidate* Temp = new cCandidate;
        in >> *Temp;
        x.DSThiSinh.push_back(Temp);
    }
    return in;
}

ostream& operator << (ostream &out, cListCandidate x) {
    out << "\n--- DANH SACH THI SINH TONG DIEM LON HON 15 ---\n";
    for (size_t i = 0; i < x.DSThiSinh.size(); i++) {
        if (x.DSThiSinh[i]->TongDiem() > 15) {
            out << *x.DSThiSinh[i];
        }
    }
    out << "\n--- THI SINH TONG DIEM CAO NHAT ---\n";
    double MaxDiem = -1;
    vector<cCandidate*> TopThiSinh;
    for (cCandidate* ts : x.DSThiSinh) {
        if (ts->TongDiem() > MaxDiem) {
            MaxDiem = ts->TongDiem();
            TopThiSinh.clear();
            TopThiSinh.push_back(ts);
        } else if (ts->TongDiem() == MaxDiem) {
            TopThiSinh.push_back(ts);
        }
    }
    for (cCandidate* ts : TopThiSinh) {
        out << *ts;
    }
    sort(x.DSThiSinh.begin(), x.DSThiSinh.end(), [](cCandidate* x, cCandidate *y){
        return x->TongDiem() < y->TongDiem();
    });
    out << "\n--- DANH SACH THI SINH GIAM DAN THEO TONG DIEM ---\n";
    for (size_t i = 0; i < x.DSThiSinh.size(); i++) {
        out << "\nThi sinh thu " << i + 1 << ":\n";
        out << *x.DSThiSinh[i];
    }
    return out;
}

cListCandidate::~cListCandidate() {
    for (cCandidate* ThiSinh : DSThiSinh) {
        delete ThiSinh;
    }
}

int main() {
    cListCandidate DanhSachThiSinh;
    cin >> DanhSachThiSinh;
    cout << DanhSachThiSinh;   
}