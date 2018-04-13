/*
又给自己挖坑, 堆都还没看就想写堆排序
*/

/*
刚实现了heap, 现在回来填坑
因为堆只保证父节点一定小于子节点(以最小堆为例), 而不限制兄弟节点的大小关系, 所以表示堆的数组并非排好序的数组
然后我当即想了一个贼牛逼的算法
设要排序的数组是vector<int> arr
申请一个vector<int> res
建一个空堆heap
先把arr中的元素依次push到heap中
然后把heap依次pop的元素扔进res
哇
这大概是一个以空间时间加起来换智商的例子, 做到了既耗时又占存储, 斯国一
like an idiot
*/

// 正确的做法是堆化数组, 然后进行堆排序, 其实思路是类似的, 但是可以做到in place
// 来源: https://blog.csdn.net/morewindows/article/details/6709644, 稍作了修改

 




