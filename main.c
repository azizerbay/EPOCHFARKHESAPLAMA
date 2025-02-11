#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini tutan struct
struct DateTime {
    int year, month, day;
    int hour, minute, second;
};

// Epoch zamanýný ve tarih bilgisini ayný bellekte tutmak için union
union EpochConverter {
    struct DateTime dt;
    time_t epoch;
};

// Fonksiyon: Kullanýcýdan tarih ve saat alýr
void getDateTime(struct DateTime *dt) {
    printf("Tarih (YYYY MM DD): ");
    scanf("%d %d %d", &dt->year, &dt->month, &dt->day);
    printf("Saat (HH MM SS): ");
    scanf("%d %d %d", &dt->hour, &dt->minute, &dt->second);
}

// Fonksiyon: struct DateTime verisini epoch zamanýna çevirir
time_t convertToEpoch(struct DateTime dt) {
    struct tm timeInfo;
    timeInfo.tm_year = dt.year - 1900;  // struct tm, yýlý 1900'den itibaren sayar
    timeInfo.tm_mon = dt.month - 1;     // struct tm, aylarý 0'dan baþlatýr
    timeInfo.tm_mday = dt.day;
    timeInfo.tm_hour = dt.hour;
    timeInfo.tm_min = dt.minute;
    timeInfo.tm_sec = dt.second;
    timeInfo.tm_isdst = -1;  // Gün ýþýðýndan tasarrufu otomatik ayarla
    return mktime(&timeInfo);
}

int main() {
    union EpochConverter time1, time2;

    // Kullanýcýdan ilk tarihi al
    printf("Birinci tarih ve saat bilgilerini giriniz:\n");
    getDateTime(&time1.dt);

    // Kullanýcýdan ikinci tarihi al
    printf("ikinci tarih ve saat bilgilerini giriniz:\n");
    getDateTime(&time2.dt);

    // Epoch zamanýna çevirme
    time1.epoch = convertToEpoch(time1.dt);
    time2.epoch = convertToEpoch(time2.dt);

    // Zaman farkýný hesapla
    double diff = difftime(time2.epoch, time1.epoch);

    // Sonuçlarý ekrana yazdýr
    printf("\nEpoch zamaný (Birinci tarih): %ld saniye\n", time1.epoch);
    printf("Epoch zamaný (Ýkinci tarih): %ld saniye\n", time2.epoch);
    printf("iki tarih arasýndaki fark: %.0f saniye (%.2f saat)\n", diff, diff / 3600.0);

    return 0;
}
