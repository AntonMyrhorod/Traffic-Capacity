#pragma once

// Standard includes

// Third-party includes

// Non-local includes

// Local includes


namespace trcp
{

namespace functions
{

class IStoppingSightDistance
{
    public:
    virtual ~IStoppingSightDistance () = default;

    virtual float getSSD (const float speed,             /* kilometers per hour [km\h] */
                          const float brakeReactionTime, /* seconds [sec] */
                          const float decelerationRate /* metre per second squared [m/sec^2] */) const = 0;
};

} // namespace functions

} // namespace trcp
