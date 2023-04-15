module punch_rom (
	input logic clock,
	input logic [14:0] address,
	output logic [2:0] q
);

logic [2:0] memory [0:23111] /* synthesis ram_init_file = "./punch/punch.mif" */;

always_ff @ (posedge clock) begin
	q <= memory[address];
end

endmodule
