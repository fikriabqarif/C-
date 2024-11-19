#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float nilaiTugas;
    float nilaiUTS;
    float nilaiUAS;
    float rataRata;
    string status;
};

// Function untuk menghitung rata-rata nilai
float hitungRataRata(float tugas, float uts, float uas) {
    return (tugas + uts + uas) / 3;
}

// Function untuk menentukan status kelulusan
string tentukanStatus(float rataRata) {
    return (rataRata > 75) ? "LULUS" : "TIDAK LULUS";
}

int main() {
    vector<Mahasiswa> daftarMahasiswa;
    char pilihan;
    
    do {
        cout << "\n=== PROGRAM PENGELOLAAN DATA MAHASISWA ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa (Rata-rata > 75)\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case '1': {
                Mahasiswa mhs;
                
                cout << "\nMasukkan Data Mahasiswa\n";
                cout << "Nama: ";
                getline(cin, mhs.nama);
                cout << "NIM: ";
                getline(cin, mhs.nim);
                cout << "Nilai Tugas: ";
                cin >> mhs.nilaiTugas;
                cout << "Nilai UTS: ";
                cin >> mhs.nilaiUTS;
                cout << "Nilai UAS: ";
                cin >> mhs.nilaiUAS;
                
                mhs.rataRata = hitungRataRata(mhs.nilaiTugas, mhs.nilaiUTS, mhs.nilaiUAS);
                mhs.status = tentukanStatus(mhs.rataRata);
                
                daftarMahasiswa.push_back(mhs);
                cout << "\nData berhasil ditambahkan!\n";
                break;
            }
            case '2': {
                cout << "\nDaftar Mahasiswa dengan Rata-rata > 75:\n";
                cout << setw(30) << left << "Nama" 
                     << setw(15) << "NIM"
                     << setw(15) << "Rata-rata"
                     << "Status" << endl;
                cout << string(75, '-') << endl;
                
                bool ada = false;
                for(const auto& mhs : daftarMahasiswa) {
                    if(mhs.rataRata > 75) {
                        cout << setw(30) << left << mhs.nama 
                             << setw(15) << mhs.nim
                             << setw(15) << fixed << setprecision(2) << mhs.rataRata
                             << mhs.status << endl;
                        ada = true;
                    }
                }
                
                if(!ada) {
                    cout << "Tidak ada mahasiswa dengan rata-rata > 75\n";
                }
                break;
            }
            case '3':
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
    } while(pilihan != '3');
    
    return 0;
}
