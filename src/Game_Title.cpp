#include "./Game_Title.h"

/*类构建函数  初始化所有私有成员*/
Game_Title::Game_Title()
{
    basic_window = NULL;
    title_options = NULL;
    title_music = NULL;
    title_image = NULL;
    enter_arrow = NULL;
    enter_arrow_texture = NULL;
    font_surface_start = NULL;
    font_surface_quit = NULL;
    rander = NULL;

    frame_rect = {0, 0, 0, 0, 0, 0, 0};
    
    title_img_texture = NULL;
    font_surface_press_enter = NULL;
    font_press_enter_texture = NULL;
    font_start_texture = NULL;
    font_quit_texture = NULL;
    font_color = {0x00, 0x00, 0x00, 0xff};
    title_image_rect = {0, 0, 0, 0};
    font_rect_press_enter = {0, 0, 0, 0};
    font_rect_start = {0, 0, 0, 0};
    font_rect_quit = {0, 0, 0, 0};
    enter_arrow_rect = {0, 0, 0, 0};
    if_quit = false;
    basic_screen_color_info = 0x00000000;
    title_music_path = "music\\title.wav";
    title_image_path = "img\\title.png";
    ttf_font_path = "font\\Mona-SemiBold-2.ttf";
    enter_arrow_path = "img\\arrow_d.png";
    font_size = 0;

    blm_file_path = "map_data\\Normal_Level\\normal01.blm";
    map_texture = NULL;

    frame_duration = 1000 / FREAME_RATE;
    render_start = render_end = 0;
}

/*初始化所有组件 若任何组件初始化失败，则返回错误码并退出*/
bool Game_Title::init_all_module()
{
    SDL_Log("Initializing all components\n");

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("Init Vedio and Audio failed: (%s)\n", SDL_GetError());
        return INIT_SDL_ERROR;
    }

    Mix_Init(MIX_INIT_MID | MIX_INIT_FLAC | MIX_INIT_MP3);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    if (TTF_Init() == INIT_TTF_ERROR)
    {
        SDL_Log("Init ttf failed: (%s)\n", SDL_GetError());
        return INIT_TTF_ERROR;
    }
    SDL_Log("Finish\n");

    return true;
}

/*音频相关操作  打开音频并进行循环播放*/
bool Game_Title::open_and_play_title_music()
{
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
                  MIX_DEFAULT_FORMAT,
                  MIX_DEFAULT_CHANNELS, 2048);

    title_music = Mix_LoadWAV(title_music_path.c_str());

    Mix_PlayChannel(1 ,title_music, -1);

    return true;
}

/*图片的渲染相关信息*/
void Game_Title::image_render()
{
    /*标题图片的渲染信息*/
    title_image = IMG_Load(title_image_path.c_str());
    title_img_texture = SDL_CreateTextureFromSurface(rander, title_image);
    title_image_rect.w = title_image->w;
    title_image_rect.h = title_image->h;

    /*箭头的渲染信息*/
    enter_arrow = IMG_Load(enter_arrow_path.c_str());
    enter_arrow_texture = SDL_CreateTextureFromSurface(rander, enter_arrow);
    enter_arrow_rect.w = enter_arrow->w;
    enter_arrow_rect.h = enter_arrow->h;
    enter_arrow_rect.x = 0;
    enter_arrow_rect.y = WINDOW_HEIGHT - enter_arrow->h;
}

/*动画的渲染相关信息*/
void Game_Title::animation_render()
{ 
    Get_Wait_Frame_Format(&frame_rect);
    Load_Bobby_Animation(&animation, rander);
}

/*地图的渲染相关信息*/
void Game_Title::map_render()
{
    map_texture = SDL_CreateTextureFromSurface(rander, IMG_Load("img\\tileset.png"));
}

/*字体的渲染相关信息*/
void Game_Title::ttf_font_render()
{
     /*字体的渲染信息*/
    font_size = 30;
    title_options = TTF_OpenFont(ttf_font_path.c_str(), font_size);
    
    font_surface_start = TTF_RenderUTF8_Blended(title_options, "Start(1)", font_color);
    font_start_texture = SDL_CreateTextureFromSurface(rander, font_surface_start);
    font_rect_start.w = font_surface_start->w;
    font_rect_start.h = font_surface_start->h;
    font_rect_start.x = 86;
    font_rect_start.y = 45;

    font_surface_quit = TTF_RenderUTF8_Blended(title_options, "Quit(0)", font_color);
    font_quit_texture = SDL_CreateTextureFromSurface(rander, font_surface_quit);
    font_rect_quit.w = font_surface_quit->w;
    font_rect_quit.h = font_surface_quit->h;
    font_rect_quit.x = 86;
    font_rect_quit.y = 80;

    font_surface_press_enter = TTF_RenderUTF8_Blended(title_options,"Press  Enter", font_color);
    font_press_enter_texture = SDL_CreateTextureFromSurface(rander, font_surface_press_enter);
    font_rect_press_enter.w = font_surface_press_enter->w;
    font_rect_press_enter.h = font_surface_press_enter->h;
    font_rect_press_enter.x = 48;
    font_rect_press_enter.y = 130;
}

/*窗口相关操作 创建窗口并渲染图片、文字*/
bool Game_Title::window_render_resource()
{
    /*创建窗口*/
    basic_window = SDL_CreateWindow("Bobby Rabbit",
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    WINDOW_WIDTH, WINDOW_HEIGHT,
                                    SDL_WINDOW_SHOWN);

    /*初始化渲染器*/
    rander = SDL_CreateRenderer(basic_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    /*图片的渲染*/
    image_render();

    /*字体的渲染*/
    ttf_font_render();

    /*动画的渲染*/
    animation_render();

    /*地图的渲染*/
    map_render();
   
    return true;
}

/*事件捕获操作*/
bool Game_Title::get_events()
{
    bool if_menu_open = false;          /*控制菜单的开关*/
    bool be_white_ttf_1 = false;       /*控制 start 字体的颜色变化 （黑/白）*/ 
    bool be_white_ttf_2 = false;       /*控制 quit 字体的颜色变化 （黑/白）*/ 
    int current_frame = 0;
    while (!if_quit)                         /*等待退出事件*/                 
    {
        while (SDL_PollEvent(&events))      /*捕获事件*/
        {   
            switch(events.type)             /*获取事件类别进行判断*/
            {
                case SDL_KEYDOWN:           /*如果是键盘事件*/ 
                    switch (events.key.keysym.sym)
                    {
                        case SDLK_RETURN:   /*如果按下 Enter 打开菜单*/
                            if_menu_open = true;
                            continue;

                        case SDLK_ESCAPE:   /*如果按下 Esc 关闭菜单*/
                            if_menu_open = false;
                            continue;

                        case SDLK_1:        /*如果在打开菜单的情况下按下 1*/
                            be_white_ttf_1 = true;  /*将 start 渲染成白色*/
                            continue;

                        case SDLK_0:        /*如果在打开菜单的情况下按下 0*/
                            be_white_ttf_2 = true;  /*将 quit 渲染成白色*/
                            continue;

                        default:
                            continue;
                    }
                case SDL_QUIT:         /*如果检查到退出事件*/
                    SDL_Log("Quit\n");
                    if_quit = true;    /*退出这个循环*/
                    continue;

                default:               /*如果是上述事件以外的事件， 则输出事件类型*/            
                    SDL_Log("Events Type: [%d]\n", events.type); 
                    continue;
            }
        }
        /*渲染：*/
        render_start = SDL_GetTicks();
        if (if_menu_open)       /*若打开菜单 要渲染的对象如下：*/
        {
            SDL_RenderClear(rander);
            /*渲染图片*/
            SDL_RenderCopy(rander, title_img_texture, NULL, &title_image_rect);
            /*渲染 Start 字体*/
            SDL_RenderCopy(rander, font_start_texture, NULL, &font_rect_start);
            /*渲染 Quit 字体*/
            SDL_RenderCopy(rander, font_quit_texture, NULL, &font_rect_quit);
            if (be_white_ttf_1)                 /*开始游戏要做的事情*/
            {
                Mix_Pause(1);
                font_color.r = 255;
                font_color.g = 255;
                font_color.b = 255;
                font_surface_start = TTF_RenderUTF8_Blended(title_options, "Start(1)", font_color);
                font_start_texture = SDL_CreateTextureFromSurface(rander, font_surface_start);
                SDL_RenderCopy(rander, font_start_texture, NULL, &font_rect_start);             /*调整相关参数后 渲染 Start 字体*/

                SDL_SetWindowSize(basic_window, 500, 500);                                      /*调整窗口大小并维持在中间的位置*/
                SDL_SetWindowPosition(basic_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
                
                SDL_RenderClear(rander);            /*清空渲染器*/
                LoadMapData(blm_file_path);         /*读取地图文件的数据*/
                DrawMap(rander, map_texture);       /*绘制地图*/
                
                /*  。。。 */
            }    
            else if (be_white_ttf_2)                /*关闭游戏要做的事情*/
            {                                       /*渲染一下 quit 字体后退出循环即可*/
                font_color.r = 255;
                font_color.g = 255;
                font_color.b = 255;
                font_surface_quit = TTF_RenderUTF8_Blended(title_options, "Quit(0)", font_color);
                font_quit_texture = SDL_CreateTextureFromSurface(rander, font_surface_quit);
                SDL_RenderCopy(rander, font_quit_texture, NULL, &font_rect_quit);
                be_white_ttf_2 = false;
                if_quit = true;         
            }
            else                        /*在没有选择菜单的内容时要做的事情*/    
            {                           /*渲染字体， 标题图片 以及 兔子的动画*/
                font_color.r = 0;
                font_color.g = 0;
                font_color.b = 0;
                ttf_font_render();
                SDL_RenderCopy(rander, font_start_texture, NULL, &font_rect_start);
                SDL_RenderCopy(rander, font_quit_texture, NULL, &font_rect_quit);
            } 
        }
        else    /*关闭菜单 要渲染的内容如下*/
        {
            Mix_Resume(1);
            be_white_ttf_1 = false;
            SDL_SetWindowSize(basic_window, WINDOW_WIDTH, WINDOW_HEIGHT);
            SDL_SetWindowPosition(basic_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
            /*渲染图片*/
            SDL_RenderCopy(rander, title_img_texture, NULL, &title_image_rect);
            /*渲染提示文字*/
            SDL_RenderCopy(rander, font_press_enter_texture, NULL, &font_rect_press_enter);
            /*渲染箭头*/
            SDL_RenderCopy(rander, enter_arrow_texture, NULL ,&enter_arrow_rect);
            //SDL_RenderPresent(rander);

            /*播放渲染兔子跺脚动画*/
            current_frame++;
            switch (current_frame)
            {
            case 1:
                SDL_RenderCopy(rander, animation.wait_texture, &frame_rect.wait_rect_frame_1, &frame_rect.wait_dest_rect);
                SDL_RenderPresent(rander);
                SDL_RenderClear(rander);
                SDL_Delay(25);
                continue;
            case 2:
                SDL_RenderCopy(rander, animation.wait_texture, &frame_rect.wait_rect_frame_2, &frame_rect.wait_dest_rect);
                SDL_RenderPresent(rander);
                SDL_RenderClear(rander);
                SDL_Delay(25);
                continue;
            case 3:
                SDL_RenderCopy(rander, animation.wait_texture, &frame_rect.wait_rect_frame_3, &frame_rect.wait_dest_rect);
                SDL_RenderPresent(rander);
                SDL_RenderClear(rander);
                SDL_Delay(25);
                continue;
            default:
                current_frame = 0;
                SDL_RenderClear(rander);
                continue;
            }
        }
        SDL_RenderPresent(rander);
        render_end = SDL_GetTicks() - render_start;

        if (render_end < frame_duration)
        {
            SDL_Delay(frame_duration - render_end);
        }
    }
    return if_quit;
}

/*类析构函数 释放所有资源*/
Game_Title::~Game_Title()
{
    SDL_Log("Free all resource");
    Mix_FreeChunk(title_music);
    SDL_DestroyTexture(font_press_enter_texture);
    SDL_DestroyTexture(title_img_texture);
    SDL_DestroyTexture(enter_arrow_texture);
    SDL_DestroyTexture(font_start_texture);
    SDL_DestroyTexture(font_quit_texture);
    SDL_DestroyRenderer(rander);
    TTF_CloseFont(title_options);
    SDL_FreeSurface(font_surface_press_enter);
    SDL_FreeSurface(title_image);
    SDL_FreeSurface(enter_arrow);
    SDL_FreeSurface(font_surface_start);
    SDL_FreeSurface(font_surface_quit);
    Mix_CloseAudio();
    SDL_DestroyWindow(basic_window);
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}