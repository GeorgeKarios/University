*version 9.1 555990641
u 38
V? 2
R? 5
@libraries
@analysis
.DC 1 0 0 0 1 1
+ 0 0 V1
+ 0 4 5
+ 0 5 15.1
+ 0 6 1
.SAVEBIAS 0 0 0 0 0
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
pageloc 1 0 2317 
@status
n 0 124:09:11:21:28:57;1728671337 e 
s 2832 124:09:11:21:29:01;1728671341 e 
*page 1 0 970 720 iA
@ports
port 7 agnd 420 330 h
@parts
part 3 r 390 240 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
part 4 r 510 310 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=2k
part 5 r 570 310 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 25 hln 100 VALUE=4k
part 6 r 630 310 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 15 25 hln 100 VALUE=3k
part 2 VDC 310 260 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=10
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 17
a 0 up 0:33 0 0 0 hln 100 V=
s 630 310 630 330 16
s 630 330 570 330 18
s 420 330 310 330 20
a 0 up 33 0 365 329 hct 100 V=
s 310 330 310 300 22
s 510 330 420 330 31
s 510 310 510 330 29
s 570 330 510 330 34
s 570 310 570 330 32
w 9
a 0 up 0:33 0 0 0 hln 100 V=
s 310 260 310 240 8
s 310 240 390 240 10
a 0 up 33 0 355 249 hct 100 V=
w 13
a 0 up 0:33 0 0 0 hln 100 V=
s 430 240 510 240 12
a 0 up 33 0 470 244 hct 100 V=
s 630 240 630 270 14
s 510 240 570 240 26
s 510 240 510 270 24
s 570 240 630 240 37
s 570 270 570 240 35
@junction
j 310 260
+ p 2 +
+ w 9
j 390 240
+ p 3 1
+ w 9
j 430 240
+ p 3 2
+ w 13
j 630 270
+ p 6 2
+ w 13
j 630 310
+ p 6 1
+ w 17
j 420 330
+ s 7
+ w 17
j 310 300
+ p 2 -
+ w 17
j 510 270
+ p 4 2
+ w 13
j 510 240
+ w 13
+ w 13
j 510 310
+ p 4 1
+ w 17
j 510 330
+ w 17
+ w 17
j 570 310
+ p 5 1
+ w 17
j 570 330
+ w 17
+ w 17
j 570 270
+ p 5 2
+ w 13
j 570 240
+ w 13
+ w 13
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
