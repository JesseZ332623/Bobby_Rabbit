#include "./Game_Animation.h"

/*加载所有动画的 texture 和 surface*/
void  Load_Bobby_Animation(Animation *animation, SDL_Renderer *render)
{
    /*[0] 向左行走 的 texture 和 surface*/
    animation->left_surface = IMG_Load("img\\bobby_left.png");
    animation->left_texture =  SDL_CreateTextureFromSurface(render, animation->left_surface);
    //SDL_FreeSurface(animation->left_surface);

    /*[1] 向右行走 的 texture 和 surface*/
    animation->left_surface = IMG_Load("img\\bobby_right.png");
    animation->right_texture = SDL_CreateTextureFromSurface(render, animation->left_surface);
    //SDL_FreeSurface(animation->left_surface);

    /*[2] 向上行走 的 texture 和 surface*/
    animation->up_surface = IMG_Load("img\\bobby_up.png");
    animation->up_texture = SDL_CreateTextureFromSurface(render, animation->up_surface);
    //SDL_FreeSurface(animation->up_surface);

    /*[3] 向下行走 的 texture 和 surface*/
    animation->down_surface = IMG_Load("img\\bobby_down.png");
    animation->down_texture = SDL_CreateTextureFromSurface(render, animation->down_surface);
    //SDL_FreeSurface(animation->down_surface);

    /*[4] 死亡 的 texture 和 surface*/
    animation->death_surface = IMG_Load("img\\bobby_death.png");
    animation->death_texture = SDL_CreateTextureFromSurface(render, animation->death_surface);
    //SDL_FreeSurface(animation->death_surface);

    /*[5] 消失 的 texture 和 surface*/
    animation->fade_surface = IMG_Load("img\\bobby_fade.png");
    animation->fade_texture = SDL_CreateTextureFromSurface(render, animation->fade_surface);

    /*[6] 不耐烦的等待 的 texture 和 surface*/
    animation->wait_surface = IMG_Load("img\\bobby_idle.png");
    animation->wait_texture = SDL_CreateTextureFromSurface(render, animation->wait_surface);
}

void Get_Wait_Frame_Format(Frame_Rect *frame_rect)
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

    frame_rect->wait_dest_rect.x = 25;
    frame_rect->wait_dest_rect.y = 320 - block_height;
    frame_rect->wait_dest_rect.w = block_width;
    frame_rect->wait_dest_rect.h = block_height;
}



#if false
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *basic_window = SDL_CreateWindow("Bobby Rabbit",
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    500, 500,
                                    SDL_WINDOW_SHOWN);
    SDL_Renderer *render = SDL_CreateRenderer(basic_window, -1, SDL_RENDERER_ACCELERATED);

    Animation animations;
    int blockWidth = 108 / 3; // 36
    int blockHeight = 50;

    // 定义3个裁切区域
    SDL_Rect srcRect1;
    srcRect1.x = 0; 
    srcRect1.y = 0;
    srcRect1.w = blockWidth;
    srcRect1.h = blockHeight;

    SDL_Rect srcRect2;
    srcRect2.x = blockWidth; 
    srcRect2.y = 0;
    srcRect2.w = blockWidth;
    srcRect2.h = blockHeight;

    SDL_Rect srcRect3;
    srcRect3.x = blockWidth * 2;
    srcRect3.y = 0;
    srcRect3.w = blockWidth;  
    srcRect3.h = blockHeight;

    // 定义目标渲染区域
    SDL_Rect dstRect;
    dstRect.x = 100;
    dstRect.y = 100;
    dstRect.w = blockWidth;
    dstRect.h = blockHeight;

    SDL_Event events;

    Load_Bobby_Animation(&animations, render);

    bool if_quit = false;
    int current_frame = 0;

    while (!if_quit)
    {
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
            {
                if_quit = true;
            } 
        }
        //SDL_RenderClear(render);
        current_frame++;
        switch (current_frame)
        {
        case 1:
            SDL_RenderCopy(render, animations.wait_texture, &srcRect1, &dstRect);
            SDL_RenderPresent(render);
            SDL_RenderClear(render);
            SDL_Delay(25);
            continue;
        case 2:
            SDL_RenderCopy(render, animations.wait_texture, &srcRect2, &dstRect);
            SDL_RenderPresent(render);
            SDL_RenderClear(render);
            SDL_Delay(25);
            continue;
        case 3:
            SDL_RenderCopy(render, animations.wait_texture, &srcRect3, &dstRect);
            SDL_RenderPresent(render);
            SDL_RenderClear(render);
            SDL_Delay(45);
            continue;
        default:
            current_frame = 0;
            continue;
        }
       
        
        
    }
    
    SDL_Quit();


    return EXIT_SUCCESS;
}
#endif




