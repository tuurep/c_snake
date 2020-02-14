#include <stdio.h>

void print_stage(int h, int w) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
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