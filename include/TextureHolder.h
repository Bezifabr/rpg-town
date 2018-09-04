#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>
#include <memory>

class TextureHolder
{
    std::map<std::string,std::unique_ptr<sf::Texture>> textures;

public:

    const sf::Texture& GetTexture(const std::string& id);
    const sf::Texture& LoadTexture(const std::string& id, const std::string& src);
};

#endif // TEXTURE_HOLDER_H