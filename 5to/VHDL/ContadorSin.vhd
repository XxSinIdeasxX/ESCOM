library IEEE;
use IEEE.std_logic_1164.all;

entity ContadorSin is
	 port(
	 	 CLK : in STD_LOGIC;
		 F : out STD_LOGIC_VECTOR(2 downto 0)
	     );
end ContadorSin;

architecture CuentaS of ContadorSin is
	signal Q0, Q1, Q2 : std_logic := '0';
	signal Ta : std_logic;  
	signal Tb : std_logic;
	signal Tc : std_logic;
	
	begin
	
		F(0) <= Q0;
		F(1) <= Q1;
		F(2) <= Q2;
		   
		Tc <= (Q0 or Q1 or Q2) and ((not Q0) or (not Q1) or (not Q2));
		Tb <= Q0;
		Ta <= (Q0 or Q1 or (not Q2)) and ((not Q0) or (not Q1) or Q2);
		
	process (CLK)
	begin
		if CLK'event and CLK = '1' then
			if Ta = '1' then
				Q0 <= not Q0;
			end if;		  
			
			if Tb = '1' then
				Q1 <= not Q1;
			end if;	  
			
			if Tc = '1' then
				Q2 <= not Q2;
			end if;
		end if;
	end process;
end CuentaS;
