#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Bitis_Cizgisi 70		//Tavþan ve kapluðanýn

void kapHareket( int* kapPtr );	//Kaplumbaða hareketini belirler
void tavHareket( int* tavPtr );	//tavþan hareketini belirler
void pozisyon_bul( const int* const kapPtr, const int* const tavPtr );

int main( void ){
   int a;
   int kap = 1, tav = 1; 		//kaplumbaða ve tavþan için iki deðiþken oluþturulmuþtur.
   srand( time( 0 ) );			//srand fonk ile zamana göre rand'ý besleyecek
   printf("BANG !!!!!\nAND THEY'RE OFF !!!!!");	//Baþlangýç ekraný yaýlacaklar
   while(kap != Bitis_Cizgisi && tav != Bitis_Cizgisi){		//Tavþan veya kaplumbaða kazana kadar döngü iþler
      kapHareket( &kap );			//Kaplumbaðanýn hareketi bulunur
      tavHareket( &tav );			//Tavþanýn hareketi bulnur
      pozisyon_bul( &kap, &tav );	//Þimdiki konumlarý bulunur
   }

   if(kap > tav){
      printf("TORTOISE WINS!!! YAY!!!");
   }else if(kap < tav){
      printf("Hare wins. Yuch.");
   }
   else if (kap == tav){
	   printf("It's a tie”.");
   }
   printf("\n\nCikis icin bir tusa basiniz.");
   scanf("%d",&a);//Ekran kapanmasýn diye yazdým.
   return 0;
}

void kapHareket( int* kapPtr ){		//Kaplumbaða hareketini pointer ile bulan fonksiyon
   int i;

   i = rand() % 10;					//1-10 arasýnda bir deðer rastgele üretilir
   if(i >= 1 && i <= 5){			//1-5 arasý 3 adým saða
      *kapPtr += 3;
   }else if(i >= 6 && i <= 7){
      *kapPtr -= 6; 				//6-7 arasý 6 kare sola
   }else{
      *kapPtr += 1;					//8-10 arasý 1 kare saða
   }

   if(*kapPtr < 1)					//Starttan geri gidecek olursa 1.kounuma git
      *kapPtr = 1;
   else if(*kapPtr > Bitis_Cizgisi) //Bitisden ileri gidecekse bitiþte kal
      *kapPtr = Bitis_Cizgisi;
}

void tavHareket( int* tavPtr ){		//Tavþan hareketini pointer ile bulan fonksiyon
   int i;
   i = rand() % 10;					//1-10 arasýnda bir deðer rastgele üretilir
   if(i >= 1 && i <= 2){
	   //uyuyor
   }
   else if(i >= 3 && i <= 4){      //3-4 arasý 9 kare saða
      *tavPtr += 9;
   }else if(i == 5){			   //5 ise 12 kare sola
      *tavPtr -= 12;
   }else if(i >= 6 && i<= 8){	   //6-8 arasý 1 kare saða
      *tavPtr += 1;
   }else{						   //9-10 arasý 2 kare sola
      *tavPtr -= 2;
   }

   if(*tavPtr < 1)
      *tavPtr = 1;
   else if(*tavPtr > Bitis_Cizgisi)
      *tavPtr = Bitis_Cizgisi;
}

void pozisyon_bul( const int* const kapPtr, const int* const tavPtr ){
   int i;

   if(*kapPtr == *tavPtr){			//Tavþan ve kaplumbaða ayný konumda ise Ouch yazar
      for(i = 1; i < *kapPtr; i++){	//yollarý çizer
         printf("%s", "_" );
      }
      printf("OUCH!!!");
   }else if(*kapPtr < *tavPtr){		//Tavþan öndeyse
      for(i = 1; i < *kapPtr; i++ ){
         printf("%s", "_" );
      }
      printf("K");

      for(i = 1; i < (*tavPtr - *kapPtr); i++){
         printf("%s", "_" );
      }
      printf("T");
   }else{							//Kaplumbaða öndeyse
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
