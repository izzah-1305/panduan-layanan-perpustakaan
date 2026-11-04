// Panduan Layanan Perpustakaan (prototipe) - Versi 0.1
//
// PENTING: semua isi alur di bawah adalah CONTOH (dummy), BUKAN prosedur resmi.
// Nama bagian/cabang sengaja tidak diisi nama asli. Isi alur harus diverifikasi
// ke staf perpustakaan sebelum dipakai sungguhan.
//
// Dasar isi alur (lihat docs/catatan-wawancara.md):
//   [WAWANCARA] = berangkat dari hasil wawancara (1 staf, 1 mahasiswa)
//   [ASUMSI]    = dugaan penulis (dibantu AI), belum divalidasi wawancara

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// Satu pilihan jawaban.
struct Pilihan {
    string label;   // tulisan yang dilihat pengguna
    string tujuan;  // id "kartu" (node) berikutnya
};

// Satu "kartu" dalam alur: pertanyaan atau hasil akhir.
struct Node {
    string teks;
    vector<Pilihan> pilihan;  // kosong = hasil akhir
};

const string PERINGATAN =
    "[Contoh alur untuk prototipe, bukan prosedur resmi. Tanyakan ke staf perpustakaan.]";

// Dua fungsi pembantu agar penulisan alur lebih rapi.
// Tanda & berarti kita bekerja pada map aslinya, bukan salinannya.
void tambahNode(map<string, Node>& alur, const string& id, const string& teks) {
    alur[id].teks = teks;
}

void tambahPilihan(map<string, Node>& alur, const string& id,
                   const string& label, const string& tujuan) {
    alur[id].pilihan.push_back({label, tujuan});
}

// ======================= ISI ALUR (DATA CONTOH) =======================
map<string, Node> siapkanAlur() {
    map<string, Node> alur;

    // ---------- Menu utama ----------
    tambahNode(alur, "mulai", "Kamu butuh bantuan apa?");
    tambahPilihan(alur, "mulai", "Saya baru datang atau bingung harus ke mana", "datang");
    tambahPilihan(alur, "mulai", "Cara masuk lewat entry gate", "gate");
    tambahPilihan(alur, "mulai", "Layanan lain ", "lain");

    // ---------- A. Baru datang / bingung arah [WAWANCARA] ----------
    // Dasar: staf menyebut banyaknya cabang menyulitkan pengarahan; mahasiswa
    // menyebut kebingungan di bagian depan. Nama bagian/cabang masih dummy.
    tambahNode(alur, "datang", "Apa keperluanmu hari ini?");
    tambahPilihan(alur, "datang", "Meminjam atau mengembalikan buku", "d_pinjam");
    tambahPilihan(alur, "datang", "Belajar atau membaca di tempat", "d_belajar");
    tambahPilihan(alur, "datang", "Mengurus keanggotaan atau administrasi", "d_admin");
    tambahPilihan(alur, "datang", "Belum tahu cabang atau bagian yang dituju", "d_bingung");

    tambahNode(alur, "d_pinjam",
        "Petunjuk (contoh):\n"
        "1. Tuju bagian layanan sirkulasi di cabang yang kamu tuju.\n"
        "2. Bawa kartu anggota atau identitas mahasiswa.\n"
        "3. Nama bagian dan letak aslinya masih DATA DUMMY, perlu diisi dari data asli.");

    tambahNode(alur, "d_belajar",
        "Petunjuk (contoh):\n"
        "1. Tuju area baca di cabang yang kamu tuju.\n"
        "2. Pastikan kamu sudah masuk lewat entry gate dan memasukkan NIM.\n"
        "3. Nama area dan letak aslinya masih DATA DUMMY, perlu diisi dari data asli.");

    tambahNode(alur, "d_admin",
        "Petunjuk (contoh):\n"
        "1. Tuju meja keanggotaan atau administrasi.\n"
        "2. Bawa identitas mahasiswa.\n"
        "3. Nama meja dan letak aslinya masih DATA DUMMY, perlu diisi dari data asli.");

    tambahNode(alur, "d_bingung",
        "Tidak apa-apa, memilih cabang atau bagian memang bisa membingungkan.\n"
        "1. Mulai dari bagian depan dan sebutkan keperluanmu ke petugas.\n"
        "2. Lihat denah atau papan petunjuk jika tersedia.\n"
        "3. Catat nama cabang atau bagian yang diarahkan, supaya kunjungan berikutnya lebih mudah.");

    // ---------- B. Entry gate [WAWANCARA] ----------
    // Dasar: staf menyebut pemustaka jarang mau memasukkan NIM di entry gate.
    // Alasan resmi pencatatan NIM belum diketahui, jadi tidak ditulis di sini.
    tambahNode(alur, "gate", "Apakah kamu sudah memasukkan NIM di entry gate saat masuk?");
    tambahPilihan(alur, "gate", "Sudah", "g_sudah");
    tambahPilihan(alur, "gate", "Belum, atau aku lupa", "g_belum");

    tambahNode(alur, "g_sudah",
        "Bagus. Lakukan hal yang sama setiap kali masuk (contoh).\n"
        "Alasan resmi pencatatan NIM perlu dipastikan ke staf perpustakaan.");

    tambahNode(alur, "g_belum",
        "Masukkan NIM di entry gate setiap kali masuk (contoh).\n"
        "1. Siapkan NIM sebelum sampai di gate.\n"
        "2. Jika gate bermasalah, sampaikan ke petugas.\n"
        "3. Alasan resmi pencatatan NIM perlu dipastikan ke staf (prototipe ini tidak mengarang alasannya).");

    // ---------- C. Layanan lain [ASUMSI] ----------
    // Lima topik di bawah berasal dari dugaan penulis, BUKAN dari wawancara.
    tambahNode(alur, "lain", "Pilih topik (contoh alur, belum divalidasi wawancara):");
    tambahPilihan(alur, "lain", "Bebas pustaka", "bp_pinjaman");
    tambahPilihan(alur, "lain", "Kartu anggota", "kartu");
    tambahPilihan(alur, "lain", "Pinjaman, perpanjangan, dan denda", "pinjam");
    tambahPilihan(alur, "lain", "Akses e-library", "elib");
    tambahPilihan(alur, "lain", "Unggah tugas akhir ke repositori", "repo");

    // ----- C1. Bebas pustaka -----
    tambahNode(alur, "bp_pinjaman", "Apakah kamu masih punya buku yang belum dikembalikan?");
    tambahPilihan(alur, "bp_pinjaman", "Ya, masih ada", "bp_kembalikan");
    tambahPilihan(alur, "bp_pinjaman", "Tidak ada", "bp_repo");

    tambahNode(alur, "bp_kembalikan",
        "Langkah (contoh):\n"
        "1. Kembalikan dulu semua buku yang masih dipinjam ke meja layanan.\n"
        "2. Jika ada denda, selesaikan sesuai aturan resmi perpustakaan.\n"
        "3. Setelah itu, ulangi pengurusan bebas pustaka.");

    tambahNode(alur, "bp_repo", "Apakah tugas akhirmu sudah diunggah ke repositori?");
    tambahPilihan(alur, "bp_repo", "Sudah", "bp_siap");
    tambahPilihan(alur, "bp_repo", "Belum", "bp_unggah");

    tambahNode(alur, "bp_unggah",
        "Unggah tugas akhirmu ke repositori lebih dulu.\n"
        "Lihat menu utama > Layanan lain > Unggah tugas akhir ke repositori.");

    tambahNode(alur, "bp_siap",
        "Syarat dasar tampaknya sudah terpenuhi (contoh).\n"
        "1. Siapkan identitas mahasiswa.\n"
        "2. Ajukan ke layanan bebas pustaka.\n"
        "3. Tanyakan ke staf berapa lama prosesnya dan di mana hasilnya diambil.");

    // ----- C2. Kartu anggota -----
    tambahNode(alur, "kartu", "Apa kondisi kartu anggotamu?");
    tambahPilihan(alur, "kartu", "Belum punya", "kartu_baru");
    tambahPilihan(alur, "kartu", "Hilang atau rusak", "kartu_hilang");
    tambahPilihan(alur, "kartu", "Ada, tapi tidak bisa dipakai", "kartu_masalah");

    tambahNode(alur, "kartu_baru",
        "Langkah (contoh):\n"
        "1. Datang ke meja keanggotaan dengan identitas mahasiswa.\n"
        "2. Isi data pendaftaran.\n"
        "3. Tanyakan kapan kartu aktif dan bisa dipakai meminjam.");

    tambahNode(alur, "kartu_hilang",
        "Langkah (contoh):\n"
        "1. Laporkan kehilangan ke meja keanggotaan secepatnya.\n"
        "2. Tanyakan syarat dan biaya penggantian kartu menurut aturan resmi.\n"
        "3. Tanyakan apakah masih bisa meminjam sebelum kartu baru jadi.");

    tambahNode(alur, "kartu_masalah",
        "Kemungkinan penyebab (contoh): kartu belum diaktifkan, masa\n"
        "keanggotaan berakhir, atau ada pinjaman bermasalah.\n"
        "Tanyakan ke meja keanggotaan untuk pengecekan.");

    // ----- C3. Pinjaman, perpanjangan, denda -----
    tambahNode(alur, "pinjam", "Apa yang ingin kamu ketahui?");
    tambahPilihan(alur, "pinjam", "Memperpanjang pinjaman", "perpanjang");
    tambahPilihan(alur, "pinjam", "Denda keterlambatan", "denda");

    tambahNode(alur, "perpanjang", "Apakah buku sudah melewati tanggal jatuh tempo?");
    tambahPilihan(alur, "perpanjang", "Belum", "perpanjang_ok");
    tambahPilihan(alur, "perpanjang", "Sudah lewat", "perpanjang_lewat");

    tambahNode(alur, "perpanjang_ok",
        "Kemungkinan masih bisa diperpanjang (contoh).\n"
        "1. Cek apakah perpanjangan bisa lewat akun online atau harus di meja layanan.\n"
        "2. Lakukan sebelum tanggal jatuh tempo.\n"
        "3. Tanyakan batas jumlah perpanjangan.");

    tambahNode(alur, "perpanjang_lewat",
        "Buku sudah terlambat (contoh).\n"
        "1. Kembalikan buku ke meja layanan.\n"
        "2. Tanyakan besar denda menurut aturan resmi.\n"
        "3. Setelah denda selesai, pinjam kembali jika masih perlu.");

    tambahNode(alur, "denda",
        "Aturan denda berbeda di tiap perpustakaan.\n"
        "Prototipe ini sengaja tidak menyebut angka.\n"
        "Cek aturan resmi atau tanyakan ke meja layanan.");

    // ----- C4. Akses e-library -----
    tambahNode(alur, "elib", "Dari mana kamu mengakses e-library?");
    tambahPilihan(alur, "elib", "Dari dalam kampus", "elib_kampus");
    tambahPilihan(alur, "elib", "Dari luar kampus", "elib_luar");

    tambahNode(alur, "elib_kampus",
        "Langkah (contoh):\n"
        "1. Buka halaman e-library perpustakaan.\n"
        "2. Masuk dengan akun yang diberikan.\n"
        "3. Jika gagal masuk, hubungi staf IT atau meja layanan.");

    tambahNode(alur, "elib_luar",
        "Beberapa sumber hanya bisa dibuka dari jaringan kampus atau\n"
        "butuh akses khusus (contoh).\n"
        "1. Cek informasi resmi tentang akses dari luar kampus.\n"
        "2. Tanyakan apakah ada cara akses jarak jauh.\n"
        "3. Jika muncul pesan error, catat dan tunjukkan ke staf.");

    // ----- C5. Unggah tugas akhir ke repositori -----
    tambahNode(alur, "repo", "Apa kendalamu dengan repositori?");
    tambahPilihan(alur, "repo", "Belum tahu cara mengunggah", "repo_cara");
    tambahPilihan(alur, "repo", "Unggahanku diminta direvisi", "repo_revisi");

    tambahNode(alur, "repo_cara",
        "Langkah (contoh):\n"
        "1. Siapkan berkas final tugas akhir (biasanya PDF).\n"
        "2. Siapkan data: judul, penulis, abstrak, kata kunci.\n"
        "3. Unggah lewat akun repositori, lalu tunggu pemeriksaan staf.");

    tambahNode(alur, "repo_revisi",
        "Langkah (contoh):\n"
        "1. Baca catatan dari staf dengan teliti.\n"
        "2. Periksa kelengkapan data (judul, abstrak, kata kunci) dan format berkas.\n"
        "3. Perbaiki dan unggah ulang.");

    return alur;
}

// ======================= MESIN ALUR =======================

// Membaca satu angka dari pengguna.
// Mengembalikan -1 jika yang diketik bukan angka,
// dan -2 jika input sudah habis (misalnya program dihentikan).
int bacaAngka() {
    int angka = 0;
    if (!(cin >> angka)) {
        if (cin.eof()) return -2;
        cin.clear();               // pulihkan cin dari kondisi error
        cin.ignore(10000, '\n');   // buang sisa ketikan yang salah
        return -1;
    }
    return angka;
}

int main() {
    map<string, Node> alur = siapkanAlur();
    string sekarang = "mulai";  // id kartu yang sedang ditampilkan

    cout << "=== PANDUAN LAYANAN PERPUSTAKAAN (PROTOTIPE) ===\n";
    cout << PERINGATAN << "\n";

    while (true) {
        // Cari kartu yang sedang aktif. Jika id salah ketik, beri tahu dengan jelas.
        auto it = alur.find(sekarang);
        if (it == alur.end()) {
            cout << "\nKesalahan alur: kartu '" << sekarang << "' tidak ditemukan.\n";
            return 1;
        }
        const Node& node = it->second;  // it->second adalah isi kartunya

        cout << "\n" << node.teks << "\n";

        bool diMenuUtama = (sekarang == "mulai");
        bool hasilAkhir = node.pilihan.empty();

        if (hasilAkhir) {
            cout << "\n" << PERINGATAN << "\n";
        }

        // Tampilkan pilihan bernomor, ditambah 0 untuk kembali/keluar
        int jumlah = node.pilihan.size();
        cout << "\n";
        for (int i = 0; i < jumlah; i++) {
            cout << i + 1 << ". " << node.pilihan[i].label << "\n";
        }
        cout << "0. " << (diMenuUtama ? "Keluar" : "Kembali ke menu utama") << "\n";
        cout << "Pilihanmu: ";

        int angka = bacaAngka();

        if (angka == -2) {
            break;                       // input habis
        } else if (angka == 0) {
            if (diMenuUtama) break;      // 0 di menu utama = keluar
            sekarang = "mulai";          // 0 di tempat lain = kembali ke menu
        } else if (angka >= 1 && angka <= jumlah) {
            sekarang = node.pilihan[angka - 1].tujuan;  // pindah ke kartu berikutnya
        } else {
            cout << "Pilihan tidak valid, coba lagi.\n";  // kartu yang sama ditampilkan lagi
        }
    }

    cout << "\nTerima kasih. Sampai jumpa!\n";
    return 0;
}
