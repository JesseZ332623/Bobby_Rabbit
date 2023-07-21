#ifndef _GAME_TITLE_H_
#define _GAME_TITLE_H_
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "./Game_Map_.h"
#include "./Game_Animation.h"

#define INIT_SDL_ERROR 1              /*初始化SDL的错误码*/
#define CREATE_WINDOW_ERROR 2         /*创建窗口的错误码*/
#define GET_EVENTS_ERROR 3            /*获取事件的错误码*/
#define FILLRECT_ERROR 4              /*渲染窗口失败错误码*/
#define UPDATE_WINDOW_SURFACE_ERROR 5 /*更新窗口失败错误码*/
#define MIX_LOAD_ERROR 6              /*加载音频失败错误码*/
#define INIT_ING_ERROR 7              /*初始化图片失败错误码*/
#define MIX_PLAY_ERROR -1             /*播放音频失败错误码*/
#define INIT_TTF_ERROR -1             /*初始化字体错误码*/

const int WINDOW_WIDTH = 240;         /*窗口宽度*/
const int WINDOW_HEIGHT = 320;        /*窗口长度*/
const int FREAME_RATE = 60;

class Game_Title
{
private:
    SDL_Window *basic_window;        /*窗口对象*/
    SDL_Renderer *rander;            /*渲染器对象*/

    Mix_Chunk *title_music;          /*背景音乐对象*/
    std::string title_music_path;

    SDL_Surface *title_image;        /*标题画面surface对象*/
    SDL_Rect title_image_rect;       /*标题画面 渲染信息*/
    SDL_Texture *title_img_texture;  /*标题画面纹理对象*/
    std::string title_image_path;

    SDL_Surface *enter_arrow;       /*进入箭头surface对象*/
    SDL_Rect enter_arrow_rect;      /*进入箭头rect对象*/
    SDL_Texture *enter_arrow_texture; /*箭头纹理对象*/
    std::string enter_arrow_path;

    Animation animation;           /*动画素材的texture 和 surface*/
    Frame_Rect frame_rect;
   

    bool if_quit;
    SDL_Event events;                /*事件捕获对象*/
    Uint32 basic_screen_color_info;
    
    int font_size;
    TTF_Font *title_options;         /*TTF字体对象*/
    SDL_Color font_color;            /*字体颜色对象*/
    SDL_Surface *font_surface_press_enter;  /*字体 surface 对象*/
    SDL_Surface *font_surface_start; 
    SDL_Surface *font_surface_quit;
    SDL_Texture *font_press_enter_texture;  /*字体纹理对象*/
    SDL_Texture *font_start_texture;
    SDL_Texture *font_quit_texture;
    SDL_Rect font_rect_press_enter;     /*字体渲染信息*/
    SDL_Rect font_rect_start;        
    SDL_Rect font_rect_quit;
    std::string ttf_font_path;

    std::string blm_file_path;          /*地图渲染信息*/
    SDL_Texture *map_texture;

    int frame_duration;                 /*帧率控制*/
    Uint32 render_start, render_end;
    
public:
    /*类构建函数  初始化所有私有成员*/
    Game_Title(void);

    /*初始化所有组件 若任何组件初始化失败，则返回错误码并退出*/
    bool init_all_module();

    /*音频相关操作  打开音频并进行循环播放*/
    bool open_and_play_title_music();

    /*窗口相关操作 创建窗口并渲染图片、文字、动画*/
    bool window_render_resource();
    void image_render();        /*渲染图片*/
    void ttf_font_render();     /*渲染字体*/
    void animation_render();    /*兔子动画的渲染信息*/
    void map_render();          /*地图的动画渲染信息*/

   

    /*事件捕获操作*/
    bool get_events();

    /*类析构函数 释放所有资源*/
    ~Game_Title();
};

#endif
