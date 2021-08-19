#include "common.hpp"

/*
> 简介
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
> 算法描述
将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
> 原理
该数组从逻辑上讲就是一个堆结构，我们用简单的公式来描述一下堆的定义就是：
大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  
> 算法分析
时间复杂度：O(nlog n)
空间复杂度：O(1)

g++ head.cpp -o xxx -std=c++11
*/

//排序
/*
步骤一 构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
此时我们从最后一个非叶子结点开始（叶结点自然不用调整，第一个非叶子结点 arr.length/2-1=5/2-1=1，
也就是下面的6结点），从左至右，从下至上进行调整。
步骤二 将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。如此反复进行交换、重建、交换。
*/
void Sort(std::vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
        //Adjust(vec, i);
        // XXX：每次都要遍历整个vec，时间复杂度过高
        for (int j = i; j >= 0; --j) {
            int parent = j == 0 ? 0 : (j - 1) / 2;

            if (vec[j] > vec[parent]) {
                Swap(vec, j, parent);
            }
        }
        Swap(vec, 0, i);
    }
}

void Adjust(std::vector<int> &vec, int root, int end) {
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int bigest = root;

    if (left <= end && vec[left] > vec[bigest]) {
        bigest = left;
    }

    if (right <= end && vec[right] > vec[bigest]) {
        bigest = right;
    }

    if (bigest != root) {
        Swap(vec, root, bigest);
        Adjust(vec, bigest, end);
    }
}

void SortX(std::vector<int> &vec) {
    //步骤一 构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
    //时间复杂度为n（n次元素的插入）* log n （调整的时间复杂度）
    for (int i = vec.size() / 2 - 1; i >= 0; --i) {
        Adjust(vec, i, vec.size() - 1);
    }

    //时间复杂度为n（n次元素的排序）* log n （调整的时间复杂度）
    for (int i = vec.size() - 1; i >= 0; --i) {
        //步骤二 将堆顶元素与末尾元素进行交换，使末尾元素最大。
        Swap(vec, 0, i);

        if (i > 0) {
            //调整新的根节点
            Adjust(vec, 0, i - 1);
        }
    }
}

int main() {
    std::vector<int> _vec;// = {9,6,8,5,3,4,7,2,1};
    Init(_vec);
    SortX(_vec);
    Show(_vec);
    return 0;
}