library verilog;
use verilog.vl_types.all;
entity modulo_k_counter is
    generic(
        N               : integer := 8;
        K               : integer := 100
    );
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        Q               : out    vl_logic_vector
    );
    attribute mti_svvh_generic_type : integer;
    attribute mti_svvh_generic_type of N : constant is 1;
    attribute mti_svvh_generic_type of K : constant is 1;
end modulo_k_counter;
