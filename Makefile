COMPILER = gcc
LINKER = ld
ASSEMBLER = nasm
CFLAGS = -m32 -c --freestanding
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T linker.ld

OBJS = Objects/kernel.o Objects/boot.o Objects/common.o Objects/error.o Objects/gdt.o Objects/idt.o Objects/irq.o Objects/isr.o Objects/keyboard.o Objects/screencontroller.o Objects/shell.o Objects/timer.o Objects/vga.o Objects/functions.o
OUTPUT = os/boot/kernel.bin

run:all

all:$(OBJS)
	mkdir os/ -p
	mkdir os/boot -p
	$(LINKER) $(LDFLAGS) -o $(OUTPUT) $(OBJS)

Objects/boot.o:boot.asm
	$(ASSEMBLER) $(ASFLAGS) -o Objects/boot.o boot.asm

Objects/kernel.o:kernel.c
	$(COMPILER) $(CFLAGS) kernel.c -o Objects/kernel.o

Objects/common.o:src/common.c
	$(COMPILER) $(CFLAGS) src/common.c -o Objects/common.o

Objects/error.o:src/error.c
	$(COMPILER) $(CFLAGS) src/error.c -o Objects/error.o

Objects/gdt.o:src/gdt.c
	$(COMPILER) $(CFLAGS) src/gdt.c -o Objects/gdt.o

Objects/idt.o:src/idt.c
	$(COMPILER) $(CFLAGS) src/idt.c -o Objects/idt.o

Objects/irq.o:src/irq.c
	$(COMPILER) $(CFLAGS) src/irq.c -o Objects/irq.o

Objects/isr.o:src/isr.c
	$(COMPILER) $(CFLAGS) src/isr.c -o Objects/isr.o

Objects/keyboard.o:src/keyboard.c
	$(COMPILER) $(CFLAGS) src/keyboard.c -o Objects/keyboard.o

Objects/screencontroller.o:src/screencontroller.c
	$(COMPILER) $(CFLAGS) src/screencontroller.c -o Objects/screencontroller.o

Objects/timer.o:src/timer.c
	$(COMPILER) $(CFLAGS) src/timer.c -o Objects/timer.o

Objects/vga.o:src/vga.c
	$(COMPILER) $(CFLAGS) src/vga.c -o Objects/vga.o

Objects/shell.o:src/shell.c
	$(COMPILER) $(CFLAGS) src/shell.c -o Objects/shell.o

Objects/functions.o:src/functions.c
	$(COMPILER) $(CFLAGS) src/functions.c -o Objects/functions.o

build:all
	rm os/boot/grub/ -r -f
	mkdir os/boot/grub/
	echo set default=0 >> os/boot/grub/grub.cfg
	echo set timeout=0 >> os/boot/grub/grub.cfg
	echo menuentry "os" { >> os/boot/grub/grub.cfg
	echo         set root='(hd96)' >> os/boot/grub/grub.cfg
	echo         multiboot /boot/kernel.bin >> os/boot/grub/grub.cfg
	echo } >> os/boot/grub/grub.cfg
	grub-mkrescue -o os.iso os/

clear:
	rm -f Objects/*.o
	rm -r -f os/
