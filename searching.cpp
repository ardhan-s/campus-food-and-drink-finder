#include <iostream>
#include "searching.hpp"
#include "menu.hpp"
using namespace std;

void searchByID(const Menu daftar[], int jumlahData, int targetID){
    for ( int i = 0; i < jumlahData; i++ ) {
        if ( daftar[i].id == targetID ) {
            cout << "Menu ditemukan: " << endl;
            cout << "ID: " << daftar[i].id << endl;
            cout << "Nama: " << daftar[i].nama << endl;
            cout << "Kategori: " << daftar[i].kategori << endl;
            cout << "Harga: " << daftar[i].harga << endl;
            cout << "Rating: " << daftar[i].rating << endl;
            return;
        }
    }
    cout << "Menu tidak ditemukan." << endl;
}

void searchByNama(const Menu daftar[], int jumlahData, string keyword){
    bool found = false;
    for ( int i = 0; i < jumlahData; i++ ) {
        if ( daftar[i].nama.find(keyword) != string::npos ) {
            if (!found) {
                cout << "Menu ditemukan: " << endl;
            }
            cout << "ID: " << daftar[i].id << endl;
            cout << "Nama: " << daftar[i].nama << endl;
            cout << "Kategori: " << daftar[i].kategori << endl;
            cout << "Harga: " << daftar[i].harga << endl;
            cout << "Rating: " << daftar[i].rating << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Menu tidak ditemukan." << endl;
    }
}

void searchByKategori(const Menu daftar[], int jumlahData, string kategori) {
    if (jumlahData == 0) {
        cout << "Belum ada data.\n";
        return;
    }

    bool found = false;
    for (int i = 0; i < jumlahData; i++) {
        if (daftar[i].kategori == kategori) {
            if (!found) {
                cout << "ID\tNama\t\tKategori\tHarga\tRating\tLabel\n";
            }
            cout << daftar[i].id << "\t" << daftar[i].nama << "\t" << daftar[i].kategori << "\t\t" << daftar[i].harga << "\t" << daftar[i].rating << "\t" << getPriceLabel(daftar[i].harga) << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Menu tidak ditemukan.\n";
    }
}

void filterByBudget(const Menu daftar[], int jumlahData, int maxBudget){
    bool found = false;
    for ( int i = 0; i < jumlahData; i++ ) {
        if ( daftar[i].harga <= maxBudget ) {
            if (!found) {
                cout << "Menu ditemukan: " << endl;
            }
            cout << daftar[i].id << "\t" << daftar[i].nama << "\t" << daftar[i].kategori << "\t\t" << daftar[i].harga << "\t" << daftar[i].rating << "\t" << getPriceLabel(daftar[i].harga) << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada menu yang sesuai dengan budget yang ditentukan." << endl;
    }
}