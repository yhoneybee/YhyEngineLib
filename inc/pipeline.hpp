#pragma once

#include <string>
#include <vector>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class Pipeline {
   public:
    Pipeline(std::wstring_view vert_filepath, std::wstring_view frag_filepath);

   private:
    void CreateGraphicsPipeline_(std::wstring_view vert_filepath, std::wstring_view frag_filepath);
};

END_NAMESPACE