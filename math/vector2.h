#ifndef HAMSTER_MATH_VECTOR2_H_
#define HAMSTER_MATH_VECTOR2_H_

#include <array>

namespace hamster {

template <typename T> class Vector2 {
public:
  Vector2(const T &x, const T &y) : m_data{x, y} {}

  const T &x() const { return m_data[0]; }

  const T &y() const { return m_data[1]; }

  static double dotProduct(const Vector2<T> &first, const Vector2<T> &second) {
    return first.x() * second.x() + first.y() * second.y();
  }

private:
  std::array<T, 2> m_data;
};

} // namespace hamster

#endif
