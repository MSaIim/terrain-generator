#pragma once
#include <string>
#include <map>

struct MapOptions
{
    MapOptions(): worldWidth(0), worldHeight(0), sheetFilePath(""), sheetRows(0), sheetColumns(0) { }

    int worldWidth;
    int worldHeight;
    std::string sheetFilePath;
    int sheetRows;
    int sheetColumns;
    std::map<int, int> tileData;
};
