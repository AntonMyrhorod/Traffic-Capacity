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

    output.m_name = root["road"]["name"].asString ();
    output.m_distance = root["road"]["distance-km"].asFloat ();
    output.m_lines = root["road"]["lines"].asInt ();

    spdlog::debug ("[CReaderFromJson::parse] Road name: {}, distance: {}, lines: {}", output.m_name,
                   output.m_distance, output.m_lines);

    data::SPoint startPoint;
    data::SPoint finishPoint;

    startPoint.m_name = root["road"]["startPoint"]["name"].asString ();
    startPoint.m_latitude = root["road"]["startPoint"]["latitude-dd"].asFloat ();
    startPoint.m_longitude = root["road"]["startPoint"]["longitude-dd"].asFloat ();
    finishPoint.m_name = root["road"]["finishPoint"]["name"].asString ();
    finishPoint.m_latitude = root["road"]["finishPoint"]["latitude-dd"].asFloat ();
    finishPoint.m_longitude = root["road"]["finishPoint"]["longitude-dd"].asFloat ();

    output.m_start = startPoint;
    output.m_finish = finishPoint;

    spdlog::debug ("[CReaderFromJson::parse] Road start point: {}, finish point: {}",
                   startPoint.m_name, finishPoint.m_name);

    const int epochYear = 1900;
    const int year = root["road"]["year"].asInt ();
    const int month = root["road"]["month"].asInt ();
    const int day = root["road"]["day"].asInt ();

    spdlog::debug ("[CReaderFromJson::parse] Statictic date: {}.{}.{}", day, month, year);

    for (const auto &it : root["road"]["timeIntervals"])
    {
        data::STimeInterval timeInterval;

        timeInterval.m_maxSpeed = it["maxSpeed-kmh"].asFloat ();
        timeInterval.m_minSpeed = it["minSpeed-kmh"].asFloat ();

        timeInterval.m_start.tm_year = year - epochYear;
        timeInterval.m_start.tm_mon = month - 1;
        timeInterval.m_start.tm_mday = day;
        timeInterval.m_start.tm_hour = it["startHours"].asInt ();
        timeInterval.m_start.tm_min = it["startMinutes"].asInt ();
        mktime (&timeInterval.m_start);

        timeInterval.m_end.tm_year = year - epochYear;
        timeInterval.m_end.tm_mon = month - 1;
        timeInterval.m_end.tm_mday = day;
        timeInterval.m_end.tm_hour = it["endHours"].asInt ();
        timeInterval.m_end.tm_min = it["endMinutes"].asInt ();
        mktime (&timeInterval.m_end);

        spdlog::debug ("[CReaderFromJson::parse] time interval: {}:{}, {}:{}, max speed: {} km.h, "
                       "min speed: {} km.h",
                       it["startHours"].asInt (), it["startMinutes"].asInt (), it["endHours"].asInt (),
                       it["endMinutes"].asInt (), timeInterval.m_maxSpeed, timeInterval.m_minSpeed);

        output.m_timeIntervals.push_back (timeInterval);
    }
}

} // namespace reader

} // namespace trcp
