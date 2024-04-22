module clk_divider(input clk, rst, output[24:0] Q);
   reg[24:0] Q_reg, Q_nxt;
   always @(posedge clk or negedge rst)
     begin
	if(rst == 0)
	  begin
	     Q_reg <= 0;
	  end
	else
	  begin
	     Q_reg <= Q_nxt;
	  end
     end // always @ (posedge clk or negedge rst)
   always @(Q_reg)
     begin
	Q_nxt = ~Q_reg;
     end
   assign Q = Q_reg;
endmodule // clk_divider

