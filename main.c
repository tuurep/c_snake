#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "deque.h"

void cls() {
    printf("\x1b[2J");
}

void print_stage(deque *snake, int h, int w) {
  char border[] = "$";
  char body[] = "O";
  char empty[] = " ";
  char apple[] = "o";

  for (int i = 0; i < w + 2; i++) {
    printf("%s ", border);
  }

  printf("\n\r");

  for (int y = 0; y < h; y++) {
    printf("%s ", border);
    for (int x = 0; x < w; x++) {
      if (contains_coords(snake, x, h - y)) {
        printf("%s ", body);
      }
      else {
        printf("%s ", empty);
      }
    }
    printf("%s\n\r", border);
  }

  for (int i = 0; i < w + 2; i++) {
    printf("%s ", border);
  }
}

int main() {
  int stage_height = 15, stage_width = 15;

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

  initscr();
  cls();

  print_stage(&snake, stage_height, stage_width);

  return 0;
}
