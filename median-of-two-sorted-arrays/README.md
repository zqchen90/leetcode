#Median of Two Sorted Arrays 
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
## Solution
这是一道非常经典的题。这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第k 大的元素。
###O(m + n) 的解法
比较直观，直接merge 两个数组，然后求第k 大的元素。
不过我们仅仅需要第k 大的元素，是不需要“排序”这么复杂的操作的。可以用一个计数器，
记录当前已经找到第m 大的元素了。同时我们使用两个指针pA 和pB，分别指向A 和B 数组的第
一个元素，使用类似于merge sort 的原理，如果数组A 当前元素小，那么pA++，同时m++；如果数
组B 当前元素小，那么pB++，同时m++。最终当m 等于k 的时候，就得到了我们的答案，O(k) 时
间，O(1) 空间。但是，当k 很接近m + n 的时候，这个方法还是O(m + n) 的。
###O(log(m+n))的解法
有没有更好的方案呢？我们可以考虑从k 入手。如果我们每次都能够删除一个一定在第k 大元
素之前的元素，那么我们需要进行k 次。但是如果每次我们都删除一半呢？由于A 和B 都是有序
的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设A 和B 的元素个数都大于k/2，我们将A 的第k/2 个元素（即A[k/2-1]）和B 的第k/2
个元素（即B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结论
对于k 是奇数也是成立的）：
 * A[k/2-1] == B[k/2-1]
 * A[k/2-1] > B[k/2-1]
 * A[k/2-1] < B[k/2-1]
如果A[k/2-1] < B[k/2-1]，意味着A[0] 到A[k/2-1] 的肯定在A 与 B 的top k 元素的范围
内，换句话说，A[k/2-1 不可能大于A 与 B 的第k 大元素。留给读者证明。
因此，我们可以放心的删除A数组的这k/2 个元素。同理，当A[k/2-1] > B[k/2-1] 时，可
以删除B 数组的k/2 个元素。
当A[k/2-1] == B[k/2-1] 时，说明找到了第k 大的元素，直接返回A[k/2-1] 或B[k/2-1]
即可。
因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
 * 当A 或B 是空时，直接返回B[k-1] 或A[k-1]；
 * 当k=1 是，返回min(A[0], B[0])；
 * 当A[k/2-1] == B[k/2-1] 时，返回A[k/2-1] 或B[k/2-1]
 
 ###findKth
 ```cpp
int findKth(int A[], int m, int B[], int n, int K) {
        // always m <= n
        if (m > n) return findKth(B, n, A, m, K);
        // if A is empty, B[K - 1] is the Kth number
        if (m == 0) return B[K - 1]; 
        if (K == 1) {
            return min(A[0], B[0]);
        }
        int ia = min(K/2, m);
        int ib = K - ia;
        if (A[ia - 1] < B[ib - 1])
            return findKth(A + ia, m - ia, B, n, K- ia);
        else if (A[ia - 1] > B[ib - 1])
            return findKth(A, m , B + ib, n - ib, K- ib);
        else
            return A[ia - 1];
    }
 ```