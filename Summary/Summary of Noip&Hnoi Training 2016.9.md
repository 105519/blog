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

* n个点，m条无向边，每次求连上第L-R条边后，图中有多少联通块

#### 题解

* ***unfinished***

### game

* ***unfinished***

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

* ***unfinished***

### game (0/0)

* ***unfinished***

### deskmate (20/20)

* ***unfinished***

## <font color=green>Sep 6</font>

### ~~grain (100/100)~~

### sail (0/100)

* ***unfinished***

### mode (80/80)

* ***unfinished***

## <font color=blue>Sep 8</font>

### equation (30/30)

* ***unfinished***

### blackflip (50/30)

* ***unfinished***

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

* ***unfinished***

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

* ***unfinished***

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


