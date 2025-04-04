#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) 
        return abs(a);
    return GCD(b, a % b);
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

class cPhanSo {
    private:
        int TuSo, MauSo;
    public:
        void RutGon();
        cPhanSo();
        cPhanSo(int Tu, int Mau);
        cPhanSo operator + (cPhanSo);
        cPhanSo operator - (cPhanSo);
        cPhanSo operator * (cPhanSo);
        cPhanSo operator / (cPhanSo);
        bool operator < (cPhanSo);
        bool operator > (cPhanSo);
        int getTuSo() { 
            return TuSo; 
        }
        friend istream &operator >> (istream &, cPhanSo &);
        friend ostream &operator << (ostream &, cPhanSo);
};

cPhanSo::cPhanSo() : TuSo(0), MauSo(1) {}

cPhanSo::cPhanSo(int Tu, int Mau) : TuSo(Tu), MauSo(Mau) {
    RutGon();
}

void cPhanSo::RutGon() {
    int gcd = GCD(TuSo, MauSo);
    TuSo /= gcd;
    MauSo /= gcd;
    if (MauSo < 0) {
        TuSo = -TuSo;
        MauSo = -MauSo;
    }
}

cPhanSo cPhanSo::operator + (cPhanSo x) {
    return cPhanSo(x.TuSo * MauSo + x.MauSo * TuSo, x.MauSo * MauSo);
}

cPhanSo cPhanSo::operator - (cPhanSo x) {
    return cPhanSo(TuSo * x.MauSo - MauSo * x.TuSo, x.MauSo * MauSo);
}

cPhanSo cPhanSo::operator * (cPhanSo x) {
    return cPhanSo(x.TuSo * TuSo, x.MauSo * MauSo);
}

cPhanSo cPhanSo::operator / (cPhanSo x) {
    if (x.TuSo == 0) {
        cout << "Loi: Khong the chia cho 0!";
        return cPhanSo(0, 1);
    }
    return cPhanSo(TuSo * x.MauSo, MauSo * x.TuSo);
}

bool cPhanSo::operator < (cPhanSo x) {
    return TuSo * x.MauSo < MauSo * x.TuSo;
}

bool cPhanSo::operator > (cPhanSo x) {
    return TuSo * x.MauSo > MauSo * x.TuSo;
}

istream &operator >> (istream &in, cPhanSo &x) {
    cout << "Nhap tu so: ";
    in >> x.TuSo;
    do {
        cout << "Nhap mau so (khac 0): ";
        in >> x.MauSo;
        if (x.MauSo == 0) {
            cout << "Loi: Mau so phai khac 0!\n";
        }
    } while (x.MauSo == 0);
    x.RutGon();
    return in;
}

ostream &operator << (ostream &out, cPhanSo x) {
    if (x.TuSo == 0) {
        out << 0;
    } else if (x.MauSo == 1) {
        out << x.TuSo;
    } else {
        out << x.TuSo << " / " << x.MauSo;
    }
    return out;
}

class cDSPhanSo {
    private:
        vector<cPhanSo> DSPhanSo;
    public:
        friend istream &operator >> (istream &, cDSPhanSo &);
        friend ostream &operator << (ostream &, cDSPhanSo);
        cPhanSo TongPs();
        cPhanSo PsLonNhat();
        cPhanSo PsNhoNhat();
        cPhanSo PsCoTuNguyenToLonNhat();
        void SapXepTangDan();
        void SapXepGiamDan();
};

istream &operator >> (istream &in, cDSPhanSo &x) {
    int SoLuong;
    cout << "Nhap so luong phan so: ";
    in >> SoLuong;
    x.DSPhanSo.resize(SoLuong);
    for (int i = 0; i < SoLuong; i++) {
        in >> x.DSPhanSo[i];
    }
    return in;
}

ostream &operator << (ostream &out, cDSPhanSo x) {
    for (cPhanSo Ps : x.DSPhanSo) {
        out << Ps << " ";
    }
    return out;
}

cPhanSo cDSPhanSo::TongPs() {
    cPhanSo Tong(0, 1);
    for (cPhanSo Ps : DSPhanSo) {
        Tong = Tong + Ps;
    }
    return Tong;
}

cPhanSo cDSPhanSo::PsLonNhat() {
    return *max_element(DSPhanSo.begin(), DSPhanSo.end());
}

cPhanSo cDSPhanSo::PsNhoNhat() {
    return *min_element(DSPhanSo.begin(), DSPhanSo.end());
}

cPhanSo cDSPhanSo::PsCoTuNguyenToLonNhat() {
    cPhanSo MaxPs(0, 1);
    for (cPhanSo Ps : DSPhanSo) {
        if (isPrime(Ps.getTuSo()) && (MaxPs.getTuSo() == 0 || Ps > MaxPs)) {
            MaxPs = Ps;
        }
    }
    return MaxPs;
}

void cDSPhanSo::SapXepTangDan() {
    sort(DSPhanSo.begin(), DSPhanSo.end());
}

void cDSPhanSo::SapXepGiamDan() {
    sort(DSPhanSo.rbegin(), DSPhanSo.rend());
}

int main() {
    cDSPhanSo ds;
    cin >> ds;

    cout << "Tong cac phan so: " << ds.TongPs() << endl;

    cout << "Phan so lon nhat: " << ds.PsLonNhat() << endl;

    cout << "Phan so nho nhat: " << ds.PsNhoNhat() << endl;

    cout << "Phan so co tu la so nguyen to lon nhat: " << ds.PsCoTuNguyenToLonNhat() << endl;

    ds.SapXepTangDan();
    cout << "Danh sach tang dan: " << ds << endl;

    ds.SapXepGiamDan();
    cout << "Danh sach giam dan: " << ds << endl;
}
