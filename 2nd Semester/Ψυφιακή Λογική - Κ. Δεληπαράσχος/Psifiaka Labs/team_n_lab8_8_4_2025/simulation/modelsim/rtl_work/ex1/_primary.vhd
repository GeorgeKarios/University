library verilog;
use verilog.vl_types.all;
entity ex1 is
    generic(
        State_A         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi1);
        State_B         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi1, Hi0);
        State_C         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi1, Hi0, Hi0);
        State_D         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi0, Hi0, Hi0, Hi1, Hi0, Hi0, Hi0);
        State_E         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi0, Hi0, Hi1, Hi0, Hi0, Hi0, Hi0);
        State_F         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi0, Hi1, Hi0, Hi0, Hi0, Hi0, Hi0);
        State_G         : vl_logic_vector(0 to 8) := (Hi0, Hi0, Hi1, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0);
        State_H         : vl_logic_vector(0 to 8) := (Hi0, Hi1, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0);
        State_I         : vl_logic_vector(0 to 8) := (Hi1, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0, Hi0)
    );
    port(
        clk             : in     vl_logic;
        reset_n         : in     vl_logic;
        w               : in     vl_logic;
        z               : out    vl_logic;
        state           : out    vl_logic_vector(8 downto 0)
    );
    attribute mti_svvh_generic_type : integer;
    attribute mti_svvh_generic_type of State_A : constant is 1;
    attribute mti_svvh_generic_type of State_B : constant is 1;
    attribute mti_svvh_generic_type of State_C : constant is 1;
    attribute mti_svvh_generic_type of State_D : constant is 1;
    attribute mti_svvh_generic_type of State_E : constant is 1;
    attribute mti_svvh_generic_type of State_F : constant is 1;
    attribute mti_svvh_generic_type of State_G : constant is 1;
    attribute mti_svvh_generic_type of State_H : constant is 1;
    attribute mti_svvh_generic_type of State_I : constant is 1;
end ex1;
