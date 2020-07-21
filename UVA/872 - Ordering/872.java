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