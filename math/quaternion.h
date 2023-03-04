#ifndef HAMSTER_MATH_QUATERNION_H_
#define HAMSTER_MATH_QUATERNION_H_

#include <array>
#include <cmath>
#include <math/vector3.h>

namespace hamster {

template <typename T> class Quaternion {
public:
  Quaternion(const T &angle, const Vector3<T> &axis) {
    const auto halfAngle = angle * static_cast<T>(0.5);
    auto sinOfHalfAngle = std::sin(halfAngle);
    auto cosOfHalfAngle = std::cos(halfAngle);
    m_data[0] = cosOfHalfAngle;
    m_data[1] = sinOfHalfAngle * axis.x();
    m_data[2] = sinOfHalfAngle * axis.y();
    m_data[3] = sinOfHalfAngle * axis.z();
  }

  Quaternion(const T &w, const T &x, const T &y, const T &z)
      : m_data{w, x, y, z} {}

  const T &w() const { return m_data[0]; }

  const T &x() const { return m_data[1]; }

  const T &y() const { return m_data[2]; }

  const T &z() const { return m_data[3]; }

  Quaternion conjugated() const {
    return Quaternion(m_data[0], -m_data[1], -m_data[2], -m_data[3]);
  }

  Quaternion operator*(const Quaternion<T> &other) {
    return Quaternion(other.w() * m_data[0] - other.x() * m_data[1] -
                          other.y() * m_data[2] - other.z() * m_data[3],
                      other.w() * m_data[1] + other.x() * m_data[0] -
                          other.y() * m_data[3] + other.z() * m_data[2],
                      other.w() * m_data[2] + other.x() * m_data[3] +
                          other.y() * m_data[0] - other.z() * m_data[1],
                      other.w() * m_data[3] - other.x() * m_data[2] +
                          other.y() * m_data[1] + other.z() * m_data[0]);
  }

  Vector3<T> rotated(const Vector3<T> &vector) {
    auto q = (*this * Quaternion(static_cast<T>(0.0), vector.x(), vector.y(),
                                 vector.z())) *
             conjugated();
    return Vector3(q.x(), q.y(), q.z());
  }

private:
  std::array<T, 4> m_data;
};

} // namespace hamster

#endif
