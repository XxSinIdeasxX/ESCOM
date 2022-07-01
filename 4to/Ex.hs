funcX :: (Eq a) => a -> [a] -> [a] 
funcX a xs 0 foldl(\acu curr -> a*curr) 1 xs