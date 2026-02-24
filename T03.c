#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// ================= STRUCT =================
struct Pelanggan {
    int id;
    char nama[50];
};

struct Transaksi {
    int id;
    int idPelanggan;
    char layanan[30];
    float berat;
    float total;
};

struct Pelanggan pelanggan[MAX];
struct Transaksi transaksi[MAX];

int jumlahPelanggan = 0;
int jumlahTransaksi = 0;

// ================= FUNCTION =================

void pauseProgram() {
    printf("\nTekan ENTER untuk kembali ke menu...");
    getchar();
    getchar();
}

void tambahPelanggan() {
    system("cls");
    printf("===== TAMBAH PELANGGAN =====\n");

    if (jumlahPelanggan >= MAX) {
        printf("Data penuh!\n");
        pauseProgram();
        return;
    }

    pelanggan[jumlahPelanggan].id = jumlahPelanggan + 1;

    printf("Nama Pelanggan: ");
    scanf(" %[^\n]", pelanggan[jumlahPelanggan].nama);

    jumlahPelanggan++;

    printf("Pelanggan berhasil ditambahkan!\n");
    pauseProgram();
}

void lihatPelanggan() {
    system("cls");
    printf("===== DAFTAR PELANGGAN =====\n");

    if (jumlahPelanggan == 0) {
        printf("Belum ada pelanggan.\n");
    } else {
        for (int i = 0; i < jumlahPelanggan; i++) {
            printf("ID: %d | Nama: %s\n",
                   pelanggan[i].id,
                   pelanggan[i].nama);
        }
    }

    pauseProgram();
}

void transaksiBaru() {
    system("cls");
    printf("===== TRANSAKSI BARU =====\n");

    if (jumlahPelanggan == 0) {
        printf("Belum ada pelanggan!\n");
        pauseProgram();
        return;
    }

    int id, pilihan;
    float harga = 0;

    lihatPelanggan();

    printf("\nMasukkan ID Pelanggan: ");
    scanf("%d", &id);

    if (id <= 0 || id > jumlahPelanggan) {
        printf("ID tidak valid!\n");
        pauseProgram();
        return;
    }

    printf("\nPilih Layanan:\n");
    printf("1. Cuci Kering (5000/kg)\n");
    printf("2. Cuci Setrika (7000/kg)\n");
    printf("3. Setrika Saja (4000/kg)\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1: harga = 5000; strcpy(transaksi[jumlahTransaksi].layanan, "Cuci Kering"); break;
        case 2: harga = 7000; strcpy(transaksi[jumlahTransaksi].layanan, "Cuci Setrika"); break;
        case 3: harga = 4000; strcpy(transaksi[jumlahTransaksi].layanan, "Setrika Saja"); break;
        default:
            printf("Pilihan tidak valid!\n");
            pauseProgram();
            return;
    }

    printf("Masukkan berat (kg): ");
    scanf("%f", &transaksi[jumlahTransaksi].berat);

    transaksi[jumlahTransaksi].id = jumlahTransaksi + 1;
    transaksi[jumlahTransaksi].idPelanggan = id;
    transaksi[jumlahTransaksi].total =
        transaksi[jumlahTransaksi].berat * harga;

    printf("\nTotal Bayar: Rp %.2f\n",
           transaksi[jumlahTransaksi].total);

    jumlahTransaksi++;
    pauseProgram();
}

void laporan() {
    system("cls");
    printf("===== LAPORAN TRANSAKSI =====\n");

    if (jumlahTransaksi == 0) {
        printf("Belum ada transaksi.\n");
    } else {
        float totalPendapatan = 0;

        for (int i = 0; i < jumlahTransaksi; i++) {
            printf("ID: %d | Nama: %s | Layanan: %s | Total: %.2f\n",
                   transaksi[i].id,
                   pelanggan[transaksi[i].idPelanggan - 1].nama,
                   transaksi[i].layanan,
                   transaksi[i].total);

            totalPendapatan += transaksi[i].total;
        }

        printf("\nTOTAL PENDAPATAN: Rp %.2f\n", totalPendapatan);
    }

    pauseProgram();
}

// ================= MAIN =================
int main() {
    int menu;

    do {
        system("cls");
        printf("=================================\n");
        printf("   SISTEM LAUNDRY IT DEL\n");
        printf("=================================\n");
        printf("1. Tambah Pelanggan\n");
        printf("2. Lihat Pelanggan\n");
        printf("3. Transaksi Baru\n");
        printf("4. Laporan\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1: tambahPelanggan(); break;
            case 2: lihatPelanggan(); break;
            case 3: transaksiBaru(); break;
            case 4: laporan(); break;
            case 5: printf("Terima kasih!\n"); break;
            default: printf("Menu tidak valid!\n"); pauseProgram();
        }

    } while (menu != 5);

    return 0;
}