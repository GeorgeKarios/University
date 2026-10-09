module modulo_k_counter_tb;
parameter N = 8;
parameter K = 100;

reg clk, reset;
wire [N-1:0] Q;

modulo_k_counter DUT (.clk(clk), .reset(reset), .Q(Q));

always #10 clk=!clk;

	initial begin
		clk   <=0;
		reset <=0;
		
		repeat(2) @ (posedge clk);
		reset <= 1;
		
		repeat(K) @ (posedge clk);
		$finish;
	end

endmodule