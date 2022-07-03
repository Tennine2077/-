#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int list[10003];

int search(int* arr,int i,int len)
{
    if(list[i]!=0) return list[i];
    else
    {
        int k=1;
        while(i+k<len)
        {
            if(arr[i]<arr[i+k])
            {
                int num = search(arr,i+k,len);
                if(list[i]<num+1) list[i] = num+1;
            }
            k+=1;
        }
        if (list[i]==0) list[i]=1;
        return list[i];
    }
}


int main()
{
    memset(list,0,sizeof(list));
    int arr[] = {0,5,6,7,8,9,1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    search(arr,0,len);
    int i=len,ans=list[i--];
    while(i--) if(ans<list[i]) ans=list[i];//求最大值
    printf("%d",ans);
    return 0;
}