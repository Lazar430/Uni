module RCA(output c_out, output [1:0]s, input [1:0] a, b, input c_in);
   
   wire co, b0, b1;

   assign b0 = b[0] ^ 1;
   assign b1 = b[1] ^ 1;
   
   FAC F1(.s(s[0]), .a(a[0]), .b(b0), .c_out(co), .c_in(1));
   FAC F2(.s(s[1]), .a(a[1]), .b(b1), .c_out(c_out), .c_in(co));
   
endmodule

