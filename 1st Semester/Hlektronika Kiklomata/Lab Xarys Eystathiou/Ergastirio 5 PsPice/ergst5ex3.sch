*version 9.1 1250478072
u 54
R? 5
V? 2
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
pageloc 1 0 2364 
@status
n 0 124:09:02:14:56:12;1727870172 e 
s 0 124:09:02:16:47:44;1727876864 e 
*page 1 0 970 720 iA
@ports
port 7 agnd 510 240 h
@parts
part 2 r 370 140 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=10k
part 4 r 540 190 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 25 hln 100 VALUE=5k
part 5 r 650 190 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 15 25 hln 100 VALUE=3k
part 3 r 370 240 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=2k
part 6 VDC 330 180 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=20v
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
@conn
w 9
a 0 up 0:33 0 0 0 hln 100 V=
s 330 180 330 140 8
s 330 140 370 140 10
a 0 up 33 0 355 149 hct 100 V=
w 43
a 0 up 0:33 0 0 0 hln 100 V=
s 650 140 650 150 47
s 410 140 540 140 45
a 0 up 33 0 470 124 hct 100 V=
s 540 140 650 140 52
s 540 140 540 150 50
w 17
a 0 up 0:33 0 0 0 hln 100 V=
s 650 190 650 240 16
s 650 240 540 240 18
a 0 up 33 0 595 244 hct 100 V=
s 540 240 510 240 31
s 540 190 540 240 29
s 510 240 410 240 32
w 21
a 0 up 0:33 0 0 0 hln 100 V=
s 370 240 330 240 20
a 0 up 33 0 350 244 hct 100 V=
s 330 240 330 220 22
@junction
j 330 180
+ p 6 +
+ w 9
j 370 140
+ p 2 1
+ w 9
j 410 240
+ p 3 2
+ w 17
j 370 240
+ p 3 1
+ w 21
j 330 220
+ p 6 -
+ w 21
j 540 240
+ w 17
+ w 17
j 510 240
+ s 7
+ w 17
j 650 190
+ p 5 1
+ w 17
j 650 150
+ p 5 2
+ w 43
j 540 190
+ p 4 1
+ w 17
j 410 140
+ p 2 2
+ w 43
j 540 150
+ p 4 2
+ w 43
j 540 140
+ w 43
+ w 43
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
t 53 t 6 500 110 600 130 0 26
karyos Georgios - askisi 3
