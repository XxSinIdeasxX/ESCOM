library IEEE;
use IEEE.std_logic_1164.all;

entity Contador is
	 port(
		 CLK : in STD_LOGIC;
		 A : out STD_LOGIC_VECTOR(2 downto 0);
		 D : out STD_LOGIC_VECTOR(2 downto 0)
	     );
end Contador;

architecture Cuenta of Contador is
	signal Q0, Q1, Q2 : std_logic := '0';

	begin
		
	A(2) <= Q2;
	A(1) <= Q1;
	A(0) <= Q0;
		
	D(2) <= not Q2;
	D(1) <= not Q1;
	D(0) <= not Q0;
		
	process	(CLK)
	begin
		if CLK'event and CLK = '1' then
			Q0 <= not Q0;
			
			if Q0 = '1' then
				Q1 <= not Q1;
				
				if Q1 = '1' then
					Q2 <= not Q2;
					
				end if;
			end if;
		end if;	
	end process;
end Cuenta;
