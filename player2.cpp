#include <doodle/doodle.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace doodle;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


//constexpr int direction_left = -1;
//constexpr int direction_down = -1;
//constexpr int direction_none = 0;
//constexpr int direction_right = 1;
//constexpr int direction_up = 1;
constexpr double gravity = 9.8;



constexpr double player_jump_height = 5;
constexpr double player_speed = 5;

struct Player {
    double x = 0;
    double y = 0;
    int width = 25;
    int height = 50;
    double y_velocity = 0;
    bool standing = false;

    void draw() {
        set_fill_color(HexColor{ 0x2743D2ff });
        draw_rectangle(x, y, width, height);
    }



    void jump() {
        if (standing == true) {
            y_velocity -= player_jump_height;
            standing = false;
        }
    }

    

    void update() {

        //block height value

        if (y > Height - height * 2) {
            standing = true;
        }



        //key setting

  /*      if (KeyIsPressed == true) {


            switch (Key) {
               
            case KeyboardButtons::Left:
                x -= player_speed;
                break;
            case KeyboardButtons::Right:
                x += player_speed;
                break;
     
            }
        }*/

        if (KeyIsPressed == true && Key == KeyboardButtons::Right) {
          
            if (KeyIsPressed == true && Key == KeyboardButtons::Z) {
                x += player_speed;
                jump();
            }
     
            else {
                x += player_speed;
            }
        }

        if (KeyIsPressed == true && Key == KeyboardButtons::Left) {

            if (KeyIsPressed == true && Key == KeyboardButtons::Z) {
                x -= player_speed;
                jump();
            }

            else {
                x -= player_speed;
            }
        }

        if (KeyIsPressed == true && Key == KeyboardButtons::Z) {
            jump();
        }

        // gravity works

        if (standing == false) {
            y_velocity += gravity * DeltaTime;
            y += y_velocity;
        }
        else {
            y_velocity = 0;
        }
    }
};

int main() {
    create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    set_frame_of_reference(FrameOfReference::LeftHanded_OriginTopLeft);
    set_outline_width(3.0);
    no_fill();
    set_outline_color(0);

    Player* player = new Player{ double(Width / 2), double(Height / 2) };


    while (!is_window_closed()) {
        update_window();
        clear_background(255);

        player->standing = false;
        player->update();
        player->draw();

    }



    return 0;
}