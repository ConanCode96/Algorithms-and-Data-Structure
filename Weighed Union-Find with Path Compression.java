import java.util.Arrays;

public class main {

	static int[] id = new int[10];
	static int[] sz = new int[10];

	public static void main(String[] args) {

		Arrays.fill(sz, 1);
		
		//get the input
		
		//process your queries
		
		//get the output done! :)
		
	}

	private boolean find(int p, int q) {
		return root(p) == root(q);
	}

	private int root(int i) {

		while (i != id[i]) {

			// Simple path-compression (link child to grandparent).
			id[i] = id[id[i]]; // one line to keep it ALMOST flat.

			i = id[i];
		}

		return i;

	}

	private void union(int p, int q) {

		int i = root(p);
		int j = root(q);


		if(i == j) return; // connected to the same root!

		// Keeping it logarithmic O(log N) at most.
		// Linking the smaller tree to the bigger.

		if (sz[i] >= sz[j]) {
			id[j] = i;
			sz[i] += sz[j];
		} else {
			id[i] = j;
			sz[j] += sz[i];
		}
	}

}
