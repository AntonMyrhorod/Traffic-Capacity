#pragma once

// Standard includes
#include <ctime>
#include <string>
#include <vector>

// Third-party includes

// Non-local includes

// Local includes


namespace trcp
{

namespace data
{

typedef struct tm STime;

struct STimeInterval
{
    float m_maxSpeed = 0; // kilometers per hour [km\h]
    float m_minSpeed = 0; // kilometers per hour [km\h]
    STime m_start = {};
    STime m_end = {};
};

} // namespace data

} // namespace trcp
