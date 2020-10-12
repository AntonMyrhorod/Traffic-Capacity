#pragma once

#include <string>

#include "trcp/common/SPoint.hpp"
#include "trcp/common/SRoad.hpp"
#include "trcp/common/STimeInterval.hpp"
#include "trcp/functions/ssd/CStoppingSightDistance.hpp"
#include "trcp/functions/ssd/IStoppingSightDistance.hpp"
#include "trcp/utils/CReaderFromJson.hpp"
#include "trcp/utils/IReader.hpp"

namespace trcp
{

inline std::string version ()
{
    std::string version;

    version += "trcp (Traffic Capacity Library) " + std::string (TRCP_VERSION) + '\n';
    version += "MIT License. Copyright (c) 2020\n";

    return version;
}

} // namespace trcp

// TODO: print library version
