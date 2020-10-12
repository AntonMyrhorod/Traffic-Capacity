// Standard includes

// Third-party includes
#include <spdlog/spdlog.h>

// Non-local includes

// Local includes
#include "trcp/functions/ssd/CStoppingSightDistance.hpp"


namespace trcp
{

namespace functions
{

float CStoppingSightDistance::getSSD (const float speed, const float brakeReactionTime, const float decelerationRate) const
{
    const float coefficient1 = 0.278F;
    const float coefficient2 = 0.039F;

    float ssd = (coefficient1 * speed * brakeReactionTime) + (coefficient2 * speed * speed / decelerationRate);

    spdlog::debug ("[CStoppingSightDistance::getSSD] ssd: {}", ssd);

    return ssd;
}


} // namespace functions

} // namespace trcp
