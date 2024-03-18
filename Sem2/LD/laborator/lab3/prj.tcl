project_new example1 -overwrite

set_global_assignment -name FAMILY MAX10
set_global_assignment -name DEVICE 10M50DAF484C7G 

set_global_assignment -name BDF_FILE example1.bdf
set_global_assignment -name VERILOG_FILE RCA.v
set_global_assignment -name SDC_FILE example1.sdc

set_global_assignment -name TOP_LEVEL_ENTITY RCA
set_location_assignment -to clk PIN_AH10

#SWITCHES
set_location_assignment PIN_C10  -to a[0];
set_location_assignment PIN_C11  -to a[1];
set_location_assignment PIN_D12  -to b[0];
set_location_assignment PIN_C12  -to b[1];

#LEDs
set_location_assignment PIN_A10  -to s[0];
set_location_assignment PIN_A9   -to s[1];
set_location_assignment PIN_A8   -to c_out;

load_package flow
execute_flow -compile

project_close
