#include <bits/stdc++.h>

using namespace std;

class FreqStack {
  public:
    FreqStack() { max_freq = 0; }

    void push(const int val) {
        ++freq[val];
        freq_dist[freq[val]].push(val);
        max_freq = max(max_freq, freq[val]);
    }

    int pop() {
        const int val = freq_dist[max_freq].top();
        freq_dist[max_freq].pop();
        --freq[val];
        if (freq_dist[max_freq].empty()) {
            --max_freq;
        }
        return val;
    }

  private:
    // Map from elements to their frequency.
    unordered_map<int, int> freq;
    // Map from frequency to elements.
    unordered_map<int, stack<int>> freq_dist;
    // Tracks maximum frequency.
    int max_freq;
};
