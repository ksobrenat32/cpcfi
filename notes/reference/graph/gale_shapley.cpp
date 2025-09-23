// Gale-Shapley algorithm for the Stable Marriage Problem.
// Finds a stable matching between two sets of N elements each (e.g., N men and N women).
// A matching is stable if there are no two people who would both prefer each other to their current partners.
// This implementation produces a "man-optimal" solution, where each man gets the best possible partner.
// Time complexity: O(N^2), as each man proposes to each woman at most once.
// Space complexity: O(N^2) to store the preference lists and rankings.

#include <vector>
#include <queue>

// N: number of men/women.
// men_preferences: men_preferences[m] is a list of women in man m's order of preference.
// women_preferences: women_preferences[w] is a list of men in woman w's order of preference.
// Returns a vector where result[w] = m, meaning woman w is matched with man m.
std::vector<int> gale_shapley_stable_matching(int N, const std::vector<std::vector<int>>& men_preferences, const std::vector<std::vector<int>>& women_preferences) {
    // Pre-process women's preferences for O(1) lookup of a man's rank.
    // women_rank[w][m] stores the rank of man m in woman w's preference list.
    std::vector<std::vector<int>> women_rank(N, std::vector<int>(N));
    for (int w = 0; w < N; ++w) {
        for (int rank = 0; rank < N; ++rank) {
            int m = women_preferences[w][rank];
            women_rank[w][m] = rank;
        }
    }

    // A queue of free men, initially all men are free.
    std::queue<int> free_men;
    for (int m = 0; m < N; ++m) {
        free_men.push(m);
    }

    // The current partner of each woman, -1 if she is free.
    std::vector<int> woman_partner(N, -1);
    // next_proposal_idx[m] stores the index of the next woman man m will propose to in his list.
    std::vector<int> next_proposal_idx(N, 0);

    while (!free_men.empty()) {
        int m = free_men.front();
        free_men.pop();

        int woman_to_propose = men_preferences[m][next_proposal_idx[m]];
        next_proposal_idx[m]++;

        if (woman_partner[woman_to_propose] == -1) {
            // The woman is free, so she accepts the proposal.
            woman_partner[woman_to_propose] = m;
        } else {
            int current_partner = woman_partner[woman_to_propose];
            // The woman compares the new proposer (m) with her current partner.
            if (women_rank[woman_to_propose][m] < women_rank[woman_to_propose][current_partner]) {
                // Woman prefers the new proposer, m.
                woman_partner[woman_to_propose] = m;
                // The old partner is now free and goes back into the queue.
                free_men.push(current_partner);
            } else {
                // Woman rejects the proposal, so man m remains free and will propose to the next on his list.
                free_men.push(m);
            }
        }
    }

    return woman_partner;
}
