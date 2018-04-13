#include "Trapper.h"

Trapper::Trapper()
{
}

Trapper::~Trapper()
{
}

void Trapper::Print()
{
    std::string objStr;
    for (int i = 0; i < this->m_Size; i++)
    {
        for (int j = 0; j < this->m_Size; j++)
        {
            objStr += this->m_MazeMatrix[i][j];
        }
        objStr += "\n";
    }
    std::cout << objStr << std::endl;
}

void Trapper::Print(std::vector<std::vector<char> > matrix)
{
    std::string objStr;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            objStr += matrix[i][j];
        }
        objStr += '\n';
    }
    std::cout << objStr << std::endl;
}

bool Trapper::IsPath(int row, int col, bool visitedCheck)
{
    if (row >= 0 && row < this->m_Size && col >= 0 && col < this->m_Size)
    {
        char tile = this->m_MazeMatrix[row][col];
        if (visitedCheck)
        {
            visitedCheck = this->m_VisitedMatrix[row][col];
        }
        this->m_VisitedMatrix[row][col] = true;
        return ((tile != '+' && tile != '-' && tile != '|') && !visitedCheck);
    }
    return false;
}

bool Trapper::Navigate(int row, int col, bool checkVisited)
{
    this->m_Steps++;
    if (this->m_MazeMatrix[row][col] == 'F')
    {
        std::cout << "Found FOOD at " << row << " " << col << std::endl;
        return true;
    }

    PrintPath(row, col, '@');
    std::this_thread::sleep_for(std::chrono::seconds(1));

    bool up = IsPath(row-1, col, true);
    bool down = IsPath(row+1, col, true);
    bool left = IsPath(row, col-1, true);
    bool right = IsPath(row, col+1, true);

    if (up)
    {
//        std::cout << "up" << std::endl;
        Navigate(row-1, col, true);
    }
    if (down)
    {
//        std::cout << "down" << std::endl;
        Navigate(row+1, col, true);
    }
    if (left)
    {
//        std::cout << "left" << std::endl;
        Navigate(row, col-1, true);
    }
    if (right)
    {
//        std::cout << "right" << std::endl;
        Navigate(row, col+1, true);
    }
    return false;
}

void Trapper::MapOut(int row, int col)
{
    PrintPath(row, col, '@');
    Node root(0, row, col);
    std::cout << "Node: " << std::get<0>(root.location) << " " << std::get<1>(root.location) << std::endl;
    std::queue<Node> tileQ;
    tileQ.push(root);
    while (!tileQ.empty())
    {
        int vertical, horizontal;
        Node node = tileQ.front();
        vertical = std::get<0>(node.location);
        horizontal = std::get<1>(node.location);
        PrintPath(vertical, horizontal, (char)(node.data+'0'));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (this->m_MazeMatrix[vertical][horizontal] == 'F')
        {
            std::cout << "Found FOOD at " << vertical << " " << horizontal << std::endl;
            this->m_Steps = node.data;
            break;
        }

        bool up = IsPath(vertical-1, horizontal, true);
        bool down = IsPath(vertical+1, horizontal, true);
        bool left = IsPath(vertical, horizontal-1, true);
        bool right = IsPath(vertical, horizontal+1, true);
        if (up)
        {
//            std::cout << "UP" << std::endl;
            Node n(node.data + 1, vertical-1, horizontal);
            tileQ.push(n);
        }
        if (down)
        {
//            std::cout << "DOWN" << std::endl;
            Node n(node.data + 1, vertical+1, horizontal);
            tileQ.push(n);
        }
        if (left)
        {
//            std::cout << "LEFT" << std::endl;
            Node n(node.data + 1, vertical, horizontal-1);
            tileQ.push(n);
        }
        if (right)
        {
//            std::cout << "RIGHT" << std::endl;
            Node n(node.data + 1, vertical, horizontal+1);
            tileQ.push(n);
        }
        tileQ.pop();
    }
}

void Trapper::FindFood()
{
    int row = -1, col = -1;
    for (int i = 0; i < this->m_Size; i++)
    {
        for (int j = 0; j < this->m_Size; j++)
        {
            if (this->m_MazeMatrix[i][j] == 'N')
            {
                std::cout << "Monster starts at " << (i+1) << ", " << (j+1) << std::endl;
                row = i;
                col = j;
            }
            if (this->m_MazeMatrix[i][j] == 'F')
            {
                std::cout << "F is at " << (i+1) << ", " << (j+1) << std::endl;
            }
        }
    }
//    Navigate(row, col, true);
    this->m_VisitedMatrix[row][col] = true;
    MapOut(row, col);
    std::cout << "Took " << this->m_Steps << " steps" << std::endl;
}

void Trapper::PrintPath(int row, int col, char c)
{
    this->m_ShowMaze[row][col] = c;
    Print(m_ShowMaze);
}
