/*--------------------------------------------------------------
All content © 2022 DigiPen (USA) Corporation, all rights reserved.
File Name: enemy.cpp
Project: GAM100
Author: Minchan Cho
-----------------------------------------------------------------*/

#include "enemy.h"
#include "player.h"


void Enemy::draw()
{
    doodle::draw_rectangle(this->enemy_x, this->enemy_y, this->enemy_width, this->enemy_height);
    doodle::set_fill_color(doodle::HexColor{ enemy_color });
}

//void Enemy::get_player(Player* player) 
//{
//    player->x = _x;
//    player->y;
//}
//void Shot::get_shot(Shot* shot)
//{
//    shot->x;
//    shot->y;
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

void Enemy::apply_physics()
{


    if (!doodle::KeyIsPressed && doodle::Key == doodle::KeyboardButtons::H)
    {
        this->enemy_HP--;
    }//HP test



    if (this->enemy_alive == true)
    {
        this->enemy_x += enemy_speed * this->enemy_x_velocity * doodle::DeltaTime;
        if ((this->enemy_x += enemy_speed * this->enemy_x_velocity) >= ENM_ROTATE_MAX)
        {
            this->enemy_x_velocity = -1;
        }
        if ((this->enemy_x += enemy_speed * this->enemy_x_velocity) <= ENM_ROTATE_MIN)
        {
            this->enemy_x_velocity = 1;
        }



        /*if ((bullet_x > this->enemy_x) && (bullet_x < enemy_x + this->enemy_width) && (bullet_y > this->enemy_y) && (bullet_y < this->enemy_y + this->enemy_height))
        {
            this->enemy_HP--;
        }*/
    }
    else if (this->enemy_alive == false)
    {
        //doodle::set_fill_color(doodle::HexColor{ defeat_enemy_color });
        doodle::no_fill();
        //doodle::no_outline();
    }
}


