#include "common.hpp"

/*
> 简介
基数排序是按照低位先排序,然后收集；再按照高位排序,然后再收集；依次类推,直到最高位。有时候有些属性是有优先级顺序的,先按低优先级排序,再按高优先级排序。最后的次序就是高优先级高的在前,高优先级相同的低优先级高的在前。
> 算法描述
1. 取得数组中的最大数,并取得位数；
2. arr为原始数组,从最低位开始取每个位组成radix数组；
3. 对radix进行计数排序（利用计数排序适用于小范围数的特点）；
> 算法分析
基数排序基于分别排序,分别收集,所以是稳定的。但基数排序的性能比桶排序要略差,每一次关键字的桶分配都需要O(n)的时间复杂度,而且分配之后得到新的关键字序列又需要O(n)的时间复杂度。假如待排数据可以分为d个关键字,则基数排序的时间复杂度将是O(d*2n) ,当然d要远远小于n,因此基本上还是线性级别的。
基数排序的空间复杂度为O(n+k),其中k为桶的数量。一般来说n>>k,因此额外空间需要大概n个左右。

g++ base.cpp common.cpp -o xxx -std=c++11
*/

int GetNum(int num, int pos) {
    while (num && pos) {
        num = num/10;
        pos--;
    }

    return pos ? 0 : num % 10;
}

void Sort(std::vector<int> &vec, int start, int end) {
    int max = vec[0];

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    //假设需要排序的数都是正整数
    int count = 0;
    while (max) {
        count++;
        max /= 10;
    }

    //std::cout << "max:" << max << " count:" << count << std::endl;
    std::vector<std::vector<int> > array{{},{},{},
                                            {},{},{},
                                            {},{},{},{}};
    
    //按个十百千的位数进行计数排序
    for (int i = 0; i < count; ++i) {
        for (int m = 0; m <= 9; ++m) {
            array[m].clear();
        }

        for (int j = 0; j < vec.size(); ++j) {
            //std::cout << vec[j] << " " << i << " " << GetNum(vec[j], i) << std::endl;
            array[GetNum(vec[j], i)].emplace_back(vec[j]);
        }

        int pos = 0;
        for (auto list : array) {
            for (auto it : list) {
                //std::cout << " - " << it;
                vec[pos++] = it;
            }
            //std::cout << std::endl;
        }

        //std::cout << "Sort by " << i << " :";
        //Show(vec);
    }
}


int main() {
    std::vector<int> _vec = {2,22,31,1221,90,85,105};
    //Init(_vec);
    Sort(_vec, 0, _vec.size() - 1);
    //Show(_vec);
    return 0;
}