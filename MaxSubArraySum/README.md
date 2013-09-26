
最大子数组和
===============
描述： 求一个一维数组的最大子数组和，比如{1,2,3,-4,9}的最大子数组和为9.

## 设计思路 ##

求和最大，只要数组元素不是负数，和就会增加，遇到负数和就不是最大。
按此思路，遍历数组只要没遇到负数，就sum+=a[i]; 遇到负数就比较之前的sum和最新的sum的大小。

### 更新(2013-09-26 11:30)
输出最大子数组和的beginindex和endindex

   for i:0->a.length
        a[i]>=0, temp_sum += a[i]
        a[i]<0
            update temp_end;
            temp_sum > sum
                update sum;
                update begin;
                update end;
            update temp_sum;
            update temp_begin;
    
    temp_sum > sum
        update sum;
        update begin;
        update end;
最后就得到sum和begin，end

## 程序
[MaxSubArraySum.c](MaxSubArraySum.c)
