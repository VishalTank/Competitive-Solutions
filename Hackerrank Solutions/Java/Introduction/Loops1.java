public class Loops1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int ans;

        for(int i=1; i<=10; i++)
        {
            ans=N*i;
            System.out.printf("%d x %d = %d\n",N,i,ans);
        }
    }
}
