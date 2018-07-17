module Main where

import Text.Printf
import Control.Exception
import System.CPUTime

import Data.List
import Control.Monad

time :: IO t -> IO t
time a = do
    start <- getCPUTime
    v <- a
    end   <- getCPUTime
    let diff = (fromIntegral (end - start)) / (10^12)
    printf "Time: %0.3f sec\n" (diff :: Double)
    return v

naiveFib n
    | n <= 1 = n
    | otherwise = naiveFib (n-1) + naiveFib (n-2)

linearFib n = let fibs = 0:1:zipWith (+) fibs (tail fibs) in fibs!!n

data NestedList a = Elem a | List [NestedList a]

flattenNested :: NestedList a -> [a]
flattenNested (Elem a) = [a]
flattenNested (List []) = []
flattenNested (List (x:xs)) = flattenNested x ++ flattenNested (List xs)

compressConsecutives :: Eq a => [a] -> [a]
compressConsecutives (x:[]) = []
compressConsecutives (x:xs)
    | x == head xs = compressConsecutives xs
    | otherwise = x : compressConsecutives xs

packConsecutives :: Eq a => [a] -> [[a]]
packConsecutives [] = []
packConsecutives (x:xs) = (x : takeWhile (==x) xs) : packConsecutives (dropWhile (==x) xs)

-- encodeRunLength [] = []
-- encodeRunLength (x:xs) = (length $ x : takeWhile (==x) xs, x) : encodeRunLength (dropWhile (==x) xs)
encodeRunLength :: Eq a => [a] -> [(Int, a)]
encodeRunLength xs = map (\x -> (length x, head x)) (group' xs)
    where
        group' :: Eq a => [a] -> [[a]]
        group' [] = []
        group' (x:xs) = (x : takeWhile (==x) xs) : (group' $ dropWhile (==x) xs)

interactLine :: (String -> String) -> IO ()
interactLine f = loop
  where
    loop = do
      l <- getLine
      when (l /= "") $ putStrLn (f l) >> loop

main :: IO()
main = do
--     print $ flattenNested $ (List [Elem 1, List [Elem 2, List [Elem 3, Elem 4], Elem 5]])
--     print $ compressConsecutives $ "aaabccaadeeee"
--     print $ packConsecutives $ ['a', 'a', 'a', 'a', 'b', 'c', 'c', 'a', 'a', 'd', 'e', 'e', 'e', 'e']
--     print $ encodeRunLength $ "aaaabccaadeeee"
    interactLine $ show . sum . map read . words
