#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = 255;
  c.green = 192;
  c.blue = 203;

  clear_screen(s);

  struct matrix *m1;
  struct matrix *m2;
  m1 = new_matrix(4, 4);
  m2 = new_matrix(4, 4);

  printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");
  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix(m2);

  printf("\nTesting ident. m1 = \n");
  ident(m1);
  print_matrix(m1);

  printf("\nTesting Matrix mult. m1 * m2 = \n");
  matrix_mult(m1, m2);
  print_matrix(m2);

  printf("\nTesting Matrix mult. m1 = \n");
  m1 = new_matrix(4, 4);
  add_edge(m1, 1, 2, 3, 4, 5, 6);
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  print_matrix(m1);

  printf("\nTesting Matrix mult. m1 * m2 = \n");
  matrix_mult(m1, m2);
  print_matrix(m2);

  free_matrix(m1);
  free_matrix(m2);

  struct matrix *edges;
  edges = new_matrix(4, 4);
  add_edge(edges, 50, 50, 0, 450, 50, 0);
  add_edge(edges, 50, 50, 0, 50, 225, 0);
  add_edge(edges, 50, 225, 0, 60, 225, 0);
  add_edge(edges, 60, 225, 0, 95, 205, 0);
  add_edge(edges, 95, 205, 0, 165, 205, 0);
  add_edge(edges, 165, 205, 0, 200, 225, 0);
  add_edge(edges, 200, 225, 0, 210, 225, 0);
  add_edge(edges, 210, 225, 0, 210, 200, 0);
  add_edge(edges, 210, 200, 0, 450, 85, 0);
  add_edge(edges, 450, 50, 0, 450, 85, 0);
  draw_lines(edges, s, c);
  free_matrix(edges);
  printf("png saved to image.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
}
