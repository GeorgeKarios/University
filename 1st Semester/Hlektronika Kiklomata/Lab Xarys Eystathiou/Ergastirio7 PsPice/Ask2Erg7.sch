*version 9.1 3140020327
u 39
PM? 2
R? 6
V? 2
@libraries
@analysis
.DC 1 0 0 4 1 1
+ 0 0 R
+ 0 4 0.001
+ 0 5 300
+ 0 6 10
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
pageloc 1 0 2616 
@status
n 0 124:09:21:14:40:36;1729510836 e 
s 2832 124:09:21:14:40:37;1729510837 e 
*page 1 0 970 720 iA
@ports
port 9 agnd 330 250 h
@parts
part 8 VDC 270 200 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=180v
part 5 r 290 180 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 25 hln 100 VALUE=5
part 3 r 340 140 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=25
part 4 r 400 180 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 25 hln 100 VALUE=10
part 6 r 470 250 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R4
a 0 ap 9 0 15 0 hln 100 REFDES=R4
a 0 u 13 0 15 25 hln 100 VALUE=8
part 7 r 370 240 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=RL
a 0 xp 9 0 15 0 hln 100 REFDES=RL
a 0 u 13 0 15 25 hln 100 VALUE={R}
part 2 PARAM 370 100 h
a 0 a 0:13 0 0 0 hln 100 PKGREF=PM1
a 1 ap 0 0 10 -2 hcn 100 REFDES=PM1
a 0 u 13 0 0 20 hln 100 NAME1=R
a 0 u 13 0 50 22 hlb 100 VALUE1=10k
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 11
s 270 200 270 180 10
s 270 140 340 140 12
s 270 180 270 140 25
s 270 180 290 180 23
w 15
s 380 140 470 140 14
s 470 140 470 180 16
s 470 180 470 210 32
s 440 180 470 180 30
w 27
s 330 180 370 180 28
s 370 180 400 180 35
s 370 180 370 200 33
w 19
s 470 250 370 250 18
s 330 250 270 250 20
s 270 250 270 240 21
s 370 250 330 250 38
s 370 240 370 250 36
@junction
j 270 200
+ p 8 +
+ w 11
j 340 140
+ p 3 1
+ w 11
j 380 140
+ p 3 2
+ w 15
j 470 210
+ p 6 2
+ w 15
j 470 250
+ p 6 1
+ w 19
j 330 250
+ s 9
+ w 19
j 270 240
+ p 8 -
+ w 19
j 290 180
+ p 5 1
+ w 11
j 270 180
+ w 11
+ w 11
j 330 180
+ p 5 2
+ w 27
j 400 180
+ p 4 1
+ w 27
j 440 180
+ p 4 2
+ w 15
j 470 180
+ w 15
+ w 15
j 370 180
+ w 27
+ w 27
j 370 250
+ w 19
+ w 19
j 370 200
+ p 7 2
+ w 27
j 370 240
+ p 7 1
+ w 19
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
