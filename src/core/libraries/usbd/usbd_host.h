#pragma once

struct libusb_context;

namespace Libraries::Usbd {

class usbd_host {
public:
usbd_host();
~usbd_host();

int init();
void exit();
protected:
private:
libusb_context* m_context = nullptr;
};

} // namespace Libraries::Usbd
