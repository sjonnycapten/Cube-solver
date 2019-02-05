-- Includes
library ieee;
use ieee.std_logic_1164.all;

entity motor_driver is

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
	
end entity motor_driver;


architecture behaviour of motor_driver is
 
	component motor_management is

		generic (
	
			dir_val : std_logic;
			steps: integer;
			step_time: integer;
			startup_ticks: integer;
			brake_ticks: integer;
			driver_enable_ticks: integer
	
		);

		port(
	
			-- Clock, reset
			clk, reset: in	std_logic;
		
			-- Connection to motor_controller
			enable_motor_management: in std_logic;
			finish_motor_controller: out std_logic;
		
			-- Output
			step: out std_logic;
			dir: out std_logic;
			enable: out std_logic
		
		);

	end component motor_management;
	
	component motor_controller is

		port(
			-- Clock, reset
			clk, reset: in	std_logic;
		
			-- Connection with registers
			start_motor: in std_logic;
			finish_motor: out std_logic;
		
			-- Connection to motor management
			finish_motor_controller: in std_logic;
			enable_motor_management: out std_logic
			
		);

	end component motor_controller;
	
	-- Connection between and motor_controller
	signal enable_managment_left: std_logic;
	signal reset_controler_left: std_logic;
	signal enable_managment_right: std_logic;
	signal reset_controler_right: std_logic;
	
	-- Output signals
	signal step_output: std_logic_vector(1 downto 0);
	signal dir_output: std_logic_vector(1 downto 0);
	signal finish_motor_output: std_logic_vector(1 downto 0);
	signal enable_output: std_logic_vector(1 downto 0);

begin
	-- Generics:
	-- Real life: '1' / '0' , 50  , 25000, 500000, 500000, 500000
	-- Wafe form: '1' / '0' , < 10, < 10 , < 10 , < 10, < 10

	-- Left
	management_left: motor_management generic map('1', 50, 37500, 500000, 500000, 500000)port map(clk, reset, enable_managment_left, reset_controler_left, step_output(0), dir_output(0), enable_output(0));
	controler_left: motor_controller port map(clk, reset, start_motor_left, finish_motor_output(0), reset_controler_left, enable_managment_left);
	
	-- Left
	management_right: motor_management generic map('0', 50, 37500, 500000, 500000, 500000)port map(clk, reset, enable_managment_right, reset_controler_right, step_output(1), dir_output(1), enable_output(1));
	controler_right: motor_controller port map(clk, reset, start_motor_right, finish_motor_output(1), reset_controler_right, enable_managment_right);
	
	-- Output
	step <= step_output(0) or step_output(1);
	dir <= dir_output(0) or dir_output(1);
	finish_motor <= finish_motor_output(0) or finish_motor_output(1);
	enable <= not (enable_output(0) or enable_output(1));

end architecture behaviour;