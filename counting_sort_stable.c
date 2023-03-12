#include<stdio.h>

int finding_max(int arr[], int size){
    int max = arr[0];
    for(int i=0; i< size; i++){
        if(arr[i]>max){
            max =arr[i];
        }
    }
    return max;
}

void counting_sort(int arr[], int size){
    int max = finding_max(arr, size);
    int i,j=0, temp[100], tmp, output[100];//loop 0 to max (means array size should be (max  + 1))
    for(i=0; i<=max; i++){
        temp[i]=0;
    }
    for(i=0; i<size; i++){
        temp[arr[i]]++;
    }
    for(i=1; i<=max; i++){
        temp[i] = temp[i] + temp[i-1];
    }
    for(i=size-1; i>=0; i--){
        //temp[arr[i]]--;
        //tmp = temp[arr[i]];
        output[--temp[arr[i]]] = arr[i]; 
    }
    for(i=0; i<size; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {1,4,1,2,7,5,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size: %d\n", size);
    counting_sort(arr, size);
    for(int i=0; i<size; i++){
        printf("%d, ",arr[i]);
    }
}
