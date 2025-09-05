// Implements the Berlekamp-Massey algorithm to find the shortest linear recurrence for a sequence.
// Time complexity: O(N^2)
// Space complexity: O(N)
template<typename T>
vector<T> berlekampMassey(const vector<T> &sequence) {
    vector<T> recurrence;    // the linear recurrence sequence we are building
    vector<T> prev_recurrence; // the best previous version of recurrence to use
    int fail_pos = -1;     // the index at which the best previous version of recurrence failed on
    for (int i=0; i<(int)sequence.size(); i++) {
        // evaluate recurrence(i)
        // delta = s_i - \sum_{j=1}^n c_j s_{i-j}
        // if delta == 0, recurrence(i) is correct
        T delta = sequence[i];
        for (int j=1; j<=(int)recurrence.size(); j++)
            delta -= recurrence[j-1] * sequence[i-j];
        if (delta == 0)
            continue;   // recurrence(i) is correct, keep going
        // now at this point, delta != 0, so we need to adjust it
        if (fail_pos == -1) {
            // this is the first time we're updating recurrence
            // s_i was the first non-zero element we encountered
            // we make recurrence of length i + 1, the values don't matter yet.
            recurrence.resize(i + 1, 0);
            fail_pos = i;
        } else {
            // we need to use a previous version of recurrence to improve on this one
            vector<T> correction = prev_recurrence;
            // 1. multiply the sequence by -1 and insert a 1 on the left
            for (T &x : correction)
                x = -x;
            correction.insert(correction.begin(), 1);
            // 2. multiply the sequence by delta / d(f + 1)
            T df1 = 0;
            for (int j=1; j<=(int)correction.size(); j++)
                df1 += correction[j-1] * sequence[fail_pos+1-j];
            assert(df1 != 0);
            T coef = delta / df1;
            for (T &x : correction)
                x *= coef;
            // 3. insert i - f - 1 zeros on the left
            vector<T> zeros(i - fail_pos - 1);
            zeros.insert(zeros.end(), correction.begin(), correction.end());
            correction = zeros;
            // now we have our new recurrence: recurrence + correction
            vector<T> temp = recurrence; // save the last version of recurrence because it might be the next prev_recurrence
            if (recurrence.size() < correction.size())
                recurrence.resize(correction.size());
            for (int j=0; j<(int)correction.size(); j++)
                recurrence[j] += correction[j];
            // finally, let's consider updating prev_recurrence
            if (i - (int) temp.size() > fail_pos - (int) prev_recurrence.size()) {
                // better length-to-fail_pos ratio, let's update!
                prev_recurrence = temp;
                fail_pos = i;
            }
        }
    }
    return recurrence;
}
