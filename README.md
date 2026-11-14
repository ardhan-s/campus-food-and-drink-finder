# Campus Food & Drink Finder

![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Windows%20%7C%20Linux-2EA44F?style=for-the-badge)
![Interface](https://img.shields.io/badge/Interface-CLI%20Terminal-orange?style=for-the-badge)

> **Bingung mau makan apa hari ini di kampus? Atau dompet lagi mode hemat di akhir bulan?**
> 
> **Campus Food & Drink Finder** hadir sebagai solusi praktis berbasis konsol (*Command Line Interface*) yang dibangun menggunakan **C++** untuk membantu mahasiswa menemukan, membandingkan, hingga menghitung estimasi jajanan dan makanan terbaik di sekitar kampus.

---

## Fitur Utama

1. **Tambah Menu (`addData`)**
   * Punya rekomendasi tempat makan atau minuman baru di sekitar kampus? Tambahkan langsung lengkap dengan ID, Nama, Kategori, Harga, dan Rating.
   * Data baru otomatis tersimpan secara permanen sehingga tidak akan hilang saat aplikasi ditutup.

2. **Tampilkan Semua Menu (`displayData`)**
   * Lihat seluruh katalog kuliner kampus dalam tampilan tabel terminal yang rapi, sejajar, dan berwarna.
   * Dilengkapi pelabelan harga otomatis (*Budget*, *Medium*, hingga *Premium*) untuk memudahkan pemilihan sesuai kantong.

3. **Ringkasan Menu (`calculateSummary`)**
   * Dapatkan gambaran cepat mengenai total variasi menu yang tersedia, rata-rata harga, rata-rata rating, serta rekomendasi menu paling ramah di kantong hingga yang paling mahal.

4. **Urutkan Menu (`sortByHarga` & `sortByRating`)**
   * Urutkan daftar menu berdasarkan **Harga** (dari yang paling murah atau paling mahal) maupun **Rating** (dari yang paling favorit) menggunakan algoritma **Bubble Sort**.

5. **Cari Menu (`searchByID`, `searchByNama`, `searchByKategori`)**
   * Temukan menu incaranmu secara instan berdasarkan **ID**, **Nama Menu**, atau **Kategori** (*Meal*, *Drink*, *Coffee*, *Snack*) dengan metode **Sequential Search**.

6. **Hitung Total Pilihan Menu (`hitungTotalPilihan`)**
   * Simulasikan pesananmu dengan memilih beberapa menu sekaligus, lalu biarkan program menghitung total tagihan secara otomatis menggunakan pendekatan fungsi **Rekursif** (`hitungTotalRekursif`).

7. **What can I eat with my budget? (`filterByBudget`)**
   * Fitur penyelamat tanggal tua. Cukup masukkan nominal uang yang kamu miliki, dan aplikasi akan langsung menyaring daftar makanan serta minuman yang sesuai dengan *budget*-mu.

8. **Penyimpanan Data Lokal (`loadData` & `saveData`)**
   * Terintegrasi dengan sistem manajemen file lokal (`data_menu.txt`) menggunakan `<fstream>` sehingga seluruh perubahan data selalu aman dan tersinkronisasi.

---

## Struktur Proyek

```text
Campus Food and Drink Finder/
├── main.cpp          # Pusat kendali program dan antarmuka menu utama
├── struct.hpp        # Definisi struktur data Menu dan kapasitas maksimal
├── menu.hpp          # Deklarasi fungsi manajemen menu & penyimpanan file
├── menu.cpp          # Implementasi tambah, tampil, ringkasan, dan load/save data
├── searching.hpp     # Deklarasi fungsi pencarian dan filter budget
├── searching.cpp     # Implementasi pencarian (ID/Nama/Kategori) & filter budget
├── sorting.hpp       # Deklarasi fungsi pengurutan data
├── sorting.cpp       # Implementasi Bubble Sort (Harga & Rating)
├── recursion.hpp     # Deklarasi fungsi perhitungan total rekursif
├── recursion.cpp     # Implementasi kalkulasi total pesanan secara rekursif
├── data_menu.txt     # Database lokal penyimpanan daftar menu (otomatis dibuat)
└── README.md         # Dokumentasi proyek
```

---

## Cara Kompilasi & Menjalankan Program

Pastikan *compiler* `g++` (dengan dukungan standar **C++17**) sudah terpasang di perangkat Anda (**macOS**, **Linux**, maupun **Windows**).

1. **Buka terminal** dan masuk ke direktori proyek:
   ```bash
   cd "Campus Food and Drink Finder"
   ```

2. **Compile seluruh file sumber:**
   ```bash
   g++ -std=c++17 main.cpp menu.cpp recursion.cpp searching.cpp sorting.cpp -o program
   ```

3. **Jalankan aplikasi:**
   * **macOS / Linux:**
     ```bash
     ./program
     ```
   * **Windows (CMD / PowerShell):**
     ```cmd
     program.exe
     ```
