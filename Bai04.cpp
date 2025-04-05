#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

bool IsPrime(int Number) {
    if (Number < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(Number); i++) {
        if (Number % i == 0) {
            return false;
        }
    }
    return true;
}

class cArray {
    private:
        int *Arr, Quantity;
    public:
        cArray();
        ~cArray();
        void InputArray();
        void OutputArray();
        void SortAscending();
        void SortDescending();
        void RandomArray(int);
        int CountOccurrences(int);
        int SmallestOddNumber();
        int LargestPrimeNumber();
        bool IsArrayAscending();
};

cArray::cArray() {
    Arr = nullptr;
    Quantity = 0;
}

cArray::~cArray() {
    if (Arr != nullptr) delete[] Arr;
}

void cArray::InputArray() {
    cout << "Nhap so luong phan tu: ";
    cin >> Quantity;
    Arr = new int[Quantity];
    for (int i = 0; i < Quantity; i++) {
        cin >> Arr[i];
    }
}

void cArray::OutputArray() {
    for (int i = 0; i < Quantity; i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

void cArray::SortAscending() {
    for (int i = 0; i < Quantity - 1; i++) {
        for (int j = 0; j < Quantity - i - 1; j++) {
            if (Arr[j] > Arr[j + 1]) {
                swap(Arr[j], Arr[j + 1]);
            }
        }
    }
    OutputArray();
}

void cArray::SortDescending() {
    for (int i = 0; i < Quantity - 1; i++) {
        for (int j = 0; j < Quantity - i - 1; j++) {
            if (Arr[j] < Arr[j + 1]) {
                swap(Arr[j], Arr[j + 1]);
            }
        }
    }
    OutputArray();
}

int cArray::SmallestOddNumber() {
    int OddMin = INT_MAX;
    bool found = false;
    for (int i = 0; i < Quantity; i++) {
        if (Arr[i] % 2 != 0 && Arr[i] < OddMin) {
            OddMin = Arr[i];
            found = true;
        }
    }
    return found ? OddMin : -1;
}

int cArray::LargestPrimeNumber() {
    int PrimeMax = -1;
    for (int i = 0; i < Quantity; i++) {
        if (IsPrime(Arr[i]) && Arr[i] > PrimeMax) {
            PrimeMax = Arr[i];
        }
    }
    return PrimeMax;
}

int cArray::CountOccurrences(int x) {
    int Count = 0;
    for (int i = 0; i < Quantity; i++) {
        if (Arr[i] == x) {
            Count++;
        }
    }
    return Count;
}

bool cArray::IsArrayAscending() {
    for (int i = 0; i < Quantity - 1; i++) {
        if (Arr[i] >= Arr[i + 1]) {
            return false;;
        }
    }
    return true;
}

void cArray::RandomArray(int n) {
    Quantity = n;
    Arr = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        Arr[i] = rand() % 100; 
    }
}

int main() {
    cArray Array;
    int n, x;

    cout << "Nhap so phan tu muon tao: ";
    cin >> n;
    Array.RandomArray(n);

    cout << "Mang sau khi tao ngau nhien: ";
    Array.OutputArray();

    cout << "Nhap gia tri x de dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << Array.CountOccurrences(x) << endl;

    if (Array.IsArrayAscending())
        cout << "Mang tang dan\n";
    else
        cout << "Mang khong tang dan\n";

    cout << "So le nho nhat: " << Array.SmallestOddNumber() << endl;

    cout << "So nguyen to lon nhat: " << Array.LargestPrimeNumber() << endl;

    cout << "Mang sau khi sap xep tang dan: ";
    Array.SortAscending();

    cout << "Mang sau khi sap xep giam dan: ";
    Array.SortDescending();
}