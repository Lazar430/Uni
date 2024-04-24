`define IDLE 3'b000;
`define CR05 3'b001;
`define CR10 3'b010;
`define CR15 3'b011;
`define CR20 3'b100;
`define ESPRESSO 3'b101;
`define LONG_ESPRESSO 3'b110;
`define CAPUCINO 3'b111



module coffee(
	      input	   clk, rst
	      input	   CR05, CR10,
	      input [1:0]  sel,
	      output [2:0] state,
	      output [2:0] coffee_out
	      );
   reg [2:0]		   state_reg, state_next;
   reg [2:0]		   coffee_out_reg, coffee_out_next;

   //sequential
   always @(posedge clk or negedge rst)
     begin
	if(rst == 0)
	  begin
	     state_reg <= 0;
	     coffee_out_reg <= 0;
	  end
	else
	  begin
	     state_reg <= state_next;
	     coffee_out_reg <= coffee_out_next;	      
	  end
     end

   //combinational
   always @(state_reg, CR05, CR10, sel)
     begin
	state_next = state_reg;
	coffee_out_next = coffe_out_reg;

	case(state_reg)
	  `IDLE:
	    begin
	       if(CR05 == 1)
		 state_next = `CR05;
	       else if(CR10 == 1)
		 state_next = `CR10;
	    end

	 `CR05:
	    begin
	       if(CR05 == 1)
		 state_next = `CR10;
	       else if(CR10 == 1)
		 state_next = `CR15;
	    end

	  `CR010:
	    begin
	       if(CR05 == 1)
		 state_next = `CR15;
	       else if(CR10 == 1)
		 state_next = `CR20;
	    end

	  `CR015:
	    begin
	       if(CR05 == 1)
		 state_next = `CR20;
	       else if(CR10 == 1)
		 state_next = `CR20;
	    end

	  `CR20:
	    begin
	       if(select == 0)
		 state_next = `CR20;
	       else if(select == 1)
		 state_next = `ESPRESSO;
	       else if(select == 2)
		 state_next = `LONG_ESPRESSO;
	       else if(select == 3)
		 state_next = `CAPUCINO;
	    end // case: `CR20

	  `ESPRESSO:
	    begin
	       coffee_out_next = `ESPRESSO;
	       state_next = `IDLE;
	    end

	  `LONG_ESPRESSO:
	    begin
	       coffee_out_next = `LONG_ESPRESSO;
	       state_next = `IDLE;
	    end

	  `CAPUCINO:
	    begin
	       coffee_out_next = `CAPUCINO;
	       state_next = `IDLE;
	    end
	end // always @ (state_reg, CR05, CR10, sel)

   assign state = state_reg;
   assign coffee_out = coffee_out_reg;
   
endmodule // coffee

