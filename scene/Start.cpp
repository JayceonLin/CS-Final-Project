#include "Start.h"
#include "../data/DataCenter.h"
#include "../data/ImageCenter.h"
#include "../shapes/Rectangle.h"
#include "../data/FontCenter.h"
#include <allegro5/allegro_primitives.h>   
#include <allegro5/allegro_font.h>

StartScreen::StartScreen()
{
    start_pressed = false;
};

void StartScreen::init()
{
    start_pressed = false;
};

void StartScreen::update()
{
    DataCenter *DC = DataCenter::get_instance();
    const Point &mouse = DC->mouse;

    // check if start button is pressed
    int button_x = DC->window_width / 2 - 100;
    int button_y = DC->window_height / 2 - 25;
    int button_w = 200;
    int button_h = 50;

    if(mouse.overlap(Rectangle{button_x, button_y, button_x + button_w, button_y + button_h})) {
        // click mouse left button
        if(DC->mouse_state[1] && !DC->prev_mouse_state[1]) {
            start_pressed = true;
        }
    }
}

void StartScreen::draw()
{
    DataCenter *DC = DataCenter::get_instance();
    FontCenter *FC = FontCenter::get_instance();

    // draw start button
    int button_x = DC->window_width / 2 - 100;
    int button_y = DC->window_height / 2 - 25;
    int button_w = 200;
    int button_h = 50;

    al_draw_filled_rectangle(button_x, button_y, button_x + button_w, button_y + button_h, al_map_rgb(0, 128, 255));
    al_draw_rectangle(button_x, button_y, button_x + button_w, button_y + button_h, al_map_rgb(255, 255, 255), 2);
    al_draw_text(
        FC->courier_new[FontSize::LARGE], al_map_rgb(255, 255, 255),
        DC->window_width / 2, DC->window_height / 2,
        ALLEGRO_ALIGN_CENTRE, "START");
}