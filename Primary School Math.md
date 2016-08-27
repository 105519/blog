# Primary School Math ~~小学~~奥数

### 前言

* 好的，今天我们来讲 **真•<font color=red>小学</font>奥数**

### 7647:余数相同问题

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 已知三个正整数 a，b，c。现有一个大于1的整数x，将其作为除数分别除a，b，c，得到的余数相同。

* 请问满足上述条件的x的最小值是多少？

* 数据保证x有解。

* a,b,c&lt;=1000000

#### 样例

* in  : 300 262 205

* out : 19

#### 初步分析

> gcd(300-262,262-205)=19

* gcd(abs(a-b),abs(b-c)) ?

```c++
#include<cstdio>
#include<algorithm>
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",gcd(abs(b-a),abs(c-b)));
}
#6169148提交状态状态: Wrong Answer
```

* 才怪咧。

#### 题解

* 其实是gcd(abs(a-b),abs(b-c))的**最小**约数...

```c++
#include<cstdio>
#include<algorithm>
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int tmp=gcd(abs(b-a),abs(c-b));
	if (tmp==0) {puts("2"); return 0;}
	for (int i=2;i*i<=tmp;i++)
		if (tmp%i==0) {printf("%d",i); return 0;}
	printf("%d\n",tmp);
}
#6169148提交状态: Accepted
```

* 当然1除外

### 7648:蓄水池水管问题

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 蓄水池有甲、丙两条进水管和乙、丁两条排水管。

* 要灌满一池水，单开甲管需要a小时，单开丙管需要c小时；要排光一池水，单开乙管需要b小时，单开丁管需要d小时。

* 现在池内没有水，如果按甲乙丙丁的顺序循环单开各水管，每次每管开1小时，则多长时间后水开始溢出水池？

* 保证一定会在有限时间内出现水溢出水池的情况。

* a,b,c,d&lt;=10

#### 样例

* in  : 3 4 5 6

* out : 24.90

#### 初步分析

* 数据这么小为什么不模拟？

> 我竟无言以对

#### 题解

* 首先将 1,1/a,1/b,1/c,1/d 统一乘以 abcd，避免精度问题。

* 为了方便

```c++
#define TOT a*b*c*d
#define Va b*c*d
#define Vb a*c*d
#define Vc a*b*d
#define Vd a*b*c
```

> TOT=360 , Va=120 , Vb=90 , Vc=72 , Vd=60

* 4小时一循环，则每个循环增加水量为`Va-Vb+Vc-Vd`

> 120-90+72-60=42

* 如果某次循环后还差不超过`max(Va,Va-Vb+Vc)`的水水池就满了，则停止循环。

> 360-42x<=max(120,120-90+72)=120
>
> 得x最小为6

* 剩下的模拟

> Ans=6\*4.0+(360-42\*6)/120=24.9

```c++
#include<cstdio>
int a,b,c,d,tot,once,times;
int va,vb,vc,vd,t1,t2;
double Ans=0.0;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	va=b*c*d; vb=a*c*d;
	vc=a*b*d; vd=a*b*c;
	tot=a*b*c*d;
	a=va; b=vb; c=vc; d=vd;
	once=a-b+c-d;
	t1=(tot-a+b-c+once-1)/once;
	t2=(tot-a+once-1)/once;
	times=t1<t2?t1:t2;
	if (times<0) times=0;
	Ans+=4.0*times;
	tot-=times*once;
	if (tot<=a) Ans+=1.0*tot/a;
	else
	{
		tot-=a,Ans+=1.0;
		tot+=b,Ans+=1.0;
		Ans+=1.0*tot/c;
	}
	printf("%.2lf\n",Ans);
}
#6169866提交状态: Accepted
```

### 7649:我家的门牌号

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 我家住在一条短胡同里，这条胡同的门牌号从1开始顺序编号。

* 若其余各家的门牌号之和减去我家门牌号，恰好等于n，求我家的门牌号及总共有多少家。

* 数据保证有唯一解。

* n&lt;=100000

#### 样例

* in  : 100

* out : 10 15

#### 题解

> n=100=(1+2+3+...+tot)-2\*id
>
> id<=tot

* 手动枚举`tot`

* 发现`tot=15`时方程有正整数解，此时`id=10`

```c++
#include<cstdio>
int n,sum;
int main()
{
	scanf("%d",&n);
	for (int i=1;;i++)
	{
		sum+=i;
		if (sum>n&&!((sum-n)&1))
		{
			printf("%d %d\n",(sum-n)/2,i);
			break;
		}
	}
}
#6169929提交状态: Accepted
```

### 7650:不定方程求解

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 给定正整数a，b，c。求不定方程 ax+by=c 关于未知数x和y的所有非负整数解组数。

* a,b,c&lt;=1000

#### 样例

* in  : 2 3 18

* out : 4

#### 初步分析

* 数据这么小为什么不n^2暴力？

> 我竟无言以对

#### 题解

* 首先把a,b,c同除`gcd(a,b,c)`

> gcd(2,3,18)=1 , 2/1=2 , 3/1=3 , 18/1=18

* 此时若a,b不互质则无解

> gcd(2,3)=1

* 用`ex_gcd(a,b,x,y)`得出`ax+by=1`一组解

> x=-1 y=1

* x,y同乘c

> x=-18 y=18

* 调整出x最小的一组非负整数解

> x=0 y=6

* 答案等于`y/a+1`

> Ans=4

```c++
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ex_gcd(int a,int b,int &x,int &y)
{
	if (!b) {x=1,y=0; return a;}
	else
	{
		int r=ex_gcd(b,a%b,x,y);
		int t=x; x=y; y=t-a/b*y;
		return r;
	}
}
int main()
{
	int a,b,c,t,x,y;
	scanf("%d%d%d",&a,&b,&c);
	t=ex_gcd(ex_gcd(a,b,x,y),c,x,y);
	a/=t; b/=t; c/=t;

	if (ex_gcd(a,b,x,y)!=1) {puts("0"); return 0;}
	x*=c; y*=c;
	if (y<=0) swap(a,b),swap(x,y);
	t=-x/b; x+=t*b; y-=t*a;
	if (x<0) x+=b,y-=a;
	printf("%d\n",y/a+1);
}
#6170312提交状态: Accepted
```

### 7653:地球人口承载力估计

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 假设地球上的新生资源按恒定速度增长。

* 照此测算，地球上现有资源加上新生资源可供x亿人生活a年，或供y亿人生活b年。

* 为了能够实现可持续发展，避免资源枯竭，地球最多能够养活多少亿人？

* x,a,y,b&lt;=10000

#### 样例

* in  : 110 90 90 210

* out : 75.00

#### 题解

* 经典牛吃草

* 童年的美好回忆啊

* `Ans=(110*90-90*210)/(110-90)=75`

```c++
#include<cstdio>
double x,a,y,b;
int main()
{
	scanf("%lf%lf%lf%lf",&x,&a,&y,&b);
	printf("%.2lf\n",(x*a-y*b)/(a-b));
}
#6171496提交状态: Accepted
```

### 7656:李白的酒

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 李白街上走，提壶去打酒。遇店加一倍，见花喝一斗。n遇店和花，喝光壶中酒。

* 试问壶中原有多少酒？

* n&lt;=100

#### 样例

* in  : 3

* out : 0.87500

#### 题解

* 这么水的题我本来不想讲的，但是这~~文言文~~题面真是太熟悉了，总让我回想起小时侯的温馨记忆。

* `2(2(2x-1)-1)-1=0`

* 得`x=0.875`

```c++
#include<cstdio>
int n;
double Ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		Ans=(1.0+Ans)/2.0;
	printf("%.5lf\n",Ans);
}
#6171579提交状态: Accepted
```

### 7828:最大公约数与最小公倍数

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 两个正整数的最大公约数是G，最小公倍数是L，它们的和最小是多少？

* G,L&lt;=10000

#### 样例

* in  : 14 280

* out : 126

#### 题解

* 设两个数分别为`L*a`与`L*b` (a&lt;=b;a,b互质)

> 14a 14b

* 则`L*a*b=G`

> 14\*a\*b=280

* `a*b=G/L`

> a\*b=20

* 枚举a，检查a,b是否互质，更新答案

> 当a=1时，b=20，a与b互质，14a+14b=294
>
> 当a=2时，b=10，a与b不互质，14a+14b=168
>
> 当a=4时，b=5，a与b互质，14a+14b=126

```c++
#include<cstdio>
int G,L,A,B,Ans=0x7fffffff;
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
int main()
{
	scanf("%d%d",&G,&L);
	L/=G;
	for (int i=1;i*i<=L;i++) if (L%i==0)
	{
		A=i; B=L/i;
		if (gcd(A,B)==1)
			Ans=Ans<A+B?Ans:A+B;
	}
	printf("%d\n",Ans*G);
}
#6174100提交状态: Accepted
```

### 7831:计算星期几

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 假设今天是星期日，那么过a^b天之后是星期几？

* a&lt;=100 , b&lt;=10000

#### 样例

* in  : 3 2000

* out : Tuesday

#### 题解

* 循环节: 3 2 6 4 5 1

* b=2000时是星期二

* 写程序的话就直接快速幂或二进制幂

```c++
#include<cstdio>
int a,b,res=1;
int main()
{
	scanf("%d%d",&a,&b);
	for (;b;b>>=1)
		b&1?res=res*a%7:0,a=a*a%7;
	if (res==1) puts("Monday");
	if (res==2) puts("Tuesday");
	if (res==3) puts("Wednesday");
	if (res==4) puts("Thursday");
	if (res==5) puts("Friday");
	if (res==6) puts("Saturday");
	if (res==0) puts("Sunday");
}
#6174288提交状态: Accepted
```

### 7832:最接近的分数

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 分母不超过 N 且 小于 A/B 的最大最简分数是多少？

* n,a,b&lt;=1000

#### 样例

* in  : 100 7 13

* out : 50 93

#### 题解

* 可以点这里[baidu](http://zhidao.baidu.com/question/875899291719340212.html)

* 不过我们还是打n^2暴力吧...

```c++
#include<cstdio>
int n,a,b,a0=0,b0=1;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++)
	for (int j=n;j>=1;j--)
	{
		if (i*b>=a*j) break;
		if (a0*j<i*b0) a0=i,b0=j;
	}
	printf("%d %d\n",a0,b0);
}
#6180447提交状态: Accepted
```

### 7833:幂的末尾

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 幂a^b的末3位数是多少？

* a&lt;=100 , b&lt;=10000

#### 样例

* in  : 7 2011

* out : 743

#### 题解

* `7^4 mod 1000 = 401`


|x^0|x^1|x^2|x^3|x^4|x^5|
|:-:|:-:|:-:|:-:|:-:|:-:|
|1  |   |   |   |   |   |
|1  |1  |   |   |   |   |
|1  |2  |1  |   |   |   |
|1  |3  |3  |1  |   |   |
|1  |4  |6  |4  |1  |   |
|1  |5  |10 |10 |5  |1  |


* `401^5=(400+1)^5`

* `400^0 mod 1000 = 1`

* `2*400^1 mod 1000 = 0`

* `10*400^2 mod 1000 = 0`

* `10*400^3 mod 1000 = 0`

* `5*400^4 mod 1000 = 0`

* `400^5 mod 1000 = 0`

* 所以`401^5 mod 1000 = 1`

* 也就是`7^20 mod 1000 = 1`

* 所以`7^2011 === 7^11 (mod 1000)`

* 答案为743

```c++
#include<cstdio>
int a,b,res=1;
int main()
{
	scanf("%d%d",&a,&b);
	for (;b;b>>=1)
		b&1?res=res*a%1000:0,a=a*a%1000;
	if (res<=9) putchar('0');
	if (res<=99) putchar('0');
	printf("%d\n",res);
}
#6174880提交状态: Accepted
```

### 7834:分成互质组

总时间限制: 1000ms 内存限制: 65536kB

#### 描述

* 给定n个正整数，将它们分组，使得每组中任意两个数互质。至少要分成多少个组？

* n&lt;=10 , Ai&lt;=10

#### 样例

* in: 14 20 33 117 143 175

* out : 3

#### 题解

* 因为14,20,175三个数两两不互质，因此这三个数必须分开，所以至少3组。

* 调整后发现(14,33)(20,117)(143,175)就是一种分法。

* 然后我们还是打暴力吧...

```c++
#include<cstdio>
int n,a[15],x[15],Ans=0x7fffffff;
int gcd(int a,int b) {return b?gcd(b,a%b):a;}
void dfs(int id,int col)
{
	if (col>=Ans) return;
	if (id==n+1) {Ans=col; return;}
	for (int i=1;i<=col;i++)
	{
		x[id]=i;
		bool flag=1;
		for (int j=1;j<id;j++) if (x[j]==x[id])
			if (gcd(a[j],a[id])!=1) {flag=0; break;}
		if (flag) dfs(id+1,col);
	}
	x[id]=col+1;
	dfs(id+1,col+1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,1);
	printf("%d\n",Ans);
}
#6182507提交状态: Accepted
```

