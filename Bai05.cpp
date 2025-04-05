#include <bits/stdc++.h>
using namespace std;

class cDaThuc {
    private:
        int *HeSo, Bac;
    public:
        cDaThuc();
        ~cDaThuc();
        void NhapDaThuc();
        void XuatDaThuc();
        int GiaTriDaThuc(int);
        cDaThuc CongDaThuc(cDaThuc);
        cDaThuc TruDaThuc(cDaThuc);
};

cDaThuc::cDaThuc() {
    HeSo = nullptr;
    Bac = 0;
}

cDaThuc::~cDaThuc() {
    if (HeSo != nullptr) delete[] HeSo;
}

void cDaThuc::NhapDaThuc() {
    cout << "Nhap bac da thuc: ";
    cin >> Bac;
    HeSo = new int[Bac + 1];
    for (int i = Bac; i >= 0; i--) {
        cin >> HeSo[i];
    }
}

void cDaThuc::XuatDaThuc() {
    for (int i = Bac; i >= 0; i--) {
        if (HeSo[i] == 0) {
            continue;
        }
        if (i < Bac && HeSo[i] > 0) {
            cout << " + ";
        } else if (HeSo[i] < 0) {
            cout << " - ";
        }
        if (abs(HeSo[i]) != 1 || i == 0) {
            cout << abs(HeSo[i]);
        }
        if (i > 0) {
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }
    }
}

int cDaThuc::GiaTriDaThuc(int x) {
    int GiaTri = 0;
    for (int i = Bac; i >= 0; i--) {
        GiaTri += HeSo[i]*pow(x, i);
    }
    return GiaTri;
}

cDaThuc cDaThuc::CongDaThuc(cDaThuc f) {
    cDaThuc KetQua;
    KetQua.Bac = max(Bac, f.Bac);
    KetQua.HeSo = new int[KetQua.Bac + 1]{0};
    for (int i = Bac; i >= 0; i--) {
        KetQua.HeSo[i] += HeSo[i];
    }
    for (int j = f.Bac; j >= 0; j--) {
        KetQua.HeSo[j] += f.HeSo[j];
    }
    return KetQua;
}

cDaThuc cDaThuc::TruDaThuc(cDaThuc f) {
    cDaThuc KetQua;
    KetQua.Bac = max(Bac, f.Bac); 
    KetQua.HeSo = new int[KetQua.Bac + 1]{0};
    for (int i = 0; i <= KetQua.Bac; i++) {
        int heSo1 = (i <= f.Bac) ? f.HeSo[i] : 0; 
        int heSo2 = (i <= Bac) ? HeSo[i] : 0;     
        KetQua.HeSo[i] = heSo1 - heSo2;          
    }
    while (KetQua.Bac > 0 && KetQua.HeSo[KetQua.Bac] == 0) {
        KetQua.Bac--;
    }
    return KetQua;
}

int main() {
    cDaThuc daThuc1, daThuc2;

    cout << "=== NHAP DA THUC THU NHAT ===\n";
    daThuc1.NhapDaThuc();

    cout << "\n=== NHAP DA THUC THU HAI ===\n";
    daThuc2.NhapDaThuc();

    cout << "\n--- DA THUC THU NHAT: ";
    daThuc1.XuatDaThuc(); cout << endl;

    cout << "--- DA THUC THU HAI: ";
    daThuc2.XuatDaThuc(); cout << endl;

    cout << "\n>>> TONG HAI DA THUC: ";
    daThuc1.CongDaThuc(daThuc2).XuatDaThuc(); cout << endl;

    cout << ">>> HIEU (DA THUC 1 - DA THUC 2): ";
    daThuc1.TruDaThuc(daThuc2).XuatDaThuc(); cout << endl;

    int x;
    cout << "\nNhap gia tri x de tinh gia tri cua da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << daThuc1.GiaTriDaThuc(x) << endl;

    return 0;
}