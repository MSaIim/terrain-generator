#include "map_generator.h"

const std::vector<int> MapGenerator::generate(const MapOptions& mapOptions) {
    // Get the tile data for building the map
    const std::vector<MapGenerator::TileData> tileData = MapGenerator::getTileData(mapOptions);

    // Build the map using the tile data
    std::vector<int> tiles = MapGenerator::build(mapOptions, tileData);

    //MapGenerator::print(mapOptions, tileData, tiles);
    return tiles;
}

const std::vector<MapGenerator::TileData> MapGenerator::getTileData(const MapOptions& mapOptions) {
    std::vector<MapGenerator::TileData> tileData;

    // Random number generator
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::uniform_int_distribution<> blockDistribution(0, static_cast<int>(MapGenerator::BlockType::Count) - 1);
    
    // Get map options
    int worldSize = mapOptions.worldWidth * mapOptions.worldHeight;
    
    // Generate tile counts
    for (auto& tile : mapOptions.tileData) {
        float maxTiles = worldSize * (tile.second / 100.f);

        // Generate random counts up to the max number of tiles
        int remainingTiles = static_cast<int>(maxTiles);

        while (remainingTiles > 0) {
            // Setup distributor(s)
            std::uniform_int_distribution<> tileDistribution(1, remainingTiles);

            // Get random block type and random number of tiles
            const int numberOfTiles = static_cast<int>(tileDistribution(randomEngine));
            MapGenerator::BlockType blockType = static_cast<MapGenerator::BlockType>(blockDistribution(randomEngine));

            // Add tile count to vector
            tileData.push_back({ tile.first, blockType, numberOfTiles });

            // Subtract the remaining tiles
            remainingTiles -= numberOfTiles;
        }
    }

    return tileData;
}

const std::vector<int> MapGenerator::build(const MapOptions& mapOptions, const std::vector<MapGenerator::TileData>& tileData) {
    const int worldSize = mapOptions.worldWidth * mapOptions.worldHeight;
    std::vector<int> tiles(worldSize, -1);

    for (int i = 0; i < tileData.size(); i++) {
        switch (tileData[i].blockType) {
            case MapGenerator::BlockType::SQUARE:
                tiles = MapGenerator::createSquareBlock(mapOptions, tileData[i], tiles);
                break;
            case MapGenerator::BlockType::LINE:
                tiles = MapGenerator::createLineBlock(mapOptions, tileData[i], tiles);
                break;
        }
    }

    // Fill any empty tiles
    tiles = MapGenerator::fillEmptyTiles(mapOptions, tiles);

    return tiles;
}

const std::vector<int>& MapGenerator::createSquareBlock(const MapOptions& mapOptions, const MapGenerator::TileData& tileData, std::vector<int>& tiles) {
    int startPosition = MapGenerator::getStartPosition(tiles);

    // Setup variables
    int index = startPosition;
    int remainingCount = tileData.count;
    int numberOfColumns = static_cast<int>(ceil(tileData.count / 4.0f));
    int worldSize = mapOptions.worldWidth * mapOptions.worldHeight;

    // Create tiles in a sqaure
    while (remainingCount > 0) {
        for (int i = 0; i < numberOfColumns; i++) {
            if (MapGenerator::isIndexInBounds(worldSize, index) && tiles[index] == -1) {
                tiles[index++] = tileData.tileType;
            }
        }

        startPosition += mapOptions.worldWidth;
        index = startPosition;
        remainingCount -= numberOfColumns;
    }

    return tiles;
}

const std::vector<int>& MapGenerator::createLineBlock(const MapOptions& mapOptions, const MapGenerator::TileData& tileData, std::vector<int>& tiles) {
    int startPosition = MapGenerator::getStartPosition(tiles);

    // Get random direction (1 = up, 2 = down, 3 = left, 4 = right)
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::uniform_int_distribution<> distribution(0, static_cast<int>(MapGenerator::Direction::Count) - 1);
    MapGenerator::Direction direction = static_cast<MapGenerator::Direction>(distribution(randomEngine));

    // Setup variables
    int index = startPosition;
    int worldSize = mapOptions.worldWidth * mapOptions.worldHeight;

    // Create tiles in that direction
    for (int i = 0; i < tileData.count; i++) {
        if (MapGenerator::isIndexInBounds(worldSize, index) && tiles[index] == -1) {
            tiles[index] = tileData.tileType;

            switch (direction) {
                case MapGenerator::Direction::UP:
                    index -= mapOptions.worldWidth;
                    break;
                case MapGenerator::Direction::DOWN:
                    index += mapOptions.worldWidth;
                    break;
                case MapGenerator::Direction::LEFT:
                    index -= 1;
                    break;
                case MapGenerator::Direction::RIGHT:
                    index += 1;
                    break;
            }
        }
    }

    return tiles;
}

const std::vector<int>& MapGenerator::fillEmptyTiles(const MapOptions& mapOptions, std::vector<int>& tiles) {
    // Get current tile count for block type
    std::map<int, int> tileCounts;
    for (int i = 0; i < tiles.size(); i++) {
        if (tiles[i] != -1) {
            tileCounts[tiles[i]] = tileCounts[tiles[i]] + 1;
        }
    }

    // Fill in the remaining tiles
    int worldSize = mapOptions.worldWidth * mapOptions.worldHeight;
    for (auto& tile : mapOptions.tileData) {
        int maxTiles = static_cast<int>(worldSize * (tile.second / 100.f));
        int remainingTiles = maxTiles - tileCounts[tile.first];
        
        for (int i = 0; i < tiles.size() && remainingTiles >= 0; i++) {
            if (tiles[i] == -1) {
                tiles[i] = tile.first;
                remainingTiles -= 1;
            }
        }
    }

    return tiles;
}

const int MapGenerator::getStartPosition(const std::vector<int>& tiles) {
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::uniform_int_distribution<> distribution(0, static_cast<int>(tiles.size() - 1));

    int startPosition = -1;
    while (startPosition == -1) {
        int position = distribution(randomEngine);

        if (tiles[position] == -1) {
            startPosition = position;
        }
    }

    return startPosition;
}

const bool MapGenerator::isIndexInBounds(const int size, const int index) {
    return index >= 0 && index < size;
}

const void MapGenerator::print(const MapOptions& mapOptions, const std::vector<MapGenerator::TileData>& tileData, const std::vector<int>& tiles) {
    std::cout << "Tile Data: " << std::endl;
    for (int i = 0; i < tileData.size(); i++) {
        std::cout << std::setw(5) << "    Tile: " << tileData[i].tileType
            << " | Block: " << static_cast<int>(tileData[i].blockType)
            << " | Count: " << tileData[i].count << std::endl;
    }

    std::cout << std::endl << "Map: " << std::endl;
    for (int i = 0; i < tiles.size(); i++) {
        std::cout << std::setw(5) << tiles[i] << " ";

        if ((i + 1) % mapOptions.worldWidth == 0) {
            std::cout << std::endl;
        }
    }
}
