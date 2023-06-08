#include "device.hpp"

#include "window.hpp"

BEGIN_NAMESPACE(yhy)

constexpr bool enableValidationLayers = DEBUG_MODE;

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                    VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                    const VkDebugUtilsMessengerCallbackDataEXT* callbackData, void* userData) {
    return VK_TRUE;
}

const std::array<const char*, 1> validationLayers{
    "VK_LAYER_KHRONOS_validation",
};

const std::array<const char*, 1> deviceExtensions{
    VK_KHR_SWAPCHAIN_EXTENSION_NAME,
};

Device::Device(Window* const window) : window_{ window } {}

Device::~Device() {}

uint32_t Device::FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
    return 0;
}

VkFormat Device::FindSupportFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features) {
    return VkFormat();
}

void Device::CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer,
                          VkDeviceMemory& bufferMemory) {}

VkCommandBuffer Device::BeginSingleTimeCommands() {
    return VkCommandBuffer();
}

void Device::EndSingleTimeCommands(VkCommandBuffer commandBuffer) {}

void Device::CopyBuffer(VkBuffer src, VkBuffer dst, VkDeviceSize size) {}

void Device::CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount) {}

void Device::CreateImageWithInfo(const VkImageCreateInfo& imageInfo, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory) {}

void Device::CreateInstance_() {}

void Device::SetupDebugMessenger_() {}

void Device::CreateSurface_() {}

void Device::PickPhysicalDevice_() {}

void Device::CreateLogicalDevice_() {}

void Device::CreateCommandPool_() {}

std::vector<const char*> Device::GetRequiredExtensions_() {
    return std::vector<const char*>();
}

bool Device::CheckValidationLayerSupport_() {
    return false;
}

QueueFamilyIndices Device::FindQueueFamilies_(VkPhysicalDevice device) {
    return QueueFamilyIndices();
}

void Device::PopulateDebugMessengerCreateInfo_(VkDebugUtilsMessengerCreateInfoEXT& createInfo) {}

void Device::HasGLFWRequiredInstanceExtensions_() {}

bool Device::CheckDeviceExtensionSupport_(VkPhysicalDevice device) {
    return false;
}

SwapChainSupportDetails Device::QuerySwapChainSupport_(VkPhysicalDevice device) {
    return SwapChainSupportDetails();
}

END_NAMESPACE