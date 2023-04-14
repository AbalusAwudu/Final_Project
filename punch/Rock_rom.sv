module Rock_rom (
	input logic clock,
	input logic [15:0] address,
	output logic [3:0] q
);

logic [3:0] memory [0:65535] /* synthesis ram_init_file = "./Rock/Rock.mif" */;

always_ff @ (posedge clock) begin
	q <= memory[address];
end

endmodule
