#include "../include/functions.h"

int sum(string twonum)
{
    int len = strlen(twonum);
    char b[len];
    splitstr(twonum, b);
    int fi = toInt(twonum);
    int se = toInt(b);
    return fi + se;
}

int fibonacci(string num)
{
    int last = toInt(num);
    int arr[last];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < last; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[last - 1];
}

int palin(string name)
{
    int len = strlen(name);
    for (int i = 0; i < len / 2; i++)
    {
        if (name[i] == name[len - i - 1])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int binary(int num)
{
    int expo = 1;
    int result = 0;
    while (num != 0)
    {
        int rem = num % 2;
        result += rem * expo;
        expo *= 10;
        num /= 2;
    }
    return result;
}

void help()
{
    println("Commands:");
    println("cls: clears the screen.");
    println("setcolor 0x##: set the color of the screen.");
    println("sum a b: adds two numbers");
    println("fibo n: prints the nth fibonacci number");
    println("strlen s: prints the length of the string");
    println("art s: ester egg");
}

void gift_art(char name[])
{
    string calli[26][7] = {{"      a       ",
                            "     a a      ",
                            "    a   a     ",
                            "   a     a    ",
                            "  a a a a a   ",
                            " a         a  ",
                            "a           a "},
                           {"b b b b    ",
                            "b       b  ",
                            "b        b ",
                            "b b b b b  ",
                            "b        b ",
                            "b        b ",
                            "b b b b b  "},
                           {"    c c c   ",
                            "  c       c ",
                            "c           ",
                            "c           ",
                            "c           ",
                            "  c       c ",
                            "    c c c   "},
                           {"d d d d     ",
                            "d        d  ",
                            "d         d ",
                            "d         d ",
                            "d         d ",
                            "d        d  ",
                            "d d d d     "},
                           {"e e e e e ",
                            "e         ",
                            "e         ",
                            "e e e     ",
                            "e         ",
                            "e         ",
                            "e e e e e "},
                           {"f f f f f ",
                            "f         ",
                            "f         ",
                            "f f f     ",
                            "f         ",
                            "f         ",
                            "f         "},
                           {"    g g g   ",
                            "  g       g ",
                            "g           ",
                            "g    g g g  ",
                            "g         g ",
                            "  g       g ",
                            "    g g g   "},
                           {"h         h ",
                            "h         h ",
                            "h         h ",
                            "h h h h h h ",
                            "h         h ",
                            "h         h ",
                            "h         h "},
                           {"i i i i i ",
                            "    i     ",
                            "    i     ",
                            "    i     ",
                            "    i     ",
                            "    i     ",
                            "i i i i i "},
                           {"        j ",
                            "        j ",
                            "        j ",
                            "        j ",
                            "j       j ",
                            "  j     j ",
                            "    j j   "},
                           {"k         k ",
                            "k       k   ",
                            "k     k     ",
                            "k   k       ",
                            "k k   k     ",
                            "k       k   ",
                            "k         k "},
                           {"l         ",
                            "l         ",
                            "l         ",
                            "l         ",
                            "l         ",
                            "l         ",
                            "l l l l l "},
                           {"m           m ",
                            "m m       m m ",
                            "m  m     m  m ",
                            "m    m m    m ",
                            "m     m     m ",
                            "m           m ",
                            "m           m "},
                           {"n        n ",
                            "n n      n ",
                            "n  n     n ",
                            "n   n    n ",
                            "n    n   n ",
                            "n     n  n ",
                            "n      n n "},
                           {"    o o o     ",
                            "  o       o   ",
                            "o           o ",
                            "o           o ",
                            "o           o ",
                            "  o       o   ",
                            "    o o o     "},
                           {"p p p p    ",
                            "p       p  ",
                            "p        p ",
                            "p p p p p  ",
                            "p          ",
                            "p          ",
                            "p          "},
                           {"    q q q     ",
                            "  q       q   ",
                            "q           q ",
                            "q           q ",
                            "q       q   q ",
                            "  q       q   ",
                            "    q q q   1 "},
                           {"r r r r    ",
                            "r       r  ",
                            "r        r ",
                            "r r r r r  ",
                            "r  r       ",
                            "r    r     ",
                            "r      r r "},
                           {"  s s s   ",
                            "s       s ",
                            " s        ",
                            "   s      ",
                            "     s    ",
                            "s       s ",
                            "  s s s   "},
                           {"t t t t t ",
                            "    t     ",
                            "    t     ",
                            "    t     ",
                            "    t     ",
                            "    t     ",
                            "    t     "},
                           {"u           u ",
                            "u           u ",
                            "u           u ",
                            "u           u ",
                            "u           u ",
                            "  u       u   ",
                            "    u u u     "},
                           {"v           v ",
                            " v         v  ",
                            "  v       v   ",
                            "   v     v    ",
                            "    v   v     ",
                            "     v v      ",
                            "      v       "},
                           {"w           w ",
                            "w           w ",
                            "w     w     w ",
                            "w    w w    w ",
                            "w  w     w  w ",
                            "w w       w w ",
                            "w           w "},
                           {"x         x ",
                            " x       x  ",
                            "   x   x    ",
                            "     x      ",
                            "   x   x    ",
                            " x       x  ",
                            "x         x "},
                           {"y        y ",
                            " y      y  ",
                            "   y  y    ",
                            "    y      ",
                            "  y        ",
                            " y         ",
                            "y          "},
                           {"z z z z z z ",
                            "         z  ",
                            "       z    ",
                            "     z      ",
                            "   z        ",
                            " z          ",
                            "z z z z z z "}};

    int length = strlen(name);
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < length; j++)
        {
            int c = (int)(name[j]) - 97;
            print(calli[c][i]);
        }
        println("");
    }
}