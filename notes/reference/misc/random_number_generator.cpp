// Description: Initializes a Mersenne Twister random number generator with a time-based seed.
// Time Complexity: O(1) for seeding.
// Space Complexity: O(1) for the generator object itself (state size is fixed).
#include <random>
#include <chrono>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// Description: Creates a uniform integer distribution.
// Usage: uniform_int_distribution<int> dist(min_val, max_val); int random_num = dist(rng);
// Time Complexity: O(1) for generation.
// Space Complexity: O(1).
std::uniform_int_distribution<int> uniform_dist(0, 100);

// Description: Creates a normal (Gaussian) distribution.
// Usage: normal_distribution<> dist(mean, std_dev); double random_num = dist(rng);
// Time Complexity: O(1) (amortized) for generation.
// Space Complexity: O(1).
std::normal_distribution<> normal_dist(0.0, 1.0);

// Description: Creates an exponential distribution.
// Usage: exponential_distribution<> dist(lambda); double random_num = dist(rng);
// Time Complexity: O(1) for generation.
// Space Complexity: O(1).
std::exponential_distribution<> exponential_dist(1.0);
