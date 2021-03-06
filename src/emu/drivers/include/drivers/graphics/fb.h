/*
 * Copyright (c) 2018 EKA2L1 Team.
 * 
 * This file is part of EKA2L1 project 
 * (see bentokun.github.com/EKA2L1).
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <common/resource.h>
#include <common/vecx.h>

#include <memory>
#include <vector>

namespace eka2l1::drivers {
    class instance;
    using instance_ptr = std::shared_ptr<instance>;

    class framebuffer {
    protected:
        vec2 size;

    public:
        explicit framebuffer(const vec2 &size)
            : size(size) {}

        framebuffer() = default;
        virtual ~framebuffer(){};

        virtual void bind() = 0;
        virtual void unbind() = 0;

        virtual void resize(const vec2 &size) = 0;

        vec2 get_size() {
            return size;
        }

        virtual std::vector<std::uint8_t> data(std::size_t stride_pixels) = 0;
        virtual std::uint32_t texture_handle() = 0;
    };
}