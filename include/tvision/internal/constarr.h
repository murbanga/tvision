#ifndef TVISION_CONSTARR_H
#define TVISION_CONSTARR_H

#include <stddef.h>

#if !defined(__GNUC__ ) || __GNUC__ >= 9 || (__GNUC__ == 5 && __GNUC_MINOR__ <= 3)
#define ARRAY_CONSTEXPR constexpr
#else
#define ARRAY_CONSTEXPR
#endif


// std::array is not constexpr until C++17. So we make our own, which costs
// nothing.

namespace tvision
{

template <class T, size_t N>
struct constarray
{
    T elems[N];

    ARRAY_CONSTEXPR T& operator[](size_t i) noexcept
    {
        return elems[i];
    }

    ARRAY_CONSTEXPR const T& operator[](size_t i) const noexcept
    {
        return elems[i];
    }

};

} // namespace tvision

#endif // TVISION_CONSTARR_H
