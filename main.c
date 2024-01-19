#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, sayi;

    printf("***VKI Karsilastirmasi***\n\n");

    printf("Kac Kisinin VKI'i Hesaplamak Istiyorsunuz?=");
    scanf("%d", &sayi);

    float boy[sayi];
	float kilo[sayi];
    float *indeks = (float *)malloc(sayi * sizeof(float));  // indeks dizisini dinamik olarak oluştur

    char *durum[sayi];  // durum dizisini karakter dizisi olarak tanımla

    for (i = 0; i < sayi; i++)
    {
        for (j = 0; j < 1; j++)
        {
            printf("Lutfen %d. Kisinin Boyunu Giriniz(m)=", i + 1);
            scanf("%f", &boy[i]);
            printf("Lutfen %d. Kisinin Kilosunu Giriniz(kg)=", i + 1);
            scanf("%f", &kilo[i]);
            indeks[i] = kilo[i] / (boy[i] * boy[i]);
        }

        // durum dizisine uygun durumu atamak için malloc kullan
        durum[i] = (char *)malloc(100 * sizeof(char));                     

        if (indeks[i] < 18.5)
        {
            snprintf(durum[i], 100, "MAALESEF DUSUK KILOLUSUNUZ!(Diyetisyene Gorunun)\a");
        }
        else if (indeks[i] >= 18.5 && indeks[i] < 25)
        {
            snprintf(durum[i], 100, "NORMAL KILOLUSUNUZ.");
        }
        else if (indeks[i] >= 25 && indeks[i] < 30)
        {
            snprintf(durum[i], 100, "FAZLA KILOLUSUNUZ!(Spor yapınız)");
        }
        else if (indeks[i] >= 30)
        {
            snprintf(durum[i], 100, "OBEZSINIZ!(Diyetisyene Gorunun)\a");
        }
    }

    for (i = 0; i < sayi; i++)
    {
        printf("%d. Kisinin Indeksi=%.3f  |  DURUM BILGISI = %s\n", i + 1, indeks[i], durum[i]);

        // malloc ile oluşturulan belleği temizler
        free(durum[i]);
    }

    // indeks dizisinindeki belleği temizliyor
    free(indeks);

    return 0;
}
