#include<stdio.h>
#include<stdlib.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long int l,r,c;
		scanf("%ld %ld %ld",&l,&r,&c);
		if(c<=r){
			printf("first\n");
		}
		else{
			c = c - r;
			c = c%(l+r);
			if(c==0){
				printf("first\n");
			}
			else if(c<=l){
				printf("second\n");
			}
			else{
				printf("first\n");
			}
		}
	}
return 0;
}
