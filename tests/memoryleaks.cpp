
#include "memoryleaks.h"

#include <cstddef>
#include <valgrind/valgrind.h>
#include <valgrind/memcheck.h>
#include <valgrind/callgrind.h>
#include <valgrind/helgrind.h>

using std::size_t;

MemoryLeaks::MemoryLeaks() : MemoryLeaks(0,0,0,0){}

MemoryLeaks::MemoryLeaks(size_t leaked,
             size_t dubious,
             size_t reachable,
             size_t suppressed) :
        _leaked(leaked),
        _dubious(dubious),
        _reachable(reachable),
        _suppressed(suppressed){}

MemoryLeaks::~MemoryLeaks(){}

bool MemoryLeaks::hasBeenLeaks(){
    return _leaked + _dubious + _reachable + _suppressed;//false if all == 0
}

MemoryLeaks MemoryLeaks::operator+(const MemoryLeaks &other){
    return MemoryLeaks{_leaked+other._leaked,
            _dubious+other._dubious,
            _reachable+other._reachable,
            _suppressed+other._suppressed};
}

MemoryLeaks &MemoryLeaks::operator+=(const MemoryLeaks &other){
    _leaked += other._leaked;
    _dubious += other._dubious;
    _reachable += other._reachable;
    _suppressed += other._suppressed;

    return *this;
}

MemoryLeaks MemoryLeaks::operator-(const MemoryLeaks &other){
    return MemoryLeaks{_leaked-other._leaked,
            _dubious-other._dubious,
            _reachable-other._reachable,
            _suppressed-other._suppressed};
}

MemoryLeaks &MemoryLeaks::operator-=(const MemoryLeaks &other){
    _leaked -= other._leaked;
    _dubious -= other._dubious;
    _reachable -= other._reachable;
    _suppressed -= other._suppressed;

    return *this;
}

MemoryLeaks MemoryLeaks::measureLeaks(){
    if(RUNNING_ON_VALGRIND){
        VALGRIND_DO_ADDED_LEAK_CHECK;

        unsigned long leaked, dubious, reachable, suppressed;
        VALGRIND_COUNT_LEAKS(leaked, dubious, reachable, suppressed)

        return MemoryLeaks{ leaked, dubious, reachable, suppressed};
    }

    return MemoryLeaks();
}