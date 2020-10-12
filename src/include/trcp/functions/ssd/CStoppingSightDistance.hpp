#pragma once

// Standard includes

// Third-party includes

// Non-local includes

// Local includes
#include "IStoppingSightDistance.hpp"


namespace trcp
{

namespace functions
{

class CStoppingSightDistance : public IStoppingSightDistance
{
    public:
    ~CStoppingSightDistance () override = default;

    float getSSD (const float speed, const float brakeReactionTime = 2.5, const float decelerationRate = 3.4) const override;
};

} // namespace functions

} // namespace trcp
