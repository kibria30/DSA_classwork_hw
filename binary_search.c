#include<stdio.h>
#include<time.h>

int binary_search(int a[],int min,int max,int target);

int main(){
    float start, end;
    start = clock();
    int a[]={6,13,14,25,33,43,51,53,64,72,84,93,95,96,97};
    int target;
    scanf("%d", &target);
    int result = binary_search(a, 0,14,target);
    if(result == -1){
        printf("Not found!!");
    }
    else{
        printf("%d is found in %dth position", target, result+1);
    }
    end = clock();
    printf("\nExecution time is: %f milisec",((end- start)/CLOCKS_PER_SEC)*1000);
}

int binary_search(int a[],int min,int max,int target){
    if(min <= max){
        int mid = (max + min )/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target){
            binary_search(a, mid+1, max, target);
        }
        else{
            binary_search(a, min, mid -1 ,target);
        }
    }
    else{
        return -1;
    }
}