`timescale 1ns / 1ps

module bit3_tb;
    reg clk, updown;
    wire QA, QB, QC;
    bit3 DUT (
        .updown(updown), 
        .CLKP(clk), 
        .QA(QA), 
        .QB(QB), 
        .QC(QC)
    );
    always #5 clk = ~clk;

    initial begin
        clk = 0;
        updown = 1;  
        
        #10 updown = 0;
        #10 updown = 1; 
        #10 $stop;
    end
endmodule
