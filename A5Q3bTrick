#include <stdio.h>
struct posn {
  int x;
  int y;
};
void foo(int *p1, int *p2) {
  p1 = p2;
  *p1 = 25;
  *p2 = 35;
  if(p1 == p2) {
    printf("p1 address equals to p2 %p\n", p1);
  } else {
    printf("NOT equals to p2 %p %p\n", p1, p2);
  }
}
void swap(struct posn *p1, struct posn *p2) {
  p1->x = p2->x;
  p2->x = p1->x;
  p2->y = p1->y;
  p1->y = p2->y;
  if(p1 == p2) {
    printf("p1 address equals to p2 %p\n", p1);
  } else {
    printf("NOT equals to p2 %p\n                 %p\n", p1, p2);
  }
}
int main(void) {
  int x = 10;
  int y = 20;
  foo(&x, &y);
  printf("x %d %p\ny %d %p\n\n", x, &x, y, &y);
  struct posn p1 = {42,24};
  struct posn p2 = {21,12};
  swap(&p1,&p2);
  printf("p1 x %d, p2 y %d\np2 x %d, p2 y %d\n", p1.x, p1.y, p2.x, p2.y);
}
