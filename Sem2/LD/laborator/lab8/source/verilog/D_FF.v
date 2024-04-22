module D_FF(
    input clock, reset,
    input enable, D,
    output reg Q
);
   always @(posedge clock or negedge reset)
     if(reset == 0)
       Q <= 0;
     else if(enable == 1)
       Q <= D;
       
endmodule // D_FF
