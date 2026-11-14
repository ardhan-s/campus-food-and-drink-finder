#include <iostream>
#include <fstream>
#include <iomanip>
#include "struct.hpp"
#include "menu.hpp"
#include "searching.hpp"
#include "sorting.hpp"
#include "recursion.hpp"
using namespace std;

int main() {
    Menu daftarMenu[maxData] = {
        {1, "Nasi Ayam Geprek", "Meal", 15000, 4.8},
        {2, "Es Teh Manis", "Drink", 4000, 4.5},
        {3, "Kopi Susu Gula Aren", "Coffee", 18000, 4.7},
        {4, "Kentang Goreng", "Snack", 12000, 4.3},
        {5, "Steak Ayam Crispy", "Meal", 38000, 4.9}
    };
    int jumlahData = 5;
    
    loadData(daftarMenu, jumlahData);
    saveData(daftarMenu, jumlahData);

    int pilihan;

    do {
        cout << "\n\033[1;36m╔══════════════════════════════════════════════════════╗\033[0m\n";
        cout << "\033[1;36m║           CAMPUS FOOD & DRINK FINDER                 ║\033[0m\n";
        cout << "\033[1;36m╠══════════════════════════════════════════════════════╣\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[1]\033[0m Tambah Menu                                     \033[1;36m║\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[2]\033[0m Tampilkan Semua Menu                            \033[1;36m║\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[3]\033[0m Ringkasan (Rata-rata, Termurah, Termahal)       \033[1;36m║\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[4]\033[0m Urutkan Menu (Harga/Rating)                     \033[1;36m║\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[5]\033[0m Cari Menu (ID/Nama/Kategori)                    \033[1;36m║\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[6]\033[0m Hitung Total Pilihan Menu                       \033[1;36m║\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;33m[7]\033[0m What Can I Eat With My Budget?                  \033[1;36m║\033[0m\n";
        cout << "\033[1;36m╠══════════════════════════════════════════════════════╣\033[0m\n";
        cout << "\033[1;36m║\033[0m  \033[1;31m[0]\033[0m Keluar                                          \033[1;36m║\033[0m\n";
        cout << "\033[1;36m╚══════════════════════════════════════════════════════╝\033[0m\n";
        cout << "\033[1m› Masukkan pilihan Anda: \033[0m";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihan = -1;
        }

        switch (pilihan) {
            case 1:
                cout << "\n\033[1;36m── TAMBAH MENU BARU ────────────────────────────────────\033[0m\n";
                addData(daftarMenu, jumlahData);
                saveData(daftarMenu, jumlahData);
                cout << "\033[1;32m✓ Data berhasil disimpan secara lokal.\033[0m\n";
                break;

            case 2:
                cout << "\n\033[1;36m── DAFTAR SEMUA MENU ───────────────────────────────────\033[0m\n";
                displayData(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 3:
                cout << "\n\033[1;36m── RINGKASAN MENU ──────────────────────────────────────\033[0m\n";
                calculateSummary(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 4: {
                cout << "\n\033[1;36m── URUTKAN MENU ────────────────────────────────────────\033[0m\n";
                string pilihan2;
                cin.ignore(1000, '\n');

                while (true) {
                    cout << "\033[1m› Urutkan berdasarkan (Harga/Rating): \033[0m";
                    getline(cin, pilihan2);

                    if (pilihan2 == "Harga" || pilihan2 == "harga") {
                        while (true) {
                            cout << "\033[1m› Urutan (Ascending/Descending): \033[0m";
                            string pilihan3;
                            getline(cin, pilihan3);

                            if (pilihan3 == "Ascending" || pilihan3 == "ascending") {
                                sortByHarga(daftarMenu, jumlahData, true);
                                break;
                            } else if (pilihan3 == "Descending" || pilihan3 == "descending") {
                                sortByHarga(daftarMenu, jumlahData, false);
                                break;
                            } else {
                                cout << "\033[31m✗ Input tidak sesuai! Ketik Ascending atau Descending.\033[0m\n";
                            }
                        }
                        break;
                    } else if (pilihan2 == "Rating" || pilihan2 == "rating") {
                        while (true) {
                            cout << "\033[1m› Urutan (Ascending/Descending): \033[0m";
                            string pilihan3;
                            getline(cin, pilihan3);

                            if (pilihan3 == "Ascending" || pilihan3 == "ascending") {
                                sortByRating(daftarMenu, jumlahData, true);
                                break;
                            } else if (pilihan3 == "Descending" || pilihan3 == "descending") {
                                sortByRating(daftarMenu, jumlahData, false);
                                break;
                            } else {
                                cout << "\033[31m✗ Input tidak sesuai! Ketik Ascending atau Descending.\033[0m\n";
                            }
                        }
                        break;
                    } else {
                        cout << "\033[31m✗ Input tidak sesuai! Ketik Harga atau Rating.\033[0m\n";
                    }
                }

                cout << "\n\033[1;32m✓ Hasil Pengurutan:\033[0m\n";
                displayData(daftarMenu, jumlahData);
                cout << endl;
                break;
            }

            case 5: {
                cout << "\n\033[1;36m── PENCARIAN MENU ──────────────────────────────────────\033[0m\n";
                string pilihan2;
                cin.ignore(1000, '\n');

                while (true) {
                    cout << "\033[1m› Cari berdasarkan (ID/Nama/Kategori): \033[0m";
                    getline(cin, pilihan2);

                    if (pilihan2 == "ID" || pilihan2 == "Id" || pilihan2 == "id") {
                        int targetID = 0;
                        cout << "\033[1m› Masukkan ID: \033[0m";
                        cin >> targetID;
                        cout << endl;
                        searchByID(daftarMenu, jumlahData, targetID);
                        cout << endl;
                        break;
                    } else if (pilihan2 == "Nama" || pilihan2 == "nama") {
                        string keyword;
                        cout << "\033[1m› Masukkan Nama: \033[0m";
                        getline(cin, keyword);
                        cout << endl;
                        searchByNama(daftarMenu, jumlahData, keyword);
                        cout << endl;
                        break;
                    } else if (pilihan2 == "Kategori" || pilihan2 == "kategori") {
                        string kategori;
                        cout << "\033[1m› Masukkan Kategori: \033[0m";
                        getline(cin, kategori);
                        cout << endl;
                        searchByKategori(daftarMenu, jumlahData, kategori);
                        cout << endl;
                        break;
                    } else {
                        cout << "\033[31m✗ Input tidak sesuai! Pilih ID, Nama, atau Kategori.\033[0m\n";
                    }
                }
                break;
            }

            case 6:
                cout << "\n\033[1;36m── HITUNG TOTAL PILIHAN MENU ───────────────────────────\033[0m\n";
                hitungTotalPilihan(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 7: {
                cout << "\n\033[1;36m── REKOMENDASI SESUAI BUDGET ───────────────────────────\033[0m\n";
                int budget;
                cout << "\033[1m› Masukkan Budget Anda (Rp): \033[0m";
                cin >> budget;

                Menu hasilBudget[maxData];
                int jumlahHasil = 0;

                for (int i = 0; i < jumlahData; i++) {
                    if (daftarMenu[i].harga <= budget) {
                        hasilBudget[jumlahHasil++] = daftarMenu[i];
                    }
                }

                if (jumlahHasil == 0) {
                    cout << "\n\033[31m✗ Tidak ada menu yang sesuai dengan budget Rp" << budget << ".\033[0m\n";
                } else {
                    cout << "\n\033[1;32m✓ Ditemukan " << jumlahHasil << " menu yang masuk budget Anda:\033[0m\n";
                    displayData(hasilBudget, jumlahHasil);
                }
                cout << endl;
                break;
            }

            case 0:
                cout << "\n\033[1;36mTerima kasih telah menggunakan Campus Food & Drink Finder!\033[0m\n\n";
                break;

            default:
                cout << "\n\033[1;31m✗ Pilihan tidak valid! Silakan masukkan angka 0 - 7.\033[0m\n";
                break;
        }
    } while (pilihan != 0);
    /*
    g++ -std=c++17 main.cpp menu.cpp recursion.cpp searching.cpp sorting.cpp -o program && ./program
    */
    return 0;
}