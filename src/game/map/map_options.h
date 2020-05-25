#pragma once
#include <string>
#include <vector>

struct MapOptions
{
    MapOptions(): worldWidth(0), worldHeight(0), sheetFilePath(""), rows(0), columns(0) { }

    int worldWidth;
    int worldHeight;
    std::string sheetFilePath;
    int rows;
    int columns;
    std::vector<int> tiles;
    std::vector<int> percentages;
};
