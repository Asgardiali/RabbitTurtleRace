#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Bitis_Cizgisi 70		//Tav�an ve kaplu�an�n

void kapHareket( int* kapPtr );	//Kaplumba�a hareketini belirler
void tavHareket( int* tavPtr );	//tav�an hareketini belirler
void pozisyon_bul( const int* const kapPtr, const int* const tavPtr );

int main( void ){
   int a;
   int kap = 1, tav = 1; 		//kaplumba�a ve tav�an i�in iki de�i�ken olu�turulmu�tur.
   srand( time( 0 ) );			//srand fonk ile zamana g�re rand'� besleyecek
   printf("BANG !!!!!\nAND THEY'RE OFF !!!!!");	//Ba�lang�� ekran� ya�lacaklar
   while(kap != Bitis_Cizgisi && tav != Bitis_Cizgisi){		//Tav�an veya kaplumba�a kazana kadar d�ng� i�ler
      kapHareket( &kap );			//Kaplumba�an�n hareketi bulunur
      tavHareket( &tav );			//Tav�an�n hareketi bulnur
      pozisyon_bul( &kap, &tav );	//�imdiki konumlar� bulunur
   }

   if(kap > tav){
      printf("TORTOISE WINS!!! YAY!!!");
   }else if(kap < tav){
      printf("Hare wins. Yuch.");
   }
   else if (kap == tav){
	   printf("It's a tie�.");
   }
   printf("\n\nCikis icin bir tusa basiniz.");
   scanf("%d",&a);//Ekran kapanmas�n diye yazd�m.
   return 0;
}

void kapHareket( int* kapPtr ){		//Kaplumba�a hareketini pointer ile bulan fonksiyon
   int i;

   i = rand() % 10;					//1-10 aras�nda bir de�er rastgele �retilir
   if(i >= 1 && i <= 5){			//1-5 aras� 3 ad�m sa�a
      *kapPtr += 3;
   }else if(i >= 6 && i <= 7){
      *kapPtr -= 6; 				//6-7 aras� 6 kare sola
   }else{
      *kapPtr += 1;					//8-10 aras� 1 kare sa�a
   }

   if(*kapPtr < 1)					//Starttan geri gidecek olursa 1.kounuma git
      *kapPtr = 1;
   else if(*kapPtr > Bitis_Cizgisi) //Bitisden ileri gidecekse biti�te kal
      *kapPtr = Bitis_Cizgisi;
}

void tavHareket( int* tavPtr ){		//Tav�an hareketini pointer ile bulan fonksiyon
   int i;
   i = rand() % 10;					//1-10 aras�nda bir de�er rastgele �retilir
   if(i >= 1 && i <= 2){
	   //uyuyor
   }
   else if(i >= 3 && i <= 4){      //3-4 aras� 9 kare sa�a
      *tavPtr += 9;
   }else if(i == 5){			   //5 ise 12 kare sola
      *tavPtr -= 12;
   }else if(i >= 6 && i<= 8){	   //6-8 aras� 1 kare sa�a
      *tavPtr += 1;
   }else{						   //9-10 aras� 2 kare sola
      *tavPtr -= 2;
   }

   if(*tavPtr < 1)
      *tavPtr = 1;
   else if(*tavPtr > Bitis_Cizgisi)
      *tavPtr = Bitis_Cizgisi;
}

void pozisyon_bul( const int* const kapPtr, const int* const tavPtr ){
   int i;

   if(*kapPtr == *tavPtr){			//Tav�an ve kaplumba�a ayn� konumda ise Ouch yazar
      for(i = 1; i < *kapPtr; i++){	//yollar� �izer
         printf("%s", "_" );
      }
      printf("OUCH!!!");
   }else if(*kapPtr < *tavPtr){		//Tav�an �ndeyse
      for(i = 1; i < *kapPtr; i++ ){
         printf("%s", "_" );
      }
      printf("K");

      for(i = 1; i < (*tavPtr - *kapPtr); i++){
         printf("%s", "_" );
      }
      printf("T");
   }else{							//Kaplumba�a �ndeyse
      for(i = 1; i < *tavPtr; i++){
         printf("%s", "_");
      }
      printf("T");

      for( i = 0; i < (*kapPtr - *tavPtr); i++){
         printf("%s", "_" );
      }
      printf("K");
   }

   printf("\n");
}
