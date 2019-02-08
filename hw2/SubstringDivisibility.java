
/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke Lopouski
 * We pledge our honor that we have abided by the Stevens Honor System
 */

import java.util.List;
import java.util.ArrayList;
import java.lang.StringBuilder;

public class SubstringDivisibility {
  public static void main(String[] args) {
    long start = System.nanoTime();

    // Handle nput
    String input = args[0];
    int inputLen = input.length();

    // Find valid substrings for each condition
    int[] primes = { 2, 3, 5, 7, 11, 13, 17 };
    int numPrimes = inputLen - 3;

    List<String>[] validSubs = getValidSubs(input, primes, numPrimes);

    // Build Valid Strings
    List<String> validStrings = getValidStrings(validSubs, input);

    // Output
    long sum = 0;
    for (String str : validStrings) {
      System.out.println(str);
      sum += Long.parseLong(str);
    }

    System.out.println(new StringBuilder().append("Sum: ").append(sum));
    System.out.printf("Elapsed time: %.6f ms\n", (System.nanoTime() - start) / 1e6);
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
          StringBuilder numBuild = new StringBuilder();

          if (num < 100) {
            numBuild.append('0');
          }
          numBuild.append(num);

          validSubs[i].add(numBuild.toString());
        }
      }
    }

    return validSubs;
  }

  private static List<String> getValidStrings(List<String>[] validSubs, String input) {
    return completeSubStr("", validSubs, 0, input);
  }

  private static List<String> completeSubStr(String str, List<String>[] subs, int index, String input) {
    List<String> possibleStrings = new ArrayList<String>();

    if (index < subs.length) {
      int len = subs[index].size();

      for (int i = 0; i < len; i++) {
        String next = subs[index].get(i);

        if (validNext(str, next)) {
          possibleStrings.addAll(
              completeSubStr(new StringBuilder().append(str).append(str.isEmpty() ? next : next.charAt(2)).toString(),
                  subs, index + 1, input));
        }
      }
    } else {
      possibleStrings.add(addMissingDigit(str, input));
    }

    return possibleStrings;
  }

  public static boolean validNext(String str, String next) {
    return str.isEmpty() || str.indexOf(next.charAt(2)) == -1 && str.indexOf(next.substring(0, 2)) == str.length() - 2;
  }

  public static String addMissingDigit(String str, String input) {
    int strlen = str.length();
    int inputlen = input.length();

    for (int i = 0; i < inputlen; i++) {
      int j;
      for (j = 0; j < strlen; j++) {
        if (input.charAt(i) == str.charAt(j)) {
          break;
        }
      }

      if (j == strlen) {
        return new StringBuilder().append(input.charAt(i)).append(str).toString();
      }
    }

    return str;
  }
}