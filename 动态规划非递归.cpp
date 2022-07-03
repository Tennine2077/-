#include<iostream>
#include<string.h>
using namespace std;

int list[10003];

int main()
{
    memset(list,0,sizeof(list));
    const int arr[] = {0,5,6,7,8,9,1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    int ans=0;
    for(int i=len-1;i>=0;i--)
    {
        int k=1;
        while(i+k<len)
        {
            if(arr[i]<arr[i+k]&&list[i]<list[i+k]+1) list[i] = list[i+k]+1;
            k++;
        }
        if(list[i]==0) list[i]=1;
        if(ans<list[i]) ans=list[i];
    }
    // int i=len;
    // while(i--) printf("%d",list[i]);
    printf("%d",ans);
    return 0;
}
