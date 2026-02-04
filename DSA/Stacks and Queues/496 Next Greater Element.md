

### 1. 🧠 **Thought Process of a Competitive Programmer**

1.  **First Read & Deconstruction:**
    *   **Input:** Two **distinct** integer arrays, `nums1` and `nums2`. `nums1` is a **subset** of `nums2`.
    *   **Goal:** For each element `x` in `nums1`, find its corresponding value in `nums2` and then find the **next greater element** for that value in `nums2`. The "next greater element" is the first element to the right that is strictly greater. If no such element exists, the answer is -1.
    *   **Output:** An array `ans` of the same length as `nums1`, where `ans[i]` is the next greater element for `nums1[i]`.

2.  **Initial Brainstorming & The Brute-Force Approach:**
    *   This problem is a direct lookup. The logic is straightforward.
    *   **Algorithm:**
        1.  Iterate through each element `n1` in `nums1`.
        2.  Find the index `j` in `nums2` where `nums2[j] == n1`. A linear scan will do.
        3.  Starting from `j+1`, perform another linear scan through the rest of `nums2` to find the first element `nums2[k]` such that `nums2[k] > n1`.
        4.  If found, store `nums2[k]` in the result.
        5.  If the second scan finishes without finding a greater element, store -1.
    *   **Complexity:** Let `M` be the length of `nums1` and `N` be the length of `nums2`.
        *   Outer loop runs `M` times.
        *   Inner loops (finding `j` and then finding the next greater element) run up to `N` times.
        *   Total time complexity: **O(M * N)**.
    *   **Constraints Check:** `M, N <= 1000`. So, `M*N <= 1,000,000`. An `O(M*N)` solution is efficient enough to pass. It's a valid solution.
    *   **Verdict:** Good, it works and passes. But can we do better? This is a key question an interviewer or a top competitive programmer asks. `O(M*N)` feels inefficient. We are repeatedly scanning `nums2`.

3.  **The Optimization Insight: Pre-computation:**
    *   The brute-force approach is slow because for each element of `nums1`, we rescan `nums2`.
    *   What if we could find the "next greater element" for *every* element in `nums2` in one single, efficient pass?
    *   If we had a map, say `next_greater_map`, where `next_greater_map[x] = y` (y is the next greater element of x), then the problem would be trivial:
        1.  Pre-compute this map for all elements in `nums2`. (The hard part)
        2.  Iterate through `nums1` and simply look up the answer: `result[i] = next_greater_map[nums1[i]]`. (The easy part)
    *   Now the entire problem boils down to this subproblem: **For an array `nums2`, efficiently find the next greater element for every number.**

4.  **Recognizing the "Next Greater Element" Pattern -> Monotonic Stack:**
    *   This subproblem is the classic use case for a **Monotonic Stack**.
    *   **What is a Monotonic Stack?** It's a stack where the elements are always in a specific order (either strictly increasing or strictly decreasing).
    *   **How does it help?** Let's use a **decreasing monotonic stack**.
        *   We will iterate through `nums2` from left to right.
        *   The stack will store numbers from `nums2` that are still "waiting" for their next greater element. Because the stack is decreasing, the top of the stack is the smallest element we've seen recently.
    *   **The Monotonic Stack Algorithm (for the subproblem):**
        1.  Initialize an empty `stack` and an empty `map` (`next_greater_map`).
        2.  Iterate through each number `num` in `nums2`.
        3.  `while` the stack is not empty AND `num` is greater than the element at the `stack.top()`:
            a. This means `num` is the "next greater element" for `stack.top()`.
            b. We've found the answer for `stack.top()`. So, `next_greater_map[stack.top()] = num`.
            c. Pop the element from the stack; it's no longer waiting.
        4.  After the `while` loop, push the current `num` onto the stack. It's now waiting for *its* next greater element.
        5.  After iterating through all of `nums2`, any elements still left in the stack do not have a next greater element. We can map them to -1.
    *   **Complexity:** Each element of `nums2` is pushed onto the stack exactly once and popped from the stack at most once. This is a single pass.
        *   Time complexity of pre-computation: **O(N)**.
        *   Space complexity of pre-computation: **O(N)** for the stack and map.
    *   **Final Solution Complexity:** `O(N)` (pre-computation) + `O(M)` (lookup) = **O(N + M)**. This is a significant improvement over `O(N*M)`.

### 2. ⚡ **Optimal C++ Implementation (Monotonic Stack)**

This code implements the efficient pre-computation strategy using a monotonic stack.

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // --- 1. Pre-computation using Monotonic Stack ---

        // The map will store: {element -> its_next_greater_element}
        unordered_map<int, int> next_greater_map;
        
        // The stack will maintain a decreasing monotonic sequence.
        // It stores elements from nums2 that are awaiting their next greater element.
        stack<int> s;

        // Iterate through nums2 to populate the map.
        for (int num : nums2) {
            // While the stack is not empty and the current number `num` is greater
            // than the element at the top of the stack...
            while (!s.empty() && num > s.top()) {
                // ... `num` is the next greater element for the element at the top.
                // We've found the answer for s.top().
                next_greater_map[s.top()] = num;
                // Pop it, as its query has been answered.
                s.pop();
            }
            // Push the current number onto the stack. It's now waiting for its
            // next greater element.
            s.push(num);
        }
        
        // Any elements remaining in the stack have no next greater element in the array.
        while (!s.empty()) {
            next_greater_map[s.top()] = -1;
            s.pop();
        }

        // --- 2. Build the Result ---
        
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            // Perform a simple O(1) average-time lookup in our pre-computed map.
            result[i] = next_greater_map[nums1[i]];
        }
        
        return result;
    }
};
```

### 3. ⏱️ **Time and Space Complexity Analysis**

*   **Brute Force Approach:**
    *   **Time:** O(M * N)
    *   **Space:** O(1) (excluding the result vector)

*   **Optimal (Monotonic Stack) Approach:**
    *   **Time: O(N + M)**
        *   The monotonic stack pass through `nums2` takes `O(N)` time because each element is pushed and popped at most once.
        *   Building the result by iterating through `nums1` and looking up in the map takes `O(M)` time.
        *   The total time is linear with respect to the sum of the input sizes.
    *   **Space: O(N)**
        *   The `unordered_map` can, in the worst case, store all `N` elements from `nums2` (if `nums2` is sorted descending).
        *   The `stack` can also store up to `N` elements in the same worst-case scenario.
        *   The space is proportional to the size of `nums2`.

### 4. 💥 **Common Mistakes and Gotchas**

1.  **Stopping at Brute Force:** In an interview, providing only the O(M*N) solution is a missed opportunity. The interviewer is almost certainly looking for the optimized O(N+M) approach.
2.  **Incorrect Monotonic Stack Logic:** The `while` loop condition (`num > s.top()`) and the order of operations (map, pop, then push) are crucial. Reversing them breaks the logic.
3.  **Handling Leftovers in the Stack:** Forgetting the final `while` loop to assign -1 to all elements left in the stack will result in incorrect answers (often 0, depending on the map's default value) for those elements.
4.  **Using a Stack of Indices:** You can store indices in the stack instead of values. This is often necessary in problems where you need the *distance* to the next greater element, not just the value. For this problem, storing values is simpler and sufficient.

### 5. 📘 **DSA Takeaway**

*   **Primary Pattern:** **Monotonic Stack**. This is the quintessential problem for this pattern. A monotonic stack is the ideal tool when a problem involves finding the "next greater/smaller element" or "previous greater/smaller element" for all items in an array.
*   **Core Concept:** **Pre-computation for Efficient Lookups**. The strategy separates the problem into two distinct phases: a linear-time pre-computation phase that answers the core query for *all possible inputs*, and a fast lookup phase that uses the pre-computed results. This is a very common and powerful problem-solving paradigm.

*   **In what other problems does this pattern show up?**
    *   **LeetCode 503: Next Greater Element II:** Same problem, but the array is circular.
    *   **LeetCode 739: Daily Temperatures:** Find the number of days until a warmer day (find the *distance* to the next greater element). Requires a stack of indices.
    *   **LeetCode 84: Largest Rectangle in Histogram:** A harder problem where a monotonic stack is used to find the "previous smaller element" and "next smaller element" for each bar to determine the width of the largest possible rectangle.