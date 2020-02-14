#include <stdio.h>
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
  int stage_height = 10, stage_width = 10;
  print_stage(stage_height, stage_width);

  return 0;
}
