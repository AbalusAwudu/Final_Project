module punch_example (
	input logic [9:0] DrawX, DrawY,
	input logic vga_clk, blank,
	output logic [7:0] red, green, blue
);

logic [16:0] rom_address;
logic [3:0] rom_q;

logic [3:0] palette_red, palette_green, palette_blue;

assign rom_address = ((DrawX * 240) / 192) + (((DrawY * 320) / 192) * 240);

always_ff @ (posedge vga_clk) begin
	if(~blank || (DrawX <= 190) || (DrawX >= 372) || (DrawY <= 20) || (DrawY >= 352))
	begin 
		red <= 8'h0;
		green <= 8'h0;
		blue <=  8'h0;
	end else
	begin
		red <= palette_red;
		green <= palette_green;
		blue <= palette_blue;
	end
end

punch_rom punch_rom (
	.clock   (vga_clk),
	.address (rom_address),
	.q       (rom_q)
);

punch_palette punch_palette (
	.index (rom_q),
	.red   (palette_red),
	.green (palette_green),
	.blue  (palette_blue)
);

endmodule

