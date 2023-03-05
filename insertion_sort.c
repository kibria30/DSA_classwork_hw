#include<stdio.h>
#include<time.h>

void insert_sort(int arr[], int size){
    int i,j,temp;
    for(i=0; i<size; i++){
        j = i;
        while(j>0 && arr[j]<arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main(){
    float start, end;
    start = clock();
    int size=8;
    int arr[] = {4,7,2,3,8,9,6,5};
    insert_sort(arr, size);
    for(int i=0; i<size; i++){
        printf("%d, ",arr[i]);
    }
    end = clock();
    printf("\nExecution time is: %f sec", (end-start)/CLOCKS_PER_SEC);
    return 0;
}