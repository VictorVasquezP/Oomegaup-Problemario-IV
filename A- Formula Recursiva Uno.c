#include <stdio.h>
long factorial(int n); 
int main(int argc, char *argv[]) {
	int n,t;
	scanf("%d",&n);
	factorial(n);
	t=factorial(n);
	printf("%d",t);
	return 0;
}
long factorial(int n){
	if(n<=5){
		return 1;
	}else{
		return factorial(n-2)*5;
	}
}
