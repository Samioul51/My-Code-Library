#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
 
typedef unsigned long long int ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef map<char, long long> mcl;
typedef map<char, int> mci;
typedef set<int> si;
typedef set<ll> sl;
typedef set<char> sc;
typedef multiset<ll> msl;
typedef vector<long long> vl;
typedef vector<int> vin;
typedef vector<char> vc;
typedef vector<string> vs;

ll i,j;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define sp <<" "<<
#define spp <<" ";
#define nl <<'\n';
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).begin(),(x).end(),greater<ll>()
#define minus cout<<-1<<endl;
#define zero cout<<0<<endl;
#define one cout<<1<<endl;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back 
#define MOD 1000000007
#define INF 1e18
#define PI 3.1415926535897932384626433832795
  
template <class T>
void print_v(vector<T> &v) {  for (auto x : v) cout << x << " "; cout <<endl; }

//PBDS
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    For Set less<T>
    For Multiset less_equal<T>
*/

//LCM
ll lcm(ll a,ll b) { return a/__gcd(a,b)*b; }
 
//Prime number
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

//Sieve of Eratosthenes
 
const ll seiveN=1e5+2;
//Prime--->marked with 1 in the array
//Non Prime--->marked with 0 in the array
ll isPrime[seiveN];
 
void seive(){
   f(i,2,seiveN)isPrime[i]=1;

   isPrime[0]=isPrime[1]=0;

    for(i=2;i*i<seiveN;i++){
        if(isPrime[i]){
            for(j=i*i;j<seiveN;j+=i){
                isPrime[j]=0;
            }
        }
    }
}
 
//Divisors
 
vin divisors(int n){
    vin div;
    cf(i,1,sqrt(n)){
        if(n%i==0){
            div.pb(i);
            if(i!=n/i)
                div.pb(n/i);
        }
    }
    return div;
}

//counting divisors

const ll X=1e5+1;
ll divcount[X];

void countingDivisior(){
    cf(i,1,X){
        for(j=i;j<=X;j+=i)divcount[j]++;
    }
}
 
//Grid Type validation for Graph

vector<pll> gridD={{-1,0},{1,0},{0,-1},{0,1}};
bool valid(ll a,ll b,ll n,ll m){
    if(a<0 or a>=n or b<0 or b>=m)
        return false;
    return true;
}

//Custom compare function for Pairs
 
bool comp(pll a,pll b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

//324=6^2*9^1

bool productOfTwo(int val,int a,int b){
    int apow=1;
    while(apow<=val){
        int bpow=1;
        while(apow*bpow<=val){
            if(apow*bpow==val)
                return true;
            if(b>1)
                bpow*=b;
            else
                break;
        }
        if(a>1)
            apow*=a;
        else
            break;
    }
    return false;
}

//Sort each column of 2D Matrix

void colSort(vector<vector<ll>>& matrix,ll rows,ll cols){
    for(j=0;j<cols;j++){
        vector<ll> temp;
        for(i=0;i<rows;i++){
            temp.pb(matrix[i][j]);
        }
        sort(all(temp));
        for(i=0;i<rows;i++){
            matrix[i][j]=temp[i];
        }
    }
}
 
//Kadane's Algorithm

ll kadane(vl& v){
    ll n=v.size(),cur=0,maxx=LLONG_MIN;
    f(i,0,n){
        cur+=v[i];
        maxx=max(maxx,cur);
        if(cur<0)
            cur=0;
    }
    return maxx;
}
 
//Prefix Sum
 
vl prefixSum(vl& v){
    ll n=v.size();
    vl pre(n+1,0);
    pre[1]=v[0];
    f(i,1,n){
        pre[i+1]=pre[i]+v[i];
    }
    return pre;
}
 
//Starts from here...

void SIR(){
    
}
 
int main(){
    fast;
    int tc;
    tc = 1;
    cin>>tc;
    for(int test=1;test<=tc;test++){
        SIR();
    }
    return 0;
}
