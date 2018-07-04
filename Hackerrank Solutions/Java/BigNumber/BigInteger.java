public class BigInteger {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger i = new BigInteger(sc.next());
        BigInteger j = new BigInteger(sc.next());

        System.out.println(i.add(j));
        System.out.println(i.multiply(j));
    }
}
