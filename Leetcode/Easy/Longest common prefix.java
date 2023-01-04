class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder longestCommonPrefix = new StringBuilder();
        int index = 0;

        outer:
        for (char c : strs[0].toCharArray()) {
            for (int i = 1; i < strs.length; i++) {
                if (index >= strs[i].length() || c != strs[i].charAt(index)) {
                    break outer;
                }
            }

            longestCommonPrefix.append(c);
            index++;
        }

        return longestCommonPrefix.toString();
    }
}

// TC: O(s * n)
// let s be the length of the first string in strs array
// n is the length of the strs array

// SC: O(1)
