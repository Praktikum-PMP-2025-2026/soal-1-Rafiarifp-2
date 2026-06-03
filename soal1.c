/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3
 *   Hari dan Tanggal    : Rabu, 3 Juni 2026
 *   Nama (NIM)          : Rafi Arif Putra (13224033)
 *   Nama File           : soal1.c
 *   Deskripsi           : Fungsi yang mengurutkan data artefak berdasarkan beberapa kriteria
 * 
 */

// Source:
// 1. https://www.geeksforgeeks.org/c/qsort-function-in-c/ ()
// 2. https://www.geeksforgeeks.org/c/sort-array-of-structs-based-on-a-member-in-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Artefak {
    char nama[50];
    char kategori[50];
    int tahun;
    int nilai;
} Artefak;

// comparator function (tahun)
int compareByTahun(const void* a, const void* b)
{
    return ((struct Artefak*)a)->tahun - ((struct Artefak*)b)->tahun;
}

// comparator function (nilai)
int compareByNilai(const void* a, const void* b)
{
    return ((struct Artefak*)b)->tahun - ((struct Artefak*)a)->tahun;
}

// comparator function (nama)
int compareByNama(const void *a, const void *b) {
    return strcmp(((struct Artefak*)a)->nama, ((struct Artefak*)b)->nama);
}

// comparator function (kategori)
int compareByKategori(const void *a, const void *b) {
    return strcmp(((struct Artefak*)a)->kategori, ((struct Artefak*)b)->kategori);
}

int main(){
    char temp;
    int n, i, j;

    // scanf n & deklarasi array of artefak berukuran n
    scanf("%d", &n);
    Artefak arr[n];

    // for loop sebanyak n kali untuk n inputs
    for(int i=0;i<n;i++){
        scanf("%s %s %d %d", &arr[i].nama, &arr[i].kategori, &arr[i].tahun, &arr[i].nilai);
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    // sorting algorithm berdasarkan alphabet kategori
    qsort(arr, n, sizeof(struct Artefak), compareByKategori);

    // sorting algorithm berdasarkan tahun untuk kategori yang sama
    for(int i=0;i<n-1;i++){
        if(arr[i].kategori == arr[i+1].kategori){
            qsort(arr, n, sizeof(struct Artefak), compareByTahun);
        }
    }

    // sorting algorithm berdasarkan nilai untuk kategori & tahun yang sama
    for(int i=0;i<n-1;i++){
        if(arr[i].kategori == arr[i+1].kategori){
            if(arr[i].tahun == arr[i+1].tahun){
                qsort(arr, n, sizeof(struct Artefak), compareByNilai);
            }
        }
    }
    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %d\n", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }

    return 0;
}
