*version 9.1 906796633
u 20
R? 3
V? 2
PM? 2
@libraries
@analysis
.DC 0 0 0 4 1 1
+ 0 0 RL
+ 0 4 0
+ 0 5 2001
+ 0 6 25
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
pageloc 1 0 1525 
@status
n 0 124:10:25:13:55:35;1732535735 e 
s 2832 124:10:25:13:55:39;1732535739 e 
*page 1 0 970 720 iA
@ports
port 4 agnd 500 340 h
@parts
part 2 r 480 290 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=470
part 5 VDC 440 300 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=10V
part 3 r 580 330 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=RL
a 0 xp 9 0 15 0 hln 100 REFDES=RL
a 0 u 13 0 20 35 hln 100 VALUE=1500
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 7
a 0 up 0:33 0 0 0 hln 100 V=
s 440 300 440 290 6
s 440 290 480 290 8
a 0 up 33 0 460 289 hct 100 V=
w 15
a 0 up 0:33 0 0 0 hln 100 V=
s 620 330 620 340 14
s 620 340 500 340 16
a 0 up 33 0 560 339 hct 100 V=
s 500 340 440 340 18
w 11
a 0 up 0:33 0 0 0 hln 100 V=
s 520 290 580 290 10
a 0 up 33 0 550 274 hct 100 V=
s 580 290 580 330 12
@junction
j 480 290
+ p 2 1
+ w 7
j 520 290
+ p 2 2
+ w 11
j 500 340
+ s 4
+ w 15
j 440 300
+ p 5 +
+ w 7
j 440 340
+ p 5 -
+ w 15
j 580 330
+ p 3 1
+ w 11
j 620 330
+ p 3 2
+ w 15
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
