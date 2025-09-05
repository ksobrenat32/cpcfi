// Description: Groups identical strings by comparing their hash values.
// Assumes the existence of a `compute_hash` function that returns a hash for a string.
// Time Complexity: O(N*L + N*log(N)) where N is the number of strings and L is their average length.
// Space Complexity: O(N) to store hashes and groups.
vector<vector<int>> group_identical_strings(const vector<string>& string_list) {
    int num_strings = string_list.size();
    vector<pair<long long, int>> hashes(num_strings);
    for (int i = 0; i < num_strings; i++) {
        hashes[i] = {compute_hash(string_list[i]), i};
    }

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < num_strings; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first) {
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
