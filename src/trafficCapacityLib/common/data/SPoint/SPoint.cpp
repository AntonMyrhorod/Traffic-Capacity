// Standard includes

// Third-party includes
#include <spdlog/spdlog.h>

// Non-local includes

// Local includes
#include "SPoint.hpp"


namespace trcp
{

namespace data
{

SPoint::SPoint (const std::string &name, const float latitude, const float longitude)
: m_name (name), m_latitude (latitude), m_longitude (longitude)
{
    spdlog::trace ("SPoint constructor. m_name: {}, m_latitude: {}, m_longitude{}", name, latitude, longitude);
}

} // namespace data

} // namespace trcp
