#include <bits/stdc++.h>
#define TAM 5000
#define ATTEMPT 100
#define WRONG 2000
#define K1 3
#define K2 10
using namespace std;

bitset<TAM+1> disc;
int tab[TAM+1][4]={0};

void update (bitset<TAM+1> &curr, int k, int att){
  disc[k-1] = 1;
  curr[k-1] = (~curr[k-1]);

  for (int i = 0; i < k; i++){
    if (i >= 3500 && att < 90) break;
    if (curr[i] == 0){
      tab[i][0] += k;
      tab[i][1]++;
    }
    else{
      tab[i][2] += k;
      tab[i][3]++;
    }
  }

  if (att < 90){
    for (int i = 0; i < 3500; i++){
      if (disc[i]==0){
	if (tab[i][1]>20 && tab[i][3]>20 && tab[i][0]/(double)tab[i][1] > tab[i][2]/(double)tab[i][3] + K2)
	  curr[i] = 0;
	else if (tab[i][1]>20 && tab[i][3]>20 && tab[i][0]/(double)tab[i][1] + K2 < tab[i][2]/(double)tab[i][3])
	  curr[i] = 1;
	else if (tab[i][1] > tab[i][3] + K1) curr[i] = 1;
	else if (tab[i][3] > tab[i][1] + K1) curr[i] = 0;
	else curr[i] = rand()%2;
      }
    }
  }
 
  else{ /* last attempt */
    for (int i = 0; i < k; i++){
      if (disc[i]==0){
	if (tab[i][1]>0 && tab[i][3]>0 && tab[i][0]/(double)tab[i][1] > tab[i][2]/(double)tab[i][3])
	  curr[i] = 0;
	else if (tab[i][1]>0 && tab[i][3]>0 && tab[i][0]/(double)tab[i][1] < tab[i][2]/(double)tab[i][3])
	  curr[i] = 1;
	else
	  curr[i] = ((tab[i][1]>tab[i][3])? 0 : 1);
      }
    }
  }
}

int main ()
{
  int res;
  bitset<TAM+1> curr;
  int tab[TAM+1][4];

  srand(12345);

  for (int i = 0; i < TAM; i++){
    tab[i][0] = tab[i][1] = tab[i][2] = tab[i][3] = 0;
    curr[i] = rand()%2;
    disc[i] = 0;
  }

  for (int i = 0; i < ATTEMPT; i++){
    for (int j = 0; j < TAM; j++) cout << curr[j];
    cout << endl; fflush(stdout);

    cin >> res;

    update(curr, res, i);
  }

  return 0;
}
