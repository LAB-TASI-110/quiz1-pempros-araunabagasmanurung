#include <stdio.h>

int main() {
    int N;

    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    int nilai[N];

    printf("Masukkan deret nilai:\n");
    for(int i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    int kodeKelompok;
    printf("Masukkan kode kelompok: ");
    scanf("%d", &kodeKelompok);

    int index = 0;
    int level = 1;
    int total = 0;

    while(index < N) {
        for(int i = 0; i < level && index < N; i++) {
            if(level == kodeKelompok) {
                total += nilai[index];
            }
            index++;
        }
        level++;
    }

    if(total == 0) {
        printf("Kelompok tidak ditemukan atau kosong.\n");
    } else {
        printf("Total nilai kelompok %d adalah: %d\n", kodeKelompok, total);
    }

    return 0;
}