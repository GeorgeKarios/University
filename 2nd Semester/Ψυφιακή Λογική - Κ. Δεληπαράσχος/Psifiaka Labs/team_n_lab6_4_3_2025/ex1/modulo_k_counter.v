module modulo_k_counter(clk, reset, Q);
	parameter N=8;
	parameter K=100;
	input clk,reset;      // Reset, clock input
	output reg [N-1:0] Q; // 3-bit output


always @(posedge clk or negedge reset)
	begin
		if (!reset)
			Q <= 0;
		else if (Q==(K-1))
			Q <= 0;
		else
			Q <= Q+1;
	end
endmodule