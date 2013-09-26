#include<stdio.h>

int func_sum(int a[], int n, int *begin, int *end){
    int sum=0;
    int temp_sum=0;
    int temp_begin=0, temp_end=0;
    int i=0;
    for(i=0;i<n;i++){
        if( a[i]>=0){
            temp_sum += a[i];
        }else{
			temp_end = i-1;
            if( temp_sum > sum ){
                sum = temp_sum;
				*begin = temp_begin;
				*end = temp_end;
            }
			temp_begin = i+1;
            temp_sum = 0;
        }
    }
    if( temp_sum > sum ){
        sum = temp_sum;
		*begin = temp_begin;
		*end = temp_end;
    }
    return sum;
}

                
int main(){
    int a[5] = {1,2,3,22,-90};
    int begin=0, end=0;
    int sum = func_sum(a, 5, &begin, &end);
    printf("Max subArray sum is %d, the subArray index is %d--%d.\n", sum, begin, end);
    //system("pause");
}
