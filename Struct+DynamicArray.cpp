#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan data apel
struct Apel {
    int harga_apel;
    int stok_apel;
};

// Struct untuk menyimpan data toko
struct Toko {
    string nama_toko;
    int jumlah_cabang;
    Apel data_apel; // Nested struct
};

// Function untuk menukar posisi dua toko
void swap(Toko &a, Toko &b) {
    Toko temp = a;
    a = b;
    b = temp;
}

// Function untuk mengurutkan toko berdasarkan harga apel (bubble sort)
void bubbleSort(Toko *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Mengurutkan dari harga termahal ke termurah
            if (arr[j].data_apel.harga_apel < arr[j + 1].data_apel.harga_apel) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah toko: ";
    cin >> n;
    
    // Alokasi memori dinamis
    Toko *daftarToko = new Toko[n];
    
    // Input data toko
    for (int i = 0; i < n; i++) {
        cout << "\nData Toko ke-" << i + 1 << endl;
        cout << "Nama Toko: ";
        cin.ignore();
        getline(cin, daftarToko[i].nama_toko);
        
        cout << "Jumlah Cabang: ";
        cin >> daftarToko[i].jumlah_cabang;
        
        cout << "Harga Apel: ";
        cin >> daftarToko[i].data_apel.harga_apel;
        
        cout << "Stok Apel: ";
        cin >> daftarToko[i].data_apel.stok_apel;
    }
    
    // Mengurutkan toko berdasarkan harga apel
    bubbleSort(daftarToko, n);
    
    // Menampilkan hasil pengurutan
    cout << "\nDaftar Toko Berdasarkan Harga Apel (Termahal ke Termurah):\n";
    for (int i = 0; i < n; i++) {
        cout << "\nToko ke-" << i + 1 << endl;
        cout << "Nama Toko: " << daftarToko[i].nama_toko << endl;
        cout << "Jumlah Cabang: " << daftarToko[i].jumlah_cabang << endl;
        cout << "Harga Apel: " << daftarToko[i].data_apel.harga_apel << endl;
        cout << "Stok Apel: " << daftarToko[i].data_apel.stok_apel << endl;
    }
    
    // Dealokasi memori
    delete[] daftarToko;
    
    return 0;
}
