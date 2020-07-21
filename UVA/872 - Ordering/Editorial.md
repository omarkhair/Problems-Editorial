# UVA 872 - Ordering Editorial

You can read the problem [here](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=813).  
For hints, check this Quora [question](https://www.quora.com/What-are-some-hints-to-solve-the-UVa-872-ordering-problem).  
Since there are at most 20 variables and no more than 50 relations, we can work on the idea of generating all possible arrangements of the sequence. There are 20! (10<sup>18</sup>) in total. Generating and checking all of them will not fit in the time limit.  
Let's see how we can improve it.  
### Solution:
  I will use back tracking to generate all possible valid arrangements with the constraints check made as early as possible. The recursive states of are the size *i* of the sequence and the sequence itself. At every call, I will loop over the variables array, check that the variable in hand is not already there and there are no bigger variables in the sequence. If that's true, add it to the sequence, make a recursive call with i+1, and then backtrack(remove it!).  
  To make the checking efficient, create 2d array[26][26] (or an array of HashSets) that will tell you for each (i, j), if variable j is greater than variable i in *O(1)*.   
  The base case is when i is equal to *N*(the number of variables). We reached a solution that passes the requirements. Add it to your answers array.  After the recursive calls end, sort your answers in ascending order and print them.  
  Make sure to make a blank line between every two test cases and a space between every two variables in a sequence. 
    
 #### My Java solution:  
<details>
<summary>Show code</summary>  
  
  
```
import java.io.*;
import java.util.*;

class Main {
	static ArrayList<Character> arr;
	static HashSet<Character>[] biggerThan;
	static int n;
	static ArrayList<String> ans;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int tt = sc.nextInt();
		boolean first= true;
		while (tt-- > 0) {
			sc.nextLine();
			StringTokenizer st = new StringTokenizer(sc.nextLine());
			arr = new ArrayList<Character>();
			while (st.hasMoreTokens())
				arr.add(st.nextToken().charAt(0));
			n = arr.size();
			biggerThan = new HashSet[26];
			for (int i = 0; i < 26; i++)
				biggerThan[i] = new HashSet<Character>();
			st = new StringTokenizer(sc.nextLine());
			while (st.hasMoreTokens()) {
				String s = st.nextToken();
				biggerThan[s.charAt(0) - 'A'].add(s.charAt(2));
			}
			ans = new ArrayList<String>();
			calc(0, new ArrayList<Character>());
			if(first)
				first  = false;
			else
				out.println();
			if(ans.size() == 0)
				out.println("NO");
			else {
				Collections.sort(ans);
				for(String s: ans)
					out.println(s);
			}
		}
		out.close();
	}

	public static void calc(int i, ArrayList<Character> seq) {
		if(i == n) {
			// add the seq to your answers
			StringBuilder sb = new StringBuilder();
			boolean first = true;
			for(char c: seq) {
				if(first)
					first  = false;
				else
					sb.append(" ");
				sb.append(c);
			}
			ans.add(sb.toString());
			return;
		}
		loop: for (char c : arr) {
			for (char c2 : seq) {
				if (biggerThan[c - 'A'].contains(c2))	// this sequence contradicts the relations, backtrack
					return;
				if (c == c2)
					continue loop;
			}
			// This Character c can be added to the sequence
			seq.add(c);
			calc(i+1, seq);
			seq.remove(i);
		}
	}

	static class Scanner {
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}
  
```
</details>
