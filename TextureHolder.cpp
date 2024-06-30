#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	//get reference to m_textures using m_s_Instance
	//equivalent of map<string,Texture>
	auto& m = m_s_Instance->m_Textures;

	//Create iterator to hold key-value pair
	//equaivlaent to map<string,Texture>::iterator
	auto keyValuePair = m.find(filename);

	//Did we find a match
	if (keyValuePair != m.end())
	{
		//if yes return texture
		return keyValuePair->second;
	}
	else 
	{
		//File name not found
		//make new entry in map filename -> texture
		auto& texture = m[filename];
		texture.loadFromFile(filename);

		return texture;
	}
}