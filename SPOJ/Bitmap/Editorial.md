# Editorial

If you didn't read the problem, check it [here](https://www.spoj.com/problems/BITMAP/).  
In this problem, we will be given an n*m 2d array with only  *0's (black)* and *1's (white)*. We are required to find the minimum distance to reach any cell if you start from a cell containing 1.  
Let's consider this 2d-array as a graph where every cell is a *vertex*, and there's an *edge* between every two adjacent cells.  
I will be discussing two solutions based on BFS:
### 1- The Naive solution:
  In this solution, we will find the distances of all the cells from each and every white cell and then take the **minimum** distance among all of them. One can find the distance from a certain white cell using **Breadth First Search (BFS)** while keeping an 2d-array of distances. The starting white cell will have a **zero** distance, its adjacent cells will have distance 1, the adjacents of the adjacents with distance 2, and so on.  
  **Time complexity:** Each BFS will traverse the whole array with O(n\*m) multiplied by the number of white cells. **Worst case** when all the cells (n\*m) are white, the total complexity will be ***O(n<sup>2</sup> \* m<sup>2</sup>)***. Surprisingly, this passes the test cases.
  
### 2- The Fast solution:
  This one is actually similar to the above. However, we will be only running **one** BFS over our array. The trick here is to make it *multi-source* BFS instead of being a *single-source*. In other words, instead of pushing one white cell to the queue, we will be pushing all the white cells at once, and the BFS will proceed as *normal*. This way, you guarantee that each black cell will be firstly reached by the **closest** white cell.  
  **Time complexity:** Only one BFS will traverse the whole array with complexity ***O(n\*m)***. This will surely fit in time. 
  
You can find both ***C++*** solutions in the same folder
  
  
  
  
  
