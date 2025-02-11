Zaman Farkı Hesaplama Programı (Epoch Zamanı)
Bu C programı, iki farklı tarih ve saat arasındaki farkı hesaplar ve epoch zamanını saniye cinsinden gösterir. Epoch, Unix zamanını ifade eder ve 1 Ocak 1970 tarihinden itibaren geçen saniye sayısını temsil eder. Program, struct ve union kullanarak tarihlerle ilgili verileri işler ve epoch zamanı üzerinden farkı hesaplar.

Programın Özeti
Bu program, kullanıcının girdiği iki tarih ve saat arasındaki zaman farkını, Unix Epoch zamanına (1970-01-01 00:00:00 UTC) dönüştürerek hesaplar. Programın çalışma mantığı şu şekildedir:

Kullanıcıdan iki farklı tarih ve saat alınır.
Bu tarihler struct ve union veri yapıları kullanılarak işlenir.
Tarihler mktime fonksiyonu ile epoch zamanına dönüştürülür.
İki epoch zaman arasındaki fark hesaplanır ve saniye cinsinden ekrana yazdırılır.
Kullanım
Programı çalıştırın.
Program, ilk olarak ilk tarih ve saati (YYYY MM DD HH MM SS formatında) girmenizi isteyecektir.
Ardından ikinci tarih ve saati aynı formatta girmeniz istenecektir.
Program, girdiğiniz tarihler arasındaki farkı epoch zamanına göre saniye cinsinden hesaplayarak ekrana yazdıracaktır.
