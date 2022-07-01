library IEEE;
use IEEE.std_logic_1164.all;

entity Multiplexor is
  port(
       S : out STD_LOGIC;
       F1, F2, F3, F4 : in STD_LOGIC;
       C : in STD_LOGIC_VECTOR(1 downto 0)
  );
end Multiplexor;

architecture Mux of Multiplexor is
begin 
	S <= F1 when C = "00" else
		 F2 when C = "01" else
		 F3 when C = "10" else
		 F4 when C = "11";
end Mux;