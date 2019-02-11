
/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke Loposky
 * We pledge our honor that we have abided by the Stevens Honor System
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class SubstringDivisibility {
  private static int[] primes = { 2, 3, 5, 7, 11, 13, 17 };

  public static void main(String[] args) {
    // Handle input
    int[] nums = parseInput(args[0]);

    long start = System.nanoTime();

    Arrays.sort(nums);

    // Build Valid numbers
    List<int[]> validNums = getValidNums(nums);

    // Output
    long sum = 0;
    for (int[] num : validNums) {
      for (int digit : num) {
        System.out.print(digit);
      }

      sum += concatInt(num);
      System.out.println();
    }

    System.out.print("Sum: ");
    System.out.println(sum);
    System.out.printf("Elapsed time: %.6f ms\n", (System.nanoTime() - start) / 1e6);
  }

  private static int concatInt(int... nums) {
    if (nums.length > 1) {
      return nums[0] * ((int) Math.pow(10, nums.length - 1)) + concatInt(Arrays.copyOfRange(nums, 1, nums.length));
    } else {
      return nums[0];
    }
  }

  private static int[] parseInput(String input) {
    char[] chars = input.toCharArray();
    int[] nums = new int[chars.length];

    for (int i = nums.length - 1; i >= 0; i--) {
      nums[i] = chars[i] - '0';
    }

    return nums;
  }

  private static List<int[]> getValidNums(int[] nums) {
    return completeNum(new int[nums.length], nums, 0);
  }

  private static List<int[]> completeNum(int[] digits, int[] nums, int index) {
    List<int[]> possibleNums = new ArrayList<int[]>();

    if (index < nums.length) {
      for (int i = 0; i < nums.length; i++) {
        if (nums[i] >= 0 && validNext(digits, nums[i], index)) {
          int[] newDigits = digits.clone();
          newDigits[index] = nums[i];

          int[] newNums = nums.clone();
          newNums[i] = -1;

          possibleNums.addAll(completeNum(newDigits, newNums, index + 1));
        }
      }
    } else {
      possibleNums.add(digits);
    }

    return possibleNums;
  }

  private static boolean validNext(int[] digits, int next, int index) {
    // Check for prime conditions
    boolean primeMult = index < 3;
    if (!primeMult) {
      int concat = concatInt(digits[index - 2], digits[index - 1], next);
      primeMult = (concat % primes[index - 3]) == 0;
    }

    return primeMult;
  }
}
