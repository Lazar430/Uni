module majority(input a, b, c, output f);
   assign f = (b & c) | (c & a) | (a & b);  
endmodule //majority

module parity(input a, b, c, output f);
   assign f = (~a & b & c) | (a & ~b & c) | (a & b & ~c) | (~a & ~b & ~c);
endmodule // parity

