# ShellScriptFilter
Shell Script ve C ile filtreleme işlemleri


Script, kod bütünü olarak tanımlanabilir. Shell Script ise linux’da kullanılan komutların .sh uzantılı dosya olarak kaydedilerek bu dosyanın çalıştırılmasıyla tek seferde çok sayıda komutun çalıştırılmasıdır. Bu bizim çok işimize yarar. Script ile terminalde tek tek farklı komutları çalıştırmak yerine, bu komutları bir script dosyasıyla tek komutla hepsini çalıştırabiliriz. Ve bu çalıştırdığımız scripti saklayarak ihtiyacımız olduğu bir anda tekrar çalıştırabiliriz. Bu yazımda Shell Script ve C kullanarak yaptığım bir filtreleme sistemini, örnek kodlarla birlikte anlatacağım.
Filtreleme sisteminde Shell Script(systemCheck.sh) ve C uygulaması(filter.c) kullandım.
systemCheck.sh 2 tane argüman alıyor birinci argüman taranmak istenen klasör, diğer argüman ise taranan yasaklı kelimeler. systemCheck.sh ile taranmak istenen klasördeki tüm dosyalara recursive olarak erişilip filter’a argüman olarak gönderiliyor.
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
#!/bin/bash
 
recursivelyList() {
 for path in $1/*;do
    if [ -d $path ];then        # list directories
        #echo $path
        recursivelyList $path $2
    elif [ -f $path ]; then     # list files
        echo $path
    /home/recep/src/filter $2 $path
    echo ""
    fi
 done
}
 
recursivelyList $1 $2
 
filter 2 argüman alıyor birinci argüman yasaklı kelimeler, diğer argüman script ile elde edilmiş taranacak olan dosya. filter yasaklı kelimeleri dosya içinde tarıyor ve dosya içinde kaç adet yasaklı kelime kullanıldıysa listeliyor.
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
FILE *arg1, *arg2;
 
int main(int argc,char *argv[])
{
    char censored[100];
    arg1 = fopen(argv[1],"r");  // censored list
 
    while(fscanf(arg1,"%s",censored)!=EOF)
    {
        arg2 = fopen(argv[2],"r");  // open file
        int sayac=0, i=0;
        char ch, word[250];
 
        while( (ch=fgetc(arg2)) != EOF )
        {
            if( ('A'<=ch && ch<='Z') || ('a'<=ch && ch<='z') || ('0'<=ch && ch<='9') )  // if character in these situation
            {
                word[i]=ch;
                i++;
            }else
            {
                word[i]='\0';
                i=0;
                if(strcmp(censored,word) == 0)   // if censonred word equal to other words
                    sayac++;
            }
        }//while
 
        if(sayac != 0)  // if it has any censonred words
    {
            printf("%d adet %sn",sayac ,censored);
    }
 
    }//while
 
    return 0;
}
Basit şekilde Script ve C kullanarak bir dizin üzerinde yapılabilecek filtreleme işlemlerini anlatmaya çalıştım. Görüldüğü gibi Script pratikliğiyle çoğu zaman işimizi kolaylaştırmaktadır.
