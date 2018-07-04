public class JavaOutputFormatting {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("================================");
        for(int i=0;i<3;i++){
            String s1=sc.next();
            int x=sc.nextInt();
            int l=s1.length();
            //Complete this line
            if(l<=10 && (x>=00 && x<=999))
                System.out.print(s1);
            for(int j=0;j<(15-l);j++)
            {
                System.out.print(" ");
            }
            System.out.printf("%03d\n",x);
        }
        System.out.println("================================");

    }
}
