//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_CLAMPED
#define CIRCLE_INCLUDE_CLAMPED

#include <algorithm>

template<typename T, T min, T max>
struct clamped
{
    constexpr clamped(T data_)
            :data(std::clamp(data_, min, max)){}

    template<typename Tx, Tx otherMin, Tx otherMax>
    constexpr clamped(const clamped<Tx, otherMin, otherMax>& other)
            :data(std::clamp(static_cast<T>(other.data), min, max)){}

    constexpr clamped(const clamped& other) = default;//special case for when accessing an identical clamped

    constexpr operator T() const
    {
        return data;
    }

    template<typename Tx>
    constexpr clamped& operator =(Tx data_)
    {
        data = std::clamp(static_cast<T>(data_), min, max);
        return *this;
    }

    template<typename Tx, Tx otherMin, Tx otherMax>
    constexpr clamped& operator =(const clamped<Tx, otherMin, otherMax>& other)
    {
        data = std::clamp(static_cast<T>(other.data), min, max);
        return *this;
    }

    constexpr clamped& operator =(const clamped& data) = default;

    template<typename Tx>
    constexpr clamped& operator +=(Tx mod)
    {
        data = std::clamp(static_cast<T>(data + mod), min, max);
        return *this;
    }

    template<typename Tx>
    constexpr clamped& operator -=(Tx mod)
    {
        data = std::clamp(static_cast<T>(data - mod), min, max);
        return *this;
    }

    template<typename Tx>
    constexpr clamped& operator *=(Tx mod)
    {
        data = std::clamp(static_cast<T>(data * mod), min, max);
        return *this;
    }

    template<typename Tx>
    constexpr clamped& operator /=(Tx mod)
    {
        data = std::clamp(static_cast<T>(data / mod), min, max);
        return *this;
    }

    template<typename Tx>
    constexpr clamped& operator %=(Tx mod)
    {
        data = std::clamp(static_cast<T>(data % mod), min, max);
        return *this;
    }

    constexpr clamped& operator++()
    {
        data = std::clamp(++data, min, max);
        return *this;
    }

    constexpr clamped operator++(int)
    {
        const clamped temp = *this;
        ++*this;
        return temp;
    }

    constexpr clamped& operator --()
    {
        data = std::clamp(--data, min, max);
        return *this;
    }

    constexpr clamped operator--(int)
    {
        const clamped temp = *this;
        --*this;
        return temp;
    }

    template<typename Tx, Tx otherMin, Tx otherMax>
    friend struct clamped;

private:
    T data;
};

#endif //CIRCLE_INCLUDE_CLAMPED
