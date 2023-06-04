#pragma once

#include <string>
#include <vector>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class Pipeline {
   public:
    Pipeline(std::string_view vert_filepath, std::string_view frag_filepath);

   private:
    void CreateGraphicsPipeline_(std::string_view vert_filepath, std::string_view frag_filepath);
};

END_NAMESPACE