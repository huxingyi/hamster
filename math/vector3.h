#ifndef HAMSTER_MATH_VECTOR3_H_
#define HAMSTER_MATH_VECTOR3_H_

#include <array>
#include <ostream>

namespace hamster {

template <typename T> class Vector3 {
public:
  Vector3(const T &x, const T &y, const T &z) : m_data{x, y, z} {}

  const T &x() const { return m_data[0]; }

  const T &y() const { return m_data[1]; }

  const T &z() const { return m_data[2]; }

  bool operator==(const Vector3<T> &other) {
    return std::abs(x() - other.x()) < std::numeric_limits<T>::epsilon() &&
           std::abs(y() - other.y()) < std::numeric_limits<T>::epsilon() &&
           std::abs(z() - other.z()) < std::numeric_limits<T>::epsilon();
  }

  bool operator!=(const Vector3<T> &other) { return !(*this == other); }

  T length() const {
    return std::sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1] +
                     m_data[2] * m_data[2]);
  }

  Vector3 normalized() const {
    auto l = length();
    return {m_data[0] / l, m_data[1] / l, m_data[2] / l};
  }

  static Vector3 crossProduct(const Vector3<T> &first,
                              const Vector3<T> &second) {
    return {first.y() * second.z() - first.z() * second.y(),
            first.z() * second.x() - first.x() * second.z(),
            first.x() * second.y() - first.y() * second.x()};
  }

  static double dotProduct(const Vector3<T> &first, const Vector3<T> &second) {
    return first.x() * second.x() + first.y() * second.y() +
           first.z() * second.z();
  }

private:
  std::array<T, 3> m_data;
};

} // namespace hamster

template <typename T>
std::ostream &operator<<(std::ostream &os, const hamster::Vector3<T> &v) {
  return os << "Vector3{" << v.x() << "," << v.y() << "," << v.z() << "}";
}

#endif
