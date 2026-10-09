module ex1(A,B,S,C);
input A,B;
output S,C;
wire tmp1, tmp2,tmp3;
nand inst1(tmp1, A, B);
nand inst2(tmp2,A ,tmp1);
nand inst3(tmp3, B,tmp1);
nand inst4(S, tmp3, tmp2);
nand inst5(C, tmp1,tmp1);
endmodule