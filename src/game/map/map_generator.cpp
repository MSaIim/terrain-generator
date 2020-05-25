#include "map_generator.h"

const std::vector<int> MapGenerator::generate(const MapOptions& mapOptions) {
    std::vector<int> map;

    MapGenerator::getTileCounts(mapOptions);

    return map;
}

const std::vector<MapGenerator::TileCount> MapGenerator::getTileCounts(const MapOptions& mapOptions) {
    std::vector<MapGenerator::TileCount> tileCounts;

    // Random number generator
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::uniform_int_distribution<> blockDistribution(0, static_cast<int>(MapGenerator::BlockType::Count) - 1);
    
    // Get map options
    int worldSize = mapOptions.worldWidth * mapOptions.worldHeight;
    
    // Generate tile counts
    for (int i = 0; i < mapOptions.percentages.size(); i++) {
        float maxTiles = worldSize * (mapOptions.percentages[i] / 100.f);

        // Generate random counts up to the max number of tiles
        int remainingTiles = static_cast<int>(maxTiles);
        
        while (remainingTiles > 0) {
            // Setup distributor(s)
            std::uniform_int_distribution<> tileDistribution(1, remainingTiles);
            
            // Get random block type and random number of tiles
            const int numberOfTiles = static_cast<int>(tileDistribution(randomEngine));
            MapGenerator::BlockType blockType = static_cast<MapGenerator::BlockType>(blockDistribution(randomEngine));

            // Add tile count to vector
            tileCounts.push_back({ mapOptions.tiles[i], blockType, numberOfTiles });

            // Subtract the remaining tiles
            remainingTiles -= numberOfTiles;
        }
    }

    return tileCounts;
}
