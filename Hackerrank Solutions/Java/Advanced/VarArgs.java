package Advanced;

public class VarArgs {
    //copy from here
    class Add {
        public void add(int... intArgs) {
            int sum = 0;
            String s = "";
            for (int i : intArgs) {
                sum += i;
                System.out.print(s + i);
                s = "+";
            }
            System.out.println("=" + sum);
        }
    }
    //to here
}
