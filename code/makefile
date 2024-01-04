all : TEST0.hex clean 

LIB = .\lib
CC = sdcc

INCLUDE = .\include
SOURSE = .\sourse

LIBMEMBER = seg7.rel ds1302.rel bluetooth.rel IN14.rel



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
	rm *.lk
	rm *.map
	rm *.rel
	rm *.rst
	rm *.sym
	rm *.mem
	rm *.ihx
