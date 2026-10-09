*version 9.1 774000937
u 35
R? 6
V? 2
@libraries
@analysis
.DC 1 0 0 0 1 1
+ 0 0 V1
+ 0 4 100
+ 0 5 200
+ 0 6 1
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
pageloc 1 0 2310 
@status
n 0 124:09:11:21:36:08;1728671768 e 
s 2832 124:09:11:21:36:12;1728671772 e 
*page 1 0 970 720 iA
@ports
port 2 agnd 370 530 h
@parts
part 4 r 270 480 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=5
part 6 r 350 430 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 25 hln 100 VALUE=25
part 8 r 350 530 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R5
a 0 ap 9 0 15 0 hln 100 REFDES=R5
a 0 u 13 0 15 25 hln 100 VALUE=70
part 5 r 430 480 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=10
part 7 r 500 530 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 15 25 hln 100 VALUE=8
part 31 VDC 270 490 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 -6 32 hcn 100 REFDES=V1
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 14
s 390 430 500 430 13
s 500 430 500 480 15
s 500 480 470 480 17
s 500 480 500 490 19
w 24
s 350 490 350 480 23
s 350 480 430 480 25
s 350 480 310 480 27
w 10
s 270 480 270 430 9
s 270 430 350 430 11
s 270 490 270 480 32
w 22
s 500 530 370 530 21
s 350 530 270 530 29
s 370 530 350 530 34
@junction
j 270 480
+ p 4 1
+ w 10
j 350 430
+ p 6 1
+ w 10
j 390 430
+ p 6 2
+ w 14
j 470 480
+ p 5 2
+ w 14
j 500 490
+ p 7 2
+ w 14
j 500 480
+ w 14
+ w 14
j 350 530
+ p 8 1
+ w 22
j 500 530
+ p 7 1
+ w 22
j 350 490
+ p 8 2
+ w 24
j 430 480
+ p 5 1
+ w 24
j 310 480
+ p 4 2
+ w 24
j 350 480
+ w 24
+ w 24
j 270 530
+ p 31 -
+ w 22
j 270 490
+ p 31 +
+ w 10
j 370 530
+ s 2
+ w 22
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
