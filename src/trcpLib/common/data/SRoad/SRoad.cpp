// Standard includes

// Third-party includes
#include <spdlog/spdlog.h>

// Non-local includes

// Local includes
#include "SRoad.hpp"


namespace trcp
{

namespace data
{

SRoad::SRoad (const std::string &name,
              const SPoint &start,
              const SPoint &finish,
              const float distance,
              const int lines,
              const std::vector<STimeInterval> &timeIntervals)
: m_name (name), m_start (start), m_finish (finish), m_distance (distance), m_lines (lines),
  m_timeIntervals (timeIntervals)
{
    spdlog::trace ("SRoad constructor. m_name: {}, m_start.name: {}, m_finish.name: {}, "
                   "m_distance: {}, m_lines: {}, m_timeIntervals.size: {}",
                   name, start.m_name, finish.m_name, distance, lines, timeIntervals.size ());
}

} // namespace data

} // namespace trcp
