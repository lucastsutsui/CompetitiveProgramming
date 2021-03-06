#include <bits/stdc++.h>
using namespace std;

bool check (int v[], int n){
  for (int i = 1; i < n; i++)
    if (v[i] < v[i-1]) return false;
  return true;
}

void update (int v[], int i, int j){
  while (i < j){
    int aux = v[i+1];
    v[i+1] = v[i];
    v[i] = aux;
    i+=2;
  }
}

int main ()
{
  int n, v[123];

  cin >> n;

  for (int i = 0; i < n; i++) cin >> v[i];

  while (!check(v,n)){
    int b = 0;
    while (b < n-1 && v[b] <= v[b+1]) b++;
    int e = b+2;
    while (e < n-1 && v[e] > v[e+1]) e+=2;
    update(v,b,e);
    cout << b+1 << ' ' << e << endl;
  }

  return 0;
}
