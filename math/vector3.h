#ifndef HAMSTER_MATH_VECTOR3_H_
#define HAMSTER_MATH_VECTOR3_H_

#include <array>

namespace hamster {

template <typename T> class Vector3 {
public:
  Vector3(const T &x, const T &y, const T &z) : m_data{x, y, z} {}

  const T &x() const { return m_data[0]; }

  const T &y() const { return m_data[1]; }

  const T &z() const { return m_data[2]; }

  bool operator==(const Vector3<T> &other) { return m_data == other.m_data; }

  static Vector3 crossProduct(const Vector3<T> &first,
                              const Vector3<T> &second) {
    return {first.y() * second.z() - first.z() * second.y(),
            first.z() * second.x() - first.x() * second.z(),
            first.x() * second.y() - first.y() * second.x()};
  }

private:
  std::array<T, 3> m_data;
};

} // namespace hamster

#endif
