project_new example1 -overwrite

set_global_assignment -name FAMILY MAX10
set_global_assignment -name DEVICE 10M50DAF484C7G 

set_global_assignment -name BDF_FILE example1.bdf
set_global_assignment -name VERILOG_FILE ../verilog/clk_divider.v
set_global_assignment -name SDC_FILE example1.sdc

set_global_assignment -name TOP_LEVEL_ENTITY clk_divider
set_location_assignment -to clk PIN_AH10

#CLOCK
set_location_assignment PIN_P11 -to clk;

#LEDs
set_location_assignment PIN_C10  -to rst  ;
set_location_assignment PIN_A8  -to Q  ;

load_package flow
execute_flow -compile

project_close
