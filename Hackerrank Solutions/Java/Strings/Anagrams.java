public class Anagrams {
    //copy from here
    static boolean isAnagram(String A, String B) {

        boolean flag = false;
        //if(A != null && B != null)
        {
            char[] a = A.toLowerCase().toCharArray();
            char[] b = B.toLowerCase().toCharArray();
            Arrays.sort(a);
            Arrays.sort(b);
            flag = Arrays.equals(a, b);
        }
        return flag;
    }
    //to here
}
