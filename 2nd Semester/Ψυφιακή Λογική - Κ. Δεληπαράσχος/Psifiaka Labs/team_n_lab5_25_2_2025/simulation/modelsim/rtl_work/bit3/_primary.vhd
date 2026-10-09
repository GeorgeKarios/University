library verilog;
use verilog.vl_types.all;
entity bit3 is
    port(
        updown          : in     vl_logic;
        CLKP            : in     vl_logic;
        QA              : out    vl_logic;
        QB              : out    vl_logic;
        QC              : out    vl_logic
    );
end bit3;
