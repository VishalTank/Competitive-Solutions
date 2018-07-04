public class StringsIntroduction {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s1 = sc.nextLine();
        String s2 = sc.nextLine();

        System.out.println(s1.length() + s2.length());

        if(s1.compareTo(s2) > 0)
            System.out.println("Yes");
        else
            System.out.println("No");

        System.out.println(s1.toUpperCase().charAt(0) + s1.substring(1) + " " + s2.substring(0,1).toUpperCase() + s2.substring(1));
    }
}
