

template<typename T, size_t S>
class Array
{
public:
    
    using iterator = ArrayIterator<T>;
    using const_iterator = ArrayIterator<const T>;
    
    constexpr size_t Size() { return S; }
#if 0
    // only read
    T operator[](size_t index) { return m_data[index]; }
#endif
    
    T& operator[](size_t index) { return m_data[index]; }
    const T& operator[](size_t index) const { return m_data[index]; }

    T* Data() { return m_data; }
    const T* Data() const { return m_data; }
    
    

    iterator begin() { return iterator(m_data); }
    iterator end() { return iterator(m_data + S); }

    const_iterator begin() const { return const_iterator(m_data); }
    const_iterator end() const { return const_iterator(m_data + S); }

    
    
private:
    T m_data[S];
};
