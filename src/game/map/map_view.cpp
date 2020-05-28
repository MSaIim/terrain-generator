#include "map_view.h"

MapView::MapView() { }

void MapView::load(const MapOptions& mapOptions, const std::vector<int>& tiles) {
    // Load the spritesheet texture
    this->spriteSheet = ResourceManager::getInstance().loadTexture(mapOptions.sheetFilePath);

    // Resize the vertex array to fit world size
    const int vertexArraySize = mapOptions.worldWidth * mapOptions.worldHeight * 4;
    this->vertexArray.setPrimitiveType(sf::Quads);
    this->vertexArray.resize(vertexArraySize);

    // Populate the vertex array with one quad per tile
    this->setQuads(mapOptions, tiles);
}

const void MapView::setQuads(const MapOptions& mapOptions, const std::vector<int>& tiles) {
    // Get size of a tile
    const unsigned int tileWidth = this->spriteSheet.getSize().x / mapOptions.sheetColumns;
    const unsigned int tileHeight = this->spriteSheet.getSize().y / mapOptions.sheetRows;

    // Populate the vertex array with one quad per tile
    for (int i = 0; i < mapOptions.worldWidth; i++) {
        for (int j = 0; j < mapOptions.worldHeight; j++) {
            // Get the current tile number (Does 1 column at a time)
            const unsigned int tileIndex = static_cast<int>(i + j * mapOptions.worldWidth);
            const unsigned int tileNumber = tiles[tileIndex];

            // Find its position in the tileset texture
            const unsigned int tileRow = tileNumber % (this->spriteSheet.getSize().x / tileWidth);
            const unsigned int tileCol = tileNumber / (this->spriteSheet.getSize().x / tileWidth);

            // Get a pointer to the current tile's quad
            const unsigned int vertexIndex = static_cast<int>((i + j * mapOptions.worldWidth) * 4);
            sf::Vertex* quad = &this->vertexArray[vertexIndex];

            /*\
            |*|  Define its 4 corners
            |*|
            |*|	  0 ----- 1	    This takes care of where and how the quad will
            |*|	  |       |	    appear in the world. Adding or subtracting in the
            |*|	  |       |	    X or Y will change the size/shape.
            |*|	  3 ----- 2
            \*/
            quad[0].position = sf::Vector2f(static_cast<float>((i * tileWidth)), static_cast<float>(j * tileHeight));
            quad[1].position = sf::Vector2f(static_cast<float>((i + 1) * tileWidth), static_cast<float>(j * tileHeight));
            quad[2].position = sf::Vector2f(static_cast<float>((i + 1) * tileWidth), static_cast<float>((j + 1) * tileHeight));
            quad[3].position = sf::Vector2f(static_cast<float>(i * tileWidth), static_cast<float>((j + 1) * tileHeight));

            /*\
            |*|  Define its 4 texture coordinates
            |*|
            |*|	  0 ------- 1   Offsets => Top(T), Right(R), Bottom(B), Left(L)
            |*|	  |	   T    |
            |*|   | L     R |   Offsets will be subtracted from the texture.
            |*|	  |	   B    |   They are not required if you want the whole texture.
            |*|	  3 ------- 2
            |*|
            |*|  Offset examples:
            |*|     - quad[0].texCoords = sf::Vector2f((float)((tileCol * tileWidth) - leftOffset), (float)((tileRow * tileHeight) - topOffset));
            |*|     - quad[1].texCoords = sf::Vector2f((float)(((tileCol + 1) * tileWidth) - rightOffset), (float)((tileRow * tileHeight) - topOffset));
            \*/
            quad[0].texCoords = sf::Vector2f(static_cast<float>(tileRow * tileWidth), static_cast<float>(tileCol * tileHeight));
            quad[1].texCoords = sf::Vector2f(static_cast<float>((tileRow + 1) * tileWidth), static_cast<float>(tileCol * tileHeight));
            quad[2].texCoords = sf::Vector2f(static_cast<float>((tileRow + 1) * tileWidth), static_cast<float>((tileCol + 1) * tileHeight));
            quad[3].texCoords = sf::Vector2f(static_cast<float>(tileRow * tileWidth), static_cast<float>((tileCol + 1) * tileHeight));
        }
    }
}

void MapView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply the transform
    states.transform *= getTransform();

    // Apply the tileset texture
    states.texture = &this->spriteSheet;

    // Draw the vertex array
    target.draw(this->vertexArray, states);
}

MapView::~MapView() { }
