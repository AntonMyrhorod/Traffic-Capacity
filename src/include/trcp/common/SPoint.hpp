#pragma once

// Standard includes
#include <string>

// Third-party includes

// Non-local includes

// Local includes


namespace trcp
{

namespace data
{

struct SPoint
{
    std::string m_name;
    float m_latitude = 0;  // decimal degrees [dd]
    float m_longitude = 0; // decimal degrees [dd]
};

} // namespace data

} // namespace trcp
