<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Summary of Noip Training 2016.8</title>
<link rel="stylesheet" href="https://stackedit.io/res-min/themes/base.css" />
<script type="text/javascript" src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML"></script>
</head>

# Summary of Noip 2016 Training

## Day1

### T1 dragon

##### 题面

* 有2n个数:1,1,2,2,3,3,4,4...,n,n

    要求进行排列，使得成为单峰序列(中间大)

    还要满足m个要求，形如 A\[i\]&lt;A\[j\] 或 A\[i\]&lt;=A\[j\]

    求方案数

##### 题解

* dp\[i\]\[j\] : 在i~j之间，第i位与第j位放置相同数字的方案数

### T2 circle

##### 题面

* 求第一象限(包括坐标轴)的1/4整型圆的所有点的y值之和

##### 题解

* 类似整除分块的做复杂度大概为O(2/3\*n)

* 利用公式(n+1)^2=n^2+2n+1可以避免大整数相乘与开根操作，O(n)但是常数极小

### T3 stay

##### 题面

* 网格图，有的格子上有陷阱，每次踩到都会受到伤害

   有些格子有怪兽，第一次旁经会受伤，4联通

##### 题解

* 一只伤害为A的怪兽分解为
```
     A
  A -A A
     A
```

* <font color=red>两只怪兽若对角线相邻则互相连边</font>

## Day2

### T1 equation

##### 题面

* 给你一个标准多项式，求导

##### 题解

* 字符串处理题...

### T2 survey

##### 题面

* 给你一个序列，求有多少子序列满足

   有\[l1,r1\]个1,\[l2,r2\]个2,\[l3,r3\]个3...\[lm,rm\]个m

##### 题解

* 枚举左端点，two pointers右端点的左右边界

### T3 track

##### 题面

* 在一颗树上，你在S点，两个陌生人在P点与Q点

    每三秒一循环，第一秒你移动一步，第二三秒陌生人向你移动一步

    求最晚什么时候被抓到

##### 题解

* 枚举最后时刻所在的结点，先判是否可行，可行则更新答案

## Day3

### T1 equation

##### 题面

* 求一个7次方程的所有解,重根需要重复输出

##### 题解

* 模拟多项式除法

### T2 prime

##### 题面

* 将第i个数看成一个编号为i的点
    若A\[i\]+A\[j\]是一个质数,则点i和点j之间存在一条无向边
    求这个图的最大匹配

##### 题解

* 因为只有奇数能与偶数配对，所以这是二分图

### T3 mahjong

##### 题面

* 判断麻将中一副牌打出哪一张最后听的牌数最多

##### 题解

* 枚举打出哪张牌,再枚举听哪张牌

    暴力判断是否能胡牌

    <font color=red>注意数组要开够</font>

## Day4

### T1 eazy

##### 题面

* 给定一个数，问它有多少个不同的质因数，多组询问

##### 题解

* 满足积性

### T2 hard

##### 题面

* 字符串122344111可被描述为1个1、2个2、1个3、2个4、3个1

    因此我们说122344111的编码为1122132431

    给定编码，求合法字符串数

##### 题解

* 前缀和优化dp

### T3 hammer

##### 题面

* 给你一张图，边权会变，8秒一循环，求最短路

##### 题解

* 分层图

* <font color=red>SPFA要加SLF优化</font>

## Day5

### T1 name

##### 题面

* 给你花名册后点名，求每次点名名字是否存在，是否重点了

##### 题解

* STL裸题

### T2 shine

##### 题面

* 在一个n\*m的方格纸上用x\*y大小的笔画下一道痕迹

    笔只能向下走或向右走，给出墨迹图，求最小的x\*y

##### 题解

* 枚举x\*y，判断是否可行

    若一时刻可同时向下或向右走则不合法

    若只能向一个方向走就向那个方向走

    走不动了就判断扫过的面积是否与墨迹面积相等

    看上去像是O(n^4)，实际只有O(n^2)

### <font color=red>T3 sleet</font>

##### 题面

* 把0,1,2...,2n-1排成一个圈，要求x的下一个只能是

    2x,2x+1,2x-2n,2x-2n+1中的一个

    给出任意一个可行解

##### 题解

* 合并环，对于一个环，找出最小的x，

    对于边x/2+n-----&gt;x，在另一个环中找到 x/2-----&gt;x^1，合并

* 欧拉回路，u与u+n合并为一个点

    \[u\]-----(u\*2)-----&gt;\[(u\*2)%n\]

    \[u\]-----(u\*2+1)-----&gt;\[(u\*2+1)%n\]

* 欧拉回路中边的编号就是答案

## Day6

### T1 one

##### 题面

* 一个字符串，初始时你在p位置，每次操作你可以

    左移一位或右移一位(1与n联通)

    所在位置字符+1或-1('a'与'z'联通)

    询问最少多少次操作后修改成为回文串

##### 题解

* 贪心，<font color=red>注意一开始就是回文串的情况</font>

### <font color=red>T2 two</font>

##### 题面

* 在树上选择一些结点，使任何一条路径上不超过k个被选结点，最多选几个

##### 题解

* 取k/2层叶子，若k为奇数就夺取一个点

### T3 three

##### 题面

* 一个键盘上，每次操作可以上下左右移或按下当前键，最少几次操作输入给定字符串

##### 题解

* 建图BFS...

## Day7

### T1 clannad

##### 题面

* 第i种颜色的团子有A\[i\]个，构造一个相邻两个团子不同色的排列

##### 题解

* 各种乱搞啦啦...

### T2 story

##### 题面

* 给出一个无向图，给边定向成为一个DAG，使得最长路最短

##### 题解

* 相当于求这个无向图最小是几分图

    先预处理出所有独立集再状压dp

    注意全集的子集的子集的数量为3^n

### T3 flame

##### 题面

* 一颗带边权的树，开始可以点燃若干个叶子

    求有多少种不同的燃烧光整棵树时间

##### 题解

* 枚举决定烧光时间的两个叶子结点，贪心地点燃其它叶子，模拟判断是否可行

## Day8

### T1 matrix

##### 题面

* F\[i\]\[j\] = a * F\[i\]\[j−1\] + b * F\[i−1\]\[j\]

   给定a,b与F的第一行第一列，求F\[n\]\[m\]

##### 题解

* 计算第一行第一列每个元素对答案的贡献

   ti = C(n-2,2n-i-2) * a^(n-i) * b^(n-1)

### T2 value

##### 题面

* n个物品，价值vi，代价wi

   选择i后，剩余物品价值都减少wi

   任意选择一些物品，使价值最大

##### 题解

* wi从小到大排序，dp

### <font color=red>T3 binary</font>

##### 题面

* 操作 1 i j : 把A\[i\]的值修改为j

* 操作 2 x y : 询问&sum;(A\[i\]+x)&y (i&isin;\[1,n\])

##### 题解

* y可以拆成多个(2^i)的和

   a&(2^i)的值有规律，每2*2^i一循环

## Day9

### T1 gcd

##### 题面

* &sum;\[gcd(a,b)==a^b\] (a,b&isin;\[1,n\];a&lt;=b)

##### 题解

* 令a=ka' b=kb' (a'与b'互质)，则a'+1=b'

### T2 path

##### 题面

* 一颗树中长度不小于S的路径最短是多长

##### 题解

* 点分治

### <font color=red>T3 bird</font>

##### 题面

* 给出种鸟通过每个洞的时间，每种鸟的数量

   求所有鸟都通过的最少时间(包括每只鸟的等待时间)

##### 题解

* 费用流，左边鸟，右边洞，每个洞复制多遍，表示<font color=red>倒数</font>第i次穿过

   S向鸟连边，容量为数量，费用为0

   洞向T连边，容量为1，费用为0

   鸟i向洞j(倒数第k次)连边，容量为1，费用为w\[i\]\[j\]*k

   <font color=red>动态加边</font>

## Day10

### T1 johann

##### 题面

* 最长公共子序列，每个数组没有重复元素

##### 题解

* 离散化，化解成最长上升子序列

### T2 <font color=red>srwudi</font>

##### 题面

* 从0点开始，每次操作可以向右移x或y或z步，或回到0点，求前n个点能到达几个

##### 题解

* 调整使x&lt;=y&lt;=z

   按z分块，缩点建图，跨块连边边权为1,不跨块边权为0

   SPFA

### T3 czgj

##### 题面

* 操作 1 l r : 给A\[i\]加上Fibonacci\[i-l+1\] (i&isin;\[l,r\])

* 操作 2 l r : 求&sum;A\[i\] (i&isin;\[l,r\])

##### 题解

* 分块，Fibonacci满足可加性

## Day11

### T1 tsm

##### 题面

* 维护一颗MST，支持加边，求u,v两点之间最长边

##### 题解

* 暴力或LCT注意<font color=red>边权为long long</font>

### T2 ihp

##### 题面

* 求&sum;phi\[i\] (i&isin;\[1,n\])

##### 题解

* 线性筛

### T3 qmras

##### 题面

* 给出一个字符串，问有多少对子串相同(位置不同)

##### 题解

* 后缀数组，并查集/rmq统计答案

## Day12

### T1 sequence

##### 题面

* 给定一个自然数序列，每次操作把\[L,R\]内的元素的值减少k(k>0)

    询问什么时候第一次出现值为负的元素

##### 题解

* 倒过来做，操作压入栈中，指针p向右扫，遇到负数就弹栈，直到A\[p\]不为负

### T2 <font color=red>graph</font>

##### 题面

* n个点，m条边，恰好k个奇数度数点的方案数

##### 题解

* dp\[i\]\[j\] : i条边，j个奇点的方案数

```c++
int v(int x) {return x*(x-1)/2;}
dp[i][j]+=g[i-1][j+2]*v(j+2);
dp[i][j]+=g[i-1][j-2]*v(n-j+2);
dp[i][j]-=g[i-2][j]*v(n-j)
dp[i][j]-=g[i-2][j]*v(j);
dp[i][j]+=g[i-1][j]*j*(n-j);
dp[i][j]-=g[i-2][j]*j*(n-j);
dp[i][j]=dp[i][j]/i;
g[i][j]=dp[i][j]+g[i-2][j];
```

### T3 calculate

##### 题面

* 求

<p><script type="math/tex; mode=display" id="MathJax-Element-1">
\sum_{i=k}^{n} \left[ \left( \prod_{j=1}^{k}(i-k+j) \right) \times \binom{n}{i} \times z^{i-k} \right]
</script></p>

##### 题解

<p><script type="math/tex; mode=display" id="MathJax-Element-2">
\begin{aligned}
& \sum_{i=k}^{n} \left[ \left( \prod_{j=1}^{k}(i-k+j) \right) \times \binom{n}{i} \times z^{i-k} \right] \\
= & \sum_{i=k}^{n} \left[ \frac{i!}{(i-k)!} \times \frac{n!}{i! \times (n-i)!} \times z^{i-k} \right] \\
= & \sum_{i=k}^{n} \left[ \frac{n!}{(i-k)! \times (n-i)!} \times z^{i-k} \right] \\
= & \sum_{i=k}^{n} \left[ \frac{n!}{(n-k)!} \times \binom{n-k}{i-k} \times z^{i-k} \right] \\
= & \sum_{i=k}^{n} \left[ \binom{n-k}{i-k} \times z^{i-k} \right] \times \frac{n!}{(n-k)!} \\
= & \sum_{i=0}^{n-k} \left[ \binom{n-k}{i} \times z^{i} \right] \times \frac{n!}{(n-k)!} \\
= & (z+1)^{n-k} \times \frac{n!}{(n-k)!} \\
\end{aligned}
</script></p>

## Day13

### T1 gens

##### 题面

* 定义一个数组若每一个前缀和都非负，则为优质的

* 给定一个数组，求有几种循环移动后是优质的

##### 题解

* 倍长数组，线段树处理

### T2 monogatari

##### 题面

* 一个无向图，有一条边权值不停改变，对于每次改变，求1到n的最短路

##### 题解

* 从1跑一遍最短路，再从n跑一遍最短路

* <font color=red>非随机数据，万万别打SPFA</font>

### T3 news

##### 题面

* 一棵树上，每个时间一个已激活结点可以激活任意一个相邻结点

* 询问对于每个结点，最先激活它最快多久整棵树都能激活

##### 题解

* 树形dp，2遍

</html>

