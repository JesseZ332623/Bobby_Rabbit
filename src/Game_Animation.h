#ifndef _GAME_ANIMATION_H
#define _GAME_ANIMATION_H

#include <vector>

#include <SDL.h>
#include <SDL_image.h>

/*需要实现的动画分别是：  向左行走[0] 向右行走[1] 向上行走[2] 向下行走[3] 死亡[4] 消失[5] 不耐烦的等待[6]*/
/*
    由于素材中的 图片是连续的，因此不用费尽心思的创建每一帧的纹理，只需加载每一张图片的 texture 和 surface
    然后在渲染时改变图片的裁剪范围即可。
*/

/*图片的 texture 和 surface 结构体*/
typedef struct Animation_Info
{
    SDL_Surface *left_surface;
    SDL_Texture *left_texture;

    SDL_Surface *right_surface;
    SDL_Texture *right_texture;

    SDL_Surface *up_surface;
    SDL_Texture *up_texture;

    SDL_Surface *down_surface;
    SDL_Texture *down_texture;

    SDL_Surface *death_surface;
    SDL_Texture *death_texture;

    SDL_Surface *fade_surface;
    SDL_Texture *fade_texture;

    SDL_Surface *wait_surface;
    SDL_Texture *wait_texture;

} Animation;

/*帧的 rect 结构体 用于规定图片的裁剪范围和播放坐标*/
typedef struct _Frame_Rect_
{
    SDL_Rect up_down_left_right_rect;
    SDL_Rect death_rect;
    SDL_Rect fade_rect;

    SDL_Rect wait_rect_frame_1;
    SDL_Rect wait_rect_frame_2;
    SDL_Rect wait_rect_frame_3;
    SDL_Rect wait_dest_rect;

} Frame_Rect;

/*加载所有动画图片的 texture 和 surface*/
void Load_Bobby_Animation(Animation *animation, SDL_Renderer *render);

/*获取 不耐烦的等待 动画的相关 rect 参数*/
void Get_Wait_Frame_Format(Frame_Rect *frame_rect);



#endif
