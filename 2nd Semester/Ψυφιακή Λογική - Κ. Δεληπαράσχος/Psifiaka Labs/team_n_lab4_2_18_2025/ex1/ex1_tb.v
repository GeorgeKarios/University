module ex1_tb();
wire S,C;
reg A,B;
ex1 dat(a,b,cin,cout,sum);
initial begin
	 A=0;B=0;
#10 A=0;B=1;
#10 A=1;B=0;
#10 A=1;B=1;
end
endmodule