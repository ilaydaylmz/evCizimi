/***************************************************************************************************************************************************************************************************
**                                                                          SAKARYA ÜNİVERSİTESİ
**                                                              BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ 
**                                                                     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                                                         PROGRAMLAMAYA GİRİŞ DERSİ
**
**                                                                           ÖDEV NUMARASI:ÖDEV2
**                                                                           ÖĞRENCİ ADI:İLAYDA YILMAZ
**                                                                           ÖĞRENCİ NUMARASI:B201210057
**                                                                           DERS GRUBU:1B GRUBU
**************************************************************************************************************************************************************************************************/
#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y)     //istediğim koordinatlara gitmesini sağlayan fonksiyonu tanımladım.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Cati           //catı adında bir class olşturdum.
{
public:
	int genislik;
	int yukseklik;
	int x;
	int y;
	int cati_yuksekligi;
	void Cati_ciz(int yukseklik , int genislik, int x, int y,int cati_yuksekligi)   //cati ciz adında fonksiyon oluşturdum.
	{
		gotoxy(x, y);
		for (int i = 1; i <= genislik; i = i + 1)             //girilen genişlik ve yükseklikte cati oluşmasını sağlayan for döngüleri kurdum.
		{
        	cout << "\n";
			for (int j = 1; j <=genislik- i; j++)
			{
				cout << " ";
			}
			for (int k = 1; k <=i*2+1;k++)
			{
				  cout << "*";
			}
		}
		cout << endl;
		return;
	}
};
class Kat                //kat adında class oluşturdum.
{
public:
	int yukseklik;
	int genislik;
	char a = 219;
	int x;
	int y;
	void Kat_ciz(int yukseklik, int genislik,int x, int y)                    //kat çiz adında fonksiyon oluşturdum.
	{
		
		for (int i = 0; i < genislik*2; i++)                     //kat çizmemi sağlayan for döngüleri oluşturdum.
		{
			cout << (char)219 << "";
		}
		cout << endl;
		
		for (int j = 0; j < (yukseklik - 2); j++)
		{
			cout << (char)219 << " ";
			for (int k = 0; k < (genislik - 2) * 2 + 1; k++)
			{
				
				cout << " ";
			}
			cout << (char)219 << "\n";
		}
		
		for (int i = 0; i < genislik*2; i++)
		{
			
			cout << (char)219 << "";
		}
		
		cout << endl;
    }
};
class Kapi              //kapı adında bir class oluşturdum.
{
public:
	int x;
	int y;
	void Kapi_ciz(int yukseklik, int genislik, int x, int y)             //kapi ciz adında bir fonksiyon oluşturdum.
	{
		for (int i = 0; i <(yukseklik/3); i++)                            //yükseklik ve genişlik ile orantılı bir boya sahip olan kapıyı çizen for döngüleri krdum.
		{
			gotoxy(x + genislik / 2, y + yukseklik / 2);
			for (int j = 0; j <(genislik/3); j++)
			{
				cout << "#";
			}
			cout << "\n";
		}
		return;
	}
};
class Ev :public Cati, public Kat,public Kapi   //kalıtım ile kurduğun ev sınıfına cati .kat ve kapı sınıflarını tanımladım.
{
public:
	int yukseklik;
	int genislik;
	int x;
	int y;
	int cati_yuksekligi;
	void Ev_ciz()                //ev çiz fonsiyonunun içine kat ciz , kapi ciz,cati çiz fonksiyonlarını çağırdım vee dışarıdan girilen değerler ile istenilen şekli çizdirdim.
	{
		cout << "yukseklik:";
		cin >> yukseklik;
		cout << "genislik:";
		cin >> genislik;
		cout << "cati yukseklik:";
		cin >> cati_yuksekligi;
		cout << "x:";
		cin >> x;
		cout << "y:";
		cin >> y;

		Cati_ciz(yukseklik, genislik, x, y,cati_yuksekligi);
		Kat_ciz(yukseklik, genislik, x, y);
		Kapi_ciz(yukseklik, genislik, x, y);
	 }

};
int main()
{
	Ev ev1;    //ev sınıfından ev1 adında bir nesne tanımladım
	ev1.Ev_ciz();             //ev1 sınıfı ev çiz fonksiyonunu çağırdı ve evi çizdirdi.
	cin.get();        
	return 0;               //programı başarılı bir şekilde sonlandırdım.
}