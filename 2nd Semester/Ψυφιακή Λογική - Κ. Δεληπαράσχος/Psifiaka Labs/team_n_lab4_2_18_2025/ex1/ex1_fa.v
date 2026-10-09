module ex1_fa(A,B,Cin,S,C);
input A,B,Cin;
output S,C;
wire int1, int2,int3;
ex1 HA1(int1,int2,A,B);
ex1 HA2(S,int3,int1,Cin);
or ints1(C,int3,int2);
endmodule