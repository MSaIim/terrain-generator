#pragma once
#include "map_options.h"
#include <vector>
#include <array>
#include <string>
#include <random>
#include <math.h>
#include <iostream>
#include <iomanip>

class MapGenerator
{
    private:
        enum class BlockType { SQUARE, LINE, Count = 2 };
        enum class Direction { UP, DOWN, LEFT, RIGHT, Count = 4 };

        struct TileData {
            int tileType;
            MapGenerator::BlockType blockType;
            int count;
        };

        static const bool isIndexInBounds(const int size, const int index);
        static const int getStartPosition(const std::vector<int>& tiles);
        static const std::vector<MapGenerator::TileData> getTileData(const MapOptions& mapOptions);
        static const std::vector<int> build(const MapOptions& mapOptions, const std::vector<MapGenerator::TileData>& tileData);
        static const std::vector<int>& createSquareBlock(const MapOptions& mapOptions, const MapGenerator::TileData& tileData, std::vector<int>& tiles);
        static const std::vector<int>& createLineBlock(const MapOptions& mapOptions, const MapGenerator::TileData& tileData, std::vector<int>& tiles);
        static const std::vector<int>& fillEmptyTiles(const MapOptions& mapOptions, std::vector<int>& tiles);

        // Debug functions
        static const void print(const MapOptions& mapOptions, const std::vector<MapGenerator::TileData>& tileData, const std::vector<int>& tiles);

    public:
        static const std::vector<int> generate(const MapOptions& mapOptions);
};
