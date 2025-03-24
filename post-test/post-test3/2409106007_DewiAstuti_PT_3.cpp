#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_PRODUK 100
#define MAX_PENGGUNA 10

struct Pengguna {
    string Nama;
    string Nim;
};

struct Produk {
    string nama;
    string tipe;
    int harga;
    int stok;
};

Pengguna daftarPengguna[MAX_PENGGUNA];
int jumlahPengguna = 0; 

Produk daftarProduk[MAX_PRODUK] = {
    {"TP-LINK 2340", "Router", 450000, 2},
    {"Cisco 2901", "Router", 3500000, 5},
    {"MikroTik hAP AC2", "Access Point", 850000, 10}
};


int jumlahProduk = 3; 
int main() {
    int pilihan, loginIndex = -1; 
    do {
        cout << "\nMenu Login:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (jumlahPengguna >= MAX_PENGGUNA) {
                cout << "Registrasi penuh, tidak bisa menambah pengguna lagi!\n";
                continue;
            }
            cout << "Masukkan Nama: ";
            getline(cin, daftarPengguna[jumlahPengguna].Nama);
            cout << "Masukkan Nim: ";
            getline(cin, daftarPengguna[jumlahPengguna].Nim);
            jumlahPengguna++;
            cout << "Registrasi berhasil! Silakan login.\n";

        } else if (pilihan == 2) {
            string Nama, Nim;
            int attempts = 0;
            while (attempts < 3) {
                cout << "Masukkan Username: ";
                getline(cin, Nama);
                cout << "Masukkan Password: ";
                getline(cin, Nim);

                for (int i = 0; i < jumlahPengguna; i++) {
                    if (daftarPengguna[i].Nama == Nama && daftarPengguna[i].Nim == Nim) {
                        loginIndex = i;
                        cout << "Login berhasil! Selamat datang, " << daftarPengguna[i].Nama << ".\n";
                        break;
                    }
                }
                if (loginIndex != -1) break; 
                attempts++;
                cout << "Login gagal! Coba lagi.\n";
            }
            if (loginIndex == -1) {
                cout << "Anda telah gagal login 3 kali. Kembali ke menu utama.\n";
                continue;
            }

            do {
                cout << "\nMenu Utama:\n";
                cout << "1. Tambah Produk\n";
                cout << "2. Tampilkan Produk\n";
                cout << "3. Update Produk\n";
                cout << "4. Hapus Produk\n";
                cout << "5. Logout\n";
                cout << "Pilih menu: ";
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    if (jumlahProduk >= MAX_PRODUK) {
                        cout << "Data produk penuh, tidak bisa menambahkan lagi!\n";
                        continue;
                    }

                    cout << "Masukkan Nama Produk: ";
                    getline(cin, daftarProduk[jumlahProduk].nama);
                    cout << "Masukkan Tipe Produk: ";
                    getline(cin, daftarProduk[jumlahProduk].tipe);
                    cout << "Masukkan Harga Produk (Rp): ";
                    cin >> daftarProduk[jumlahProduk].harga;
                    cout << "Masukkan Stok Produk: ";
                    cin >> daftarProduk[jumlahProduk].stok;
                    cin.ignore(); 

                    jumlahProduk++; 
                    cout << "Produk berhasil ditambahkan!\n";

                } else if (pilihan == 2) {
                    cout << "\nDaftar Produk:\n";
                    cout << left << setw(5) << "No"
                         << setw(20) << "Nama Produk"
                         << setw(20) << "Tipe"
                         << setw(15) << "Harga (Rp)"
                         << setw(10) << "Stok" << endl;
                    cout << string(70, '-') << endl;

                    for (int i = 0; i < jumlahProduk; i++) {
                        cout << left << setw(5) << i
                             << setw(20) << daftarProduk[i].nama
                             << setw(20) << daftarProduk[i].tipe
                             << setw(15) << daftarProduk[i].harga
                             << setw(10) << daftarProduk[i].stok << endl;
                    }

                } else if (pilihan == 3) {
                    cout << "Masukkan nomor produk yang ingin diupdate: ";
                    int index;
                    cin >> index;
                    cin.ignore();

                    if (index >= 0 && index < jumlahProduk) {
                        cout << "Masukkan Nama Produk baru: ";
                        getline(cin, daftarProduk[index].nama);
                        cout << "Masukkan Tipe Produk baru: ";
                        getline(cin, daftarProduk[index].tipe);
                        cout << "Masukkan Harga Produk baru (Rp): ";
                        cin >> daftarProduk[index].harga;
                        cout << "Masukkan Stok Produk baru: ";
                        cin >> daftarProduk[index].stok;
                        cout << "Produk berhasil diupdate!\n";
                    } else {
                        cout << "Index tidak valid!\n";
                    }

                } else if (pilihan == 4) {
                    cout << "Masukkan nomor produk yang ingin dihapus: ";
                    int index;
                    cin >> index;

                    if (index >= 0 && index < jumlahProduk) {
                        for (int i = index; i < jumlahProduk - 1; i++) {
                            daftarProduk[i] = daftarProduk[i + 1];
                        }
                        jumlahProduk--;
                        cout << "Produk berhasil dihapus!\n";
                    } else {
                        cout << "Index tidak valid!\n";
                    }

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
