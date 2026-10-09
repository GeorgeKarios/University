`timescale 1ns/1ps

module ex1acc_tb;
    reg clk, reset;
    reg [7:0] A;
    wire [7:0] Q;
    wire overflow;

    ex1acc uut (
        .clk(clk),
        .reset(reset),
        .A(A),
        .Q(Q),
        .overflow(overflow)
    );

    always #5 clk = ~clk;  // Ρολόι με περίοδο 10ns

    initial begin
        $dumpfile("accumulator.vcd");
        $dumpvars(0, accumulator_tb);

        clk = 0;
        reset = 1; A = 8'b00000000;
        #10 reset = 0;

        // Δοκιμή αθροίσεων
        #10 A = 8'b00000011;  // +3
        #10 A = 8'b00000101;  // +5
        #10 A = 8'b00001111;  // +15
        #10 A = 8'b11110000;  // +240 (προκαλεί υπερχείλιση)
        #10 $finish;
    end
endmodule
