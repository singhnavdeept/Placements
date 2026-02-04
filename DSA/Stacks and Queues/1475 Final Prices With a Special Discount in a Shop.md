



### 1. 🧠 **Thought Process of a Competitive Programmer**

1.  **First Read & Deconstruction:**
    *   **Input:** An array `prices` where `prices[i]` is the price of the `i`-th item.
    *   **Rule:** For each item `i`, there is a "special discount". The discount is equal to the price of the *first* item `j` such that `j > i` and `prices[j] <= prices[i]`.
    *   **Goal:** Calculate the final price for each item after applying the discount. If no such `j` exists for an item `i`, there is no discount for that item. Return the array of final prices.
    *   **Example:** `prices = [8, 4, 6, 2, 3]`
        *   Item 0 (price 8): Next smaller/equal is 4 (at index 1). Final price = 8 - 4 = 4.
        *   Item 1 (price 4): Next smaller/equal is 2 (at index 3). Final price = 4 - 2 = 2.
        *   Item 2 (price 6): Next smaller/equal is 2 (at index 3). Final price = 6 - 2 = 4.
        *   Item 3 (price 2): No item to the right is smaller or equal. No discount. Final price = 2.
        *   Item 4 (price 3): No item to the right. No discount. Final price = 3.
    *   **Output:** `[4, 2, 4, 2, 3]`
    *   **Keywords:** "first item `j > i`," "next smaller or equal element."

2.  **Initial Brainstorming & The Brute-Force Approach:**
    *   The problem statement directly describes the algorithm.
    *   **Algorithm:**
        1.  Create a copy of the `prices` array to store the results.
        2.  Iterate through the array with an outer loop for `i` from `0` to `n-1`.
        3.  For each `i`, start an inner loop for `j` from `i+1` to `n-1`.
        4.  Inside the inner loop, check if `prices[j] <= prices[i]`.
        5.  If this condition is met, we've found our discount. Update `result[i] = prices[i] - prices[j]` and `break` the inner loop (since we only care about the *first* one).
    *   **Complexity:** Two nested loops. **O(N²)**.
    *   **Constraints Check:** `prices.length` up to 500. `500 * 500 = 250,000`, which is very small. An `O(N^2)` solution is perfectly fine and will pass easily.
    *   **Verdict:** This is a valid, acceptable solution. In a contest, if the constraints were this small, you would code this immediately to get the points and move on. However, in an interview, the follow-up would be, "What if `N` was up to 10^5? How would you optimize?"

3.  **The Optimization Insight: Pre-computation & The "Next X" Pattern:**
    *   The O(N²) approach is slow because we are repeatedly scanning to the right for each `i`.
    *   The core of the problem is finding the **"Next Smaller or Equal Element"** for each item.
    *   This is a classic problem variant that screams **Monotonic Stack**. It's the sibling of "Next Greater Element".
    *   We can pre-compute the "next smaller or equal element" for every index in a single O(N) pass.

4.  **Formulating the Monotonic Stack Strategy:**
    *   We want to find the next *smaller* element. This means we should maintain an **increasing monotonic stack**. Why? When we encounter a new number, any numbers on the stack that are *larger* than the new number have just found *their* next smaller element.
    *   The stack will store **indices**, not values. Storing indices is crucial because we need to know where to update the final price in our result array.
    *   **Algorithm:**
        1.  Initialize a `result` vector with the original `prices`.
        2.  Initialize an empty `stack`. The stack will store indices `i` where `prices[i]` is waiting to find its next smaller/equal element. It will be maintained in increasing order of `prices` values.
        3.  Iterate through the `prices` array with an index `i` from `0` to `n-1`.
        4.  **The Core Logic:** `while` the stack is not empty AND the current price `prices[i]` is less than or equal to the price at the index on top of the stack (`prices[stack.top()]`):
            a. We've found the answer! The current `prices[i]` is the next smaller/equal element for the item at `stack.top()`.
            b. Let `top_index = stack.top()`.
            c. Update the result for that index: `result[top_index] -= prices[i]`.
            d. Pop from the stack. The item at `top_index` is now resolved.
        5.  After the `while` loop, push the current index `i` onto the stack. It is now waiting for *its* next smaller/equal element.
        6.  After iterating through the entire array, any indices remaining in the stack have no next smaller/equal element. Their prices in the `result` array are already correct (since they were never discounted), so we don't need to do anything.
    *   **Complexity:** Each index is pushed onto the stack exactly once and popped at most once. This is a single pass.
        *   Time complexity: **O(N)**.
        *   Space complexity: **O(N)** in the worst case for the stack (e.g., if the `prices` array is strictly increasing).

### 2. ⚡ **C++ Implementations**

#### Method 1: Brute Force `O(N^2)` (Acceptable for given constraints)

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution_BruteForce {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices; // Start with original prices

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Find the first j > i where prices[j] <= prices[i]
                if (prices[j] <= prices[i]) {
                    // Apply the discount and break the inner loop
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return result;
    }
};
```

#### Method 2: Monotonic Stack `O(N)` (The Optimal Solution)

This is the code a top-tier programmer would write to demonstrate advanced pattern recognition.

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_Optimal {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result = prices; // Initialize result with original prices.
        
        // The stack will store INDICES. It will be maintained such that
        // prices[s.top()] is an increasing sequence from bottom to top.
        stack<int> s;

        // Iterate through the array. 'i' is the current index.
        for (int i = 0; i < n; ++i) {
            
            // While the stack is not empty and the current price is less than or equal to
            // the price of the item at the index on top of the stack...
            while (!s.empty() && prices[i] <= prices[s.top()]) {
                // ... we have found the discount for the item at s.top().
                int prev_index = s.top();
                
                // Apply the discount to the result for that previous item.
                result[prev_index] -= prices[i];
                
                // The item at prev_index has been processed, so pop it.
                s.pop();
            }
            
            // Push the current index onto the stack. It is now waiting for its
            // "next smaller or equal element".
            s.push(i);

            // The competitive programming trick: iterate backwards
            // If you iterate backwards, you are looking for the *previous* smaller element
            // for the right item. For a *next* smaller element problem,
            // the standard is a forward pass as shown above.
        }
        
        // Any indices left in the stack have no discount, and their prices in `result`
        // are already correct (the original price). So we're done.
        
        return result;
    }
};
```

### 3. ⏱️ **Time and Space Complexity Analysis**

*   **Brute Force Approach:**
    *   **Time:** O(N²)
    *   **Space:** O(1) (excluding the `result` vector)

*   **Optimal (Monotonic Stack) Approach:**
    *   **Time: O(N)**
        *   We perform a single pass through the `prices` array.
        *   Each index is pushed onto the stack exactly once.
        *   Each index is popped from the stack at most once.
        *   The total number of operations is linear with respect to `N`.
    *   **Space: O(N)**
        *   In the worst-case scenario (e.g., a strictly increasing `prices` array like `[1, 2, 3, 4, 5]`), all `N` indices will be pushed onto the stack before any are popped. The maximum size of the stack can be `N`.

### 4. 💥 **Common Mistakes and Gotchas**

1.  **Choosing Brute Force with Larger Constraints:** The biggest conceptual mistake would be failing to recognize the monotonic stack pattern if the constraints were larger (e.g., `N = 10^5`).
2.  **Stacking Values vs. Indices:** Stacking the `prices` values directly is a common error. If you do this, you lose the information about *which item* to apply the discount to. You **must** stack the indices.
3.  **Incorrect Stack Monotonicity:** Using a decreasing stack for a "next smaller" problem (or an increasing stack for "next greater"). This would find the wrong elements. Rule of thumb:
    *   Next/Prev **Greater**: Use a *decreasing* stack.
    *   Next/Prev **Smaller**: Use an *increasing* stack.
4.  **Handling the `or equal` part:** The problem says `prices[j] <= prices[i]`. The `while` loop condition `prices[i] <= prices[s.top()]` correctly handles this equality. Forgetting the `=` would be a bug.

### 5. 📘 **DSA Takeaway**

*   **Primary Pattern:** **Monotonic Stack**. This is the core takeaway. It is the go-to, optimal solution for all "Next Greater/Smaller Element" (NGE/NSE) variations.
*   **Core Concept:** The monotonic stack efficiently keeps track of "unresolved" elements that are waiting for their NGE/NSE. When a new element arrives, it resolves all the elements on the stack that it can, and then it is added to the stack to await its own resolution. This ensures a single, O(N) pass.
*   **Problem Transformation:** The first step is to recognize that the "special discount" is just a story wrapped around the standard "Next Smaller or Equal Element" problem. Abstracting the problem to its algorithmic core is a key skill.

*   **In what other problems does this pattern show up?**
    *   **LeetCode 496: Next Greater Element I**
    *   **LeetCode 503: Next Greater Element II**
    *   **LeetCode 739: Daily Temperatures**
    *   **LeetCode 84: Largest Rectangle in Histogram** (a harder application of the same core idea)