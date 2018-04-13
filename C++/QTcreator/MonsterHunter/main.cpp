#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "trapper.h"

int main(int argc, char **argv)
{
    printf("hello world\n");
    const char* mapName = "map3.txt";
    std::ifstream istreamFile(mapName);
    std::vector<std::vector<char> > map;
    std::string line;

    int num_lines = 0;

    if (istreamFile.is_open())
    {
        while (getline(istreamFile, line))
        {
            std::cout << line << std::endl;
            ++num_lines;
        }

        istreamFile.clear();
        istreamFile.close();
        istreamFile.open(mapName);

        char c;
        for (int i = 0; i < num_lines; i++)
        {
            std::vector<char> tempChars;
            for (int j = 0; j < num_lines; j++)
            {
                istreamFile >> std::noskipws >> c;
                while (c == '\n')
                {
                    istreamFile >> std::noskipws >> c;
                }
                tempChars.push_back(c);
            }
            map.push_back(tempChars);
        }
    }
    istreamFile.clear();
    istreamFile.close();

    Trapper test(map);
    test.Print();
    test.FindFood();

    return 0;
}
