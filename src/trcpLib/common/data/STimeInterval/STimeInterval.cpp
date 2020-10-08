// Standard includes

// Third-party includes
#include <spdlog/spdlog.h>

// Non-local includes

// Local includes
#include "STimeInterval.hpp"

namespace trcp
{

namespace data
{

STimeInterval::STimeInterval (const float maxSpeed, const float minSpeed, const STime start, const STime end)
: m_maxSpeed (maxSpeed), m_minSpeed (minSpeed), m_start (start), m_end (end)
{
    std::string startStr;
    std::string endStr;
    const std::size_t bufferSize = 26;
    char buffer[bufferSize];

    strftime (buffer, bufferSize, "%Y-%m-%d %H:%M:%S", &start);
    startStr = std::string (buffer);
    strftime (buffer, bufferSize, "%Y-%m-%d %H:%M:%S", &end);
    endStr = std::string (buffer);
    spdlog::trace ("STimeInterval constructor. m_maxSpeed: {}, "
                   "m_minSpeed: {}, m_start: {}, m_end: {}",
                   m_maxSpeed, m_minSpeed, startStr, endStr);
}

} // namespace data

} // namespace trcp
