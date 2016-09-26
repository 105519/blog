#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn=530000;
const double pi=acos(-1.0);

namespace FFT{
	int An,Bn,Cn,n,step;
	int rev[maxn];

	struct Complex {
		double x,y;
		Complex() {}
		Complex(double x,double y):x(x),y(y) {}
		Complex operator + (const Complex &C) const {return Complex(x+C.x,y+C.y);}
		Complex operator - (const Complex &C) const {return Complex(x-C.x,y-C.y);}
		Complex operator * (const Complex &C) const {return Complex(x*C.x-y*C.y,x*C.y+y*C.x);}
	}A[maxn],B[maxn],C[maxn];

	void fft(Complex a[],LL flag)
	{
		LL i,j,k;
		for (i=0;i<n;i++)
			if (i<rev[i]) swap(a[i],a[rev[i]]);
		for (k=1;k<n;k<<=1)
		{
			Complex wk_1(cos(pi/k),flag*sin(pi/k));
			for (i=0;i<n;i+=(k<<1))
			{
				Complex wk_j=Complex(1.0,0.0);
				for (j=0;j<k;j++)
				{
					Complex x=a[i+j];
					Complex y=a[i+j+k]*wk_j;
					a[i+j]=x+y;
					a[i+j+k]=x-y;
					wk_j=wk_j*wk_1;
				}
			}
		}
		if (flag==-1) for (i=0;i<n;i++) a[i].x/=n;
	}

	void Init(const int a[],const int b[])
	{
		int i;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		An=a[0]; Bn=b[0];
		for (i=1;i<=a[0];i++)
			A[i-1]=Complex(a[i],0.0);
		for (i=1;i<=b[0];i++)
			B[i-1]=Complex(b[i],0.0);
	}

	void Solve()
	{
		int i;
		Cn=An+Bn-1;
		for (n=1,step=0;n<Cn;n<<=1,step++);
		for (i=0;i<n;i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)<<(step-1));
		fft(A,+1);
		fft(B,+1);
		for (i=0;i<n;i++) C[i]=A[i]*B[i];
		fft(C,-1);
	}

	void GetNum(int Ans[])
	{
		int i;
		Ans[0]=FFT::Cn+1;
		for (i=1;i<=Ans[0];i++)
			Ans[i]=round(FFT::C[i-1].x);
		for (i=1;i<=Ans[0];i++)
		{
			Ans[i+1]+=Ans[i]/10;
			Ans[i]%=10;
		}
		while (!Ans[Ans[0]]) Ans[0]--;
	}
}

struct BigInt{
	int v[maxn];

	void scan()
	{
		int i; v[0]=0;
		char c=getchar();
		while (c<'0'||c>'9') c=getchar();
		while (c>='0'&&c<='9')
			v[++v[0]]=c-'0',c=getchar();
		for (i=1;i<=v[0];i++)
			if (i<v[0]-i+1) swap(v[i],v[v[0]-i+1]);
	}

	void print()
	{
		for (int i=v[0];i;i--)
			putchar(v[i]+'0');
		putchar('\n');
	}

	BigInt operator * (const BigInt B) const
	{
		static BigInt Ans;
		int i;
		FFT::Init(this->v,B.v);
		FFT::Solve();
		FFT::GetNum(Ans.v);
		return Ans;
	}

#define Ans(x) (Ans.v[(x)])
	BigInt operator / (const int x) const
	{
		static BigInt Ans=*this;
		int res=0,i;
		for (i=Ans(0);i>=1;i--)
		{
			res=res*10+Ans(i);
			Ans(i)=res/x;
			res%=x;
		}
		while (!Ans(Ans(0))) Ans(0)--;
		return Ans;
	}

#define V(x) (this->v[(x)])
	void operator /= (const int x)
	{
		int res=0,i;
		for (i=V(0);i>=1;i--)
		{
			res=res*10+V(i);
			V(i)=res/x;
			res%=x;
		}
		while (!V(V(0))) V(0)--;
	}

	void operator -= (const int x)
	{
		int res=x,i;
		for (i=1;i<=V(0);i++)
		{
			V(i)-=res%10;
			res/=10;
			if (V(i)<0) V(i)+=10,res++;
		}
		while (!V(V(0))) V(0)--;
	}
};

