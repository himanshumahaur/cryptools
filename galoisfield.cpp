#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> a, vector<int> b) {
    vector<int> c(max(a.size(), b.size()));
    for(int i=0; i<a.size(); i++) c[i] = a[i];
    for(int i=0; i<b.size(); i++) c[i] += b[i];
    for(auto &i:c) i = (i%2+2)%2;
    return c;
}

vector<int> sub(vector<int> a, vector<int> b) {
    vector<int> c(max(a.size(), b.size()));
    for(int i=0; i<a.size(); i++) c[i] = a[i];
    for(int i=0; i<b.size(); i++) c[i] -= b[i];
    for(auto &i:c) i = (i%2+2)%2;
    return c;
}

vector<int> mul(vector<int> a, vector<int> b) {
    vector<int> c(a.size() + b.size() - 1);
    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    for(auto &i:c) i = (i%2+2)%2;
    return c;
}

void print(vector<int> vec) {
    for(auto i:vec) cout << i << ", ";
    cout << " | ";
}

void printl(vector<int> vec) {
    for(auto i:vec) cout << i << " , ";
    cout << endl;
}

vector<int> div(vector<int> a, vector<int> b) {
    int ptr = a.size()-1;
    int reg = b.size()-1;

    vector<int> quo;
    vector<int> cur = a;

    while(ptr >= reg) {
        int exp = ptr - reg + 1;

        vector<int> t(exp);
        t[exp-1] = cur[ptr] / b[reg];
        quo = add(quo, t);

        // print(cur);
        // print(b);
        // print(t);

        cur = sub(cur, mul(b, t));
        cur.resize(cur.size()-1);

        // printl(cur);

        ptr--;
    }

    return cur;
}

int cnv(vector<int> vec) {
    int num = 0;
    for(int i=0; i<vec.size(); i++) {
        if(vec[i]) num += pow(2, i);
    }
    return num;
}

int main() {
    int n = 8;
    vector<vector<int>> vec;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                vec.push_back({k, j, i});
            }
        }
    }

    vector<vector<vector<int>>> mata(8, vector<vector<int>>(8));
    vector<vector<vector<int>>> matm(8, vector<vector<int>>(8));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mata[i][j] = add(vec[i], vec[j]);
            matm[i][j] = div(mul(vec[i], vec[j]), {1, 1, 0, 1});
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << cnv(mata[i][j]) << " ";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << cnv(matm[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}
