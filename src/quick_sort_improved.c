#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  if (n == 0) return;
  int i, j, m, pivot;
  pivot = A[n-1];
  A[n-1] = A[0];
  A[0] = pivot;
  for (i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }
  for(i = m = 1 ; i < j; i++){
    if(A[i] < pivot){
      swap(A+i, A+m);
      m++;
    }
  }
    swap(A,A+m-1);
    quick_sort(A+j, n-j);
    quick_sort(A, m-1);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
