#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>                               //KULLANACA�IMIZ K�T�PHANELER� TANIMLIYORUZ
#include<string.h>                  
#include<ctype.h>  
#include<time.h>       
#include <locale.h>


        






 void KelimePratigi();
 void Credits();
 void KelimeListeleri();
 void YeniKelimeGirisi();                       //FONKS�YONLARIMIZI TANIMLIYORUZ
 void KelimeSil();
 void AnlamSil();
 void KelimeleriDuzenle();
 void EkraniTemizle();
 void AnlamListeleri();
 
 
 void EkraniTemizle() {                        //EKRANITEM�ZLE FONKS�YONUMUZUN ��LEV�N� TANIMLIYORUZ
system("CLS");                                //system("CLS") Komutu ile fonksiyonumuzu �a��rd���m�z yerde ekran� temizleyip program�n daha temiz �al��mas�n� ama�l�yoruz.
 }
 
 
   
COORD coord = {0, 0};                      

void gotoxy (int x, int y)                                                //GOTOXY FONKS�YONUMUZUN ��LEV�N� TANIMLIYORUZ
{                                                                         //gotoxy FONKS�YONU ��ER�S�NE BEL�RTT���M�Z KOORD�NATLARA G�TMEM�Z� SA�LAR. �RN/ gotoxy(20,20)
coord.X = x; coord.Y = y;                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {                                                //ANA SAYFAMIZI OLU�TURUYORUZ
	setlocale(LC_ALL, "Turkish");                           //T�RK�E KARAKTERLER� KULLANMAK ���N GEREKL� FONKS�YONU YAZIYORUZ
	EkraniTemizle();                                      //EKRANDA DAHA �NCEDEN KALAN B�R �EY VARSA ONU TEM�ZL�YORUZ

int secenek;
gotoxy(20,3);	
  printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YABANCI DIL KELIME PRATIGINE HOSGELDINIZ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");  //BA�LIK
  
  do {
   gotoxy(20,5);
   printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");               //YAPMAK �STED��� ��LEM� SORUYORUZ.
   printf("\n 1- Kelimeleri Duzenle: \n");
   printf("\n 2- Kelime Calismasina Gir: \n");
   printf("\n 3- Emegi Gecenler: \n");
   printf("\n 4- Cikis \n");
   printf(" :");
   scanf("%d", &secenek);                  //TERC�H�N� ALIYORUZ
   
   switch(secenek)                  //B�R SW�TCH-CASE D�NG�S� KURARAK KULLANICININ SE��M� DO�RULTUSUNDA �STED��� ��LEME G�RMES�N� SA�LIYORUZ
   {
    case 1:
    KelimeleriDuzenle();
    case 2:
    KelimePratigi();
    break;
    case 3:
    Credits();
    case 4:                                              // CASE 4, YAN� C�K�S� SE�T�YSE PROGRAMI EX�T(0) KOMUTU �LE SONLANDIRIYORUZ
    printf("Daha Sonra Gorusmek Uzere :) ");
    exit(0);
    break;
    
   }
  }
  while(secenek!=4);                 

}	


void KelimeleriDuzenle() {                               //KelimeleriDuzenle FONKS�YONUMUZU TANIMLIYORUZ
	EkraniTemizle();                         
	
	int op;
	EkraniTemizle();
	
	do {
	gotoxy(20,3);                                         //BURADA B�R SAYFA DAHA YARATIP KULLANCININ BU MEN� ��ER�S�NDE NE YAPMAK �STED���N� ��REN�YORUZ
   printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");
   printf("\n 1- Yeni Kelime Girisi: \n");
   printf("\n 2- Kelime Silme: \n");
   printf("\n 3- Kelime Listelerini Goruntule: \n");
   printf("\n 4- Anlam Listelerini Goruntule: \n ");
   printf("\n 5- Ana Menuye Don: \n ");
   scanf("%d", &op);                                    //TERC�H�N� ALIYORUZ
   
   switch(op) {                                          //Y�NE SW�TCH-CASE D�NG�S� KURARAK KULLANCIYI TERC�H� DO�RULTUSUNDA Y�NLEND�R�YORUZ
   	
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



void YeniKelimeGirisi() {                      //YeniKelimeGirisi FONKS�YONUMUZU TANIMLIYORUZ
	       
	EkraniTemizle();                            //BU FONKS�YONUMUZ KULLANICININ S�STEME YEN� KEL�MELER EKLEMES�N� SA�LIYOR
	gotoxy(20,3);
	int baslik, i, m, tercih;
	

	
	printf("\nLutfen Yeni Girmek Istediginiz Kelime Sayisini Belirtiniz:");                 //KULLANICININ S�STEME EKLEMEK �STED��� KEL�ME SAY�S�N� ��REN�YORUZ          
	scanf("%d", &m);
	char kelimeler[100][100];                                                              //KEL�MELER D�Z�M�Z� TANIMLIYORUZ
	char anlamlar[100][100];                                                               //ANLAMLAR D�Z�M�Z� TANIMLIYORUZ
	
	FILE *fp;                                                                          //FILE *fp KOMUTU �LE DOSYA ��LEMLER�NE BA�LIYORUZ
	fp=fopen("Kelimeler","a");                                                         //fp OLARAK KEL�MELER�M�Z�N TUTULDU�U "Kelimeler" txt DOSYAMIZI "a" �LE OLA�AN MET�N�N �ZER�NE EKLEYECEK �EK�LDE A�IYORUZ
	
	FILE *fp1;                                                                         //AYNI ��LEM� KEL�MELER�M�Z�N ANLAMLARININ TUTULDU�U "Anlamlar.txt" DOSYASINI ���N YAPIYORUZ
	fp1=fopen("Anlamlar", "a");
	
	
	printf(" Lutfen Yeni Girmek Istediginiz Kelimeleri teker teker giriniz:\n ");          //EKLEMEK �STED��� KEL�MELER� SIRAYLA �ST�YORUZ
	printf("\nLUTFEN ILK KELIMEYE GIRIS YAPMAYINIZ, ENTER TUSUNA BIR KERE BASARAK 2. KELIMEDEN BASLAYINIZ\n");
	for(i=1;  i<=m; i++) {                                                      //FOR D�NG�S�N� KULLANICININ EKLEMEK �STED��� KEL�ME SAYISINCA ARTTIRARAK KEL�MELER� TEK TEK ALIYORUZ

	printf("\n\nLutfen %d. kelime ve anlamini giriniz:\n\n ", i);
	
	
	printf("\n %d. kelime " ,i);
	fgets(kelimeler,100,stdin);                                                
	fputs(kelimeler,fp);                                                 //ALDI�IMIZ KEL�MELER�N fp �LE TANIMLADI�IMIZ KEL�MELER DOSYASINA YAZILMASINI �STED���M�Z� BEL�RT�YORUZ
	
	printf("\n     anlami ");                                              //KEL�MELER�N ANLAMLARINI ALIYORUZ
	fgets(anlamlar,100,stdin);
	fputs(anlamlar, fp1);                                               //ANLAMLARI fp1 �LE TANIMLADI�IMIZ ANLAMLAR DOSYASINA YAZDIRIYORUZ
	
	
	}	
	
	printf("\n");
	fclose(fp);                                               //KEL�MELER DOSYAMIZI ���M�Z B�TT��� ���N KAPATIYORUZ
	fclose(fp1);                                              //ANLAMLAR DOSYAMIZI ���M�Z B�TT��� ���N KAPATIYORUZ
	
	do {
		
		
	printf("Kelime Girisine Devam Etmek Istiyor musunuz ? (1/2)\n");           //KULLANICIYA BA�KA KEL�ME EKLEMEK �STEY�P �STEMED���N� SORUYORUZ
	scanf("%d", &tercih);
	
	switch(tercih) {          //SW�TCH-CASE �LE �STE��N� GER�EKLE�T�R�YORUZ
	
	case 1:	
	printf("\n");
	YeniKelimeGirisi();
	break;
	
	case 2:
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");	           //KULLANICI BA�KA KEL�ME EKLEMEK �STEM�YORSA ANA MEN�YE Y�NLEND�R�YORUZ
	printf("\n");
	getch();
	main();
	break;
	}
	
	}
	while(tercih !=2);
	}
	
	
	
	
	
	void AnlamSil() {                                     //AnlamSil FONKS�YONUMUZU TANIMLIYORUZ
	EkraniTemizle();                                         //BU FONKS�YONUMUZUN AMACI KULLANICININ ARTIK �ALI�MAK �STEMED��� VEYA YARARLI G�RMED��� KEL�MELER� L�STEDEN S�LMES�D�R
	gotoxy(20,3);	                                          //BU FONKS�YON TEK�L OLARAK �ALI�MAZ, KULLANICI KEL�ME S�LMEK �STERSE ANLAMINI DA L�STEDEN S�LMES� ���N BU FONKSY�ONA Y�NLEND�R�L�R
	
	
	printf("\nProgramin Guvenilirligini Arttirmak Acisindan Lutfen Sildiginiz Kelimenin Anlamini Da Siliniz: \n");
		
	
	
	char Anlamlar[100][100];                       //ANLAM D�Z�M�Z� TANIMLIYORUZ
	
	char anlam[256];                        //KULLANICININ S�LMEK �STED��� ANLAMI ATACA�AMIZ DE���KEN� TANIMLIYORUZ
	FILE *fp1;                             
	FILE *fp3;
	
	fp1=fopen("Anlamlar", "r");                //fp1 OLARAK ANLAMLARIMIZIN BULUNDU�U "anlamlar.txt" KLAS�R�N� "r" �LE OKUNMAK �ZERE A�IYORUZ
	fp3=fopen("TempAnlamlar", "a");	              //fp3 OLARAK KULLANICININ S�LMEK �STED��� ANLAMI S�L�P GER� KALANLARI TEKRAR YAZACA�IMIZ GE��C� B�R "TempAnlamlar.txt" DOSYASINI "a" �LE �ZER�NE EKLENECEK �EK�LDE A�IYORUZ
		
		
	printf("\nSildiginiz Kelimenin Anlamini Giriniz: \n");      //S�L�NMES� �STENEN ANLAMI ALIYORUZ
	scanf("%s", &anlam[256]);
	
	while(fscanf(fp1,"%s", &Anlamlar[100][100])!=EOF) {      //WH�LE D�NG�S� �LE fp1 �LE BEL�RTT���M�Z ANLAMLAR DOSYASININ EOF �LE SONUNA KADAR �LERL�YORUZ VE FSCANF �LE ANLAMLAR D�Z�M�ZE TA�IYORUZ
		
		
		
		
	if(strcmp(&anlam[256],&Anlamlar[100][100])==0) {      //�F D�NG�S� �LE KULLANICININ G�RD��� KEL�MEN�N G�RD��� KEL�MEN�N ANLAMLAR D�Z�M�Z ��ER�S�NDE OLUP OLMADI�INI strcmp==0 �LE SORGULUYORUZ
		
		
	printf("%s kelimesi silindi! \n", &anlam[256]);        //KULLANICININ VERD��� KEL�MEN�N S�L�ND��� BEL�RT�P ANA MEN�YE Y�NLEND�R�YORUZ
	printf("Ana Menu Icin enter");
	
	}
	else {
		
	fprintf(fp3, "%s\n", &Anlamlar[100][100]);             //KEL�MELER D�Z�M�Z� YEN� ANLAMLAR D�Z�S� OLARAK KULLANACA�IMIZ, fp3 �LE TANIMLADI�IMIZ "TempAnlamlar.txt" DOSYASININ ���NE fprintf �LE YAZIYORUZ         
	}
	}
	
	
	
	fclose(fp1);            //DOSYALARIMIZI KAPATIYORUZ
	fclose(fp3);
	remove("Anlamlar");           //ANLAMLAR DOSYAMIZI S�L�YORUZ
	rename("TempAnlamlar","Anlamlar");     //TempAnlamlar DOSYAMIZ ANLAMLARI TUTTU�UMUZ YEN� DOSYAMIZ OLACA�I ���N ADINI Anlamlar OLARAK DE���T�R�YORUZ
		
		
		
		
	
	getch();           
	
	main();                 //ANA MEN�YE D�ND�R�YORUZ
		
		
		
		
		
		
	}
	
	
	void KelimeSil() {                 //KelimeSil FONKS�YONUMUZU TANIMLIYORUZ
		                                
	EkraniTemizle();                //BU FONKS�YON KULLANICININ L�STEDEN KEL�ME S�LMES�N� SA�LAR
	gotoxy(20,3);
	
	
	
	
	
		
	char Kelimeler[100][100];                            //KEL�MELER D�Z�M�Z� TANIMLIYORUZ
	
	char kelime[256];                             //KULLANICIDAN ALACA�IMIZ S�L�NMES� �STENEN KEL�MEY� ATAYACA�IMIZ STR�NG� TANIMLIYORUZ
	FILE *fp;
	FILE *fp2;
	
	fp=fopen("Kelimeler", "r");                    //fp OLARAK KEL�MELER�M�Z�N TUTULDU�U "Kelimeler.txt" DOSYASINI "r" �LE OKUMAK ���N A�IYORUZ
	fp2=fopen("TempKelimeler", "a");	            //fp2 OLARAK KULLANICININ S�L�NMES�N� �STED��� KEL�MEY� S�L�P GER�S� TEKRAR YAZACA�IMIZ "TempKelimeler" DOSYASINI "a" �LE �ZER�NE EKLENECEK �EK�LDE A�IYORUZ.
		
		
	printf("Silmek Istediginiz Kelimeyi Seciniz: ");        //S�L�NMES� �STENEN KEL�MEY� ALIYORUZ
	scanf("%s", &kelime[256]);
	
	while(fscanf(fp,"%s", &Kelimeler[100][100])!=EOF) {           //WH�LE D�NG�S� �LE fp �LE BEL�RTT���M�Z KEL�MELER DOSYASININ EOF �LE SONUNA KADAR �LERL�YORUZ VE FSCANF �LE KEL�MELER D�Z�M�ZE TA�IYORUZ
		
		
		
		
	if(strcmp(&kelime[256],&Kelimeler[100][100])==0) {           //�F D�NG�S� KURARAK KULLANICININ S�L�NMES�N� �STED��� KEL�MEN�N D�Z�DE OLUP OLMADI�INI strcmp==0 �LE TEST ED�YORUZ
		
		
	printf("%s kelimesi silindi! \n", &kelime[256]);           //KULLANICIYA VERD��� KEL�MEN�N S�L�ND���N� BEL�RT�P ANA MEN�YE Y�NLEND�R�YORUZ
	
	printf("Ana Menu Icin enter");
	
	
	}
	else {
		
	fprintf(fp2, "%s\n", &Kelimeler[100][100]);               //GER� KALAN KEL�MELER�M�Z� fp2 �LE A�TI�IMIZ "TempKelimeler.txt" DOSYAMIZIN ���NE FPR�NTF �LE YAZIYORUZ.
	
	}
	}
	
	
	
	fclose(fp);                                     //���M�Z B�TT��� ���N DOSYALARIMIZI KAPATIYORUZ.
	fclose(fp2);
	remove("Kelimeler");                                //"Kelimeler.txt" DOSYAMIZI S�L�YORUZ
	rename("TempKelimeler","Kelimeler");                //"TempKelimeler" DOSYAMIZ, KEL�MELER� TUTACA�IMIZ YEN� DOSYAMIZ OLDU�U ���N ADINI "Kelimeler.txt" OLARAK DE���T�R�YORUZ
	
	AnlamSil();                                        //KULLANICININ S�L�NMES� �STED��� KEL�MEY� S�LD�KTEN SONRA ANLAMINI DA L�STEDEN S�LMES� ���N AnlamSil FONKS�YONUNA Y�NLEND�R�YORUZ
	getch();
	
	main();                                            
	}
	
	
void AnlamListeleri() {                            //AnlamListeleri FONKS�YONUMUZU TANIMLIYORUZ
	
	EkraniTemizle();                                     //BU FONKS�YONUN KULLANICININ L�STEM�ZDE BULUNAN ANLAMLARI UYGULAMA ���NDE G�R�NT�LEMES�N� SA�LAR
	
	char ch;
	FILE *fp1;
	printf("\n");
	fp1 = fopen("Anlamlar","r");                            //fp1 �LE "Anlamlar" DOSYAMIZI "r" �LE OKUNMAK �ZERE A�IYORUZ
	
	if(fp1 == NULL)                                           //if D�NG�S� KURARAK fp1 �LE A�TI�IMIZ "Anlamlar" DOSYAMIZI SORGULUYORUZ. fp1==NULL �LE L�STEN�N ���N�N BO� OLUP OLMADI�INI ANLIYORUZ
	{
	printf("Dosya Bulunamadi\n");                                    //E�ER fp1 BO�SA KULLANICIYA DOSYANIN BO� OLDU�UNU BEL�RT�P ANA MEN�YE Y�NLEND�R�YORUZ
	
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	main();
	}
	else                                                           
	{	
	while((ch=fgetc(fp1))!=EOF)                          //E�ER fp1 BO� DE��LSE ch=fgetc(fp1) �LE L�STEN�N ���NDEK� ANLAMLARI ch D�Z�M�ZE L�STEN�N SONUNA G�DENE KADAR AKTARIYORUZ            
	
	{
	printf("%c",ch);                                            //ANLAMLARIMIZI EKRANA YAZDIRIYORUZ
    }
	}
	fclose(fp1);	                                                      //DOSYAMIZI KAPATIP KULLANICIYI B�R �NCEK� MEN� OLAN KelimeleriDuzenle'ye Y�NLEND�R�YORUZ
	printf("\nBir Onceki Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	KelimeleriDuzenle();

	EkraniTemizle();
	
	
	
}	
	
	
	

void KelimeListeleri() {                            //KelimeListeleri FONKS�YONUMUZU TANIMLIYORUZ
	
	EkraniTemizle();                                    //BU FONKS�YONUMUZUN AMACI KEL�MELER S�STEM�Z� KULLANICININ UYGULAMA ���NDE G�R�NT�LEMES�D�R
	
	int secenek;
	char ch;
	FILE *fp;
	printf("\n");
	fp = fopen("Kelimeler","r");                               //KEL�MELER�M�Z�N TUTULDU�U "Kelimeler" DOSYAMIZI "r" �LE OKUNMAK �ZERE A�IYORUZ
	
	if(fp == NULL)                                                 //E�ER fp �LE TANITTI�IMIZ DOSYAMIZ BO� �SE KULLICIYA DOSYANIN BULUNAMADI�INI BEL�RT�P ANA MEN�YE Y�NLEND�R�YORUZ
	{
	printf("Dosya Bulunamadi\n");
	
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	main();
	}
	else
	{	
	while((ch=fgetc(fp))!=EOF)                                       //E�ER fp �LE TANITTI�IMIZ DOSYAMIZ BO� DE��LSE ch=fgetc(fp) �LE L�STEN�N SONUNA G�DENE KADAR ch D�Z�M�Z�N ���NE YAZDIRIYORUZ
	
	{
	printf("%c",ch);                                                 //KEL�MELER�M�Z� EKRANA YAZDIRIYORUZ
    }
	}
	fclose(fp);	                                                       //DOSYAMIZI KAPATIYORUZ
	
	do { 
	printf("\nAnlam Listesini Gormek Icin Lutfen 1 e basiniz ");                   //KULLANICININ ��LEM� B�T�RD�KTEN SONRA NE YAPMAK �STED��� ��RENMEK ���N B�R SW�TCH-CASE D�NG�S� KURUYORUZ
	printf("\nBir Onceki Menuye Donmek Icin 2 ye Basiniz: ");
	scanf("%d", &secenek);
	switch(secenek) {
		
	case 1:
	AnlamListeleri();                                                 //KULLANICI 1'E TIKLARSA ANLAM L�STEM�Z� G�R�NT�L�YORUZ
	break;
	case 2:
	KelimeleriDuzenle();                                                       //KULLANICI 2'YE TIKLARSA B�R �NCEK� MEN� OLAN KelimeleriD�zenleye Y�NLEND�R�YORUZ
	break;
	}
	
	}
	while(secenek!=2);
	getch();
	EkraniTemizle();
}
	
void Credits() {                                                                   //Credits FONKS�YONUMUZU TANIMLIYORUZ
	system("CLS");
	
	
	printf("     Yusuf KALAYLI \n\a");                                                //EME�� GE�ENLER� VE REFERANSLARIN BULUNDU�U KLAS�R� TANIMLIYORUZ
	printf("     Kaynakca 'ReadMe' Klasorunun icindedir \n");
	printf(" Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	
	main();                                                    //ANA MEN�YE Y�NLEND�R�YORUZ
}









void KelimePratigi() {                                      //KelimePrati�i FONKS�YONUMUZU TANIMLIYORUZ
	
	setlocale(LC_ALL, "Turkish");                           //T�RK�E KARAKTERLER� KULLANMAK ���N GEREKL� FONKS�YONU YAZIYORUZ

	system("CLS");                                              //BU FONKS�YON UYGULAMAMIZIN ASIL AMACI OLAN KEL�ME �ALI�MASINI YAPMAMIZA YARDIMCI OLAN FONKS�YONDUR
	int m, i, j;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YABANCI DIL KELIME PRATIGINE HOSGELDINIZ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  gotoxy(20,5);
   printf("\xDB Lutfen Calismak istediginiz kelime sayisini giriniz: ");              //KULLANICIDAN KA� KEL�ME �ALI�MAK �STED���N� ��REN�YORUZ
   scanf("%d", &m);
   
   FILE *fp;
   FILE *fp1;
   
   fp = fopen("Kelimeler", "r");                            //fp �LE "Kelimeler" DOSYAMIZI "r" �LE OKUNMAK �ZERE A�IYORUZ
   fp1 = fopen("Anlamlar", "r");                               //fp1 �LE "Anlamlar" DOSYAMIZI "r" �LE OKUNMAK �ZERE A�IYORUZ
   
   char kelimeler[100][100];                                      //KEL�MELER VE ANLAMLAR OLMAK �ZERE �K� ADET D�Z� A�IYORUZ, BUNLARIN ��ER�S�NE KULLANICIYA SORMAK �ZERE KEL�MELER� VE ANLAMLARI AKTARACA�IZ
   char anlamlar[100][100];
   //char kelimeler1[20][20];
  
   
   if(m>20) {    gotoxy(20,8);  EkraniTemizle();   printf("Harvard Universitesinde yapilan bir arastirmaya gore yabanci dilde kelime pratigi yapmak icin ideal kelime sayisi 20'dir. Biraz daha kolaydan baslamak sizin icin daha iyi olacaktir :)\a");
    }                                       //E�ER KULLANICI 20 KEL�MEDEN DAHA FAZLA �ALI�MAK �STERSE VER�ML�L��� ARTTIRMAK ���N DAHA D���K SAYIDA KEL�ME �LE �ALI�MASI GEREKT��� S�YL�YORUZ
  else {
  	
gotoxy(20,8);                        
int n=0;
int f=0;
char t[100][100];

while(!feof(fp)) {                            //B�R WH�LE D�NG�S� A�ARAK fp �LE A�TI�IMIZIN DOSYANIN SONUNA KADAR DEVAM ED�YORUZ
	
	fscanf(fp, "%s", &t[n][100]);                        //fscanf �LE fp DOSYAMIZIN ���NDE KEL�MELER� ALIP t �LE A�TI�IMIZ D�Z�M�Z�N ���NE YAZDIRIYORUZ
	strcpy(&kelimeler[n][100], &t[n][100]);                    //strcpy �LE t D�Z�M�Z�N ���NDEK� VER�LER� kelimeler D�Z�M�Z�N ���NE KOPYALIYORUZ
	n++;                                       //n++ �LE n sayisini artt�rarak t�m kelimelerimizi al�yoruz
}
while(!feof(fp1)) {                           //B�R WH�LE D�NG�S� DAHA A�ARAK AYNI ��LEM� fp1 �LE A�TI�IMIZIN ANLAMLAR DOSYASI ���N YAPIYORUZ
	
	fscanf(fp1, "%s", &t[f][100]);
	strcpy(&anlamlar[f][100], &t[f][100]);
	f++;
	
}

    

int uzunluk, q, r;

printf("                   \xDB\xDB\xB2 Evet, Hazirsaniz Baslayalim\n\n");                                      //KULLANICIYA OYUNUN GENEL MANTI�I TANITILIYOR
printf("                   \xDB Girmis oldugunuz %d kelime size karisik sekillerde sorulacaktir.\n", m);
printf("                   \xDB Ve arka arkaya %d dogru cevap verene kadar program devam edecektir.\n", m);
printf("                   \xDB Bildiginiz kelimeler size tekrar sorulmayacaktir :) \n\n\n");
printf("                   \xDB LUTFEN KUCUK HARF KULLANINIZ  \n\n\n");
printf("                   \xDB LUTFEN TURKCE HARF KULLANMAYINIZ (�,�,�,�,�, I) BUNLARIN YER�NE (U,O,G,S,C, �) KULLANINIZ \n\n\n");
	int dc=0, yc=0;
   
 
while(dc<m){                  //dc �LE TANIMLADI�IMIZ DO�RU CEVAP SAYIMIZ m �LE KULLANICIDAN ALDI�IMIZ KEL�ME SAYISINDAN K���K OLDU�U S�RECE WH�LE D�NG�S� �LE UYGULAMANIN �ALI�MASI SA�LANIYOR
	
	
	for(i=1; i<=m; i++) {          //B�R for D�NG�S� KURARAK ��E BA�LIYORUZ, i'yi KEL�ME SAYIMIZ OLAN m'ye KADAR ARTTIRIYORUZ
	char cevap[50];               //KULLANICININ VERM�� OLDU�U CEVAPLARI ALACA�IMIZ B�R STR�NG TANIMLIYORUZ

	int rastgele;                   //KULLANICIYA SORULARI RASTGELE B�R �EK�LDE SORMAK ���N KULLANACA�IMIZ "RASTGELEY�" TANIMLIYORUZ
	srand(time(NULL));               //"RASTGELE" N�N, 1 �LE KEL�ME SAYIMIZ OLAN m ARASINDA RASTGELE B�R DE�ER ALMASINI SA�LIYORUZ
    rastgele=1+rand()%100;
	
	
     


	
	printf("%s kelimesinin anlami nedir: ", &kelimeler[rastgele]);                 //RASTGELE SE��LEN KEL�M�Z� KULLANICIYA SORUP CEVABINI ALIYORUZ
	scanf("%s",&cevap[i]);
	
	
	if(strcmp(&cevap[i],&anlamlar[rastgele])==0) {                                      //KULLANICININ VERD��� CEVAP, ANLAMLAR L�STEM�ZDE O KEL�MEN�N KAR�ILI�I MIDIR strcmp==0 �LE SORGULUYORUZ
	
	int o;                                                 
	dc++;                                        //CEVAP DO�RU �SE dc �LE TANITTI�IMIZ DO�RU CEVABI ARTTIRIYORUZ
	o=(m-dc);
	//sayac++;
	
	
	if(dc<m) {                                                         //YAZIM HATASI OLMAMASI ���N BURADA B�R �F D�NG�S� A�IYORUZ (SON SORUYA GEL�NCE 0 SORUNUZ KALDI YAZMAMASI AMACIYLA)
	printf("Tebrikler! Cevaplamaniz Gereken %d Soru Kaldi\n\n", o);      //KULLANICIYA CEVABININ DO�RU OLDU�UNU VE DO�RU CEVAPLAMASI GEREKEN SORU SAYISINI BEL�RT�YORUZ
	}
	
	
	}
	else {
	printf("               Yanlis Cevap! Lutfen Daha Dikkatli Olunuz arkaya arkaya bilmeniz gereken soru sayisi %d \n\n", m);    //E�ER CEVAP YANLI�SA KULLANICIYI UYARIP TEKRAR m KADAR KEL�ME DO�RU CEVAPLAMASI GEREKT���N� BEL�RT�YORUZ
	dc=0;               //PROGRAMIMIZ ARKA ARKAYA �ALI�MASI �STENEN KEL�ME KADAR DO�RU CEVAP VER�LMES�N� AMA�LADI�INDAN YANLI� CEVAP ALINCA dc SAYIMIZI 0 YAPIYORUZ
	}
	
	
	
	
	

	
	
	}
	

	
	
	
 }
 printf(" \nTebrikler Girmis Oldugunuz %d Kelimeyi Basariyla Tamamladiniz, \nBiraz dinlendikten sonra yeni kelimeler geciniz :) \a\n" ,m);	 //E�ER KULLANICI ARKA ARKAYA m KADAR SORUYA DO�RU CEVAP VERM��SE KEND�S�N� TEBR�K ED�P �ALI�MAYI SONLANDIRIYORUZ
printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz");                                   //ANA MEN�YE Y�NLEND�R�YORUZ
getch();
EkraniTemizle();
}


}




	
	
