



## 📌 Problem Info

- **Name**: [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
    
- **Link**:[Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)
    
- **Difficulty**:Easy 
    
- **Tags**: (Heap, DP, Graph, Sliding Window, etc.)
    
- **Date Solved**: 22 - March
    

---

## 📥 What is Given?

- Input format: Array of integers stone  , representing stone weights   
    
- Constraints: each element is about 1 to 1000 and total length is less than 31
    
- ## Edge cases:
	-
    
- Hidden observations:
    
    - (sorted? bounded? duplicates? negative values?)
        

---

## 🎯 What is Required?

- Output format: weight of the last remaining stone if there is any , else just return 0 

    
- Exact goal: To return the standing integer if there is is after smashing larger one in a given way 
    
- Optimization target:
    
    - Time Complexity:
        
    - Space Complexity:
        

---

## 🔍 Pattern Recognition

- Type of problem:
    
    -
        
    - ☐ Heap / Priority Queue
        
    
        

---

## 🧩 Initial Thoughts (Brute Force First)

- Basic idea:
    
- Time complexity:
    
- Why it fails / is inefficient:
    

---

## ⚡ Optimized Approach

- Key insight:
    
- Why this works:
    
- Data structures used:
    
- Step-by-step logic:  
    1.  
    2.  
    3.
    

---

## 🧪 Dry Run

- Example:
    
- Step-by-step execution:
    

---

## 💻 Code (C++)

```cpp
// Write cleanclass Solution {

public:

    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for(int i : stones){

            pq.push(i);

        }

        while(pq.size() > 1){

            int y = pq.top(); pq.pop();

            int x = pq.top(); pq.pop();

            if(x==y)continue;

            else{

                pq.push(y-x);

            }

        }

        if(pq.size()==1){

            return pq.top();

        }

        return 0;

    }

}; final code here
```

---

## ⛔ Mistakes / Learnings

- What went wrong: try to think in arrays first ,
    
- Edge cases missed: none 
    
- New trick learned: 
    

---

## 🔁 Revision Notes (VERY IMPORTANT)

- One-line intuition:
    
- When to use this pattern again:
    

---

## 🧠 Pattern Extraction

- General rule:
    
- Variations of this problem:
    

---

## ⭐ Difficulty Reflection

- My rating (1–10):
    
- Time taken:
    
- Could I solve again without help? (Y/N) Y 