/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: enemy.h
Project: GAM100
Author: Minchan Cho
-----------------------------------------------------------------*/

#ifndef ENEMY_H
#define ENEMY_H

#include <doodle/doodle.hpp>
#include <string>
#include <cctype>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define ENM_ROTATE_MAX doodle::Width - 100
#define ENM_ROTATE_MIN doodle::Width / 2


//int bullet_x = 0;
//int bullet_y = 0;
//constexpr int defeat_enemy_color = 0xdffffffff;

class Player;
class Shot;

class Enemy
{
    int enemy_color = 0xdf4b40ff;
    double enemy_x = WINDOW_WIDTH / 3;
    double enemy_y = 25;
    double enemy_width = 25;
    double enemy_height = 25;
    double enemy_sense = 100;
    double x_direction = 1;
    double enemy_HP = 10;
    //int get_bullet_x ;
    //int get_bullet_y;
    double get_player_x;
    double get_player_y;
    double get_player_width;
    double get_player_height;
    bool enemy_alive = false;
    bool player_spoted = false;
    double enemy_speed = 1.3;

public:

    Player* player = nullptr;

    void draw();
    void check_alive();
    void apply_physics();
    void get_player();
    void player_spot();
 /*   void get_shot();*/



};

#endif