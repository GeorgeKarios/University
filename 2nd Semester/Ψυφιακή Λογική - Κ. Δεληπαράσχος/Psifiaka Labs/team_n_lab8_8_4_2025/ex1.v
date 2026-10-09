module ex1(
    input clk,          // Manual clock (KEY0)
    input reset_n,      // Active-low reset (SW0)
    input w,            // Input data (SW1)
    output reg z,       // Output (LEDG0)
    output [8:0] state  // State outputs (LEDR8-LEDR0)
);

// One-hot encoded state definitions
parameter State_A = 9'b000000001;
parameter State_B = 9'b000000010;
parameter State_C = 9'b000000100;
parameter State_D = 9'b000001000;
parameter State_E = 9'b000010000;
parameter State_F = 9'b000100000;
parameter State_G = 9'b001000000;
parameter State_H = 9'b010000000;
parameter State_I = 9'b100000000;

reg [8:0] current_state, next_state;

// State register (sequential logic)
always @(posedge clk or negedge reset_n) begin
    if (!reset_n)
        current_state <= State_A;
    else
        current_state <= next_state;
end

// Next state logic (combinational)
always @(*) begin
    case (current_state)
        State_A: next_state = (w == 1) ? State_B : State_F;
        State_B: next_state = (w == 1) ? State_C : State_A;
        State_C: next_state = (w == 1) ? State_D : State_A;
        State_D: next_state = (w == 1) ? State_E : State_A;
        State_E: next_state = (w == 1) ? State_E : State_A;
        State_F: next_state = (w == 0) ? State_G : State_A;
        State_G: next_state = (w == 0) ? State_H : State_A;
        State_H: next_state = (w == 0) ? State_I : State_A;
        State_I: next_state = (w == 0) ? State_I : State_A;
        default: next_state = State_A;
    endcase
end

// Output logic (combinational)
always @(*) begin
    z = (current_state == State_E) || (current_state == State_I);
end

// Assign state to output LEDs
assign state = current_state;

endmodule



