import Data.List
import Data.IntSet (toList, fromList)

prob23 = sum [1..20161] - (sum $ nub' $ genSums abundants)
  where nub' = toList . fromList
        abundants = filter (\x -> x < sumProperDivisors x) [12..20149]
        genSums xs = [(x + y) | x <- xs, y <- xs, y >= x, (x + y) < 20162]
