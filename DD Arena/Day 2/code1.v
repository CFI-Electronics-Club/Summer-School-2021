// Code your design here
module code1(D, E, A, B, C);
  output D, E;
  input A, B, C;
  
  assign D = (A & B) | (!C);
  assign E = (!C);
  
endmodule
