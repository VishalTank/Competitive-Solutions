package DataStructures;

public class Arraylist {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int d,q,x,y;

        ArrayList[] al = new ArrayList[n];

        for(int i=0;i<n;i++)
        {
            d = sc.nextInt();
            al[i] = new ArrayList();

            for(int j=0;j<d;j++)
            {
                int temp = sc.nextInt();
                al[i].add(temp);
            }
        }

        q=sc.nextInt();

        for(int i=0;i<q;i++)
        {
            x=sc.nextInt();
            y=sc.nextInt();
            try{
                System.out.println(al[x-1].get(y-1));
            } catch(Exception e){
                System.out.println("ERROR!");
            }
        }
    }
}
