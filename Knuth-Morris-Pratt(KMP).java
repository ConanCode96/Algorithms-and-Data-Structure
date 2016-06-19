public class Knuth_Morris_Pratt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String str = "abcxabcdabcdabcy";
		String pat = "abcdabcy";
		int matches;

		SubStringSearch ss = new SubStringSearch();

		matches = ss.KMP(str.toCharArray(), pat.toCharArray());

		System.out.println(matches); // Total complexity O(m+n)
		
		matches = ss.hasSubstring(str.toCharArray(), pat.toCharArray());
		
		System.out.println(matches); // Total complexity O(m*n)
		
		return;
	}
}

class SubStringSearch {

	// O(m+n) fast!
	protected int KMP(char[] text, char[] pattern) {

		int[] transition = process(pattern);

		int n = text.length;
		int m = pattern.length;

		int matches = 0;

		int i = 0, j = 0;

		while (j < m && i < n) { // O(n)

			if (pattern[j] == text[i]) { // There's a sub-match
				i++;
				j++;
			}

			else { // characters differ

				if (j != 0)
					j = transition[j - 1];

				else
					i++;
			}

			if (j == m) {
				matches++; // total match!
				j = 0;    // to avoid intersecting matches!
						 // j = trans[j-1]; would make intersecting matches
						// count (i.e. (abcabcab) for the pattern (abcab) == 2).
			}
		}

		return matches;
	}

	private int[] process(char[] pattern) {

		int length = pattern.length;

		int[] transition = new int[length];

		transition[0] = 0; // no possible (pre-suf)-fix from one character

		for (int i = 0, j = 1; j < length;) { // O(length)

			if (pattern[i] == pattern[j]) {
				transition[j] = i + 1;
				i++;
				j++;
			}

			else {

				while (i != 0 && pattern[i] != pattern[j])
					i = transition[i-1];

				if (pattern[i] == pattern[j])
					continue; // continue and keep the loop-routine

				else if (i == 0) { // no possible (pre==suf)-fix
					transition[j] = 0;
					j++;
				}
			}
		}

		/*
		 * for(int i = 0; i<transition.length; ++i)
		 * System.out.print(transition[i] + " ");
		 * 
		 * System.out.println();
		 */

		return transition;

	}
	
	//O(m*n) bad!
	protected int hasSubstring(char[] text, char[] pattern){
		int matches = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < text.length && j < pattern.length){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        
            if(j == pattern.length){
            	matches++; j = 0;
            }
        }
        
        return matches;
	}
	

}
