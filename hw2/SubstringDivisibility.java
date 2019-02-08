
/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke Lopouski
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

    // Build Valid numbers
    List<Integer> validNums = getValidNums(nums);

    // Output
    long sum = 0;
    // for (int num : validNums) {
    //   System.out.println(num);
    //   sum += num;
    // }

    System.out.printf("Sum: %d\n", sum);
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

    Arrays.sort(nums);

    return nums;
  }

  private static int getDigit(int num, int place) {
    if (place == 0)
      return 0;

    return (num % ((int) Math.pow(10, place))) / ((int) Math.pow(10, place - 1));
  }

  private static boolean containsDigit(int num, int digit) {
    while (num > 0) {
      if (getDigit(num, 1) == digit) {
        return true;
      }

      num /= 10;
    }

    return false;
  }

  private static List<Integer> getValidNums(int[] nums) {
    return completeNum(new int[nums.length], nums, 1);
  }

  private static List<Integer> completeNum(int[] digits, int[] nums, int index) {
    List<Integer> possibleNums = new ArrayList<Integer>();

    if (index < nums.length) {
      for (int num : nums) {
        if (validNext(digits, num, index)) {
          int[] newDigits = digits.clone();
          newDigits[index] = num;

          possibleNums.addAll(completeNum(newDigits, nums, index + 1));
        }
      }
    } else {
      addMissingDigit(digits, nums);
      possibleNums.add(concatInt(digits));
    }

    return possibleNums;
  }

  private static boolean validNext(int[] digits, int next, int index) {
    // Check for uniqueness
    for (int digit : digits) {
      if (digit == next) {
        return false;
      }
    }

    boolean primeMult = index < 3;
    if (!primeMult) {
      int concat = concatInt(digits[index - 2], digits[index - 1], next);
      primeMult = (concat % primes[index - 3]) == 0;
    }

    return primeMult;
  }

  private static void addMissingDigit(int[] digits, int[] nums) {
    for (int num : nums) {
      boolean found = false;

      for (int digit : digits) {
        if (num == digit) {
          found = true;
          break;
        }
      }

      if (!found) {
        digits[0] = num;
        break;
      }
    }
  }
}