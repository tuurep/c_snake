#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "deque.h"

void ncurses_settings() {
  initscr();
  raw();
  noecho();
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
  int stage_height = 15; // Min 1, max 51
  int stage_width = 15; // Min 1, max 208
  int ch;
  deque snake;

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

  initialize(&snake);

  enqueue_tail(&snake, head);
  enqueue_tail(&snake, body1);
  enqueue_tail(&snake, body2);
  enqueue_tail(&snake, body3);
  enqueue_tail(&snake, tail);

  print(&snake);

  ncurses_settings();

  print_stage(&snake, stage_height, stage_width);

  for (int i = 0; i < 20; i++) {
    timeout(-1);
    ch = getch();
    printf("%d %c\n\r", ch, ch);
  }

  endwin();

  return 0;
}
