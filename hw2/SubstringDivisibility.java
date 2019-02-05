/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke Lopouski
 * We pledge our honor that we have abided by the Stevens Honor System
 */

import java.util.Arrays;

public class SubstringDivisibility {
  public static void main(String[] args) {
    String input = "0123456789"; //args[0];
    // Handle nput

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