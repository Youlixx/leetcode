#ifndef __01870_HPP__
#define __01870_HPP__

#include <gtest/gtest.h>

#include <cmath>
#include <vector>

// 01870. Minimum Speed to Arrive on Time -
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
namespace _01870 {
class Solution {
public:
  /// You are given a floating-point number hour, representing the amount of
  /// time you have to reach the office. To commute to the office, you must
  /// take n trains in sequential order. You are also given an integer array
  /// dist of length n, where dist[i] describes the distance (in kilometers) of
  /// the ith train ride.
  /// Each train can only depart at an integer hour, so you may need to wait in
  /// between each train ride.
  /// For example, if the 1st train ride takes 1.5 hours, you must wait for an
  /// additional 0.5 hours before you can depart on the 2nd train ride at the
  /// 2 hour mark.
  /// Return the minimum positive integer speed (in kilometers per hour) that
  /// all the trains must travel at for you to reach the office on time, or -1
  /// if it is impossible to be on time.
  /// Tests are generated such that the answer will not exceed 107 and hour
  /// will have at most two digits after the decimal point.
  int minSpeedOnTime(std::vector<int> &dist, double hour) {
    if (hour <= dist.size() - 1) {
      return -1;
    }

    int minSpeed = 1;
    int maxSpeed = 10000000;

    while (maxSpeed - minSpeed > 1) {
      int speed = (maxSpeed + minSpeed) / 2;

      if (isValidSpeed(dist, speed, hour)) {
        maxSpeed = speed;
      } else {
        minSpeed = speed;
      }
    }

    if (isValidSpeed(dist, minSpeed, hour)) {
      return minSpeed;
    }

    return maxSpeed;
  }

private:
  bool isValidSpeed(std::vector<int> &dist, int speed, double hour) {
    double totalTime = 0;

    for (auto &distance : dist) {
      totalTime = std::ceil(totalTime) + (double)(distance) / speed;

      if (totalTime > hour) {
        return false;
      }
    }

    return true;
  }
};
} // namespace _01870

TEST(_01870, Case1) {
  _01870::Solution solution{};

  std::vector<int> dist{1, 3, 2};

  ASSERT_EQ(solution.minSpeedOnTime(dist, 6), 1);
}

TEST(_01870, Case2) {
  _01870::Solution solution{};

  std::vector<int> dist{1, 3, 2};

  ASSERT_EQ(solution.minSpeedOnTime(dist, 2.7), 3);
}

TEST(_01870, Case3) {
  _01870::Solution solution{};

  std::vector<int> dist{1, 3, 2};

  ASSERT_EQ(solution.minSpeedOnTime(dist, 1.9), -1);
}

#endif
