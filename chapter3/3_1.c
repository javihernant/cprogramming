#include <stdio.h>
#define LEN 100

int binsearch(int x, int arr[], int n){
    int a = 0;
    int b = n-1;
    int mid;
    while(a<=b){
        int mid = (a + b) / 2;
        if(x < arr[mid]){
            b = mid - 1;
        }else if(x > arr[mid]){
            a = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

/* alternate version of binsearch using only one test inside the loop */
int binsearch2(int x, int arr[], int n){
    int a = 0;
    int b = n-1;
    int mid;
    while(a<b){
        int mid = (a + b) / 2;
        if(x > arr[mid]){
            a = mid + 1;
        }else{
            b = mid;
        }
    }
    return arr[a] != x ? -1 : a;
}


int main(){
    int arr[LEN];
   
    for(int i=0; i<LEN; i++){
        arr[i] = i*2;
    }

    printf("Index %d\n", binsearch2(50, arr, LEN));
    
    return 0;
}
