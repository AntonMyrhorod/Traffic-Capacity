#pragma once

// Standard includes
#include <string>
#include <vector>

// Third-party includes

// Non-local includes

// Local includes
#include "common/data/SPoint/SPoint.hpp"
#include "common/data/STimeInterval/STimeInterval.hpp"


namespace trcp
{

namespace data
{

struct SRoad
{
    SRoad (const std::string &name, const SPoint &start, const SPoint &finish, const std::vector<STimeInterval> &timeIntervals);

    const std::string m_name;
    const SPoint m_start;
    const SPoint m_finish;
    const std::vector<STimeInterval> m_timeIntervals;
};

} // namespace data

} // namespace trcp
