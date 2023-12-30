// Library yang digunakan
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Deklarasi Fungsi yang digunakan
int faktorialRekursif(int a);           // Fungsi Faktorial dengan cara rekursif
int faktorialIteratif(int a);           // Fungsi Faktorial dengan cara iteratif
int kombinasi(int n, int m);            // Fungsi perhitungan Kombinasi
int permutasi(int n, int m);            // Fungsi perhitungan Permutasi
void swap(char* x, char* y);            // Fungsi menukar elemen dalam array
void kejadian(char* a, int l, int r);   // Fungsi menampilkan himpunan permutasi
static void fungsimain(void);

// Inisialisasi variabel global yang digunakan
static int jumlah = 0;                  // Variabel untuk menghitung jumlah pemanggilan fungsi

// Fungsi main
int main(void){

    // Event Handler
    bool quit = false;
    int keluar;

    while (!quit)
    {   
        if (keluar == 1)
        {
            quit = true;
        }
        else
        {
            fungsimain();
        }  
        scanf("%d", &keluar);
    }
    return 0;
}

// Inisialisasi fungsi faktorial dengan cara rekursif
int faktorialRekursif(int a){
    
    // base case
    if (a == 0 || a == 1)   
    {
        return 1;
    }

    // recursive case
    else
    {
        return a * faktorialRekursif(a-1);  
    }
    
    
}

// Inisialisasi fungsi faktorial dengan cara iteratif
int faktorialIteratif(int a){
    int hasil = 1;                  // Inisialisasi variabel hasil
    for (int i = 1; i <= a; i++)    // Inisialisasi perulangan untuk menghitung hasil
    {
        hasil = hasil * i;          // Modifikasi nilai variabel hasil
    }
    return hasil; 
    
}

// Inisialisasi fungsi perhitungan jumlah kombinasi
int kombinasi(int n, int m){
    return faktorialRekursif(n) / (faktorialRekursif(m) * faktorialRekursif(n-m));
}

// Inisialisasi fungsi perhitungan jumlah permutasi
int permutasi(int n, int m){
    return faktorialIteratif(n) / faktorialIteratif(n-m);
}

// Inisialisasi fungsi menukar elemen dalam array
void swap(char* x, char* y) { 
    char temp;              // Inisialisasi variabel temporer
    temp = *x;              // Memasukkan nilai pointer x ke dalam variabel temporer
    *x = *y;                // Memasukkan nilai pointer y ke dalam pointer x
    *y = temp;              // Memasukkan nilai variabel temporer ke dalam pointer y
} 

// Inisialisasi fungsi penampilan himpunan kejadian permutasi
void kejadian(char* a, int l, int r) { 
    int i;                          // Deklarasi variabel i
    
    // base case
    if (l == r)                     // Memeriksa apakah nilai l (indeks awal array) sama dengan r (indeks akhir array)
    {
        printf("%s\n", a);          // Output string ketika nilai l (indeks awal array) sama dengan r (indeks akhir array)
        jumlah = jumlah + 1;        // Modifikasi nilai variabel jumlah permutasi yang terjadi
    } 

    // recursive case
    else 
    { 
        for (i = l; i <= r; i++)    // Inisialisasi perulangan untuk mengiterasi setiap elemen dalam array string 
        { 
            swap((a + l), (a + i)); // Menukar elemen dalam indeks (a + l) pada string dengan elemen dalam indeks (a + i) dalam string
            kejadian(a, l + 1, r);  // Memanggil fungsi kejadian() untuk elemen selanjutnya
            swap((a + l), (a + i)); // Mengembalikan posisi elemen dalam array string seperti sebelum pemanggilan fungsi swap() pertama
        } 
    } 
}

static void fungsimain(void){
    // Header program
    printf("=============================================\n");
	printf("         PROGRAM PERMUTASI KOMBINASI         \n");
	printf("=============================================\n");

    // Deklarasi variabel dalam main
    char x;                 // Variabel yang digunakan untuk mengambil keputusan eksekusi program permutasi atau kombinasi
    char str[100] = "";     // Variabel yang digunakan untuk menyimpan string dalam fungsi menampilkan permutasi
    int n,                  // Variabel yang digunakan untuk menyimpan nilai input n (jumlah kejadian yang bisa dipilih) dalam fungsi
        m,                  // Variabel yang digunakan untuk menyimpan nilai input m (jumlah kejadian yang harus dipilih) dalam fungsi 
        z;                  // Variabel yang digunakan untuk mengambil keputusan eksekusi program jumlah permutasi atau himpunan kejadian

    // Meminta input user untuk mengambil keputusan eksekusi program permutasi atau kombinasi
    printf("Kombinasi [K] / Permutasi [P]? ");
    scanf("%c", &x);
    printf("\n");
    x = tolower(x);         // Memastikan input user selalu dalam keadaan lowercase

    // Program Permutasi
    if (x == 'p')           // Memeriksa input user
    {
        // Meminta input user untuk mengambil keputusan eksekusi program menghitung jumlah permutasi atau menampilkan himpunan kejadian
        printf("=============================================\n");
        printf("Jumlah permutasi [1], Himpunan kejadian[2]: ");
        scanf("%d", &z);
        
        // Memeriksa input user
        switch (z)
        {
        case 1:             // Menghitung Jumlah Permutasi
            printf("=====================nPm=====================\n");

            // Meminta user menginput nilai n untuk permutasi nPm
            printf("Masukkan nilai n: ");
            scanf("%d", &n);

            // Meminta user menginput nilai r untuk permutasi nPm
            printf("Masukkan nilai m: ");
            scanf("%d", &m);

            if (m > n)      // Menguji apakah permutasi bisa dilakukan
            {
             printf("Hasil tidak terdefinisikan\n");        // Output ketika permutasi tidak bisa dilakukan
            }
            else
            {
                printf("Hasil dari %d Permutasi %d adalah %d\n", n, m, permutasi(n, m));    // Output ketika permutasi berhasil dilakukan
            }

            printf("=============================================\n");
            printf("Selesai [1] atau ulangi [2]?  ");
            break;
        
        case 2:             // Menampilkan himpunan kejadian permutasi serta jumlahnya
            printf("===============Permutasi=====================\n");

            // Meminta user menginput string yang akan ditampilkan himpunan kejadian permutasinya
            printf("Masukkan string: ");
            scanf("%s", &str);

            // Inisialisasi variabel n dengan masukkan panjang dari string yang telah diinput oleh user
            int n = strlen(str); 

            // Pemanggilan fungsi kejadian untuk menampilkan himpunan kejadian permutasi dari string yang telah diinput oleh user
            kejadian(str, 0, n - 1);

            // Mencetak output jumlah kejadian permutasi
            printf("Jumlah kejadian: %d\n", jumlah);
            printf("=============================================\n");
            printf("Selesai [1] atau ulangi [2]?  ");
            break;
        }
        
    }

    // Program Kombinasi
    else if (x == 'k')      // Memeriksa input user
    {
        printf("=====================nCm=====================\n");
        
        // Meminta user menginput nilai n untuk Kombinasi nCm
        printf("Masukkan nilai n: ");
        scanf("%d", &n);

        // Meminta user menginput nilai m untuk Kombinasi nCm
        printf("Masukkan nilai m: ");
        scanf("%d", &m);
        
        // Menguji apakah kombinasi bisa dilakukan
        if (m > n)
        {
            printf("Hasil tidak terdefinisikan\n");     // Output ketika kombinasi tidak dapat dilakukan
        }
        else
        {
            printf("Hasil dari %d Kombinasi %d adalah %d\n", n, m, kombinasi(n, m));    // Output ketika kombinasi berhasil dilakukan
        }

        printf("=============================================\n");
        printf("Selesai [1] atau ulangi [2]?  ");
    }

    else
    {
        printf("================INPUT SALAH!!================\n");  // Output ketika user salah memasukkan input pemilihan program permutasi atau kombinasi
    }
}