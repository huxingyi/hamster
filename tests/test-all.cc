#include <math/vector2.h>
#include <math/vector3.h>
#include <tests/test.h>

using namespace hamster;

int g_numTestFailures = 0;

TEST_CASE(Vector2) {
  EXPECT(equals(Vector2<double>::dotProduct({1.0, 0.0}, {0.0, 1.0}), 0.0));
  EXPECT(equals(Vector2<double>::dotProduct({1.0, 0.0}, {1.0, 0.0}), 1.0));
  EXPECT(equals(Vector2<double>::dotProduct({1.0, 0.0}, {-1.0, 0.0}), -1.0));
}

TEST_CASE(Vector3) {
  EXPECT(Vector3<double>::crossProduct({1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}) ==
         Vector3<double>(0.0, 0.0, 1.0));
  EXPECT(Vector3<double>::crossProduct({0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}) ==
         Vector3<double>(1.0, 0.0, 0.0));
  EXPECT(Vector3<double>::crossProduct({0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}) ==
         Vector3<double>(0.0, 1.0, 0.1));
}

int main() {
  RUN_TEST(Vector2);
  RUN_TEST(Vector3);

  std::cout << (g_numTestFailures > 0
                    ? std::to_string(g_numTestFailures) + " FAILED"
                    : "all passed")
            << std::endl;
  return 0;
}
