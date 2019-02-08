
/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke Lopouski
 * We pledge our honor that we have abided by the Stevens Honor System
 */

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class SubstringDivisibility {
  public static void main(String[] args) {
    // Handle input
    int[] nums = parseInput(args[0]);

    long start = System.nanoTime();

    // Find valid numbers for each condition
    int[] primes = { 2, 3, 5, 7, 11, 13, 17 };

    List<Integer>[] validParts = getValidParts(nums, primes);

    // *DEBUG
    // for (int i = 0; i < nums.length - 3; i++) {
    //   System.out.printf("Multiples of: %d\n", primes[i]);
    //   for (int subi : validParts[i]) {
    //     System.out.println(subi);
    //   }
    // }
    // System.out.println();

    // Build Valid Strings
    List<Integer> validNums = getValidFull(validParts, nums);

    // Output
    long sum = 0;
    for (int num : validNums) {
      System.out.println(num);
      sum += num;
    }

    System.out.println(new StringBuilder().append("Sum: ").append(sum));
    System.out.printf("Elapsed time: %.6f ms\n", (System.nanoTime() - start) / 1e6);
  }

  private static int concatInt(int... nums) {
    if (nums.length > 1) {
      return nums[0] * ((int) Math.pow(10, nums.length - 1)) + concatInt(Arrays.copyOfRange(nums, 1, nums.length));
    } else {
      return nums[0];
    }
  }

  // private static int subInt(int num, int start, int end) {

  // }

  private static int getDigit(int num, int place) {
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

  private static int[] parseInput(String input) {
    char[] chars = input.toCharArray();
    int[] nums = new int[chars.length];

    for (int i = nums.length - 1; i >= 0; i--) {
      nums[i] = chars[i] - '0';
    }

    return nums;
  }

  private static List<Integer>[] getValidParts(int[] nums, int[] primes) {
    int numPrimes = nums.length - 3;

    // Find each permutation of 3 digits
    int num3Subs = (nums.length) * (nums.length - 1) * (nums.length - 2);
    int index = 0;
    int[] len3Subs = new int[num3Subs];

    for (int i = nums.length - 1; i >= 0; i--) {
      for (int j = nums.length - 1; j >= 0; j--) {
        for (int k = nums.length - 1; k >= 0; k--) {
          if (i != j && i != k && j != k) {
            len3Subs[index] = concatInt(nums[i], nums[j], nums[k]);
            index++;
          }
        }
      }
    }

    // Find all permutations that are valid for each condition
    List<Integer>[] validNums = new ArrayList[numPrimes];
    for (int i = numPrimes - 1; i >= 0; i--) {
      validNums[i] = new ArrayList<Integer>();
    }

    for (index--; index >= 0; index--) {
      int num = len3Subs[index];

      for (int i = numPrimes - 1; i >= 0; i--) {
        if (num % primes[i] == 0) {
          validNums[i].add(num);
        }
      }
    }

    return validNums;
  }

  private static List<Integer> getValidFull(List<Integer>[] validParts, int[] nums) {
    return completeNum(0, validParts, 0, nums);
  }

  private static List<Integer> completeNum(int num, List<Integer>[] parts, int index, int[] nums) {
    List<Integer> possibleNums = new ArrayList<Integer>();

    if (index < parts.length) {
      for (int next : parts[index]) {
        if (validNext(num, next)) {
          possibleNums
              .addAll(completeNum(concatInt(num, (num == 0) ? next : getDigit(next, 1)), parts, index + 1, nums));
        }
      }
    } else {
      possibleNums.add(addMissingDigit(num, nums));
    }

    return possibleNums;
  }

  private static boolean validNext(int num, int next) {
    return num == 0 || containsDigit(num, getDigit(next, 1)) && getDigit(num, 1) == getDigit(next, 2)
        && getDigit(num, 2) == getDigit(next, 3);
  }

  private static int addMissingDigit(int num, int[] nums) {
    for (int i = 0; i < nums.length; i++) {
      int numDigits = (int) Math.log(num) + 1;
      int j;
      for (j = 1; j <= numDigits; j++) {
        if (nums[i] == getDigit(num, j)) {
          break;
        }
      }

      if (j == numDigits) {
        return concatInt(nums[i], num);
      }
    }

    return num;
  }
}