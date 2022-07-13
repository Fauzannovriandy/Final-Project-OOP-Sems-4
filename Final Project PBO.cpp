#include <iostream>
#include <windows.h>
#include <string>
#include <unistd.h>

using namespace std;

//screen loading
void delay() {
	int delay;
	delay=1;
	while(delay<100000000) {
		delay++;
	}
}

void screen_loading(){
	int i;
	char load[] = {'D','E','P','O','T',' ','F','A','N','T','A'};
	for(i=0; i<=11; i++) {
		printf("%c\t", load[i]);
		delay();
	}
	sleep(2);
}

//koordinat tampilan teks
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void garis(int x){
	int z;
	for(z = 0; z < x; z++) {
		printf("=");
	}
	printf("\n");
}

// Fungsi gotoxy untuk mengatur letak
void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//class node/simpul untuk linked list
class Node {
    public:
        string paket;
        Node* next;

        Node(string paket){
            this->paket = paket;
            this->next = NULL;
        }
};

class Menu
{
public:
    double paket;
    double porsi;
    double total;

    Node* head = NULL; //data paling depan di linked list
    Node* tail = NULL; //data paling belakang di linked list

    Menu()
    {
        paket = 0;
        porsi = 0;
        total = 0;
    }

    void addPaket(string paket){ //function add/push back di linked list, menambahkan data baru di belakang
        Node* paketBaru = new Node(paket);

        if(head == NULL){
            head = paketBaru;
        }
        else{
            paketBaru->next = head;
            head = paketBaru;
        }
    }

    double pilih_paket()
    {
        system("CLS");

        cout << "=====================----PAKET----======================= " << endl;
        cout << "=====================----HEMAT----======================= " << endl;
        Node* temp = head;
        int i = 1;
        while(temp != NULL){
            cout << i << ". " << temp->paket << endl;
            i++;
            temp = temp->next;
        }
        cout << "===================----SILAHKAN----===================== " << endl;
        cout << "==================----- DIPILIH ----==================== " << endl;

        gotoxy(70,1);cout << "---------------------------";
        gotoxy(70,2);cout << "   Pilih paket    : ";
        gotoxy(90,2);cin >> this->paket;
        cin.ignore();

        gotoxy(70,3);cout << "   Jumlah porsi   : ";
        gotoxy(90,3);cin >> this->porsi;
        cin.ignore();

        return this->hitung_jumlah();
    }

    double hitung_jumlah()
    {
        if (paket >= 1 && paket <= 4)
        {
            if (paket == 1)
            {
                total = 25000 * porsi;
            }
            else if (paket == 2)
            {
                total = 20000 * porsi;
            }
            else if (paket == 3)
            {
                total = 15000 * porsi;
            }
            else if (paket == 4)
            {
                total = 20000 * porsi;
            }

        }
        return total;
    }

};

class Transaksi : public Menu
{
public:
    Transaksi operator+(const Transaksi& transaksi) { //overloading operator untuk set total
        Transaksi trans;
        trans.total = this->total + transaksi.total;
        trans.paket = this->paket;
        trans.porsi = this->porsi;
        return trans;
    }

    // ================== INI YANG DIUBAH ================================================

    // OVERLOADING FUNCTION
    void display_harga()
    {

            gotoxy(70,4);cout << "   Nomor Paket    : " << this->paket << endl;
            gotoxy(70,5);cout << "   Jumlah Pesanan : " << this->porsi << endl;
            gotoxy(70,6);cout << "   Harga pesanan  : " << this->total << endl;
            gotoxy(70,7);cout << "---------------------------"<< endl;



    }

    void display_harga(bool total)
    {
        gotoxy(35,11);cout << "===================================== " << endl;
        gotoxy(35,12);cout << "       Total harga :        " << this->total << endl;
        gotoxy(35,13);cout << "===================================== " << endl;
    }

    // ==================================================================================

};

class Reservasi
{
public:
    int nomor;
    string nama;

    Reservasi(string nama, int nomor)
    {
        this->nama = nama;
        this->nomor = nomor;
    }

    Reservasi(string nama) //overloading function pada constructor Reservasi
    {
        this->nama = nama;
    }
};

// ======================= SAMA INI ========================================
void buatMenu()
{
    // CUMAN BUAT LOOP PROGRAM
    Transaksi totalTransaksi;
    char lanjut;
    do{
        Transaksi transaksi;
        transaksi.addPaket("Paket A = Nasi Ayam Bakar + Es Teh Manis = Rp25.000");
        transaksi.addPaket("Paket B = Nasi Ikan Goreng + Teh Hangat  = Rp20.000");
        transaksi.addPaket("Paket C = Nasi Goreng + Air Putih        = Rp15.000");
        transaksi.addPaket("Paket D = Nasi Ayam Teriyaki + Es Jeruk  = Rp20.000");

        transaksi.pilih_paket();
        transaksi.display_harga();
        totalTransaksi = totalTransaksi + transaksi;

        gotoxy(35,10);cout<<"Apakah anda ingin memesan lagi? [y/n] : ";
        cin>>lanjut;
    } while(lanjut == 'y');
    totalTransaksi.display_harga(true);

}

int main(int argc, char *argv[])
{
    system("color 17");
	gotoxy(23,12);
	screen_loading();
	system("cls");

    gotoxy(40,0);cout << "=====================================" << endl;
    gotoxy(41,1);cout << "===Selamat Datang di Depot FanTa===" << endl;
    gotoxy(40,2);cout << "=====================================" << endl;
    cout << endl;

    int nomor, pilihan;
    string nama;

    gotoxy(40,3);cout << "======================================";
    gotoxy(40,4);cout << "==        (1) Take away             ==";
    gotoxy(40,5);cout << "==        (2)  Dine in              ==";
    gotoxy(40,6);cout << "==              Pilih :             ==";
    gotoxy(40,7);cout << "==               ( )                ==";
    gotoxy(40,8);cout << "======================================";
    gotoxy(58,7);cin >> pilihan;
    cin.ignore();

    gotoxy(40,9);cout << "==        Nama Pelanggan :          ==";
    gotoxy(67,9);getline(cin, nama);


    if(pilihan == 2){
        gotoxy(40,10);cout << "==        Nomor Meja     :          ==";
        gotoxy(67,10);cin >> nomor;
        cin.ignore();
        Reservasi *reservasi = new Reservasi(nama, nomor);
    }
    else{
        Reservasi *reservasi = new Reservasi(nama);
    }

    buatMenu();

    return 0;
}
