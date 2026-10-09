module ex1(J,K,CLK,Q,q);

input J,K,CLK;
output reg Q;
output q;

always @(posedge CLK)
begin
	if(J==0 && K==0)
		Q<=Q; //idio
	else if(J==0 && K==1)
		Q<=0; //arnitiko
	else if(J==1 && K==0)
		Q<=1; //thetiko
	else
		Q<=!Q; //antistrofi
end
assign q =!Q;
endmodule