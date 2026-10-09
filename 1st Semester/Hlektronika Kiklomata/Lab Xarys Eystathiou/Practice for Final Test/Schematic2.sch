*version 9.1 198380206
u 20
V? 2
R? 3
@libraries
@analysis
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 1522 
@status
n 0 124:10:25:01:35:21;1732491321 e 
s 0 124:10:25:01:35:21;1732491321 e 
*page 1 0 970 720 iA
@ports
port 5 agnd 490 310 h
@parts
part 2 VDC 410 230 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=2v
part 4 r 560 290 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=1k
part 3 r 560 240 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=330
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 7
a 0 up 0:33 0 0 0 hln 100 V=
s 410 230 560 230 6
a 0 up 33 0 485 229 hct 100 V=
s 560 230 560 240 8
w 11
a 0 up 0:33 0 0 0 hln 100 V=
s 600 240 600 290 10
a 0 up 33 0 602 265 hlt 100 V=
w 13
a 0 up 0:33 0 0 0 hln 100 V=
s 560 290 560 310 12
s 560 310 490 310 14
s 490 310 410 310 16
a 0 up 33 0 450 309 hct 100 V=
s 410 310 410 270 18
@junction
j 410 230
+ p 2 +
+ w 7
j 560 240
+ p 3 1
+ w 7
j 600 290
+ p 4 2
+ w 11
j 600 240
+ p 3 2
+ w 11
j 560 290
+ p 4 1
+ w 13
j 490 310
+ s 5
+ w 13
j 410 270
+ p 2 -
+ w 13
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
