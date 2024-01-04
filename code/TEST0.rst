                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.3.0 #14184 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module TEST0
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _Serialflush
                                     13 	.globl _Serialprint
                                     14 	.globl _Serialbegin_value
                                     15 	.globl _IN14_init
                                     16 	.globl _CY
                                     17 	.globl _AC
                                     18 	.globl _F0
                                     19 	.globl _RS1
                                     20 	.globl _RS0
                                     21 	.globl _OV
                                     22 	.globl _F1
                                     23 	.globl _P
                                     24 	.globl _PS
                                     25 	.globl _PT1
                                     26 	.globl _PX1
                                     27 	.globl _PT0
                                     28 	.globl _PX0
                                     29 	.globl _RD
                                     30 	.globl _WR
                                     31 	.globl _T1
                                     32 	.globl _T0
                                     33 	.globl _INT1
                                     34 	.globl _INT0
                                     35 	.globl _TXD
                                     36 	.globl _RXD
                                     37 	.globl _P3_7
                                     38 	.globl _P3_6
                                     39 	.globl _P3_5
                                     40 	.globl _P3_4
                                     41 	.globl _P3_3
                                     42 	.globl _P3_2
                                     43 	.globl _P3_1
                                     44 	.globl _P3_0
                                     45 	.globl _EA
                                     46 	.globl _ES
                                     47 	.globl _ET1
                                     48 	.globl _EX1
                                     49 	.globl _ET0
                                     50 	.globl _EX0
                                     51 	.globl _P2_7
                                     52 	.globl _P2_6
                                     53 	.globl _P2_5
                                     54 	.globl _P2_4
                                     55 	.globl _P2_3
                                     56 	.globl _P2_2
                                     57 	.globl _P2_1
                                     58 	.globl _P2_0
                                     59 	.globl _SM0
                                     60 	.globl _SM1
                                     61 	.globl _SM2
                                     62 	.globl _REN
                                     63 	.globl _TB8
                                     64 	.globl _RB8
                                     65 	.globl _TI
                                     66 	.globl _RI
                                     67 	.globl _P1_7
                                     68 	.globl _P1_6
                                     69 	.globl _P1_5
                                     70 	.globl _P1_4
                                     71 	.globl _P1_3
                                     72 	.globl _P1_2
                                     73 	.globl _P1_1
                                     74 	.globl _P1_0
                                     75 	.globl _TF1
                                     76 	.globl _TR1
                                     77 	.globl _TF0
                                     78 	.globl _TR0
                                     79 	.globl _IE1
                                     80 	.globl _IT1
                                     81 	.globl _IE0
                                     82 	.globl _IT0
                                     83 	.globl _P0_7
                                     84 	.globl _P0_6
                                     85 	.globl _P0_5
                                     86 	.globl _P0_4
                                     87 	.globl _P0_3
                                     88 	.globl _P0_2
                                     89 	.globl _P0_1
                                     90 	.globl _P0_0
                                     91 	.globl _B
                                     92 	.globl _ACC
                                     93 	.globl _PSW
                                     94 	.globl _IP
                                     95 	.globl _P3
                                     96 	.globl _IE
                                     97 	.globl _P2
                                     98 	.globl _SBUF
                                     99 	.globl _SCON
                                    100 	.globl _P1
                                    101 	.globl _TH1
                                    102 	.globl _TH0
                                    103 	.globl _TL1
                                    104 	.globl _TL0
                                    105 	.globl _TMOD
                                    106 	.globl _TCON
                                    107 	.globl _PCON
                                    108 	.globl _DPH
                                    109 	.globl _DPL
                                    110 	.globl _SP
                                    111 	.globl _P0
                                    112 ;--------------------------------------------------------
                                    113 ; special function registers
                                    114 ;--------------------------------------------------------
                                    115 	.area RSEG    (ABS,DATA)
      000000                        116 	.org 0x0000
                           000080   117 _P0	=	0x0080
                           000081   118 _SP	=	0x0081
                           000082   119 _DPL	=	0x0082
                           000083   120 _DPH	=	0x0083
                           000087   121 _PCON	=	0x0087
                           000088   122 _TCON	=	0x0088
                           000089   123 _TMOD	=	0x0089
                           00008A   124 _TL0	=	0x008a
                           00008B   125 _TL1	=	0x008b
                           00008C   126 _TH0	=	0x008c
                           00008D   127 _TH1	=	0x008d
                           000090   128 _P1	=	0x0090
                           000098   129 _SCON	=	0x0098
                           000099   130 _SBUF	=	0x0099
                           0000A0   131 _P2	=	0x00a0
                           0000A8   132 _IE	=	0x00a8
                           0000B0   133 _P3	=	0x00b0
                           0000B8   134 _IP	=	0x00b8
                           0000D0   135 _PSW	=	0x00d0
                           0000E0   136 _ACC	=	0x00e0
                           0000F0   137 _B	=	0x00f0
                                    138 ;--------------------------------------------------------
                                    139 ; special function bits
                                    140 ;--------------------------------------------------------
                                    141 	.area RSEG    (ABS,DATA)
      000000                        142 	.org 0x0000
                           000080   143 _P0_0	=	0x0080
                           000081   144 _P0_1	=	0x0081
                           000082   145 _P0_2	=	0x0082
                           000083   146 _P0_3	=	0x0083
                           000084   147 _P0_4	=	0x0084
                           000085   148 _P0_5	=	0x0085
                           000086   149 _P0_6	=	0x0086
                           000087   150 _P0_7	=	0x0087
                           000088   151 _IT0	=	0x0088
                           000089   152 _IE0	=	0x0089
                           00008A   153 _IT1	=	0x008a
                           00008B   154 _IE1	=	0x008b
                           00008C   155 _TR0	=	0x008c
                           00008D   156 _TF0	=	0x008d
                           00008E   157 _TR1	=	0x008e
                           00008F   158 _TF1	=	0x008f
                           000090   159 _P1_0	=	0x0090
                           000091   160 _P1_1	=	0x0091
                           000092   161 _P1_2	=	0x0092
                           000093   162 _P1_3	=	0x0093
                           000094   163 _P1_4	=	0x0094
                           000095   164 _P1_5	=	0x0095
                           000096   165 _P1_6	=	0x0096
                           000097   166 _P1_7	=	0x0097
                           000098   167 _RI	=	0x0098
                           000099   168 _TI	=	0x0099
                           00009A   169 _RB8	=	0x009a
                           00009B   170 _TB8	=	0x009b
                           00009C   171 _REN	=	0x009c
                           00009D   172 _SM2	=	0x009d
                           00009E   173 _SM1	=	0x009e
                           00009F   174 _SM0	=	0x009f
                           0000A0   175 _P2_0	=	0x00a0
                           0000A1   176 _P2_1	=	0x00a1
                           0000A2   177 _P2_2	=	0x00a2
                           0000A3   178 _P2_3	=	0x00a3
                           0000A4   179 _P2_4	=	0x00a4
                           0000A5   180 _P2_5	=	0x00a5
                           0000A6   181 _P2_6	=	0x00a6
                           0000A7   182 _P2_7	=	0x00a7
                           0000A8   183 _EX0	=	0x00a8
                           0000A9   184 _ET0	=	0x00a9
                           0000AA   185 _EX1	=	0x00aa
                           0000AB   186 _ET1	=	0x00ab
                           0000AC   187 _ES	=	0x00ac
                           0000AF   188 _EA	=	0x00af
                           0000B0   189 _P3_0	=	0x00b0
                           0000B1   190 _P3_1	=	0x00b1
                           0000B2   191 _P3_2	=	0x00b2
                           0000B3   192 _P3_3	=	0x00b3
                           0000B4   193 _P3_4	=	0x00b4
                           0000B5   194 _P3_5	=	0x00b5
                           0000B6   195 _P3_6	=	0x00b6
                           0000B7   196 _P3_7	=	0x00b7
                           0000B0   197 _RXD	=	0x00b0
                           0000B1   198 _TXD	=	0x00b1
                           0000B2   199 _INT0	=	0x00b2
                           0000B3   200 _INT1	=	0x00b3
                           0000B4   201 _T0	=	0x00b4
                           0000B5   202 _T1	=	0x00b5
                           0000B6   203 _WR	=	0x00b6
                           0000B7   204 _RD	=	0x00b7
                           0000B8   205 _PX0	=	0x00b8
                           0000B9   206 _PT0	=	0x00b9
                           0000BA   207 _PX1	=	0x00ba
                           0000BB   208 _PT1	=	0x00bb
                           0000BC   209 _PS	=	0x00bc
                           0000D0   210 _P	=	0x00d0
                           0000D1   211 _F1	=	0x00d1
                           0000D2   212 _OV	=	0x00d2
                           0000D3   213 _RS0	=	0x00d3
                           0000D4   214 _RS1	=	0x00d4
                           0000D5   215 _F0	=	0x00d5
                           0000D6   216 _AC	=	0x00d6
                           0000D7   217 _CY	=	0x00d7
                                    218 ;--------------------------------------------------------
                                    219 ; overlayable register banks
                                    220 ;--------------------------------------------------------
                                    221 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        222 	.ds 8
                                    223 ;--------------------------------------------------------
                                    224 ; internal ram data
                                    225 ;--------------------------------------------------------
                                    226 	.area DSEG    (DATA)
                                    227 ;--------------------------------------------------------
                                    228 ; overlayable items in internal ram
                                    229 ;--------------------------------------------------------
                                    230 ;--------------------------------------------------------
                                    231 ; Stack segment in internal ram
                                    232 ;--------------------------------------------------------
                                    233 	.area SSEG
      000036                        234 __start__stack:
      000036                        235 	.ds	1
                                    236 
                                    237 ;--------------------------------------------------------
                                    238 ; indirectly addressable internal ram data
                                    239 ;--------------------------------------------------------
                                    240 	.area ISEG    (DATA)
                                    241 ;--------------------------------------------------------
                                    242 ; absolute internal ram data
                                    243 ;--------------------------------------------------------
                                    244 	.area IABS    (ABS,DATA)
                                    245 	.area IABS    (ABS,DATA)
                                    246 ;--------------------------------------------------------
                                    247 ; bit data
                                    248 ;--------------------------------------------------------
                                    249 	.area BSEG    (BIT)
                                    250 ;--------------------------------------------------------
                                    251 ; paged external ram data
                                    252 ;--------------------------------------------------------
                                    253 	.area PSEG    (PAG,XDATA)
                                    254 ;--------------------------------------------------------
                                    255 ; uninitialized external ram data
                                    256 ;--------------------------------------------------------
                                    257 	.area XSEG    (XDATA)
                                    258 ;--------------------------------------------------------
                                    259 ; absolute external ram data
                                    260 ;--------------------------------------------------------
                                    261 	.area XABS    (ABS,XDATA)
                                    262 ;--------------------------------------------------------
                                    263 ; initialized external ram data
                                    264 ;--------------------------------------------------------
                                    265 	.area XISEG   (XDATA)
                                    266 	.area HOME    (CODE)
                                    267 	.area GSINIT0 (CODE)
                                    268 	.area GSINIT1 (CODE)
                                    269 	.area GSINIT2 (CODE)
                                    270 	.area GSINIT3 (CODE)
                                    271 	.area GSINIT4 (CODE)
                                    272 	.area GSINIT5 (CODE)
                                    273 	.area GSINIT  (CODE)
                                    274 	.area GSFINAL (CODE)
                                    275 	.area CSEG    (CODE)
                                    276 ;--------------------------------------------------------
                                    277 ; interrupt vector
                                    278 ;--------------------------------------------------------
                                    279 	.area HOME    (CODE)
      000000                        280 __interrupt_vect:
      000000 02 00 29         [24]  281 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  282 	reti
      000004                        283 	.ds	7
      00000B 02 01 A4         [24]  284 	ljmp	_IN14_timer
      00000E                        285 	.ds	5
      000013 32               [24]  286 	reti
      000014                        287 	.ds	7
      00001B 32               [24]  288 	reti
      00001C                        289 	.ds	7
      000023 02 01 67         [24]  290 	ljmp	_uartISR
                                    291 ;--------------------------------------------------------
                                    292 ; global & static initialisations
                                    293 ;--------------------------------------------------------
                                    294 	.area HOME    (CODE)
                                    295 	.area GSINIT  (CODE)
                                    296 	.area GSFINAL (CODE)
                                    297 	.area GSINIT  (CODE)
                                    298 	.globl __sdcc_gsinit_startup
                                    299 	.globl __sdcc_program_startup
                                    300 	.globl __start__stack
                                    301 	.globl __mcs51_genXINIT
                                    302 	.globl __mcs51_genXRAMCLEAR
                                    303 	.globl __mcs51_genRAMCLEAR
                                    304 	.area GSFINAL (CODE)
      000085 02 00 26         [24]  305 	ljmp	__sdcc_program_startup
                                    306 ;--------------------------------------------------------
                                    307 ; Home
                                    308 ;--------------------------------------------------------
                                    309 	.area HOME    (CODE)
                                    310 	.area HOME    (CODE)
      000026                        311 __sdcc_program_startup:
      000026 02 00 88         [24]  312 	ljmp	_main
                                    313 ;	return from main will return to caller
                                    314 ;--------------------------------------------------------
                                    315 ; code
                                    316 ;--------------------------------------------------------
                                    317 	.area CSEG    (CODE)
                                    318 ;------------------------------------------------------------
                                    319 ;Allocation info for local variables in function 'main'
                                    320 ;------------------------------------------------------------
                                    321 ;num                       Allocated to registers r7 
                                    322 ;tube                      Allocated to registers r6 
                                    323 ;------------------------------------------------------------
                                    324 ;	TEST0.c:9: void main(){
                                    325 ;	-----------------------------------------
                                    326 ;	 function main
                                    327 ;	-----------------------------------------
      000088                        328 _main:
                           000007   329 	ar7 = 0x07
                           000006   330 	ar6 = 0x06
                           000005   331 	ar5 = 0x05
                           000004   332 	ar4 = 0x04
                           000003   333 	ar3 = 0x03
                           000002   334 	ar2 = 0x02
                           000001   335 	ar1 = 0x01
                           000000   336 	ar0 = 0x00
                                    337 ;	TEST0.c:10: IN14_init();
      000088 12 01 8F         [24]  338 	lcall	_IN14_init
                                    339 ;	TEST0.c:11: UART_start(FREQ,BAUD);
      00008B 75 82 FD         [24]  340 	mov	dpl,#0xfd
      00008E 12 01 03         [24]  341 	lcall	_Serialbegin_value
                                    342 ;	TEST0.c:12: Serialflush();  
      000091 12 01 50         [24]  343 	lcall	_Serialflush
                                    344 ;	TEST0.c:13: ES = 1;
                                    345 ;	assignBit
      000094 D2 AC            [12]  346 	setb	_ES
                                    347 ;	TEST0.c:14: EA = 1;
                                    348 ;	assignBit
      000096 D2 AF            [12]  349 	setb	_EA
                                    350 ;	TEST0.c:15: P0 = 0;
      000098 75 80 00         [24]  351 	mov	_P0,#0x00
                                    352 ;	TEST0.c:17: while(1){
      00009B                        353 00109$:
                                    354 ;	TEST0.c:19: if(uartNewLineFlag){
      00009B 30 00 FD         [24]  355 	jnb	_uartNewLineFlag,00109$
                                    356 ;	TEST0.c:20: ES = 0;
                                    357 ;	assignBit
      00009E C2 AC            [12]  358 	clr	_ES
                                    359 ;	TEST0.c:21: switch(uartReadBuffer[0]){
      0000A0 AF 22            [24]  360 	mov	r7,_uartReadBuffer
      0000A2 BF 41 02         [24]  361 	cjne	r7,#0x41,00134$
      0000A5 80 0A            [24]  362 	sjmp	00101$
      0000A7                        363 00134$:
      0000A7 BF 42 02         [24]  364 	cjne	r7,#0x42,00135$
      0000AA 80 10            [24]  365 	sjmp	00102$
      0000AC                        366 00135$:
                                    367 ;	TEST0.c:22: case 'A':
      0000AC BF 43 44         [24]  368 	cjne	r7,#0x43,00104$
      0000AF 80 1F            [24]  369 	sjmp	00103$
      0000B1                        370 00101$:
                                    371 ;	TEST0.c:23: Serialprint("hi");
      0000B1 90 02 B6         [24]  372 	mov	dptr,#___str_0
      0000B4 75 F0 80         [24]  373 	mov	b,#0x80
      0000B7 12 01 25         [24]  374 	lcall	_Serialprint
                                    375 ;	TEST0.c:24: break;
                                    376 ;	TEST0.c:25: case 'B':
      0000BA 80 40            [24]  377 	sjmp	00105$
      0000BC                        378 00102$:
                                    379 ;	TEST0.c:26: Serialprint("hi,");
      0000BC 90 02 B9         [24]  380 	mov	dptr,#___str_1
      0000BF 75 F0 80         [24]  381 	mov	b,#0x80
      0000C2 12 01 25         [24]  382 	lcall	_Serialprint
                                    383 ;	TEST0.c:27: Serialprint(uartReadBuffer+1);
      0000C5 90 00 23         [24]  384 	mov	dptr,#(_uartReadBuffer + 0x0001)
      0000C8 75 F0 40         [24]  385 	mov	b,#0x40
      0000CB 12 01 25         [24]  386 	lcall	_Serialprint
                                    387 ;	TEST0.c:28: break;
                                    388 ;	TEST0.c:29: case 'C':
      0000CE 80 2C            [24]  389 	sjmp	00105$
      0000D0                        390 00103$:
                                    391 ;	TEST0.c:30: unsigned char num = uartReadBuffer[2]-'0';
      0000D0 E5 24            [12]  392 	mov	a,(_uartReadBuffer + 0x0002)
      0000D2 24 D0            [12]  393 	add	a,#0xd0
      0000D4 FF               [12]  394 	mov	r7,a
                                    395 ;	TEST0.c:31: unsigned char tube = uartReadBuffer[1]-'0';
      0000D5 E5 23            [12]  396 	mov	a,(_uartReadBuffer + 0x0001)
      0000D7 24 D0            [12]  397 	add	a,#0xd0
      0000D9 FE               [12]  398 	mov	r6,a
                                    399 ;	TEST0.c:32: Serialprint("set");
      0000DA 90 02 BD         [24]  400 	mov	dptr,#___str_2
      0000DD 75 F0 80         [24]  401 	mov	b,#0x80
      0000E0 C0 07            [24]  402 	push	ar7
      0000E2 C0 06            [24]  403 	push	ar6
      0000E4 12 01 25         [24]  404 	lcall	_Serialprint
      0000E7 D0 06            [24]  405 	pop	ar6
      0000E9 D0 07            [24]  406 	pop	ar7
                                    407 ;	TEST0.c:33: IN14_show[tube] = num;
      0000EB EE               [12]  408 	mov	a,r6
      0000EC 24 2D            [12]  409 	add	a,#_IN14_show
      0000EE F8               [12]  410 	mov	r0,a
      0000EF A6 07            [24]  411 	mov	@r0,ar7
                                    412 ;	TEST0.c:34: break;
                                    413 ;	TEST0.c:35: default:
      0000F1 80 09            [24]  414 	sjmp	00105$
      0000F3                        415 00104$:
                                    416 ;	TEST0.c:36: Serialprint("El Psy congroo\n");
      0000F3 90 02 C1         [24]  417 	mov	dptr,#___str_3
      0000F6 75 F0 80         [24]  418 	mov	b,#0x80
      0000F9 12 01 25         [24]  419 	lcall	_Serialprint
                                    420 ;	TEST0.c:37: }
      0000FC                        421 00105$:
                                    422 ;	TEST0.c:38: Serialflush(); 
      0000FC 12 01 50         [24]  423 	lcall	_Serialflush
                                    424 ;	TEST0.c:39: ES = 1;
                                    425 ;	assignBit
      0000FF D2 AC            [12]  426 	setb	_ES
                                    427 ;	TEST0.c:42: } 
      000101 80 98            [24]  428 	sjmp	00109$
                                    429 	.area CSEG    (CODE)
                                    430 	.area CONST   (CODE)
                                    431 	.area CONST   (CODE)
      0002B6                        432 ___str_0:
      0002B6 68 69                  433 	.ascii "hi"
      0002B8 00                     434 	.db 0x00
                                    435 	.area CSEG    (CODE)
                                    436 	.area CONST   (CODE)
      0002B9                        437 ___str_1:
      0002B9 68 69 2C               438 	.ascii "hi,"
      0002BC 00                     439 	.db 0x00
                                    440 	.area CSEG    (CODE)
                                    441 	.area CONST   (CODE)
      0002BD                        442 ___str_2:
      0002BD 73 65 74               443 	.ascii "set"
      0002C0 00                     444 	.db 0x00
                                    445 	.area CSEG    (CODE)
                                    446 	.area CONST   (CODE)
      0002C1                        447 ___str_3:
      0002C1 45 6C 20 50 73 79 20   448 	.ascii "El Psy congroo"
             63 6F 6E 67 72 6F 6F
      0002CF 0A                     449 	.db 0x0a
      0002D0 00                     450 	.db 0x00
                                    451 	.area CSEG    (CODE)
                                    452 	.area XINIT   (CODE)
                                    453 	.area CABS    (ABS,CODE)
