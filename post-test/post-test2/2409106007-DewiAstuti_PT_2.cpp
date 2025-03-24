#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Struktur Produk
struct Produk {
    string nama;
    string tipe;
    double harga;
    int stok;
};

// Menggunakan vector agar produk bawaan bisa diedit
vector<Produk> perangkatJaringan = {
    {"TP-LINK 2340", "Router", 450000, 2},
    {"Cisco 2901", "Router", 3500000, 5},
    {"MikroTik hAP AC2", "Access Point", 850000, 10}
};

int main() {
    vector<Produk> produkList;
    string username, nim;
    int attempts = 0;
    bool loginSukses = false;

    // Sistem Login
    while (attempts < 3) {
        cout << "Username: ";
        if (attempts == 0) { 
            getline(cin, username);
        } else {
            cin.ignore();
            getline(cin, username);
        }

        cout << "Password: ";
        cin >> nim;
        cin.ignore();

        if (username == "dewi astuti" && nim == "2409106007") {
            cout << "Login berhasil!\n";
            loginSukses = true;
            break;
        } else {
            attempts++;
            cout << "Login gagal! Coba lagi.\n";
        }
    }

    if (!loginSukses) {
        cout << "Anda telah gagal login 3 kali. Program dihentikan.\n";
        return 0;
    }

    while (true) {
        int pilihan;
        cout << "\nMenu:\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Update Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Produk produkBaru;
                cout << "Masukkan Nama Produk: ";
                cin.ignore();
                getline(cin, produkBaru.nama);
                cout << "Masukkan Tipe Produk: ";
                getline(cin, produkBaru.tipe);
                cout << "Masukkan Harga Produk (Rp): ";
                cin >> produkBaru.harga;
                cout << "Masukkan Stok Produk: ";
                cin >> produkBaru.stok;
                produkList.push_back(produkBaru);
                cout << "Produk berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                cout << "\nDaftar Produk:\n";
                cout << left << setw(5) << "No"
                     << setw(20) << "Nama Produk"
                     << setw(20) << "Tipe"
                     << setw(15) << "Harga (Rp)"
                     << setw(10) << "Stok" << endl;
                cout << string(75, '-') << endl;

                int index = 0;

                // Menampilkan produk bawaan
                for (const auto& produk : perangkatJaringan) {
                    cout << left << setw(5) << index++
                         << setw(20) << produk.nama
                         << setw(20) << produk.tipe
                         << setw(15) << fixed << setprecision(0) << produk.harga
                         << setw(10) << produk.stok << endl;
                }

                // Menampilkan produk tambahan
                for (const auto& produk : produkList) {
                    cout << left << setw(5) << index++
                         << setw(20) << produk.nama
                         << setw(20) << produk.tipe
                         << setw(15) << fixed << setprecision(0) << produk.harga
                         << setw(10) << produk.stok << endl;
                }

                break;
            }
            case 3: {
                // Menampilkan produk sebelum update
                cout << "\nDaftar Produk untuk Diperbarui:\n";
                int index = 0;
                for (const auto& produk : perangkatJaringan) {
                    cout << index++ << ". " << produk.nama << " (" << produk.tipe << ")\n";
                }
                for (const auto& produk : produkList) {
                    cout << index++ << ". " << produk.nama << " (" << produk.tipe << ")\n";
                }

                // User memilih produk untuk diupdate
                cout << "Masukkan nomor produk yang ingin diupdate: ";
                int pilihIndex;
                cin >> pilihIndex;
                cin.ignore();

                // Validasi index
                if (pilihIndex >= 0 && pilihIndex < perangkatJaringan.size()) {
                    cout << "Masukkan Nama Produk baru: ";
                    getline(cin, perangkatJaringan[pilihIndex].nama);
                    cout << "Masukkan Tipe Produk baru: ";
                    getline(cin, perangkatJaringan[pilihIndex].tipe);
                    cout << "Masukkan Harga Produk baru (Rp): ";
                    cin >> perangkatJaringan[pilihIndex].harga;
                    cout << "Masukkan Stok Produk baru: ";
                    cin >> perangkatJaringan[pilihIndex].stok;
                    cout << "Produk bawaan berhasil diupdate!\n";
                } else 
                if (pilihIndex >= perangkatJaringan.size() && pilihIndex < perangkatJaringan.size() + produkList.size()) {
                    int produkIndex = pilihIndex - perangkatJaringan.size();
                    cout << "Masukkan Nama Produk baru: ";
                    getline(cin, produkList[produkIndex].nama);
                    cout << "Masukkan Tipe Produk baru: ";
                    getline(cin, produkList[produkIndex].tipe);
                    cout << "Masukkan Harga Produk baru (Rp): ";
                    cin >> produkList[produkIndex].harga;
                    cout << "Masukkan Stok Produk baru: ";
                    cin >> produkList[produkIndex].stok;
                    cout << "Produk tambahan berhasil diupdate!\n";
                } else {
                    cout << "Index tidak valid!\n";
                }
                break;
            }
            case 4: {
                cout << "Masukkan nomor produk yang ingin dihapus: ";
                int index;
                cin >> index;

                if (index >= 0 && index < perangkatJaringan.size()) {
                    perangkatJaringan.erase(perangkatJaringan.begin() + index);
                    cout << "Produk bawaan berhasil dihapus!\n";
                } else if (index >= perangkatJaringan.size() && index < perangkatJaringan.size() + produkList.size()) {
                    produkList.erase(produkList.begin() + (index - perangkatJaringan.size()));
                    cout << "Produk tambahan berhasil dihapus!\n";
                } else {
                    cout << "Index tidak valid!\n";
                }
                break;
            }
            case 5: {
                char konfirmasi;
                cout << "Apakah Anda yakin ingin keluar? (y/n): ";
                cin >> konfirmasi;
                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    cout << "Terima kasih! Program selesai.\n";
                    return 0;
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}
