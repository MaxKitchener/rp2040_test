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

uint tc_vl6108::get_model_id()
{
    i2c->read(address, &reg.id_model_id, 1);
    return(reg.id_model_id);
}

uint tc_vl6108::get_model_rev()
{
    i2c->read(address, &reg.id_model_rev_maj, 2);
    return((reg.id_model_rev_maj << 8) + reg.id_model_rev_min);
}

uint tc_vl6108::get_module_rev()
{
    i2c->read(address, &reg.id_module_rev_maj, 2);
    return((reg.id_module_rev_maj << 8) + reg.id_module_rev_min);
}
