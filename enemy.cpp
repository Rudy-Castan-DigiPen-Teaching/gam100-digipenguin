/*--------------------------------------------------------------
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
    doodle::push_settings();
    doodle::set_fill_color(doodle::HexColor{ enemy_color });
    doodle::draw_rectangle(this->enemy_x, this->enemy_y, this->enemy_width, this->enemy_height);
    doodle::pop_settings();
    doodle::push_settings();
    doodle::no_fill();
    doodle::draw_rectangle(this->enemy_x - enemy_sense, this->enemy_y - enemy_sense,  + this->enemy_width + this->enemy_sense*2,this->enemy_height + this->enemy_sense*2);
    doodle::pop_settings();

}

void Enemy::get_player() 
{
    get_player_x = player->x;
    get_player_y = player->y;
    get_player_width = player->width;
    get_player_height = player->height;


}


//void Enemy::get_shot()
//{
//    get_bullet_x = shot->x;
//    get_bullet_y = shot->y;
//}


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


void Enemy::player_spot()
{
    if (this->enemy_x - this->enemy_sense <= this->get_player_x + get_player_width && this->enemy_x + this->enemy_width + this->enemy_sense >= this->get_player_x)
    {
         if (this->enemy_y + this->enemy_height + this->enemy_sense >= get_player_y && this->enemy_y - enemy_sense <= get_player_y + get_player_height)
         {
        this->player_spoted = true;
         }
    }
    else
    {
        this->player_spoted = false;
    }
}


void Enemy::apply_physics()
{

   
    if (this->enemy_alive == true)
    {

        // Rotate
        if (this->player_spoted == false)
        {
            this->enemy_x += enemy_speed * this->x_direction * doodle::DeltaTime;

            if ((this->enemy_x += enemy_speed * this->x_direction) >= ENM_ROTATE_MAX)
            {
                x_direction = -1;
            }
            if ((this->enemy_x += enemy_speed * this->x_direction) <= ENM_ROTATE_MIN)
            {
                x_direction = 1;
            }
        }

       /* follow player*/


        if (this->player_spoted == true)
        {
             //player left
            if (this->enemy_x >= get_player_x && this->enemy_x - enemy_sense <= get_player_x + get_player_width)
            {
                this->enemy_x -= enemy_speed + 1;
            }   
            //player up
            if (this->enemy_y + enemy_height / 2 <= get_player_y + get_player_height / 2 && this->enemy_y + enemy_height + enemy_sense >= get_player_y)
            {
                this->enemy_y += enemy_speed + 1;
            }
            //player right
            if (this->enemy_x <= get_player_x && this->enemy_x + enemy_width + enemy_sense >= get_player_x)
            {
                this->enemy_x += enemy_speed + 1;
            }
            //player down
            if (this->enemy_y + enemy_height/2 >= get_player_y + get_player_height/2 && this->enemy_y - enemy_sense <= get_player_y + get_player_height)
            {
                this->enemy_y -= enemy_speed + 1;
            }
        }

        //this->enemy_x = this->player->x;
        //this->enemy_y = this->player->y;

        //check hitbox

  /*      if ((doodle::get_mouse_x() > this->enemy_x) && (doodle::get_mouse_x() < enemy_x + this->enemy_width) && (doodle::get_mouse_y() > this->enemy_y) && (doodle::get_mouse_y() < this->enemy_y + this->enemy_height))
        {
            this->enemy_HP--;
        }*/

        //hit by bullet
    //    while (enemy_alive == true)
    //{
    //    if ((get_bullet_x > this->enemy_x) && (get_bullet_x < enemy_x + this->enemy_width) && (get_bullet_y > this->enemy_y) && (get_bullet_y < this->enemy_y + this->enemy_height))
    //    {
    //        this->enemy_HP--;
    //    }

    //    if (enemy_HP <= 0)
    //    {
    //        break;
    //    }
    //}



    //enemy defeat
        if (this->enemy_alive == false)
        {
            //doodle::set_fill_color(doodle::HexColor{ defeat_enemy_color });
            /*doodle::no_fill();*/
            //doodle::no_outline();
        }
    }
}


