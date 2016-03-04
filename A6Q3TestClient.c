// This is the test client for matrix question
// Change a and b to get several answers
// mainly test dot_product    0, +, -
//             is_multiple    0, non-scalar multiple, multiple of each other, + -, - +
//             cross_product  

int main(void) {
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};
  int length = 3;  
  int dotProduct = dot_product(a, b, length);
  printf("dotProduct %d, orthogonal ", dotProduct);
  if(is_orthogonal(a, b, length)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  
  int c[length];
  add_to_vector(a, b, c, length);
  printf("c0 %d, c1 %d, c2 %d\n", c[0], c[1], c[2]);
  
  printf("multiple ");
  if(is_multiple(a, b, length)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  
  int d[length];
  cross_product(a, b, d);
  printf("c0 %d, c1 %d, c2 %d\n", d[0], d[1], d[2]);
}
