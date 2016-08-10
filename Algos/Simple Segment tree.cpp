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


int arr[100],segtree[2*128 - 1];/// 2 * (closest bigger power of 2) - 1

int maketree(int l,int h,int pos)
{
    if(l==h)
    {
        segtree[pos] =arr[l]%2;    ///counting odd
        return segtree[pos];
    }
    int mid = (l+h)/2;
    segtree[pos] = maketree(mid+1,h,2*pos +2)+ maketree(l,mid,2*pos +1) ; ///R+l=J
    return segtree[pos];

}

int querytree(int ql, int qh,int l,int h,int pos)
{
    if(ql<=l && qh>=h)
    {
        return segtree[pos];
    }
    else if((ql>l && ql<=h) || (qh>=l && qh<h))     ///((ql>=l && ql<=h) || (qh>=l && qh<=h))
    {
        return querytree(ql,qh,l,(l+h)/2,2*pos+1) + querytree(ql,qh,(l+h)/2 +1,h,2*pos+2);
    }
    else
    {
        return 0;
    }
}

int updatetree(int indx, int n,int val,int l,int h,int pos)
{
    int ql=indx , qh=indx;
    if(ql<=l && qh>=h)      ///l==h && l==indx for this case
    {
        segtree[pos]=val%2;
        return segtree[pos];
    }
    else if(ql>h || qh<l)
    {
        return segtree[pos];
    }
    else
    {
        segtree[pos]= updatetree(ql,n,val,l,(l+h)/2,2*pos+1) + updatetree(ql,n,val,(l+h)/2 +1,h,2*pos+2);
        return segtree[pos];
    }
}

int main()
{
    ios::sync_with_stdio(false);

        int n;cin>>n;
        f(i,0,n)
        {
            cin>>arr[i];
        }
        maketree(0,n-1,0);

        int q;cin>>q;
        f(i,0,q)
        {
            int a,b,c;
            cin>>a>>b>>c;
            switch (a)
            {
            case 0:
                updatetree(b-1,n,c,0,n-1,0);
                break;
            case 1:             ///odd
                cout<<c-b-querytree(b-1,c-1,0,n-1,0)+1<<endl;
                break;
            case 2:             ///even
                cout<<querytree(b-1,c-1,0,n-1,0)<<endl;
                break;
            }
        }


    return 0;
}
