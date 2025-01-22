// SPDX - FileCopyrightText : Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "usbd_host.h"

#include <libusb.h>

namespace Libraries::Usbd {

usbd_host::usbd_host() {}

usbd_host::~usbd_host() = default;

int usbd_host::init() {
    if (!m_has_initialised) {
        int ret = libusb_init(&m_context);
        if (ret != LIBUSB_SUCCESS) {
            return ret;
        }
        m_has_initialised = true;
    };
    return 0;
}

void usbd_host::exit() {
    m_has_initialised = false;
}

size_t usbd_host::get_devices(std::vector<std::shared_ptr<usbd_device>> devices) {
    for (auto it = m_devices.begin(); it != m_devices.end(); it++) {
        devices.push_back(it->second);
    }
    return m_devices.size();
}

} // namespace Libraries::Usbd