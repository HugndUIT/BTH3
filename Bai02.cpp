#include <bits/stdc++.h>
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
    void Xoay(float);
    float getx() { return x; }
    float gety() { return y; }
    friend class cTamGiac;
};

cDiem::cDiem() { x = y = 0; }
cDiem::cDiem(float a, float b) { x = a; y = b; }

void cDiem::Nhap() {
    cout << "Nhap x: "; cin >> x;
    cout << "Nhap y: "; cin >> y;
}

void cDiem::Xuat() {
    cout << "(" << x << ", " << y << ") ";
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

void cDiem::Xoay(float theta) {
    float radian = theta * M_PI / 180.0;
    float newX = x * cos(radian) - y * sin(radian);
    float newY = x * sin(radian) + y * cos(radian);
    x = newX;
    y = newY;
}

class cDaGiac {
private:
    vector<cDiem> DSDiem;
public:
    void Nhap();
    void Xuat();
    float ChuVi();
    float DienTich();
    void TinhTien(float, float);
    void PhongTo(float);
    void ThuNho(float);
    void Xoay(float);
};

void cDaGiac::Nhap() {
    int SoLuong;
    cout << "Nhap so luong diem: ";
    cin >> SoLuong;
    for (int i = 0; i < SoLuong; i++) {
        cDiem Temp;
        cout << "Diem thu " << i + 1 << ":\n";
        Temp.Nhap();
        DSDiem.push_back(Temp);
    }
}

void cDaGiac::Xuat() {
    cout << "Toa do cac dinh cua da giac: ";
    for (cDiem Index : DSDiem) {
        Index.Xuat();
    }
    cout << endl;
}

float cDaGiac::ChuVi() {
    float CV = 0;
    for (size_t i = 0; i < DSDiem.size(); i++) {
        CV += DSDiem[i].KhoangCach(DSDiem[(i + 1) % DSDiem.size()]);
    }
    return CV;
}

float cDaGiac::DienTich() {
    float DT = 0;
    for (size_t i = 0; i < DSDiem.size(); i++) {
        int j = (i + 1) % DSDiem.size();
        DT += (DSDiem[i].getx() * DSDiem[j].gety()) - (DSDiem[j].getx() * DSDiem[i].gety());
    }
    return 0.5 * abs(DT);
}

void cDaGiac::TinhTien(float dx, float dy) {
    for (auto &d : DSDiem) {
        d.TinhTien(dx, dy);
    }
}

void cDaGiac::PhongTo(float k) {
    for (auto &d : DSDiem) {
        d.PhongTo(k);
    }
}

void cDaGiac::ThuNho(float k) {
    if (k == 0) return;
    for (auto &d : DSDiem) {
        d.ThuNho(k);
    }
}

void cDaGiac::Xoay(float goc) {
    for (auto &d : DSDiem) {
        d.Xoay(goc);
    }
}

int main() {
    cDaGiac daGiac;
    int choice;
    float dx, dy, k, goc;
    do {
        cout << "1. Nhap da giac\n";
        cout << "2. Xuat da giac\n";
        cout << "3. Tinh chu vi\n";
        cout << "4. Tinh dien tich\n";
        cout << "5. Tinh tien\n";
        cout << "6. Phong to\n";
        cout << "7. Thu nho\n";
        cout << "8. Xoay\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
            case 1:
                daGiac.Nhap();
                break;
            case 2:
                daGiac.Xuat();
                break;
            case 3:
                cout << "Chu vi da giac: " << daGiac.ChuVi() << endl;
                break;
            case 4:
                cout << "Dien tich da giac: " << daGiac.DienTich() << endl;
                break;
            case 5:
                cout << "Nhap dx, dy: ";
                cin >> dx >> dy;
                daGiac.TinhTien(dx, dy);
                break;
            case 6:
                cout << "Nhap he so phong to k: ";
                cin >> k;
                daGiac.PhongTo(k);
                break;
            case 7:
                cout << "Nhap he so thu nho k: ";
                cin >> k;
                daGiac.ThuNho(k);
                break;
            case 8:
                cout << "Nhap goc xoay (do): ";
                cin >> goc;
                daGiac.Xoay(goc);
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}