public class EndOfFile {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int i=1;
        while(in.hasNext())
        {
            System.out.println(i+" "+in.nextLine());
            i++;
        }

        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}
