#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include <stdlib.h>

// Change stage size here
#define STAGE_HEIGHT 20
#define STAGE_WIDTH 15

// Change aesthetics here
#define BORDER '$'
#define BODY 'O'
#define EMPTY ' '
#define APPLE 'a'

// Change speed here
#define nothing

// Change number of apples here
#define nuthing

// Don't change
#define MAX_Q_SIZE (STAGE_HEIGHT * STAGE_WIDTH)

typedef struct coords {
	int x;
  int y;
} coords;

#endif