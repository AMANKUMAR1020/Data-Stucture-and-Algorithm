class Solution {
    public char nonRepeatingChar(String s) {
        // code here
        int[] a = new int[26];
        
        for(int i =0; i<s.length(); i++){
            Character c = s.charAt(i);
            a[c - 'a']++;
        }
        
        for(int i =0; i<s.length(); i++){
             Character c = s.charAt(i);
            
            if(a[c - 'a'] == 1){
                return c;
            } 
        }
        return '$';
    }
}
