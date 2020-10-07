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
    STimeInterval (const float maxSpeed, const float minSpeed, const STime start, const STime end);

    const float m_maxSpeed; // kilometers per hour [km\h]
    const float m_minSpeed; // kilometers per hour [km\h]
    const STime m_start;
    const STime m_end;
};

} // namespace data

} // namespace trcp
