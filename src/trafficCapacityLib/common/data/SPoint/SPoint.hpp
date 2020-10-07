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
    SPoint (const std::string &name, const float latitude, const float longitude);

    const std::string m_name;
    const float m_latitude;  // decimal degrees [dd]
    const float m_longitude; // decimal degrees [dd]
};

} // namespace data

} // namespace trcp
