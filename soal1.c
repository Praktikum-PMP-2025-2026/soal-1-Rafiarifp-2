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

// Comparison function for sorting based on age (https://www.geeksforgeeks.org/c/sort-array-of-structs-based-on-a-member-in-c/)
int compareByTahun(const void* a, const void* b)
{
    return ((struct Artefak*)a)->tahun - ((struct Artefak*)b)->tahun;
}

int main(){
    char temp_nama[50];
    int n, i, j;

    // scanf n & deklarasi array of artefak berukuran n
    scanf("%d", &n);
    Artefak arr[n];

    // for loop sebanyak n kali untuk n inputs
    for(int i=0;i<n;i++){
        scanf("%s %s %d %d", &arr[i].nama, &arr[i].kategori, &arr[i].tahun, &arr[i].nilai);
    }

    // sorting algorithm berdasarkan tahun
    int size = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(struct Artefak), compareByTahun);

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %d\n", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }

    return 0;
}
