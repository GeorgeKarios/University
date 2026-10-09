module accumulator_tb;
    reg clk, reset;
    reg [7:0] A;
    wire [7:0] Q;
    wire overflow;

    accumulator uut (
        .clk(clk),
        .reset(reset),
        .A(A),
        .Q(Q),
        .overflow(overflow)
    );

    always #5 clk = ~clk;  
    initial begin
        $dumpfile("accumulator.vcd");
        $dumpvars(0, accumulator_tb);

        clk = 0;
        reset = 1; A = 8'b00000000;
        #10 reset = 0;

        
        #10 A = 8'b00000011; 
        #10 A = 8'b00000101;  
        #10 A = 8'b00001111; 
        #10 A = 8'b11110000;  
        #10 $finish;
    end
endmodule
