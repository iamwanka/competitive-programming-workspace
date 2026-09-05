#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long G;

    // Read number of cells and profit per boat
    if (!(cin >> N >> G)) return 0;

    // T[i] = excavation cost of cell i (0 if already water)
    vector<long long> T(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> T[i];

    // Prefix sums:
    // PS[i] = T[1] + T[2] + ... + T[i]
    // Allows O(1) interval cost queries
    vector<long long> PS(N + 1, 0);
    for (int i = 1; i <= N; ++i)
        PS[i] = PS[i - 1] + T[i];

    // Check if we can place m boats of lengths 1..m
    // Total cells needed = m(m+1)/2 <= N
    auto feasible_m = [&](long long m) {
        return m * (m + 1) / 2 <= (long long)N;
    };

    // Find maximum possible number of boats (m_max)
    int m_max = 0;
    {
        int lo = 0, hi = 500000; // safe upper bound
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (feasible_m(mid)) lo = mid;
            else hi = mid - 1;
        }
        m_max = lo;
    }

    const long long INF = (long long)9e18;

    /*
        DP explanation:

        Fprev[i] = minimum excavation cost to place (k-1) boats
                   such that the (k-1)-th boat ends at position i

        Fcurr[i] = same, but for k boats

        We only keep two layers (rolling DP).
    */

    vector<long long> Fprev(N + 1, 0);   // Base case: 0 boats costs 0
    vector<long long> Fcurr(N + 1, INF);

    // Cmin[k] = minimum excavation cost to place exactly k boats (anywhere)
    vector<long long> Cmin(m_max + 1, 0);

    // Iterate over number of boats k = 1..m_max
    for (int k = 1; k <= m_max; ++k) {

        /*
            prefMin[i] = min(Fprev[0..i])
            Used to optimize transition:
            min over all valid previous endpoints
        */
        vector<long long> prefMin(N + 1);
        prefMin[0] = Fprev[0];
        for (int i = 1; i <= N; ++i)
            prefMin[i] = min(prefMin[i - 1], Fprev[i]);

        // Reset current DP layer
        fill(Fcurr.begin(), Fcurr.end(), INF);

        // Compute DP for k boats
        // The k-th boat has length k and ends at position i
        for (int i = k; i <= N; ++i) {

            // Cost to excavate cells [i-k+1, i]
            long long cost_k = PS[i] - PS[i - k];

            // Best cost to place k-1 boats ending before i-k+1
            long long bestPrev = prefMin[i - k];

            // DP transition
            Fcurr[i] = cost_k + bestPrev;
        }

        // Find minimum cost among all possible ending positions
        long long best = INF;
        for (int i = k; i <= N; ++i)
            best = min(best, Fcurr[i]);

        Cmin[k] = best;

        // Prepare for next iteration
        Fprev.swap(Fcurr);
    }

    // Compute final answer:
    // profit = k * G - Cmin[k]
    long long ans = 0; // placing 0 boats is allowed

    for (int k = 1; k <= m_max; ++k) {
        if (Cmin[k] >= INF / 2) continue;
        ans = max(ans, (long long)k * G - Cmin[k]);
    }

    cout << ans << "\n";
    return 0;
}
