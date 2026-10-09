*version 9.1 4063028527
u 37
PM? 2
R? 3
V? 2
@libraries
@analysis
.DC 1 0 0 4 1 1
+ 0 0 PAN
+ 0 4 0.001
+ 0 5 7k
+ 0 6 70
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
pageloc 1 0 1692 
@status
n 0 124:09:20:22:03:39;1729451019 e 
s 0 124:09:20:22:04:25;1729451065 e 
c 124:09:20:22:41:37;1729453297
*page 1 0 970 720 iA
@ports
port 5 agnd 510 210 h
@parts
part 2 PARAM 610 130 h
a 0 a 0:13 0 0 0 hln 100 PKGREF=PM1
a 1 ap 0 0 10 -2 hcn 100 REFDES=PM1
a 0 u 13 0 0 20 hln 100 NAME1=PAN
a 0 u 13 0 50 22 hlb 100 VALUE1=200
part 4 r 590 190 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 u 13 0 15 45 hln 100 VALUE={PAN}
a 0 x 0:13 0 0 0 hln 100 PKGREF=PAN
a 0 xp 9 0 15 0 hln 100 REFDES=PAN
part 3 r 510 150 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=470
part 6 VDC 450 170 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=10
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
@conn
w 13
a 0 up 0:33 0 0 0 hln 100 V=
s 550 150 590 150 12
a 0 up 33 0 565 154 hct 100 V=
w 8
a 0 up 0:33 0 0 0 hln 100 V=
s 450 150 510 150 10
a 0 up 33 0 485 154 hct 100 V=
s 450 170 450 150 9
s 450 180 450 170 7
w 15
a 0 up 0:33 0 0 0 hln 100 V=
s 510 210 450 210 18
s 590 210 510 210 16
a 0 up 33 0 525 214 hct 100 V=
s 590 190 590 210 14
@junction
j 450 210
+ p 6 -
+ w 15
j 450 170
+ p 6 +
+ w 8
j 550 150
+ p 3 2
+ w 13
j 510 150
+ p 3 1
+ w 8
j 590 190
+ p 4 1
+ w 15
j 590 150
+ p 4 2
+ w 13
j 510 210
+ s 5
+ w 15
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
