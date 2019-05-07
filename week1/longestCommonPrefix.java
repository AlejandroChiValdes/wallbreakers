class Solution
{
    public String longestCommonPrefix(String[] strs)
    {
        // Handle the edge case of an empty array first.
        if (strs.length == 0)
            return "";
        // length of the shortest string in the list
        int shortest = shortestStr(strs);
        //System.out.println(shortest);
        String result = ""
        
        // The outer loop will check the char at the current index of each string to see if they're all the same.
        for (int charIndex = 0; charIndex < shortest; charIndex++)
        {
            if (allMatch(strs, charIndex))
            {
                // current character is the same between all strings
                result += strs[0].charAt(charIndex);
            }
            else
                return result;
        }
        // index is now larger than the length of the shortest string. return.
        return result;
    }
    
    public int shortestStr(String[] strs)
    {
        int len = 2147483647;
        for (int i = 0; i < strs.length; ++i)
        {
            int newLen = strs[i].length();
            if ( newLen < len)
                len = newLen;
        }
        return len;
    }
    
    public boolean allMatch(String[] strs, int index)
    {
        for (int i = 0; i < strs.length; ++i)
        {
            if (strs[i].charAt(index) != strs[0].charAt(index))
                return false;
        }
        return true;
    }
}