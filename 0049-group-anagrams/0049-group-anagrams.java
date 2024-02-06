

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hashMap = new HashMap<>();
        List<List<String>> ans = new ArrayList<>();

        for (String str : strs) {
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);

            if (!hashMap.containsKey(sortedStr)) {
                hashMap.put(sortedStr, new ArrayList<>());
            }
            hashMap.get(sortedStr).add(str);
        }

        for (Map.Entry<String, List<String>> entry : hashMap.entrySet()) {
            ans.add(entry.getValue());
        }

        return ans;
    }
}
