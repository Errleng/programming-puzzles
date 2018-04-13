#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <queue>

class Trapper
{
private:
    const int m_Size = 0;
    int m_Steps;
    const std::vector<std::vector<char> > m_MazeMatrix;
    std::vector<std::vector<bool> > m_VisitedMatrix;

    std::vector<std::vector<char> > m_ShowMaze;
public:
    Trapper();
    Trapper(std::vector<std::vector<char> > map) : m_Size(map.size()), m_Steps(0), m_MazeMatrix(map), m_ShowMaze(map)
    {for (int i = 0; i < this->m_Size; i++) {
        std::vector<bool> boolRow;
        for (int j = 0; j < this->m_Size; j++)
        {
            boolRow.push_back(false);
        }
        this->m_VisitedMatrix.push_back(boolRow);
    }}
    ~Trapper();

    void Print();
    void Print(std::vector<std::vector<char> > matrix);
    bool IsPath(int row, int col, bool visitedCheck);
    bool Navigate(int row, int col, bool checkVisited);
    void MapOut(int row, int col);
    void FindFood();

    void PrintPath(int row, int col, char c);
};

struct Node
{
public:
    const int data;
    std::tuple<int, int> location;
    std::vector<Node> children;

    Node(int c, int row, int col) : data(c), location(std::make_tuple(row, col)) {}
};
