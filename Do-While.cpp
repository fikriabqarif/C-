#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Deklarasi variabel
    int pilihan, jumlah;
    char ulang;
    double harga, total, diskon;
    string jenis;
    
    do {
        // Tampilan menu
        cout << "\n=== PENJUALAN TIKET KONSER ===" << endl;
        cout << "1. VIP     : Rp1.000.000" << endl;
        cout << "2. Reguler : Rp500.000" << endl;
        cout << "3. Ekonomi : Rp200.000" << endl;
        cout << "=============================" << endl;
        
        // Input pilihan tiket
        do {
            cout << "Pilih jenis tiket (1-3): ";
            cin >> pilihan;
            
            if (pilihan < 1 || pilihan > 3) {
                cout << "Pilihan tidak valid! Silakan pilih 1-3." << endl;
            }
        } while (pilihan < 1 || pilihan > 3);
        
        // Menentukan harga dan jenis tiket
        switch (pilihan) {
            case 1:
                harga = 1000000;
                jenis = "VIP";
                break;
            case 2:
                harga = 500000;
                jenis = "Reguler";
                break;
            case 3:
                harga = 200000;
                jenis = "Ekonomi";
                break;
        }
        
        // Input jumlah tiket
        do {
            cout << "Jumlah tiket yang dibeli: ";
            cin >> jumlah;
            
            if (jumlah <= 0) {
                cout << "Jumlah tiket tidak valid! Minimal 1 tiket." << endl;
            }
        } while (jumlah <= 0);
        
        // Perhitungan
        total = harga * jumlah;
        diskon = (total > 2000000) ? total * 0.1 : 0;
        
        // Tampilkan rincian pembelian
        cout << "\n=== RINCIAN PEMBELIAN ===" << endl;
        cout << "Jenis Tiket    : " << jenis << endl;
        cout << "Harga Tiket    : Rp" << fixed << setprecision(0) << harga << endl;
        cout << "Jumlah Tiket   : " << jumlah << endl;
        cout << "Total Harga    : Rp" << total << endl;
        cout << "Diskon (10%)   : Rp" << diskon << endl;
        cout << "Total Bayar    : Rp" << total - diskon << endl;
        cout << "========================" << endl;
        
        // Tanya apakah ingin membeli lagi
        do {
            cout << "\nApakah Anda ingin membeli lagi? (y/n): ";
            cin >> ulang;
            
            if (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N') {
                cout << "Input tidak valid! Masukkan y atau n." << endl;
            }
        } while (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');
        
    } while (ulang == 'y' || ulang == 'Y');
    
    cout << "\nTerima kasih telah membeli tiket konser kami!" << endl;
    
    return 0;
}
