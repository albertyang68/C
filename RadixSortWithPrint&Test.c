#include <stdio.h>

void radix_sort(int arr[],int len) {
  struct stack {
    int len;
    int maxlen;
    int data[100];
  };
  
  struct stack num0 = {.len = 0, .maxlen = 100};
  struct stack num1 = {.len = 0, .maxlen = 100};
  struct stack num2 = {.len = 0, .maxlen = 100};
  struct stack num3 = {.len = 0, .maxlen = 100};
  struct stack num4 = {.len = 0, .maxlen = 100};
  struct stack num5 = {.len = 0, .maxlen = 100};
  struct stack num6 = {.len = 0, .maxlen = 100};
  struct stack num7 = {.len = 0, .maxlen = 100};
  struct stack num8 = {.len = 0, .maxlen = 100};
  struct stack num9 = {.len = 0, .maxlen = 100};
  
  struct stack stackArr[10] = {num0, num1, num2, num3, num4, num5, 
                               num6, num7, num8, num9};  
  
  int max;
  if(len != 0) {
    max = arr[0];
  } else {
    return;
  }
  
  // determine the times of pass k
  
  // find max number
  for(int i = 0; i < len; i++) {
    if(arr[i] > max) {
      max = arr[i];
      /////////////////////////////////////////////////////
      printf("max %d\n", max);
    }
  }
  
  int k = 0;
  int tempInt = max;
  // find max number digit (which is k)
  while(tempInt != 0) {
    tempInt = tempInt / 10;
    k++;
  }
  ///////////////////////////////////////////////////////
  printf("k %d\n", k);
  
  // algorithum step 1
  int divider;
  int kTen = 1;
  for(int i = 1; i <= k; i++) {
    
    // put all nums in stack array, into right digit stack
    for(int j = 0; j < len; j++) {
      if((arr[j] / kTen) < 10) {
        printf("arr[j] = %d\n", arr[j]);
        divider = arr[j] / kTen;
        (stackArr[divider]).data[(stackArr[divider]).len] = arr[j];
        printf("round k %d, num %d in %d", i, (stackArr[divider]).data[(stackArr[divider]).len], divider);
        (stackArr[divider]).len++;
        printf(", length %d\n", (stackArr[divider]).len);
      } else {
        divider = (arr[j] / kTen) % 10;
        printf("arr[j] = %d\n", arr[j]);
        (stackArr[divider]).data[(stackArr[divider]).len] = arr[j];
        printf("round k %d, num %d in %d", i, (stackArr[divider]).data[(stackArr[divider]).len], divider);
        (stackArr[divider]).len++;
        printf(", length %d\n", (stackArr[divider]).len);
      }
    }
    /////////////////////////////////////////////////////////////////////
    
    // put all nums inside of stack array back to arr[]
    // from stackArr[0] to [9]
    // take number of each stack from index 0 to length
    int indexStack = 0;
    int indexArr = 0;
    for(int a = 0; a <= 9; a++) {
      indexStack = (stackArr[a]).len - 1;
      printf("stack %d\n", a);
      for(int b = 0; b <= indexStack; b++) {
        printf("indexArr %d, for number %d\n", indexArr, (stackArr[a]).data[b]);
        arr[indexArr] = (stackArr[a]).data[b];
        indexArr++;
      }
//*******************************************************************************************//      
      (stackArr[a]).len = 0;
//*******************************used to foget to do this************************************//
    }
    
//*******************************************************************************************//    
    if(kTen == 1) {
        kTen = 10;
      } else {
        kTen *= 10;
    }
//*******************************used to foget to do this************************************//
    
    printf("kTen %d is ready for k %d round\n", kTen, i + 1);
  }
}

int main(void) {
  int a[] = {10, 15, 1, 60, 5, 100, 25, 50};
  int aLength = 8;
  radix_sort(a, aLength);
  printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
}
