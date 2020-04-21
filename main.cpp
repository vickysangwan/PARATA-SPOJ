#include<bits/stdc++.h>
using namespace std;
bool canMake(vector<int> &cooks,int P,int L,int mid)
{
    int total=0;
    for(int i=0;i<L;i++)
    {
        int sum=0,j=1;
        while(sum<=mid)
        {
            sum=sum+j*cooks[i];
            total++;
            j++;
        }
        total--;
    }
    if(total>=P)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int P;
        cin>>P;
        int L;
        cin>>L;
        vector<int> cooks(L);
        for(int i=0;i<L;i++)
        {
            cin>>cooks[i];
        }
        int max_time=0;
        for(int i=1;i<=P;i++)
        {
            max_time+=i*cooks[0];
        }
        int s=0;
        int e=max_time;
        int ans=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int ispossible=canMake(cooks,P,L,mid);
            if(ispossible)
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
