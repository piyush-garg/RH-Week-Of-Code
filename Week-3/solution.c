#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        long long int n,x,y,m;
        x=0;
        y=0;
        scanf("%lld",&n);
        m = n/4;
        x = x + m*(-2);
        y = y + m*(-2);
        if(n%4==0){
            n = n;
        }
        else if(n%4==1){
            x = x + n;
        }
        else if(n%4==2){
            x = x + n-1;
            y = y + n;
        }
        else{
            x = x-2;
            y = y + n-1;
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
