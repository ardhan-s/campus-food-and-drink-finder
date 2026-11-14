#include <iostream>
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
    int pilihan;

    do {
        cout << "\n\033[1;36m=== CAMPUS FOOD & DRINK FINDER ===\033[0m\n";
        cout << "1. Tambah Menu\n";
        cout << "2. Tampilkan Semua Menu\n";
        cout << "3. Ringkasan (Rata-rata, Termurah, Termahal)\n";
        cout << "4. Urutkan Menu (Harga/Rating)\n";
        cout << "5. Cari Menu (ID/Nama/Kategori)\n";
        cout << "6. Pilih Menu\n";
        cout << "7. What can i eat with my budget?\n";
        cout << "0. Keluar \n\n";
        cout << "\033[1mPilih: \033[0m";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << endl;
                addData(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 2:
                cout << endl;
                displayData(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 3:
                cout << endl;
                calculateSummary(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 4: {
                cout << endl;
                string pilihan2;
                cin.ignore(1000, '\n');

                while (true) {
                    cout << "Berdasarkan Harga/Rating: ";
                    getline(cin, pilihan2);

                    if (pilihan2 == "Harga" || pilihan2 == "harga") {
                        while (true) {
                            cout << "Ascending/Descending?: ";
                            string pilihan3;
                            getline(cin, pilihan3);

                            if (pilihan3 == "Ascending" || pilihan3 == "ascending") {
                                sortByHarga(daftarMenu, jumlahData, true);
                                break;
                            } else if (pilihan3 == "Descending" || pilihan3 == "descending") {
                                sortByHarga(daftarMenu, jumlahData, false);
                                break;
                            } else {
                                cout << "Input tidak sesuai!" << endl;
                            }
                        }
                        break;
                    } else if (pilihan2 == "Rating" || pilihan2 == "rating") {
                        while (true) {
                            cout << "Ascending/Descending?: ";
                            string pilihan3;
                            getline(cin, pilihan3);

                            if (pilihan3 == "Ascending" || pilihan3 == "ascending") {
                                sortByRating(daftarMenu, jumlahData, true);
                                break;
                            } else if (pilihan3 == "Descending" || pilihan3 == "descending") {
                                sortByRating(daftarMenu, jumlahData, false);
                                break;
                            } else {
                                cout << "Input tidak sesuai!" << endl;
                            }
                        }
                        break;
                    } else {
                        cout << "Input tidak sesuai!" << endl;
                    }
                }

                cout << endl;
                displayData(daftarMenu, jumlahData);
                cout << endl;
                break;
            }

            case 5: {
                cout << endl;
                string pilihan2;
                cin.ignore(1000, '\n');

                while (true) {
                    cout << "Berdasarkan ID/Nama/Kategori?: ";
                    getline(cin, pilihan2);

                    if (pilihan2 == "ID" || pilihan2 == "Id" || pilihan2 == "id") {
                        int targetID = 0;
                        cout << "Masukkan ID: ";
                        cin >> targetID;
                        cout << endl;
                        searchByID(daftarMenu, jumlahData, targetID);
                        cout << endl;
                        break;
                    } else if (pilihan2 == "Nama" || pilihan2 == "nama") {
                        string keyword;
                        cout << "Masukkan Nama: ";
                        getline(cin, keyword);
                        cout << endl;
                        searchByNama(daftarMenu, jumlahData, keyword);
                        cout << endl;
                        break;
                    } else if (pilihan2 == "Kategori" || pilihan2 == "kategori") {
                        string kategori;
                        cout << "Masukkan Kategori: ";
                        getline(cin, kategori);
                        cout << endl;
                        searchByKategori(daftarMenu, jumlahData, kategori);
                        cout << endl;
                        break;
                    } else {
                        cout << "Input tidak sesuai!" << endl;
                    }
                }
                break;
            }

            case 6:
                cout << endl;
                hitungTotalPilihan(daftarMenu, jumlahData);
                cout << endl;
                break;

            case 7: {
                int budget;
                cout << "Masukkan Budget (Rp): ";
                cin >> budget;

                Menu hasilBudget[maxData];
                int jumlahHasil = 0;

                for (int i = 0; i < jumlahData; i++) {
                    if (daftarMenu[i].harga <= budget) {
                        hasilBudget[jumlahHasil++] = daftarMenu[i];
                    }
                }

                if (jumlahHasil == 0) {
                    cout << "Tidak ada menu yang sesuai dengan budget.\n";
                } else {
                    cout << endl;
                    displayData(hasilBudget, jumlahHasil);
                }
                cout << endl;
                break;
            }

            case 0:
                cout << "\n\033[1mTerima kasih!\033[0m\n";
                break;

            default:
                cout << "\n\033[1mPilihan tidak valid!\033[0m\n";
                break;
        }
    } while (pilihan != 0);

    // g++ -std=c++17 main.cpp menu.cpp recursion.cpp searching.cpp sorting.cpp -o program
    // ./program
    return 0;
}