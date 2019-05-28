import bisect
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        #use sliding window with bisect
        #start with window starting at index 0
        #sort and store p to use for comparisons
        #every iteration, remove the last character and insert the newest one (while maintaining the sortedness), perform a comparison. If the new string matches p, add the index to the result list
        #Time complexity: O( s * p)
        # you must iterate through every index in s to check if the series of characters starting at each index i is an anagram, so it's at least order s
        # for every iteration, you must remove the previously used character from the last window and insert the new character from this window. Insertion and deletion from arbitrary locations in an array is O(n). Since you're performing these operations on a string length len(p), the overall complexity is O(s * p)
		
		compare = list(sorted(p));
        window = list(sorted(s[0:len(p)]));
        result = [];
        for i in range(len(s) - len(p) + 1):
            if i > 0:
                window.remove(s[i - 1]);
                bisect.insort_left( window, s[i + len(p) - 1] );
            if window == compare:
                result.append(i)
        return result;