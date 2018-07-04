package OOP;

public class Interface {
    //copy from here
    class MyCalculator implements AdvancedArithmetic {
        int sum = 0;
        public int divisor_sum(int n)
        {
            for(int i = 1; i <= n; i++)
            {
                if (n % i == 0) {
                    sum += i;
                }
            }
            return sum;
        }

    }
    //to here
}
