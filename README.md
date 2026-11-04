# Panduan Layanan Perpustakaan (Prototipe)



> Semua data dan alur di repo ini adalah **contoh (dummy)** dan **bukan prosedur resmi** perpustakaan. Tidak ada data anggota, transaksi, atau kredensial.

**Pembuat:** Cesaraihan Muhammad izzah, Teknik Informatika, semester 2
**GitHub:** izzah-1305

## 1. Masalah yang dipilih

Dari wawancara dengan dua orang (satu staf perpustakaan, satu mahasiswa semester 4), muncul tiga hal:

- **Pemustaka sulit diarahkan.** Staf menyebut banyaknya cabang membuat pengarahan sulit. Mahasiswa menyebut bagian depan yang membingungkan dan menyarankan denah yang jelas.
- **Informasi ada, tetapi tidak sampai.** Menurut staf, informasi sudah dipasang besar-besar di web, tetapi pemustaka malas membacanya.
- **Pertanyaan dasar berulang.** Staf menyebut pertanyaan pemustaka umumnya dasar, dan kebiasaan seperti memasukkan NIM di entry gate masih sering terlewat.

Rumusan masalah: *pemustaka yang baru datang sulit menemukan arah dan jawaban dasar, padahal informasinya ada. Informasi yang harus dibaca panjang tidak sampai ke mereka.*

Catatan lengkap ada di [`docs/catatan-wawancara.md`](docs/catatan-wawancara.md).

## 2. Siapa yang terbantu

- **Pemustaka**, terutama yang baru datang atau belum paham alur layanan.
- **Staf**, yang diharapkan tidak perlu terlalu sering mengarahkan ulang atau meneruskan pertanyaan dasar. Ini harapan, belum terbukti.

## 3. Bagaimana solusi bekerja

Program konsol C++ berbentuk **pohon keputusan**. Pengguna memilih keperluan dengan satu angka, menjawab beberapa pertanyaan pendek, lalu mendapat hasil berupa beberapa langkah singkat. Angka `0` selalu kembali ke menu utama.

Alasan pendekatan ini: karena informasi yang panjang tidak dibaca, prototipe memakai **pertanyaan pendek dan jawaban tiga langkah**, bukan halaman penjelasan. Ini masih hipotesis dan belum diuji (lihat bagian 5).

Tiga jalur dari menu utama, dengan dasar yang berbeda:

| Jalur | Dasar |
|---|---|
| Saya baru datang atau bingung harus ke mana | Wawancara staf dan mahasiswa. Nama bagian dan cabang masih dummy. |
| Cara masuk lewat entry gate | Wawancara staf. Alasan resmi pencatatan NIM belum diketahui, jadi tidak ditulis. |
| Layanan lain (bebas pustaka, kartu anggota, pinjaman dan denda, e-library, repositori) | **Dugaan penulis**, belum divalidasi wawancara. Dipertahankan sebagai contoh bentuk alur. |

Keputusan desain: **isi alur dipisah dari mesin**. Isi ada di fungsi `siapkanAlur()`, mesin ada di `main()`, sehingga isi bisa diganti tanpa mengubah logika. Diagram lengkap ada di [`docs/diagram-alur.md`](docs/diagram-alur.md).

## 4. Cara melihat dan menjalankan

Butuh compiler C++ (misalnya `g++`). Dari folder repo:

```
g++ -std=c++17 -o panduan src/main.cpp
./panduan
```

Di Windows PowerShell, jalankan dengan `.\panduan.exe`. Atau buka `src/main.cpp` di VS Code lalu jalankan seperti biasa.

Coba urutan ini: `1` (baru datang), `4` (belum tahu cabang), lalu `0` (kembali), `2` (entry gate), `2` (belum), `0`, `0` (keluar).

## 5. Yang belum selesai dan asumsi

- **Isi alur adalah contoh.** Nama cabang dan bagian adalah dummy, dan belum diverifikasi staf.
- **Dasar wawancara terbatas:** dua narasumber, sebagian jawaban kosong, dan **prototipe belum diuji pada narasumber**. Tanggapan terhadap alurnya belum ada.
- **Lima topik di jalur "Layanan lain" adalah dugaan penulis**, bukan temuan wawancara.
- **Antarmuka konsol tidak cocok untuk pemustaka sungguhan.** Prototipe ini hanya membuktikan logika alurnya.
- **Pertanyaan terbuka:** apakah menu teks pendek cukup bagi orang yang malas membaca? Saya belum tahu.

## 6. Langkah berikutnya

1. Menguji prototipe ke beberapa pemustaka dan mengamati di mana mereka ragu.
2. Memverifikasi alur dengan staf dan mengisi nama cabang dan bagian yang asli.
3. Mewujudkan usulan mahasiswa: **denah** yang menandai tiap bagian dengan jelas, dan **poster FAQ** yang bisa dibuat dari data alur yang sama.
4. Memindahkan isi alur ke berkas teks agar staf bisa memperbaikinya tanpa menyentuh kode.
5. Membuat antarmuka web yang ringan, misalnya dengan QR di bagian depan.
6. Memikirkan cara memberi tahu pemustaka tentang informasi yang sudah ada, sesuai usulan staf ("broadcast"). Ini di luar ruang lingkup prototipe.

## Tentang level saya

Saya baru belajar C++ sejak tahun ini, jadi kode dibuat sederhana agar saya bisa menjelaskan setiap bagiannya.

## Struktur repo

```
README.md
src/main.cpp
docs/catatan-wawancara.md
docs/diagram-alur.md
```
