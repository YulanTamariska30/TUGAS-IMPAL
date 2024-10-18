#include <stdio.h>
#include <string.h>

// Struktur untuk mendefinisikan barang di keranjang
typedef struct {
    char namaBuku[50];
    int harga;
    int jumlah;
} Barang;

// Fungsi untuk mencari buku berdasarkan nama di keranjang
int cariBuku(char namaBuku[], int jumlahBarang, Barang keranjang[]) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(keranjang[i].namaBuku, namaBuku) == 0) {
            return i; // Mengembalikan indeks buku jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika buku tidak ditemukan
}

int main() {
    Barang keranjang[100]; // Kapasitas maksimal keranjang adalah 100 item
    int jumlahBarang = 0;  // Jumlah barang dalam keranjang
    char namaDicari[50];   // Variabel untuk nama buku yang ingin dicari
    char lagi;             // Variabel untuk menambahkan buku lagi

    // Memasukkan beberapa buku ke dalam keranjang
    do {
        // Meminta input nama buku
        printf("Masukkan nama buku: ");
        scanf(" %[^\n]", keranjang[jumlahBarang].namaBuku);

        // Meminta input harga buku
        printf("Masukkan harga buku: ");
        scanf("%d", &keranjang[jumlahBarang].harga);

        // Meminta input jumlah buku yang dibeli
        printf("Masukkan jumlah buku: ");
        scanf("%d", &keranjang[jumlahBarang].jumlah);

        jumlahBarang++; // Menambah jumlah barang di keranjang

        // Menanyakan apakah ingin menambah buku lagi
        printf("Apakah Anda ingin menambah buku lagi ke keranjang? (y/n): ");
        scanf(" %c", &lagi);

    } while (lagi == 'y' || lagi == 'Y'); // Perulangan selama pelanggan memilih 'y' atau 'Y'

    // Menampilkan detail keranjang belanja
    printf("\nKeranjang belanja Anda:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d. %s - Harga: %d x Jumlah: %d\n", i + 1, keranjang[i].namaBuku, keranjang[i].harga, keranjang[i].jumlah);
    }

    // Mencari buku berdasarkan nama
    printf("\nMasukkan nama buku yang ingin dicari: ");
    scanf(" %[^\n]", namaDicari);

    int indeksBuku = cariBuku(namaDicari, jumlahBarang, keranjang);

    if (indeksBuku != -1) {
        // Jika buku ditemukan, tampilkan detailnya
        printf("\nBuku ditemukan:\n");
        printf("Nama Buku: %s\n", keranjang[indeksBuku].namaBuku);
        printf("Harga: %d\n", keranjang[indeksBuku].harga);
        printf("Jumlah: %d\n", keranjang[indeksBuku].jumlah);
    } else {
        // Jika buku tidak ditemukan, tampilkan pesan kesalahan
        printf("\nBuku '%s' tidak ditemukan di keranjang.\n", namaDicari);
    }

    return 0;
}
