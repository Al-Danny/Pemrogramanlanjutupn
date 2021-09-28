#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//deklarasi struct
typedef struct data
{
	char nama[20];
	char npm[20];
}data;

struct pribadi
{
	data data;
	char kelas[20];
	char jurusan[20 ];
}dt[100];
//akhir deklarasi struct

int lastIndex = 0;
int i;
void input();
void view();
int cari();
void perbarui();
void edit();
void del();
void pencarian();

//deklarasi menu dengan function
void menubase ()
{
	system("cls");
	int menu;
	printf ("\t\t\t==================================\n");
	printf ("\t\t\t     Manajemen Data Mahasiswa\n");
	printf ("\t\t\t==================================\n\n");
	printf (" 1. Tambahkan data\n");
	printf (" 2. Tampilkan data\n");
	printf (" 3. Update data\n");
	printf (" 4. delete data\n");
	printf (" 5. pencarian data\n");
	printf (" 6. exit\n");
	printf (" ---------------------------\n");
	printf (" Masukkan Angka Pilihan : ");
	scanf  ("%d",&menu);
	switch(menu)
	{
		case 1:
			input();
		break;
		
		case 2:
			view();
		break;
		
		case 3:
			perbarui();
		break;
		
		case 4:
			del();
		break;
		
		case 5:
			pencarian();
		break;
		
		case 6:
			system ("exit");
			system ("cls");
			printf (" Terima Kasih telah berkunjung");
		break;
		
		default :
			system ("cls");
			printf (" Maaf Inputan Salah silahkan pilih kembali\n");
			system ("pause");
			menubase();
		break;
	}
}
//akhir deklarasi function menu

//deklarasi function 1
void input()
{
	system ("cls");
	fflush(stdin);
	printf ("===================\n");
	printf (" Tambah data\n");
	printf ("===================\n");
    printf (" Nama       : ");
	gets(dt[lastIndex].data.nama);
	printf (" NPM        : ");
	gets(dt[lastIndex].data.npm);
	printf (" Jurusan    : ");
	gets(dt[lastIndex].jurusan);
	printf (" Kelas      : ");
	gets(dt[lastIndex].kelas);
	lastIndex++;
	menubase();	
}
//akhir deklarasi function 1

//deklarasi function 2
void view()
{
	system ("cls");
	for (i=0;i<lastIndex;i++)
	{
		printf  ("%d.",i+1);
		printf  ("\tNama       : %s\n",dt[i].data.nama);
		printf  ("\tNPM        : %s\n",dt[i].data.npm);
		printf  ("\tKelas      : %s\n",dt[i].kelas);
		printf  ("\tJurusan    : %s\n",dt[i].jurusan);
	}
	system ("pause");
	menubase();	
}
//akhir deklarasi function 2

//deklarasi function cari
int cari(char npm[20])
{
	int i = 0;
	int data = -1;
    while (i<lastIndex && data<0)
    {
        if (strcmp(dt[i].data.npm, npm) == 0)
        {
            data = i;
        }
        i++;
    }
    return data;
}
//akhir deklarasi

//deklarasi function dalam function 3
void perbarui ()
{
	fflush(stdin);
	char npm[20];
	printf (" Masukkan npm yang ingin diupdate : ");
	gets(npm);
	int index = cari(npm);
	if (index<0)
	{
		fflush(stdin);
		printf (" Data yang dicari tidak ada !!!");
		system ("pause");
		menubase();
	}
	else
	{
		edit(index);
	}
}
//akhir deklarasi function 3


//deklarasi function function 3
void edit(int baru)
{
	system("cls");
	printf (" Nama       : ");
	gets(dt[baru].data.nama);
	printf (" NPM        : ");
	gets(dt[baru].data.npm);
	printf (" Jurusan    : ");
	gets(dt[baru].jurusan);
	printf (" Kelas      : ");
	gets(dt[baru].kelas);
	printf (" Data telah terupdate\n\n");
	system ("pause");
	menubase();
}
//akhir deklarasi



//deklarasi function hapus
void hapus(int index)
{
	int lokasi = 0;
	for (i=0;i<lastIndex;i++)
	{
		if (i != index)
		{
			dt[lokasi]=dt[i];
			lokasi++;
		}
	}
	lastIndex--;
	printf (" Data Telah Terhapus\n\n");
	system (" pause ");
	menubase();
}
//akhir deklarasi

//deklarasi function 4
void del()
{
	fflush(stdin);
	char npm[20];
	printf (" Masukkan Npm yang ingin dihapus : ");
	gets(npm);
	int index = cari (npm);
	if (index<0)
	{
		fflush(stdin);
		printf (" Data tidak ditemukan !!!!\n");
		system ("pause");
		menubase();
	}
	else
	{
		hapus(index);
	}
}
//akhir deklarasi function 4

//deklarasi function 5
void pencarian ()
{
	char cari[20];
	fflush(stdin);
	printf (" Masukkan Nama atau NPM data yang dicari : ");
	gets(cari);
	system ("cls");
	int urutan = 1;
	for(i=0;i<lastIndex;i++)
	{
		if (strcmp(dt[i].data.nama, cari) == 0 || strcmp(dt[i].data.npm, cari) == 0)
		{
			printf  ("%d.",urutan);
			printf  ("\tNama       : %s\n",dt[i].data.nama);
			printf  ("\tNPM        : %s\n",dt[i].data.npm);
			printf  ("\tKelas      : %s\n",dt[i].kelas);
			printf  ("\tJurusan    : %s\n",dt[i].jurusan);
			urutan++;
		}
		else if (urutan == 1)
		{
			fflush(stdin);
			printf (" Data tidak ditemukan !!!!\n");
			system ("pause");
		}
	}
	system ("pause");
	menubase();
}
//akhir deklarasi function 5


int main ()
{
	menubase();
	return 0;
}
