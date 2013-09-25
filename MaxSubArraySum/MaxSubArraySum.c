#include<stdio.h>

int func_sum(int a[], int n){
    int sum=0;
    int temp_sum=0;
    //int begin=0, end=0;
    int i=0;
    for(i=0;i<n;i++){
        if( a[i]>=0){
            temp_sum += a[i];
        }else{
            if( temp_sum > sum ){
                sum = temp_sum;
            }
            temp_sum = 0;
        }
    }
    if( temp_sum > sum ){
        sum = temp_sum;
    }
    return sum;
}

            
int main(){
    int a[5] = {1,2,3,22,-90};
    int sum = func_sum(a, 5);
    printf("Max subArray sum is %d\n", sum);
    system("pause");
}
