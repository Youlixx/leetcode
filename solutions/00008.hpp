#ifndef __00008_HPP__
#define __00008_HPP__

#include <gtest/gtest.h>

#include <climits>
#include <string>

// 00008. String to Integer (atoi) -
// https://leetcode.com/problems/string-to-integer-atoi/
namespace _00008 {
class Solution {
public:
  /// Implement the myAtoi(string s) function, which converts a string to a
  /// 32-bit signed integer (similar to C/C++'s atoi function).
  /// The algorithm for myAtoi(string s) is as follows:
  /// - Read in and ignore any leading whitespace.
  /// - Check if the next character (if not already at the end of the string)
  ///   is '-' or '+'. Read this character in if it is either. This determines
  ///   if the final result is negative or positive respectively. Assume the
  ///   result is positive if neither is present.
  /// - Read in next the characters until the next non-digit character or the
  ///   end of the input is reached. The rest of the string is ignored.
  /// - Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
  ///   If no digits were read, then the integer is 0. Change the sign as
  ///   necessary (from step 2).
  /// - If the integer is out of the 32-bit signed integer range
  ///   [-231, 231 - 1], then clamp the integer so that it remains in the
  ///   range. Specifically, integers less than -231 should be clamped to -231,
  ///   and integers greater than 231 - 1 should be clamped to 231 - 1.
  /// - Return the integer as the final result.
  /// Note:
  /// - Only the space character ' ' is considered a whitespace character.
  /// - Do not ignore any characters other than the leading whitespace or the
  ///   rest of the string after the digits.
  int myAtoi(std::string s) { return Parser().parse(s); }

private:
  enum ParserStep { SKIPPING, CONSUMING, DONE };
  enum ParserSign { POSITIVE, NEGATIVE, INFERRED };

  struct Parser {
    long num;

    ParserStep step;
    ParserSign sign;

    Parser() : num{0}, step{ParserStep::SKIPPING}, sign{ParserSign::INFERRED} {}

    int parse(std::string s) {
      for (const auto &c : s) {
        consume(c);

        if (step == ParserStep::DONE) {
          break;
        }
      }

      return num;
    }

    void consume(char c) {
      switch (step) {
      case ParserStep::SKIPPING:
        switch (c) {
        case ' ':
          break;
        case '-':
          step = ParserStep::CONSUMING;
          sign = ParserSign::NEGATIVE;
          break;
        case '+':
          step = ParserStep::CONSUMING;
          sign = ParserSign::POSITIVE;
          break;
        default:
          if (c >= '0' && c <= '9') {
            step = ParserStep::CONSUMING;
            num = c - '0';
          } else {
            step = ParserStep::DONE;
          }

          break;
        }

        break;
      case ParserStep::CONSUMING:
        if (c >= '0' && c <= '9') {
          num *= 10;

          if (sign != ParserSign::NEGATIVE) {
            num += c - '0';
          } else {
            num -= c - '0';
          }
        } else {
          step = ParserStep::DONE;
        }

        break;
      default:
        break;
      }

      if (num > INT_MAX) {
        step = ParserStep::DONE;
        num = INT_MAX;
      } else if (num < INT_MIN) {
        step = ParserStep::DONE;
        num = INT_MIN;
      }
    }
  };
};
} // namespace _00008

TEST(_00008, Case1) {
  _00008::Solution solution{};

  ASSERT_EQ(solution.myAtoi("42"), 42);
}

TEST(_00008, Case2) {
  _00008::Solution solution{};

  ASSERT_EQ(solution.myAtoi("   -42"), -42);
}

TEST(_00008, Case3) {
  _00008::Solution solution{};

  ASSERT_EQ(solution.myAtoi("4193 with words"), 4193);
}

TEST(_00008, Case4) {
  _00008::Solution solution{};

  ASSERT_EQ(solution.myAtoi("-91283472332"), INT_MIN);
}

TEST(_00008, Case5) {
  _00008::Solution solution{};

  ASSERT_EQ(solution.myAtoi("20000000000000000000"), INT_MAX);
}

#endif
