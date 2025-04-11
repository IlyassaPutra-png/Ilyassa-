// login.h
#ifndef LOGIN_H
#define LOGIN_H

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

extern akun user; // agar bisa diakses dari file lain

void registerAkun();
string login();
string menuLogin();

#endif