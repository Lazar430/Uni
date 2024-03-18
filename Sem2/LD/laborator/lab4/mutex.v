module mutex(input a, b, selector, output reg out);

   always @(a, b, selector)

     begin

	if(selector == 1)
	  out = b;
	else
	  out = a;
	
     end
   
endmodule // mutex
