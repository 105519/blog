#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long

const int mo=1e9+7;
const int maxn=1010;

int power(int x,int k)
{
	int res=1;
	while (k)
	{
		if (k&1) res=(LL)res*x%mo;
		x=(LL)x*x%mo;
		k>>=1;
	}
	return res;
}

namespace Lagrange{
	int n,x[maxn],y[maxn];
	int Pi[maxn],num[maxn];
	int Ans[maxn],Den;
	void solve()
	{
		int i,j;
//		scanf("%d",&n);
//		for (i=1;i<=n;i++)
//			scanf("%d%d",&x[i],&y[i]);
		memset(Ans,0,sizeof(Ans));
		Pi[0]=1;
		for (i=1;i<=n;i++)
		for (j=n;j>=0;j--)
		{
			LL tmp=j?Pi[j-1]:0;
			tmp-=(LL)x[i]*Pi[j];
			tmp%=mo;
			Pi[j]=tmp;
		}
		for (i=1;i<=n;i++)
		{
			Den=y[i];
			for (j=1;j<=n;j++)
				if (j!=i) Den=(LL)Den*power(x[i]-x[j],mo-2)%mo;
			for (j=0;j<=n;j++)
				num[j]=Pi[j];
			for (j=n;j>=1;j--)
			{
				Ans[j-1]+=(LL)num[j]*Den%mo;
				Ans[j-1]%=mo;
				num[j-1]+=(LL)num[j]*x[i]%mo;
				num[j-1]%=mo;
			}
		}
		for (j=0;j<n;j++)
			if (Ans[j]<0) Ans[j]+=mo;
//		for (i=n-1;i>=0;i--)
//			printf("%d ",Ans[i]);
//		printf("\n");
	}
}

