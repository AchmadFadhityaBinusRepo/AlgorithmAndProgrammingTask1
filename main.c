#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define GAJI_POKOK 2000000
#define JAM_KERJA_NORMAL_PERBULAN 173
#define BONUS_LEMBUR_PERJAM 3000
#define IS_MATCH 0
#define TRUE 1
#define FALSE 0

// --- Pendefinisian Tipe Data Komposit
typedef struct {
    float gajiPokok;
    float tunjanganPendidikan;
    float tunjanganJabatan;
    float bonusLembur;
    float gajiTotal;
} Gaji;

typedef struct {
    char nama[255];
    char pendidikan[5];
    int golongan;
    float jumlahJamKerja;
    Gaji gaji;
} Karyawan;
// --- Akhir Pendefinisian Tipe Data Komposit

// --- Prototipe Fungsi
void toUpperString(char *str);
float hitungTunjanganJabatan(int golongan);
float hitungTunjanganPendidikan(char *pendidikan);
int isHasOverTimeHour(float jumlahJamKerja);
float hitungBonusLembur(float jumlahJamKerja);
Gaji hitungGaji(char *pendidikan, int golongan, float jumlahJamKerja);
void inputKaryawan(Karyawan *karyawan);
void showResult(Karyawan karyawan);
// --- Akhir Prototipe Fungsi

// --- Main Program
int main() {
    Karyawan karyawan;
    inputKaryawan(&karyawan);
    karyawan.gaji = hitungGaji(karyawan.pendidikan, karyawan.golongan, karyawan.jumlahJamKerja);
    showResult(karyawan);
    return 0;
}
// --- Akhir Main Program


void toUpperString(char *str){
    for (int i=0; i<sizeof(str); i++){
        str[i] = toupper(str[i]);
    }
}

float hitungTunjanganJabatan(int golongan){
    switch (golongan) {
        case 1:
            return 0.05 * GAJI_POKOK;
        case 2:
            return 0.1 * GAJI_POKOK;
        case 3:
            return 0.15 * GAJI_POKOK;
        default:
            return 0 * GAJI_POKOK;
    }
}

float hitungTunjanganPendidikan(char *pendidikan){
    if (strcmp(pendidikan, "SMA") == IS_MATCH){
        return 0.025 * GAJI_POKOK;
    } else if (strcmp(pendidikan, "D3") == IS_MATCH){
        return 0.05 * GAJI_POKOK;
    } else if (strcmp(pendidikan, "S1") == IS_MATCH){
        return 0.1 * GAJI_POKOK;
    } else {
        return 0 * GAJI_POKOK;
    }
}

// Dikarenakan di soal tidak diberi keterangan total jam kerja normal dalam 1 bulan
// maka saya mengambil referensi dari internet yang menyatakan di indonesia
// 1 bulan total jam kerjanya adalah 173 jam
// sumber: https://sleekr.co/blog/ketentuan-jam-kerja-karyawan/
int isHasOverTimeHour(float jumlahJamKerja){
    if (jumlahJamKerja > JAM_KERJA_NORMAL_PERBULAN){
        return TRUE;
    } else {
        return FALSE;
    }
}

float hitungBonusLembur(float jumlahJamKerja){
    float jamLebih = jumlahJamKerja - JAM_KERJA_NORMAL_PERBULAN;
    return jamLebih * BONUS_LEMBUR_PERJAM;
}

Gaji hitungGaji(char *pendidikan, int golongan, float jumlahJamKerja) {
    Gaji gaji;
    gaji.gajiPokok = GAJI_POKOK;
    gaji.tunjanganJabatan = hitungTunjanganJabatan(golongan);
    gaji.tunjanganPendidikan = hitungTunjanganPendidikan(pendidikan);
    gaji.bonusLembur = 0;

    if (isHasOverTimeHour(jumlahJamKerja)){
        gaji.bonusLembur = hitungBonusLembur(jumlahJamKerja);
    }

    gaji.gajiTotal = gaji.gajiPokok + gaji.tunjanganJabatan + gaji.tunjanganPendidikan + gaji.bonusLembur;
    return gaji;
}

void inputKaryawan(Karyawan *karyawan){
    printf("**** PROGRAM HITUNG GAJI KARYAWAN ****\n");
    printf("Nama Karyawan:");
    scanf("%255s", &(karyawan->nama));

    printf("Golongan Jabatan:");
    scanf("%d", &(karyawan->golongan));

    printf("Pendidikan:");
    scanf("%5s", &(karyawan->pendidikan));
    toUpperString(karyawan->pendidikan); //menghindari perbedaan case saat input

    printf("Jumlah jam kerja:\t");
    scanf("%f", &(karyawan->jumlahJamKerja));
}

void showResult(Karyawan karyawan){
    printf("\nNama Karyawan: %s", karyawan.nama);
    printf("\n\tTunjangan Jabatan: Rp %0.2f", karyawan.gaji.tunjanganJabatan);
    printf("\n\tTunjangan Pendidikan: Rp %0.2f", karyawan.gaji.tunjanganPendidikan);
    printf("\n\tHonor Lembur: Rp %0.2f", karyawan.gaji.bonusLembur);
    printf("\nTotal Gaji Rp: %0.2f", karyawan.gaji.gajiTotal);
}

int main (){
    int angka = 123; // contoh assignment operator, variabel angka akan memiliki nilai 123
    return 0;
}