#pragma once
#include <cstddef>
#include <guiddef.h>
#include <string>

namespace std
{
    template<> struct hash<GUID>
    {
        std::size_t operator()(GUID const& guid) const noexcept
        {
            std::size_t h1 = std::hash<long>{}(guid.Data1);
            std::size_t h2 = std::hash<std::uint16_t>{}(guid.Data2);
            std::size_t h3 = std::hash<std::uint16_t>{}(guid.Data3);
            std::size_t h4 = std::hash<char>{}((char) guid.Data4);
            
            return h1 ^ ((h2 * h3) << 1) + 397 ^ h4;
        }
    };
}