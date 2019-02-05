-- Includes
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity motor_management is

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

end entity motor_management;

architecture behaviour of motor_management is

	type states is (waiting, driver_startup, enabled_on, enabled_off, driver_brake, driver_enable, finished);
	signal current_state: states;

begin

	-- Logic to advance to the next state
	process (clk, reset)
	
	-- Counters for in process
	variable counter_timer: integer;
	variable counter_step: integer;
	variable counter_reset: integer;
	variable counter_startup: integer;
	variable counter_brake: integer;
	variable counter_enable: integer;
	
	begin
	
		if reset = '1' then
			
			-- Reset, counters to zero, state becoms waiting
			current_state <= waiting;
			counter_step := 0;
			counter_timer := 0;
			counter_reset := 0;
			counter_startup := 0;
			counter_brake := 0;
			counter_enable := 0;
			
		elsif (rising_edge(clk)) then
		
			case current_state is
			
				when waiting=>
				
					-- When motor is enabled, go to next state
					if enable_motor_management = '1' then
						current_state <= driver_startup;
					else
						current_state <= waiting;
					end if;
					
				when driver_startup =>
				
					-- Give some time to startup driver
					if counter_startup >= (startup_ticks - 1) then
					
						-- Go to enable
						counter_startup := 0;
						current_state <= enabled_off;
					
					else
					
						-- Count
						counter_startup := counter_startup + 1;
						current_state <= driver_startup;	
						
					end if;
					
					
				when enabled_on=>		
				
					-- Wait till ...
					if counter_timer >= (step_time - 1) then
	
						-- Reset counter
						counter_timer := 0;
						
						if counter_step >= (steps - 1) then
							
							-- Step is finished, brake driver
							counter_step := 0;
							current_state <= driver_brake;
							
						else
							
							-- Next step, step is low
							counter_step := counter_step + 1;	
							current_state <= enabled_off;
							
						end if;
						
					else
						
						-- Count
						counter_timer := counter_timer + 1;
						current_state <= enabled_on;
						
					end if;
					
				when enabled_off =>
				
					-- Wait till ...
					if counter_timer >= (step_time - 1) then
					
						-- Reset timer
						counter_timer := 0;
						current_state <= enabled_on;
					
					else
					
						-- Count
						counter_timer := counter_timer + 1;
						current_state <= enabled_off;
					end if;
					
				when driver_brake =>
					
					-- Give some time to brake driver
					if counter_brake >= (brake_ticks - 1) then
					
						-- Go to enable
						counter_brake := 0;
						current_state <= driver_enable;
					
					else
					
						-- Count
						counter_brake := counter_brake + 1;
						current_state <= driver_brake;	
						
					end if;
					
				when  driver_enable =>
					
					-- Give some time to enable driver
					if counter_enable >= (driver_enable_ticks - 1) then
					
						-- Go to enable
						counter_enable := 0;
						current_state <= finished;
					
					else
					
						-- Count
						counter_enable := counter_enable + 1;
						current_state <= driver_enable;	
						
					end if;
					
				when finished=>
					
					-- Wait three clock ticks, go waiting
					if counter_reset >= 2 then
					
						counter_reset := 0;
						current_state <= waiting;
						
					else
					
						counter_reset := counter_reset + 1;	
						current_state <= finished;
						
					end if;

			end case;
		end if;

	end process;

	-- Output depends solely on the current state
	process (current_state)
	begin
	
	case current_state is
		
		when waiting =>
			step <= '0';
			finish_motor_controller <= '0';
			dir <= '0';
			enable <= '0';
			
		when driver_startup =>
			step <= '0';
			finish_motor_controller <= '0';
			dir <= '0';
			enable <= '1';
				
		when enabled_on =>
			step <= '1';
			finish_motor_controller <= '0';
			dir <= dir_val;
			enable <= '1';
		
		when enabled_off =>
			step <= '0';
			finish_motor_controller <= '0';
			dir <= dir_val;
			enable <= '1';
			
		when driver_brake =>
			step <= '0';
			finish_motor_controller <= '0';
			dir <= '0';
			enable <= '1';
			
		when driver_enable =>
			step <= '0';
			finish_motor_controller <= '0';
			dir <= '0';
			enable <= '0';
		
				
		when finished =>
			step <= '0';
			finish_motor_controller <= '1';
			dir <= '0';
			enable <= '0';
				
		end case;

	end process;

end behaviour;
