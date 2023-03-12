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


int pos_value(int n, int pos){
    for(int i=1; i<=pos; i++){
        if(i==1) continue;
        n = n/10;
    }
    return n%10;
}

void redix(int arr[], int size){
    int max = find_max(arr, size);
    int digits = 0;
    while(max){
        max=max/10;
        digits++;
    }
    int temp[10], pos_arr[100], output[100], index, i, j, tmp;
    
    for(j=1; j<=digits; j++){
        for(i=0; i<10; i++){
            temp[i]=0;
        }
        for(i=0; i<size; i++){
            pos_arr[i] = pos_value(arr[i], j);
            temp[pos_arr[i]]++;
        }
        for(i=1; i<10; i++){
            temp[i] = temp[i] + temp[i-1];
        }
        for(i=size-1; i>=0; i--){
            temp[pos_arr[i]]--;
            tmp = temp[pos_arr[i]];
            output[tmp] = arr[i]; 
        }
        for(i=0; i<size; i++){
            arr[i] = output[i];
        }
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