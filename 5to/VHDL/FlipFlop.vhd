library IEEE;
use IEEE.std_logic_1164.all;

entity FlipFlop is
	 port(
		 CLK : in STD_LOGIC;
		 L1 : out STD_LOGIC;
		 L2 : out STD_LOGIC;
		 S : in STD_LOGIC
	     );
end FlipFlop;
	 
architecture FF_D of FlipFlop is  
    signal Q0, Q1 : std_logic;
begin
	
	L2 <= Q1;
	L1 <= Q0;
	
	process (CLK)
	begin
		if rising_edge (CLK) then
			
			Q1 <= Q0;
			Q0 <= S;
			
		end if;
	end process;	
end FF_D;
