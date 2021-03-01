#pragma once

#include <cstdint>

#include "bglib_types.hpp"

namespace bglib {

class ble
{
public:
    virtual ~ble() {}
    static const ble_msg  apis[];

    /*****************************************************************************
     *
     *
     *      Command Functions
     *
     *
     ****************************************************************************/

    /**Reset device**/
    inline void cmd_system_reset(uint8_t boot_in_dfu) { this->send_message (bglib::ble_cmd_system_reset_idx,boot_in_dfu); }
    /**Hello - command for testing**/
    inline void cmd_system_hello() { this->send_message (bglib::ble_cmd_system_hello_idx); }
    /**Get device bluetooth address**/
    inline void cmd_system_address_get() { this->send_message (bglib::ble_cmd_system_address_get_idx); }
    /**write register**/
    inline void cmd_system_reg_write(uint16_t address,uint8_t value) { this->send_message (bglib::ble_cmd_system_reg_write_idx,address,value); }
    /**read register**/
    inline void cmd_system_reg_read(uint16_t address) { this->send_message (bglib::ble_cmd_system_reg_read_idx,address); }
    /**get and reset packet counters**/
    inline void cmd_system_get_counters() { this->send_message (bglib::ble_cmd_system_get_counters_idx); }
    /**Get status from all connections**/
    inline void cmd_system_get_connections() { this->send_message (bglib::ble_cmd_system_get_connections_idx); }
    /**Read Memory**/
    inline void cmd_system_read_memory(uint32_t address,uint8_t length) { this->send_message (bglib::ble_cmd_system_read_memory_idx,address,length); }
    /**Get Device info**/
    inline void cmd_system_get_info() { this->send_message (bglib::ble_cmd_system_get_info_idx); }
    /**Send data to endpoint, error is returned if endpoint does not have enough space**/
    inline void cmd_system_endpoint_tx(uint8_t endpoint,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_system_endpoint_tx_idx,endpoint,data_len,data_data); }
    /**Add entry to whitelist**/
    inline void cmd_system_whitelist_append(hwaddr address,uint8_t address_type) { this->send_message (bglib::ble_cmd_system_whitelist_append_idx,address,address_type); }
    /**Remove entry from whitelist**/
    inline void cmd_system_whitelist_remove(hwaddr address,uint8_t address_type) { this->send_message (bglib::ble_cmd_system_whitelist_remove_idx,address,address_type); }
    /**Add entry to whitelist**/
    inline void cmd_system_whitelist_clear() { this->send_message (bglib::ble_cmd_system_whitelist_clear_idx); }
    /**Read data from endpoint, error is returned if endpoint does not have enough data.**/
    inline void cmd_system_endpoint_rx(uint8_t endpoint,uint8_t size) { this->send_message (bglib::ble_cmd_system_endpoint_rx_idx,endpoint,size); }
    /**Set watermarks on both input and output side**/
    inline void cmd_system_endpoint_set_watermarks(uint8_t endpoint,uint8_t rx,uint8_t tx) { this->send_message (bglib::ble_cmd_system_endpoint_set_watermarks_idx,endpoint,rx,tx); }
    /**Set encryption key that will be used with aes_encrypt and aes_decrypt commands.**/
    inline void cmd_system_aes_setkey(uint16_t key_len,uint8_t* key_data) { this->send_message (bglib::ble_cmd_system_aes_setkey_idx,key_len,key_data); }
    /**Encrypt one block of data**/
    inline void cmd_system_aes_encrypt(uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_system_aes_encrypt_idx,data_len,data_data); }
    /**Decrypt one block of data**/
    inline void cmd_system_aes_decrypt(uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_system_aes_decrypt_idx,data_len,data_data); }
    /**Defragment persistent store**/
    inline void cmd_flash_ps_defrag() { this->send_message (bglib::ble_cmd_flash_ps_defrag_idx); }
    /**Dump all ps keys**/
    inline void cmd_flash_ps_dump() { this->send_message (bglib::ble_cmd_flash_ps_dump_idx); }
    /**erase all ps keys**/
    inline void cmd_flash_ps_erase_all() { this->send_message (bglib::ble_cmd_flash_ps_erase_all_idx); }
    /**save ps key**/
    inline void cmd_flash_ps_save(uint16_t key,uint16_t value_len,uint8_t* value_data) { this->send_message (bglib::ble_cmd_flash_ps_save_idx,key,value_len,value_data); }
    /**load ps key**/
    inline void cmd_flash_ps_load(uint16_t key) { this->send_message (bglib::ble_cmd_flash_ps_load_idx,key); }
    /**erase ps key**/
    inline void cmd_flash_ps_erase(uint16_t key) { this->send_message (bglib::ble_cmd_flash_ps_erase_idx,key); }
    /**erase flash page**/
    inline void cmd_flash_erase_page(uint8_t page) { this->send_message (bglib::ble_cmd_flash_erase_page_idx,page); }
    /**write data to user data area**/
    inline void cmd_flash_write_data(uint32_t address,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_flash_write_data_idx,address,data_len,data_data); }
    /**read data from user data area.**/
    inline void cmd_flash_read_data(uint32_t address,uint8_t length) { this->send_message (bglib::ble_cmd_flash_read_data_idx,address,length); }
    /**Write to attribute database**/
    inline void cmd_attributes_write(uint16_t handle,uint8_t offset,uint16_t value_len,uint8_t* value_data) { this->send_message (bglib::ble_cmd_attributes_write_idx,handle,offset,value_len,value_data); }
    /**Read from attribute database**/
    inline void cmd_attributes_read(uint16_t handle,uint16_t offset) { this->send_message (bglib::ble_cmd_attributes_read_idx,handle,offset); }
    /**Read attribute type from database**/
    inline void cmd_attributes_read_type(uint16_t handle) { this->send_message (bglib::ble_cmd_attributes_read_type_idx,handle); }
    /**Respond to user attribute read request**/
    inline void cmd_attributes_user_read_response(uint8_t connection,uint8_t att_error,uint16_t value_len,uint8_t* value_data) { this->send_message (bglib::ble_cmd_attributes_user_read_response_idx,connection,att_error,value_len,value_data); }
    /**Response to attribute_changed event where reason is user-attribute write.**/
    inline void cmd_attributes_user_write_response(uint8_t connection,uint8_t att_error) { this->send_message (bglib::ble_cmd_attributes_user_write_response_idx,connection,att_error); }
    /**Send notification or indication to remote device.**/
    inline void cmd_attributes_send(uint8_t connection,uint16_t handle,uint16_t value_len,uint8_t* value_data) { this->send_message (bglib::ble_cmd_attributes_send_idx,connection,handle,value_len,value_data); }
    /**Disconnect connection, starts a disconnection procedure on connection**/
    inline void cmd_connection_disconnect(uint8_t connection) { this->send_message (bglib::ble_cmd_connection_disconnect_idx,connection); }
    /**Get Link RSSI**/
    inline void cmd_connection_get_rssi(uint8_t connection) { this->send_message (bglib::ble_cmd_connection_get_rssi_idx,connection); }
    /**Update connection parameters**/
    inline void cmd_connection_update(uint8_t connection,uint16_t interval_min,uint16_t interval_max,uint16_t latency,uint16_t timeout) { this->send_message (bglib::ble_cmd_connection_update_idx,connection,interval_min,interval_max,latency,timeout); }
    /**Request version exchange**/
    inline void cmd_connection_version_update(uint8_t connection) { this->send_message (bglib::ble_cmd_connection_version_update_idx,connection); }
    /**Get Current channel map**/
    inline void cmd_connection_channel_map_get(uint8_t connection) { this->send_message (bglib::ble_cmd_connection_channel_map_get_idx,connection); }
    /**Set Channel map**/
    inline void cmd_connection_channel_map_set(uint8_t connection,uint16_t map_len,uint8_t* map_data) { this->send_message (bglib::ble_cmd_connection_channel_map_set_idx,connection,map_len,map_data); }
    /**Remote feature request**/
    inline void cmd_connection_features_get(uint8_t connection) { this->send_message (bglib::ble_cmd_connection_features_get_idx,connection); }
    /**Get Connection Status Parameters**/
    inline void cmd_connection_get_status(uint8_t connection) { this->send_message (bglib::ble_cmd_connection_get_status_idx,connection); }
    /**Raw TX**/
    inline void cmd_connection_raw_tx(uint8_t connection,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_connection_raw_tx_idx,connection,data_len,data_data); }
    /**Disable or enable slave latency**/
    inline void cmd_connection_slave_latency_disable(uint8_t disable) { this->send_message (bglib::ble_cmd_connection_slave_latency_disable_idx,disable); }
    /**Discover attributes by type and value**/
    inline void cmd_attclient_find_by_type_value(uint8_t connection,uint16_t start,uint16_t end,uint16_t uuid,uint16_t value_len,uint8_t* value_data) { this->send_message (bglib::ble_cmd_attclient_find_by_type_value_idx,connection,start,end,uuid,value_len,value_data); }
    /**Discover attributes by type and value**/
    inline void cmd_attclient_read_by_group_type(uint8_t connection,uint16_t start,uint16_t end,uint16_t uuid_len,uint8_t* uuid_data) { this->send_message (bglib::ble_cmd_attclient_read_by_group_type_idx,connection,start,end,uuid_len,uuid_data); }
    /**Read all attributes where type matches**/
    inline void cmd_attclient_read_by_type(uint8_t connection,uint16_t start,uint16_t end,uint16_t uuid_len,uint8_t* uuid_data) { this->send_message (bglib::ble_cmd_attclient_read_by_type_idx,connection,start,end,uuid_len,uuid_data); }
    /**Discover Attribute handle and type mappings**/
    inline void cmd_attclient_find_information(uint8_t connection,uint16_t start,uint16_t end) { this->send_message (bglib::ble_cmd_attclient_find_information_idx,connection,start,end); }
    /**Read Characteristic value using handle**/
    inline void cmd_attclient_read_by_handle(uint8_t connection,uint16_t chrhandle) { this->send_message (bglib::ble_cmd_attclient_read_by_handle_idx,connection,chrhandle); }
    /**write data to attribute**/
    inline void cmd_attclient_attribute_write(uint8_t connection,uint16_t atthandle,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_attclient_attribute_write_idx,connection,atthandle,data_len,data_data); }
    /**write data to attribute using ATT write command**/
    inline void cmd_attclient_write_command(uint8_t connection,uint16_t atthandle,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_attclient_write_command_idx,connection,atthandle,data_len,data_data); }
    /**Send confirmation for received indication, use only if manual indications are enabled**/
    inline void cmd_attclient_indicate_confirm(uint8_t connection) { this->send_message (bglib::ble_cmd_attclient_indicate_confirm_idx,connection); }
    /**Read Long Characteristic value**/
    inline void cmd_attclient_read_long(uint8_t connection,uint16_t chrhandle) { this->send_message (bglib::ble_cmd_attclient_read_long_idx,connection,chrhandle); }
    /**Send prepare write request to remote host**/
    inline void cmd_attclient_prepare_write(uint8_t connection,uint16_t atthandle,uint16_t offset,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_attclient_prepare_write_idx,connection,atthandle,offset,data_len,data_data); }
    /**Send prepare write request to remote host**/
    inline void cmd_attclient_execute_write(uint8_t connection,uint8_t commit) { this->send_message (bglib::ble_cmd_attclient_execute_write_idx,connection,commit); }
    /**Read multiple attributes from server**/
    inline void cmd_attclient_read_multiple(uint8_t connection,uint16_t handles_len,uint8_t* handles_data) { this->send_message (bglib::ble_cmd_attclient_read_multiple_idx,connection,handles_len,handles_data); }
    /**Enable encryption on link**/
    inline void cmd_sm_encrypt_start(uint8_t handle,uint8_t bonding) { this->send_message (bglib::ble_cmd_sm_encrypt_start_idx,handle,bonding); }
    /**Set device to bondable mode**/
    inline void cmd_sm_set_bondable_mode(uint8_t bondable) { this->send_message (bglib::ble_cmd_sm_set_bondable_mode_idx,bondable); }
    /**delete bonding information from ps store**/
    inline void cmd_sm_delete_bonding(uint8_t handle) { this->send_message (bglib::ble_cmd_sm_delete_bonding_idx,handle); }
    /**set pairing requirements**/
    inline void cmd_sm_set_parameters(uint8_t mitm,uint8_t min_key_size,uint8_t io_capabilities) { this->send_message (bglib::ble_cmd_sm_set_parameters_idx,mitm,min_key_size,io_capabilities); }
    /**Passkey entered**/
    inline void cmd_sm_passkey_entry(uint8_t handle,uint32_t passkey) { this->send_message (bglib::ble_cmd_sm_passkey_entry_idx,handle,passkey); }
    /**List all bonded devices**/
    inline void cmd_sm_get_bonds() { this->send_message (bglib::ble_cmd_sm_get_bonds_idx); }
    /**
    		    Set out-of-band encryption data for device
    		    Device does not allow any other kind of pairing except oob if oob data is set.
    		    **/
    inline void cmd_sm_set_oob_data(uint16_t oob_len,uint8_t* oob_data) { this->send_message (bglib::ble_cmd_sm_set_oob_data_idx,oob_len,oob_data); }
    /**
    				Add all bonded devices with a known public or static address to
    				the whitelist. Previous entries in the whitelist are first
    				cleared. This command can't be used while advertising, scanning
    				or being connected.
    			**/
    inline void cmd_sm_whitelist_bonds() { this->send_message (bglib::ble_cmd_sm_whitelist_bonds_idx); }
    /**
    				Change keys distribution fields in pairing request and response. By default all keys are distributed.
    			**/
    inline void cmd_sm_set_pairing_distribution_keys(uint8_t initiator_keys,uint8_t responder_keys) { this->send_message (bglib::ble_cmd_sm_set_pairing_distribution_keys_idx,initiator_keys,responder_keys); }
    /**Set GAP central/peripheral privacy flags	
    			**/
    inline void cmd_gap_set_privacy_flags(uint8_t peripheral_privacy,uint8_t central_privacy) { this->send_message (bglib::ble_cmd_gap_set_privacy_flags_idx,peripheral_privacy,central_privacy); }
    /**Set discoverable and connectable mode**/
    inline void cmd_gap_set_mode(uint8_t discover,uint8_t connect) { this->send_message (bglib::ble_cmd_gap_set_mode_idx,discover,connect); }
    /**start or stop discover procedure**/
    inline void cmd_gap_discover(uint8_t mode) { this->send_message (bglib::ble_cmd_gap_discover_idx,mode); }
    /**Direct connection**/
    inline void cmd_gap_connect_direct(hwaddr address,uint8_t addr_type,uint16_t conn_interval_min,uint16_t conn_interval_max,uint16_t timeout,uint16_t latency) { this->send_message (bglib::ble_cmd_gap_connect_direct_idx,address,addr_type,conn_interval_min,conn_interval_max,timeout,latency); }
    /**End current GAP procedure**/
    inline void cmd_gap_end_procedure() { this->send_message (bglib::ble_cmd_gap_end_procedure_idx); }
    /**Connect to any device on whitelist**/
    inline void cmd_gap_connect_selective(uint16_t conn_interval_min,uint16_t conn_interval_max,uint16_t timeout,uint16_t latency) { this->send_message (bglib::ble_cmd_gap_connect_selective_idx,conn_interval_min,conn_interval_max,timeout,latency); }
    /**Set scan and advertising filtering parameters**/
    inline void cmd_gap_set_filtering(uint8_t scan_policy,uint8_t adv_policy,uint8_t scan_duplicate_filtering) { this->send_message (bglib::ble_cmd_gap_set_filtering_idx,scan_policy,adv_policy,scan_duplicate_filtering); }
    /**Set scan parameters**/
    inline void cmd_gap_set_scan_parameters(uint16_t scan_interval,uint16_t scan_window,uint8_t active) { this->send_message (bglib::ble_cmd_gap_set_scan_parameters_idx,scan_interval,scan_window,active); }
    /**Set advertising parameters**/
    inline void cmd_gap_set_adv_parameters(uint16_t adv_interval_min,uint16_t adv_interval_max,uint8_t adv_channels) { this->send_message (bglib::ble_cmd_gap_set_adv_parameters_idx,adv_interval_min,adv_interval_max,adv_channels); }
    /**Set advertisement or scan response data. Use broadcast mode to advertise data**/
    inline void cmd_gap_set_adv_data(uint8_t set_scanrsp,uint16_t adv_data_len,uint8_t* adv_data_data) { this->send_message (bglib::ble_cmd_gap_set_adv_data_idx,set_scanrsp,adv_data_len,adv_data_data); }
    /**Sets device to Directed Connectable Mode
                            Uses fast advertisement procedure for 1.28s after which device enters nonconnectable mode. 
                            If device has valid reconnection characteristic value, it is used for connection
                            otherwise passed address and address type are used                        
                **/
    inline void cmd_gap_set_directed_connectable_mode(hwaddr address,uint8_t addr_type) { this->send_message (bglib::ble_cmd_gap_set_directed_connectable_mode_idx,address,addr_type); }
    /**Set Initiating connection scan parameters**/
    inline void cmd_gap_set_initiating_con_parameters(uint16_t scan_interval,uint16_t scan_window) { this->send_message (bglib::ble_cmd_gap_set_initiating_con_parameters_idx,scan_interval,scan_window); }
    /**Set non-resolvable address**/
    inline void cmd_gap_set_nonresolvable_address(hwaddr address) { this->send_message (bglib::ble_cmd_gap_set_nonresolvable_address_idx,address); }
    /**Configure I/O-port interrupts**/
    inline void cmd_hardware_io_port_config_irq(uint8_t port,uint8_t enable_bits,uint8_t falling_edge) { this->send_message (bglib::ble_cmd_hardware_io_port_config_irq_idx,port,enable_bits,falling_edge); }
    /**Set soft timer to send events**/
    inline void cmd_hardware_set_soft_timer(uint32_t time,uint8_t handle,uint8_t single_shot) { this->send_message (bglib::ble_cmd_hardware_set_soft_timer_idx,time,handle,single_shot); }
    /**Read A/D conversion**/
    inline void cmd_hardware_adc_read(uint8_t input,uint8_t decimation,uint8_t reference_selection) { this->send_message (bglib::ble_cmd_hardware_adc_read_idx,input,decimation,reference_selection); }
    /**Configure I/O-port direction**/
    inline void cmd_hardware_io_port_config_direction(uint8_t port,uint8_t direction) { this->send_message (bglib::ble_cmd_hardware_io_port_config_direction_idx,port,direction); }
    /**Configure I/O-port function**/
    inline void cmd_hardware_io_port_config_function(uint8_t port,uint8_t function) { this->send_message (bglib::ble_cmd_hardware_io_port_config_function_idx,port,function); }
    /**Configure I/O-port pull-up/pull-down**/
    inline void cmd_hardware_io_port_config_pull(uint8_t port,uint8_t tristate_mask,uint8_t pull_up) { this->send_message (bglib::ble_cmd_hardware_io_port_config_pull_idx,port,tristate_mask,pull_up); }
    /**Write I/O-port**/
    inline void cmd_hardware_io_port_write(uint8_t port,uint8_t mask,uint8_t data) { this->send_message (bglib::ble_cmd_hardware_io_port_write_idx,port,mask,data); }
    /**Read I/O-port**/
    inline void cmd_hardware_io_port_read(uint8_t port,uint8_t mask) { this->send_message (bglib::ble_cmd_hardware_io_port_read_idx,port,mask); }
    /**Configure SPI**/
    inline void cmd_hardware_spi_config(uint8_t channel,uint8_t polarity,uint8_t phase,uint8_t bit_order,uint8_t baud_e,uint8_t baud_m) { this->send_message (bglib::ble_cmd_hardware_spi_config_idx,channel,polarity,phase,bit_order,baud_e,baud_m); }
    /**Transfer SPI data**/
    inline void cmd_hardware_spi_transfer(uint8_t channel,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_hardware_spi_transfer_idx,channel,data_len,data_data); }
    /**Read data from I2C bus using bit-bang in cc2540. I2C clk is in P1.7 data in P1.6. Pull-up must be enabled on pins**/
    inline void cmd_hardware_i2c_read(uint8_t address,uint8_t stop,uint8_t length) { this->send_message (bglib::ble_cmd_hardware_i2c_read_idx,address,stop,length); }
    /**Write data to I2C bus using bit-bang in cc2540. I2C clk is in P1.7 data in P1.6. Pull-up must be enabled on pins**/
    inline void cmd_hardware_i2c_write(uint8_t address,uint8_t stop,uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_hardware_i2c_write_idx,address,stop,data_len,data_data); }
    /**Set TX Power**/
    inline void cmd_hardware_set_txpower(uint8_t power) { this->send_message (bglib::ble_cmd_hardware_set_txpower_idx,power); }
    /**Set comparator for timer channel**/
    inline void cmd_hardware_timer_comparator(uint8_t timer,uint8_t channel,uint8_t mode,uint16_t comparator_value) { this->send_message (bglib::ble_cmd_hardware_timer_comparator_idx,timer,channel,mode,comparator_value); }
    /**Enable I/O-port interrupts**/
    inline void cmd_hardware_io_port_irq_enable(uint8_t port,uint8_t enable_bits) { this->send_message (bglib::ble_cmd_hardware_io_port_irq_enable_idx,port,enable_bits); }
    /**Set I/O-port interrupt direction**/
    inline void cmd_hardware_io_port_irq_direction(uint8_t port,uint8_t falling_edge) { this->send_message (bglib::ble_cmd_hardware_io_port_irq_direction_idx,port,falling_edge); }
    /**Enable or disable analog comparator**/
    inline void cmd_hardware_analog_comparator_enable(uint8_t enable) { this->send_message (bglib::ble_cmd_hardware_analog_comparator_enable_idx,enable); }
    /**Read analog comparator output**/
    inline void cmd_hardware_analog_comparator_read() { this->send_message (bglib::ble_cmd_hardware_analog_comparator_read_idx); }
    /**Configure analog comparator interrupt**/
    inline void cmd_hardware_analog_comparator_config_irq(uint8_t enabled) { this->send_message (bglib::ble_cmd_hardware_analog_comparator_config_irq_idx,enabled); }
    /**Set RX Sensitivity**/
    inline void cmd_hardware_set_rxgain(uint8_t gain) { this->send_message (bglib::ble_cmd_hardware_set_rxgain_idx,gain); }
    /**Enable or disable USB**/
    inline void cmd_hardware_usb_enable(uint8_t enable) { this->send_message (bglib::ble_cmd_hardware_usb_enable_idx,enable); }
    /**Enable or disable sleep mode**/
    inline void cmd_hardware_sleep_enable(uint8_t enable) { this->send_message (bglib::ble_cmd_hardware_sleep_enable_idx,enable); }
    /**Start packet transmission, send one packet at every 625us**/
    inline void cmd_test_phy_tx(uint8_t channel,uint8_t length,uint8_t type) { this->send_message (bglib::ble_cmd_test_phy_tx_idx,channel,length,type); }
    /**Start receive test**/
    inline void cmd_test_phy_rx(uint8_t channel) { this->send_message (bglib::ble_cmd_test_phy_rx_idx,channel); }
    /**End test, and report received packets**/
    inline void cmd_test_phy_end() { this->send_message (bglib::ble_cmd_test_phy_end_idx); }
    /**Reset test**/
    inline void cmd_test_phy_reset() { this->send_message (bglib::ble_cmd_test_phy_reset_idx); }
    /**Get current channel quality map**/
    inline void cmd_test_get_channel_map() { this->send_message (bglib::ble_cmd_test_get_channel_map_idx); }
    /**Debug command**/
    inline void cmd_test_debug(uint8_t opcode,uint16_t input_len,uint8_t* input_data) { this->send_message (bglib::ble_cmd_test_debug_idx,opcode,input_len,input_data); }
    /**Set channel quality measurement mode**/
    inline void cmd_test_channel_mode(uint8_t mode) { this->send_message (bglib::ble_cmd_test_channel_mode_idx,mode); }
    /**Reset system**/
    inline void cmd_dfu_reset(uint8_t dfu) { this->send_message (bglib::ble_cmd_dfu_reset_idx,dfu); }
    /**set address for flashing**/
    inline void cmd_dfu_flash_set_address(uint32_t address) { this->send_message (bglib::ble_cmd_dfu_flash_set_address_idx,address); }
    /**Upload binary for flashing. Address will be updated automatically.**/
    inline void cmd_dfu_flash_upload(uint16_t data_len,uint8_t* data_data) { this->send_message (bglib::ble_cmd_dfu_flash_upload_idx,data_len,data_data); }
    /**Uploading is finished.**/
    inline void cmd_dfu_flash_upload_finish() { this->send_message (bglib::ble_cmd_dfu_flash_upload_finish_idx); }


protected:

    const ble_msg * get_msg(uint8_t idx);
    const ble_msg * find_msg_hdr(ble_header hdr);
    const ble_msg * find_msg_hdr_r(ble_header hdr);
    const ble_msg * get_msg_hdr(ble_header hdr);
    void send_message(uint8_t msgid,...);

    /*****************************************************************************
     *
     *
     *      Implementatoin Functions: Override These
     *
     *
     ****************************************************************************/

    /**Serial data to send to the device**/
    virtual void output(uint8_t len1,uint8_t* data1,uint16_t len2,uint8_t* data2) {}

    /**Reset device**/
    virtual void rsp_system_reset(const void *nul) {}
    
    /**Hello - command for testing**/
    virtual void rsp_system_hello(const void *nul) {}
    
    /**Get device bluetooth address**/
    virtual void rsp_system_address_get(const ble_msg_system_address_get_rsp_t *msg) {}
    
    /**write register**/
    virtual void rsp_system_reg_write(const ble_msg_system_reg_write_rsp_t *msg) {}
    
    /**read register**/
    virtual void rsp_system_reg_read(const ble_msg_system_reg_read_rsp_t *msg) {}
    
    /**get and reset packet counters**/
    virtual void rsp_system_get_counters(const ble_msg_system_get_counters_rsp_t *msg) {}
    
    /**Get status from all connections**/
    virtual void rsp_system_get_connections(const ble_msg_system_get_connections_rsp_t *msg) {}
    
    /**Read Memory**/
    virtual void rsp_system_read_memory(const ble_msg_system_read_memory_rsp_t *msg) {}
    
    /**Get Device info**/
    virtual void rsp_system_get_info(const ble_msg_system_get_info_rsp_t *msg) {}
    
    /**Send data to endpoint, error is returned if endpoint does not have enough space**/
    virtual void rsp_system_endpoint_tx(const ble_msg_system_endpoint_tx_rsp_t *msg) {}
    
    /**Add entry to whitelist**/
    virtual void rsp_system_whitelist_append(const ble_msg_system_whitelist_append_rsp_t *msg) {}
    
    /**Remove entry from whitelist**/
    virtual void rsp_system_whitelist_remove(const ble_msg_system_whitelist_remove_rsp_t *msg) {}
    
    /**Add entry to whitelist**/
    virtual void rsp_system_whitelist_clear(const void *nul) {}
    
    /**Read data from endpoint, error is returned if endpoint does not have enough data.**/
    virtual void rsp_system_endpoint_rx(const ble_msg_system_endpoint_rx_rsp_t *msg) {}
    
    /**Set watermarks on both input and output side**/
    virtual void rsp_system_endpoint_set_watermarks(const ble_msg_system_endpoint_set_watermarks_rsp_t *msg) {}
    
    /**Set encryption key that will be used with aes_encrypt and aes_decrypt commands.**/
    virtual void rsp_system_aes_setkey(const void *nul) {}
    
    /**Encrypt one block of data**/
    virtual void rsp_system_aes_encrypt(const ble_msg_system_aes_encrypt_rsp_t *msg) {}
    
    /**Decrypt one block of data**/
    virtual void rsp_system_aes_decrypt(const ble_msg_system_aes_decrypt_rsp_t *msg) {}
    
    /**Defragment persistent store**/
    virtual void rsp_flash_ps_defrag(const void *nul) {}
    
    /**Dump all ps keys**/
    virtual void rsp_flash_ps_dump(const void *nul) {}
    
    /**erase all ps keys**/
    virtual void rsp_flash_ps_erase_all(const void *nul) {}
    
    /**save ps key**/
    virtual void rsp_flash_ps_save(const ble_msg_flash_ps_save_rsp_t *msg) {}
    
    /**load ps key**/
    virtual void rsp_flash_ps_load(const ble_msg_flash_ps_load_rsp_t *msg) {}
    
    /**erase ps key**/
    virtual void rsp_flash_ps_erase(const void *nul) {}
    
    /**erase flash page**/
    virtual void rsp_flash_erase_page(const ble_msg_flash_erase_page_rsp_t *msg) {}
    
    /**write data to user data area**/
    virtual void rsp_flash_write_data(const ble_msg_flash_write_data_rsp_t *msg) {}
    
    /**read data from user data area.**/
    virtual void rsp_flash_read_data(const ble_msg_flash_read_data_rsp_t *msg) {}
    
    /**Write to attribute database**/
    virtual void rsp_attributes_write(const ble_msg_attributes_write_rsp_t *msg) {}
    
    /**Read from attribute database**/
    virtual void rsp_attributes_read(const ble_msg_attributes_read_rsp_t *msg) {}
    
    /**Read attribute type from database**/
    virtual void rsp_attributes_read_type(const ble_msg_attributes_read_type_rsp_t *msg) {}
    
    /**Respond to user attribute read request**/
    virtual void rsp_attributes_user_read_response(const void *nul) {}
    
    /**Response to attribute_changed event where reason is user-attribute write.**/
    virtual void rsp_attributes_user_write_response(const void *nul) {}
    
    /**Send notification or indication to remote device.**/
    virtual void rsp_attributes_send(const ble_msg_attributes_send_rsp_t *msg) {}
    
    /**Disconnect connection, starts a disconnection procedure on connection**/
    virtual void rsp_connection_disconnect(const ble_msg_connection_disconnect_rsp_t *msg) {}
    
    /**Get Link RSSI**/
    virtual void rsp_connection_get_rssi(const ble_msg_connection_get_rssi_rsp_t *msg) {}
    
    /**Update connection parameters**/
    virtual void rsp_connection_update(const ble_msg_connection_update_rsp_t *msg) {}
    
    /**Request version exchange**/
    virtual void rsp_connection_version_update(const ble_msg_connection_version_update_rsp_t *msg) {}
    
    /**Get Current channel map**/
    virtual void rsp_connection_channel_map_get(const ble_msg_connection_channel_map_get_rsp_t *msg) {}
    
    /**Set Channel map**/
    virtual void rsp_connection_channel_map_set(const ble_msg_connection_channel_map_set_rsp_t *msg) {}
    
    /**Remote feature request**/
    virtual void rsp_connection_features_get(const ble_msg_connection_features_get_rsp_t *msg) {}
    
    /**Get Connection Status Parameters**/
    virtual void rsp_connection_get_status(const ble_msg_connection_get_status_rsp_t *msg) {}
    
    /**Raw TX**/
    virtual void rsp_connection_raw_tx(const ble_msg_connection_raw_tx_rsp_t *msg) {}
    
    /**Disable or enable slave latency**/
    virtual void rsp_connection_slave_latency_disable(const ble_msg_connection_slave_latency_disable_rsp_t *msg) {}
    
    /**Discover attributes by type and value**/
    virtual void rsp_attclient_find_by_type_value(const ble_msg_attclient_find_by_type_value_rsp_t *msg) {}
    
    /**Discover attributes by type and value**/
    virtual void rsp_attclient_read_by_group_type(const ble_msg_attclient_read_by_group_type_rsp_t *msg) {}
    
    /**Read all attributes where type matches**/
    virtual void rsp_attclient_read_by_type(const ble_msg_attclient_read_by_type_rsp_t *msg) {}
    
    /**Discover Attribute handle and type mappings**/
    virtual void rsp_attclient_find_information(const ble_msg_attclient_find_information_rsp_t *msg) {}
    
    /**Read Characteristic value using handle**/
    virtual void rsp_attclient_read_by_handle(const ble_msg_attclient_read_by_handle_rsp_t *msg) {}
    
    /**write data to attribute**/
    virtual void rsp_attclient_attribute_write(const ble_msg_attclient_attribute_write_rsp_t *msg) {}
    
    /**write data to attribute using ATT write command**/
    virtual void rsp_attclient_write_command(const ble_msg_attclient_write_command_rsp_t *msg) {}
    
    /**Send confirmation for received indication, use only if manual indications are enabled**/
    virtual void rsp_attclient_indicate_confirm(const ble_msg_attclient_indicate_confirm_rsp_t *msg) {}
    
    /**Read Long Characteristic value**/
    virtual void rsp_attclient_read_long(const ble_msg_attclient_read_long_rsp_t *msg) {}
    
    /**Send prepare write request to remote host**/
    virtual void rsp_attclient_prepare_write(const ble_msg_attclient_prepare_write_rsp_t *msg) {}
    
    /**Send prepare write request to remote host**/
    virtual void rsp_attclient_execute_write(const ble_msg_attclient_execute_write_rsp_t *msg) {}
    
    /**Read multiple attributes from server**/
    virtual void rsp_attclient_read_multiple(const ble_msg_attclient_read_multiple_rsp_t *msg) {}
    
    /**Enable encryption on link**/
    virtual void rsp_sm_encrypt_start(const ble_msg_sm_encrypt_start_rsp_t *msg) {}
    
    /**Set device to bondable mode**/
    virtual void rsp_sm_set_bondable_mode(const void *nul) {}
    
    /**delete bonding information from ps store**/
    virtual void rsp_sm_delete_bonding(const ble_msg_sm_delete_bonding_rsp_t *msg) {}
    
    /**set pairing requirements**/
    virtual void rsp_sm_set_parameters(const void *nul) {}
    
    /**Passkey entered**/
    virtual void rsp_sm_passkey_entry(const ble_msg_sm_passkey_entry_rsp_t *msg) {}
    
    /**List all bonded devices**/
    virtual void rsp_sm_get_bonds(const ble_msg_sm_get_bonds_rsp_t *msg) {}
    
    /**
    		    Set out-of-band encryption data for device
    		    Device does not allow any other kind of pairing except oob if oob data is set.
    		    **/
    virtual void rsp_sm_set_oob_data(const void *nul) {}
    
    /**
    				Add all bonded devices with a known public or static address to
    				the whitelist. Previous entries in the whitelist are first
    				cleared. This command can't be used while advertising, scanning
    				or being connected.
    			**/
    virtual void rsp_sm_whitelist_bonds(const ble_msg_sm_whitelist_bonds_rsp_t *msg) {}
    
    /**
    				Change keys distribution fields in pairing request and response. By default all keys are distributed.
    			**/
    virtual void rsp_sm_set_pairing_distribution_keys(const ble_msg_sm_set_pairing_distribution_keys_rsp_t *msg) {}
    
    /**Set GAP central/peripheral privacy flags	
    			**/
    virtual void rsp_gap_set_privacy_flags(const void *nul) {}
    
    /**Set discoverable and connectable mode**/
    virtual void rsp_gap_set_mode(const ble_msg_gap_set_mode_rsp_t *msg) {}
    
    /**start or stop discover procedure**/
    virtual void rsp_gap_discover(const ble_msg_gap_discover_rsp_t *msg) {}
    
    /**Direct connection**/
    virtual void rsp_gap_connect_direct(const ble_msg_gap_connect_direct_rsp_t *msg) {}
    
    /**End current GAP procedure**/
    virtual void rsp_gap_end_procedure(const ble_msg_gap_end_procedure_rsp_t *msg) {}
    
    /**Connect to any device on whitelist**/
    virtual void rsp_gap_connect_selective(const ble_msg_gap_connect_selective_rsp_t *msg) {}
    
    /**Set scan and advertising filtering parameters**/
    virtual void rsp_gap_set_filtering(const ble_msg_gap_set_filtering_rsp_t *msg) {}
    
    /**Set scan parameters**/
    virtual void rsp_gap_set_scan_parameters(const ble_msg_gap_set_scan_parameters_rsp_t *msg) {}
    
    /**Set advertising parameters**/
    virtual void rsp_gap_set_adv_parameters(const ble_msg_gap_set_adv_parameters_rsp_t *msg) {}
    
    /**Set advertisement or scan response data. Use broadcast mode to advertise data**/
    virtual void rsp_gap_set_adv_data(const ble_msg_gap_set_adv_data_rsp_t *msg) {}
    
    /**Sets device to Directed Connectable Mode
                            Uses fast advertisement procedure for 1.28s after which device enters nonconnectable mode. 
                            If device has valid reconnection characteristic value, it is used for connection
                            otherwise passed address and address type are used                        
                **/
    virtual void rsp_gap_set_directed_connectable_mode(const ble_msg_gap_set_directed_connectable_mode_rsp_t *msg) {}
    
    /**Set Initiating connection scan parameters**/
    virtual void rsp_gap_set_initiating_con_parameters(const ble_msg_gap_set_initiating_con_parameters_rsp_t *msg) {}
    
    /**Set non-resolvable address**/
    virtual void rsp_gap_set_nonresolvable_address(const ble_msg_gap_set_nonresolvable_address_rsp_t *msg) {}
    
    /**Configure I/O-port interrupts**/
    virtual void rsp_hardware_io_port_config_irq(const ble_msg_hardware_io_port_config_irq_rsp_t *msg) {}
    
    /**Set soft timer to send events**/
    virtual void rsp_hardware_set_soft_timer(const ble_msg_hardware_set_soft_timer_rsp_t *msg) {}
    
    /**Read A/D conversion**/
    virtual void rsp_hardware_adc_read(const ble_msg_hardware_adc_read_rsp_t *msg) {}
    
    /**Configure I/O-port direction**/
    virtual void rsp_hardware_io_port_config_direction(const ble_msg_hardware_io_port_config_direction_rsp_t *msg) {}
    
    /**Configure I/O-port function**/
    virtual void rsp_hardware_io_port_config_function(const ble_msg_hardware_io_port_config_function_rsp_t *msg) {}
    
    /**Configure I/O-port pull-up/pull-down**/
    virtual void rsp_hardware_io_port_config_pull(const ble_msg_hardware_io_port_config_pull_rsp_t *msg) {}
    
    /**Write I/O-port**/
    virtual void rsp_hardware_io_port_write(const ble_msg_hardware_io_port_write_rsp_t *msg) {}
    
    /**Read I/O-port**/
    virtual void rsp_hardware_io_port_read(const ble_msg_hardware_io_port_read_rsp_t *msg) {}
    
    /**Configure SPI**/
    virtual void rsp_hardware_spi_config(const ble_msg_hardware_spi_config_rsp_t *msg) {}
    
    /**Transfer SPI data**/
    virtual void rsp_hardware_spi_transfer(const ble_msg_hardware_spi_transfer_rsp_t *msg) {}
    
    /**Read data from I2C bus using bit-bang in cc2540. I2C clk is in P1.7 data in P1.6. Pull-up must be enabled on pins**/
    virtual void rsp_hardware_i2c_read(const ble_msg_hardware_i2c_read_rsp_t *msg) {}
    
    /**Write data to I2C bus using bit-bang in cc2540. I2C clk is in P1.7 data in P1.6. Pull-up must be enabled on pins**/
    virtual void rsp_hardware_i2c_write(const ble_msg_hardware_i2c_write_rsp_t *msg) {}
    
    /**Set TX Power**/
    virtual void rsp_hardware_set_txpower(const void *nul) {}
    
    /**Set comparator for timer channel**/
    virtual void rsp_hardware_timer_comparator(const ble_msg_hardware_timer_comparator_rsp_t *msg) {}
    
    /**Enable I/O-port interrupts**/
    virtual void rsp_hardware_io_port_irq_enable(const ble_msg_hardware_io_port_irq_enable_rsp_t *msg) {}
    
    /**Set I/O-port interrupt direction**/
    virtual void rsp_hardware_io_port_irq_direction(const ble_msg_hardware_io_port_irq_direction_rsp_t *msg) {}
    
    /**Enable or disable analog comparator**/
    virtual void rsp_hardware_analog_comparator_enable(const void *nul) {}
    
    /**Read analog comparator output**/
    virtual void rsp_hardware_analog_comparator_read(const ble_msg_hardware_analog_comparator_read_rsp_t *msg) {}
    
    /**Configure analog comparator interrupt**/
    virtual void rsp_hardware_analog_comparator_config_irq(const ble_msg_hardware_analog_comparator_config_irq_rsp_t *msg) {}
    
    /**Set RX Sensitivity**/
    virtual void rsp_hardware_set_rxgain(const void *nul) {}
    
    /**Enable or disable USB**/
    virtual void rsp_hardware_usb_enable(const ble_msg_hardware_usb_enable_rsp_t *msg) {}
    
    /**Enable or disable sleep mode**/
    virtual void rsp_hardware_sleep_enable(const ble_msg_hardware_sleep_enable_rsp_t *msg) {}
    
    /**Start packet transmission, send one packet at every 625us**/
    virtual void rsp_test_phy_tx(const void *nul) {}
    
    /**Start receive test**/
    virtual void rsp_test_phy_rx(const void *nul) {}
    
    /**End test, and report received packets**/
    virtual void rsp_test_phy_end(const ble_msg_test_phy_end_rsp_t *msg) {}
    
    /**Reset test**/
    virtual void rsp_test_phy_reset(const void *nul) {}
    
    /**Get current channel quality map**/
    virtual void rsp_test_get_channel_map(const ble_msg_test_get_channel_map_rsp_t *msg) {}
    
    /**Debug command**/
    virtual void rsp_test_debug(const ble_msg_test_debug_rsp_t *msg) {}
    
    /**Set channel quality measurement mode**/
    virtual void rsp_test_channel_mode(const void *nul) {}
    
    /**Reset system**/
    virtual void rsp_dfu_reset(const void *nul) {}
    
    /**set address for flashing**/
    virtual void rsp_dfu_flash_set_address(const ble_msg_dfu_flash_set_address_rsp_t *msg) {}
    
    /**Upload binary for flashing. Address will be updated automatically.**/
    virtual void rsp_dfu_flash_upload(const ble_msg_dfu_flash_upload_rsp_t *msg) {}
    
    /**Uploading is finished.**/
    virtual void rsp_dfu_flash_upload_finish(const ble_msg_dfu_flash_upload_finish_rsp_t *msg) {}
    
    /**Device booted up, and is ready to receive commands**/
    virtual void evt_system_boot(const ble_msg_system_boot_evt_t *msg) {}
    
    /**Debug data output**/
    virtual void evt_system_debug(const ble_msg_system_debug_evt_t *msg) {}
    
    /**Endpoint receive size crossed watermark**/
    virtual void evt_system_endpoint_watermark_rx(const ble_msg_system_endpoint_watermark_rx_evt_t *msg) {}
    
    /**Endpoint transmit size crossed watermark**/
    virtual void evt_system_endpoint_watermark_tx(const ble_msg_system_endpoint_watermark_tx_evt_t *msg) {}
    
    /**Script failure detected**/
    virtual void evt_system_script_failure(const ble_msg_system_script_failure_evt_t *msg) {}
    
    /**No valid license key found**/
    virtual void evt_system_no_license_key(const void *nul) {}
    
    /**Protocol error in command parser**/
    virtual void evt_system_protocol_error(const ble_msg_system_protocol_error_evt_t *msg) {}
    
    /**Dump key result**/
    virtual void evt_flash_ps_key(const ble_msg_flash_ps_key_evt_t *msg) {}
    
    /**Attribute value has changed**/
    virtual void evt_attributes_value(const ble_msg_attributes_value_evt_t *msg) {}
    
    /**User-backed attribute data requested**/
    virtual void evt_attributes_user_read_request(const ble_msg_attributes_user_read_request_evt_t *msg) {}
    
    /**attribute status flags has changed**/
    virtual void evt_attributes_status(const ble_msg_attributes_status_evt_t *msg) {}
    
    /**Connection opened**/
    virtual void evt_connection_status(const ble_msg_connection_status_evt_t *msg) {}
    
    /**Remote version information**/
    virtual void evt_connection_version_ind(const ble_msg_connection_version_ind_evt_t *msg) {}
    
    /**Remote feature information**/
    virtual void evt_connection_feature_ind(const ble_msg_connection_feature_ind_evt_t *msg) {}
    
    /**Raw RX**/
    virtual void evt_connection_raw_rx(const ble_msg_connection_raw_rx_evt_t *msg) {}
    
    /**Link Disconnected**/
    virtual void evt_connection_disconnected(const ble_msg_connection_disconnected_evt_t *msg) {}
    
    /**Attribute indication has been acknowledged**/
    virtual void evt_attclient_indicated(const ble_msg_attclient_indicated_evt_t *msg) {}
    
    /**GATT procedure completed**/
    virtual void evt_attclient_procedure_completed(const ble_msg_attclient_procedure_completed_evt_t *msg) {}
    
    /**group discovery return**/
    virtual void evt_attclient_group_found(const ble_msg_attclient_group_found_evt_t *msg) {}
    
    /**characteristics found**/
    virtual void evt_attclient_attribute_found(const ble_msg_attclient_attribute_found_evt_t *msg) {}
    
    /**Handle type mapping found**/
    virtual void evt_attclient_find_information_found(const ble_msg_attclient_find_information_found_evt_t *msg) {}
    
    /**attribute value returned**/
    virtual void evt_attclient_attribute_value(const ble_msg_attclient_attribute_value_evt_t *msg) {}
    
    /**Response to read multiple request**/
    virtual void evt_attclient_read_multiple_response(const ble_msg_attclient_read_multiple_response_evt_t *msg) {}
    
    /**SMP data output**/
    virtual void evt_sm_smp_data(const ble_msg_sm_smp_data_evt_t *msg) {}
    
    /**Link bonding has failed**/
    virtual void evt_sm_bonding_fail(const ble_msg_sm_bonding_fail_evt_t *msg) {}
    
    /**Passkey to be entered to remote device**/
    virtual void evt_sm_passkey_display(const ble_msg_sm_passkey_display_evt_t *msg) {}
    
    /**Passkey Requested**/
    virtual void evt_sm_passkey_request(const ble_msg_sm_passkey_request_evt_t *msg) {}
    
    /**Bond status information**/
    virtual void evt_sm_bond_status(const ble_msg_sm_bond_status_evt_t *msg) {}
    
    /**Scan Response**/
    virtual void evt_gap_scan_response(const ble_msg_gap_scan_response_evt_t *msg) {}
    
    /**Not used**/
    virtual void evt_gap_mode_changed(const ble_msg_gap_mode_changed_evt_t *msg) {}
    
    /**I/O-port state**/
    virtual void evt_hardware_io_port_status(const ble_msg_hardware_io_port_status_evt_t *msg) {}
    
    /**soft timer event**/
    virtual void evt_hardware_soft_timer(const ble_msg_hardware_soft_timer_evt_t *msg) {}
    
    /**adc result**/
    virtual void evt_hardware_adc_result(const ble_msg_hardware_adc_result_evt_t *msg) {}
    
    /**This event is produced when analog comparator output changes**/
    virtual void evt_hardware_analog_comparator_status(const ble_msg_hardware_analog_comparator_status_evt_t *msg) {}
    
    /**Device booted up in dfu, and is ready to receive commands**/
    virtual void evt_dfu_boot(const ble_msg_dfu_boot_evt_t *msg) {}
     
    virtual void _default(const void*) {}
}; // class ble
    
} // namespace bglib
