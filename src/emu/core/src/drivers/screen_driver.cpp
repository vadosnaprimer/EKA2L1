#include <core/drivers/screen_driver.h>
#include <core/drivers/backend/ogl/screen_driver_ogl.h>

namespace eka2l1 {
    namespace driver {
        screen_driver_ptr new_screen_driver(driver_type dr_type) {
            switch (dr_type) {
                case driver_type::opengl: {
                    return std::make_shared<screen_driver_ogl>();
                }
            }

            return screen_driver_ptr(nullptr);
        }
    }
}