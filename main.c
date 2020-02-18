#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "deque.h"

void ncurses_settings() {
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
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

  printf("\n\r");
}

int main() {
  enum direction { // Right, Left, Up, Down
    R,
    L,
    U,
    D
  };

  enum direction dir = R;

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

  ncurses_settings();

  while(1) {
    print(&snake);
    print_stage(&snake, stage_height, stage_width);

    timeout(1000);
    ch = getch();

    if (ch == 113) { // Press q to quit
      printf("\n\rYou pressed it!");
      break;
    }

    if (ch == KEY_RIGHT) {
      printf("\n\rYou pressed it!"); 
      dir = R;
    }
    if (ch == KEY_LEFT) {
      printf("\n\rYou pressed it!");
      dir = L;
    }
    if (ch == KEY_UP) {
      printf("\n\rYou pressed it!");
      dir = U;
    }
    if (ch == KEY_DOWN) {
      printf("\n\rYou pressed it!");
      dir = D;
    }

    if (dir == R && peek_head(&snake).x < stage_width - 1) {
      coords new_head = peek_head(&snake);
      new_head.x++;
      enqueue_head(&snake, new_head);
      dequeue_tail(&snake);
    }

    if (dir == L && peek_head(&snake).x > 0) {
      coords new_head = peek_head(&snake);
      new_head.x--;
      enqueue_head(&snake, new_head);
      dequeue_tail(&snake);
    }

    if (dir == U && peek_head(&snake).y < stage_height) {
      coords new_head = peek_head(&snake);
      new_head.y++;
      enqueue_head(&snake, new_head);
      dequeue_tail(&snake);
    }

    if (dir == D && peek_head(&snake).y > 1) {
      coords new_head = peek_head(&snake);
      new_head.y--;
      enqueue_head(&snake, new_head);
      dequeue_tail(&snake);
    }

    printf("%d %c\n\r", ch, ch);
  }

  endwin();


  print(&snake);
  print_stage(&snake, stage_height, stage_width);

  return 0;
}
