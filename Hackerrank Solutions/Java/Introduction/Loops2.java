public class Loops2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int q = sc.nextInt();

        for(int j=0;j<q;j++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int n = sc.nextInt();

            int sum = a;

            for(int i=0;i<n;i++)
            {
                sum +=  (Math.pow(2,i)*b);
                System.out.print(sum + " ");
            }
            System.out.println();
        }
    }
}
