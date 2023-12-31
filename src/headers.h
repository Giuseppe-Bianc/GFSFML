#pragma once
#define GLFW_INCLUDE_VULKAN
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLM_FORCE_SILENT_WARNINGS
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_WIN32
#define GLM_FORCE_SIZE_T_LENGTH
#define GLM_FORCE_PURE
#define GLM_FORCE_INLINE
#define GLM_FORCE_EXPLICIT_CTOR
#define GLM_FORCE_CXX20
#define GLM_FORCE_UNRESTRICTED_GENTYPE
#define GLM_FORCE_PRECISION_HIGHP_DOUBLE
#define GLM_FORCE_PRECISION_HIGHP_INT
#define GLM_FORCE_PRECISION_HIGHP_FLOAT
#define VMA_IMPLEMENTATION
#ifdef _MSC_VER
// Microsoft Visual C++ Compiler
#pragma warning(push)
#pragma warning(disable : 6386 6385)
#endif

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <execution>
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numbers>
#include <omp.h>
#include <optional>
#include <random>
#include <ranges>
#include <set>
#include <spdlog/cfg/env.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string_view>
#include <unordered_set>
#include <vector>

#include "casts.h"
// Restore warning levels.
#ifdef _MSC_VER
// Microsoft Visual C++ Compiler
#pragma warning(pop)
#endif

#define LTRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define LDEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define LINFO(...) SPDLOG_INFO(__VA_ARGS__)
#define LWARN(...) SPDLOG_WARN(__VA_ARGS__)
#define LERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define LCRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)

#define SYSPAUSE()                                                                                                               \
    LINFO("Press enter to exit...");                                                                                             \
    std::cin.ignore();

static inline constexpr long double pi = std::numbers::pi_v<long double>;
static inline constexpr long double twoPi = 2 * pi;
static inline constexpr long double halfPi = pi / 2;
// Dimensioni della finestra
// static inline constexpr double aspect_ratio = 16.0 / 9.0;
static inline constexpr double aspect_ratioW = 16.0;
static inline constexpr double aspect_ratioH = 9.0;
static inline constexpr int imageF = 80;
static inline constexpr int w = C_I(aspect_ratioW * imageF);
static inline constexpr int h = C_I(aspect_ratioH * imageF);
static inline constexpr std::size_t ST_w = C_ST(w);
static inline constexpr std::size_t ST_h = C_ST(h);
static inline constexpr double scale = 256.0;
static inline constexpr double invStHMinusOne = 1.0 / C_D(ST_h - 1);
static inline constexpr double invStWMinusOne = 1.0 / C_D(ST_w - 1);
