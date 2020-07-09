# UVA 196 - Spreadsheet Editorial

In case you didn't read the problem, check it [here](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=132).  
In this problem, you are required to implement a simple spreadsheet application. You will be provided with a 2d Array containing either a number or a **sum** equation. Note that the equation may contain a reference to another equation, so you have to calculate it first. It's guaranteed that there's no circular dependencies meaning that you will not find a cell **X** that depends on cell **Y**, and on the same time **Y** depends on **X**.  
Firstly, let's see how we can convert the given cell notation to row and column. If you are given **"AFC221"**, then for sure, row = 221. To get the column, we can treat **"AFC"** as a number system with base 26. To convert it to decimal "base 10", we take the right-most bit and multiply by 26<sup>0</sup>, the one to its left by 26<sup>1</sup>, and so on. Since we know, that A is equivalent to 1, B is equivalent to 2, and , in general, *char* is equivalent to 
``` char - 'A' + 1 ```.  
Then, for "AFC", col = ('C'-'A'+1)\*26<sup>0</sup> + ('F'-'A'+1)\*26<sup>1</sup> + ('A'-'A'+1)*26<sup>2</sup> .  

### Solution:
  Take the input as a string 2d array. Then, iterate over it and whenever we find an *expression*, we calculate its value recursively. Note that it has to be recursive because the cells involved in an expression may be an expression themselves. So, you extract the cells' indices from the expression, convert them as mentioned above, calculate their effective value using a recursive call, and add them all up. After you calculate its effective value, store it in your array, in case it was needed in another calculation. This will save you some time.  
  Pay attention to the format of the output as there is no space after the last element of each row.
  **Time complexity:**  ***O(Rows \* Columns)***.  
Another editorial for iterative solution can be found [here](https://algorithmist.com/wiki/UVa_196_-_Spreadsheet).  
You can find my ***C++*** solution in the same folder. Moreover, Here's a [link](https://github.com/kalex1994/UVA/blob/master/196.cpp) to a similar soltuion.  

  
