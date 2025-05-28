
template<typename T, size_t S>
class Array
{
public:
    constexpr size_t Size() { return S; }
#if 0
    // only read
    T operator[](size_t index) { return m_data[index]; }
#endif
    
    T& operator[](size_t index) { return m_data[index]; }
    const T& operator[](size_t index) const { return m_data[index]; }

    T* Data() { return m_data; }
    const T* Data() const { return m_data; }

private:
    T m_data[S];
};
