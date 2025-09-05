// LPS for s, lps[i] could also be defined as the longest prefix which is also a proper suffix
vi computeLPS(string s){
    size_t len = 0;
    size_t M = s.size();
    vi lps(M, 0);

    size_t i = 1;
    while(i < M) {
        if( s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0){
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Get number of occurrences of a pattern in a text using KMP
// O(N+M)
size_t KMPOccurrences(string pattern, string text){
    vi lps = computeLPS(pattern); // LPS array

    size_t M = pattern.size();
    size_t N = text.size();

    size_t i = 0; // Index for text
    size_t j = 0; // Index for pattern

    size_t cnt = 0; // Counter

    while ((N - i) >= (M - j)) {
        // Watch for the pattern
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        // If the full match found
        if (j == M) {
            cnt++;
            j = lps[j - 1];
        }

        // Mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return cnt;
}
