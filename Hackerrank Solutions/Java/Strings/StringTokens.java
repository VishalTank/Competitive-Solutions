public class StringTokens {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        s = s.trim();
        if(s.length()==0)
            System.out.println(s.length());

        else
        if(s.length()<400000){
            String[] arr=s.split("[_\\@ !,?.']+");

            System.out.println(arr.length);

            for(int i=0;i<arr.length;i++)
                System.out.println(arr[i]);
        }
    }
}
