#include <iostream>
#include <vector>
#ifndef flyod_alg
#define flyod_alg

template <typename T> void flyod(std::vector<std::vector<T>> &graph) {
  int n = graph.size();
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }
}

#endif