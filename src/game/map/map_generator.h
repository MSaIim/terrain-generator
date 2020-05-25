#pragma once
#include "map_options.h"
#include <vector>
#include <string>
#include <random>

class MapGenerator
{
    private:
        enum class BlockType { SQUARE, CIRLCE, LINE, Count = 3 };

        struct TileCount {
            int tileType;
            MapGenerator::BlockType blockType;
            int count;
        };

        static const std::vector<MapGenerator::TileCount> getTileCounts(const MapOptions& mapOptions);

    public:
        static const std::vector<int> generate(const MapOptions& mapOptions);
};
