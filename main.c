#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h> 
#include "deque.h"

coords apple;

int rand_range(int min_n, int max_n) {
    return rand() % (max_n - min_n + 1) + min_n;
}

void ncurses_settings() {
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
}

void print_stage(deque *snake, int h, int w) {
  for (int i = 0; i < w + 2; i++) {
    printf("%c ", BORDER);
  }

  printf("\n\r");

  for (int y = 0; y < h; y++) {
    printf("%c ", BORDER);
    for (int x = 0; x < w; x++) {
      if (contains_coords(snake, x, h - y)) {
        printf("%c ", BODY);
      }
      else if (apple.x == x && apple.y == h - y) {
        printf("%c ", APPLE);
      }
      else {
        printf("%c ", EMPTY);
      }
    }
    printf("%c\n\r", BORDER);
  }

  for (int i = 0; i < w + 2; i++) {
    printf("%c ", BORDER);
  }

  printf("\n\r");
}

void move_snake(deque *snake, coords new_head) {
  if (!contains_coords(snake, new_head.x, new_head.y)) {
    enqueue_head(snake, new_head);
    if (!(new_head.x == apple.x && new_head.y == apple.y)) {
      dequeue_tail(snake);
    }
    else {
      apple.x = rand_range(1, STAGE_WIDTH - 1);
      apple.y = rand_range(1, STAGE_HEIGHT - 1);
    }
  }
}

int main() {
  enum direction { // Right, Left, Up, Down
    R, L, U, D
  };

  int ch;
  deque snake;

  // Call only once
  srand(time(0));
  apple.x = rand_range(1, STAGE_WIDTH - 1);
  apple.y = rand_range(1, STAGE_HEIGHT - 1);

  // To be randomized:
  enum direction dir = R;

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
  // End of randomized

  initialize(&snake);

  enqueue_tail(&snake, head);
  enqueue_tail(&snake, body1);
  enqueue_tail(&snake, body2);
  enqueue_tail(&snake, body3);
  enqueue_tail(&snake, tail);
  
  ncurses_settings();

  while(1) {
    clear();
    refresh();
    print_stage(&snake, STAGE_HEIGHT, STAGE_WIDTH);

    timeout(200);
    ch = getch();

    // Press q to quit
    if (ch == 113) break;
    if ((ch == KEY_RIGHT || ch == 100) && dir != L)
      dir = R;
    if ((ch == KEY_LEFT || ch == 97) && dir != R)
      dir = L;
    if ((ch == KEY_UP || ch == 119) && dir != D)
      dir = U;
    if ((ch == KEY_DOWN || ch == 115) && dir != U)
      dir = D;

    coords new_head = peek_head(&snake);

    if (dir == R && peek_head(&snake).x < STAGE_WIDTH - 1) {
      new_head.x++;
      move_snake(&snake, new_head);
    }

    if (dir == L && peek_head(&snake).x > 0) {
      new_head.x--;
      move_snake(&snake, new_head);
    }

    if (dir == U && peek_head(&snake).y < STAGE_WIDTH) {
      new_head.y++;
      move_snake(&snake, new_head);
    }

    if (dir == D && peek_head(&snake).y > 1) {
      new_head.y--;
      move_snake(&snake, new_head);
    }
  }

  endwin();

  print_stage(&snake, STAGE_HEIGHT, STAGE_WIDTH);

  return 0;
}
