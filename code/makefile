all : TEST0.hex clean 

LIB = .\lib
CC = sdcc

INCLUDE = .\include
SOURSE = .\sourse

LIBMEMBER = bluetooth.rel IN14.rel i2c.rel ds3231.rel



%.hex : %.ihx
	packihx $< > $@

%.ihx : %.c DM.lib 
	$(CC) $< -I $(INCLUDE) DM.lib

%.rel : ..\$(SOURSE)\%.c ..\$(INCLUDE)\%.h
	$(CC) -I$(INCLUDE) -c $< -o $@

DM.lib : $(addprefix $(LIB)\, $(LIBMEMBER))
	sdar -rc $@ $^
	sdranlib DM.lib

clean : 
	del *.lk
	del *.map
	del *.rel
	del *.rst
	del *.sym
	del *.mem
	del *.ihx
