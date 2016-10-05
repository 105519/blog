# Summary of Noip&Hnoi Training

## <font color=red>A</font><font color=purple>u</font><font color=green>g</font> <font color=orange>2</font><font color=blue>7</font>

### A 大胖吃花生(10/20)

* ***unfinished***

### B 题目(40/40)

* ***unfinished***

### ~~C 没给钱(100/100)~~

## <font color=blue>Sep 1</font>

### ~~savecat (100/100)~~

### study

#### 题目

* n个点，m条无向边，每次求连上第L~R条边后，图中有多少联通块

#### 题解

* 询问按L从小到大排序，指针l从1到n扫一遍，维护每个位置r的答案

  用LCT维护最晚消失森林，森林里面每有一条边联通块个数就少一个

  用BIT维护每条边在不在最晚消失森林里

### game

#### 题目

* 给出一个有向图，每个点都会被至少一条由1到n的路径经过，要求尽可能增大整张图的边权和，但1到n的最长路不会增大

#### 题解

* 设修改图后1到i的最长路长度为`f[i]`，1到n的原最长路长度为G

$$
\begin{aligned}
& \max { \sum _{(i,j)\in E} (f[j]-f[i]) } \\
& \forall f[i] >=0 \\
& f[n] <= G \\
& \forall f[i]+w[i][j] <=j
\end{aligned}
$$

* 目标化简

$$
\begin{aligned}
& \sum _{(i,j)\in E} (f[j]-f[i]) \\
= & \sum {deg_{in}[j] \times f[j]} - \sum {deg_{out}[i] \times f[i]} \\
= & \sum {deg_{delta}[i] \times f[i]} \\
\end{aligned}
$$

* 裸的单纯形啊，~~套模板就好了啊~~

## <font color=green>Sep 3</font>

### ~~fht (100/100)~~

### ~~phantom (100/100)~~

### sherco (60/60)

#### 题目

* 把一颗树切成若干颗树，使得每棵树大小相同，求方案数

#### 题解

* 对于每种大小，最多有一种切法

  对于每种大小k，如果正好有n/k颗子树sz是k的倍数，则可行

  O(n*ln(n))

## <font color=blue>Sep 4</font>

### polygon (90/90)

#### 题目

* 一个只有直角的多边形可以用类似`LLRLLRLLRLLR`的序列来表示，其中L表示90°，R表示270°，一个合法的多边形至少存在一个多边形内一个点能直接看到多边形上每一个点，求长度为n的序列有多少个合法的，循环同构不计

#### 题解

* R旁边一定是两个L，将LRLRL...LRLRL删去，合法的序列最后会只剩4个L

  令`x=(n+4)/2`，则$Ans = \binom{x}{4} + \binom{x-1}{4}$，高精度，FFT

### game (0/0)

* ***unfinished***

### deskmate (20/20)

#### 题目

* 班上有n名学生，每个人有一个理想同桌，要求两两配对，满足尽可能多的人的愿望，并要求在此前提下满足男女搭配尽量多

> 注意如果A喜欢B，B也喜欢A，使AB同桌对答案只产生1的贡献

#### 题解

* 环套树森林双关键字dp，难点在环上，注意环上相连2点必定有一点参与产生贡献的配对，2次dp取较大值

## <font color=green>Sep 6</font>

### ~~grain (100/100)~~

### sail (0/100)

#### 题目

* 求两个数组的最长公共上升子序列

#### 题解

* 设f\[i\]\[j\]为以数组A前i个数中的某一个与数组B中的第j个数结尾的最长长度，则有

$$
\begin{aligned}
f[i][j] = &
\begin{cases}
\max \limits_{k<j,b[k]<b[j]} f[i-1][k]+1 &\ a[i]=b[j] \\
f[i-1][j] &\ a[i]=b[i] \\
\end{cases} \\
= & \begin{cases}
\max \limits_{k<j,b[k]<a[i]} f[i-1][k]+1 &\ a[i]=b[j] \\
f[i-1][j] &\ a[i]=b[i] \\
\end{cases}
\end{aligned}
$$

* 记录一下f\[i-1\]\[j\]的最大值，即可O(n*m)做了

### mode (80/80)

#### 题目

* 对于一个数组，每次求[L,R]之间的加权众数

#### 题解

* 设mode(A)表示集合A中的众数，不加权

  $mode(A \bigcup B) \in mode(A) \bigcup B$

* 这个结论对于加权时也成立，分块，预处理出第i至j块的众数

## <font color=blue>Sep 8</font>

### equation (30/30)

* ***unfinished***

  It's too hard for me to solve this problem right now.

### blackflip (50/30)

* ***unfinished***

  It's too hard for me to solve this problem right now.

### graph (50/100)

#### 题目

* 给定一张无向图，动态加边/删边，求是否为二分图

#### 题解

* 离线，对图维护一颗删除时间的最大生成树

  加入新的边时若是删旧边，且旧边与树形成奇环，则将旧边加入集合S

  删除边时要在S中同时删除，询问就成了问S集合为不为空

## <font color=green>Sep 10</font>

### ~~choose (100/100)~~

### climb (50/100)

#### 题目

* 一张有向图上，有一个起点，多个终点，找一条从起点到一个终点的路径，使得经过点数最多(点带权)

#### 题解

* tarjan缩点，top序dp

* <font color=red>!!!top序不能直接在BFS上嵌套!!!</font>

### ~~trans (100/100)~~

## <font color=blue>Sep 11</font>

### random (20/100)

#### 题目

* 给你一堆点，<font color=red>可能有***重点***，三点共线</font>

  问2^n种选点方案的凸包上点的个数的总和

#### 题解

* 对于每个点算贡献

  枚举一个点与这个点在凸包上连接的两条边，这样就是O(n^3)的

  two pointers优化掉一个n，算上排序就成了O(n^2\*log(n))

### substr (20/20)

#### 题目

* 有n个字符串Si，每次询问第l至第r个串中有多少个是询问串Pi的母串

#### 题解

* query(l,r,Pi)=query(1,r,Pi)-query(1,l-1,Pi)

  每个问题描述成两个query(1,x,Pi)，离线下来，按x排序

  对于m个询问串P建立AC自动机，并建立fail树

  每加入一个新的Sx时，设Sx在AC自动机上经过了u1,u2,...

  相当于把root->u1,root->u2,...标黑

  然后再把这次标黑的点的答案加1

  可以把u1,u2,...离线下来，按虚树的方法维护答案，就是O(n\*log(n))的了

### product (0/0)

* ***unfinished***

  It's too hard for me to solve this problem right now.

## <font color=green>Sep 13</font>

### elevator (0/100)

* 题意不想说了，直接讲讲怎么暴0的吧...

  > 标准答案
  >
  > 0000
  >
  > 0000
  >
  > 1101
  >
  > 0001

  > 我的答案
  >
  > 0 0 0 0
  >
  > 0 0 0 0
  >
  > 1 1 0 1
  >
  > 0 0 0 1

### ~~updown (100/100)~~

### ~~transport (100/100)~~

## <font color=blue>Sep 15</font>

### sad (10/10)

* ***unfinished***

### new (80/60)

* ***unfinished***

### tri(0/0)

#### 题目

* n个点，m条边，边有红绿蓝三种，求生成树数量，其中绿边不超过g条，蓝边不超过b条

#### 题解

* 先看只有红绿边的情况

  把红边当1，绿边当x，用Matrix Tree求出的第x^i项的系数就是正好有i条绿边时生成树的数量

* 由于边数小于n，蓝边可以当x^n，于是第x^(i+j*n)项的系数就是正好有i条绿边，j条蓝边时生成树的数量，使用拉格朗日插值，注意有`n*n`项

## <font color=green>Sep 16</font>

### ~~magician (100/100)~~

### ~~guard (100/100)~~

### laser(95/100)

* ***unfinished***

## <font color=green>Sep 20</font>

### ~~copy (100/100)~~

### game (0/0)

#### 题目

* 求出6个只含有4与7的不超过m位的数(eg.447744)，可以有0，使它们经过加减后等于n

#### 题解

* dp\[k\]\[i\]\[j\]\[val\]:第k位，i个正数，j个负数，上一次进位为val的方案数

* 口胡超级简单，实现起来2333...

### sxbk(10/100)

#### 题目

* 计算几何，给你一个凸包，多组询问一条直线在凸包里面的线段有多长

#### 题解

* 旋转卡壳+二分答案，其实打对了，被样例坑了...

## <font color=blue>Sep 22</font>

### party (20/20)

* ***unfinished***

### block (0/0)

#### 题目

* n*n棋盘上每个格子有一个标号，不会存在3个格子编号相同，支持一下两种操作

    1. 行变换，将每一行按任意顺序打乱

    2. 列变换，将每一列按任意顺序打乱

* 给出一个初始矩阵和一个目标矩阵，求最少的变换次数

#### 题解

1. 两个矩阵元素不一样则无解，否则一定有解，且答案不超过3

2. Ans=0:完全一样

3. Ans=1:每一行元素一样或每一列元素一样

4. Ans=2:[戳这里]()

5. Ans=3:前面四种都不是

### exploration (10/10)

#### 题目

* 给你一个图，任务一求m条点不重复的路径(S与T除外)的最短路，任务二求边不重复的最短路

#### 题解

* 拆点费用流

* <font color=red>题目很简单，只是套了几层伪装就没看出来了...</font>

## <font color=green>Sep 24</font>

### ~~number (100/100)~~

### ~~matrix (100/100)~~

### ~~divisor (100/100)~~

## <font color=blue>Sep 25</font>

### ~~bubble (100/100)~~

### alive (60/100)

#### 题目

* 给定一个图，每条边有两种权值——长度与美观度，求最小生成树期望美观度

  注意相同边权不超过30条

#### 题解

* kruskal + matrix tree

  <font color=red> 注意记录答案用long double!!!</font>

### tornado (30/100)

#### 题目

* 求fib序列在模n意义下最短循环节`//fib[0]=0 fib[1]=1`

#### 题解

* 先讲结论

  n分解质因子，$n=p1^{k1}p2^{k2}...pk^{pk}$，则$L(n)=lcm(L(p1^{k1}),L(p2^{k2}),...,L(pk^{pk}))$

  通过打表可得$L(p^k)=L(p) p^{k-1}$

    1. n<=5直接算，`L(2)=3,L(3)=8,L(5)=20`

    2. 若5是模p的二次剩余，Ans为(p-1)的因子

    3. 若5是模p的非二次剩余，Ans为(2(p+1))的因子

* 证明

    > 以下计算均为模n意义下

    1. n<=5暴力解出，怎么会错`2333...`

    2. 当5是模p的二次剩余时，即$5^{\frac{p-1}{2}}\equiv1(mod\ p)$，则$\sqrt{5}$有值

        任务变成了证明`fib[p-1]=0&&fib[p]=1`

        $$
        \begin{aligned}
        fib[p-1] = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^{p-1} - \left( \frac{1-\sqrt{5}}{2} \right)^{p-1} \right] \\
        = & \frac{1}{\sqrt{5}} \left( 1 - 1 \right) \\
        = & 0 \\
        \end{aligned}
        $$
        
        $$
        \begin{aligned}
        fib[p] = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^{p} - \left( \frac{1-\sqrt{5}}{2} \right)^{p} \right] \\
        = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right) - \left( \frac{1-\sqrt{5}}{2} \right) \right] \\
        = & \frac{1}{\sqrt{5}} \sqrt{5} \\
        = & 1 \\
        \end{aligned}
        $$

    3. 当5是模p的非二次剩余时，即$5^{\frac{p-1}{2}}\equiv-1(mod\ p)$，则$\sqrt{5}^{p-1}=-1$

        任务变成了证明`fib[p]=-1&&fib[p+1]=0`，这样就会有一遍负值的fib序列，两边长度均为为p+1，则2(p+1)必为一个循环节

        * 前置技能

            1. $\forall i \in [1,p-1]\ ,\ \binom{p}{i} = 0$

            2. $\forall i \in [2,p-1]\ ,\ \binom{p+1}{i} = 0$

            3. $(x+1)^{p} = \sum \limits_{i=0}^{p} \binom{p}{i}\ x^{i} = x^{p}+1$

            4. $(x+1)^{p+1} = \sum \limits_{i=0}^{p+1} \binom{p+1}{i}\ x^{i} = x^{p+1} + (p+1)x^{p} + (p+1)x + 1$

        * 开始证明

        $$
        \begin{aligned}
        fib[p] = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^{p} - \left( \frac{1-\sqrt{5}}{2} \right)^{p} \right] \\
        = & \frac{(1+\sqrt{5})^{p}-(1-\sqrt{5})^{p}}{2^{p} \sqrt{5}} \\
        = & \frac{(1+\sqrt{5}^{p})-(1-\sqrt{5}^{p})}{2^{p} \sqrt{5}} \\
        = & \frac{2\sqrt{5}^{p}}{2^{p} \sqrt{5}} \\
        = & \frac{\sqrt{5}^{p-1}}{2^{p-1}} \\
        = & \frac{-1}{1} \\
        = & -1 \\
        \end{aligned}
        $$
        
        $$
        \begin{aligned}
        fib[p+1] = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^{p+1} - \left( \frac{1-\sqrt{5}}{2} \right)^{p+1} \right] \\
        = & \frac{(1+\sqrt{5})^{p+1}-(1-\sqrt{5})^{p+1}}{2^{p+1} \sqrt{5}} \\
        = & \frac{(1+(p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}+\sqrt{5}^{p+1}) - (1+(p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p}+(-\sqrt{5})^{p+1})} {2^{p} \sqrt{5}} \\
        = & \frac{((p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}) - ((p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p})} {2^{p} \sqrt{5}} \\
        = & \frac{2(p+1)(\sqrt{5}+\sqrt{5}^{p})}{2^{p} \sqrt{5}} \\
        = & \frac{1+\sqrt{5}^{p-1}}{2^{p-1}} \\
        = & \frac{1-1}{1} \\
        = & 0 \\
        \end{aligned}
        $$

        证毕，撒花

## <font color=green>Sep 27</font>

### ~~toll (100/100)~~

### ~~sort (100/100)~~

### ~~room (100/100)~~

## <font color=blue>Sep 29</font>

### maze (0/0)

* ***unfinished***

  It's too hard for me to solve this problem right now.

### a+b (100/30)

#### 题目

* 对于正整数x，定义fib表达法

    1. `fib[1]=1,fib[2]=2`

    2. $x = \sum \limits_{i=1}^{n} a_{i}fib_{i}$

    3. an!=0，且以an,...,a2,a1顺序，字典序最大

* 给定两个合法的表示法，求它们的和用表示法如何表达

#### 题解

* 一个表示法只有0和1，因为`0,0,2,0 = 1,0,0,1`

  所以和序列只有0,1,2

* 先消除2

    * 从an到a1扫，严格按照以下优先级，有`|`符号表示在最左边的特殊处理(即`|a1,a2`，`ai,ai+1`)

        1. `2,1,0 ===> 1,0,1`

        2. `1,2,0 ===> 1,2,0`

        3. `|2,0 ===> |0,1`

        4. `|0,2,0 ===> |1,0,1`

        5. `0,0,2,0 ===> 1,0,0,1`

        6. `1,0,2,0 ===> 2,0,0,1`

        7. `2,0,2,0 ===> 2,0,2,0`

    * 从a1到an扫，`1,2,0 ===> 0,1,1`

* 再消除1，从a1到an，每次处理出一串连续的1，`1,1,0 ===>0,0,1`

### road (0/30)

* ***unfinished***

  It's too hard for me to solve this problem right now.

> Written with [StackEdit](https://stackedit.io/).

