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

#include <core/core_kernel.h>
#include <core/kernel/change_notifier.h>

#include <common/cvt.h>
#include <common/random.h>

namespace eka2l1 {
    namespace kernel {
        change_notifier::change_notifier(kernel_system *kern)
            : eka2l1::kernel::kernel_obj(kern, "changenotifier" + common::to_string(eka2l1::random()),
                  kernel::access_type::local_access) {
            obj_type = object_type::change_notifier;
        }

        bool change_notifier::logon(epoc::request_status *request_sts) {
            if (request_status) {
                return false;
            }

            requester = kern->crr_thread();
            request_status = request_sts;

            return true;
        }

        bool change_notifier::logon_cancel() {
            if (!request_status) {
                return false;
            }

            *request_status = -3;
            requester->signal_request();

            requester = nullptr;
            request_status = nullptr;

            return true;
        }

        void change_notifier::notify_change_requester() {
            *request_status = 0;
            requester->signal_request();

            requester = nullptr;
            request_status = nullptr;
        }
    }
}