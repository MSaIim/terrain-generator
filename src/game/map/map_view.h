#pragma once
#include <SFML/Graphics.hpp>
#include "../core/resource_manager.h"
#include "map_options.h"
#include <vector>

class MapView : public sf::Drawable, public sf::Transformable
{
    private:
        sf::Texture spriteSheet;
        sf::VertexArray vertexArray;

        const void setQuads(const MapOptions& mapOptions, const std::vector<int>& tiles);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    public:
        MapView();
        ~MapView();

        void load(const MapOptions& mapOptions, const std::vector<int>& tiles);
};
