#include <stdio.h>
#include <string.h>

int main() {
    char kode[10];
    char nama[50];
    int harga, porsi;
    int total_semua = 0;
    int total;

    printf("Menu\t\tPorsi\tHarga\tTotal\n");
    printf("=====================================================\n");

    while (1) {
        printf("Kode Menu (ketik END untuk selesai): ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            break;
        }

        printf("Porsi: ");
        scanf("%d", &porsi);

        if (strcmp(kode, "NP") == 0) {
            strcpy(nama, "Nasi Padang");
            harga = 25000;
        }
        else if (strcmp(kode, "RD") == 0) {
            strcpy(nama, "Rendang");
            harga = 30000;
        }
        else if (strcmp(kode, "AG") == 0) {
            strcpy(nama, "Ayam Goreng");
            harga = 22000;
        }
        else if (strcmp(kode, "ST") == 0) {
            strcpy(nama, "Soto Ayam");
            harga = 20000;
        }
        else if (strcmp(kode, "BU") == 0) {
            strcpy(nama, "Bakso Urat");
            harga = 18000;
        }
        else if (strcmp(kode, "MA") == 0) {
            strcpy(nama, "Mie Ayam");
            harga = 17000;
        }
        else if (strcmp(kode, "IB") == 0) {
            strcpy(nama, "Ikan Bakar");
            harga = 40000;
        }
        else {
            printf("Kode tidak valid!\n");
            continue;
        }

        total = harga * porsi;
        total_semua += total;

        printf("%-15s\t%d\t%d\t%d\n", nama, porsi, harga, total);
    }

    printf("=====================================================\n");
    printf("Total Pembayaran\t\t\t%d\n", total_semua);

    return 0;
}