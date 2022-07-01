library IEEE;
use IEEE.std_logic_1164.all;

entity Deco4Bit is
	 port(
		 X : in STD_LOGIC_VECTOR(3 downto 0);
		 F : out STD_LOGIC_VECTOR(0 to 6)
	     );
end Deco4Bit;

architecture DecoBit of Deco4Bit is
begin
	process (X)
	begin
		case X is
			when "0000" => F <= "1111110"; -- 0
			when "0001" => F <= "0110000"; -- 1
			when "0010" => F <= "1101101"; -- 2
			when "0011" => F <= "1111001"; -- 3
			when "0100" => F <= "0110011"; -- 4
			when "0101" => F <= "1011011"; -- 5
			when "0110" => F <= "0011111"; -- 6
			when "0111" => F <= "1110000"; -- 7
			when "1000" => F <= "1111111"; -- 8
			when "1001" => F <= "1111011"; -- 9
			when "1010" => F <= "1110110"; -- A
			when "1011" => F <= "0011111"; -- b
			when "1100" => F <= "1001110"; -- C
			when "1101" => F <= "0111101"; -- d
			when "1110" => F <= "1001111"; -- E
			when "1111" => F <= "1000111"; -- F 
			when others => F <= "-------";
		end case;
	end process;
end DecoBit;



