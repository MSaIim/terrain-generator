#pragma once
#include <string>
#include <map>

struct MapOptions
{
    MapOptions(): worldWidth(0), worldHeight(0), sheetFilePath(""), rows(0), columns(0) { }

    int worldWidth;
    int worldHeight;
    std::string sheetFilePath;
    int rows;
    int columns;
    std::map<int, int> tileData;
};
