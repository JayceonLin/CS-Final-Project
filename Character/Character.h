#ifndef Character_H_INCLUDED
#define Character_H_INCLUDED

#include "../Object.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Point.h"
#include <vector>
#include <queue>
#include <map>

// fixed settings
enum class CharacterState {
	LEFT, RIGHT, Front, Back,CharacterState_MAX
};

/**
 * @brief The class of a character.
 * @details Character inherits Object and takes Rectangle as its hit box.
 */
class Character : public Object
{
	public:
		void init();
		void update();
		void draw() override;
	private:
		CharacterState state=CharacterState::Front;
		double speed=5;
		std::map<CharacterState,std::string> gitfPath;
		int w,h;
};

#endif
