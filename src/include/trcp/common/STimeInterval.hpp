#pragma once

// Standard includes
#include <string>
#include <time.h>
#include <vector>

// Third-party includes

// Non-local includes

// Local includes


typedef struct tm STime;

namespace trcp
{

namespace data
{

struct STimeInterval
{
    float m_maxSpeed = 0; // kilometers per hour [km\h]
    float m_minSpeed = 0; // kilometers per hour [km\h]
    STime m_start;
    STime m_end;
};

} // namespace data

} // namespace trcp
