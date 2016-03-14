#ifndef ABSTR_CC_MEMORY_H
#define ABSTR_CC_MEMORY_H

//Abstract Ram

#include <vector>
#include <stdexcept>

namespace abstr_cc
{
    template <typename T>
    class Ram
    {
    public:
        Ram(std::size_t size)
        {
            _memory.reserve(size);
            for (std::size_t i = 0; i < size; i++)
                _memory.push_back(T());
        }

        std::size_t size() const { return _memory.size(); }

        void set(std::size_t index, const T &value)
        {
            if (index >= _memory.size())
                throw std::out_of_range("abstr_cc::Memory::set -> index out of range");

            _memory[index] = value;
        }

        const T &get(std::size_t index) const
        {
            if (index >= _memory.size())
                throw std::out_of_range("abstr_cc::Memory::get -> index out of range");

            return _memory[index];
        }

        Ram &operator =(const Ram &ram)
        {
            _memory = ram._memory;
            return *this;
        }

    private:
        std::vector<T> _memory;
    };
}

#endif // ABSTR_CC_MEMORY_H
