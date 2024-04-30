#include <iostream>
using namespace std;

//fungsi untuk menghitung checksum dari nomor kartu
int Hitungchecksum(long long nomor_kartu)                 //fungsi dengan parameter nomor_kartu tipe long
{
    int total = 0;
    bool dua_digit = false;                               //jika true maka proses digit ke 2 dari kanan, jika false proses digit pertama dari kanan

// loop untuk menghitung nomor kartu sampai habis atau > 0
    while (nomor_kartu > 0)
    {
        int digit = nomor_kartu % 10;

        if (dua_digit)
        {
            digit *= 2;                                   // jika dua_digit adalah true maka kali 2
            if (digit > 9)                                // jika hasil kali 2 > 9 atau 2 digit maka kurangi 9
                digit -= 9;
        }
        total += digit;                                   // Menambahkan digit (setelah diubah jika dua_digit adalah true) ke total checksum
        dua_digit = !dua_digit;                           // Mengubah nilai dua_digit menjadi kebalikannya untuk menandakan digit berikutnya
        nomor_kartu /= 10;                                // Menghapus digit paling kanan dari nomor kartu
    }
    return total;                                         // Mengembalikan total dari perhitungan checksum
}

int main()
{
    long long nomor_kartu;                                //deklarasi tipe data
    int jumlah_digit = 0;
    cout << "Masukkan Nomor Kartu Anda : ";
    cin >> nomor_kartu;                                   //memasukkan nomor kartu yang kan dicek

//hitung checksum dengan memanggil function Hitungchecksum
    int checksum = Hitungchecksum(nomor_kartu);

// Menghitung jumlah digit nomor kartu
    long long temp_nomor_kartu = nomor_kartu;
    while (temp_nomor_kartu != 0) {
        temp_nomor_kartu /= 10;
        jumlah_digit++;
    }

    string tipe_kartu = "TIDAK DIKETAHUI";

//identifikasi tipe kartu berdasarkan jumlah digit dan checksum
    if ((jumlah_digit == 13 || jumlah_digit == 16) && nomor_kartu / 1000000000000000 == 4 && checksum % 10 == 0)
    {
        tipe_kartu = "VISA";
    }
    else if (jumlah_digit == 16 && (nomor_kartu / 100000000000000 >= 51 && nomor_kartu / 100000000000000 <= 55) && checksum % 10 == 0)
    {
        tipe_kartu = "MASTERCARD";
    }
    else if (checksum % 10 != 0)
    {
        tipe_kartu = "TIDAK VALID";
    }

// menampilkan hasil pada terminal
    cout << "Nomor Kartu Anda : " << nomor_kartu << endl;
    cout << "Tipe Kartu Anda : " << tipe_kartu << endl;
    cout << "Checksum : " << checksum << endl;
    return 0;
}