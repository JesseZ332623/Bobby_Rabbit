#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include <SDL.h>

#include <iostream>
#include <fstream>

const int TILE_SIZE = 32;
const int MAP_WIDTH = 16;
const int MAP_HEIGHT = 16;

/*读取地图数据*/
void LoadMapData(const std::string& filename);

/*通过地图数据绘制地图*/
void DrawMap(SDL_Renderer* renderer, SDL_Texture* texture); 

#endif