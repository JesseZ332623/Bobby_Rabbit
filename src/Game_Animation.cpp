#include "./Game_Animation.h"

/*加载所有动画的 texture 和 surface*/
void Load_Bobby_Animation(Animation *animation, SDL_Renderer *render)
{
    /*[0] 向左行走 的 texture 和 surface*/
    animation->left_surface = IMG_Load("img\\bobby_left.png");
    animation->left_texture = SDL_CreateTextureFromSurface(render, animation->left_surface);
    // SDL_FreeSurface(animation->left_surface);

    /*[1] 向右行走 的 texture 和 surface*/
    animation->left_surface = IMG_Load("img\\bobby_right.png");
    animation->right_texture = SDL_CreateTextureFromSurface(render, animation->left_surface);
    // SDL_FreeSurface(animation->left_surface);

    /*[2] 向上行走 的 texture 和 surface*/
    animation->up_surface = IMG_Load("img\\bobby_up.png");
    animation->up_texture = SDL_CreateTextureFromSurface(render, animation->up_surface);
    // SDL_FreeSurface(animation->up_surface);

    /*[3] 向下行走 的 texture 和 surface*/
    animation->down_surface = IMG_Load("img\\bobby_down.png");
    animation->down_texture = SDL_CreateTextureFromSurface(render, animation->down_surface);
    // SDL_FreeSurface(animation->down_surface);

    /*[4] 死亡 的 texture 和 surface*/
    animation->death_surface = IMG_Load("img\\bobby_death.png");
    animation->death_texture = SDL_CreateTextureFromSurface(render, animation->death_surface);
    // SDL_FreeSurface(animation->death_surface);

    /*[5] 消失 的 texture 和 surface*/
    animation->fade_surface = IMG_Load("img\\bobby_fade.png");
    animation->fade_texture = SDL_CreateTextureFromSurface(render, animation->fade_surface);

    /*[6] 不耐烦的等待 的 texture 和 surface*/
    animation->wait_surface = IMG_Load("img\\bobby_idle.png");
    animation->wait_texture = SDL_CreateTextureFromSurface(render, animation->wait_surface);
}

/*设置 不耐烦的等待 动画的相关 rect 参数*/
void Set_Wait_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 108 / 3; // 36
    int block_height = 50;

    frame_rect->wait_rect_frame_1.x = 0;
    frame_rect->wait_rect_frame_1.y = 0;
    frame_rect->wait_rect_frame_1.w = block_width;
    frame_rect->wait_rect_frame_1.h = block_height;

    frame_rect->wait_rect_frame_2.x = block_width;
    frame_rect->wait_rect_frame_2.y = 0;
    frame_rect->wait_rect_frame_2.w = block_width;
    frame_rect->wait_rect_frame_2.h = block_height;

    frame_rect->wait_rect_frame_3.x = block_width * 2;
    frame_rect->wait_rect_frame_3.y = 0;
    frame_rect->wait_rect_frame_3.w = block_width;
    frame_rect->wait_rect_frame_3.h = block_height;

    frame_rect->wait_dest_rect.x = 35;
    frame_rect->wait_dest_rect.y = 320 - block_height;
    frame_rect->wait_dest_rect.w = block_width;
    frame_rect->wait_dest_rect.h = block_height;
}

/*设置 向左行走 动画的相关 rect 参数*/
void Set_Left_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 36; // 288 / 8
    int block_height = 50;
    int frame = 8;

    for (int cur_frame = 0; cur_frame < frame; ++cur_frame)
    {
        frame_rect->u_d_l_r_rect_frames[cur_frame].x = cur_frame * block_width;
        frame_rect->u_d_l_r_rect_frames[cur_frame].y = 0;
        frame_rect->u_d_l_r_rect_frames[cur_frame].h = block_height;
        frame_rect->u_d_l_r_rect_frames[cur_frame].w = block_width;
    }
    frame_rect->left_dest_rect.x = 204;
    frame_rect->left_dest_rect.y = 270;
    frame_rect->left_dest_rect.w = block_width;
    frame_rect->left_dest_rect.h = block_height;
}

/*设置 向右行走 动画的相关 rect 参数*/
void Set_Right_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 36; // 288 / 8
    int block_height = 50;
    int frame = 8;

    for (int cur_frame = 0; cur_frame < frame; ++cur_frame)
    {
        frame_rect->u_d_l_r_rect_frames[cur_frame].x = cur_frame * block_width;
        frame_rect->u_d_l_r_rect_frames[cur_frame].y = 0;
        frame_rect->u_d_l_r_rect_frames[cur_frame].h = block_height;
        frame_rect->u_d_l_r_rect_frames[cur_frame].w = block_width;
    }
    frame_rect->right_dest_rect.x = 0;
    frame_rect->right_dest_rect.y = 270;
    frame_rect->right_dest_rect.w = block_width;
    frame_rect->right_dest_rect.h = block_height;
}

/*设置 向上行走 动画的相关 rect 参数*/
void Set_Up_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 36; // 288 / 8
    int block_height = 50;
    int frame = 8;

    for (int cur_frame = 0; cur_frame < frame; ++cur_frame)
    {
        frame_rect->u_d_l_r_rect_frames[cur_frame].x = cur_frame * block_width;
        frame_rect->u_d_l_r_rect_frames[cur_frame].y = 0;
        frame_rect->u_d_l_r_rect_frames[cur_frame].h = block_height;
        frame_rect->u_d_l_r_rect_frames[cur_frame].w = block_width;
    }
    frame_rect->up_dest_rect.x = 0;
    frame_rect->up_dest_rect.y = 0;
    frame_rect->up_dest_rect.w = block_width;
    frame_rect->up_dest_rect.h = block_height;
}

/*设置 向下走 动画的相关 rect 参数*/
void Set_Down_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 36; // 288 / 8
    int block_height = 50;
    int frame = 8;

    for (int cur_frame = 0; cur_frame < frame; ++cur_frame)
    {
        frame_rect->u_d_l_r_rect_frames[cur_frame].x = cur_frame * block_width;
        frame_rect->u_d_l_r_rect_frames[cur_frame].y = 0;
        frame_rect->u_d_l_r_rect_frames[cur_frame].h = block_height;
        frame_rect->u_d_l_r_rect_frames[cur_frame].w = block_width;
    }
    frame_rect->down_dest_rect.x = 400;
    frame_rect->down_dest_rect.y = 0;
    frame_rect->down_dest_rect.w = block_width;
    frame_rect->down_dest_rect.h = block_height;
}

/*设置 死亡 动画的相关 rect 参数*/
void Set_Death_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 54;
    int block_height = 352;
    int frame = 8;

    for (int cur_frame = 0; cur_frame < frame; ++cur_frame)
    {
        frame_rect->death_rect[cur_frame].x = cur_frame * block_width;
        frame_rect->death_rect[cur_frame].y = 0;
        frame_rect->death_rect[cur_frame].h = block_height;
        frame_rect->death_rect[cur_frame].w = block_width;
    }

    frame_rect->death_dest_rect.x = 250;
    frame_rect->death_dest_rect.y = 300;
    frame_rect->death_dest_rect.h = block_height;
    frame_rect->death_dest_rect.y = block_width;
}

/*设置 消失 动画的相关 rect 参数*/
void Set_Fade_Frame_Format(Frame_Rect *frame_rect)
{
    int block_width = 324 / 9;
    int block_height = 50;
    int frame = 9;

    for (int cur_frame = 0; cur_frame < frame; ++cur_frame)
    {
        frame_rect->death_rect[cur_frame].x = cur_frame * block_width;
        frame_rect->death_rect[cur_frame].y = 0;
        frame_rect->death_rect[cur_frame].h = block_height;
        frame_rect->death_rect[cur_frame].w = block_width;
    }

    frame_rect->fade_dest_rect.x = 475;
    frame_rect->fade_dest_rect.y = 600;
    frame_rect->fade_dest_rect.h = block_height;
    frame_rect->fade_dest_rect.w = block_width;
}

#if false
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *basic_window = SDL_CreateWindow("Bobby Rabbit",
                                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                                800, 800,
                                                SDL_WINDOW_SHOWN);
    SDL_SetWindowInputFocus(basic_window);
    SDL_Renderer *render = SDL_CreateRenderer(basic_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Animation animations;
    Frame_Rect frames;

    SDL_Event events;

    SDL_Rect animations_pos = {0 , 0, 36, 50};


    Load_Bobby_Animation(&animations, render);
    Set_Wait_Frame_Format(&frames);
    Set_Right_Frame_Format(&frames);
    Set_Left_Frame_Format(&frames);
    Set_Up_Frame_Format(&frames);
    Set_Down_Frame_Format(&frames);
    Set_Death_Frame_Format(&frames);
    Set_Fade_Frame_Format(&frames);

    bool if_quit = false;

    bool if_left_walk = false;
    bool if_right_walk = false;
    bool if_up_walk = false;
    bool if_down_walk = false;

    int current_frame_left = 0;
    int current_frame_right = 0;
    int current_frame_up = 0;
    int current_frame_down = 0;

    SDL_PumpEvents();

    frames.up_dest_rect.x = frames.up_dest_rect.y = 0;
    frames.down_dest_rect.x = frames.down_dest_rect.y = 0;
    frames.left_dest_rect.x = frames.left_dest_rect.y = 0;
    frames.right_dest_rect.x = frames.right_dest_rect.y = 0;

#if true
    while (!if_quit)
    {
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_KEYDOWN)
            {
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                    if_up_walk = true;
                    break;

                case SDL_SCANCODE_A:
                    if_left_walk = true;
                    break;

                case SDL_SCANCODE_S:
                    if_down_walk = true;
                    break;

                case SDL_SCANCODE_D:
                    if_right_walk = true;
                    break;

                default:
                    break;
                }
            }
            else if (events.type == SDL_KEYUP)
            {
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                    if_up_walk = false;
                    break;

                case SDL_SCANCODE_A:
                    if_left_walk = false;
                    break;

                case SDL_SCANCODE_S:
                    if_down_walk = false;
                    break;

                case SDL_SCANCODE_D:
                    if_right_walk = false;
                    break;
                }
            }
            else if (events.type == SDL_QUIT)
            {
                SDL_Log("Quit\n");
                if_quit = true;
            }
        }
        if (if_right_walk)
        {
            for (int i = 0; i < 8; i++)
            {
                SDL_RenderCopy(render, animations.right_texture, &frames.u_d_l_r_rect_frames[i], &animations_pos);
                SDL_RenderPresent(render);
                SDL_RenderClear(render);
                animations_pos.x += 2;
                SDL_Delay(15);
            } 
        }
        else if (if_left_walk)
        {
            for (int i = 0; i < 8; i++)
            {

                SDL_RenderCopy(render, animations.left_texture, &frames.u_d_l_r_rect_frames[i], &animations_pos);
                SDL_RenderPresent(render);
                SDL_RenderClear(render);
                animations_pos.x -= 2;
                SDL_Delay(15);
            } 
        }
        else if (if_up_walk)
        {
            for (int i = 0; i < 8; i++)
            {
                SDL_RenderCopy(render, animations.up_texture, &frames.u_d_l_r_rect_frames[i], &animations_pos);
                SDL_RenderPresent(render);
                SDL_RenderClear(render);
                animations_pos.y -= 2;
                SDL_Delay(15);
            } 
        }
        else if (if_down_walk)
        {
            for (int i = 0; i < 8; i++)
            {
                SDL_RenderCopy(render, animations.down_texture, &frames.u_d_l_r_rect_frames[i], &animations_pos);
                SDL_RenderPresent(render);
                SDL_RenderClear(render);
                animations_pos.y += 2;
                SDL_Delay(15);
            }         
        }
    }
#endif

    SDL_Quit();
    return EXIT_SUCCESS;
}
#endif
