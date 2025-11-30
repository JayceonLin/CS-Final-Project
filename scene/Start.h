#ifndef Start_H_INCLUDED
#define Start_H_INCLUDED

class StartScreen
{
    public:
        StartScreen();
        void init();
        void update();
        void draw();

        bool isStarted() const  {return start_pressed;}
    private:
        bool start_pressed = false;
};









#endif
