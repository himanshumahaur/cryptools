#include <bits/stdc++.h>
using namespace std;

using ll = long long int;


ll gcd(ll a, ll b) {
    if(b==0) return a;
    else return gcd(b, a%b);
}

pair<ll, ll> egcd(ll a, ll b) {
    if(b==0) return {1, 0};
    else {
        pair<ll, ll> p = egcd(b, a%b);
        return {p.second, p.first-(a/b)*p.second};
    }
}

bool isPrime(ll n) {
    return true;
}

ll enc(ll M, ll E, ll N) {
    return ll(pow(M, E))%N;
}

ll dec(ll C, ll D, ll N) {
    return ll(pow(C, D))%N;
}

long long int modulo(long long int a, long long int b) {
    return (a % b + b) % b;
}

int main() {

    ll P = 7;
    ll Q = 19;

    ll N = P*Q;
    ll T = (P-1)*(Q-1);

    ll E = 29;
    
    // randomly select and satisfy following

    // if (isPrime(E) && E<T && T%E!=0) cout << "valid";
    // else cout << "invalid";

    ll D = egcd(T, E).second;

    ll M = 60;

    ll tmp = pow(M, E);
    cout << N << endl;
    cout << modulo(tmp, N) << endl;


    // ll C = N + enc(60, E, N);
    // cout << C << endl;

    return 0;
}