project_new example1 -overwrite

set_global_assignment -name FAMILY MAX10
set_global_assignment -name DEVICE 10M50DAF484C7G 

set_global_assignment -name BDF_FILE example1.bdf
set_global_assignment -name VERILOG_FILE ../verilog/test.v
set_global_assignment -name SDC_FILE example1.sdc

set_global_assignment -name TOP_LEVEL_ENTITY test
set_location_assignment -to clk PIN_AH10

#SWITCHES
set_location_assignment PIN_C10 -to c[0]   ;# SW[0]
set_location_assignment PIN_C11 -to c[1]   ;# SW[1]
set_location_assignment PIN_D12 -to c[2]   ;# SW[2]
set_location_assignment PIN_C12 -to c[3]   ;# SW[3]


#LEDs
set_location_assignment PIN_A8  -to f  ;# LED[0]

load_package flow
execute_flow -compile

project_close
