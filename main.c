#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void print_stage(deque *snake, int h, int w) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (contains_coords(snake, x, h - y)) {
        printf("O ");
      }
      else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  int stage_height = 10, stage_width = 10; // Don't forget: MAX in deque.h should be stage_width * stage_height (I think).
  
  coords head;
  head.x = 6;
  head.y = 6;

  coords body1;
  body1.x = 5;
  body1.y = 6;

  coords body2;
  body2.x = 4;
  body2.y = 6;

  coords body3;
  body3.x = 4;
  body3.y = 5;

  coords tail;
  tail.x = 3;
  tail.y = 5;

  deque snake;
  initialize(&snake);

  enqueue_tail(&snake, head);
  enqueue_tail(&snake, body1);
  enqueue_tail(&snake, body2);
  enqueue_tail(&snake, body3);
  enqueue_tail(&snake, tail);

  print(&snake);

  print_stage(&snake, stage_height, stage_width);

  return 0;
}
