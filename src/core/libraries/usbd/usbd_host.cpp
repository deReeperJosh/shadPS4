#include "usbd_host.h"

#include <libusb.h>

namespace Libraries::Usbd {

usbd_host::usbd_host() {
    init();
}

usbd_host::~usbd_host() {
    exit();
}

int usbd_host::init() {
    const int ret = libusb_init(&m_context);
    if (ret != LIBUSB_SUCCESS)
        return ret;

    return 0;
}

void usbd_host::exit() {
    libusb_exit(m_context);
}

} // namespace Libraries::Usbd
