#include "pipeline.hpp"

#include <fstream>

#include "file.hpp"

BEGIN_NAMESPACE(yhy)

Pipeline::Pipeline(std::string_view vert_filepath, std::string_view frag_filepath) {
    CreateGraphicsPipeline_(vert_filepath, frag_filepath);
}

void Pipeline::CreateGraphicsPipeline_(std::string_view vert_filepath, std::string_view frag_filepath) {
    auto vert_bytes = File::Read(vert_filepath);
    auto frag_bytes = File::Read(frag_filepath);
}

END_NAMESPACE
