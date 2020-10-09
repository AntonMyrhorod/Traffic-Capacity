#pragma once

// Standard includes
#include <string>
#include <vector>

// Third-party includes

// Non-local includes

// Local includes
#include "SPoint.hpp"
#include "STimeInterval.hpp"


namespace trcp
{

namespace data
{

struct SRoad
{
    std::string m_name;
    SPoint m_start;
    SPoint m_finish;
    float m_distance = 0; // kilometers [km]
    int m_lines = 0;
    std::vector<STimeInterval> m_timeIntervals;
};

} // namespace data

} // namespace trcp
