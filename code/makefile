all : Dmeta.hex lab1.hex seg.hex clean 

%.hex : %.c
	sdcc $<
	packihx $(basename $@).ihx > $@

clean : 
	rm *.ihx
	rm *.lk
	rm *.map
	rm *.rel
	rm *.rst
	rm *.sym
	rm *.mem
