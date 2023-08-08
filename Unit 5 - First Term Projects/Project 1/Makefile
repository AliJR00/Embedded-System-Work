
CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -g -gdwarf-2
prjectname = finalfile
INC = -I .
SRC = $(wildcard *.c)
DES = $(SRC:.c=.o)
SRCS = $(wildcard *.s)
DESS = $(SRCS:.s=.o)

all:$(prjectname).hex
	@echo "all done"

%.o:%.c
	$(CC)gcc.exe -c $(CFLAGS) $(INC) $< -o $@

%.o:%.s
	$(CC)as.exe $(CFLAGS) $(INC) $< -o $@

$(prjectname).elf: $(DES) $(DESS)
	$(CC)ld.exe -T linker_script.ld $(DES) $(DESS) -o $@ -Map=mapfile.Map

$(prjectname).hex:$(prjectname).elf
	$(CC)objcopy.exe -O ihex $< $@

$(prjectname).bin:$(prjectname).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.o *.elf *.hex *.bin