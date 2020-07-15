#include "MapaAQP.h"
#include <allegro.h>

MapaAQP::MapaAQP()
{
}

void MapaAQP::init(){
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if (depth == 0) depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 480, 510, 0, 0);
    if (res != 0){
        allegro_message(allegro_error);
        exit(-1);
    }
    install_timer();
    install_keyboard();
    install_mouse();
}

void MapaAQP::deinit(){
    clear_keybuf();
}
