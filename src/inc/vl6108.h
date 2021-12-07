/*
 * ****************************************************************************
 * File           :       vl6108.h
 * Project        :       <<project>>
 *
 * Description    :
 * ****************************************************************************
 */



#ifndef _VL6108_H
#define _VL6108_H

#include "global.h"
#include "i2c.h"

#define VL6108_DEFUALT_ADDRESS 0x29

class tc_vl6108
{
    private:
        uint address;
        tc_i2c* i2c;
    public:
        struct reg
        {
            /*0x000*/uint8_t  id_model_id;
            /*0x001*/uint8_t  id_model_rev_maj;
            /*0x002*/uint8_t  id_model_rev_min;
            /*0x003*/uint8_t  id_module_rev_maj;
            /*0x004*/uint8_t  id_module_rev_min;
            /*0x006*/uint8_t  id_date_hi;
            /*0x007*/uint8_t  id_date_lo;
            /*0x008*/uint16_t id_time;
            /*0x010*/uint8_t  sys_mode_gpio0;
            /*0x011*/uint8_t  sys_mode_gpio1;
            /*0x012*/uint8_t  sys_history_ctrl;
            /*0x014*/uint8_t  sys_interrupt_config_gpio0;
            /*0x015*/uint8_t  sys_interrupt_clear;
            /*0x016*/uint8_t  sys_fresh_out_of_reset;
            /*0x017*/uint8_t  sys_grouped_parameter_hold;
            /*0x018*/uint8_t  sysrange_start;
            /*0x019*/uint8_t  sysrange_thresh_high;
            /*0x01A*/uint8_t  sysrange_thresh_low;
            /*0x01B*/uint8_t  sysrange_intermeasurement_period;
            /*0x01C*/uint8_t  sysrange_max_convergance_time;
            /*0x01E*/uint8_t  sysrange_crosstalk_compensation_rate;
            /*0x021*/uint8_t  sysrange_crosstalk_valid_height;
            /*0x022*/uint16_t sysrange_early_convergance_estimate;
            /*0x024*/uint8_t  sysrange_part_to_part_range_offset;
            /*0x025*/uint8_t  sysrange_range_ignore_valid_height;
            /*0x026*/uint16_t sysrange_range_ignore_thresh;
            /*0x02C*/uint8_t  sysrange_max_ambient_level_mult;
            /*0x02D*/uint8_t  sysrange_range_check_enables;
            /*0x02E*/uint8_t  sysrange_vhv_recalibrate;
            /*0x031*/uint8_t  sysrange_vhv_repeat_rate;
            /*0x038*/uint8_t  sysals_start;
            /*0x03A*/uint16_t sysals_thresh_high;
            /*0x03C*/uint16_t sysals_thresh_low;
            /*0x03E*/uint8_t  sysals_intermeasurement_period;
            /*0x03F*/uint8_t  sysals_analogue_gain;
            /*0x040*/uint8_t  sysals_integration_period;
            /*0x04D*/uint8_t  result_range_status;
            /*0x04E*/uint8_t  result_als_status;
            /*0x04F*/uint8_t  result_interrupt_status_gpio;
            /*0x050*/uint16_t result_als_val;
            /*0x052*/union    result_history
                     {
                        uint8_t range[16];
                        uint16_t als[8];
                     };
            /*0x062*/uint8_t  result_range_val;
            /*0x064*/uint8_t  result_range_raw;
            /*0x066*/uint16_t result_range_return_rate;
            /*0x068*/uint16_t result_reference_rate;
            /*0x06C*/uint32_t result_range_return_signal_count;
            /*0x070*/uint32_t result_range_reference_signal_count;
            /*0x074*/uint32_t result_range_return_amb_count;
            /*0x078*/uint32_t result_range_reference_amb_count;
            /*0x074*/uint32_t result_range_return_conv_time;
            /*0x080*/uint32_t result_range_reference_conv_time;
            /*0x10A*/uint8_t  readout_averaging_sample_period;
            /*0x119*/uint8_t  firmware_bootup;
            /*0x120*/uint8_t  firmware_result_scaler;
            /*0x212*/uint8_t  i2c_slave_device_address;
            /*0x2A3*/uint8_t  interleaved_mode_enable;
        }reg;
        //public class methods
        tc_vl6108();
        void set_address(uint _address);
        void set_i2c(tc_i2c* _i2c);
        uint get_model_id();
        uint get_model_rev();
        uint get_module_rev();

};

#endif
