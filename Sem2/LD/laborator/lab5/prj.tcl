project_new example1 -overwrite

set_global_assignment -name FAMILY MAX10
set_global_assignment -name DEVICE 10M50DAF484C7G 

set_global_assignment -name BDF_FILE example1.bdf
set_global_assignment -name VERILOG_FILE hex.v
set_global_assignment -name SDC_FILE example1.sdc

set_global_assignment -name TOP_LEVEL_ENTITY hex
set_location_assignment -to clk PIN_AH10

set_location_assignment PIN_F15 -to i[3]   ;
set_location_assignment PIN_B14 -to i[2]   ;
set_location_assignment PIN_A14 -to i[1]   ;
set_location_assignment PIN_A13 -to i[0]   ;

set_location_assignment PIN_C14  -to seg[6]  ;
set_location_assignment PIN_E15  -to seg[5]  ;
set_location_assignment PIN_C15  -to seg[4]  ;
set_location_assignment PIN_C16  -to seg[3]  ;
set_location_assignment PIN_E16  -to seg[2]  ;
set_location_assignment PIN_D17  -to seg[1]  ;
set_location_assignment PIN_C17  -to seg[0]  ;

load_package flow
execute_flow -compile

project_close
