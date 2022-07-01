tabla :: (a->b)->[a]->[b]
tabla f[]=[]
tabla f(x:xs)=f x:map f xs

multi :: Integer -> [Integer]
multi 1 = tabla(1*)[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
multi n = multi(n-1)
