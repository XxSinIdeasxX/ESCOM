library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity MDE is
    Port ( F : out  STD_LOGIC_VECTOR (6 downto 0);
           C : out  STD_LOGIC_VECTOR (3 downto 0);
           CLK : in  STD_LOGIC);
end MDE;

architecture Behavioral of MDE is
signal ref : INTEGER range 0 to 100000;
signal X : std_logic_vector(3 downto 0) := (others => '0');
signal display : std_logic_vector(1 downto 0) := (others => '0');
begin

C <= X;

process(CLK)
	begin
	if (CLK'event and CLK='1')then
		if ref < 100000 then
			ref <= ref + 1;
		else 
			display <= display + 1;
			ref <= 0;
		end if;
	end if;
end process;

process (display)
	begin
		case (display) is
			when "00" => X <= "0111";
			when "01" => X <= "1011";
			when "10" => X <= "1101";
			when "11" => X <= "1110";
			when others => X <= "1111";
		end case;
	
		case (X) is
			when "1110" => F <= "1001000";
			when "1101" => F <= "0001000";
			when "1011" => F <= "1110001";
			when "0111" => F <= "0000001";
			when others => F <= "1111111";
		end case;
	end process;
end Behavioral;