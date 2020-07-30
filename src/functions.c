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

int precedence(string op)
{
    if (strcmp(op, "+") || strcmp(op, "-"))
        return 1;
    if (strcmp(op, "/") || strcmp(op, "*"))
        return 2;
    return 0;
}
int applyOp(int a, int b, string op)
{
    if (strcmp(op, "/"))
    {
        return a / b;
    }
    else if (strcmp(op, "*"))
    {
        return a * b;
    }
    else if (strcmp(op, "-"))
    {
        return a - b;
    }
    else if (strcmp(op, "+"))
    {
        return a + b;
    }
}

int solve(string expr)
{
    string token[20];
    int num_tok = 0;
    for (int i = 0; i < 20; i++)
    {
        char temp[10];
        splitstr(expr, temp);
        if (strcmp(expr, temp))
        {
            break;
        }
        strcpy(token[i], temp);
        num_tok++;
    }
    string ops[num_tok];
    int values[num_tok];
    int ops_top = -1, values_top = -1;
    for (int k = 0; k < num_tok; k++)
    {
        if (strcmp(token[k], "("))
        {
            ops_top++;
            strcpy(ops[ops_top], token[k]);
        }
        else if (isDigit(token[k]))
        {
            values_top++;
            values[values_top] = toInt(token[k]);
        }
        else if (strcmp(token[k], ")"))
        {
            while (ops_top != -1 && strcmp(ops[ops_top], "("))
            {
                int val2 = values[values_top];
                values_top--;
                int val1 = values[values_top];
                values_top--;

                string op = ops[ops_top];
                ops_top--;

                values_top++;
                values[values_top] = applyOp(val1, val2, op);
            }
            if (ops_top != -1)
            {
                ops_top--;
            }
        }
        else
        {
            while (ops_top != -1 && precedence(ops[ops_top]) >= precedence(token[k]))
            {
                int val2 = values[values_top];
                values_top--;

                int val1 = values[values_top];
                values_top--;

                string op = ops[ops_top];
                ops_top--;

                values_top++;
                values[values_top] = applyOp(val1, val2, op);
            }
            ops_top++;
            strcpy(ops[ops_top], token[k]);
        }
    }
    while (ops_top != -1)
    {
        int val2 = values[values_top];
        values_top--;

        int val1 = values[values_top];
        values_top--;

        string op = ops[ops_top];
        ops_top--;

        values_top++;
        values[values_top] = applyOp(val1, val2, op);

        values_top++;
        values[values_top] = applyOp(val1, val2, op);
    }
    return values[values_top];
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