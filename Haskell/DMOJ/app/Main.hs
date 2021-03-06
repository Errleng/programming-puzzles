module Main where

-- import Lib

import           Control.Monad
import           Data.Time
import qualified Data.Vector                   as DV

lnInt :: IO Int
lnInt = do
    a <- getLine
    return $ read a

nextIntLns :: Int -> IO [[Int]]
nextIntLns n = do
    a <- replicateM n getLine
    return $ map (\x -> let xsplit = words x in map read xsplit :: [Int]) a

type Vertex = Int

type WVertex = (Vertex, Int)

type Edge = (Vertex, Vertex, Int)

newtype Graph =
    Graph (DV.Vector [WVertex])
    deriving (Show)

type Bounds = (Vertex, Vertex)

--eds x = (map (\(a, b, c) -> (a, [(b, c)])) x) ++ (map (\(a, b, c) -> (b, [(a, c)])) x)
--buildGraph :: Bounds -> [Edge] -> Graph
--buildGraph b es = array b es
addEdge :: Graph -> Edge -> Graph
addEdge (Graph adj) (n1, n2, w) = Graph ((n1 , w) : (adj ! n2))
-- addEdge :: Edge -> Graph -> Graph
-- addEdge (n1, n2, w) (Graph adj) = Graph ([(n1, w) : (adj !! n2)] ++ [(n2, w) : (adj !! n1)])
-- addEdge (n1, n2, w) (Graph adj) = Graph ([(n1, w

-- addEdges :: [Edge] -> Graph -> Graph
-- addEdges [] g = g
-- addEdges (e:es) g = addEdge e (addEdges es g)

main :: IO ()
main = do
    start <- getCurrentTime
--    n <- lnInt
--    t <- lnInt
--    edges <- nextIntLns t
    let n      = 3
        t      = 3
        k      = 3
        d      = 1
        edges  = [(1, 2, 4), (2, 3, 2), (1, 3, 3)]
        prices = [(1, 14), (2, 8), (3, 3)]
        graph  = Graph (DV.replicate n [])
        gTest  = addEdge graph (1, 2, 1)
        -- g = addEdges [(1, 2, 1), (1, 1, 1)] graph
--        biEdges = eds edges
--        g = buildGraph (1, n) biEdges
--    print $ biEdges
--    print $ g
    print graph
    print gTest
    end <- getCurrentTime
    print $ diffUTCTime end start
