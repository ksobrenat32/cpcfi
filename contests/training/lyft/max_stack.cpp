/*
Problem: Design a max stack data structure that functions like a regular stack but also efficiently supports retrieving and removing the maximum element in the stack.

Class implementation:

    MaxStack(): Initializes an empty stack.
    push(x: int) -> None: Pushes the element x onto the stack.
    pop() -> int: Removes and returns the top element of the stack.
    top() -> int: Retrieves the top element without removing it O(1)O(1) time complexity).
    peekMax() -> int: Retrieves the maximum element in the stack without removing it.
    popMax() -> int: Retrieves and removes the maximum element from the stack. If multiple occurrences exist, only the topmost one is removed.
*/
#include <bits/stdc++.h>
using namespace std;

class MaxStack {
    public:
        void push(int x){
            st.push_back(x);
            ms.insert(x);
        }

        int top(){
            return st.back();
        }

        int pop(){
            int t = st.back();
            st.pop_back();
            ms.erase(ms.find(t));
            return t;
        }

        int peekMax() {
            return *ms.rbegin();
        }

        int popMax() {
            auto x = prev(ms.end());
            int t = *x;
            ms.erase(x);
            for(auto it = st.rbegin(); it != st.rend(); ++it){
                if(*it == t){
                    st.erase(it.base() - 1);
                    break;
                }
            }
            return t;
        }
    private:
        // Keep real stack
        vector<int> st;
        // Keep ordered set (multiset to allow repeated values)
        multiset<int> ms;
};

int main(){
    // Test 1: Basic operations
    cout << "=== Test 1: Basic push, top, pop ===" << '\n';
    MaxStack ms1;
    ms1.push(5);
    ms1.push(1);
    ms1.push(3);
    cout << "top: " << ms1.top() << " (expected: 3)" << '\n';
    cout << "pop: " << ms1.pop() << " (expected: 3)" << '\n';
    cout << "top: " << ms1.top() << " (expected: 1)" << '\n';
    cout << '\n';

    // Test 2: peekMax and popMax
    cout << "=== Test 2: peekMax and popMax ===" << '\n';
    MaxStack ms2;
    ms2.push(5);
    ms2.push(1);
    ms2.push(5);
    cout << "top: " << ms2.top() << " (expected: 5)" << '\n';
    cout << "peekMax: " << ms2.peekMax() << " (expected: 5)" << '\n';
    cout << "popMax: " << ms2.popMax() << " (expected: 5, removes topmost)" << '\n';
    cout << "top: " << ms2.top() << " (expected: 1)" << '\n';
    cout << "peekMax: " << ms2.peekMax() << " (expected: 5)" << '\n';
    cout << "pop: " << ms2.pop() << " (expected: 1)" << '\n';
    cout << "top: " << ms2.top() << " (expected: 5)" << '\n';
    cout << '\n';

    // Test 3: Multiple duplicates
    cout << "=== Test 3: Multiple duplicate values ===" << '\n';
    MaxStack ms3;
    ms3.push(3);
    ms3.push(7);
    ms3.push(3);
    ms3.push(7);
    ms3.push(3);
    cout << "peekMax: " << ms3.peekMax() << " (expected: 7)" << '\n';
    cout << "popMax: " << ms3.popMax() << " (expected: 7, topmost)" << '\n';
    cout << "top: " << ms3.top() << " (expected: 3)" << '\n';
    cout << "popMax: " << ms3.popMax() << " (expected: 7, second occurrence)" << '\n';
    cout << "top: " << ms3.top() << " (expected: 3)" << '\n';
    cout << "peekMax: " << ms3.peekMax() << " (expected: 3)" << '\n';
    cout << '\n';

    // Test 4: Negative numbers
    cout << "=== Test 4: Negative numbers ===" << '\n';
    MaxStack ms4;
    ms4.push(-5);
    ms4.push(-1);
    ms4.push(-10);
    cout << "peekMax: " << ms4.peekMax() << " (expected: -1)" << '\n';
    cout << "popMax: " << ms4.popMax() << " (expected: -1)" << '\n';
    cout << "top: " << ms4.top() << " (expected: -10)" << '\n';
    cout << "peekMax: " << ms4.peekMax() << " (expected: -5)" << '\n';
    cout << '\n';

    // Test 5: Mixed operations sequence
    cout << "=== Test 5: Mixed operations ===" << '\n';
    MaxStack ms5;
    ms5.push(10);
    ms5.push(20);
    cout << "peekMax: " << ms5.peekMax() << " (expected: 20)" << '\n';
    ms5.push(15);
    cout << "top: " << ms5.top() << " (expected: 15)" << '\n';
    cout << "popMax: " << ms5.popMax() << " (expected: 20)" << '\n';
    cout << "top: " << ms5.top() << " (expected: 15)" << '\n';
    cout << "pop: " << ms5.pop() << " (expected: 15)" << '\n';
    cout << "top: " << ms5.top() << " (expected: 10)" << '\n';
    cout << "peekMax: " << ms5.peekMax() << " (expected: 10)" << '\n';
    cout << '\n';

    // Test 6: Single element
    cout << "=== Test 6: Single element ===" << '\n';
    MaxStack ms6;
    ms6.push(42);
    cout << "top: " << ms6.top() << " (expected: 42)" << '\n';
    cout << "peekMax: " << ms6.peekMax() << " (expected: 42)" << '\n';
    cout << "popMax: " << ms6.popMax() << " (expected: 42)" << '\n';
    cout << '\n';

    cout << "All tests completed!" << '\n';
    return 0;
}

