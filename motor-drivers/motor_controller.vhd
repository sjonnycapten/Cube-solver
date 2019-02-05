-- Includes
library ieee;
use ieee.std_logic_1164.all;

entity motor_controller is

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

end entity motor_controller;


architecture behaviour of motor_controller is

	-- Different states
	type states is (waiting, enabled, finished);
	signal current_state: states;

begin

	-- State machine
	process (clk, reset)
	
		-- Variables to hold old value
		variable start_motor_remind: std_logic;
		
	begin
	
		-- Reset, state becomes waiting, old state of motor becomes 0
		if reset = '1' then
			
			current_state <= waiting;
			start_motor_remind := '0';
			
		elsif (rising_edge(clk)) then
		
			case current_state is
				when waiting=>
					
					-- If start_motor is changed, bit is toggled in register
					if start_motor /= start_motor_remind then
						start_motor_remind := start_motor;
						current_state <= enabled;
					else
						current_state <= waiting;
					end if;
					
				when enabled=>
				
					-- If moter is reset
					if finish_motor_controller = '1' then
						current_state <= finished;
					else
						current_state <= enabled;
					end if;
					
				when finished=>
					
					-- Go to first state
					current_state <= waiting;
					
			end case;
			
		end if;
		
	end process;

	-- Output depends solely on the current state
	process (current_state)
	begin
	
		case current_state is	
		
			when waiting =>
			
				-- Motor off, finish_motor doesn't change
				finish_motor <= '0';
				enable_motor_management <= '0';
					
			when enabled =>
			
				-- Motor on, finish_motor doesn't change
				finish_motor <= '1';
				enable_motor_management <= '1';
					
			when finished =>
			
				-- Motor off, finish_motor is toggled
				finish_motor <= '0';
				enable_motor_management <= '0';
					
		end case;
		
	end process;
	
end behaviour;
