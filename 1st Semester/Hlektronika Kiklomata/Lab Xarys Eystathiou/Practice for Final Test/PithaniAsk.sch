*version 9.1 266969048
u 42
R? 6
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
pageloc 1 0 2604 
@status
n 0 124:10:25:13:07:29;1732532849 e 
s 0 124:10:25:13:07:33;1732532853 e 
c 124:10:25:13:08:05;1732532885
*page 1 0 970 720 iA
@ports
port 7 agnd 330 270 h
@parts
part 8 VDC 270 230 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=10v
part 4 r 420 260 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 25 35 hln 100 VALUE=600
part 5 r 360 260 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 15 25 hln 100 VALUE=750
part 6 r 340 170 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=900
a 0 xp 9 0 15 0 hln 100 REFDES=900
part 2 r 300 200 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=500
part 3 r 370 200 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 u 13 0 15 25 hln 100 VALUE=800
a 0 ap 9 0 35 5 hln 100 REFDES=R2
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 10
s 330 270 360 270 9
s 360 270 360 260 11
s 360 270 420 270 13
s 420 270 420 260 15
s 330 270 270 270 34
w 18
a 0 up 0:33 0 0 0 hln 100 V=
s 380 170 420 170 17
a 0 up 33 0 440 159 hct 100 V=
s 420 170 420 200 19
s 420 200 420 220 23
s 410 200 420 200 21
w 27
a 0 up 0:33 0 0 0 hln 100 V=
s 300 200 270 200 26
s 270 200 270 230 28
s 270 200 270 170 30
s 270 170 340 170 32
a 0 up 33 0 265 154 hct 100 V=
w 25
a 0 up 0:33 0 0 0 hln 100 V=
s 370 200 360 200 24
s 360 200 340 200 38
s 360 200 360 220 36
a 0 up 33 0 377 220 hlt 100 V=
@junction
j 330 270
+ s 7
+ w 10
j 360 260
+ p 5 1
+ w 10
j 360 270
+ w 10
+ w 10
j 410 200
+ p 3 2
+ w 18
j 420 200
+ w 18
+ w 18
j 340 200
+ p 2 2
+ w 25
j 370 200
+ p 3 1
+ w 25
j 270 270
+ p 8 -
+ w 10
j 360 220
+ p 5 2
+ w 25
j 360 200
+ w 25
+ w 25
j 420 260
+ p 4 1
+ w 10
j 420 220
+ p 4 2
+ w 18
j 380 170
+ p 6 2
+ w 18
j 340 170
+ p 6 1
+ w 27
j 300 200
+ p 2 1
+ w 27
j 270 230
+ p 8 +
+ w 27
j 270 200
+ w 27
+ w 27
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
