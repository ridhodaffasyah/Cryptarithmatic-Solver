/* NAMA     : RIDHO DAFFASYAH
   NIM      : 13519038
   KELAS    : 01

   TUGAS KECIL 1 - IF2211 STRATEGI ALGORITMA

   Penyelesaian Cryptarithmetic dengan Algoritma Brute Force

*/

/* HEADER */
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <time.h>
#include <cstring>
#include <vector>

using namespace std;

/* KAMUS LOKAL */
ifstream in_stream;
vector<string> list_operan;
vector<char> list_huruf_unik;
string str;
char semuahurufdioperan[10];
int panjang = 0;
int nilaihuruf[10] = {0};
int i, j, k, angka1, angka2, angka3, percobaan, solusi;

/* FUNGSI-FUNGSI */
int faktorial(int n){
	if(n == 0){
		return 1;
	}
	else {
		return n*faktorial(n - 1);
	}
}

/* FUNGSI UNTUK MENCARI NILAI PERMUTASI */
int permutasi(int n, int r){
	return faktorial(n)/faktorial(n - r);
}

/* FUNGSI UNTUK MEMASUKKAN NILAI KE SUATU HURUF */
void masukinnilaikeHuruf(){
	int i = panjang - 1;
	nilaihuruf[i] = nilaihuruf[i] + 1;
	while (nilaihuruf[i] == 10){
        nilaihuruf[i] = 0;
        i = i - 1;
        nilaihuruf[i] = nilaihuruf[i] + 1;
	}
}

/* FUNGSI UNTUK MENGETAHUI NILAI SUATU HURUF DARI POSISI NYA*/
int posisi(char str[], char c){
	int i, panjangchar;
	panjangchar = strlen(str);
	for(i = 0; i < panjangchar; i++){
		if(str[i] == c){
			return nilaihuruf[i];
		}
	}
}

/* UNTUK MENGETAHUI POSISI SUATU HURUF */
int posisihuruf(char str[], char c){
    for(int i = 0; i < strlen(str); i++){
        if(c == str[i]){
            return i;
        }
    }
}

/* FUNGSI UNTUK MEMISAHKAN HURUF-HURUF YANG UNIK */
void hanyaunik(char str[])
{
	int i, j, panjangchar;
	panjangchar = strlen(str);
	for(i = 0; i < panjangchar; i++){
		for(j = panjang - 1; j >= 0; j--){
			if(semuahurufdioperan[j] == str[i]){
				break;
			}
		}
		if(j == -1){
			semuahurufdioperan[panjang] = str[i];
			panjang = panjang + 1;
		}
	}
}

/* PROGRAM UTAMA */
int main(){

    /* MEMBUKA FILE EKSTERNAL */
    in_stream.open("../test/soal.txt");

    /* MEMBACA ISI FILE EKSTERNAL */
    while (!in_stream.eof()){
        in_stream >> str;
        /* MENGISI LIST DENGAN CHAR DARI BELAKANG */
        list_operan.push_back(str);
    }
    list_operan.pop_back();

    /* JIKA LEBIH DARI 2 OPERAN */
    if (list_operan.size()>4){
        exit(3);
        return 3;
    }

    /* MENAMPILKAN ISI TEXT */
    if (list_operan[0].size() < list_operan[1].size()){
        for (i = list_operan[0].size(); i < list_operan[1].size() - 1; i++){
                cout << " ";
        }
        cout << list_operan[0] << "\n";
        for (i = 1; i <= list_operan.size(); i++){
            cout << list_operan[i];
            cout << "\n";
        }
    }
    else{
        cout << list_operan[0] << "\n";
        for (i = list_operan[1].size(); i <= list_operan[0].size(); i++){
                cout << " ";
        }
        cout << list_operan[1] << "\n";
        for (i = 0; i<list_operan[3].size(); i++){
                cout << "-";
        }
        cout << "\n" << list_operan[3];
    }

    /* MENGHITUNG WAKTU KETIKA DIMULAI PROGRAM SAMPAI AKHIR PROGRAM */
    clock_t tStart = clock();

    /* MEMISAHKAN HURUF YANG UNIK / BERBEDA KE DALAM LIST HURUF UNIK */
    char operan1[list_operan.size()];
    char operan2[list_operan.size()];
    char operan3[list_operan.size()];

    for (i = 0; i < list_operan[0].size(); i++){
        operan1[i] = list_operan[0][i];
    }
    for (i = 0; i < list_operan[1].size() - 1; i++){
        operan2[i] = list_operan[1][i];
    }
    for (i = 0; i<list_operan[3].size(); i++){
        operan3[i] = list_operan[3][i];
    }

    hanyaunik(operan1);
    hanyaunik(operan2);
    hanyaunik(operan3);

    int huruf1 = 0;
    int huruf2 = posisihuruf(semuahurufdioperan, operan2[0]);
    int huruf3 = posisihuruf(semuahurufdioperan, operan3[0]);

    /* JIKA JUMLAH HURUF DI DALAM OPERAND LEBIH DARI 10 */
    if(panjang > 10){
		cout << "Jumlah huruf di dalam operand paling banyak 10 buah!";
		return 0;
	}

    /* MENCARI KEMUNGKINAN ANGKA DARI LIST HURUF DENGAN BRUTE FORCE */
    if (list_operan.size()<4){
        percobaan = permutasi(10,panjang);
        cout << "\nPercobaan yang seharusnya dilakukan  : " << percobaan;
    }

    solusi = 0;

	for(i = 1; i <= percobaan; i++){
		masukinnilaikeHuruf();
		for(j = 0; j < panjang; j++){
			for(k = j+1; k < panjang; k++){
				if(nilaihuruf[j] == nilaihuruf[k]){
					masukinnilaikeHuruf();
					j=-1;
					break;
				}
			}
		}

        angka1 = 0; angka2 = 0; angka3 = 0;

        /* MENGISI ANGKA SESUAI DENGAN POSISI HURUF DI OPERAN */
        for(j = 0; j < list_operan[0].size(); j++){
            angka1 = (angka1*10) + posisi(semuahurufdioperan,operan1[j]);
        }
        for(j = 0; j < list_operan[1].size()-1; j++){
            angka2 = (angka2*10) + posisi(semuahurufdioperan,operan2[j]);
        }
        for(j = 0; j < list_operan[3].size(); j++){
            angka3 = (angka3*10) + posisi(semuahurufdioperan,operan3[j]);
        }

        /* SOLUSI BERUPA HASIL PENJUMLAHAN DI KEDUA OPERAN DAN HURUF PERTAMA TIDAK BOLEH 0*/
        if((angka1 + angka2 == angka3) && (nilaihuruf[huruf1] != 0) && (nilaihuruf[huruf2] != 0) && (nilaihuruf[huruf3] != 0)){
            solusi++;
            if (solusi > 1){
                break;
            }
            else {
                cout << "\nTotal percobaan yang telah dilakukan : " << i << "\n\n";
                if (list_operan[0].size() < list_operan[1].size()){
                    for (i = list_operan[0].size(); i < list_operan[1].size() - 1; i++){
                        cout << " ";
                    }
                    cout << angka1 << "\n";
                    cout << angka2 << '+' << "\n";
                    for (i = 0; i<list_operan[3].size(); i++){
                        cout << "-";
                    }
                    cout << "\n" << angka3;
                    cout<<"\n\nWaktu yang diperlukan:" <<endl<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<" detik"<<endl;
                }
                else {
                    cout << angka1 << "\n";
                    for (i = list_operan[1].size(); i <= list_operan[0].size(); i++){
                        cout << " ";
                    }
                    cout << angka2 << '+' << "\n";
                    for (i = 0; i<list_operan[3].size(); i++){
                        cout << "-";
                    }
                    cout << "\n" << angka3;
                    cout<<"\n\nWaktu yang diperlukan:" <<endl<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<" detik"<<endl;
                }
            }
        }
	}
    return 0;
}

