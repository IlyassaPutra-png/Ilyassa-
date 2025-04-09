#include <iostream>
#include <string>
using namespace std;

struct akun {
    string NIK;
    string nama;
    char jenisKelamin;
    int umur;
    string password;
    bool menerima;
};

akun user;

void registerAkun() {
    cout << "Masukkan NIK: ";
    cin >> user.NIK;
    cout << "Masukkan Nama: ";
    cin >> user.nama;
    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> user.jenisKelamin;
    cout << "Masukkan Umur: ";
    cin >> user.umur;
    cout << "Masukkan Password: ";
    cin >> user.password;

    cout << "\nData berhasil disimpan!" << endl;
}

string login() {
    system("CLS");
    string NIK;
    string password;
    cout << "=== LOGIN ===" << endl;
    cout << "Masukkan NIK untuk login: ";
    cin >> NIK;
    cout << "Masukkan Password: ";
    cin >> password;

    if(NIK == "admin" && password == "admin") {
        return "admin";
    }

    if (user.NIK == NIK && user.password == password) {
        cout << "\nLogin berhasil!" << endl;
        return user.nama;
    } else {
        cout << "\nLogin gagal! NIK atau password salah." << endl;
        return "null";
    }
}

string menuLogin() {
    while(true) {
        system("CLS");
        cout << "=== MENU LOGIN ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        string user;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                user = login();
                if(user != "null") {
                    return user;
                } else {
                    continue;
                }
            case 2:
                registerAkun();
                break;
            case 3:
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
}

void userMenu() {
    system("CLS");
    cout << "=== MENU USER ===" << endl;
    cout << "1. Tampilan antrian" << endl;
    cout << "2. Ambil antrian" << endl;
    cout << "3. Menerima sembako" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            cout << "Tampilan antrian" << endl;
            break;
        case 2:
            cout << "Ambil antrian" << endl;
            break;
        case 0:
            cout << "Keluar dari program" << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
}

void adminMenu() {
    system("CLS"); 
    cout << "=== MENU ADMIN ===" << endl;
    cout << "1. Lihat antrian" << endl;
    cout << "2. Hapus antrian" << endl;
    cout << "3. Cari data warga" << endl;
    cout << "4. Riwayat distribusi" << endl;
    cout << "5. Lihat dan edit stock" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
    int pilihan;
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            cout << "Tambah antrian" << endl;
            break;
        case 2:
            cout << "Hapus antrian" << endl;
            break;
        case 3:
            cout << "Lihat antrian" << endl;
            break;
        case 0:
            cout << "Keluar dari program" << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
}

int main() {
    string user;
    while (true) {
        user = menuLogin();
        if(user == "admin") {
            adminMenu();
        } else {
            userMenu();
        }
    }
    return 0;
}