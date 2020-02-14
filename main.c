#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void print_stage(int h, int w) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      printf("# ");
    }
    printf("\n");
  }
}

int main() {
  int stage_height = 10, stage_width = 10; // Don't forget: MAX in deque.h should be stage_width * stage_height (I think).
  print_stage(stage_height, stage_width);

  deque q;
  initialize(&q);

  return 0;
}
