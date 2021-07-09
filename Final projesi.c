#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>                               //KULLANACAÐIMIZ KÜTÜPHANELERÝ TANIMLIYORUZ
#include<string.h>                  
#include<ctype.h>  
#include<time.h>       
#include <locale.h>


        






 void KelimePratigi();
 void Credits();
 void KelimeListeleri();
 void YeniKelimeGirisi();                       //FONKSÝYONLARIMIZI TANIMLIYORUZ
 void KelimeSil();
 void AnlamSil();
 void KelimeleriDuzenle();
 void EkraniTemizle();
 void AnlamListeleri();
 
 
 void EkraniTemizle() {                        //EKRANITEMÝZLE FONKSÝYONUMUZUN ÝÞLEVÝNÝ TANIMLIYORUZ
system("CLS");                                //system("CLS") Komutu ile fonksiyonumuzu çaðýrdýðýmýz yerde ekraný temizleyip programýn daha temiz çalýþmasýný amaçlýyoruz.
 }
 
 
   
COORD coord = {0, 0};                      

void gotoxy (int x, int y)                                                //GOTOXY FONKSÝYONUMUZUN ÝÞLEVÝNÝ TANIMLIYORUZ
{                                                                         //gotoxy FONKSÝYONU ÝÇERÝSÝNE BELÝRTTÝÐÝMÝZ KOORDÝNATLARA GÝTMEMÝZÝ SAÐLAR. ÖRN/ gotoxy(20,20)
coord.X = x; coord.Y = y;                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {                                                //ANA SAYFAMIZI OLUÞTURUYORUZ
	setlocale(LC_ALL, "Turkish");                           //TÜRKÇE KARAKTERLERÝ KULLANMAK ÝÇÝN GEREKLÝ FONKSÝYONU YAZIYORUZ
	EkraniTemizle();                                      //EKRANDA DAHA ÖNCEDEN KALAN BÝR ÞEY VARSA ONU TEMÝZLÝYORUZ

int secenek;
gotoxy(20,3);	
  printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YABANCI DIL KELIME PRATIGINE HOSGELDINIZ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");  //BAÞLIK
  
  do {
   gotoxy(20,5);
   printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");               //YAPMAK ÝSTEDÝÐÝ ÝÞLEMÝ SORUYORUZ.
   printf("\n 1- Kelimeleri Duzenle: \n");
   printf("\n 2- Kelime Calismasina Gir: \n");
   printf("\n 3- Emegi Gecenler: \n");
   printf("\n 4- Cikis \n");
   printf(" :");
   scanf("%d", &secenek);                  //TERCÝHÝNÝ ALIYORUZ
   
   switch(secenek)                  //BÝR SWÝTCH-CASE DÖNGÜSÜ KURARAK KULLANICININ SEÇÝMÝ DOÐRULTUSUNDA ÝSTEDÝÐÝ ÝÞLEME GÝRMESÝNÝ SAÐLIYORUZ
   {
    case 1:
    KelimeleriDuzenle();
    case 2:
    KelimePratigi();
    break;
    case 3:
    Credits();
    case 4:                                              // CASE 4, YANÝ CÝKÝSÝ SEÇTÝYSE PROGRAMI EXÝT(0) KOMUTU ÝLE SONLANDIRIYORUZ
    printf("Daha Sonra Gorusmek Uzere :) ");
    exit(0);
    break;
    
   }
  }
  while(secenek!=4);                 

}	


void KelimeleriDuzenle() {                               //KelimeleriDuzenle FONKSÝYONUMUZU TANIMLIYORUZ
	EkraniTemizle();                         
	
	int op;
	EkraniTemizle();
	
	do {
	gotoxy(20,3);                                         //BURADA BÝR SAYFA DAHA YARATIP KULLANCININ BU MENÜ ÝÇERÝSÝNDE NE YAPMAK ÝSTEDÝÐÝNÝ ÖÐRENÝYORUZ
   printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");
   printf("\n 1- Yeni Kelime Girisi: \n");
   printf("\n 2- Kelime Silme: \n");
   printf("\n 3- Kelime Listelerini Goruntule: \n");
   printf("\n 4- Anlam Listelerini Goruntule: \n ");
   printf("\n 5- Ana Menuye Don: \n ");
   scanf("%d", &op);                                    //TERCÝHÝNÝ ALIYORUZ
   
   switch(op) {                                          //YÝNE SWÝTCH-CASE DÖNGÜSÜ KURARAK KULLANCIYI TERCÝHÝ DOÐRULTUSUNDA YÖNLENDÝRÝYORUZ
   	
   case 1:
   YeniKelimeGirisi();
   break;
   case 2:
    KelimeSil();
    break;
    case 3:
    EkraniTemizle();
    KelimeListeleri();
    break;
    case 4:
    AnlamListeleri();
    case 5:
    main();
    break;
   }
	}
	while(op!=6);
  
   
	
}



void YeniKelimeGirisi() {                      //YeniKelimeGirisi FONKSÝYONUMUZU TANIMLIYORUZ
	       
	EkraniTemizle();                            //BU FONKSÝYONUMUZ KULLANICININ SÝSTEME YENÝ KELÝMELER EKLEMESÝNÝ SAÐLIYOR
	gotoxy(20,3);
	int baslik, i, m, tercih;
	

	
	printf("\nLutfen Yeni Girmek Istediginiz Kelime Sayisini Belirtiniz:");                 //KULLANICININ SÝSTEME EKLEMEK ÝSTEDÝÐÝ KELÝME SAYÝSÝNÝ ÖÐRENÝYORUZ          
	scanf("%d", &m);
	char kelimeler[100][100];                                                              //KELÝMELER DÝZÝMÝZÝ TANIMLIYORUZ
	char anlamlar[100][100];                                                               //ANLAMLAR DÝZÝMÝZÝ TANIMLIYORUZ
	
	FILE *fp;                                                                          //FILE *fp KOMUTU ÝLE DOSYA ÝÞLEMLERÝNE BAÞLIYORUZ
	fp=fopen("Kelimeler","a");                                                         //fp OLARAK KELÝMELERÝMÝZÝN TUTULDUÐU "Kelimeler" txt DOSYAMIZI "a" ÝLE OLAÐAN METÝNÝN ÜZERÝNE EKLEYECEK ÞEKÝLDE AÇIYORUZ
	
	FILE *fp1;                                                                         //AYNI ÝÞLEMÝ KELÝMELERÝMÝZÝN ANLAMLARININ TUTULDUÐU "Anlamlar.txt" DOSYASINI ÝÇÝN YAPIYORUZ
	fp1=fopen("Anlamlar", "a");
	
	
	printf(" Lutfen Yeni Girmek Istediginiz Kelimeleri teker teker giriniz:\n ");          //EKLEMEK ÝSTEDÝÐÝ KELÝMELERÝ SIRAYLA ÝSTÝYORUZ
	printf("\nLUTFEN ILK KELIMEYE GIRIS YAPMAYINIZ, ENTER TUSUNA BIR KERE BASARAK 2. KELIMEDEN BASLAYINIZ\n");
	for(i=1;  i<=m; i++) {                                                      //FOR DÖNGÜSÜNÜ KULLANICININ EKLEMEK ÝSTEDÝÐÝ KELÝME SAYISINCA ARTTIRARAK KELÝMELERÝ TEK TEK ALIYORUZ

	printf("\n\nLutfen %d. kelime ve anlamini giriniz:\n\n ", i);
	
	
	printf("\n %d. kelime " ,i);
	fgets(kelimeler,100,stdin);                                                
	fputs(kelimeler,fp);                                                 //ALDIÐIMIZ KELÝMELERÝN fp ÝLE TANIMLADIÐIMIZ KELÝMELER DOSYASINA YAZILMASINI ÝSTEDÝÐÝMÝZÝ BELÝRTÝYORUZ
	
	printf("\n     anlami ");                                              //KELÝMELERÝN ANLAMLARINI ALIYORUZ
	fgets(anlamlar,100,stdin);
	fputs(anlamlar, fp1);                                               //ANLAMLARI fp1 ÝLE TANIMLADIÐIMIZ ANLAMLAR DOSYASINA YAZDIRIYORUZ
	
	
	}	
	
	printf("\n");
	fclose(fp);                                               //KELÝMELER DOSYAMIZI ÝÞÝMÝZ BÝTTÝÐÝ ÝÇÝN KAPATIYORUZ
	fclose(fp1);                                              //ANLAMLAR DOSYAMIZI ÝÞÝMÝZ BÝTTÝÐÝ ÝÇÝN KAPATIYORUZ
	
	do {
		
		
	printf("Kelime Girisine Devam Etmek Istiyor musunuz ? (1/2)\n");           //KULLANICIYA BAÞKA KELÝME EKLEMEK ÝSTEYÝP ÝSTEMEDÝÐÝNÝ SORUYORUZ
	scanf("%d", &tercih);
	
	switch(tercih) {          //SWÝTCH-CASE ÝLE ÝSTEÐÝNÝ GERÇEKLEÞTÝRÝYORUZ
	
	case 1:	
	printf("\n");
	YeniKelimeGirisi();
	break;
	
	case 2:
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");	           //KULLANICI BAÞKA KELÝME EKLEMEK ÝSTEMÝYORSA ANA MENÜYE YÖNLENDÝRÝYORUZ
	printf("\n");
	getch();
	main();
	break;
	}
	
	}
	while(tercih !=2);
	}
	
	
	
	
	
	void AnlamSil() {                                     //AnlamSil FONKSÝYONUMUZU TANIMLIYORUZ
	EkraniTemizle();                                         //BU FONKSÝYONUMUZUN AMACI KULLANICININ ARTIK ÇALIÞMAK ÝSTEMEDÝÐÝ VEYA YARARLI GÖRMEDÝÐÝ KELÝMELERÝ LÝSTEDEN SÝLMESÝDÝR
	gotoxy(20,3);	                                          //BU FONKSÝYON TEKÝL OLARAK ÇALIÞMAZ, KULLANICI KELÝME SÝLMEK ÝSTERSE ANLAMINI DA LÝSTEDEN SÝLMESÝ ÝÇÝN BU FONKSYÝONA YÖNLENDÝRÝLÝR
	
	
	printf("\nProgramin Guvenilirligini Arttirmak Acisindan Lutfen Sildiginiz Kelimenin Anlamini Da Siliniz: \n");
		
	
	
	char Anlamlar[100][100];                       //ANLAM DÝZÝMÝZÝ TANIMLIYORUZ
	
	char anlam[256];                        //KULLANICININ SÝLMEK ÝSTEDÝÐÝ ANLAMI ATACAÐAMIZ DEÐÝÞKENÝ TANIMLIYORUZ
	FILE *fp1;                             
	FILE *fp3;
	
	fp1=fopen("Anlamlar", "r");                //fp1 OLARAK ANLAMLARIMIZIN BULUNDUÐU "anlamlar.txt" KLASÖRÜNÜ "r" ÝLE OKUNMAK ÜZERE AÇIYORUZ
	fp3=fopen("TempAnlamlar", "a");	              //fp3 OLARAK KULLANICININ SÝLMEK ÝSTEDÝÐÝ ANLAMI SÝLÝP GERÝ KALANLARI TEKRAR YAZACAÐIMIZ GEÇÝCÝ BÝR "TempAnlamlar.txt" DOSYASINI "a" ÝLE ÜZERÝNE EKLENECEK ÞEKÝLDE AÇIYORUZ
		
		
	printf("\nSildiginiz Kelimenin Anlamini Giriniz: \n");      //SÝLÝNMESÝ ÝSTENEN ANLAMI ALIYORUZ
	scanf("%s", &anlam[256]);
	
	while(fscanf(fp1,"%s", &Anlamlar[100][100])!=EOF) {      //WHÝLE DÖNGÜSÜ ÝLE fp1 ÝLE BELÝRTTÝÐÝMÝZ ANLAMLAR DOSYASININ EOF ÝLE SONUNA KADAR ÝLERLÝYORUZ VE FSCANF ÝLE ANLAMLAR DÝZÝMÝZE TAÞIYORUZ
		
		
		
		
	if(strcmp(&anlam[256],&Anlamlar[100][100])==0) {      //ÝF DÖNGÜSÜ ÝLE KULLANICININ GÝRDÝÐÝ KELÝMENÝN GÝRDÝÐÝ KELÝMENÝN ANLAMLAR DÝZÝMÝZ ÝÇERÝSÝNDE OLUP OLMADIÐINI strcmp==0 ÝLE SORGULUYORUZ
		
		
	printf("%s kelimesi silindi! \n", &anlam[256]);        //KULLANICININ VERDÝÐÝ KELÝMENÝN SÝLÝNDÝÐÝ BELÝRTÝP ANA MENÜYE YÖNLENDÝRÝYORUZ
	printf("Ana Menu Icin enter");
	
	}
	else {
		
	fprintf(fp3, "%s\n", &Anlamlar[100][100]);             //KELÝMELER DÝZÝMÝZÝ YENÝ ANLAMLAR DÝZÝSÝ OLARAK KULLANACAÐIMIZ, fp3 ÝLE TANIMLADIÐIMIZ "TempAnlamlar.txt" DOSYASININ ÝÇÝNE fprintf ÝLE YAZIYORUZ         
	}
	}
	
	
	
	fclose(fp1);            //DOSYALARIMIZI KAPATIYORUZ
	fclose(fp3);
	remove("Anlamlar");           //ANLAMLAR DOSYAMIZI SÝLÝYORUZ
	rename("TempAnlamlar","Anlamlar");     //TempAnlamlar DOSYAMIZ ANLAMLARI TUTTUÐUMUZ YENÝ DOSYAMIZ OLACAÐI ÝÇÝN ADINI Anlamlar OLARAK DEÐÝÞTÝRÝYORUZ
		
		
		
		
	
	getch();           
	
	main();                 //ANA MENÜYE DÖNDÜRÜYORUZ
		
		
		
		
		
		
	}
	
	
	void KelimeSil() {                 //KelimeSil FONKSÝYONUMUZU TANIMLIYORUZ
		                                
	EkraniTemizle();                //BU FONKSÝYON KULLANICININ LÝSTEDEN KELÝME SÝLMESÝNÝ SAÐLAR
	gotoxy(20,3);
	
	
	
	
	
		
	char Kelimeler[100][100];                            //KELÝMELER DÝZÝMÝZÝ TANIMLIYORUZ
	
	char kelime[256];                             //KULLANICIDAN ALACAÐIMIZ SÝLÝNMESÝ ÝSTENEN KELÝMEYÝ ATAYACAÐIMIZ STRÝNGÝ TANIMLIYORUZ
	FILE *fp;
	FILE *fp2;
	
	fp=fopen("Kelimeler", "r");                    //fp OLARAK KELÝMELERÝMÝZÝN TUTULDUÐU "Kelimeler.txt" DOSYASINI "r" ÝLE OKUMAK ÝÇÝN AÇIYORUZ
	fp2=fopen("TempKelimeler", "a");	            //fp2 OLARAK KULLANICININ SÝLÝNMESÝNÝ ÝSTEDÝÐÝ KELÝMEYÝ SÝLÝP GERÝSÝ TEKRAR YAZACAÐIMIZ "TempKelimeler" DOSYASINI "a" ÝLE ÜZERÝNE EKLENECEK ÞEKÝLDE AÇIYORUZ.
		
		
	printf("Silmek Istediginiz Kelimeyi Seciniz: ");        //SÝLÝNMESÝ ÝSTENEN KELÝMEYÝ ALIYORUZ
	scanf("%s", &kelime[256]);
	
	while(fscanf(fp,"%s", &Kelimeler[100][100])!=EOF) {           //WHÝLE DÖNGÜSÜ ÝLE fp ÝLE BELÝRTTÝÐÝMÝZ KELÝMELER DOSYASININ EOF ÝLE SONUNA KADAR ÝLERLÝYORUZ VE FSCANF ÝLE KELÝMELER DÝZÝMÝZE TAÞIYORUZ
		
		
		
		
	if(strcmp(&kelime[256],&Kelimeler[100][100])==0) {           //ÝF DÖNGÜSÜ KURARAK KULLANICININ SÝLÝNMESÝNÝ ÝSTEDÝÐÝ KELÝMENÝN DÝZÝDE OLUP OLMADIÐINI strcmp==0 ÝLE TEST EDÝYORUZ
		
		
	printf("%s kelimesi silindi! \n", &kelime[256]);           //KULLANICIYA VERDÝÐÝ KELÝMENÝN SÝLÝNDÝÐÝNÝ BELÝRTÝP ANA MENÜYE YÖNLENDÝRÝYORUZ
	
	printf("Ana Menu Icin enter");
	
	
	}
	else {
		
	fprintf(fp2, "%s\n", &Kelimeler[100][100]);               //GERÝ KALAN KELÝMELERÝMÝZÝ fp2 ÝLE AÇTIÐIMIZ "TempKelimeler.txt" DOSYAMIZIN ÝÇÝNE FPRÝNTF ÝLE YAZIYORUZ.
	
	}
	}
	
	
	
	fclose(fp);                                     //ÝÞÝMÝZ BÝTTÝÐÝ ÝÇÝN DOSYALARIMIZI KAPATIYORUZ.
	fclose(fp2);
	remove("Kelimeler");                                //"Kelimeler.txt" DOSYAMIZI SÝLÝYORUZ
	rename("TempKelimeler","Kelimeler");                //"TempKelimeler" DOSYAMIZ, KELÝMELERÝ TUTACAÐIMIZ YENÝ DOSYAMIZ OLDUÐU ÝÇÝN ADINI "Kelimeler.txt" OLARAK DEÐÝÞTÝRÝYORUZ
	
	AnlamSil();                                        //KULLANICININ SÝLÝNMESÝ ÝSTEDÝÐÝ KELÝMEYÝ SÝLDÝKTEN SONRA ANLAMINI DA LÝSTEDEN SÝLMESÝ ÝÇÝN AnlamSil FONKSÝYONUNA YÖNLENDÝRÝYORUZ
	getch();
	
	main();                                            
	}
	
	
void AnlamListeleri() {                            //AnlamListeleri FONKSÝYONUMUZU TANIMLIYORUZ
	
	EkraniTemizle();                                     //BU FONKSÝYONUN KULLANICININ LÝSTEMÝZDE BULUNAN ANLAMLARI UYGULAMA ÝÇÝNDE GÖRÜNTÜLEMESÝNÝ SAÐLAR
	
	char ch;
	FILE *fp1;
	printf("\n");
	fp1 = fopen("Anlamlar","r");                            //fp1 ÝLE "Anlamlar" DOSYAMIZI "r" ÝLE OKUNMAK ÜZERE AÇIYORUZ
	
	if(fp1 == NULL)                                           //if DÖNGÜSÜ KURARAK fp1 ÝLE AÇTIÐIMIZ "Anlamlar" DOSYAMIZI SORGULUYORUZ. fp1==NULL ÝLE LÝSTENÝN ÝÇÝNÝN BOÞ OLUP OLMADIÐINI ANLIYORUZ
	{
	printf("Dosya Bulunamadi\n");                                    //EÐER fp1 BOÞSA KULLANICIYA DOSYANIN BOÞ OLDUÐUNU BELÝRTÝP ANA MENÜYE YÖNLENDÝRÝYORUZ
	
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	main();
	}
	else                                                           
	{	
	while((ch=fgetc(fp1))!=EOF)                          //EÐER fp1 BOÞ DEÐÝLSE ch=fgetc(fp1) ÝLE LÝSTENÝN ÝÇÝNDEKÝ ANLAMLARI ch DÝZÝMÝZE LÝSTENÝN SONUNA GÝDENE KADAR AKTARIYORUZ            
	
	{
	printf("%c",ch);                                            //ANLAMLARIMIZI EKRANA YAZDIRIYORUZ
    }
	}
	fclose(fp1);	                                                      //DOSYAMIZI KAPATIP KULLANICIYI BÝR ÖNCEKÝ MENÜ OLAN KelimeleriDuzenle'ye YÖNLENDÝRÝYORUZ
	printf("\nBir Onceki Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	KelimeleriDuzenle();

	EkraniTemizle();
	
	
	
}	
	
	
	

void KelimeListeleri() {                            //KelimeListeleri FONKSÝYONUMUZU TANIMLIYORUZ
	
	EkraniTemizle();                                    //BU FONKSÝYONUMUZUN AMACI KELÝMELER SÝSTEMÝZÝ KULLANICININ UYGULAMA ÝÇÝNDE GÖRÜNTÜLEMESÝDÝR
	
	int secenek;
	char ch;
	FILE *fp;
	printf("\n");
	fp = fopen("Kelimeler","r");                               //KELÝMELERÝMÝZÝN TUTULDUÐU "Kelimeler" DOSYAMIZI "r" ÝLE OKUNMAK ÜZERE AÇIYORUZ
	
	if(fp == NULL)                                                 //EÐER fp ÝLE TANITTIÐIMIZ DOSYAMIZ BOÞ ÝSE KULLICIYA DOSYANIN BULUNAMADIÐINI BELÝRTÝP ANA MENÜYE YÖNLENDÝRÝYORUZ
	{
	printf("Dosya Bulunamadi\n");
	
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	main();
	}
	else
	{	
	while((ch=fgetc(fp))!=EOF)                                       //EÐER fp ÝLE TANITTIÐIMIZ DOSYAMIZ BOÞ DEÐÝLSE ch=fgetc(fp) ÝLE LÝSTENÝN SONUNA GÝDENE KADAR ch DÝZÝMÝZÝN ÝÇÝNE YAZDIRIYORUZ
	
	{
	printf("%c",ch);                                                 //KELÝMELERÝMÝZÝ EKRANA YAZDIRIYORUZ
    }
	}
	fclose(fp);	                                                       //DOSYAMIZI KAPATIYORUZ
	
	do { 
	printf("\nAnlam Listesini Gormek Icin Lutfen 1 e basiniz ");                   //KULLANICININ ÝÞLEMÝ BÝTÝRDÝKTEN SONRA NE YAPMAK ÝSTEDÝÐÝ ÖÐRENMEK ÝÇÝN BÝR SWÝTCH-CASE DÖNGÜSÜ KURUYORUZ
	printf("\nBir Onceki Menuye Donmek Icin 2 ye Basiniz: ");
	scanf("%d", &secenek);
	switch(secenek) {
		
	case 1:
	AnlamListeleri();                                                 //KULLANICI 1'E TIKLARSA ANLAM LÝSTEMÝZÝ GÖRÜNTÜLÜYORUZ
	break;
	case 2:
	KelimeleriDuzenle();                                                       //KULLANICI 2'YE TIKLARSA BÝR ÖNCEKÝ MENÜ OLAN KelimeleriDüzenleye YÖNLENDÝRÝYORUZ
	break;
	}
	
	}
	while(secenek!=2);
	getch();
	EkraniTemizle();
}
	
void Credits() {                                                                   //Credits FONKSÝYONUMUZU TANIMLIYORUZ
	system("CLS");
	
	
	printf("     Yusuf KALAYLI \n\a");                                                //EMEÐÝ GEÇENLERÝ VE REFERANSLARIN BULUNDUÐU KLASÖRÜ TANIMLIYORUZ
	printf("     Kaynakca 'ReadMe' Klasorunun icindedir \n");
	printf(" Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	
	main();                                                    //ANA MENÜYE YÖNLENDÝRÝYORUZ
}









void KelimePratigi() {                                      //KelimePratiði FONKSÝYONUMUZU TANIMLIYORUZ
	
	setlocale(LC_ALL, "Turkish");                           //TÜRKÇE KARAKTERLERÝ KULLANMAK ÝÇÝN GEREKLÝ FONKSÝYONU YAZIYORUZ

	system("CLS");                                              //BU FONKSÝYON UYGULAMAMIZIN ASIL AMACI OLAN KELÝME ÇALIÞMASINI YAPMAMIZA YARDIMCI OLAN FONKSÝYONDUR
	int m, i, j;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YABANCI DIL KELIME PRATIGINE HOSGELDINIZ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  gotoxy(20,5);
   printf("\xDB Lutfen Calismak istediginiz kelime sayisini giriniz: ");              //KULLANICIDAN KAÇ KELÝME ÇALIÞMAK ÝSTEDÝÐÝNÝ ÖÐRENÝYORUZ
   scanf("%d", &m);
   
   FILE *fp;
   FILE *fp1;
   
   fp = fopen("Kelimeler", "r");                            //fp ÝLE "Kelimeler" DOSYAMIZI "r" ÝLE OKUNMAK ÜZERE AÇIYORUZ
   fp1 = fopen("Anlamlar", "r");                               //fp1 ÝLE "Anlamlar" DOSYAMIZI "r" ÝLE OKUNMAK ÜZERE AÇIYORUZ
   
   char kelimeler[100][100];                                      //KELÝMELER VE ANLAMLAR OLMAK ÜZERE ÝKÝ ADET DÝZÝ AÇIYORUZ, BUNLARIN ÝÇERÝSÝNE KULLANICIYA SORMAK ÜZERE KELÝMELERÝ VE ANLAMLARI AKTARACAÐIZ
   char anlamlar[100][100];
   //char kelimeler1[20][20];
  
   
   if(m>20) {    gotoxy(20,8);  EkraniTemizle();   printf("Harvard Universitesinde yapilan bir arastirmaya gore yabanci dilde kelime pratigi yapmak icin ideal kelime sayisi 20'dir. Biraz daha kolaydan baslamak sizin icin daha iyi olacaktir :)\a");
    }                                       //EÐER KULLANICI 20 KELÝMEDEN DAHA FAZLA ÇALIÞMAK ÝSTERSE VERÝMLÝLÝÐÝ ARTTIRMAK ÝÇÝN DAHA DÜÞÜK SAYIDA KELÝME ÝLE ÇALIÞMASI GEREKTÝÐÝ SÖYLÜYORUZ
  else {
  	
gotoxy(20,8);                        
int n=0;
int f=0;
char t[100][100];

while(!feof(fp)) {                            //BÝR WHÝLE DÖNGÜSÜ AÇARAK fp ÝLE AÇTIÐIMIZIN DOSYANIN SONUNA KADAR DEVAM EDÝYORUZ
	
	fscanf(fp, "%s", &t[n][100]);                        //fscanf ÝLE fp DOSYAMIZIN ÝÇÝNDE KELÝMELERÝ ALIP t ÝLE AÇTIÐIMIZ DÝZÝMÝZÝN ÝÇÝNE YAZDIRIYORUZ
	strcpy(&kelimeler[n][100], &t[n][100]);                    //strcpy ÝLE t DÝZÝMÝZÝN ÝÇÝNDEKÝ VERÝLERÝ kelimeler DÝZÝMÝZÝN ÝÇÝNE KOPYALIYORUZ
	n++;                                       //n++ ÝLE n sayisini arttýrarak tüm kelimelerimizi alýyoruz
}
while(!feof(fp1)) {                           //BÝR WHÝLE DÖNGÜSÜ DAHA AÇARAK AYNI ÝÞLEMÝ fp1 ÝLE AÇTIÐIMIZIN ANLAMLAR DOSYASI ÝÇÝN YAPIYORUZ
	
	fscanf(fp1, "%s", &t[f][100]);
	strcpy(&anlamlar[f][100], &t[f][100]);
	f++;
	
}

    

int uzunluk, q, r;

printf("                   \xDB\xDB\xB2 Evet, Hazirsaniz Baslayalim\n\n");                                      //KULLANICIYA OYUNUN GENEL MANTIÐI TANITILIYOR
printf("                   \xDB Girmis oldugunuz %d kelime size karisik sekillerde sorulacaktir.\n", m);
printf("                   \xDB Ve arka arkaya %d dogru cevap verene kadar program devam edecektir.\n", m);
printf("                   \xDB Bildiginiz kelimeler size tekrar sorulmayacaktir :) \n\n\n");
printf("                   \xDB LUTFEN KUCUK HARF KULLANINIZ  \n\n\n");
printf("                   \xDB LUTFEN TURKCE HARF KULLANMAYINIZ (Ü,Ö,Ð,Þ,Ç, I) BUNLARIN YERÝNE (U,O,G,S,C, Ý) KULLANINIZ \n\n\n");
	int dc=0, yc=0;
   
 
while(dc<m){                  //dc ÝLE TANIMLADIÐIMIZ DOÐRU CEVAP SAYIMIZ m ÝLE KULLANICIDAN ALDIÐIMIZ KELÝME SAYISINDAN KÜÇÜK OLDUÐU SÜRECE WHÝLE DÖNGÜSÜ ÝLE UYGULAMANIN ÇALIÞMASI SAÐLANIYOR
	
	
	for(i=1; i<=m; i++) {          //BÝR for DÖNGÜSÜ KURARAK ÝÞE BAÞLIYORUZ, i'yi KELÝME SAYIMIZ OLAN m'ye KADAR ARTTIRIYORUZ
	char cevap[50];               //KULLANICININ VERMÝÞ OLDUÐU CEVAPLARI ALACAÐIMIZ BÝR STRÝNG TANIMLIYORUZ

	int rastgele;                   //KULLANICIYA SORULARI RASTGELE BÝR ÞEKÝLDE SORMAK ÝÇÝN KULLANACAÐIMIZ "RASTGELEYÝ" TANIMLIYORUZ
	srand(time(NULL));               //"RASTGELE" NÝN, 1 ÝLE KELÝME SAYIMIZ OLAN m ARASINDA RASTGELE BÝR DEÐER ALMASINI SAÐLIYORUZ
    rastgele=1+rand()%100;
	
	
     


	
	printf("%s kelimesinin anlami nedir: ", &kelimeler[rastgele]);                 //RASTGELE SEÇÝLEN KELÝMÝZÝ KULLANICIYA SORUP CEVABINI ALIYORUZ
	scanf("%s",&cevap[i]);
	
	
	if(strcmp(&cevap[i],&anlamlar[rastgele])==0) {                                      //KULLANICININ VERDÝÐÝ CEVAP, ANLAMLAR LÝSTEMÝZDE O KELÝMENÝN KARÞILIÐI MIDIR strcmp==0 ÝLE SORGULUYORUZ
	
	int o;                                                 
	dc++;                                        //CEVAP DOÐRU ÝSE dc ÝLE TANITTIÐIMIZ DOÐRU CEVABI ARTTIRIYORUZ
	o=(m-dc);
	//sayac++;
	
	
	if(dc<m) {                                                         //YAZIM HATASI OLMAMASI ÝÇÝN BURADA BÝR ÝF DÖNGÜSÜ AÇIYORUZ (SON SORUYA GELÝNCE 0 SORUNUZ KALDI YAZMAMASI AMACIYLA)
	printf("Tebrikler! Cevaplamaniz Gereken %d Soru Kaldi\n\n", o);      //KULLANICIYA CEVABININ DOÐRU OLDUÐUNU VE DOÐRU CEVAPLAMASI GEREKEN SORU SAYISINI BELÝRTÝYORUZ
	}
	
	
	}
	else {
	printf("               Yanlis Cevap! Lutfen Daha Dikkatli Olunuz arkaya arkaya bilmeniz gereken soru sayisi %d \n\n", m);    //EÐER CEVAP YANLIÞSA KULLANICIYI UYARIP TEKRAR m KADAR KELÝME DOÐRU CEVAPLAMASI GEREKTÝÐÝNÝ BELÝRTÝYORUZ
	dc=0;               //PROGRAMIMIZ ARKA ARKAYA ÇALIÞMASI ÝSTENEN KELÝME KADAR DOÐRU CEVAP VERÝLMESÝNÝ AMAÇLADIÐINDAN YANLIÞ CEVAP ALINCA dc SAYIMIZI 0 YAPIYORUZ
	}
	
	
	
	
	

	
	
	}
	

	
	
	
 }
 printf(" \nTebrikler Girmis Oldugunuz %d Kelimeyi Basariyla Tamamladiniz, \nBiraz dinlendikten sonra yeni kelimeler geciniz :) \a\n" ,m);	 //EÐER KULLANICI ARKA ARKAYA m KADAR SORUYA DOÐRU CEVAP VERMÝÞSE KENDÝSÝNÝ TEBRÝK EDÝP ÇALIÞMAYI SONLANDIRIYORUZ
printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz");                                   //ANA MENÜYE YÖNLENDÝRÝYORUZ
getch();
EkraniTemizle();
}


}




	
	
