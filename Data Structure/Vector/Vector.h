#pragma once
#include <cstddef>    // size_t
#include <utility>    // std::move, std::forward

template <typename T, size_t InitialCapacity = 2>
class Vector {
public:
    Vector() : m_Data(nullptr), m_Size(0), m_Capacity(0) {
        ReAlloc(InitialCapacity);
    }

    ~Vector() {
        clear();
        ::operator delete(m_Data);

    }

    void PushBack(const T& value) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);
        new (&m_Data[m_Size++]) T(value);
    }

    void PushBack(T&& value) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);
        new (&m_Data[m_Size++]) T(std::move(value));
    }

    template<typename... Args>
    void EmplaceBack(Args&&... args) {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);
        new (&m_Data[m_Size++]) T(std::forward<Args>(args)...);
    }

    void PopBack() {
        if (m_Size > 0)
            m_Data[--m_Size].~T();
    }

    void clear() {
        for (size_t i = 0; i < m_Size; ++i)
            m_Data[i].~T();
        m_Size = 0;
    }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

    size_t Size() const { return m_Size; }

private:
    void ReAlloc(size_t newCapacity) {
        T* newBlock = static_cast<T*>(::operator new(newCapacity * sizeof(T)));

        for (size_t i = 0; i < m_Size; ++i)
            new (&newBlock[i]) T(std::move(m_Data[i]));

        for (size_t i = 0; i < m_Size; ++i)
            m_Data[i].~T();

        ::operator delete(m_Data);
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }

private:
    T* m_Data;
    size_t m_Size;
    size_t m_Capacity;
};
