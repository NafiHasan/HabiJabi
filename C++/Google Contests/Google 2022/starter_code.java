import java.util.*;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int testCases = in.nextInt();
    for (int testCase = 1; testCase <= testCases; testCase++) {
      int numberOfFriends = in.nextInt();
      int numberOfForibbenTeas = in.nextInt();
      int optionsOffered = in.nextInt();
      int[][] friendsOrders = new int[numberOfFriends][optionsOffered];
      for (int friend = 0; friend < numberOfFriends; friend++) {
        String currentFriendOrder = in.next().trim();
        for (int option = 0; option < optionsOffered; option++) {
          friendsOrders[friend][option] =
              Character.getNumericValue(currentFriendOrder.charAt(option));
        }
      }
      int[][] forbiddenOrders = new int[numberOfForibbenTeas][optionsOffered];
      for (int forbiddenIndex = 0; forbiddenIndex < numberOfForibbenTeas; forbiddenIndex++) {
        String currentForbiddenTeaOrder = in.next().trim();
        for (int option = 0; option < optionsOffered; option++) {
          forbiddenOrders[forbiddenIndex][option] =
              Character.getNumericValue(currentForbiddenTeaOrder.charAt(option));
        }
      }
      int ans = findSmallestNumberOfComplaints(friendsOrders, forbiddenOrders);
      System.out.println("Case #" + testCase + ": " + ans);
    }
  }

  static int findSmallestNumberOfComplaints(int[][] friendsOrders, int[][] forbiddenOrders) {
    // TODO: implement this method to find the smallest number of complaints given that Shakti will
    // only be getting 1 type of tea for his friends.
    int smallestNumberOfComplaints = -1;
    return smallestNumberOfComplaints;
  }
}
