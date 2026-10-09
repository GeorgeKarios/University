module ex1_tb;
	reg J,K,CLK;
	wire Q,q;
	ex1 DUT(.J(J),.K(K),.CLK(CLK),.Q(Q),.q(q));
	initial begin 
			 CLK=0;
			 J=0;K=0;
		#10 J=0;K=1;
		#10 J=1;K=0;
		#10 J=1;K=1;
		#10 $stop; //stamata
		end
	always
		#5 CLK = !CLK;
endmodule