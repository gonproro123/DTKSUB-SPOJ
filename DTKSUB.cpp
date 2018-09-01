
//  main.cpp
//  DTKSUB

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const long long MOD = 1e9+7;
const int base = 97;
const int SIZE= 5 * 1e5 +5;

typedef unsigned long long ull;
//-------------------

int n,k;
ull Hash[SIZE],pow[SIZE];
ull a[SIZE];
string S;
void Init()
{
    pow[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        pow[i] = pow[i-1] * base % MOD;
        Hash[i]=( Hash[i-1]*base + S[i] - 32 ) % MOD;
    }
}
int Get_Hash(int i,int j)
{
    return (Hash[j] - Hash[i-1]*pow[j-i+1] + MOD*MOD) % MOD;
}
bool check(int length)
{
    
    int Res=0;
    int h=0;
    fill_n(a, SIZE, 0);
    for(int i=1;i <= n - length + 1; i++)
    {
        a[++h] = Get_Hash(i, i+length-1);
    }
    sort(a+1,a+h+1);
    int Count = 1;
    for(int i=2;i<=h;i++)
    {
        if(a[i] == a[i-1])
        {
            Count++;
            Res=max(Res,Count);
        }
        else Count=1;
    }
    if(Res >= k)
        return true;
    return false;
}
void solve()
{
    if(k == 1)
    {
        cout<<n<<"\n";
        exit(0);
    }
    int lo = 1;
    int Val = 0;
    int hi = n;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(check(mid))
        {
            lo = mid + 1;
            Val= max(mid, Val);
        }
        
        else hi = mid - 1;
    }
    cout <<  Val <<endl;
}
int main()
{
    cin >> n >> k;
    cin >> S;
    S = " " + S;
    Init();
    solve();
    return 0;
}

