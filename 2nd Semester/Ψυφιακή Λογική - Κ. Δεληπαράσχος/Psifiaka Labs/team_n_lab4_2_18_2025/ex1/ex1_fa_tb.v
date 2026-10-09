module ex1_fa_tb();
wire S,C;
reg A,B,Cin;
ex1 dat(A,B,Cin,S,C);
initial begin
	 A=0; B=0;Cin=0;
#10 A=0; B=0;Cin=1;
#10 A=0; B=1;Cin=0;
#10 A=0; B=1;Cin=1;
#10 A=1; B=0;Cin=0;
#10 A=1; B=0;Cin=1;
#10 A=1; B=1;Cin=0;
#10 A=1; B=1;Cin=1;
end
endmodule