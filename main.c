/*sharp oranını hesaplayan bir kod yazacağız bunun için kullanıcıdan 3 değer alacağız sonrasında sharp
 oranı formülüne göre sharp oranını hesaplayacağız-yanlış karakterler girilmesi durumunda hata komutu ile karşılaşacagız-
 ve çıkan sonucu getirdiği kazanca göre yorumlayacagız*/

#include <stdio.h>  //scanf,printf gibi fonksiyonları kullanmamızı sağlar

// Girdi tamponunu temizleyen fonksiyon
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Boş döngü: tüm karakterleri okur ve yok eder
    }
}

int main(void) { //c dilinde main fonksiyonu kodu başlatır
    double yatirim_getirisi, risksiz_faiz, standart_sapma, sharpe_orani;  //double veri tipi ile değişkenlerimizi atadık kullanıcının girdiği sayılar burada saklanacak

    printf("=== Sharpe Orani Hesaplayici ===\n");  //printf sayesinde kullanıcı ne ile karşılaşacagına dair bir başlıkla karşılaşıyor

    printf("Yatirim getirisi (%% cinsinden): ");  //ekrana yüzdecinsinden sayı girilmesini söyler
    if (scanf("%lf", &yatirim_getirisi) != 1) {   /*bu satır genel itibariyle hatalı girişte programı durdurur,
                                                   %lf kullanıcıdan ondalıklı sayı alır, &yatırım_getirisi değerimizi bu değişkende saklar,
                                                   !=1 ise hatalı karakter girişiminde hata verip çıkar*/
     printf("Gecersiz giris! Lütfen sayi giriniz.\n");
        return 1;
    }
    clearInputBuffer();

    printf("Risksiz faiz orani (%% cinsinden): ");  //risksiz faiz oranını ister-bir nevi garantili kazanç kaynaklaırdır-yine aynı şekilde sayı şeklinde karakter girişi ister aksi halde hata verir
    if (scanf("%lf", &risksiz_faiz) != 1) {
        printf("Gecersiz giris! Lütfen sayi giriniz.\n");
        return 1;
    }
    clearInputBuffer();

    printf("Portfoyun standart sapmasi (%% cinsinden): ");  //portfoyun standrt sapması ise yatırımın ne kadar dalgalandığını ifade eder yüksekse yatırım çok oynak düşükse oynak olmadığını ıfade eder
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("Gecersiz giris! Lütfen sayi giriniz.\n");
        return 1;
    }
    clearInputBuffer();

    // Negatif veya sıfır standart sapma kontrolü
    if (standart_sapma <= 0) {  //formüle göre getiriden risksiz olanı çıkarıp sonucu standart sapmaya bölüyoruz matematiksel açıdan hata çıkmaması adına standart sapma 0 olamaz ayrıca gerçek hayatta her yatırım bir miktarda olsa risk içerir yanı 0dan küçük olamaz
        printf("Standart sapma 0 veya negatif olamaz.\n"); //yanlı karakter girişlerinde ekranda uyarı verir
        return 1;
    }

    // Sharpe oranı hesaplama
    sharpe_orani = (yatirim_getirisi - risksiz_faiz) / standart_sapma;  //sharp oranı formülümüz

    printf("\nSharpe Orani = %.2f\n", sharpe_orani);  // formülden çıkan sonçlarımız ondalıklı olabilir bu yüzden virgülden sonraki iki sayıyı görmek için bu satırı yazdık

    // son olarak Yorumsal değerlendirme yapıyoruz
    if (sharpe_orani < 0)
        printf("-> Sharpe orani %.2f: Yatirim, risksiz getiriye gore daha kotu performans gostermis.\n", sharpe_orani);
    else if (sharpe_orani == 0)
        printf("-> Sharpe orani %.2f: Yatirim, sadece risksiz getiri kadar kazandirmis. Ekstra getirisi yok.\n", sharpe_orani);
    else if (sharpe_orani < 1)
        printf("-> Sharpe orani %.2f: Risk-getiri orani dusuk. Iyi gunler.\n", sharpe_orani);
    else if (sharpe_orani < 2)
        printf("-> Sharpe orani %.2f: Iyi bir performans. Iyi gunler.\n", sharpe_orani);
    else if (sharpe_orani < 3)
        printf("-> Sharpe orani %.2f: Cok iyi bir performans. Iyi gunler.\n", sharpe_orani);
    else if (sharpe_orani >= 3)
        printf("-> Sharpe orani %.2f: Mukemmel bir performans! Iyi gunler.\n", sharpe_orani);

    return 0;  //programımız bitiyor
}

