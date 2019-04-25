dp        =: <:@] %~ [: <: ] ^ >:@[                  NB. Sum of factors of prime power
div       =: ([: */ +/"1@= dp ~.)@q:                 NB. Divisor funtion
rdiv      =: div - ]                                 NB. Restricted divisor function
abundants =: ( ( rdiv > ] ) # ] ) >:i.28123          NB. Abundant numbers
abu2      =: /:~ (<:&28123 # ] ) ~. , +/~ abundants  NB. integer that are sum of two abundant numbers
( +/ >:i.28123 ) - ( +/ abu2 )
