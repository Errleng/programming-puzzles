module Lib
    ( someFunc
    ) where

import Control.Monad
import Data.Array
import Data.Time
import qualified Data.Map.Strict as MS

solve r c cats = cache ! (r, c)
  where
    bounds = ((0, 0), (r, c))
    coords = (,) <$> [0..r] <*> [0..c]
    cache = listArray bounds $ map calculate coords
    calculate (0, _) = 0
    calculate (_, 0) = 0
    calculate (1, 1) = 1
    calculate (a, b)
      | not ([a, b] `elem` cats) = cache ! (a-1, b) + cache ! (a, b-1)
      | otherwise = 0

someFunc :: IO ()
someFunc = do
  rc <- getLine
  k <- getLine

  let irc = map read $ words rc :: [Int]
  let ik = read k :: Int
  g <- replicateM ik getLine
  let ig = map (\a -> map read $ words a :: [Int]) g

  start <- getCurrentTime

  print $ solve (irc!!0) (irc!!1) ig

  end <- getCurrentTime

  print $ diffUTCTime end start
