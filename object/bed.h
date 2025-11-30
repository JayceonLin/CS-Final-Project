#ifndef BED_H_INCLUDED
#define BED_H_INCLUDED

#include "../shapes/Rectangle.h"
#include "../Object.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <map>
#include <string>

enum class BedState {
	untouched,touched,BedState_MAX
};

class Bed: public Object
{
    public:
        void init();
        void draw();
        bool is_player_touching();
        void interact();
    private:
        int x,y;
        int w,h;
        bool showing_prompt = false;
        BedState state=BedState::untouched;
        std::map<BedState,std::string> imgPath;
};

#endif