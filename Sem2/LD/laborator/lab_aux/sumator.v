module sumator(input [3:0]a, b, input c_in, output [3:0]s, output c_out);
  wire c1;
  wire c2;
  wire c3;
  FAC f0(a[0], b[0], c_in, s[0], c1);
  FAC f1(a[1], b[1], c1, s[1], c2);
  FAC f2(a[2], b[2], c2, s[2], c3);
  FAC f3(a[3], b[3], c3, s[3], c_out);
endmodule // sumator
