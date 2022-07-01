module P2 where

-- Fernando Rodríguez Calderón
-- Práctica 2
-- Opción 1 y 3
-- 28 / Oct / 2021
-- Paradigmas de programación 3CM2 

serie :: Integer -> Integer -> Integer 
serie a 0 = 1
serie a n = a ^ n + serie a (n-1)

insertL ::Eq a => a -> a -> [a] -> [a]
insertL _ _ [] = []
insertL new old (x:xs) = if x == old then new:(x:xs) else x:insertL new old xs
