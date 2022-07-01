library IEEE;
use IEEE.std_logic_1164.all;

entity ContadorSinCC is
	 port(
		 CLK : in STD_LOGIC;
		 D : in STD_LOGIC;
		 F : out STD_LOGIC_VECTOR(2 downto 0)
	     );
end ContadorSinCC;						   

architecture CuentaCC of ContadorSinCC is
  	signal Q0, Q1, Q2 : std_logic := '0';
	signal Da, Db, Dc : std_logic;

begin
	
	F(0) <= Q0;
	F(1) <= Q1;
	F(2) <= Q2;
	
	Da <= D;
	Db <= not Q1 and (Q0 xnor D);
	Dc <= (Q0 xnor D) and (Q1 xor Q2);
	
	process (CLK) 
	begin
		if CLK'event and CLK = '1' then
			Q0 <= Da;
			Q1 <= Db;
			Q2 <= Dc;
		end if;
	end process;
end CuentaCC;
