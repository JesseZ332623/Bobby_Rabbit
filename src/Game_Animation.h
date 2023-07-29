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
    /*上下左右行走 动画的相关 rect 参数 一共 8 帧*/
    SDL_Rect u_d_l_r_rect_frames[8];

    /*死亡的 动画相关 rect 参数 共 8 帧*/
    SDL_Rect death_rect[8];

    /*消失的 动画相关 rect 参数 共 9 帧*/
    SDL_Rect fade_rect[9];

    /*向左行走的 目标 rect 参数*/
    SDL_Rect left_dest_rect;

    /*向右行走的 目标 rect 参数*/
    SDL_Rect right_dest_rect;

    /*向上行走的 目标 rect 参数*/
    SDL_Rect up_dest_rect;

    /*向下行走的 目标 rect 参数*/
    SDL_Rect down_dest_rect;

    /*死亡的 目标 rect 参数*/
    SDL_Rect death_dest_rect;

    /*消失的 目标 rect 参数*/
    SDL_Rect fade_dest_rect;

    /*不耐烦的等待 动画的相关 rect 参数 一共 3 帧*/
    SDL_Rect wait_rect_frame_1;
    SDL_Rect wait_rect_frame_2;
    SDL_Rect wait_rect_frame_3;
    SDL_Rect wait_dest_rect;

} Frame_Rect;

/*加载所有动画图片的 texture 和 surface*/
void Load_Bobby_Animation(Animation *animation, SDL_Renderer *render);

/*设置 不耐烦的等待 动画的相关 rect 参数*/
void Set_Wait_Frame_Format(Frame_Rect *frame_rect);

/*设置 向左行走 动画的相关 rect 参数*/
void Set_Left_Frame_Format(Frame_Rect *frame_rect);

/*设置 向右行走 动画的相关 rect 参数*/
void Set_Right_Frame_Format(Frame_Rect *frame_rect);

/*设置 向上行走 动画的相关 rect 参数*/
void Set_Up_Frame_Format(Frame_Rect *frame_rect);

/*设置 向下走 动画的相关 rect 参数*/
void Set_Down_Frame_Format(Frame_Rect *frame_rect);

/*设置 死亡 动画的相关 rect 参数*/
void Set_Death_Frame_Format(Frame_Rect *frame_rect);

/*设置 消失 动画的相关 rect 参数*/
void Set_Fade_Frame_Format(Frame_Rect *frame_rect);

#endif
