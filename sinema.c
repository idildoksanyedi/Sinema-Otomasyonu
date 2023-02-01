// Sinema Otomasyonu Projesi
// Ýdil Doksanyedi


#define _CRT_SECURE_NO_WARNINGS
#define ogrenci_indirim 0.05 // ogrenci biletlerine uygulanacak indirim %5. O yuzden sabit olarak yazdim.
#define cocuk_indirim 0.15  // cocuk biletlerine uygulanacak indirim %15. O yuzden sabit olarak yazdim.
#define bilet_fiyat 80 // indirimsiz bilet fiyati
#include<stdio.h>

float total_ogrenci(int ogrenci) {
	float ogrenci_total; // indirimli fiyati saklayacak degisken

	ogrenci_total = bilet_fiyat - (ogrenci * bilet_fiyat * ogrenci_indirim); //aritmetik hesap
	return ogrenci_total;
}
float total_cocuk(int cocuk) {
    float cocuk_total;  // indirimli fiyati saklayacak degisken

	cocuk_total = bilet_fiyat - (cocuk * bilet_fiyat * cocuk_indirim); //aritmetik hesap
	return cocuk_total;
}
float total_tam(int tam) {
	float tam_total;  // indirimli fiyati saklayacak degisken

	tam_total = bilet_fiyat * tam; //aritmetik hesap
	return tam_total;
}


int main() {
	int islem, gun,salon_no; // kullanicidan secilecek degeerler
	int  ogrenci, cocuk, tam;
	float toplam, toplam2, toplam3; // odenecek toplam fiyatlarýn degiskenleri
	char salon1[8] = "SALON1", salon2[9] = "SALON2", salon3[10] = "SALON3"; // salon numaralari

	

	printf("SINEMAMIZA HOSGELDINIZ :)\n\n");

	printf("FILM NO:\tFILM ADI:\tSAAT:\tSALON NO:\n");  // Sinema tablosu film numarasi,saat,salon ve filmin adini icerir.
	printf(" 2458\t       SuperMan  \t13.00\t %s\n", salon1);
	printf(" 3579\t    Hababam Sinifi  \t11.30\t %s\n", salon3);
	printf(" 1364\t   Evde Tekbasina  \t15.00\t %s\n\n", salon2);


	printf("Lutfen ekrana gelecek bilgileri doldurun: \n\n");

	printf("Kac tane ogrenci bileti alacaksiniz: "); // indirimlerden  yararlanmak icin bilet türlerini kullanicidan ister.
	scanf_s("%d", &ogrenci);
	printf("Kac tane cocuk bileti alacaksiniz: ");
	scanf_s("%d", &cocuk);
	printf("Kac tane tam bilet alacaksiniz: ");
	scanf_s("%d", &tam);

	printf("\n\n");

	printf("Birinci islem rezervasyon(1)\tIkinci islem bilet al(2).\n\n"); // otomasyon rezarvasyon ve bileti hemen alma secenegi sunar.
	printf("Hangi islemi yapmak istersiniz? ");
	scanf_s("%d", &islem);
	switch (islem) {

	case 1: // kullanici baska bir güne bilet almak isterse calisacak kisim.

		printf("Sectiginiz islem rezarvasyon yapmak.\n Lutfen rezarvasyon icin 1-7 arasinda bir gun degeri girin. ");
		printf("1-> Pazartesi    7-> Pazar : "); // rezarvasyonda kullanicidan haftanin bir gününü girmesini ister.
		scanf_s("%d", &gun);


		if (gun == 1) {
			printf("Pazartesi gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else if (gun == 2) {
			printf("Sali gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else if (gun == 3) {
			printf("Carsamba gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else if (gun == 4) {
			printf("Persembe gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else if (gun == 5) {
			printf("Cuma gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else if (gun == 6) {
			printf("Cumartesi gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else if (gun == 7) {
			printf("Pazar gunu icin rezarvasyon yapiyorsunuz.\n");
		}
		else {
			printf("Lutfen gun sayisini dogru girin.");
		}

		printf("Rezarvasyon yapmak istediginiz film numarasini girin: "); // Rezervasyon yapmak istedigi filmin tablodaki film numarasini kullanici girer.
		scanf_s("%d", &salon_no);

		printf("\n");

		if (salon_no == 2458) { // SALON1

			if (ogrenci >= 1) {
				if (cocuk >= 1) {
					if (tam >= 1) {
						toplam2 = total_cocuk(cocuk) + total_ogrenci(ogrenci) + total_tam(tam); // eger kullanici 3 bilet türüne de giris yaptýysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar.
						printf("Haftanin %d. gunune %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", gun, salon_no, salon1);// Kullaniciyi hangi gün hangi numarali ve hangi salona rezarvasyonu yaptirdigiyle alakali bilgilendirir.
						printf("Odeyeceginiz tutar: %.1f TL", toplam2); // Kulaniciya toplamda ödenecek miktri gosterir.
					}break;
					toplam = total_cocuk(cocuk) + total_ogrenci(ogrenci); //  
					printf("Haftanin %d. gunune %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", gun, salon_no, salon1);
					printf("Odeyeceginiz tutar: %.1f TL", toplam);

				}break;
				printf("Haftanin %d. gunune %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", gun, salon_no, salon1);
				printf("Odeyeceginiz tutar: %.1f TL", total_ogrenci(ogrenci)); // eger kullanici sadece ogrenci girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar


			}
			else if (ogrenci >= 1) {
				if (tam >= 1) {
					toplam3 = total_ogrenci(ogrenci) + total_tam(tam); //eger kullanici tam ve ogrenci girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar.
					printf("Haftanin %d. gunune %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", gun, salon_no, salon1);
					printf("Odeyeceginiz tutar: %.1f TL", toplam3);
				}
			}
			else if (cocuk >= 1) {
				printf("Haftanin %d. gunune %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon1);
				printf("Odeyeceginiz tutar: %.1f TL", total_cocuk(cocuk)); break; // eger kullanici sadece cocuk girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar
			}
			else if (tam >= 1); {
				printf("Haftanin %d. gunune %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.", gun,salon_no, salon1);
				printf("Odeyeceginiz tutar: %.1f TL", total_tam(tam)); break; // eger kullanici sadece tam girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar
			}
		}//**********************************************************************************************

		else if (salon_no == 3579) { // yukaridaki kisimla aynidir. SALON3
			if (ogrenci >= 1) {
				if (cocuk >= 1) {
					if (tam >= 1) {
						toplam2 = total_cocuk(cocuk) + total_ogrenci(ogrenci) + total_tam(tam);
						printf("Haftanin %d. gunune %d'lu Hababam Sinifi filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon3);
						printf("Odeyeceginiz tutar: %.1f TL", toplam2);
					}break;
					toplam = total_cocuk(cocuk) + total_ogrenci(ogrenci);
					printf("Haftanin %d. gunune %d'lu Hababam Sinifi filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon3);
					printf("Odeyeceginiz tutar: %.1f TL", toplam);

				}break;
				printf("Haftanin %d. gunune %d'lu Hababam Sinifi filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon3);
				printf("Odeyeceginiz tutar: %.1f TL", total_ogrenci(ogrenci));


			}
			else if (ogrenci >= 1) {
				if (tam >= 1) {
					toplam3 = total_ogrenci(ogrenci) + total_tam(tam); 
					printf("Haftanin %d. gunune %d'lu Hababam Sinifi filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n", gun, salon_no, salon3);
					printf("Odeyeceginiz tutar: %.1f TL", toplam3);
				}
			}
			else if (cocuk >= 1) {
				printf("Haftanin %d. gunune %d'lu Hababam Sinifi filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon3);
				printf("Odeyeceginiz tutar: %.1f TL", total_cocuk(cocuk)); break;
			}
			else if (tam > 1); {
				printf("Haftanin %d. gunune %d'lu Hababam Sinifi filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon3);
				printf("Odeyeceginiz tutar: %.1f TL", total_tam(tam)); break;
			}

		}
		
		else if (salon_no == 1364) { // SALON2
			if (ogrenci >= 1) {
				if (cocuk >= 1) {
					if (tam >= 1) {
						toplam2 = total_cocuk(cocuk) + total_ogrenci(ogrenci) + total_tam(tam);
						printf("Haftanin %d. gunune %d'lu Evde Tekbasina filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon2);
						printf("Odeyeceginiz tutar: %.1f TL", toplam2);
					}break;
					toplam = total_cocuk(cocuk) + total_ogrenci(ogrenci);
					printf("Haftanin %d. gunune %d'lu Evde Tekbasina filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon2);
					printf("Odeyeceginiz tutar: %.1f TL", toplam);

				}break;
				printf("Haftanin %d. gunune %d'lu Evde Tekbasina filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon2);
				printf("Odeyeceginiz tutar: %.1f TL", total_ogrenci(ogrenci));


			}
			else if (ogrenci >= 1) {
				if (tam >= 1) {
					toplam3 = total_ogrenci(ogrenci) + total_tam(tam); 
					printf("Haftanin %d. gunune %d'lu Evde tekbasiina filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", gun, salon_no, salon2);
					printf("Odeyeceginiz tutar: %.1f TL", toplam3);
				}
			}
			else if (cocuk >= 1) {
				printf("Haftanin %d. gunune %d'lu Evde Tekbasina filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon2);
				printf("Odeyeceginiz tutar: %.1f TL", total_cocuk(cocuk)); break;
			}
			else if (tam > 1); {
				printf("Haftanin %d. gunune %d'lu Evde Tekbasina filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.", gun, salon_no, salon2);
				printf("Odeyeceginiz tutar: %.1f TL", total_tam(tam)); break;
			}

		}
		else {
		printf("Hatali tuslama yaptiniz. Tekrar deneyin."); break;

		}




	case 2: // kullanici anlik bilet almak isterse

		printf("Bilet alma islemini sectiniz.");
		printf("\tLutfen izlemek istediginiz filmin numarasini girin: ");
		scanf_s("%d", &salon_no);

		if (salon_no == 2458) {
			if (ogrenci >= 1) {
				if (cocuk >= 1) {
					if (tam >= 1) {
						toplam2 = total_cocuk(cocuk) + total_ogrenci(ogrenci) + total_tam(tam);
						printf(" %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon1);
						printf("Odeyeceginiz tutar: %.1f TL", toplam2);
					}break;
					toplam = total_cocuk(cocuk) + total_ogrenci(ogrenci);
					printf(" %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon1);
					printf("Odeyeceginiz tutar: %.1f TL", toplam);

				}break;
				printf(" %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon1);
				printf("Odeyeceginiz tutar: %.1f TL", total_ogrenci(ogrenci));


			}
			else if (ogrenci >= 1) {
				if (tam >= 1) {
					toplam3 = total_ogrenci(ogrenci) + total_tam(tam); //eger kullanici tam ve ogrenci girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar.
					printf(" %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon1);
					printf("Odeyeceginiz tutar: %.1f TL", toplam3);
				}
			}
			else if (cocuk >= 1) {
				printf(" %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon1);
				printf("Odeyeceginiz tutar: %.1f TL\n", total_cocuk(cocuk)); break;
			}
			else if (tam >= 1); {
				printf(" %d'lu SuperMan filmine saat 13.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon1);
				printf("Odeyeceginiz tutar: %.1f TL\n", total_tam(tam)); break;
			}
		}
		else if (salon_no == 3579) { 
			if (ogrenci >= 1) {
				if (cocuk >= 1) {
					if (tam >= 1) {
						toplam2 = total_cocuk(cocuk) + total_ogrenci(ogrenci) + total_tam(tam);
						printf(" %d'lu Hababam Sinifi filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon3);
						printf("Odeyeceginiz tutar: %.1f TL\n", toplam2);
					}break;
					toplam = total_cocuk(cocuk) + total_ogrenci(ogrenci);
					printf(" %d'lu Hababam Sinifi filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon3);
					printf("Odeyeceginiz tutar: %.1f TL", toplam);

				}break;
				printf("%d'lu Hababam Sinifi filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon3);
				printf("Odeyeceginiz tutar: %.1f TL", total_ogrenci(ogrenci));


			}
			else if (ogrenci >= 1) {
				if (tam >= 1) {
					toplam3 = total_ogrenci(ogrenci) + total_tam(tam); //eger kullanici tam ve ogrenci girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar.
					printf(" %d'lu Hababam Sinifi filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon3);
					printf("Odeyeceginiz tutar: %.1f TL", toplam3);
				}
			}
			else if (cocuk >= 1) {
				printf(" %d'lu Hababam Sinifi filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon3);
				printf("Odeyeceginiz tutar: %.1f TL", total_cocuk(cocuk)); break;
			}
			else if (tam > 1); {
				printf(" %d'lu Hababam Sinifi filmine saat 11.30 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon3);
				printf("Odeyeceginiz tutar: %.1f TL", total_tam(tam)); break;
			}

		}
		else if (salon_no == 1364) {
			if (ogrenci >= 1) {
				if (cocuk >= 1) {
					if (tam >= 1) {
						toplam2 = total_cocuk(cocuk) + total_ogrenci(ogrenci) + total_tam(tam);
						printf(" %d'lu Evde Tekbasina filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon2);
						printf("Odeyeceginiz tutar: %.1f TL", toplam2);
					}break;
					toplam = total_cocuk(cocuk) + total_ogrenci(ogrenci);
					printf(" %d'lu Evde Tekbasina filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon2);
					printf("Odeyeceginiz tutar: %.1f TL", toplam);

				}break;
				printf(" %d'lu Evde Tekbasina filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon2);
				printf("Odeyeceginiz tutar: %.1f TL", total_ogrenci(ogrenci));


			}
			else if (ogrenci >= 1) {
				if (tam >= 1) {
					toplam3 = total_ogrenci(ogrenci) + total_tam(tam); //eger kullanici tam ve ogrenci girisi yaptiysa fonksiyonlardaki islemleri gerceklestirerek toplam ödenecek tutarý hesaplar.
					printf("%d'lu Evde tekbasina filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n",salon_no, salon2);
					printf("Odeyeceginiz tutar: %.1f TL", toplam3);
				}
			}
			else if (cocuk >= 1) {
				printf(" %d'lu Evde Tekbasina filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon2);
				printf("Odeyeceginiz tutar: %.1f TL", total_cocuk(cocuk)); break;
			}
			else if (tam > 1); {
				printf("%d'lu Evde Tekbasina filmine saat 15.00 %s'e rezarvasyonunuz yapilmistir.\n", salon_no, salon2);
				printf("Odeyeceginiz tutar: %.1f TL", total_tam(tam)); break;
			}

		}default:
			printf("Hatali tuslama yaptiniz tekrar deneyin."); break;
	}
	
	printf("\n");
	printf("\n SINEMAMIZI TERCIH ETTIGINIZ ICIN TESEKKURLER!!! YINE BEKLERIZ :)\n\n");

	return 0;

}