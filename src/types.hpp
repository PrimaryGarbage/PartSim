#ifndef __TYPES_HPP__
#define __TYPES_HPP__

#include <memory>

typedef unsigned int uint;

template<class T>
using Unp = std::unique_ptr<T>;

template<class T>
using Shp = std::shared_ptr<T>;

#endif // __TYPES_HPP__