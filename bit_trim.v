module bit_trim(dataa,datab,result);
	input [31:0] dataa,datab;
	output [31:0] result;
	assign result = {dataa[31:24],datab[23:16],dataa[15:8],datab[7:0]};
	 
endmodule 