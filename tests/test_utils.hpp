#pragma once
#include <stdexcept>

#define ASSERT(_cond, _msg) do { if (!(_cond)) throw std::runtime_error(_msg); } while(0)
