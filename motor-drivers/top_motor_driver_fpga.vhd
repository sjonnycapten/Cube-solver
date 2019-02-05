-- Includes
library ieee;
use ieee.std_logic_1164.all;

entity top_motor_driver_fpga is

	port(
	
		-- clock, reset
		clock_50: in std_logic;
		key: in std_logic_vector(3 downto 0);
		sw: in std_logic_vector(17 downto 0);
		gpio: out std_logic_vector(35 downto 0);
		ledg: out std_logic_vector(7 downto 0)
		
	);

end entity top_motor_driver_fpga;

architecture behaviour of top_motor_driver_fpga is

	 
	
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
			enable: out std_logic
		
		);
	
	end component motor_driver;

begin

	-- Generate 5 drivers
	drivers: for counter in 0 to 6 generate
	
		driver: motor_driver port map(
		
			clock_50, not key(0),
			sw(counter * 2),
			sw(counter * 2 + 1),
			ledg(counter),
			gpio(counter * 3),
			gpio(counter * 3 + 1),
			gpio(counter * 3 + 2)
			
		);
		
	end generate drivers;

end architecture behaviour;