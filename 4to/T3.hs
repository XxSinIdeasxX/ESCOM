module T3 where

-- Fernando Rodríguez Calderón
-- Tarea 3
-- Opción 1 y 3
-- 3 / Nov / 2021
-- Paradigmas de programación 3CM2

rember :: Eq a =>  a -> [a] -> [a]
rember _ [] = []
rember a (x:xs) = if x == a then xs else x:rember a xs

dotProduct :: Num a => [a] -> [a] -> a
dotProduct l1 l2 = foldl1 (+) (zipWith (*) l1 l2)


