#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include "game_settings.h"

typedef struct coords {
	int x;
  int y;
} coords;

typedef struct deque {
	coords data[MAX_Q_SIZE];
	int first, last;
} deque;
 
void initialize(deque *p);
int empty(deque *p);
int full(deque *p);
int contains_coords(deque *p, int x, int y);
coords peek_head(deque *p);
void enqueue_tail(deque *p, coords c);
void enqueue_head(deque *p, coords c);
coords dequeue_head(deque *p);
coords dequeue_tail(deque *p);
void print(deque *p);

#endif