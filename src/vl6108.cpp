/*
 * ****************************************************************************
 * File           :       VL6108.cpp
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */

#include "vl6108.h"


tc_vl6108::tc_vl6108()
{
    address = VL6108_DEFUALT_ADDRESS;
    i2c = NULL;
}

void tc_vl6108::set_address(uint _address)
{
    address = _address;
}

void tc_vl6108::set_i2c(tc_i2c* _i2c)
{
    if(_i2c != NULL)
    {
        i2c = _i2c;
    }

}


void tc_vl6108::get_id_info()
{
    i2c->read(address, 0x00, &reg.id_model_id, 9);

    id.model_id = reg.id_model_id;
    id.model_rev = ((float)(reg.id_model_rev_maj * 100) + reg.id_model_rev_min)/100;
    id.module_rev = ((float)(reg.id_module_rev_maj * 100) + reg.id_module_rev_min)/100;
}

void tc_vl6108::get_sys_info()
{
    i2c->read(address, 0x10, &reg.sys_mode_gpio0, 7);
}

void tc_vl6108::get_sysrange_info()
{
    i2c->read(address, 0x18, &reg.sysrange_start, 14);
}
