// x^2+y^2=r^2

// (y1-y2) = r1-r2
// (y2^2+r2^2)^1/2
#include <stdio.h>
#include <math.h>
int main(){
	int n;
	scanf("%d",&n);
	int min = -1;
	for (int i = 0; i < n; ++i)
	{
		int x,y,r;
		scanf("%d %d %d",&x,&y,&r);
		double siz = sqrt(pow(y,2)+pow(r,2));
		printf("%f\n",siz);
	}
	return 0;
}
