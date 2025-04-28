#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>  

using namespace std;

#define MAX_PRODUK 100
#define MAX_PENGGUNA 10

struct Profil {
    string Nama;
    string Nim;
};

struct Pengguna {
    Profil profil;
};

struct Produk {
    string kode;
    string nama;
    string tipe;
    int harga;
    int stok;
};

Pengguna daftarPengguna[MAX_PENGGUNA];
int jumlahPengguna = 0;

Produk daftarProduk[MAX_PRODUK] = {
    {"P001", "TP-LINK 2340", "Router", 450000, 2},
    {"P002", "Cisco 2901", "Router", 3500000, 5},
    {"P003", "MikroTik hAP AC2", "Access Point", 850000, 10}
};

int jumlahProduk = 3;

bool urutkanNama(Produk a, Produk b) {
    return a.nama < b.nama;
}

bool urutkanHarga(Produk a, Produk b) {
    return a.harga > b.harga;
}

bool urutkanStok(Produk a, Produk b) {
    return a.stok > b.stok;
}

void tampilkanProduk(Produk* arr, int n, int &total) {
    if (n == 0) return; 
    cout << left << setw(5) << "No"
         << setw(10) << "Kode"
         << setw(20) << "Nama Produk"
         << setw(20) << "Tipe"
         << setw(15) << "Harga (Rp)"
         << setw(10) << "Stok"
         << setw(20) << "Alamat Pointer" << endl;
    cout << string(120, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i
             << setw(10) << arr[i].kode
             << setw(20) << arr[i].nama
             << setw(20) << arr[i].tipe
             << setw(15) << arr[i].harga
             << setw(10) << arr[i].stok
             << setw(20) << &arr[i] << endl;  
        total += arr[i].stok;
    }
}

void registrasi(Pengguna* daftar, int &jumlah) {
    if (jumlah >= MAX_PENGGUNA) {
        cout << "Registrasi penuh, tidak bisa menambah pengguna lagi!\n";
        return;
    }
    cout << "Masukkan Nama: ";
    getline(cin, daftar[jumlah].profil.Nama);
    cout << "Masukkan Nim: ";
    getline(cin, daftar[jumlah].profil.Nim);
    jumlah++;
    cout << "Registrasi berhasil! Silakan login.\n";
    cout << string(30, '-') << endl;
}

int login(Pengguna* daftar, int jumlah) {
    string Nama, Nim;
    int attempts = 0;
    while (attempts < 3) {
        cout << "Masukkan Username: ";
        getline(cin, Nama);
        cout << "Masukkan Password: ";
        getline(cin, Nim);

        for (int i = 0; i < jumlah; i++) {
            if (daftar[i].profil.Nama == Nama && daftar[i].profil.Nim == Nim) {
                cout << "Login berhasil! Selamat datang, " << daftar[i].profil.Nama << ".\n";
                cout << string(30, '-') << endl;
                return i;
            }
        }
        attempts++;
        cout << "Login gagal! Coba lagi.\n";
    }
    cout << "Anda telah gagal login 3 kali. Kembali ke menu utama.\n";
    return -1;
}

void tambahProduk(Produk* daftar, int &jumlah) {
    if (jumlah >= MAX_PRODUK) {
        cout << "Data produk penuh, tidak bisa menambahkan lagi!\n";
        return;
    }

    cout << "Masukkan Kode Produk : ";
    getline(cin, daftar[jumlah].kode);
    cout << "Masukkan Nama Produk : ";
    getline(cin, daftar[jumlah].nama);
    cout << "Masukkan Tipe Produk : ";
    getline(cin, daftar[jumlah].tipe);
    cout << "Masukkan Harga Produk (Rp): ";
    cin >> daftar[jumlah].harga;
    cout << "Masukkan Stok Produk : ";
    cin >> daftar[jumlah].stok;
    cin.ignore();

    jumlah++;
    cout << "Produk berhasil ditambahkan!\n";
    cout << string(30, '-') << endl;
}

void tampilkanProduk(Produk* arr, int n) {
    int pilihanSort;
    cout << "\nTampilkan Produk Berdasarkan:\n";
    cout << "| 1 | Nama Produk A-Z\n";
    cout << "| 2 | Harga Produk (Tertinggi ke Terendah)\n";
    cout << "| 3 | Stok Produk (Terbanyak ke Tersedikit)\n";
    cout << "| 4 | Kembali ke Menu Utama\n";
    cout << "Pilih opsi untuk sortir: ";
    cin >> pilihanSort;
    cin.ignore();

    
    switch (pilihanSort) {
        case 1:
            sort(arr, arr + n, urutkanNama);
            break;
        case 2:
            sort(arr, arr + n, urutkanHarga);
            break;
        case 3:
            sort(arr, arr + n, urutkanStok);
            break;
        case 4:
            return;  
        default:
            cout << "Opsi tidak valid!\n";
            return;
    }

    cout << "\nDaftar Produk:\n";
    int total = 0;
    tampilkanProduk(arr, n, total);  

    cout << "\nTotal seluruh stok produk: " << total << " unit\n";
    cout << string(30, '-') << endl;
}

void updateProduk(Produk* daftar, int jumlah) {
    cout << "Masukkan nomor produk yang ingin diupdate: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index >= 0 && index < jumlah) {
        cout << "Masukkan Kode Produk baru : ";
        getline(cin, daftar[index].kode);
        cout << "Masukkan Nama Produk baru : ";
        getline(cin, daftar[index].nama);
        cout << "Masukkan Tipe Produk baru : ";
        getline(cin, daftar[index].tipe);
        cout << "Masukkan Harga Produk baru (Rp): ";
        cin >> daftar[index].harga;
        cout << "Masukkan Stok Produk baru : ";
        cin >> daftar[index].stok;
        cin.ignore();
        cout << "Produk berhasil diupdate!\n";
    } else {
        cout << "Index tidak valid!\n";
    }
    cout << string(30, '-') << endl;
}

void hapusProduk(Produk* daftar, int &jumlah) {
    cout << "Masukkan nomor produk yang ingin dihapus: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index >= 0 && index < jumlah) {
        for (int i = index; i < jumlah - 1; i++) {
            daftar[i] = daftar[i + 1];
        }
        jumlah--;
        cout << "Produk berhasil dihapus!\n";
    } else {
        cout << "Index tidak valid!\n";
    }
    cout << string(30, '-') << endl;
}

int main() {
    int pilihan, loginIndex = -1;

    do {
        cout << "============================" << endl;
        cout << "|    Menu Login            |" << endl;
        cout << "============================" << endl;
        cout << "| 1 | Register             |" << endl;
        cout << "| 2 | Login                |" << endl;
        cout << "| 3 | Keluar               |" << endl;
        cout << "============================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            registrasi(daftarPengguna, jumlahPengguna);
        } else if (pilihan == 2) {
            loginIndex = login(daftarPengguna, jumlahPengguna);
            if (loginIndex == -1) continue;

            do {
                cout << "============================" << endl;
                cout << "|        Menu Utama         |" << endl;
                cout << "============================" << endl;
                cout << "| 1 | Tambah Produk           |" << endl;
                cout << "| 2 | Tampilkan Produk        |" << endl;
                cout << "| 3 | Update Produk           |" << endl;
                cout << "| 4 | Hapus Produk            |" << endl;
                cout << "| 5 | Logout                  |" << endl;
                cout << "===============================" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    tambahProduk(daftarProduk, jumlahProduk);
                } else if (pilihan == 2) {
                    tampilkanProduk(daftarProduk, jumlahProduk);
                } else if (pilihan == 3) {
                    updateProduk(daftarProduk, jumlahProduk);
                } else if (pilihan == 4) {
                    hapusProduk(daftarProduk, jumlahProduk);
                } else if (pilihan == 5) {
                    cout << "Logout berhasil. Kembali ke menu utama.\n";
                    loginIndex = -1;
                    break;
                }
            } while (true);
        }
    } while (pilihan != 3);

    cout << "Terima kasih! Program selesai.\n";
    return 0;
}