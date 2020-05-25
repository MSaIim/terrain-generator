#pragma once
#include "map_options.h"
#include <vector>
#include <string>
#include <random>

class Generator
{
    private:
        enum class BlockType { SQUARE, CIRLCE, LINE, Count = 3 };

        struct TileCount {
            int tileType;
            Generator::BlockType blockType;
            int count;
        };

        static const std::vector<Generator::TileCount> getTileCounts(const MapOptions& mapOptions);

    public:
        static const std::vector<int> generateMap(const MapOptions& mapOptions);
};
