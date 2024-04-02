module compare(input[1:0]a, b, output ge, le);
   assign ge = (~b[1] & ~b[0]) | (a[1] & a[0]) | (a[1] & ~b[1]) | (a[0] & ~b[1]) | (a[1] & ~b[0]);
   assign le = (~a[1] & ~a[0]) | (b[1] & b[0]) | (~a[1] & b[0]) | (~a[1] & b[1]) | (~a[0] & b[1]);
endmodule // compare
  
