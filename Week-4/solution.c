#include<stdio.h>
#include<stdlib.h>
void merge(long long int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    long long int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(long long int a[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
int main(){
    int t;
    //Input number of testcases
    scanf("%d",&t);

    //For each testcase
    while(t--){
        int p,q,r,i;
        long long int sum = 0;
        long long int sum1,sum2,sumx,sumy,sumz,sumt;

	//Input types of jellies,chocolates and chewing gums
        scanf("%d %d %d",&p,&q,&r);
        long long int a[p],b[q],c[r],sa[p],sc[r];
	
	//Input count of jellies of each type
        for(i=0;i<p;i++){
            scanf("%lld",&a[i]);
        }
        
	//Input count of chocolates of each type
	for(i=0;i<q;i++){
            scanf("%lld",&b[i]);
        }

	//Input count of chweing gums of each type
        for(i=0;i<r;i++){
            scanf("%lld",&c[i]);
        }

	//Sort the types of jellies in increasing order of count
        mergeSort(a,0,p-1);

	//Sort the types of chocolates in increasing order of count
        mergeSort(b,0,q-1);

	//Sort the types of chewing gums in increasing order of count
        mergeSort(c,0,r-1);

	//sa array is the sum of all the types of jellies which are less than its count including itself
	//first element should be itself
        sa[0]=a[0];

	//rest all will be sum of itslef and all less than itself
        for(i=1;i<p;i++){
            sa[i]=a[i]+sa[i-1];
        }

	//sc array is the sume of all types of chewing gums  which are less than its count including itself
        sc[0]=c[0];
        for(i=1;i<r;i++){
            sc[i]=c[i]+sc[i-1];
        }

        int j,k,l,h,mid;
        //for all the choclates type
	for(i=0;i<q;i++){
	    //check if no smaller count of jelly than chocolate
            if(a[0]>b[i]){
                j=-1;
            }
	    //check if all are smaller than given chocolate
            else if(a[p-1]<=b[i]){
                j=p-1;
            }
	    //find the jelly type index using binary search which is just smaller
            else{
                l=0;
                h=p-1;
                while(l<=h){
                    mid=(l+h)/2;
                    if((a[mid]<=b[i]) && (a[mid+1]>b[i])){
                        break;
                    }
                    else{
                        if(a[mid]>b[i]){
                            h= mid-1;
                        }
                        else{
                            l=mid+1;
                        }
                    }
                }
                j=mid;
            }
	    //same for chewing gum
            if(c[0]>b[i]){
                k=-1;
            }
            else if(c[r-1]<=b[i]){
                k=r-1;
            }
            else{
                l=0;
                h=r-1;
                while(l<=h){
                    mid=(l+h)/2;
                    if((c[mid]<=b[i]) && (c[mid+1]>b[i])){
                        break;
                    }
                    else{
                        if(c[mid]>b[i]){
                            h= mid-1;
                        }
                        else{
                            l=mid+1;
                        }
                    }
                }
                k=mid;
            }
	    //calculation of interesting value function starts
	    //check if no jelly count was smaller than choclate count then zero
            if(j==-1){
                sum1=0;
            }
	    //else find the sum
            else{
                sumx = sa[j];
                sumy = (j+1)*b[i];
                sumy = sumy%(1000000007);
                sum1 = sumx+sumy;
            }
	    //same for chewing gum
            if(k==-1){
                sum2=0;
            }
            else{
                sumz = sc[k];
                sumy = (k+1)*b[i];
                sumy = sumy%(1000000007);
                sum2 = sumz+sumy;
            }
	    //finding the interestingvalue function for a given chocolate
            sum1 = sum1%(1000000007);
            sum2 = sum2%(1000000007);	
            sumt = sum1*sum2;
            sumt = sumt%(1000000007);
	    //adding to sum variable which is sum of interestingvalue function of all chocolates
            sum = sum + sumt;
            sum = sum%(1000000007);
        }
	//final interesting value
        printf("%lld\n",sum);
    }
    return 0;
}
