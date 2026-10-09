*version 9.1 3363898025
u 66
R? 4
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
pageloc 1 0 2096 
@status
n 0 124:09:02:18:34:48;1727883288 e 
s 2832 124:09:02:18:34:52;1727883292 e 
*page 1 0 970 720 iA
@ports
port 43 agnd 420 290 h
@parts
part 3 r 320 180 h
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 15 25 hln 100 VALUE=2.2k
part 5 r 520 250 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R3
a 0 ap 9 0 15 0 hln 100 REFDES=R3
a 0 u 13 0 15 25 hln 100 VALUE=10k
part 4 r 420 250 v
a 0 sp 0 0 0 10 hlb 100 PART=r
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R2
a 0 ap 9 0 15 0 hln 100 REFDES=R2
a 0 u 13 0 15 30 hln 100 VALUE=4.7k
part 6 VDC 260 210 h
a 0 sp 0 0 22 37 hln 100 PART=VDC
a 0 a 0:13 0 0 0 hln 100 PKGREF=V1
a 1 ap 9 0 24 7 hcn 100 REFDES=V1
a 1 u 13 0 -11 18 hcn 100 DC=9v
part 1 titleblk 970 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 s 13 0 300 95 hrn 100 PAGENO=1
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
@conn
w 8
a 0 up 0:33 0 0 0 hln 100 V=
s 260 210 260 180 7
s 260 180 320 180 9
a 0 up 33 0 300 184 hct 100 V=
w 22
a 0 up 0:33 0 0 0 hln 100 V=
s 520 250 470 250 21
s 470 250 420 250 27
s 470 250 470 290 25
s 260 290 260 250 30
s 470 290 420 290 44
a 0 up 33 0 330 289 hct 100 V=
s 470 290 530 290 46
s 420 290 260 290 56
w 12
a 0 up 0:33 0 0 0 hln 100 V=
s 360 180 470 180 11
a 0 up 33 0 420 184 hct 100 V=
s 470 180 470 210 13
s 470 210 420 210 15
s 470 210 520 210 19
s 470 180 560 180 40
@junction
j 260 210
+ p 6 +
+ w 8
j 320 180
+ p 3 1
+ w 8
j 420 210
+ p 4 2
+ w 12
j 420 250
+ p 4 1
+ w 22
j 520 250
+ p 5 1
+ w 22
j 470 250
+ w 22
+ w 22
j 260 250
+ p 6 -
+ w 22
j 470 290
+ w 22
+ w 22
j 420 290
+ s 43
+ w 22
j 360 180
+ p 3 2
+ w 12
j 520 210
+ p 5 2
+ w 12
j 470 210
+ w 12
+ w 12
j 470 180
+ w 12
+ w 12
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
t 65 t 6 480 150 370 170 0 22
Karyos G. Ergastirio 5
