module ex1acc (
    input clk, reset,
    input [7:0] A,
    output reg [7:0] Q,
    output reg overflow
);
    wire [7:0] sum;
    wire carry;

    ex1 #(8) adder8 (
        .A(Q),
        .B(A),
        .Cin(0),
        .S(sum),
        .Cout(carry)
    );

    always @(posedge clk or posedge reset) begin
        if (reset)
            Q <= 8'b0;
        else
            Q <= sum;
    end

    always @(posedge clk) begin
        overflow <= carry;
    end

endmodule
