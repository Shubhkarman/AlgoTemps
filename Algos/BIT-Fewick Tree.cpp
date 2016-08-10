#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<chrono>
#define endl "\n"
#define ull unsigned long long
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define all(c) c.begin(),c.end()
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f(i,a,b) for(int i=a;i<b;i++)

using namespace std;


int arr[100],bit[101];

int parent(int x)
{
    int y=~x +1;
    y = x&y; /// ONLY WORK FOR UNSIGNED INT
    y=x-y;
    /// or simply y = x&(x-1);
    return y;
}
int next(int x)
{
    int y = x &(~x +1); /// ONLY WORK FOR UNSIGNED INT
    ///or simply y=x&(-x);
    y=x+y;
    return y;
}
int maketree(int n,int pos,int val)
{
    if(pos<=n)
    {
        bit[pos]+=val;
        maketree(n,next(pos),val);
    }
    else return 0;
}
int updatetree(int n,int pos,int val)
{
    if(pos<=n)
    {
        bit[pos]+=val;
        return updatetree(n,next(pos),val);
    }
    else return 0;

}
int querytree(int h)    ///calculates 0 to h-1 sum
{
    if(h==0)
        return 0;
    return bit[h]+querytree(parent(h));
}



int main()
{
    int n;
    cin>>n;
    f(i,0,n)
    {
        cin>>arr[i];
    }
    f(i,0,n)
    {
        maketree(n,i+1,arr[i]);
    }
    int q;cin>>q;
    f(i,0,q)
    {
        int a,b,c;
        cin>>a>>b>>c;   ///indexed with 1.... tree indexes with 0
        switch(a)
        {
        case 0:
            updatetree(n,b,c-arr[b-1]);
            break;
        case 1:
            cout<<querytree(c)-querytree(b-1)<<endl;  ///we need to intially send b+1 and c+1
            ///but since they are indexed from 1 and prog is indexed from 1, it is the same...
            break;
        }
    }
}
