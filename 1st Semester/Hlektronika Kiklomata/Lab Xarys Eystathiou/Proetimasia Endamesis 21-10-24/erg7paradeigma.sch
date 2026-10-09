*version 9.1 3573713003
u 30
V? 2
R? 3
PM? 2
@libraries
@analysis
.DC 1 0 0 4 1 1
+ 0 0 R
+ 0 4 0.0001
+ 0 5 7.1k
+ 0 6 65
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
pageloc 1 0 1709 
@status
n 0 124:09:21:14:11:24;1729509084 e 
s 2832 124:09:21:14:11:28;1729509088 e 
*page 1 0 970 720 iA
@ports
port 2 agnd 420 260 h
@parts
part 21 PARAM 350 170 h
a 0 a 0:13 0 0 0 hln 100 PKGREF=PM1
a 1 ap 0 0 10 -2 hcn 100 REFDES=PM1
a 0 u 13 0 50 22 hlb 100 VALUE1=10k
a 0 u 13 0 0 20 hln 100 NAME1=R
part 4 r 410 190 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=470
part 3 VDC 360 210 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 1 u 13 0 -11 18 hcn 100 DC=10v
a 0 x 0:13 0 0 0 hln 100 PKGREF=VF
a 1 xp 9 0 24 7 hcn 100 REFDES=VF
part 5 r 510 250 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=RF
a 0 xp 9 0 15 0 hln 100 REFDES=RF
a 0 u 13 0 15 35 hln 100 VALUE={R}
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 7
a 0 up 0:33 0 0 0 hln 100 V=
s 360 190 410 190 8
a 0 up 33 0 385 194 hct 100 V=
s 360 210 360 190 6
w 23
a 0 up 0:33 0 0 0 hln 100 V=
s 360 260 360 250 19
s 510 260 420 260 18
a 0 up 33 0 435 264 hct 100 V=
s 510 250 510 260 14
s 420 260 360 260 27
w 11
a 0 up 0:33 0 0 0 hln 100 V=
s 510 190 510 210 12
s 450 190 510 190 10
a 0 up 33 0 480 194 hct 100 V=
@junction
j 360 210
+ p 3 +
+ w 7
j 450 190
+ p 4 2
+ w 11
j 410 190
+ p 4 1
+ w 7
j 360 250
+ p 3 -
+ w 23
j 420 260
+ s 2
+ w 23
j 510 250
+ p 5 1
+ w 23
j 510 210
+ p 5 2
+ w 11
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
