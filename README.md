# ShellScriptFilter
Shell Script ve C ile filtreleme işlemleri


Script, kod bütünü olarak tanımlanabilir. Shell Script ise linux’da kullanılan komutların .sh uzantılı dosya olarak kaydedilerek bu dosyanın çalıştırılmasıyla tek seferde çok sayıda komutun çalıştırılmasıdır. Bu bizim çok işimize yarar. Script ile terminalde tek tek farklı komutları çalıştırmak yerine, bu komutları bir script dosyasıyla tek komutla hepsini çalıştırabiliriz. Ve bu çalıştırdığımız scripti saklayarak ihtiyacımız olduğu bir anda tekrar çalıştırabiliriz. Bu yazımda Shell Script ve C kullanarak yaptığım bir filtreleme sistemini, örnek kodlarla birlikte anlatacağım.
Filtreleme sisteminde Shell Script(systemCheck.sh) ve C uygulaması(filter.c) kullandım.
systemCheck.sh 2 tane argüman alıyor birinci argüman taranmak istenen klasör, diğer argüman ise taranan yasaklı kelimeler. systemCheck.sh ile taranmak istenen klasördeki tüm dosyalara recursive olarak erişilip filter’a argüman olarak gönderiliyor.

systemCheck.sh

filter 2 argüman alıyor birinci argüman yasaklı kelimeler, diğer argüman script ile elde edilmiş taranacak olan dosya. filter yasaklı kelimeleri dosya içinde tarıyor ve dosya içinde kaç adet yasaklı kelime kullanıldıysa listeliyor.

filter.c

Basit şekilde Script ve C kullanarak bir dizin üzerinde yapılabilecek filtreleme işlemlerini anlatmaya çalıştım. Görüldüğü gibi Script pratikliğiyle çoğu zaman işimizi kolaylaştırmaktadır.


Kaynak:
<a href="http://recepdur.com/shell-script-ile-filtreleme/">recepdur.com/shell-script-ile-filtreleme</a>
