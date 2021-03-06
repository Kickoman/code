#include <sergeenko>

DREVA FENVIKA

Andrzej потратил 84кб

Мы не храним одно из слагаемых
Восемь элементов
А один
А два
А три
А четыре
А пять
А шесть
А семь
так, я сказал немножечко по-другому, так что давайте пронумеруем их, в прошлый раз я рассказывал, как будет при нумерации от 1, теперь посмотрим,
Как будет при нумерации от нуля.

А ноль
А один
А два
А три
А четыре 
Опять
А шесть
А семь

Теперь мы группируем их попарно и храним там суммы.

  (сумма)
  /     \
(Х)     (У)

Продолжаем аналогичным образом...

Основной смысл дерева Фенвика ...
 Это у нас дерево отрезков.

Мы можем не хранить одно из слагаемых, а вычислять его по формуле b = s - a;

Буду предполагать, что мы не храним ПРАВОЕ слагаемое.
Соответственно, вот эти элементы не нужны.

Иллюстрация 1.

i чётное => уровень 0 => f[i] = a[i];

По сути, номер уровня будет определяться очень интересным образом.

Ноль умножить на два и ноль умножить на два плюс один (кэп подсказывает, будет 0 и 1 соответственно)

Если у нас уровень K и номер J
то потомки K - 1, номер 2J или 2J+1

элементы заканчиваются на нулевое количество единиц (сложнааа)

На втором уровне будет точно такая же формула, только получается, что мы спускаемся вправо, жи чётно, а потом мы ещё спускаемся и ещё два плюс один,
Снова короч единица вышла

По сути получается, что у нас, если элемент был на уровне К и имел номер Жи и если он хранится в массиве Ф, то он будет иметь номер Жи*2^K + 2^K - 1 = 
= (j + 1) * 2 ^ k - 1

жиштрих умножить на два в степени ка ... что-то странное, но это всё

То есть, мы сейчас знаем, как по элементу определить, ...
Точнее, как по уровню элемента найти его дочерний элемент, его уровень и номера

тут три раза одно и то же сказали, я не собираюсь так писать, мне Л

Если у нас есть число, которое заканчивается на некоторое количество единиц, перед ними стоит какое-то число.

Напомню следующее, что у нас вот, эмм, количество элементов, сумма которыъ хранится на уровне К - это два в степени Ка.

Соответственно в ф итом хранится сумма a[i]  + a[i - 1] + ... + a[i - 2 ^ k  + 1];

т оесть всего у нас тут получается два в степени к элементов, где ка определяется, как количество "вот этих"

Нас больше интересует, как по номеру и определить количество предыдущих.

Тут снова каша какая-то у него в голове.

Найти сумму первых элементов и увеличить их на заданное число, возможно отрицательное.
Сумма идите нахер и плюс и так далее.

у нас есть последовательность из единиц и ноль

Если мы прибавим единицу, мы получим пэштрих один и нули

Давайте теперь сравним... Сравниваем. Что у нас получается. Если мы сюда прибавим единицу, опять же, в конце у нас последовательность единиц. 
Ему очень хочется прибавить единицу.
Он получает p'10001000 '

// Андрей не понял

тут ноль и единица, кстати

Для определения и минус два ка, мы должны выполнять И ЭНД И ПЛЮС ОДИН и отнять единицу


КТО-НИБУДЬ, ОБЪЯСНИТЕ МНЕ, К ЧЕМУ ВСЁ ЭТО ОН РАССКАЗЫВАЕТ?
НАХРЕНААА

он объясняет, как прибавить единицу, а не дерево фенвика

i & (i - 1)

отсюда это получается, если сделать правильные замены

новое значение И это есть вот это.

Жи есть жи энд жи минус один

Можем что угодно показать, но это нам, чтобы немножко подумали.
ПОДСТАНОВКА!    

Сюда мы вместо И будем подставлять жи минус один.

А тут получается жиштрих равно жиминусодинэнджи

Это нам позволяет вычислять сумму. Есть операция изменения элемента, увеличения его на какое-то число.

Нам надо понять, какие элементы мы должны пересчитать.

Как спускаться, мы уже знаем. Мы спустились на самое дно. 
Теперь надо идти к корню

// Андрей хочет спать 
// т9

собсна, по этим формулам у нас предок на уровне к + 1

И здесь его наш потомок на самом деле имеет всё другое
Давайте тогда просто поделим его на два!

Теперь, в чём самый интересный момент? 
Если наш предок не хранится, а кто его знает, жи див два может оказаться числом нечётным. Мы не знаем, кто был предок.
Вот, например, для а2. Сам а2 хранится, он чётный, а вот его предок - хер там плавал.

Надо обратить один момент вот на что, на следующий аспект, что на самом деле у нас, если мы применим вот эту формулу,
мы получим место, где должен был храниться этот элемент. 
Опять каша

мы вместо жи должны подставить жи див два

т.е. у нас было некое число жи, которое было чётным, а затем было какое-то количество единиц. Ка штук. соотно предок, является
увеличением числа единиц, только здесь мы теперь отбрасываем этот ноль. Мы его ИМЕННО ОТБРАСЫВАЕМ!!!

Гениальные фразочки.

Ну давайте думать, ёпт
(j / 2 + 1 ) * 2 ^ (k + 1) 8=====D

Интересный момент. 
Смотрим.
Здесь у нас, по сути, умножить на два. Жи чётно. Мы берём номер хранящегося элемента...
предка...
жи... на два в степени ка плюс два в степени КАПЛЮСОДИН минус один

// Я тоже хочу спать 

он ещё и неправильно сделал, оказывается.
Ну ёбана.

Опять увеличиваем. Чем больше, походу, тем лучше.

И заменяем ноль на единицу. Вот этот.
Ему снова хочется.
Мммм.

//Сергеенко-Сергеенко, не садись мне на коленки.

Как так можно, имея префикс ноль, один, получить К единиц.

Нужно просто сделать ор.

i | (i + 1)

Элементы с нуля по седьмой
Где-то таким вот образом
Повторю, вспомнили. j = (j | (j - 1)) + 1;

C[i] = a[i] + b[i];

Fa Fb
Fc[i] = F(Fa[i], Fb[i]);

!!! ФРАЗА!!! "изоморфизм массивов деревьев фенвика."

Дерево фенвика деревьев фенвика

Можно ли построить?

Массив массивов это не двумерный массив

int sum2(int x, int y)
{
    int s = 0, i = x, j = y;
    while (i >= 0)
    {
        j = y;
        while (j >= 0)
        {
            s += f[i][j];
            j = j & (j + 1) - 1;
        }
        i = i & (i + 1) - 1;
    }
    return s;
}

void add(int x, int y, int value)
{
    int i = x;
    while (i < n)
    {
        int j = y;
        while (j < m)
        {
            t[i][j] += value;
            j |= j + 1;
        }
        i |= i + 1;
    }
}

ANDRZEJ LALKA

+++
//mda

/*
    #####  #   #  ###   ####  ####  #####  ####
    #   #  ##  #  #  #  #  #     #  #         #
    #####  # # #  #  #  ###     #   ####      #
    #   #  #  ##  #  #  # #    #    #      #  #
    #   #  #   #  ###   #  #  ####  #####   ##

    #   #  ###   #####
    ## ##  #  #  #   #
    # # #  #  #  #####
    #   #  #  #  #   #
    #   #  ###   #   #
*/

/*
....#####..#...#..###...####..####..#####..####
....#...#..##..#..#..#..#..#.....#..#.........#
....#####..#.#.#..#..#..###.....#...####......#
....#...#..#..##..#..#..#.#....#....#......#..#
....#...#..#...#..###...#..#..####..#####...##

....#...#..###...#####
....##.##..#..#..#...#
....#.#.#..#..#..#####
....#...#..#..#..#...#
....#...#..###...#...#
*/


число а можно представить в виде произведения двух целых чисел.

Бля, да он про деление рассказывает

Наибольший общий делитель есть Бэ

из делителей делитель

А можно представить как bq*c

SOVOKUPNOST общих делителе совпадает
Да ёпта, ты это уже говорил

ОЧЕВИДНО

Если дельта есть некий общий делитель а и б, то НОД ай. мне последовательность

Есть единица.
Ну хоть что-то есть.

Затем. Если у нас есть 2 взаимнопростых числа (ВП(Ч)), то АЦБ будет ЦБ 

Бэ делит Цэ

Если
Нам известно, что у нас есть набор чисел аитых и набор чисел бэитых, и нам известно, бэжитых скажем, получим, что если каждое из чисел аитых...
Будет ВП с произведением чего-то там.
