#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>                               //KULLANACAĞIMIZ KÜTÜPHANELERİ TANIMLIYORUZ
#include<string.h>                  
#include<ctype.h>  
#include<time.h>       
#include <locale.h>


        






 void KelimePratigi();
 void Credits();
 void KelimeListeleri();
 void YeniKelimeGirisi();                       //FONKSİYONLARIMIZI TANIMLIYORUZ
 void KelimeSil();
 void AnlamSil();
 void KelimeleriDuzenle();
 void EkraniTemizle();
 void AnlamListeleri();
 
 
 void EkraniTemizle() {                        //EKRANITEMİZLE FONKSİYONUMUZUN İŞLEVİNİ TANIMLIYORUZ
system("CLS");                                //system("CLS") Komutu ile fonksiyonumuzu çağırdığımız yerde ekranı temizleyip programın daha temiz çalışmasını amaçlıyoruz.
 }
 
 
   
COORD coord = {0, 0};                      

void gotoxy (int x, int y)                                                //GOTOXY FONKSİYONUMUZUN İŞLEVİNİ TANIMLIYORUZ
{                                                                         //gotoxy FONKSİYONU İÇERİSİNE BELİRTTİĞİMİZ KOORDİNATLARA GİTMEMİZİ SAĞLAR. ÖRN/ gotoxy(20,20)
coord.X = x; coord.Y = y;                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {                                                //ANA SAYFAMIZI OLUŞTURUYORUZ
	setlocale(LC_ALL, "Turkish");                           //TÜRKÇE KARAKTERLERİ KULLANMAK İÇİN GEREKLİ FONKSİYONU YAZIYORUZ
	EkraniTemizle();                                      //EKRANDA DAHA ÖNCEDEN KALAN BİR ŞEY VARSA ONU TEMİZLİYORUZ

int secenek;
gotoxy(20,3);	
  printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YABANCI DIL KELIME PRATIGINE HOSGELDINIZ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");  //BAŞLIK
  
  do {
   gotoxy(20,5);
   printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");               //YAPMAK İSTEDİĞİ İŞLEMİ SORUYORUZ.
   printf("\n 1- Kelimeleri Duzenle: \n");
   printf("\n 2- Kelime Calismasina Gir: \n");
   printf("\n 3- Emegi Gecenler: \n");
   printf("\n 4- Cikis \n");
   printf(" :");
   scanf("%d", &secenek);                  //TERCİHİNİ ALIYORUZ
   
   switch(secenek)                  //BİR SWİTCH-CASE DÖNGÜSÜ KURARAK KULLANICININ SEÇİMİ DOĞRULTUSUNDA İSTEDİĞİ İŞLEME GİRMESİNİ SAĞLIYORUZ
   {
    case 1:
    KelimeleriDuzenle();
    case 2:
    KelimePratigi();
    break;
    case 3:
    Credits();
    case 4:                                              // CASE 4, YANİ CİKİSİ SEÇTİYSE PROGRAMI EXİT(0) KOMUTU İLE SONLANDIRIYORUZ
    printf("Daha Sonra Gorusmek Uzere :) ");
    exit(0);
    break;
    
   }
  }
  while(secenek!=4);                 

}	


void KelimeleriDuzenle() {                               //KelimeleriDuzenle FONKSİYONUMUZU TANIMLIYORUZ
	EkraniTemizle();                         
	
	int op;
	EkraniTemizle();
	
	do {
	gotoxy(20,3);                                         //BURADA BİR SAYFA DAHA YARATIP KULLANCININ BU MENÜ İÇERİSİNDE NE YAPMAK İSTEDİĞİNİ ÖĞRENİYORUZ
   printf("Lutfen Yapmak Istediginiz Islemi Seciniz: ");
   printf("\n 1- Yeni Kelime Girisi: \n");
   printf("\n 2- Kelime Silme: \n");
   printf("\n 3- Kelime Listelerini Goruntule: \n");
   printf("\n 4- Anlam Listelerini Goruntule: \n ");
   printf("\n 5- Ana Menuye Don: \n ");
   scanf("%d", &op);                                    //TERCİHİNİ ALIYORUZ
   
   switch(op) {                                          //YİNE SWİTCH-CASE DÖNGÜSÜ KURARAK KULLANCIYI TERCİHİ DOĞRULTUSUNDA YÖNLENDİRİYORUZ
   	
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



void YeniKelimeGirisi() {                      //YeniKelimeGirisi FONKSİYONUMUZU TANIMLIYORUZ
	       
	EkraniTemizle();                            //BU FONKSİYONUMUZ KULLANICININ SİSTEME YENİ KELİMELER EKLEMESİNİ SAĞLIYOR
	gotoxy(20,3);
	int baslik, i, m, tercih;
	

	
	printf("\nLutfen Yeni Girmek Istediginiz Kelime Sayisini Belirtiniz:");                 //KULLANICININ SİSTEME EKLEMEK İSTEDİĞİ KELİME SAYİSİNİ ÖĞRENİYORUZ          
	scanf("%d", &m);
	char kelimeler[100][100];                                                              //KELİMELER DİZİMİZİ TANIMLIYORUZ
	char anlamlar[100][100];                                                               //ANLAMLAR DİZİMİZİ TANIMLIYORUZ
	
	FILE *fp;                                                                          //FILE *fp KOMUTU İLE DOSYA İŞLEMLERİNE BAŞLIYORUZ
	fp=fopen("Kelimeler","a");                                                         //fp OLARAK KELİMELERİMİZİN TUTULDUĞU "Kelimeler" txt DOSYAMIZI "a" İLE OLAĞAN METİNİN ÜZERİNE EKLEYECEK ŞEKİLDE AÇIYORUZ
	
	FILE *fp1;                                                                         //AYNI İŞLEMİ KELİMELERİMİZİN ANLAMLARININ TUTULDUĞU "Anlamlar.txt" DOSYASINI İÇİN YAPIYORUZ
	fp1=fopen("Anlamlar", "a");
	
	
	printf(" Lutfen Yeni Girmek Istediginiz Kelimeleri teker teker giriniz:\n ");          //EKLEMEK İSTEDİĞİ KELİMELERİ SIRAYLA İSTİYORUZ
	printf("\nLUTFEN ILK KELIMEYE GIRIS YAPMAYINIZ, ENTER TUSUNA BIR KERE BASARAK 2. KELIMEDEN BASLAYINIZ\n");
	for(i=1;  i<=m; i++) {                                                      //FOR DÖNGÜSÜNÜ KULLANICININ EKLEMEK İSTEDİĞİ KELİME SAYISINCA ARTTIRARAK KELİMELERİ TEK TEK ALIYORUZ

	printf("\n\nLutfen %d. kelime ve anlamini giriniz:\n\n ", i);
	
	
	printf("\n %d. kelime " ,i);
	fgets(kelimeler,100,stdin);                                                
	fputs(kelimeler,fp);                                                 //ALDIĞIMIZ KELİMELERİN fp İLE TANIMLADIĞIMIZ KELİMELER DOSYASINA YAZILMASINI İSTEDİĞİMİZİ BELİRTİYORUZ
	
	printf("\n     anlami ");                                              //KELİMELERİN ANLAMLARINI ALIYORUZ
	fgets(anlamlar,100,stdin);
	fputs(anlamlar, fp1);                                               //ANLAMLARI fp1 İLE TANIMLADIĞIMIZ ANLAMLAR DOSYASINA YAZDIRIYORUZ
	
	
	}	
	
	printf("\n");
	fclose(fp);                                               //KELİMELER DOSYAMIZI İŞİMİZ BİTTİĞİ İÇİN KAPATIYORUZ
	fclose(fp1);                                              //ANLAMLAR DOSYAMIZI İŞİMİZ BİTTİĞİ İÇİN KAPATIYORUZ
	
	do {
		
		
	printf("Kelime Girisine Devam Etmek Istiyor musunuz ? (1/2)\n");           //KULLANICIYA BAŞKA KELİME EKLEMEK İSTEYİP İSTEMEDİĞİNİ SORUYORUZ
	scanf("%d", &tercih);
	
	switch(tercih) {          //SWİTCH-CASE İLE İSTEĞİNİ GERÇEKLEŞTİRİYORUZ
	
	case 1:	
	printf("\n");
	YeniKelimeGirisi();
	break;
	
	case 2:
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");	           //KULLANICI BAŞKA KELİME EKLEMEK İSTEMİYORSA ANA MENÜYE YÖNLENDİRİYORUZ
	printf("\n");
	getch();
	main();
	break;
	}
	
	}
	while(tercih !=2);
	}
	
	
	
	
	
	void AnlamSil() {                                     //AnlamSil FONKSİYONUMUZU TANIMLIYORUZ
	EkraniTemizle();                                         //BU FONKSİYONUMUZUN AMACI KULLANICININ ARTIK ÇALIŞMAK İSTEMEDİĞİ VEYA YARARLI GÖRMEDİĞİ KELİMELERİ LİSTEDEN SİLMESİDİR
	gotoxy(20,3);	                                          //BU FONKSİYON TEKİL OLARAK ÇALIŞMAZ, KULLANICI KELİME SİLMEK İSTERSE ANLAMINI DA LİSTEDEN SİLMESİ İÇİN BU FONKSYİONA YÖNLENDİRİLİR
	
	
	printf("\nProgramin Guvenilirligini Arttirmak Acisindan Lutfen Sildiginiz Kelimenin Anlamini Da Siliniz: \n");
		
	
	
	char Anlamlar[100][100];                       //ANLAM DİZİMİZİ TANIMLIYORUZ
	
	char anlam[256];                        //KULLANICININ SİLMEK İSTEDİĞİ ANLAMI ATACAĞAMIZ DEĞİŞKENİ TANIMLIYORUZ
	FILE *fp1;                             
	FILE *fp3;
	
	fp1=fopen("Anlamlar", "r");                //fp1 OLARAK ANLAMLARIMIZIN BULUNDUĞU "anlamlar.txt" KLASÖRÜNÜ "r" İLE OKUNMAK ÜZERE AÇIYORUZ
	fp3=fopen("TempAnlamlar", "a");	              //fp3 OLARAK KULLANICININ SİLMEK İSTEDİĞİ ANLAMI SİLİP GERİ KALANLARI TEKRAR YAZACAĞIMIZ GEÇİCİ BİR "TempAnlamlar.txt" DOSYASINI "a" İLE ÜZERİNE EKLENECEK ŞEKİLDE AÇIYORUZ
		
		
	printf("\nSildiginiz Kelimenin Anlamini Giriniz: \n");      //SİLİNMESİ İSTENEN ANLAMI ALIYORUZ
	scanf("%s", &anlam[256]);
	
	while(fscanf(fp1,"%s", &Anlamlar[100][100])!=EOF) {      //WHİLE DÖNGÜSÜ İLE fp1 İLE BELİRTTİĞİMİZ ANLAMLAR DOSYASININ EOF İLE SONUNA KADAR İLERLİYORUZ VE FSCANF İLE ANLAMLAR DİZİMİZE TAŞIYORUZ
		
		
		
		
	if(strcmp(&anlam[256],&Anlamlar[100][100])==0) {      //İF DÖNGÜSÜ İLE KULLANICININ GİRDİĞİ KELİMENİN GİRDİĞİ KELİMENİN ANLAMLAR DİZİMİZ İÇERİSİNDE OLUP OLMADIĞINI strcmp==0 İLE SORGULUYORUZ
		
		
	printf("%s kelimesi silindi! \n", &anlam[256]);        //KULLANICININ VERDİĞİ KELİMENİN SİLİNDİĞİ BELİRTİP ANA MENÜYE YÖNLENDİRİYORUZ
	printf("Ana Menu Icin enter");
	
	}
	else {
		
	fprintf(fp3, "%s\n", &Anlamlar[100][100]);             //KELİMELER DİZİMİZİ YENİ ANLAMLAR DİZİSİ OLARAK KULLANACAĞIMIZ, fp3 İLE TANIMLADIĞIMIZ "TempAnlamlar.txt" DOSYASININ İÇİNE fprintf İLE YAZIYORUZ         
	}
	}
	
	
	
	fclose(fp1);            //DOSYALARIMIZI KAPATIYORUZ
	fclose(fp3);
	remove("Anlamlar");           //ANLAMLAR DOSYAMIZI SİLİYORUZ
	rename("TempAnlamlar","Anlamlar");     //TempAnlamlar DOSYAMIZ ANLAMLARI TUTTUĞUMUZ YENİ DOSYAMIZ OLACAĞI İÇİN ADINI Anlamlar OLARAK DEĞİŞTİRİYORUZ
		
		
		
		
	
	getch();           
	
	main();                 //ANA MENÜYE DÖNDÜRÜYORUZ
		
		
		
		
		
		
	}
	
	
	void KelimeSil() {                 //KelimeSil FONKSİYONUMUZU TANIMLIYORUZ
		                                
	EkraniTemizle();                //BU FONKSİYON KULLANICININ LİSTEDEN KELİME SİLMESİNİ SAĞLAR
	gotoxy(20,3);
	
	
	
	
	
		
	char Kelimeler[100][100];                            //KELİMELER DİZİMİZİ TANIMLIYORUZ
	
	char kelime[256];                             //KULLANICIDAN ALACAĞIMIZ SİLİNMESİ İSTENEN KELİMEYİ ATAYACAĞIMIZ STRİNGİ TANIMLIYORUZ
	FILE *fp;
	FILE *fp2;
	
	fp=fopen("Kelimeler", "r");                    //fp OLARAK KELİMELERİMİZİN TUTULDUĞU "Kelimeler.txt" DOSYASINI "r" İLE OKUMAK İÇİN AÇIYORUZ
	fp2=fopen("TempKelimeler", "a");	            //fp2 OLARAK KULLANICININ SİLİNMESİNİ İSTEDİĞİ KELİMEYİ SİLİP GERİSİ TEKRAR YAZACAĞIMIZ "TempKelimeler" DOSYASINI "a" İLE ÜZERİNE EKLENECEK ŞEKİLDE AÇIYORUZ.
		
		
	printf("Silmek Istediginiz Kelimeyi Seciniz: ");        //SİLİNMESİ İSTENEN KELİMEYİ ALIYORUZ
	scanf("%s", &kelime[256]);
	
	while(fscanf(fp,"%s", &Kelimeler[100][100])!=EOF) {           //WHİLE DÖNGÜSÜ İLE fp İLE BELİRTTİĞİMİZ KELİMELER DOSYASININ EOF İLE SONUNA KADAR İLERLİYORUZ VE FSCANF İLE KELİMELER DİZİMİZE TAŞIYORUZ
		
		
		
		
	if(strcmp(&kelime[256],&Kelimeler[100][100])==0) {           //İF DÖNGÜSÜ KURARAK KULLANICININ SİLİNMESİNİ İSTEDİĞİ KELİMENİN DİZİDE OLUP OLMADIĞINI strcmp==0 İLE TEST EDİYORUZ
		
		
	printf("%s kelimesi silindi! \n", &kelime[256]);           //KULLANICIYA VERDİĞİ KELİMENİN SİLİNDİĞİNİ BELİRTİP ANA MENÜYE YÖNLENDİRİYORUZ
	
	printf("Ana Menu Icin enter");
	
	
	}
	else {
		
	fprintf(fp2, "%s\n", &Kelimeler[100][100]);               //GERİ KALAN KELİMELERİMİZİ fp2 İLE AÇTIĞIMIZ "TempKelimeler.txt" DOSYAMIZIN İÇİNE FPRİNTF İLE YAZIYORUZ.
	
	}
	}
	
	
	
	fclose(fp);                                     //İŞİMİZ BİTTİĞİ İÇİN DOSYALARIMIZI KAPATIYORUZ.
	fclose(fp2);
	remove("Kelimeler");                                //"Kelimeler.txt" DOSYAMIZI SİLİYORUZ
	rename("TempKelimeler","Kelimeler");                //"TempKelimeler" DOSYAMIZ, KELİMELERİ TUTACAĞIMIZ YENİ DOSYAMIZ OLDUĞU İÇİN ADINI "Kelimeler.txt" OLARAK DEĞİŞTİRİYORUZ
	
	AnlamSil();                                        //KULLANICININ SİLİNMESİ İSTEDİĞİ KELİMEYİ SİLDİKTEN SONRA ANLAMINI DA LİSTEDEN SİLMESİ İÇİN AnlamSil FONKSİYONUNA YÖNLENDİRİYORUZ
	getch();
	
	main();                                            
	}
	
	
void AnlamListeleri() {                            //AnlamListeleri FONKSİYONUMUZU TANIMLIYORUZ
	
	EkraniTemizle();                                     //BU FONKSİYONUN KULLANICININ LİSTEMİZDE BULUNAN ANLAMLARI UYGULAMA İÇİNDE GÖRÜNTÜLEMESİNİ SAĞLAR
	
	char ch;
	FILE *fp1;
	printf("\n");
	fp1 = fopen("Anlamlar","r");                            //fp1 İLE "Anlamlar" DOSYAMIZI "r" İLE OKUNMAK ÜZERE AÇIYORUZ
	
	if(fp1 == NULL)                                           //if DÖNGÜSÜ KURARAK fp1 İLE AÇTIĞIMIZ "Anlamlar" DOSYAMIZI SORGULUYORUZ. fp1==NULL İLE LİSTENİN İÇİNİN BOŞ OLUP OLMADIĞINI ANLIYORUZ
	{
	printf("Dosya Bulunamadi\n");                                    //EĞER fp1 BOŞSA KULLANICIYA DOSYANIN BOŞ OLDUĞUNU BELİRTİP ANA MENÜYE YÖNLENDİRİYORUZ
	
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	main();
	}
	else                                                           
	{	
	while((ch=fgetc(fp1))!=EOF)                          //EĞER fp1 BOŞ DEĞİLSE ch=fgetc(fp1) İLE LİSTENİN İÇİNDEKİ ANLAMLARI ch DİZİMİZE LİSTENİN SONUNA GİDENE KADAR AKTARIYORUZ            
	
	{
	printf("%c",ch);                                            //ANLAMLARIMIZI EKRANA YAZDIRIYORUZ
    }
	}
	fclose(fp1);	                                                      //DOSYAMIZI KAPATIP KULLANICIYI BİR ÖNCEKİ MENÜ OLAN KelimeleriDuzenle'ye YÖNLENDİRİYORUZ
	printf("\nBir Onceki Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	KelimeleriDuzenle();

	EkraniTemizle();
	
	
	
}	
	
	
	

void KelimeListeleri() {                            //KelimeListeleri FONKSİYONUMUZU TANIMLIYORUZ
	
	EkraniTemizle();                                    //BU FONKSİYONUMUZUN AMACI KELİMELER SİSTEMİZİ KULLANICININ UYGULAMA İÇİNDE GÖRÜNTÜLEMESİDİR
	
	int secenek;
	char ch;
	FILE *fp;
	printf("\n");
	fp = fopen("Kelimeler","r");                               //KELİMELERİMİZİN TUTULDUĞU "Kelimeler" DOSYAMIZI "r" İLE OKUNMAK ÜZERE AÇIYORUZ
	
	if(fp == NULL)                                                 //EĞER fp İLE TANITTIĞIMIZ DOSYAMIZ BOŞ İSE KULLICIYA DOSYANIN BULUNAMADIĞINI BELİRTİP ANA MENÜYE YÖNLENDİRİYORUZ
	{
	printf("Dosya Bulunamadi\n");
	
	printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	main();
	}
	else
	{	
	while((ch=fgetc(fp))!=EOF)                                       //EĞER fp İLE TANITTIĞIMIZ DOSYAMIZ BOŞ DEĞİLSE ch=fgetc(fp) İLE LİSTENİN SONUNA GİDENE KADAR ch DİZİMİZİN İÇİNE YAZDIRIYORUZ
	
	{
	printf("%c",ch);                                                 //KELİMELERİMİZİ EKRANA YAZDIRIYORUZ
    }
	}
	fclose(fp);	                                                       //DOSYAMIZI KAPATIYORUZ
	
	do { 
	printf("\nAnlam Listesini Gormek Icin Lutfen 1 e basiniz ");                   //KULLANICININ İŞLEMİ BİTİRDİKTEN SONRA NE YAPMAK İSTEDİĞİ ÖĞRENMEK İÇİN BİR SWİTCH-CASE DÖNGÜSÜ KURUYORUZ
	printf("\nBir Onceki Menuye Donmek Icin 2 ye Basiniz: ");
	scanf("%d", &secenek);
	switch(secenek) {
		
	case 1:
	AnlamListeleri();                                                 //KULLANICI 1'E TIKLARSA ANLAM LİSTEMİZİ GÖRÜNTÜLÜYORUZ
	break;
	case 2:
	KelimeleriDuzenle();                                                       //KULLANICI 2'YE TIKLARSA BİR ÖNCEKİ MENÜ OLAN KelimeleriDüzenleye YÖNLENDİRİYORUZ
	break;
	}
	
	}
	while(secenek!=2);
	getch();
	EkraniTemizle();
}
	
void Credits() {                                                                   //Credits FONKSİYONUMUZU TANIMLIYORUZ
	system("CLS");
	
	
	printf("     Yusuf KALAYLI \n\a");                                                //EMEĞİ GEÇENLERİ VE REFERANSLARIN BULUNDUĞU KLASÖRÜ TANIMLIYORUZ
	printf("     Kaynakca 'ReadMe' Klasorunun icindedir \n");
	printf(" Ana Menuye Donmek Icin ENTER Tusuna Basiniz: ");
	getch();
	
	main();                                                    //ANA MENÜYE YÖNLENDİRİYORUZ
}









void KelimePratigi() {                                      //KelimePratiği FONKSİYONUMUZU TANIMLIYORUZ
	
	setlocale(LC_ALL, "Turkish");                           //TÜRKÇE KARAKTERLERİ KULLANMAK İÇİN GEREKLİ FONKSİYONU YAZIYORUZ

	system("CLS");                                              //BU FONKSİYON UYGULAMAMIZIN ASIL AMACI OLAN KELİME ÇALIŞMASINI YAPMAMIZA YARDIMCI OLAN FONKSİYONDUR
	int m, i, j;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YABANCI DIL KELIME PRATIGINE HOSGELDINIZ! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  gotoxy(20,5);
   printf("\xDB Lutfen Calismak istediginiz kelime sayisini giriniz: ");              //KULLANICIDAN KAÇ KELİME ÇALIŞMAK İSTEDİĞİNİ ÖĞRENİYORUZ
   scanf("%d", &m);
   
   FILE *fp;
   FILE *fp1;
   
   fp = fopen("Kelimeler", "r");                            //fp İLE "Kelimeler" DOSYAMIZI "r" İLE OKUNMAK ÜZERE AÇIYORUZ
   fp1 = fopen("Anlamlar", "r");                               //fp1 İLE "Anlamlar" DOSYAMIZI "r" İLE OKUNMAK ÜZERE AÇIYORUZ
   
   char kelimeler[100][100];                                      //KELİMELER VE ANLAMLAR OLMAK ÜZERE İKİ ADET DİZİ AÇIYORUZ, BUNLARIN İÇERİSİNE KULLANICIYA SORMAK ÜZERE KELİMELERİ VE ANLAMLARI AKTARACAĞIZ
   char anlamlar[100][100];
   //char kelimeler1[20][20];
  
   
   if(m>20) {    gotoxy(20,8);  EkraniTemizle();   printf("Harvard Universitesinde yapilan bir arastirmaya gore yabanci dilde kelime pratigi yapmak icin ideal kelime sayisi 20'dir. Biraz daha kolaydan baslamak sizin icin daha iyi olacaktir :)\a");
    }                                       //EĞER KULLANICI 20 KELİMEDEN DAHA FAZLA ÇALIŞMAK İSTERSE VERİMLİLİĞİ ARTTIRMAK İÇİN DAHA DÜŞÜK SAYIDA KELİME İLE ÇALIŞMASI GEREKTİĞİ SÖYLÜYORUZ
  else {
  	
gotoxy(20,8);                        
int n=0;
int f=0;
char t[100][100];

while(!feof(fp)) {                            //BİR WHİLE DÖNGÜSÜ AÇARAK fp İLE AÇTIĞIMIZIN DOSYANIN SONUNA KADAR DEVAM EDİYORUZ
	
	fscanf(fp, "%s", &t[n][100]);                        //fscanf İLE fp DOSYAMIZIN İÇİNDE KELİMELERİ ALIP t İLE AÇTIĞIMIZ DİZİMİZİN İÇİNE YAZDIRIYORUZ
	strcpy(&kelimeler[n][100], &t[n][100]);                    //strcpy İLE t DİZİMİZİN İÇİNDEKİ VERİLERİ kelimeler DİZİMİZİN İÇİNE KOPYALIYORUZ
	n++;                                       //n++ İLE n sayisini arttırarak tüm kelimelerimizi alıyoruz
}
while(!feof(fp1)) {                           //BİR WHİLE DÖNGÜSÜ DAHA AÇARAK AYNI İŞLEMİ fp1 İLE AÇTIĞIMIZIN ANLAMLAR DOSYASI İÇİN YAPIYORUZ
	
	fscanf(fp1, "%s", &t[f][100]);
	strcpy(&anlamlar[f][100], &t[f][100]);
	f++;
	
}

    

int uzunluk, q, r;

printf("                   \xDB\xDB\xB2 Evet, Hazirsaniz Baslayalim\n\n");                                      //KULLANICIYA OYUNUN GENEL MANTIĞI TANITILIYOR
printf("                   \xDB Girmis oldugunuz %d kelime size karisik sekillerde sorulacaktir.\n", m);
printf("                   \xDB Ve arka arkaya %d dogru cevap verene kadar program devam edecektir.\n", m);
printf("                   \xDB Bildiginiz kelimeler size tekrar sorulmayacaktir :) \n\n\n");
printf("                   \xDB LUTFEN KUCUK HARF KULLANINIZ  \n\n\n");
printf("                   \xDB LUTFEN TURKCE HARF KULLANMAYINIZ (Ü,Ö,Ğ,Ş,Ç, I) BUNLARIN YERİNE (U,O,G,S,C, İ) KULLANINIZ \n\n\n");
	int dc=0, yc=0;
   
 
while(dc<m){                  //dc İLE TANIMLADIĞIMIZ DOĞRU CEVAP SAYIMIZ m İLE KULLANICIDAN ALDIĞIMIZ KELİME SAYISINDAN KÜÇÜK OLDUĞU SÜRECE WHİLE DÖNGÜSÜ İLE UYGULAMANIN ÇALIŞMASI SAĞLANIYOR
	
	
	for(i=1; i<=m; i++) {          //BİR for DÖNGÜSÜ KURARAK İŞE BAŞLIYORUZ, i'yi KELİME SAYIMIZ OLAN m'ye KADAR ARTTIRIYORUZ
	char cevap[50];               //KULLANICININ VERMİŞ OLDUĞU CEVAPLARI ALACAĞIMIZ BİR STRİNG TANIMLIYORUZ

	int rastgele;                   //KULLANICIYA SORULARI RASTGELE BİR ŞEKİLDE SORMAK İÇİN KULLANACAĞIMIZ "RASTGELEYİ" TANIMLIYORUZ
	srand(time(NULL));               //"RASTGELE" NİN, 1 İLE KELİME SAYIMIZ OLAN m ARASINDA RASTGELE BİR DEĞER ALMASINI SAĞLIYORUZ
    rastgele=1+rand()%100;
	
	
     


	
	printf("%s kelimesinin anlami nedir: ", &kelimeler[rastgele]);                 //RASTGELE SEÇİLEN KELİMİZİ KULLANICIYA SORUP CEVABINI ALIYORUZ
	scanf("%s",&cevap[i]);
	
	
	if(strcmp(&cevap[i],&anlamlar[rastgele])==0) {                                      //KULLANICININ VERDİĞİ CEVAP, ANLAMLAR LİSTEMİZDE O KELİMENİN KARŞILIĞI MIDIR strcmp==0 İLE SORGULUYORUZ
	
	int o;                                                 
	dc++;                                        //CEVAP DOĞRU İSE dc İLE TANITTIĞIMIZ DOĞRU CEVABI ARTTIRIYORUZ
	o=(m-dc);
	//sayac++;
	
	
	if(dc<m) {                                                         //YAZIM HATASI OLMAMASI İÇİN BURADA BİR İF DÖNGÜSÜ AÇIYORUZ (SON SORUYA GELİNCE 0 SORUNUZ KALDI YAZMAMASI AMACIYLA)
	printf("Tebrikler! Cevaplamaniz Gereken %d Soru Kaldi\n\n", o);      //KULLANICIYA CEVABININ DOĞRU OLDUĞUNU VE DOĞRU CEVAPLAMASI GEREKEN SORU SAYISINI BELİRTİYORUZ
	}
	
	
	}
	else {
	printf("               Yanlis Cevap! Lutfen Daha Dikkatli Olunuz arkaya arkaya bilmeniz gereken soru sayisi %d \n\n", m);    //EĞER CEVAP YANLIŞSA KULLANICIYI UYARIP TEKRAR m KADAR KELİME DOĞRU CEVAPLAMASI GEREKTİĞİNİ BELİRTİYORUZ
	dc=0;               //PROGRAMIMIZ ARKA ARKAYA ÇALIŞMASI İSTENEN KELİME KADAR DOĞRU CEVAP VERİLMESİNİ AMAÇLADIĞINDAN YANLIŞ CEVAP ALINCA dc SAYIMIZI 0 YAPIYORUZ
	}
	
	
	
	
	

	
	
	}
	

	
	
	
 }
 printf(" \nTebrikler Girmis Oldugunuz %d Kelimeyi Basariyla Tamamladiniz, \nBiraz dinlendikten sonra yeni kelimeler geciniz :) \a\n" ,m);	 //EĞER KULLANICI ARKA ARKAYA m KADAR SORUYA DOĞRU CEVAP VERMİŞSE KENDİSİNİ TEBRİK EDİP ÇALIŞMAYI SONLANDIRIYORUZ
printf("Ana Menuye Donmek Icin ENTER Tusuna Basiniz");                                   //ANA MENÜYE YÖNLENDİRİYORUZ
getch();
EkraniTemizle();
}


}




	
	
