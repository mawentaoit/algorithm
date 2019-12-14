#include <iostream>
#include<vector>

void partition(vector<int> arr, int L, int R, int num) {
    int less = L-1;
    int more = r+1;
    int cur = L;
    while(cur < more) {
        if(arr[cur] < num) {
            swap(arr[++less], arr[cur++]);
        } else if(arr[cur] > num) {
            swap(arr[--more], cur);
        } else {
            cur++;
        }
    }
}
int main() {
经典快排小于区域和等于区域很可能会打偏，你拿最后一个数子取滑分
随机快排，我在整个数组中，随机做一个滑分，我随即选一个树，然后用随机选的树
去滑分，你能够找出最差的情况，
递归函数，准备一个递归函数的代价是比较高的
网上太占用时间了
系统上工程上怎么实现
二叉树，完全二叉树
如果你不是满二叉树
都叫完全二叉树
012345
你就可以脑部出一个完全二叉树，
这棵树是你脑海中的，你可以把一个数组想象成一个完全二叉树
堆分为大根堆小根堆
堆就是完全二叉树
谈到堆，你到底是大根堆还是小根堆
在一棵完全二叉树里面
在计算机里面就是0
当我加入第i个节点的时候
i+1的调整代价是啥
log1 + log2 + log3
O(n),简历大根堆
你原来已经形成了一个特别好的结构
这个数组是这样的
三位置，四位值
同样道理
在这样的一个范围
导致这个index
int largest = left+1 < heapsize && arr[left + 1] > arr[left] ? left+1 : left;
largest = arr[largest] > arr[index] ? largest : index;
if(largest == index) {
    break;
}
swap(arr[index], arr[largest]);
index = largest;
left = index * 2 + 1;
largest != index;
当我建立堆的时候，heapinsert向上插入是heapinsert
当某个值变小了，可能要经历向下调整
已经形成的收集代价O(1)
要经历一个O(n*logN)
如果有堆的话
得到这个结果，因为你拍好之后，新的代价又无序了
本身很难，再将堆这个结构
数组初始长度为1000
我怎么弹出，这叫一个减堆操作，把标记越界，就又恢复成大根堆了
所以最后一个数，来到堆定植后，重新变成大根堆
做一个大根堆，加东西减东西的操作
优先级队列，就是堆，堆就可以通过一种标准，大根堆里面放着n个数
跟其他数是没有关系的
我给大家的代码没有这个代码是有的，应该是之前的基础课
交换完了之后heaify(arr, 0, heapSize);
几乎所有的贪心问题，我有点饿了
快排和堆排
为什么综合排序，332113444
你不用区分
相同值无差异
快排一个班的同学先按照
01 stable sort
什么样的问题，有一道非常经典的问题
什么样的问题，在在一个数组中，奇数放左边，偶数放右边
我们在快排中，也是01标准，完全是在搞你的，快排是做不到稳定性的
其实你很难写
快排的过程
如果面到这个题目，
那个算法是，那个面试官
国手，student
你想比较student类型
优先级队列
会按照什么东西来组织这个东西呢？
内存地址
封装好了
student cur = heap.poll();
zheshibijiaoqi
tongpaixu,jisupaixu,jisupaix
因为他们不是基于比较的排序
我举个例子，词频++起来，这些
O(n),时间复杂度
学习的过程中，这种瓶颈，不能被，
就求这个东西，让你时间复杂度为O(N)
N个数，N+1个桶，if(min == max) return 0;
else {
    0 1 2 3 4 5 ... n
    N个数，我准备了N+1个桶
    10-19
    我们不用去管两个桶内部的差值，一定
    找这个飞控同，
    怎么不直接找中间某个空桶，你注意看这种情况，下一个情况
    为什么不断的找，因为空桶，
    但一定不是来资
}
}