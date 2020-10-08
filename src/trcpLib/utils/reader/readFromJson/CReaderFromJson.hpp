#pragma once

// Standard includes

// Third-party includes

// Non-local includes

// Local includes
#include "utils/reader/IReader.hpp"


namespace trcp
{

namespace reader
{

class CReaderFromJson : public IReader
{
    public:
    ~CReaderFromJson() override = default;

    void parse (const std::string &source, data::SRoad &output) override;
};

} // namespace reader

} // namespace trcp
