#include <iostream>
#include <cmath>
using namespace std;

class cDiem {
private:
    float x, y;
public:
    cDiem();
    cDiem(float, float);
    void Nhap();
    void Xuat();
    void TinhTien(float, float);
    void PhongTo(float);
    void ThuNho(float);
    float KhoangCach(cDiem);
    float BinhPhuongKC(cDiem);
    friend class cTamGiac;
};

cDiem::cDiem() { x = y = 0; }
cDiem::cDiem(float a, float b) { x = a; y = b; }

void cDiem::Nhap() {
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
}

void cDiem::Xuat() {
    cout << "(" << x << ", " << y << ")";
}

void cDiem::TinhTien(float dx, float dy) {
    x += dx;
    y += dy;
}

void cDiem::PhongTo(float k) {
    x *= k;
    y *= k;
}

void cDiem::ThuNho(float k) {
    if (k != 0) {
        x /= k;
        y /= k;
    }
}

float cDiem::KhoangCach(cDiem B) {
    return sqrt((x - B.x)*(x - B.x) + (y - B.y)*(y - B.y));
}

float cDiem::BinhPhuongKC(cDiem B) {
    return (x - B.x)*(x - B.x) + (y - B.y)*(y - B.y);
}

class cTamGiac {
private:
    cDiem A, B, C;
public:
    void Nhap();
    void Xuat();
    bool LaTamGiac();
    string LoaiTamGiac();
    float ChuVi();
    float DienTich();
    void TinhTien(float, float);
    void PhongTo(float);
    void ThuNho(float);
};

void cTamGiac::Nhap() {
    cout << "Nhap diem A:\n"; A.Nhap();
    cout << "Nhap diem B:\n"; B.Nhap();
    cout << "Nhap diem C:\n"; C.Nhap();
}

void cTamGiac::Xuat() {
    cout << "Tam giac co 3 dinh:\n";
    cout << "A"; A.Xuat(); cout << "\n";
    cout << "B"; B.Xuat(); cout << "\n";
    cout << "C"; C.Xuat(); cout << "\n";
}

bool cTamGiac::LaTamGiac() {
    float AB = A.KhoangCach(B);
    float BC = B.KhoangCach(C);
    float CA = C.KhoangCach(A);
    return (AB + BC > CA && AB + CA > BC && BC + CA > AB);
}

string cTamGiac::LoaiTamGiac() {
    float AB2 = A.BinhPhuongKC(B);
    float BC2 = B.BinhPhuongKC(C);
    float CA2 = C.BinhPhuongKC(A);
    bool vuong = (AB2 + BC2 == CA2 || AB2 + CA2 == BC2 || BC2 + CA2 == AB2);
    bool can = (AB2 == BC2 || AB2 == CA2 || BC2 == CA2);
    bool deu = (AB2 == BC2 && BC2 == CA2);
    if (deu) return "Tam giac deu";
    if (vuong && can) return "Tam giac vuong can";
    if (vuong) return "Tam giac vuong";
    if (can) return "Tam giac can";
    return "Tam giac thuong";
}

float cTamGiac::ChuVi() {
    return A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A);
}

float cTamGiac::DienTich() {
    float a = A.KhoangCach(B);
    float b = B.KhoangCach(C);
    float c = C.KhoangCach(A);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::TinhTien(float dx, float dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void cTamGiac::PhongTo(float k) {
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}

void cTamGiac::ThuNho(float k) {
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}

int main() {
    cTamGiac tg;
    int chon;
    bool daNhap = false;
    do {
        cout << "\n======= MENU =======\n";
        cout << "1. Nhap tam giac\n";
        cout << "2. Xuat tam giac\n";
        cout << "3. Kiem tra loai tam giac\n";
        cout << "4. Tinh chu vi\n";
        cout << "5. Tinh dien tich\n";
        cout << "6. Tinh tien tam giac\n";
        cout << "7. Phong to tam giac\n";
        cout << "8. Thu nho tam giac\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> chon;
        switch (chon) {
            case 1:
                tg.Nhap();
                if (!tg.LaTamGiac()) {
                    cout << "Khong phai tam giac hop le. Vui long nhap lai!\n";
                    daNhap = false;
                } else {
                    daNhap = true;
                }
                break;
            case 2:
                if (daNhap) tg.Xuat();
                else cout << "Ban chua nhap tam giac!\n";
                break;
            case 3:
                if (daNhap) cout << "Loai tam giac: " << tg.LoaiTamGiac() << endl;
                else cout << "Ban chua nhap tam giac!\n";
                break;
            case 4:
                if (daNhap) cout << "Chu vi: " << tg.ChuVi() << endl;
                else cout << "Ban chua nhap tam giac!\n";
                break;
            case 5:
                if (daNhap) cout << "Dien tich: " << tg.DienTich() << endl;
                else cout << "Ban chua nhap tam giac!\n";
                break;
            case 6:
                if (daNhap) {
                    float dx, dy;
                    cout << "Nhap dx: "; cin >> dx;
                    cout << "Nhap dy: "; cin >> dy;
                    tg.TinhTien(dx, dy);
                    cout << "Da tinh tien tam giac.\n";
                } else cout << "Ban chua nhap tam giac!\n";
                break;
            case 7:
                if (daNhap) {
                    float k;
                    cout << "Nhap he so phong to: ";
                    cin >> k;
                    tg.PhongTo(k);
                    cout << "Da phong to tam giac.\n";
                } else cout << "Ban chua nhap tam giac!\n";
                break;
            case 8:
                if (daNhap) {
                    float k;
                    cout << "Nhap he so thu nho: ";
                    cin >> k;
                    tg.ThuNho(k);
                    cout << "Da thu nho tam giac.\n";
                } else cout << "Ban chua nhap tam giac!\n";
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
}