#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "interval.h"
#include <tuple>
#include <cmath>

using color = vec3;

// Gamma correction function (gamma = 2.0)
inline double linear_to_gamma(double linear_component) {
    return (linear_component > 0) ? std::sqrt(linear_component) : 0.0;
}

// Returns SDL-friendly clamped color tuple [0–255] with gamma correction
inline std::tuple<uint8_t, uint8_t, uint8_t> get_color_bytes(const color& pixel_color, int samples_per_pixel) {
    auto scale = 1.0 / samples_per_pixel;

    // Apply scale and gamma correction
    auto r = linear_to_gamma(pixel_color.x() * scale);
    auto g = linear_to_gamma(pixel_color.y() * scale);
    auto b = linear_to_gamma(pixel_color.z() * scale);

    // Clamp and convert to byte range [0, 255]
    static const interval intensity(0.0, 0.999);
    auto clamp = [](double x) {
        return static_cast<uint8_t>(256 * intensity.clamp(x));
        };

    return { clamp(r), clamp(g), clamp(b) };
}

#endif

