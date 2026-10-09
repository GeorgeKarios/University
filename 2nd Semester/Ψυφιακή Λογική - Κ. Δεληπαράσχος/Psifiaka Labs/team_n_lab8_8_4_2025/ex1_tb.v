module ex1_tb;

reg clk;
reg reset_n;
reg w;
wire z;
wire [8:0] state;

ex1 uut (
    .clk(clk),
    .reset_n(reset_n),
    .w(w),
    .z(z),
    .state(state)
);
initial begin
    clk = 0;
    forever #5 clk = ~clk;
end

initial begin
    // Initialize inputs
    reset_n = 0;
    w = 0;
    
    // Reset the FSM
    #10;
    reset_n = 1;
    
    // Test sequence: 1,1,1,1 (should detect at 4th 1)
    #10 w = 1;
    #10 w = 1;
    #10 w = 1;
    #10 w = 1;
    #10 w = 0; // Should reset detection
    
    // Test sequence: 0,0,0,0 (should detect at 4th 0)
    #10 w = 0;
    #10 w = 0;
    #10 w = 0;
    #10 w = 0;
    #10 w = 1; // Should reset detection
    
    // Test overlapping sequences
    #10 w = 1;
    #10 w = 1;
    #10 w = 1;
    #10 w = 1;
    #10 w = 1; // Should keep z=1
    #10 w = 0;
    #10 $finish;
end

endmodule