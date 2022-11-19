﻿/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: enemy.cpp
Project: GAM100
Author: Minchan Cho
-----------------------------------------------------------------*/
#include <iostream>
#include "enemy.h"
#include "player.h"
#include "shot.h"


void Enemy::draw()
{
    doodle::draw_rectangle(this->enemy_x, this->enemy_y, this->enemy_width, this->enemy_height);
    doodle::set_fill_color(doodle::HexColor{ enemy_color });
    doodle::push_settings();
    doodle::no_fill();
    doodle::draw_rectangle(this->enemy_x - 100, this->enemy_y - 87, 225, 225);
    doodle::pop_settings();
}

void Enemy::get_player() 
{
    get_player_x = player->x;
    get_player_y = player->y;


}


void Enemy::get_shot(Shot* shot)
{
    get_bullet_x = shot->x;
    get_bullet_y = shot->y;
}


//void Enemy::Init(class Shot* shot)
//{
//    m_pA_shot = shot;
//    m_pA_shot->x;
//    m_pA_shot->y; 
//
//    if ((m_pA_shot->x > this->enemy_x) && (m_pA_shot->x < enemy_x + this->enemy_width) && (m_pA_shot->y > this->enemy_y) && (m_pA_shot->y < this->enemy_y + this->enemy_height))
//    {
//        this->enemy_HP--;
//    }
//}


void Enemy::check_alive()
{
    if (this->enemy_HP > 0)
    {
        this->enemy_alive = true;
    }
    else
    {
        this->enemy_alive = false;
    }
}

void Enemy::apply_physics()
{
    int check_x_sense = this->enemy_x + enemy_sense;
    int check_minuse_x_sense = this->enemy_x - enemy_sense;



    if (!doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::H)
    {
        this->enemy_HP--;
    }//HP test


    // Rotate
    if (this->enemy_alive == true)
    {

        //this->enemy_x += enemy_speed * this->x_velocity;
        //this->enemy_y += enemy_speed * this->y_velocity;

        //if (this->enemy_x >= ENM_ROTATE_MAX)
        //{
        //    enemy_x -= enemy_speed * this->x_velocity;
        //}
        //else if (this->enemy_x <= ENM_ROTATE_MIN)
        //{
        //    enemy_x += enemy_speed * this->x_velocity;
        //}


       /* follow player*/

        if (this->enemy_x >= get_player_x && this-> enemy_x - enemy_sense <= get_player_x + 25)
        {
            enemy_x -= enemy_speed;
        }
        if (this->enemy_x <= get_player_x && this-> enemy_x +enemy_width + enemy_sense >= get_player_x)
        {
            enemy_x += enemy_speed;
        }

        //if(get_player_x <= this->enemy_x - enemy_sense)
        //{
        //    this->x_velocity = -1;
        //}
        //if (get_player_x >= enemy_x + this->enemy_width + enemy_sense)
        //{
        //    this->x_velocity = 1;
        //}


        //this->enemy_x = this->player->x;
        //this->enemy_y = this->player->y;


        //if (get_player_y > this->enemy_y - enemy_sense)
        //{
        //    this->y_velocity = -1;
        //}
        //if(get_player_y < this->enemy_y + this->enemy_height + enemy_sense)
        //{
        //    this->y_velocity = 1;
        //}


        //check hitbox
        // 
        if ((doodle::get_mouse_x() > this->enemy_x) && (doodle::get_mouse_x() < enemy_x + this->enemy_width) && (doodle::get_mouse_y() > this->enemy_y) && (doodle::get_mouse_y() < this->enemy_y + this->enemy_height))
        {
            this->enemy_HP--;
        }

        //hit by bullet
        if ((get_bullet_x > this->enemy_x) && (get_bullet_x < enemy_x + this->enemy_width) && (get_bullet_y > this->enemy_y) && (get_bullet_y < this->enemy_y + this->enemy_height))
        {
            this->enemy_HP--;
        }

    }



    //enemy defeat
    if (this->enemy_alive == false)
    {
        //doodle::set_fill_color(doodle::HexColor{ defeat_enemy_color });
        doodle::no_fill();
        //doodle::no_outline();
    }
}


