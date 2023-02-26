#include<stdio.h>
#include<time.h>

void Msort(int a[], int temp[], int left, int right);
void merge(int a[], int temp[], int lpos, int rpos, int rightend);

int a[]={8,6,4,9,7,5,2,3};
int temp[8];

int main(){
    time_t start , end;
    start = clock();
    Msort(a, temp, 0,7);
    for(int i=0; i<8; i++){
        printf("%d ",a[i]);
    }

    end = clock();
    printf("\nExecution is %f", (float)end - (float)start);

    //int ticks = clock();
    //printf("Execution time is: %f", (float)ticks/ CLOCKS_PER_SEC);
    return 0;
}

void Msort(int a[], int temp[], int left, int right){
    if(left <right){
        int centre = (left+right)/2;
        Msort(a, temp, left, centre);
        Msort(a, temp, centre+1, right);
        merge(a, temp, left, centre+1, right);
    }
}

void merge(int a[], int temp[], int lpos, int rpos, int rightend){
    int leftend = rpos -1;
    int tempos = lpos;
    int element = rightend - lpos +1;

    while(lpos<=leftend && rpos <= rightend){
        if(a[lpos]<=a[rpos]){
            temp[tempos++] = a[lpos++];
        }
        else{
            temp[tempos++] = a[rpos++];
        }
    }
    while(lpos<=leftend){
        temp[tempos++] = a[lpos++];
    }
    while(rpos<=rightend){
        temp[tempos++] = a[rpos++];
    }
    for(int i=0; i<element; i++){
        a[rightend]= temp[rightend];
        rightend--;
    }
}
