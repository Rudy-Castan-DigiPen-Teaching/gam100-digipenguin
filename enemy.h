#ifndef ENEMY_H
#define ENEMY_H

#include <doodle/doodle.hpp>
#include <string>
#include <cctype>

#define WINDOW_TITLE "enemy test"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 700
#define ENM_ROTATE_MAX doodle::Width - 100
#define ENM_ROTATE_MIN doodle::Width / 2


int bullet_x = 0;
int bullet_y = 0;
constexpr int enemy_color = 0xdf4b40ff;
constexpr int defeat_enemy_color = 0xdffffffff;
constexpr int enemy_speed = 2;



struct Enemy
{
    int enemy_x = WINDOW_WIDTH / 2;
    int enemy_y = WINDOW_HEIGHT / 2;
    int enemy_width = 100;
    int enemy_height = 200;
    int enemy_x_velocity = 1;
    int enemy_HP = 10;
    bool enemy_alive = false;

    void draw();
    void check_alive();
    void apply_physics();
};

#endif