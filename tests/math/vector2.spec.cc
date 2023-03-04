#include <math/vector2.h>
#include <tests/test.h>

using namespace hamster;

int g_numTestFailures = 0;

TEST_CASE(Vector2) {
  EXPECT(equals(Vector2<double>::dotProduct({1.0, 0.0}, {0.0, 1.0}), 0.0));
  EXPECT(equals(Vector2<double>::dotProduct({1.0, 0.0}, {1.0, 0.0}), 1.0));
  EXPECT(equals(Vector2<double>::dotProduct({1.0, 0.0}, {-1.0, 0.0}), -1.0));
}

int main() {
  RUN_TEST(Vector2);
  return 0;
}
