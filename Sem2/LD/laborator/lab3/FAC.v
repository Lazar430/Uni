module FAC(input a, b, c_in, output s, c_out);
   assign s = a ^ b ^ c_in;
   assign c_out = (a & b) | (b & c_in) | (c_in & a);
endmodule
