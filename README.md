# 🎓 Sistem Manajemen Data Mahasiswa

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Singly%20Linked%20List-orange?style=for-the-badge)](#)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](#lisensi)

Aplikasi **CLI (Command Line Interface)** berbasis C++ untuk mengelola data akademik mahasiswa — meliputi NIM, Nama, dan IPK — dengan struktur data **Singly Linked List** sebagai basis penyimpanan dinamis di memori.

Proyek ini dibuat sebagai implementasi konsep struktur data linear non-kontigu, menekankan efisiensi alokasi memori dan operasi CRUD (*Create, Read, Update/Search, Delete*) tanpa ketergantungan pada array statis.

---

## 📑 Daftar Isi

- [Fitur Utama](#-fitur-utama)
- [Struktur Data](#-struktur-data)
- [Kompleksitas Algoritma](#-kompleksitas-algoritma)
- [Instalasi & Kompilasi](#-instalasi--kompilasi)
- [Cara Penggunaan](#-cara-penggunaan)
- [Struktur Proyek](#-struktur-proyek)
- [Rencana Pengembangan](#-rencana-pengembangan)
- [Kontribusi](#-kontribusi)
- [Lisensi](#-lisensi)

---

## ✨ Fitur Utama

| Fitur | Deskripsi |
|---|---|
| ➕ **Tambah Data** | Menyisipkan data mahasiswa baru di akhir *list*, dengan validasi NIM unik untuk mencegah duplikasi. |
| 📋 **Tampilkan Data** | Menampilkan seluruh NIM mahasiswa yang terdaftar dalam sistem. |
| 🔍 **Cari Data** | Menelusuri *list* berdasarkan NIM dan menampilkan detail lengkap (Nama, NIM, IPK). |
| 🗑️ **Hapus Data** | Menghapus node mahasiswa dari memori berdasarkan NIM, dengan penyesuaian pointer otomatis. |
| 📊 **Hitung Total** | Menghitung jumlah mahasiswa yang tersimpan secara *real-time*. |
| 🧹 **Manajemen Memori** | Dekalokasi memori otomatis (`clear()`) saat program berakhir untuk mencegah *memory leak*. |

---

## 🧱 Struktur Data

Sistem ini dibangun di atas dua struktur inti: `Mahasiswa` sebagai *payload* data, dan `Node` sebagai unit penyimpanan dalam *linked list*.

```cpp
struct Mahasiswa {
    std::string nim;
    std::string nama;
    double ipk;
};

struct Node {
    Mahasiswa mhs;
    Node* next;
};
```

**Karakteristik implementasi:**
- Setiap `Node` menyimpan satu record `Mahasiswa` dan pointer ke node berikutnya.
- Penyisipan dilakukan di akhir *list* (`tail insertion`) untuk mempertahankan urutan input.
- Operasi pencarian dan penghapusan menggunakan pendekatan *two-pointer* (`prev` & `current`) untuk penyesuaian pointer yang aman.

---

## ⏱ Kompleksitas Algoritma

| Operasi | Kompleksitas Waktu | Kompleksitas Ruang |
|---|:---:|:---:|
| Tambah Data | O(n) | O(1) |
| Cari Data | O(n) | O(1) |
| Hapus Data | O(n) | O(1) |
| Tampilkan Semua | O(n) | O(1) |
| Hitung Jumlah | O(n) atau O(1)* | O(1) |

<sup>*Tergantung apakah jumlah data dilacak dengan counter terpisah atau dihitung ulang setiap pemanggilan.</sup>

---

## ⚙️ Instalasi & Kompilasi

### Prasyarat
- Compiler C++ yang mendukung standar **C++11** ke atas (GCC, Clang, atau MSVC)

### Kompilasi via g++

```bash
git clone https://github.com/username/nama-repo.git
cd nama-repo
g++ -std=c++17 -o mahasiswa main.cpp
```

### Menjalankan Program

```bash
./mahasiswa       # Linux/macOS
mahasiswa.exe     # Windows
```

---

## 🚀 Cara Penggunaan

Setelah program dijalankan, pengguna akan disajikan menu interaktif berbasis teks:

```
=== SISTEM MANAJEMEN DATA MAHASISWA ===
1. Tambah Data Mahasiswa
2. Tampilkan Daftar NIM
3. Cari Data Mahasiswa
4. Hapus Data Mahasiswa
5. Hitung Jumlah Mahasiswa
6. Keluar
Pilih menu:
```

Setiap fitur diakses dengan memasukkan nomor menu yang sesuai, kemudian mengikuti instruksi input yang ditampilkan (NIM, Nama, IPK).

---

## 📂 Struktur Proyek

```
.
├── main.cpp        # Entry point & logika menu utama
├── README.md       # Dokumentasi proyek
└── LICENSE         # Lisensi proyek
```

---

## 🗺 Rencana Pengembangan

- [ ] Fitur *update* data mahasiswa tanpa hapus-tambah ulang
- [ ] Penyimpanan data persisten (file `.txt` / `.csv`)
- [ ] Sorting data berdasarkan IPK atau Nama
- [ ] Validasi input IPK (rentang 0.00–4.00)

---

## 🤝 Kontribusi

Kontribusi terbuka untuk siapa saja. Silakan buat *fork*, lakukan perubahan pada *branch* terpisah, lalu ajukan *pull request*.

1. Fork repositori ini
2. Buat branch baru (`git checkout -b fitur-baru`)
3. Commit perubahan (`git commit -m "Menambahkan fitur X"`)
4. Push ke branch (`git push origin fitur-baru`)
5. Buka Pull Request

---

