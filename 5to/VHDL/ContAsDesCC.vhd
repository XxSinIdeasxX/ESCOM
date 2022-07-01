library IEEE;
use IEEE.std_logic_1164.all;

entity ContAsDesCC is
	 port(
		 CLK : in STD_LOGIC;
		 E : in STD_LOGIC;
		 F : out STD_LOGIC_VECTOR(0 to 6)
	     );
end ContAsDesCC;							 

architecture ContAsDesCC of ContAsDesCC is
	signal Q : std_logic_vector(3 downto 0) := "0000";
	signal Ta, Tb, Tc, Dd : std_logic;

begin  
	
	Ta <= '1';
	Tb <= E xor Q(0);
	Tc <= ((not E) and Q(1) and Q(0)) or (E and (not Q(1)) and (not Q(0)));
	Dd <= '0';
	
	process (Q, CLK)
	begin
		case Q is
			when "0000" => F <= "1111110"; --0
			when "0001" => F <= "0110000"; --1
			when "0010" => F <= "1101101"; --2
			when "0011" => F <= "1111001"; --3
			when "0100" => F <= "0110011"; --4
			when "0101" => F <= "1011011"; --5
			when "0110" => F <= "1011111"; --6
			when "0111" => F <= "1110000"; --7
			when others => F <= "0000000"; --otros
		end case; 
		
		if CLK'event and CLK = '1' then
			
			Q(3) <= Dd;
					  
			if Ta = '1' then
				Q(0) <= not Q(0);
			end if;
			
			if Tb = '1' then
				Q(1) <= not Q(1);
			end if;
		
			if Tc = '1' then
				Q(2) <= not Q(2);
			end if;
			
		end if;	
	end process;
end ContAsDesCC;
