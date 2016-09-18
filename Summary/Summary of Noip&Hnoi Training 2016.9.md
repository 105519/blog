# Summary of Noip&Hnoi Training

## <font color=red>A</font><font color=purple>u</font><font color=green>g</font> <font color=pink>2</font><font color=blue>7</font>

### A 大胖吃花生(10/20)

* ***unfinished***

### B 题目(40/40)

* ***unfinished***

### ~~C 没给钱(100/100)~~

## <font color=blue>Sep 1</font>

### ~~savecat (100/100)~~

### study

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

### equation 解方程

* ***unfinished***

### blackflip 游戏

* ***unfinished***

### graph

* ***unfinished***

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

