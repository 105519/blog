#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

bool chkmin(double &a,double b) {if (a>b) {a=b; return 1;} return 0;}

const int maxn=110;
double mat[maxn][maxn];

namespace SimplexAlgorithm{
	int n,m;
	double _A[maxn][maxn];

	/*
	void write(double A[][maxn],int d)
	{
		int i,j;
		for (i=0;i<=m+2*d;i++)
		{
			if (i==m+1)
			{
				for (j=0;j<=n+2*d+1;j++)
					printf("-------");
				printf("\n");
			}
			for (j=0;j<=n+2*d;j++)
			{
				if (j==n+1) printf("  | ");
				if (j<=n) printf("%7.2lf",A[i][j]);
				else printf("%.2lf ",A[i][j]);
			}
			printf("|\n");
		}
		printf("\n\n");
	}
	*/

	void PIVOT(double A[][maxn],int l,int e)
	{
		int i,j;
		for (i=0;i<=m;i++)
		for (j=0;j<=n;j++) _A[i][j]=0;

		for (j=0;j<=n;j++) if (j!=e)
			_A[l][j]=A[l][j]/A[l][e];
		_A[l][e]=1/A[l][e];
		for (i=0;i<=m;i++) if (i!=l)
		{
			for (j=0;j<=n;j++) if (j!=e)
				_A[i][j]=A[i][j]-A[i][e]*_A[l][j];
			_A[i][e]=-A[i][e]*_A[l][e];
		}

		for (i=0;i<=m;i++)
		for (j=0;j<=n;j++) A[i][j]=_A[i][j];
	}

	bool SIMPLEX(double A[][maxn],int m)
	{
		int i,j,l,e;
		double delta;
		for (;;)
		{
			e=l=0; delta=100000000000.0;
			for (j=n;j>=1;j--)
				if (A[0][j]>1e-6) e=j;
			if (!e) break;
			for (i=1;i<=m;i++) if (A[i][e]>1e-6)
				l=chkmin(delta,A[i][0]/A[i][e])?i:l;
			if (!l) return 0;
			PIVOT(A,l,e);
		}
		return 1;
	}

	bool INITIALIZE_SIMPLEX(double A[][maxn])
	{
		int i,j,k=1;
		for (i=1;i<=m;i++)
			if (A[k][0]>A[i][0]) k=i;
		if (A[k][0]>=0) return 1;
		n++; m++;
		for (j=0;j<=n;j++)
			A[m][j]=A[0][j],A[0][j]=0.0;
		for (i=0;i<=m;i++) A[i][n]=-1.0;
		A[0][n]=-1.0;
		PIVOT(A,k,n);
		SIMPLEX(A,m-1);
		for (j=0;j<=n;j++)
			swap(A[0][j],A[m][j]);
		m++;
		for (j=0;j<=n;j++)
			A[m][j]=-A[m-1][j];
		return 1;
	}

	bool work()
	{
		int i,j;
		scanf("%d%d",&m,&n);
		for (i=0;i<=m;i++)
		for (j=0;j<=n;j++)
			scanf("%lf",&mat[i][j]);

		mat[0][0]*=-1.0;
		if (!INITIALIZE_SIMPLEX(mat)) return 0;
		//write(mat,0);
		SIMPLEX(mat,m);
		mat[0][0]*=-1.0;
		//write(mat,0);
	}
}

