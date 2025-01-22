// SPDX - FileCopyrightText : Copyright 2025 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <map>

#include "usbd_device.h"

struct libusb_context;

namespace Libraries::Usbd {
class usbd_host {
public:
    usbd_host();
    ~usbd_host();

    int init();
    void exit();
    size_t get_devices(std::vector<std::shared_ptr<usbd_device>> devices);

protected:
private:
    libusb_context* m_context = nullptr;
    std::map<u64, std::shared_ptr<usbd_device>> m_devices;
    bool m_has_initialised = false;
};

extern usbd_host g_usbd_host;
} // namespace Libraries::Usbd