
CC=arm-none-eabi-
CFLAGS= -gdwarf-2 -g
INC=-I .

SRC = $(wildcard *.c)
FIN = $(SRC:.c=.o)
SRCS = $(wildcard *.s)
FINS = $(SRCS:.s=.o)


all: finalfile.hex finalfile.bin
	@echo "done"


%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INC) $< -o $@

%.o: %.s
	$(CC)as.exe $(CFLAGS) $(INC) $< -o $@

finalfile.elf: $(FIN) $(FINS)
	$(CC)ld.exe -T linker_script.ld $(FIN) $(FINS) -o $@ -Map=map_file.map
	cp finalfile.elf finalfile.axf

finalfile.hex: finalfile.elf
	$(CC)objcopy.exe -O ihex $< $@

finalfile.bin: finalfile.elf
	$(CC)objcopy.exe -O binary $< $@


clean:
	rm *.elf *.o *.bin *.hex
