#pragma once

// Standard includes
#include <string>

// Third-party includes

// Non-local includes
#include "trcp/common/SRoad.hpp"

// Local includes


namespace trcp
{

namespace reader
{

class IReader
{
    public:
    virtual ~IReader () = default;

    virtual void parse (const std::string &source, data::SRoad &output) = 0;
};

} // namespace reader

} // namespace trcp
