library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity Dado is
	 port(
		 CLK : in STD_LOGIC;
		 S : in STD_LOGIC;
		 Disp : out STD_LOGIC_VECTOR(0 to 6)
	     );
end Dado;

architecture Dado of Dado is

type estado is (A, B, C, D, E, F);
signal state, nxt_state : estado;
signal salida : std_logic_vector(0 to 6);

signal conta : INTEGER range 0 to 100 := 0;
signal X : std_logic := '0';

begin
	
	process(CLK) -- Divisor de frecuencia
	begin
		if (CLK'event and CLK='1') then
			if conta < 100 then
				conta <= conta + 1;
			else 
				X <= not X;
				conta <= 0;
			end if;
		end if;
	end process;
	
	process(X) -- Lógica secuencial
	begin
		if (X'event and X = '1')then
			Disp <= salida;
			state <= nxt_state;
		end if;
	end process;
	
	process(state) -- Salida en cada estado
	begin
		if state = A then
			salida <= "1001111";
		elsif state = B then
			salida <= "0010010";
		elsif state = C then
			salida <= "0000110";
		elsif state = D then
			salida <= "1001100";
		elsif state = E then
			salida <= "0100100";
		elsif state = F then
			salida <= "0100000";
		end if;
	end process;
	
	process(state, S) -- Cambio de estado
	begin		   
		nxt_state <= state;
		case(state) is
			when A =>
			 if S = '1' then
				 nxt_state <= B;
			 end if;
			when B =>
			 if S = '1' then
				 nxt_state <= C;
			 end if;
			when C =>
			 if S = '1' then
				 nxt_state <= D;
			 end if;
			when D =>
			 if S = '1' then
				 nxt_state <= E;
			 end if;
			when E =>
			 if S = '1' then
				 nxt_state <= F;
			 end if;
			when F =>
			 if S = '1' then
				 nxt_state <= A;
			 end if;
		end case;
	end process;
end Dado;
