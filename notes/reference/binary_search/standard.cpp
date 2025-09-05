// Finds a target in a sorted vector. Time: O(log n), Space: O(1).
int binary_search(vector<int>& sorted_vec, int target) {
    int left = 0, right = sorted_vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_vec[mid] == target) return mid;
        if (sorted_vec[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Finds the first element >= target. Time: O(log n), Space: O(1).
int lower_bound(vector<int>& sorted_vec, int target) {
    int left = 0, right = sorted_vec.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        sorted_vec[mid] < target ? left = mid + 1
                                 : right = mid;
    }
    return left;
}

// Finds the first element > target. Time: O(log n), Space: O(1).
int upper_bound(vector<int>& sorted_vec, int target) {
    int left = 0, right = sorted_vec.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        sorted_vec[mid] <= target ? left = mid + 1
                                  : right = mid;
    }
    return left;
}

// Finds the square root of a number with a given precision. Time: O(log(n/precision)), Space: O(1).
double sqrt_precision(double number, double precision=1e-6) {
    double left = 0, right = number;
    // The loop can also be `while (right - left > precision)`
    for (int i = 0; i < 100; ++i) {
        double mid = (left + right) / 2;
        if (mid*mid < number) left = mid;
        else right = mid;
    }
    return left;
}

// Finds the minimum value satisfying a monotonic condition. Time: O(log(R) * C), Space: O(1).
int find_min_valid(vector<int>& nums, int k) {
    auto is_valid = [&](int x) {
        // Monotonic condition check (e.g., is it possible to split `nums` into `k` subarrays with max sum `x`?)
        return true; // placeholder
    };

    int left = 0, right = 1e9; // Adjust search space bounds as needed
    while (left < right) {
        int mid = left + (right - left) / 2;
        is_valid(mid) ? right = mid
                      : left = mid + 1;
    }
    return left;
}
