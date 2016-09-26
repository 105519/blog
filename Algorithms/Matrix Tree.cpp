#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n,m,D[50][50],A[50][50];

namespace MatrixTree{
	double C[50][50];
#define zero(x) ((x>0?x:-x)<1e-6)

	int determinant(double a[50][50],int n)
	{
		int i,j,k,sign=0;
		double ret=1.0;
		for (i=1;i<=n;i++)
		{
			if (zero(a[i][i]))
			{
				for (j=i+1;j<=n;j++)
					if (!zero(a[j][i])) break;
				if (j==n+1) return 0;
				for (k=i;k<=n;k++)
					swap(a[i][k],a[j][k]);
				sign++;
			}
			ret*=a[i][i];
			for (j=i+1;j<=n;j++)
			for (k=n;k>=i;k--)
				a[j][k]-=a[i][k]*a[j][i]/a[i][i];
		}
		if (sign&1) ret*=-1.0;
		return (int)round(abs(ret));
	}

	int solve()
	{
		int i,j;
		for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			C[i][j]=D[i][j]-A[i][j];
		return determinant(C,n-1);
	}
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		D[u][u]++; D[v][v]++;
		A[u][v]++; A[v][u]++;
	}
	printf("%d\n",MatrixTree::solve());
}

