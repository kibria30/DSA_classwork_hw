#include<stdio.h>

int find_max(int arr[], int size){
    int max=0; 
    for(int i=0; i<size; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int arr[], int size, int pos){
    int i, temp[10], tmp, output[100];
    for(i=0; i<10; i++){
        temp[i]=0;
    }
    for(i=0; i<size; i++){
        temp[(arr[i]/pos)%10]++;
    }
    for(i=1; i<10; i++){
        temp[i] = temp[i] + temp[i-1];
    }
    for(i=size-1; i>=0; i--){
        //temp[arr[i]]--;
        //tmp = temp[arr[i]];
        output[--temp[(arr[i]/pos)%10]] = arr[i]; 
    }
    for(i=0; i<size; i++){
        arr[i] = output[i];
    }
}

void redix(int arr[], int size){
    int max = find_max(arr, size);
    int pos;
    for(pos=1; max/pos > 0; pos = pos*10){
        counting_sort(arr, size, pos);
    }
}

int main(){
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr)/sizeof(arr[0]);
    redix(arr, size);
    for(int i=0; i<size; i++){
        printf("%d, ",arr[i]);
    }
}