#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b, a%b);
}

pair<int, int> egcd(int a, int b) {
    if(b==0) return {1, 0};
    else {
        pair<int, int> p = egcd(b, a%b);
        return {p.second, p.first-(a/b)*p.second};
    }
}

int main() {

    return 0;
}