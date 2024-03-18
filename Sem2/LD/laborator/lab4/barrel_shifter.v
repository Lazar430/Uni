module barrel_shifter(input [3:0]a, input [1:0]selector, output [3:0]out)

  wire [3:0]mutex_l01;
  assign mutex_l01 = {1'b0, a[3], a[2], a[1]};

   wire [3:0]mutex_l1;
   wire [3:0] mutex_l11;
   assign mutex_l11 = {1'b0, 1'b0, mutex_l1[3], mutex_l1[2]};

   genvar     i;
   

   generate
      for(i = 0; i < 4; i = i + 1)
	begin: tag
	   mutex m1(.a(a[i]), .b(mutex_l01[i]), .selector(selector[0]), .out(mutex_l1[i]));
	   mutex m2(.a(mutex_l1[i]), .b(mutex_l11[i]), .selector(selector[1]), .out(out[i]));       
	end
   endgenerate
   
endmodule // barrel_shifter
