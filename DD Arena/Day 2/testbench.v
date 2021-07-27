// Code your testbench here
module testbench;
  wire d, e;
  reg a, b, c;
  
  code1 M(d, e, a, b, c);
  initial 
  begin
    $dumpfile("testbench.vcd");
    $dumpvars(1);
    a = 1'b0; b = 1'b0; c = 1'b0;
    #100
    $display("%b %b", d, e);
    a = 1'b1; b = 1'b1; c = 1'b1;
    #100
    $display("%b %b", d, e);
    $finish();
  end
endmodule
