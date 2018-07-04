package DataStructures;

public class List {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);

        ArrayList a = new ArrayList();

        int n = sc.nextInt();

        for(int i=0;i<n;i++)
            a.add(i,sc.nextInt());

        int q = sc.nextInt();

        for(int i=0;i<q;i++)
        {
            String s = sc.next();
            if(s.equals("Insert"))
            {
                int x = sc.nextInt();
                int y = sc.nextInt();
                a.add(x,y);
            }
            else
            if(s.equals("Delete"))
            {
                int x = sc.nextInt();
                a.remove(x);
            }
        }

        Iterator i = a.iterator();

        while(i.hasNext())
        {
            Integer num = (Integer)i.next();
            System.out.print(num + " ");}
    }
}
