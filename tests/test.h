#ifndef HAMSTER_TESTS_TEST_H_
#define HAMSTER_TESTS_TEST_H_

#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <string>

inline bool equals(const double a, const double b) {
  return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}

#define TEST_CASE(name) void test_##name()

#define RUN_TEST(name)                                                         \
  do {                                                                         \
    try {                                                                      \
      test_##name();                                                           \
      std::cout << #name << " passed." << std::endl;                           \
    } catch (std::exception & e) {                                             \
      std::cerr << #name << " failed." << std::endl;                           \
    }                                                                          \
  } while (false)

#define EXPECT(expr)                                                           \
  do {                                                                         \
    if (!(expr)) {                                                             \
      std::cerr << __FILE__ << ":" << __LINE__ << ": "                         \
                << "Expected " << #expr << " to be true, but it was false."    \
                << std::endl;                                                  \
      ++g_numTestFailures;                                                     \
    }                                                                          \
  } while (false)

#define ASSERT(expr)                                                           \
  do {                                                                         \
    if (!(expr)) {                                                             \
      std::cerr << __FILE__ << ":" << __LINE__ << ": "                         \
                << "Expected " << #expr << " to be true, but it was false."    \
                << std::endl;                                                  \
      ++g_numTestFailures;                                                     \
      throw std::exception();                                                  \
    }                                                                          \
  } while (false)

#define EXPECT_EQUAL(val1, val2)                                               \
  do {                                                                         \
    if ((val1) != (val2)) {                                                    \
      std::cerr << __FILE__ << ":" << __LINE__ << ": "                         \
                << "Expected " << #val1 << " (" << (val1) << ") "              \
                << "to equal " << #val2 << " (" << (val2) << ")" << std::endl; \
      ++g_numTestFailures;                                                     \
    }                                                                          \
  } while (false)

#define ASSERT_EQUAL(val1, val2)                                               \
  do {                                                                         \
    if ((val1) != (val2)) {                                                    \
      std::cerr << __FILE__ << ":" << __LINE__ << ": "                         \
                << "Expected " << #val1 << " (" << (val1) << ") "              \
                << "to equal " << #val2 << " (" << (val2) << ")" << std::endl; \
      ++g_numTestFailures;                                                     \
      throw std::exception();                                                  \
    }                                                                          \
  } while (false)

#endif
