#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama = "dewi astuti", nim = "2409106007";
    
    cout << "====================================\n";
    cout << "    LOGIN PENGGUNA\n";
    cout << "====================================\n";
    
    string inputNama, inputNIM;
    int percobaanLogin = 0;
    
    while (percobaanLogin < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, inputNama);
        cout << "Masukkan NIM: ";
        getline(cin, inputNIM);
        
        if (inputNama == nama && inputNIM == nim) {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Nama atau NIM salah! Coba lagi.\n";
            percobaanLogin++;
        }
    }
    
    if (percobaanLogin == 3) {
        cout << "Anda telah mencoba 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;
    double nilai;
    
    do {
        cout << "====================================\n";
        cout << "    PROGRAM KONVERSI SATUAN\n";
        cout << "====================================\n";
        cout << "Pilih konversi yang ingin dilakukan:\n";
        cout << "1. Meter ke Centimeter, Mile, Foot\n";
        cout << "2. Centimeter ke Meter, Mile, Foot\n";
        cout << "3. Mile ke Meter, Centimeter, Foot\n";
        cout << "4. Foot ke Meter, Centimeter, Mile\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        
        if (pilihan == 5) break;
        
        cout << "Masukkan nilai: ";
        while (!(cin >> nilai)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Harap masukkan angka: ";
        }
        
        if (pilihan == 1) {
            cout << "Meter: " << nilai << " m\n";
            cout << "Centimeter: " << nilai * 100 << " cm\n";
            cout << "Mile: " << nilai * 0.000621371 << " mi\n";
            cout << "Foot: " << nilai * 3.28084 << " ft\n";
        } else if (pilihan == 2) {
            cout << "Centimeter: " << nilai << " cm\n";
            cout << "Meter: " << nilai / 100 << " m\n";
            cout << "Mile: " << nilai / 160934 << " mi\n";
            cout << "Foot: " << nilai / 30.48 << " ft\n";
        } else if (pilihan == 3) {
            cout << "Mile: " << nilai << " mi\n";
            cout << "Meter: " << nilai * 1609.34 << " m\n";
            cout << "Centimeter: " << nilai * 160934 << " cm\n";
            cout << "Foot: " << nilai * 5280 << " ft\n";
        } else if (pilihan == 4) {
            cout << "Foot: " << nilai << " ft\n";
            cout << "Meter: " << nilai / 3.28084 << " m\n";
            cout << "Centimeter: " << nilai * 30.48 << " cm\n";
            cout << "Mile: " << nilai / 5280 << " mi\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    
    } while (true);
    
    cout << "Program selesai. Terima kasih!\n";
    return 0;
}
