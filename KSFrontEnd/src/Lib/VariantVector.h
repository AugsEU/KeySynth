// ============================================================================
// Vector which acts like Vector<T*> but doesn't use dynamic allocations
// ----------------------------------------------------------------------------
#pragma once
#include <pch.h>
// ============================================================================
// Include
// ============================================================================
#include <cstddef>
#include <new>
#include <type_traits>
#include <utility>



// ============================================================================
// VariantVector
// ============================================================================
template<typename T, std::size_t MAX_SIZE, std::size_t CAPACITY>
class VariantVector
{
private:
    using Storage = std::aligned_storage_t<MAX_SIZE, alignof(std::max_align_t)>;

    Storage mData[CAPACITY];
    T*      mPointers[CAPACITY];

    std::size_t mSize = 0;

public:
    VariantVector() = default;

    ~VariantVector()
    {
        clear();
    }

    VariantVector(const VariantVector&) = delete;
    VariantVector& operator=(const VariantVector&) = delete;

    VariantVector(VariantVector&& other) noexcept
    {
        *this = std::move(other);
    }

    VariantVector& operator=(VariantVector&& other) noexcept
    {
        if (this != &other)
        {
            clear();

            for (std::size_t i = 0; i < other.mSize; ++i)
            {
                mPointers[i] = other.mPointers[i];

                // Move raw storage
                memcpy(&mData[i], &other.mData[i], MAX_SIZE);

                // Fix pointer to new location
                mPointers[i] = reinterpret_cast<T*>(&mData[i]);
            }

            mSize = other.mSize;
            other.mSize = 0;
        }
        return *this;
    }

    template<typename U, typename... Args>
    U* push_back(Args&&... args)
    {
        static_assert(std::is_base_of<T, U>::value, "U must derive from T");
        static_assert(sizeof(U) <= MAX_SIZE, "U too large for storage");

        if (mSize >= CAPACITY)
            return nullptr; // silent fail

        void* place = &mData[mSize];
        U* obj = new (place) U(std::forward<Args>(args)...);

        mPointers[mSize] = obj;

        ++mSize;
        return obj;
    }

    void pop_back()
    {
        if (mSize == 0)
            return;

        --mSize;
    }

    void clear()
    {
        mSize = 0;
    }

    std::size_t size() const { return mSize; }
    constexpr std::size_t capacity() const { return CAPACITY; }
    bool empty() const { return mSize == 0; }

    T* operator[](std::size_t i)
    {
        return mPointers[i];
    }

    const T* operator[](std::size_t i) const
    {
        return mPointers[i];
    }

    T* front() { return mSize ? mPointers[0] : nullptr; }
    T* back()  { return mSize ? mPointers[mSize - 1] : nullptr; }

    const T* front() const { return mSize ? mPointers[0] : nullptr; }
    const T* back()  const { return mSize ? mPointers[mSize - 1] : nullptr; }

    // Iterators (pointer-style)
    T** begin() { return mPointers; }
    T** end()   { return mPointers + mSize; }

    T* const* begin() const { return mPointers; }
    T* const* end()   const { return mPointers + mSize; }
};
