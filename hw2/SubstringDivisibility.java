
/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke Lopouski
 * We pledge our honor that we have abided by the Stevens Honor System
 */

import java.util.List;
import java.util.ArrayList;
import java.lang.StringBuilder;

public class SubstringDivisibility {
  public static void main(String[] args) {
    long start = System.currentTimeMillis();

    // Handle nput
    String input = "0123456789"; // args[0];
    int inputLen = input.length();

    // Find valid permutations
    int[] primes = { 2, 3, 5, 7, 11, 13, 17 };
    int numPrimes = inputLen - 3;

    List<String>[] validSubs = getValidSubs(input, primes, numPrimes);

    // * DEBUG
    // Check what is in each ArrayList
    for (int i = 0; i < numPrimes; i++) {
      System.out.println("\nMultiples of " + primes[i] + ":");

      for (String sub : validSubs[i]) {
        System.out.println(sub);
      }
    }

    // Build Valid Strings
    // ArrayList<String> validStrings = new ArrayList<String>();

    // Output
    long finish = System.currentTimeMillis();
    long elapsed = finish - start;

    int sum = 0;
    System.out.println("Sum: " + sum);
    System.out.println("Elapsed time: " + elapsed + "ms");
  }

  private static List<String>[] getValidSubs(String input, int[] primes, int numPrimes) {
    int inputLen = input.length();

    // Find each permutation of 3 digits
    int num3Subs = (inputLen) * (inputLen - 1) * (inputLen - 2);
    int index = 0;
    int[] len3Subs = new int[num3Subs];

    for (int i = inputLen - 1; i >= 0; i--) {
      for (int j = inputLen - 1; j >= 0; j--) {
        for (int k = inputLen - 1; k >= 0; k--) {
          if (i != j && i != k && j != k) {
            String subStr = new StringBuilder().append(input.charAt(i)).append(input.charAt(j)).append(input.charAt(k))
                .toString();

            len3Subs[index] = Integer.parseInt(subStr);
            index++;
          }
        }
      }
    }

    // Find all permutations that are valid for each condition
    List<String>[] validSubs = new ArrayList[numPrimes];
    for (int i = numPrimes - 1; i >= 0; i--) {
      validSubs[i] = new ArrayList<String>();
    }

    for (index = num3Subs - 1; index >= 0; index--) {
      int num = len3Subs[index];

      for (int i = numPrimes - 1; i >= 0; i--) {
        if (num % primes[i] == 0) {
          validSubs[i].add(Integer.toString(num));
        }
      }
    }

    return validSubs;
  }
}