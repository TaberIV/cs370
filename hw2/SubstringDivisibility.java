
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

    Arrays.sort(nums);

    return nums;
  }

  private static List<int[]> getValidNums(int[] nums) {
    return completeNum(new int[nums.length], nums, 1);
  }

  private static List<int[]> completeNum(int[] digits, int[] nums, int index) {
    List<int[]> possibleNums = new ArrayList<int[]>();

    if (index < nums.length) {
      for (int num : nums) {
        if (validNext(digits, num, index)) {
          int[] newDigits = digits.clone();
          newDigits[index] = num;
          
          // System.out.printf("Added %d at index %d to ", num, index);
          // for (int i = 0; i <= index; i++) {
          //   System.out.print(newDigits[i]);
          // }
          // System.out.println();

          possibleNums.addAll(completeNum(newDigits, nums, index + 1));
        }
      }
    } else {
      addMissingDigit(digits, nums);
      possibleNums.add(digits);
    }

    return possibleNums;
  }

  private static boolean validNext(int[] digits, int next, int index) {
    // Check for uniqueness
    for (int i = 1; i < index; i++) {
      if (digits[i] == next) {
        return false;
      }
    }

    // Check for prime conditions
    boolean primeMult = index < 3;
    if (!primeMult) {
      int concat = concatInt(digits[index - 2], digits[index - 1], next);
      primeMult = (concat % primes[index - 3]) == 0;
    }

    return primeMult;
  }

  private static int[] addMissingDigit(int[] digits, int[] nums) {
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

    return digits;
  }
}