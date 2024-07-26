
**push_swap** projesi, verileri sıralamanız gereken oldukça basit ve etkili bir algoritma projesidir. Vermiş olduğunuz yüzlerce binlerce sayıyı kısa süre içerisinde sıralar.

Bu proje iki program içerir:
- İlk program **checker** olarak adlandırılır ve tamsayı argümanlar alır, standart çıktıda talimatları okur. Talimatlar okunduktan sonra, checker bunları uygular ve tamsayılar sıralanmışsa `OK` olarak gösterir. Aksi takdirde, `KO` olarak gösterir.
- İkinci program **push_swap** olarak adlandırılır ve verilen tamsayı argümanlarını sıralar , standart çıktıda hesaplar ve gösterir.

## push_swap Talimatları

- **sa**: *swap a* - yığın a'nın üstündeki ilk 2 elemanı takas eder. Tek bir eleman veya hiç eleman yoksa hiçbir şey yapmaz.
- **sb**: *swap b* - yığın b'nin üstündeki ilk 2 elemanı takas eder. Tek bir eleman veya hiç eleman yoksa hiçbir şey yapmaz.
- **ss**: sa ve sb'yi aynı anda yapar.
- **pa**: *push a* - b'nin üstündeki ilk elemanı alır ve a'nın üstüne koyar. b boşsa hiçbir şey yapmaz.
- **pb**: *push b* - a'nın üstündeki ilk elemanı alır ve b'nin üstüne koyar. a boşsa hiçbir şey yapmaz.
- **ra**: *rotate a* - yığın a'daki tüm elemanları 1 pozisyon yukarı kaydırır. İlk eleman son eleman olur.
- **rb**: *rotate b* - yığın b'deki tüm elemanları 1 pozisyon yukarı kaydırır. İlk eleman son eleman olur.
- **rr**: ra ve rb'yi aynı anda yapar.
- **rra**: *reverse rotate a* - yığın a'daki tüm elemanları 1 pozisyon aşağı kaydırır. Son eleman ilk eleman olur.
- **rrb**: *reverse rotate b* - yığın b'deki tüm elemanları 1 pozisyon aşağı kaydırır. Son eleman ilk eleman olur.
- **rrr**: rra ve rrb'yi aynı anda yapar.

## Derleme

Checker'ı derlemek için: `make checker`

Push_swap'i derlemek için: `make push_swap`

Her ikisini de derlemek için: `make`

## Çalıştırma

Checker: `./checker 0 2 3 1` ardından program kullanıcı girişini bekler

Push_swap: `./push_swap 0 2 3 1`

Not: Yığın işlemlerini görmek için ilk parametre olarak `-v` debug seçeneğini de kullanabilirsiniz.

![alt text](https://github.com/ska42/push_swap/blob/main/img/option_debug_example.png?raw=true)

## Test

`script.sh` adında bir bash betiği vardır; bu betik n boyutunda bir dizi oluşturur, karıştırır ve ardından `push_swap | checker` komutunu x kez test eder.

```
./script.sh size_array [nb_times]
```

![alt text](https://github.com/ska42/push_swap/blob/main/img/script_example.png?raw=true)

### Bölüm I: Çözüm İçin Hazırlık

#### Adım 1: İndeksleme

Görev gereği verilen sayılar tekrarlanmamalıdır. Bu nedenle her sayıya bir indeks atayabiliriz. Bu, gelecekteki adımlarda bize yardımcı olacaktır.

İndeks `0` en küçük sayıya atanır. En büyük sayıya ise `sayılar sayısı - 1` indeksi atanır.

_Örnek_

Numara|İndeks
-----:|-----:
-2147483648|0
2100|4
220010|6
-1|1
7|2
210815|5
121|3

#### Adım 2: İşaretleme

İki farklı işaretleme modum var:

* `büyüktür` işaretleme modu
* `indeksine göre` işaretleme modu

_Önce bir işaretleme modunu algoritmamda kullanırım, sonra ikinci modunu kullanırım. Sonuçları karşılaştırır ve daha iyi olanını gösteririm._

İşaretleme sırasında hangi elemanları yığın A'da tutacağımıza karar vermemiz gerekir. Diğer elemanlar yığın B'ye taşınacaktır.

Seçilen modda mümkün olduğunca çok elemanı yığın A'da tutmaya çalışırız.

Bu adımda `markup_head` bulunmalı ve seçilen `markup_head` ile ve belirtilen işaretleme modunda işaretleme yapılmalıdır. `markup_head` işaretlemenin başlangıç elemanıdır.

`markup_head`'i bulmak için her elemanla işaretleme yaparız ve yığın A'da en fazla elemanı tutacak olan elemanı `markup_head` olarak atarız.

İki eleman aynı sonucu veriyorsa, `markup_head` olarak daha küçük indekse sahip eleman seçilir.

#### `büyüktür` işaretleme modu

`markup_head`'ten başlayarak her elemanın önceki elemandan büyük olması gerekir. Bu durumu sağlamayan elemanlar yığın B'ye taşınır.

_Örnek_

`-2147483648` elemanını `markup_head` olarak kullanarak `büyüktür` işaretleme modunda işaretleme sonucu.

Numara|İndeks|Yığın A'da Tutma
-----:|-----:|:-----:
-2147483648|0|`doğru`
2100|4|`doğru`
220010|6|`doğru`
-1|1|`yanlış`
7|2|`yanlış`
210815|5|`yanlış`
121|3|`yanlış`

_Başka bir örnek_

`-1` elemanını `markup_head` olarak kullanarak `büyüktür` işaretleme modunda işaretleme sonucu.

Numara|İndeks|Yığın A'da Tutma
-----:|-----:|:-----:
-2147483648|0|`yanlış`
2100|4|`yanlış`
220010|6|`doğru`
-1|1|`doğru`
7|2|`doğru`
210815|5|`doğru`
121|3|`yanlış`

#### `indeksine göre` işaretleme modu

`markup_head`'ten başlayarak her elemanın, önceki elemandan 1 indeks fazla olması gerekir. Bu durumu sağlamayan elemanlar yığın B'ye taşınır.

_Örnek_

`-2147483648` elemanını `markup_head` olarak kullanarak `indeksine göre` işaretleme modunda işaretleme sonucu.

Numara|İndeks|Yığın A'da Tutma
-----:|-----:|:-----:
-2147483648|0|`doğru`
2100|4|`yanlış`
220010|6|`yanlış`
-1|1|`doğru`
7|2|`doğru`
210815|5|`yanlış`
121|3|`doğru`

### Bölüm II: Yığın A'dan Yığın B'ye

**Pseudocode**

```
YIGIN A'DA "Yığın A'da Tutma" alanında "yanlış" değeri olan elemanlar olduğu sürece
      SA (swap a) gerekli ise
            sa (swap a) komutunu gerçekleştir
            işaretlemeyi güncelle
      EĞER A yığınının üstündeki eleman "yanlış" değere sahipse
            pb (push b) komutunu gerçekleştir
      EĞER DEĞİLSE
            ra (rotate a) komutunu gerçekleştir
```

#### `sa (swap a)` gerektiğini nasıl kontrol ederiz?

`sa (swap a)` komutunu gerçekleştirmeli ve ardından işaretlemeyi yeniden yapmalıyız. Sadece önceki adımlarda seçilen parametrelerle (örneğin `markup_head`) işaretlemeyi güncellemeliyiz.

Daha sonra, `sa (swap a)` komutunu uyguladıktan sonra yığın A'da kaç elemanın kalacağını, `sa (swap a)` komutu olmadan kıyaslamalıyız.

Eğer `sa (swap a)` komutundan sonra daha fazla eleman kalıyorsa, bu komutu yapmanın bir nedeni vardır.

Sonuçta, `sa (swap a)` komutunu geri almalı ve hesaplamalarımızın sonucunu döndürmeliyiz.

### Bölüm III: Yığın B'den Yığın A'ya

**Pseudocode**

```
YIGIN B BOŞ OLANA KADAR
      Yığın B'den yığın A'ya taşınacak elemanı seç
      Pa (push a) komutu için yığın

 A ve yığın B'yi uygun hale getirmek için hareket et
      pa (push a) komutunu gerçekleştir
```

### Yığın B'den Yığın A'ya taşınacak elemanı nasıl seçeriz?

Yığın B'deki bir elemanı üstteki yığına taşımak için kaç komut gerektiğini ve yığın A'daki uygun bir elemanı üstteki yığına taşımak için kaç komut gerektiğini hesaplamalıyız.

Bu değeri yığın B'deki her eleman için hesaplamalı ve en küçük hesaplanan değere sahip olan elemanı seçip yığın A'ya taşımalıyız.

### Bölüm IV: Yığın A'yı Hizalama

Son olarak, yığın A'yı hizalamamız gerekiyor. En küçük eleman yığının üstünde olana kadar yığın A'yı hareket ettirmeliyiz.

### Önemli

Bu algoritmayı iki kez uygularım. İlk olarak bir işaretleme modunu kullanırım, ardından diğer modunu kullanırım. Sonuçları karşılaştırır ve daha iyi olanını gösteririm.

---
