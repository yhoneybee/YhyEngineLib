#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <array>
#include <optional>
#include <vector>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class Window;

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {
    QueueFamilyIndices() : graphicsFamily{ std::nullopt }, presentFamily{ std::nullopt } {}
    QueueFamilyIndices(uint32_t graphicsFamily, uint32_t presentFamily) : graphicsFamily{ graphicsFamily }, presentFamily{ presentFamily } {}

    constexpr bool IsComplete() { return graphicsFamily && presentFamily; }

    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;
};

class Device {
   public:
    Device(Window* const window);
    ~Device();

    DENIED_COPY(Device)
    DENIED_MOVE(Device)

    VkCommandPool GetCommandPool() { return commandPool_; }
    VkDevice GetDevice() { return device_; }
    VkSurfaceKHR GetSurface() { return surface_; }
    VkQueue GetGraphicsQueue() { return graphicsQueue_; }
    VkQueue GetPresentQueue() { return presentQueue_; }
    SwapChainSupportDetails GetSwapChainSupport() { return QuerySwapChainSupport_(physicalDevice_); }

    uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    VkFormat FindSupportFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
    void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
    VkCommandBuffer BeginSingleTimeCommands();
    void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
    void CopyBuffer(VkBuffer src, VkBuffer dst, VkDeviceSize size);
    void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);
    void CreateImageWithInfo(const VkImageCreateInfo& imageInfo, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);

    VkPhysicalDeviceProperties properties;

   private:
    void CreateInstance_();
    void SetupDebugMessenger_();
    void CreateSurface_();
    void PickPhysicalDevice_();
    void CreateLogicalDevice_();
    void CreateCommandPool_();
    bool IsDeviceSuitable_(VkPhysicalDevice device);
    std::vector<const char*> GetRequiredExtensions_();
    bool CheckValidationLayerSupport_();
    QueueFamilyIndices FindQueueFamilies_(VkPhysicalDevice device);
    void PopulateDebugMessengerCreateInfo_(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void HasGLFWRequiredInstanceExtensions_();
    bool CheckDeviceExtensionSupport_(VkPhysicalDevice device);
    SwapChainSupportDetails QuerySwapChainSupport_(VkPhysicalDevice device);

    VkInstance instance_;
    VkDebugUtilsMessengerEXT debugMessenger_;
    VkPhysicalDevice physicalDevice_;
    VkCommandPool commandPool_;
    VkDevice device_;
    VkSurfaceKHR surface_;
    VkQueue graphicsQueue_;
    VkQueue presentQueue_;
    Window* window_;
};

END_NAMESPACE