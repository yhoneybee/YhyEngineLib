# information

> A game engine built using the VulkanSDK.

# setting

## vscode

### intellisense setting
* `.vscode/c_cpp_properties.json/configurations/includePath`
    * `"E:/Libraries/glm"`
    * `"E:/Libraries/glfw-<glfw Version>.bin.WIN64/include"`

### include setting
* `.vscode/tasks.json/tasks/args`
    * `"E:/Libraries/glm"`
    * `"E:/Libraries/glfw-<glfw Version>.bin.WIN64/include"`

### library setting
* `.vscode/tasks.json/tasks/args`
    * `"-l", "vulkan-1"`
    * `"-l", "glfw3"`
    * `"-L", "E:/VulkanSDK/<Vulkan Version>/Lib"`
    * `"-L", "E:/Libraries/glfw-<glfw Version>.bin.WIN64/lib-mingw-w64"`

## visual studio

### include setting
* `C/C++/General/Additional Include Directories`
    * `E:/Libraries/glm`
    * `E:/Libraries/glfw-<glfw Version>.bin.WIN64/include`

### library setting
* `Linker/General/Additional Library Directories`
    * `E:/VulkanSDK/<Vulkan Version>/Lib`
    * `E:/Libraries/glfw-<glfw Version>.bin.WIN64/lib-vc<Visual Studio Version>`
* `Linker/Input/Additional Dependencies`
    * `vulkan-1.lib`
    * `glfw3.lib`

# how to use