#include<bits/stdc++.h> 

using namespace std;

#define MAXN 100010
#define GROUPS 8

int MB[MAXN][GROUPS];
int MF[MAXN][GROUPS];
int PS[MAXN][GROUPS];

int main() {

  int N, K; cin >> N >> K;
  vector<pair<int, int> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    A[i].second--;
  }
  sort(A.begin(), A.end());

  /* Construct backstep masks */
  for(int i = 0; i < GROUPS; i++) {
    MB[0][i] = 1 << A[0].second;
  }
  for(int i = 1; i < N; i++) {
    int bt = 1 << A[i].second;

    MB[i][0] = bt;
    for(int j = 1; j < GROUPS; j++) {
      if(MB[i - 1][j] & bt) {
        MB[i][j] = MB[i - 1][j];
      } else {
        MB[i][j] = bt | MB[i - 1][j - 1];
      }
    }
  }

  /* Construct forward step masks */
  for(int i = 0; i < GROUPS; i++) {
    MF[N - 1][i] = 1 << A[N - 1].second;
  }
  for(int i = N - 2; i >= 0; i--) {
    int bt = 1 << A[i].second;

    MF[i][0] = bt;
    for(int j = 1; j < GROUPS; j++) {
      if(MF[i + 1][j] & bt) {
        MF[i][j] = MF[i + 1][j];
      } else {
        MF[i][j] = bt | MF[i + 1][j - 1];
      }
    }
  }

  /* Construct partial sums */
  for(int i = 0; i < N; i++) {
    memcpy(PS[i + 1], PS[i], sizeof(PS[i]));
    ++PS[i + 1][A[i].second];
  }

  int result = -1;
  for(int j = K - 1; j < GROUPS; j++) {
    vector<int> V(1 + GROUPS);
    map<vector<int>, int> cost_map;

    /* Compute the earliest starts for given masks
     * and normalized partial sums. */
    for(int i = N - 1; i >= 0; i--) {
      int base = -1;
      int m = V[GROUPS] = MF[i][j];
      if(__builtin_popcount(m) <= j) continue;
      for(int k = 0; k < GROUPS; k++) {
        if(m & 1 << k) {
          if(base == -1) {
            base = PS[i][k];
          }
          V[k] = PS[i][k] - base;
        } else {
          V[k] = PS[i][k];
        }
      }
      cost_map[V] = A[i].first;
    }

    /* Find best start points for each ending position. */
    for(int i = 0; i < N; i++) {
      int base = -1;
      int m = V[GROUPS] = MB[i][j];
      if(__builtin_popcount(m) <= j) continue;
      for(int k = 0; k < GROUPS; k++) {
        if(m & 1 << k) {
          if(base == -1) {
            base = PS[i + 1][k];
          }
          V[k] = PS[i + 1][k] - base;
        } else {
          V[k] = PS[i + 1][k];
        }
      }

      map<vector<int>, int>::iterator it = cost_map.find(V);
      if(it != cost_map.end() && it->second < A[i].first) {
        result = max(result, A[i].first - it->second);
      }
    }
  }

  cout << result << endl;
  return 0;
}
