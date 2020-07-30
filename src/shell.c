#include "../include/shell.h"
string buffer = "\0                                  ";

u8int maincolor = 0x0f;

void shell_enterpressed()
{
    printchar('\n');
    shell();
}

void shell_addchar(char c)
{
    concatc(buffer, c, buffer);
}

void shell_backspace()
{
    remchar(buffer, buffer);
}

int shell_can_backspace()
{
    if (strlen(buffer) > 0)
        return 1;
    return 0;
}

void init_shell()
{
    setcolor(maincolor);
    print("unnamedOS>");
}

void shell()
{
    findCommand(buffer);
    buffer[0] = '\0';
    setcolor(maincolor);
    if (getY() == 0)
        print("unnamedOS>");
    else
        print("\nunnamedOS>");
}

void findCommand(string command)
{
    if (startswith(command, "art"))
    {
        if (strlen(command) >= strlen("art a"))
        {
            substring(command, command, 4);
            strtolower(command, command);
            gift_art(command);
        }
        else
        {
            print("enter something");
        }
    }
    else if (startswith(command, "solve"))
    {
        if (strlen(command) >= strlen("solve a + b"))
        {
            substring(command, command, 6);
            int result = solve(command);
            printnum(result);
        }
        else
        {
            print("Enter an expression");
        }
    }
    else if (strcmp(command, "cls"))
    {
        cls();
    }
    else if (startswith(command, "fibo"))
    {
        if (startswith(command, "fibo") && strlen(command) >= strlen("fibo a"))
        {
            substring(command, command, 5);
            int fib = fibonacci(command);
            printnum(fib);
        }
        else
        {
            print("Input a number too");
        }
    }
    else if (startswith(command, "sum"))
    {
        if (startswith(command, "sum") && strlen(command) >= strlen("sum a b"))
        {
            substring(command, command, 4);
            int k = sum(command);
            printnum(k);
        }
        else
        {
            print("Enter two numbers");
        }
    }
    else if (startswith(command, "setcolor"))
    {
        int a = toHex(command[11]);
        int b = toHex(command[12]);
        if (startswith(command, "setcolor 0x") && strlen(command) == 13 && a != -1 && b != -1)
        {
            maincolor = (a * 16) + b;
            setcolor(maincolor);
            colorRestOfScreen();
            print("color set to 0x");
            printchar(command[11]);
            printchar(command[12]);
        }
        else
        {
            setcolor(0x04);
            print("Please specify a color.");
        }
    }
    else if (startswith(command, "strlen"))
    {
        if (strlen(command) >= strlen("strlen a"))
        {
            substring(command, command, 7);
            printnum(strlen(command));
        }
        else
        {
            print("enter a string");
        }
    }
    else if (strcmp(command, "help"))
    {
        help();
    }
    else
    {
        int bg = maincolor / 16;
        if (bg == 0x4)
            setcolor((bg * 16) + 0xf);
        else
            setcolor((bg * 16) + 0x4);
        print("No such command ");
        print(command);
        print(".");
    }
}