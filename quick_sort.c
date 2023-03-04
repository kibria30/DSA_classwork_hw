#include<stdio.h>
#include<time.h>

int partition(int arr[], int left, int right){
    int x,temp;
    x = arr[right];
    int j=left-1;
    //int j = left;
    for(int i=left; i<right; i++){
        if(arr[i]<=x){
            j++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            //j++;
        }
    }
    temp = arr[j+1];
    arr[j+1] = arr[right];
    arr[right] = temp;
    return j+1;
    //return j;
}

void quick_sort(int arr[],int left,int right){
    if(left < right){
        int pos = partition(arr, left, right);
        quick_sort(arr, left, pos-1);
        quick_sort(arr, pos+1, right);
    }

}

int main(){
    float start, end;
    start = clock();
    int size=8;
    int arr[] = {4,7,2,3,8,9,6,5};
    quick_sort(arr, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d, ", arr[i]);
    }
    end = clock();
    printf("\n Execution time is: %f sec", (end- start)/CLOCKS_PER_SEC);
    return 0;
}