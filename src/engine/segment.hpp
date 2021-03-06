#pragma once

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <map>
#include <memory>
#include <utility>
#include <mutex>
#include <optional>

#include "common/serialization.hpp"
#include "memtable.hpp"

namespace fs = std::filesystem;

// Segment
typedef std::map<std::string, int64_t> SegmentIndex;
class Segment;
typedef std::shared_ptr<Segment> SegmentPtr;

class Segment {
public:
    fs::path file_path;
    std::int64_t timestamp;  // timestamp, used for ordering
    std::int64_t keys_amount;
    std::int64_t indexed_keys_amount;
    int64_t index_start;
    
    Segment(fs::path d);

    static SegmentPtr dump_memtable(MemTable& mtbl, fs::path dir, int64_t timestamp, unsigned int index_step);

    std::optional<string_or_tomb> lookup(std::string key);

private:
    SegmentIndex index;

};