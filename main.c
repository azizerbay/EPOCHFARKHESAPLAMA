#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini tutan struct
struct DateTime {
    int year, month, day;
    int hour, minute, second;
};

// Epoch zaman�n� ve tarih bilgisini ayn� bellekte tutmak i�in union
union EpochConverter {
    struct DateTime dt;
    time_t epoch;
};

// Fonksiyon: Kullan�c�dan tarih ve saat al�r
void getDateTime(struct DateTime *dt) {
    printf("Tarih (YYYY MM DD): ");
    scanf("%d %d %d", &dt->year, &dt->month, &dt->day);
    printf("Saat (HH MM SS): ");
    scanf("%d %d %d", &dt->hour, &dt->minute, &dt->second);
}

// Fonksiyon: struct DateTime verisini epoch zaman�na �evirir
time_t convertToEpoch(struct DateTime dt) {
    struct tm timeInfo;
    timeInfo.tm_year = dt.year - 1900;  // struct tm, y�l� 1900'den itibaren sayar
    timeInfo.tm_mon = dt.month - 1;     // struct tm, aylar� 0'dan ba�lat�r
    timeInfo.tm_mday = dt.day;
    timeInfo.tm_hour = dt.hour;
    timeInfo.tm_min = dt.minute;
    timeInfo.tm_sec = dt.second;
    timeInfo.tm_isdst = -1;  // G�n �����ndan tasarrufu otomatik ayarla
    return mktime(&timeInfo);
}

int main() {
    union EpochConverter time1, time2;

    // Kullan�c�dan ilk tarihi al
    printf("Birinci tarih ve saat bilgilerini giriniz:\n");
    getDateTime(&time1.dt);

    // Kullan�c�dan ikinci tarihi al
    printf("ikinci tarih ve saat bilgilerini giriniz:\n");
    getDateTime(&time2.dt);

    // Epoch zaman�na �evirme
    time1.epoch = convertToEpoch(time1.dt);
    time2.epoch = convertToEpoch(time2.dt);

    // Zaman fark�n� hesapla
    double diff = difftime(time2.epoch, time1.epoch);

    // Sonu�lar� ekrana yazd�r
    printf("\nEpoch zaman� (Birinci tarih): %ld saniye\n", time1.epoch);
    printf("Epoch zaman� (�kinci tarih): %ld saniye\n", time2.epoch);
    printf("iki tarih aras�ndaki fark: %.0f saniye (%.2f saat)\n", diff, diff / 3600.0);

    return 0;
}
