#ifndef MEMORYLEAKS_H
#define MEMORYLEAKS_H

#include <cstddef>

class MemoryLeaks {

public:
    MemoryLeaks();
    MemoryLeaks(  std::size_t leaked,
                  std::size_t dubious,
                  std::size_t reachable,
                  std::size_t suppressed);

    MemoryLeaks(const MemoryLeaks &other) = default;
    MemoryLeaks &operator=(const MemoryLeaks &other) = default;
    MemoryLeaks(MemoryLeaks &&other) = default;
    MemoryLeaks &operator=(MemoryLeaks &&other) = default;

    virtual ~MemoryLeaks();

    bool hasBeenLeaks();
    static MemoryLeaks measureLeaks();

    MemoryLeaks operator+(const MemoryLeaks &other);
    MemoryLeaks &operator+=(const MemoryLeaks &other);
    MemoryLeaks operator-(const MemoryLeaks &other);
    MemoryLeaks &operator-=(const MemoryLeaks &other);

protected:
private:
    std::size_t _leaked;
    std::size_t _dubious;
    std::size_t _reachable;
    std::size_t _suppressed;
};

#endif // MEMORYLEAKS_H
