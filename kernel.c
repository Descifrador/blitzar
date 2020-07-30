#include "include/common.h"
#include "include/keyboard.h"
#include "include/vga.h"
#include "include/error.h"
#include "include/screencontroller.h"
#include "include/gdt.h"
#include "include/idt.h"
#include "include/isr.h"
#include "include/irq.h"
#include "include/timer.h"
#include "include/shell.h"

void startscreen();

int main()
{
    startscreen();
    gdt_install();
    idt_install();
    isrs_install();
    irq_install_handler(0, timer_handler);
    irq_install_handler(1, keyboard_handler);
    irq_install();
    asm volatile("sti");
    cls();
    init_shell();
    return 0xDEAD;
}

void startscreen()
{
    cls();
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("------------------------------", 0x36);
    center_print("|    Welcome to unnamedOS!    |", 0x36);
    center_print("|         Version 0.1         |", 0x36);
    center_print("|          (Blitzar)          |", 0x36);
    center_print("|  Press any key to continue  |", 0x36);
    center_print("------------------------------", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    center_print("", 0x36);
    setcolor(0x36);
    colorRestOfScreen();
    while (inb(0x60) & 0x80)
    {
    };
    setcolor(0x0f);
    cls();
}