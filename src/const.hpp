#ifndef CONST_H
#define CONST_H

#define GAME_NAME "Space"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define PLAYER_WIDTH 50.f
#define PLAYER_HEIGHT 20.f
#define PLAYER_X_CENTER (PLAYER_WIDTH / 2.f)
#define PLAYER_Y_CENTER (PLAYER_HEIGHT / 2.f)

#define BULLET_WIDTH 20.f
#define BULLET_HEIGHT 5.f
#define BULLET_X_CENTER (BULLET_WIDTH / 2.f)
#define BULLET_Y_CENTER (BULLET_HEIGHT / 2.f)
#define BULLET_SPEED 8.6
#define BULLET_LIFETIME 2.0

#define UPPER_LIMIT -PLAYER_WIDTH
#define LOWER_LIMIT WINDOW_HEIGHT+PLAYER_WIDTH
#define LEFT_LIMIT -PLAYER_WIDTH
#define RIGHT_LIMIT WINDOW_WIDTH+PLAYER_WIDTH

#define MAX_SPEED 3.8
#define MAX_ROTATION_SPEED 1.3

#endif // !CONST_HPP
