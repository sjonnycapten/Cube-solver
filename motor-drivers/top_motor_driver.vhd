-- Includes
library ieee;
use ieee.std_logic_1164.all;

entity top_motor_driver is

	port(
	
		-- clock, reset
		clk, reset: in	std_logic;
		
		-- connection to registers
		motor_enable: in std_logic_vector(9 downto 0);
		motor_finish: out std_logic_vector(4 downto 0);
		
		-- Output
		motor_output: out std_logic_Vector(14 downto 0)
		
	);

end entity top_motor_driver;

architecture behaviour of top_motor_driver is

	component motor_driver is

		port(
	
			-- Clock, reset
			clk, reset: in	std_logic;
		
			-- To registers
			start_motor_left: in std_logic;
			start_motor_right: in std_logic;
			finish_motor: out std_logic;
		
			-- To output
			step: out std_logic;
			dir: out std_logic;
			sleep: out std_logic
		
		);
	
	end component motor_driver;

begin

	-- Generate 6 drivers
	drivers: for counter in 0 to 5 generate
	
		driver: motor_driver port map(
		
			clk, reset,
			motor_enable(counter * 2),
			motor_enable(counter * 2 + 1),
			motor_finish(counter),
			motor_output(counter * 3),
			motor_output(counter * 3 + 1),
			motor_output(counter * 3 + 2)
			
		);
		
	end generate drivers;

end architecture behaviour;