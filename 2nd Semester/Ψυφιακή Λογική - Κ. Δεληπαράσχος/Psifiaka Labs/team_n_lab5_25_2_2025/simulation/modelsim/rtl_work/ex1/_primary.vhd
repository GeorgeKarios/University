library verilog;
use verilog.vl_types.all;
entity ex1 is
    port(
        J               : in     vl_logic;
        K               : in     vl_logic;
        CLK             : in     vl_logic;
        \Q\             : out    vl_logic;
        q               : out    vl_logic
    );
end ex1;
