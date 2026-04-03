# 🧠 LeetCode Problem Analysis

## 📌 Problem Info

- **Name**: Kth Largest Element in a Stream
    
- **Link**: [https://leetcode.com/problems/kth-largest-element-in-a-stream/](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
    
- **Difficulty**: Easy
    
- **Tags**: Heap, Design, Streaming Data
    
- **Date Solved**:
    

---

## 📥 What is Given?

- A class `KthLargest`
    
- Input:
    
    - Integer `k`
        
    - Initial array `nums`
        
- Then multiple calls to:
    
    ```cpp
    int add(int val);
    ```
    

### Constraints:

- `1 <= k <= 10^4`
    
- Stream can grow large
    

### Edge Cases:

- Initial array size < k
    
- Negative numbers
    
- Duplicate values
    

### Hidden Observations:

- We **don’t need full sorting every time**
    
- We only care about the **k-th largest**, not all elements
    
- Stream = dynamic input → recomputation must be efficient
    

---

## 🎯 What is Required?

- After each `add(val)`:
    
    - Return the **k-th largest element so far**
        

---

## 🔍 Pattern Recognition

- Type:
    
    - ☑ Heap / Priority Queue
        
    - ☑ Streaming / Online algorithm
        
    - ☐ DP
        
    - ☐ Graph
        

### Similar Problems:

- Kth Largest Element in Array
    
- Top K Frequent Elements
    

---

## 🧩 Initial Thoughts (Brute Force First)

### Idea:

- Insert into array
    
- Sort every time
    

### Complexity:

- ❌ O(n log n) per operation → too slow
    

---

## ⚡ Optimized Approach

### ✅ Key Insight:

👉 Maintain only **k largest elements**, not all.

---

### 💡 Core Idea:

Use a **min heap of size k**

- Heap stores **k largest elements seen so far**
    
- The top of heap = **k-th largest**
    

---

### Why Min Heap?

- Smallest element in heap = answer
    
- If new element is bigger → it deserves a spot
    
- If smaller → ignore
    

---

### Steps:

1. Initialize a **min heap**
    
2. Add elements from `nums`:
    
    - Push into heap
        
    - If size > k → pop smallest
        
3. For each `add(val)`:
    
    - Push val
        
    - If size > k → pop
        
    - Return `heap.top()`
        

---

## 🧪 Dry Run

k = 3  
nums = [4, 5, 8, 2]

Heap after init → [4, 5, 8]

add(3) → heap = [4,5,8] → answer = 4  
add(5) → heap = [5,5,8] → answer = 5  
add(10) → heap = [5,8,10] → answer = 5  
add(9) → heap = [8,9,10] → answer = 8

---

## 💻 Code (C++)

```cpp
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > k) {
            pq.pop();
        }
        
        return pq.top();
    }
};
```

---

## ⛔ Mistakes / Learnings

- Using max heap → wrong intuition
    
- Keeping all elements → unnecessary
    
- Forgetting to maintain heap size = k
    

---

## 🔁 Revision Notes

- **One-line intuition**:  
    → "Keep k largest elements → smallest among them is answer"
    
- Trigger:  
    → Anytime you see _k-th largest/smallest in stream_
    

---

## 🧠 Pattern Extraction

### General Rule:

- K-th largest → **min heap (size k)**
    
- K-th smallest → **max heap (size k)**
    

---

### Variations:

- Streaming median → two heaps
    
- Top K elements → heap or bucket
    

---

## ⭐ Difficulty Reflection

- My rating: 4/10
    
- Time taken:
    
- Could solve again? (Y/N):