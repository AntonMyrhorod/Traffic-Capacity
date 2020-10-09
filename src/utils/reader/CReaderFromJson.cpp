// Standard includes
#include <fstream>

// Third-party includes
#include <json/json.h>
#include <spdlog/spdlog.h>

// Non-local includes
#include "trcp/utils/CReaderFromJson.hpp"

// Local includes


namespace trcp
{

namespace reader
{

void CReaderFromJson::parse (const std::string &source, data::SRoad &output)
{
    std::ifstream ifs (source);

    if (!ifs.is_open ())
    {
        spdlog::error ("[CReaderFromJson::parse] Failed to open config: {}", source);
        throw std::exception ("Failed to open config");
    }

    Json::CharReaderBuilder builder;
    Json::Value root;
    JSONCPP_STRING errs;

    if (!parseFromStream (builder, ifs, &root, &errs))
    {
        spdlog::error ("[CReaderFromJson::parse] Failed to parse json file: {}", errs.c_str ());
        throw std::exception (errs.c_str ());
    }

    data::SRoad road;

    road.m_name = root["road"]["name"].asString ();
    road.m_distance = root["road"]["distance-km"].asFloat ();
    road.m_lines = root["road"]["lines"].asInt ();

    spdlog::debug ("[CReaderFromJson::parse] Road name: {}, distance: {}, lines: {}", road.m_name,
                   road.m_distance, road.m_lines);

    data::SPoint startPoint;
    data::SPoint finishPoint;

    startPoint.m_name = root["road"]["startPoint"]["name"].asString ();
    startPoint.m_latitude = root["road"]["startPoint"]["latitude-dd"].asFloat ();
    startPoint.m_longitude = root["road"]["startPoint"]["longitude-dd"].asFloat ();
    finishPoint.m_name = root["road"]["finishPoint"]["name"].asString ();
    finishPoint.m_latitude = root["road"]["finishPoint"]["latitude-dd"].asFloat ();
    finishPoint.m_longitude = root["road"]["finishPoint"]["longitude-dd"].asFloat ();

    road.m_start = startPoint;
    road.m_finish = finishPoint;

    spdlog::debug ("[CReaderFromJson::parse] Road start point: {}, finish point: {}",
                   startPoint.m_name, finishPoint.m_name);
}

} // namespace reader

} // namespace trcp
