#include "bed.h"
#include "../data/DataCenter.h"
#include "../Level.h"
#include "../Game.h"
#include "../data/ImageCenter.h"
#include "../Character/Character.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

namespace BedSetting {
    // bed image paths
    static constexpr char bed_imgs_root_path[static_cast<int>(BedState::BedState_MAX)][40] = {
        "./assets/image/bedt.png",
        "./assets/image/bed_touched.png"
    };
}

void Bed::init() {
    for(int i=0;i<static_cast<int>(BedState::BedState_MAX);i++)
    {
        imgPath[static_cast<BedState>(i)]=string(BedSetting::bed_imgs_root_path[i]);
    }
    ImageCenter *IC = ImageCenter::get_instance();
    DataCenter *DC = DataCenter::get_instance();
    ALLEGRO_BITMAP *img = IC->get(imgPath[state]);
    int wh=DC->window_height;
    int ww=DC->window_width;
    w=al_get_bitmap_width(img);
    h=al_get_bitmap_height(img);
    shape.reset(new Rectangle{
        ww-w-300,wh-h-150,
        ww-300+w,
        wh-150+h});
}

void Bed::draw() {
    ImageCenter *IC = ImageCenter::get_instance();
    ALLEGRO_BITMAP *img = IC->get(imgPath[state]);
    DataCenter *DC = DataCenter::get_instance();
    al_draw_bitmap(img,shape->center_x()-(w/2),shape->center_y()-(h/2) ,0);
}

bool Bed::is_player_touching() {
    DataCenter *DC = DataCenter::get_instance();
    Character* character=DC->character;
    
    return shape->overlap(*(character->shape));
}
void Bed::interact() {
    
    DataCenter *DC = DataCenter::get_instance();

    // 是否碰到床？
    if (is_player_touching())
        state = BedState::touched;
    else {
        state = BedState::untouched;
        showing_prompt = false;    // 一離開就關掉視窗
        return;
    }
}


