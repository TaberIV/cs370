import java.util.Arrays;

public class SubstringDivisibility {
  public static void main(String[] args) {
    // Handle nput
    String input = args[0];

    char[] nums = input.toCharArray();
    Arrays.sort(nums);

    long start = System.currentTimeMillis();

    // Do Stuff

    // Output
    long finish = System.currentTimeMillis();
    long elapsed = finish - start;

    int sum = 0;
    System.out.println("Sum: " + sum);
    System.out.println("Elapsed time: " + elapsed + "ms");
  }
}