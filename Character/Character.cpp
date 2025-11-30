#include "Character.h"
#include "../data/DataCenter.h"
#include "../data/GIFCenter.h"
#include "../data/ImageCenter.h"
#include "../Level.h"
#include "../shapes/Point.h"
#include "../shapes/Rectangle.h"
#include "../Utils.h"
#include <allegro5/allegro_primitives.h>

using namespace std;

namespace CharacterSetting {
	static constexpr char character_imgs_root_path[40] = {
		"./assets/gif/Hero/dragonite_"
	};
	static constexpr char dir_path_postfix[][10] = {
		"left", "right", "front", "back"
	};
}

void Character::init()
{
	for(int i=0;i<static_cast<int>(CharacterState::CharacterState_MAX);i++)
	{
		gitfPath[static_cast<CharacterState>(i)]=string(CharacterSetting::character_imgs_root_path)+string(CharacterSetting::dir_path_postfix[i])+".gif";
	}
	GIFCenter *GC=GIFCenter::get_instance();
	ALGIF_ANIMATION *gif=GC->get(gitfPath[state]);
	DataCenter *DC=DataCenter::get_instance();
	int wh=DC->window_height;
	int ww=DC->window_width;
	w=gif->width;
	h=gif->height;
	shape.reset(new Rectangle{
		ww /2.0 , wh / 2.0,
		ww / 2.0 + w,
		wh / 2.0 + h});
}

void Character::update()
{
	DataCenter *DC=DataCenter::get_instance();

	//Keep character inside the game field
	if(shape->center_x()<0)
		shape->update_center_x(0);
	if(shape->center_x()>DC->window_width)
		shape->update_center_x(DC->window_width);
	if(shape->center_y()<0)
		shape->update_center_y(0);
	if(shape->center_y()>DC->window_height)
		shape->update_center_y(DC->window_height);
	if(DC->key_state[ALLEGRO_KEY_A])
	{
		state=CharacterState::LEFT;
		shape->update_center_x(shape->center_x()-speed);
	}
	if(DC->key_state[ALLEGRO_KEY_D])
	{
		state=CharacterState::RIGHT;
		shape->update_center_x(shape->center_x()+speed);
	}
	if(DC->key_state[ALLEGRO_KEY_W])
	{
		state=CharacterState::Back;
		shape->update_center_y(shape->center_y()-speed);
	}
	if(DC->key_state[ALLEGRO_KEY_S])
	{
		state=CharacterState::Front;
		shape->update_center_y(shape->center_y()+speed);
	}
}
void Character::draw()
{
	GIFCenter *GC=GIFCenter::get_instance();
	ALGIF_ANIMATION *gif=GC->get(gitfPath[state]);
	algif_draw_gif(gif,
				   shape->center_x()-w/2,
				   shape->center_y()-h/2,0);
}
