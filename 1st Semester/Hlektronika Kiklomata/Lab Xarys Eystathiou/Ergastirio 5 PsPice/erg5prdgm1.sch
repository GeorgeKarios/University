*version 9.1 726443817
u 36
R? 3
V? 2
@libraries
@analysis
.DC 1 0 0 4 1 1
+ 0 0 R2
+ 0 4 0.1
+ 0 5 10
+ 0 6 1
.OP 1 
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
pageloc 1 0 1573 
@status
n 0 124:09:20:23:25:13;1729455913 e 
s 2832 124:09:20:23:26:07;1729455967 e 
*page 1 0 970 720 iA
@ports
port 2 agnd 310 210 h
@parts
part 5 VDC 250 120 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=5
part 3 r 320 80 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=2.2k
part 4 r 430 140 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 40 hln 100 VALUE=4.7k
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 15
a 0 up 0:33 0 0 0 hln 100 V=
s 430 140 430 210 14
s 430 210 310 210 16
a 0 up 33 0 330 214 hct 100 V=
s 310 210 250 210 21
s 250 210 250 160 23
w 7
a 0 up 0:33 0 0 0 hln 100 V=
s 250 120 250 80 6
s 250 80 320 80 8
a 0 up 33 0 295 84 hct 100 V=
w 11
a 0 up 0:33 0 0 0 hln 100 V=
s 360 80 430 80 10
a 0 up 33 0 415 64 hct 100 V=
s 430 80 430 100 12
@junction
j 360 80
+ p 3 2
+ w 11
j 430 100
+ p 4 2
+ w 11
j 250 120
+ p 5 +
+ w 7
j 250 160
+ p 5 -
+ w 15
j 320 80
+ p 3 1
+ w 7
j 430 140
+ p 4 1
+ w 15
j 310 210
+ s 2
+ w 15
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
t 25 t 5 330 136 374 150 0 9
Karyos G.
