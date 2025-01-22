// SPDX - FileCopyrightText : Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

struct libusb_device;
struct libusb_device_descriptor;

namespace Libraries::Usbd {

class usbd_device {
public:
virtual ~usbd_device();
u16 get_vid();
u16 get_pid();
protected:
private:
u16 m_vid;
u16 m_pid;
};

class usbd_device_passthrough final : public usbd_device {
public:
usbd_device_passthrough(libusb_device* device, const libusb_device_descriptor& descriptor);
~usbd_device_passthrough();
protected:
private:
};

class usbd_device_emulated : public usbd_device {
public:
usbd_device_emulated();
~usbd_device_emulated();
protected:
private:
};

} // namespace Libraries::Usbd