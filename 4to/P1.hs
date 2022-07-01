module P1 where

{- Fernando Rodríguez Calderón
Práctica 1. Funciones puras, de primer orden y de orden superior
Opción Haskell
12 / Oct / 2021
Paradigmas de programación 3CM2 -}

elemento :: [a] -> Integer -> a
elemento (x:xs) 1 = x
elemento (x:xs) n = elemento xs (n-1)

repetir :: (a -> a) -> Integer -> a -> a
repetir f 0 x = x
repetir f n x = f (repetir f (n-1) x)

potencia :: Integer -> Integer -> Integer
potencia x 0 = 1
potencia x n = repetir (x*) (n-1) x


