
#include "./Game_Map_.h"

// 地图数据
unsigned char mapData[MAP_HEIGHT][MAP_WIDTH];

void LoadMapData(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Failed to open map file: " << filename << std::endl;
        return;
    }
    file.seekg(4);
    file.read(reinterpret_cast<char *>(mapData), MAP_WIDTH * MAP_HEIGHT);
    file.close();
}

void DrawMap(SDL_Renderer *renderer, SDL_Texture *texture)
{
    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            int tileIndex = mapData[y][x];
            int srcX = (tileIndex % 8) * TILE_SIZE;
            int srcY = (tileIndex / 8) * TILE_SIZE;
            int dstX = x * TILE_SIZE;
            int dstY = y * TILE_SIZE;

            SDL_Rect srcRect = {srcX, srcY, TILE_SIZE, TILE_SIZE};
            SDL_Rect dstRect = {dstX, dstY, TILE_SIZE, TILE_SIZE};

            SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
        }
    }
}