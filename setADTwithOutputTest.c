#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name

// Name: Ziqiao Yang
// login ID: 20609335

// implementation:

struct Set{
  int *elements;
  int len;
  int maxLen;
};

struct Set *set_create(void) {
  struct Set *s = malloc(sizeof(struct Set));
  (*s).len = 0;
  (*s).maxLen = 1;
  (*s).elements = malloc((*s).maxLen * sizeof(int));
  return s;
}

void set_destroy(struct Set *s) {
  free((*s).elements);
  (*s).len = 0;
  (*s).maxLen = 0;
  free(s);
}

int set_size(const struct Set *s) {
  return (*s).len;
}

void set_add(struct Set *s, int i) {
  int index = 0;
  int store;
  int add = i;
    
  if((*s).len == 0) {
    (*s).elements[0] = i;
    (*s).len++;
    (*s).maxLen *= 2;
    (*s).elements = realloc((*s).elements, (*s).maxLen * sizeof(int));
    return;
  }
  
  // find the index that we need to add
  for(int j = 0; j < (*s).len; j++) {
    if(j != 0 && i > (*s).elements[j - 1] && i < (*s).elements[j]) {
      index = j;
      break;
    } else if((*s).elements[j] == i) {
      return;
    } else if(i > (*s).elements[j]){
      index++;
    }
  }
  
  printf("add %d at %d\n", i, index);
  // insert i into s at j
  for(int j = index; j < (*s).len + 1; j++) {
    store = (*s).elements[j];
    (*s).elements[j] = add;
    add = store;
  }
  
  (*s).len++;
  
  // double maxLen
  if((*s).len == (*s).maxLen) {
    (*s).maxLen *= 2;
    (*s).elements = realloc((*s).elements, (*s).maxLen * sizeof(int));
  }
}

void set_remove(struct Set *s, int i) {
  int index = -1;
  if((*s).len == 0) return;

  
  // find the index of i
  for(int j = 0; j < (*s).len; j++) {
    if((*s).elements[j] == i) {
      index = j;
      break;
    }
  }
  
  // remove at index
  for(int j = index; j < (*s).len; j++) {
    (*s).elements[j] = (*s).elements[j + 1];
  }
  
  if(index >= 0) (*s).len--;
}

struct Set *set_union(const struct Set *s1, const struct Set *s2) {
  struct Set *s = malloc(sizeof(struct Set));
  (*s).elements = malloc(sizeof(int) * ((*s1).len + (*s2).len));
  (*s).len = ((*s1).len + (*s2).len);
  (*s).maxLen = ((*s1).len + (*s2).len);
  int s1Index = 0;
  int s2Index = 0;
  
  for(int i = 0; i < ((*s1).len + (*s2).len); i++) {
    if(s1Index == (*s1).len) {
      (*s).elements[i] = (*s2).elements[s2Index];
      s2Index++;
    } else if(s2Index == (*s2).len) {
      (*s).elements[i] = (*s1).elements[s1Index];
      s1Index++;
    } else if((*s1).elements[s1Index] > (*s2).elements[s2Index]) {
      (*s).elements[i] = (*s2).elements[s2Index];
      s2Index++;
    } else if((*s1).elements[s1Index] < (*s2).elements[s2Index]){
      (*s).elements[i] = (*s1).elements[s1Index];
      s1Index++;
    } else if((*s1).elements[s1Index] == (*s2).elements[s2Index]){
      (*s).elements[i] = (*s1).elements[s1Index];
      s1Index++;
      s2Index++;
      (*s).len--;
    }
  }
    
  return s;
}

struct Set *set_intersect(const struct Set *s1, const struct Set *s2) {
  struct Set *s = malloc(sizeof(struct Set));
  if((*s1).len >= (*s2).len) {
    (*s).elements = malloc(sizeof(int) * (*s1).len);
    (*s).maxLen = (*s1).len;
  } else {
    (*s).elements = malloc(sizeof(int) * (*s2).len);
    (*s).maxLen = (*s2).len;
  }
  
  int s1Index = 0;
  int s2Index = 0;
  int total = 0;
  
  for(int i = 0; i < ((*s1).len + (*s2).len); i++) {
    printf("test %d %d ", (*s1).elements[s1Index], (*s2).elements[s2Index]);
    if(s1Index == (*s1).len || s2Index == (*s2).len) {
      break;
    } else if((*s1).elements[s1Index] == (*s2).elements[s2Index]) {
      printf("equal\n");
      (*s).elements[total] = (*s1).elements[s1Index];
      s1Index++;
      s2Index++;
      total++;
    } else if((*s1).elements[s1Index] > (*s2).elements[s2Index]) {
      printf(">\n");
      s2Index++;
    } else {
      printf("<\n");
      s1Index++;
    }
  }
  
  printf("total %d\n", total);
  (*s).len = total;
  (*s).maxLen = total;
  
  return s;
}

void set_print(const struct Set *s) {
  if((*s).len == 0) return;
  
  printf("[%d", (*s).elements[0]);
  for(int i = 1; i < (*s).len; i++) {
    printf(",%d", (*s).elements[i]);
  }
  printf("]\n");
}
