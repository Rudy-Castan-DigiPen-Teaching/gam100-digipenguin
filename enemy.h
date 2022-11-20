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
    int enemy_x = WINDOW_WIDTH / 3;
    int enemy_y = 25;
    int enemy_width = 25;
    int enemy_height = 50;
    int enemy_sense = 100;
    int enemy_HP = 10;
    int get_bullet_x ;
    int get_bullet_y;
    int get_player_x;
    int get_player_y;
    bool enemy_alive = false;
    int enemy_speed = 1;
    //class Shot* m_pA_shot;

public:

    Player* player = nullptr;

    void draw();
    void check_alive();
    void apply_physics();
    void get_player();
 /*   void get_shot();*/



};

#endif