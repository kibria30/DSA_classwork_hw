#include<stdio.h>
#include<time.h>

int linear_search(int arr[],int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    float start, end;
    start = clock();
    int size=15;
    //scanf("%d", &size);
    int arr[]={6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
    int target;
    scanf("%d", &target);
    int result = linear_search(arr, size, target);
    if(result == -1){
        printf("Not found!!");
    }
    else{
        printf("%d is found in %dth position", target, result+1);
    }
    end = clock();
    printf("\nExecution time is: %f ",(end- start)/CLOCKS_PER_SEC);
}