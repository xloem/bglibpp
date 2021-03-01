#pragma once

#include <cstdint>

/*Default packed configuration*/
#ifdef __GNUC__
#ifdef _WIN32
#define PACKSTRUCT( decl ) decl __attribute__((__packed__,gcc_struct))
#else
#define PACKSTRUCT( decl ) decl __attribute__((__packed__))
#endif
#define ALIGNED __attribute__((aligned(0x4)))
#elif __IAR_SYSTEMS_ICC__

#define PACKSTRUCT( decl ) __packed decl

#define ALIGNED
#elif _MSC_VER  //msvc

#define PACKSTRUCT( decl ) __pragma( pack(push, 1) ) decl __pragma( pack(pop) )
#define ALIGNED
#else 
#define PACKSTRUCT(a) a PACKED 
#endif

namespace bglib
{

struct bd_addr
{
    uint8_t addr[6];
};
typedef bd_addr hwaddr;

struct uint8array
{
    uint8_t len;
    uint8_t data[];
};

struct string
{
    uint8_t len;
    int8_t data[];
};

class ble;
typedef void (ble::*ble_cmd_handler)(const void*);
struct ble_header
{
    uint8_t  type_hilen;
    uint8_t  lolen;
    uint8_t  cls;
    uint8_t  command;
};


struct ble_msg
{
    ble_header    hdr;
    uint32_t               params;
    ble_cmd_handler       handler;
};       

struct ble_class_handler_t
{
    const ble_msg * const *msgs;
    uint8_t maxhandlers;
};

enum system_endpoints
{
    system_endpoint_api    = 0,
    system_endpoint_test   = 1,
    system_endpoint_script = 2,
    system_endpoint_usb    = 3,
    system_endpoint_uart0  = 4,
    system_endpoint_uart1  = 5,
    system_endpoints_max   = 6
};

enum attributes_attribute_change_reason
{
    attributes_attribute_change_reason_write_request      = 0,
    attributes_attribute_change_reason_write_command      = 1,
    attributes_attribute_change_reason_write_request_user = 2,
    attributes_attribute_change_reason_max                = 3
};

enum attributes_attribute_status_flag
{
    attributes_attribute_status_flag_notify   = 1,
    attributes_attribute_status_flag_indicate = 2,
    attributes_attribute_status_flag_max      = 3
};

enum connection_connstatus
{
    connection_connected         = 1,
    connection_encrypted         = 2,
    connection_completed         = 4,
    connection_parameters_change = 8,
    connection_connstatus_max    = 9
};

enum attclient_attribute_value_types
{
    attclient_attribute_value_type_read             = 0,
    attclient_attribute_value_type_notify           = 1,
    attclient_attribute_value_type_indicate         = 2,
    attclient_attribute_value_type_read_by_type     = 3,
    attclient_attribute_value_type_read_blob        = 4,
    attclient_attribute_value_type_indicate_rsp_req = 5,
    attclient_attribute_value_types_max             = 6
};

enum sm_bonding_key
{
    sm_bonding_key_ltk         = 0x01,
    sm_bonding_key_addr_public = 0x02,
    sm_bonding_key_addr_static = 0x04,
    sm_bonding_key_irk         = 0x08,
    sm_bonding_key_edivrand    = 0x10,
    sm_bonding_key_csrk        = 0x20,
    sm_bonding_key_masterid    = 0x40,
    sm_bonding_key_max         = 65
};

enum sm_io_capability
{
    sm_io_capability_displayonly     = 0,
    sm_io_capability_displayyesno    = 1,
    sm_io_capability_keyboardonly    = 2,
    sm_io_capability_noinputnooutput = 3,
    sm_io_capability_keyboarddisplay = 4,
    sm_io_capability_max             = 5
};

#define GAP_SCAN_HEADER_ADV_IND          0
#define GAP_SCAN_HEADER_ADV_DIRECT_IND   1
#define GAP_SCAN_HEADER_ADV_NONCONN_IND  2
#define GAP_SCAN_HEADER_SCAN_REQ         3
#define GAP_SCAN_HEADER_SCAN_RSP         4
#define GAP_SCAN_HEADER_CONNECT_REQ      5
#define GAP_SCAN_HEADER_ADV_DISCOVER_IND 6

#define GAP_AD_FLAG_LIMITED_DISCOVERABLE      0x01
#define GAP_AD_FLAG_GENERAL_DISCOVERABLE      0x02
#define GAP_AD_FLAG_BREDR_NOT_SUPPORTED       0x04
#define GAP_AD_FLAG_SIMULTANEOUS_LEBREDR_CTRL 0x10
#define GAP_AD_FLAG_SIMULTANEOUS_LEBREDR_HOST 0x20
#define GAP_AD_FLAG_MASK                      0x1f

enum gap_address_type
{
    gap_address_type_public = 0,
    gap_address_type_random = 1,
    gap_address_type_max    = 2
};

enum gap_discoverable_mode
{
    gap_non_discoverable     = 0,
    gap_limited_discoverable = 1,
    gap_general_discoverable = 2,
    gap_broadcast            = 3,
    gap_user_data            = 4,
    gap_discoverable_mode_max= 5
};

enum gap_connectable_mode
{
    gap_non_connectable           = 0,
    gap_directed_connectable      = 1,
    gap_undirected_connectable    = 2,
    gap_scannable_non_connectable = 3,
    gap_connectable_mode_max      = 4
};

enum gap_discover_mode
{
    gap_discover_limited     = 0,
    gap_discover_generic     = 1,
    gap_discover_observation = 2,
    gap_discover_mode_max    = 3
};

enum gap_ad_types
{
    gap_ad_type_none                 = 0,
    gap_ad_type_flags                = 1,
    gap_ad_type_services_16bit_more  = 2,
    gap_ad_type_services_16bit_all   = 3,
    gap_ad_type_services_32bit_more  = 4,
    gap_ad_type_services_32bit_all   = 5,
    gap_ad_type_services_128bit_more = 6,
    gap_ad_type_services_128bit_all  = 7,
    gap_ad_type_localname_short      = 8,
    gap_ad_type_localname_complete   = 9,
    gap_ad_type_txpower              = 10,
    gap_ad_types_max                 = 11
};

enum gap_advertising_policy
{
    gap_adv_policy_all               = 0,
    gap_adv_policy_whitelist_scan    = 1,
    gap_adv_policy_whitelist_connect = 2,
    gap_adv_policy_whitelist_all     = 3,
    gap_advertising_policy_max       = 4
};

enum gap_scan_policy
{
    gap_scan_policy_all       = 0,
    gap_scan_policy_whitelist = 1,
    gap_scan_policy_max       = 2
};


enum ble_parameter_types
{
    ble_msg_parameter_uint8=2,
    ble_msg_parameter_int8=3,
    ble_msg_parameter_uint16=4,
    ble_msg_parameter_int16=5,
    ble_msg_parameter_uint32=6,
    ble_msg_parameter_int32=7,
    ble_msg_parameter_uint8array=8,
    ble_msg_parameter_string=9,
    ble_msg_parameter_hwaddr=10,
    ble_msg_parameter_uint16array=11
};

enum ble_msg_types
{
    ble_msg_type_cmd=0x00,
    ble_msg_type_rsp=0x00,
    ble_msg_type_evt=0x80
};
enum ble_dev_types
{
    ble_dev_type_ble    =0x00,
    ble_dev_type_wifi   =0x08,
    ble_dev_type_iwrap  =0x10,
    ble_dev_type_dumo   =0x20,
    ble_dev_type_test   =0x20,
    ble_dev_type_gecko  =0x20
};

enum ble_classes
{
    ble_cls_system,
    ble_cls_flash,
    ble_cls_attributes,
    ble_cls_connection,
    ble_cls_attclient,
    ble_cls_sm,
    ble_cls_gap,
    ble_cls_hardware,
    ble_cls_test,
    ble_cls_dfu,
    ble_cls_last
};
enum ble_command_ids
{
    ble_cmd_system_reset_id=0,
    ble_cmd_system_hello_id=1,
    ble_cmd_system_address_get_id=2,
    ble_cmd_system_reg_write_id=3,
    ble_cmd_system_reg_read_id=4,
    ble_cmd_system_get_counters_id=5,
    ble_cmd_system_get_connections_id=6,
    ble_cmd_system_read_memory_id=7,
    ble_cmd_system_get_info_id=8,
    ble_cmd_system_endpoint_tx_id=9,
    ble_cmd_system_whitelist_append_id=10,
    ble_cmd_system_whitelist_remove_id=11,
    ble_cmd_system_whitelist_clear_id=12,
    ble_cmd_system_endpoint_rx_id=13,
    ble_cmd_system_endpoint_set_watermarks_id=14,
    ble_cmd_system_aes_setkey_id=15,
    ble_cmd_system_aes_encrypt_id=16,
    ble_cmd_system_aes_decrypt_id=17,
    ble_cmd_flash_ps_defrag_id=0,
    ble_cmd_flash_ps_dump_id=1,
    ble_cmd_flash_ps_erase_all_id=2,
    ble_cmd_flash_ps_save_id=3,
    ble_cmd_flash_ps_load_id=4,
    ble_cmd_flash_ps_erase_id=5,
    ble_cmd_flash_erase_page_id=6,
    ble_cmd_flash_write_data_id=7,
    ble_cmd_flash_read_data_id=8,
    ble_cmd_attributes_write_id=0,
    ble_cmd_attributes_read_id=1,
    ble_cmd_attributes_read_type_id=2,
    ble_cmd_attributes_user_read_response_id=3,
    ble_cmd_attributes_user_write_response_id=4,
    ble_cmd_attributes_send_id=5,
    ble_cmd_connection_disconnect_id=0,
    ble_cmd_connection_get_rssi_id=1,
    ble_cmd_connection_update_id=2,
    ble_cmd_connection_version_update_id=3,
    ble_cmd_connection_channel_map_get_id=4,
    ble_cmd_connection_channel_map_set_id=5,
    ble_cmd_connection_features_get_id=6,
    ble_cmd_connection_get_status_id=7,
    ble_cmd_connection_raw_tx_id=8,
    ble_cmd_connection_slave_latency_disable_id=9,
    ble_cmd_attclient_find_by_type_value_id=0,
    ble_cmd_attclient_read_by_group_type_id=1,
    ble_cmd_attclient_read_by_type_id=2,
    ble_cmd_attclient_find_information_id=3,
    ble_cmd_attclient_read_by_handle_id=4,
    ble_cmd_attclient_attribute_write_id=5,
    ble_cmd_attclient_write_command_id=6,
    ble_cmd_attclient_indicate_confirm_id=7,
    ble_cmd_attclient_read_long_id=8,
    ble_cmd_attclient_prepare_write_id=9,
    ble_cmd_attclient_execute_write_id=10,
    ble_cmd_attclient_read_multiple_id=11,
    ble_cmd_sm_encrypt_start_id=0,
    ble_cmd_sm_set_bondable_mode_id=1,
    ble_cmd_sm_delete_bonding_id=2,
    ble_cmd_sm_set_parameters_id=3,
    ble_cmd_sm_passkey_entry_id=4,
    ble_cmd_sm_get_bonds_id=5,
    ble_cmd_sm_set_oob_data_id=6,
    ble_cmd_sm_whitelist_bonds_id=7,
    ble_cmd_sm_set_pairing_distribution_keys_id=8,
    ble_cmd_gap_set_privacy_flags_id=0,
    ble_cmd_gap_set_mode_id=1,
    ble_cmd_gap_discover_id=2,
    ble_cmd_gap_connect_direct_id=3,
    ble_cmd_gap_end_procedure_id=4,
    ble_cmd_gap_connect_selective_id=5,
    ble_cmd_gap_set_filtering_id=6,
    ble_cmd_gap_set_scan_parameters_id=7,
    ble_cmd_gap_set_adv_parameters_id=8,
    ble_cmd_gap_set_adv_data_id=9,
    ble_cmd_gap_set_directed_connectable_mode_id=10,
    ble_cmd_gap_set_initiating_con_parameters_id=11,
    ble_cmd_gap_set_nonresolvable_address_id=12,
    ble_cmd_hardware_io_port_config_irq_id=0,
    ble_cmd_hardware_set_soft_timer_id=1,
    ble_cmd_hardware_adc_read_id=2,
    ble_cmd_hardware_io_port_config_direction_id=3,
    ble_cmd_hardware_io_port_config_function_id=4,
    ble_cmd_hardware_io_port_config_pull_id=5,
    ble_cmd_hardware_io_port_write_id=6,
    ble_cmd_hardware_io_port_read_id=7,
    ble_cmd_hardware_spi_config_id=8,
    ble_cmd_hardware_spi_transfer_id=9,
    ble_cmd_hardware_i2c_read_id=10,
    ble_cmd_hardware_i2c_write_id=11,
    ble_cmd_hardware_set_txpower_id=12,
    ble_cmd_hardware_timer_comparator_id=13,
    ble_cmd_hardware_io_port_irq_enable_id=14,
    ble_cmd_hardware_io_port_irq_direction_id=15,
    ble_cmd_hardware_analog_comparator_enable_id=16,
    ble_cmd_hardware_analog_comparator_read_id=17,
    ble_cmd_hardware_analog_comparator_config_irq_id=18,
    ble_cmd_hardware_set_rxgain_id=19,
    ble_cmd_hardware_usb_enable_id=20,
    ble_cmd_hardware_sleep_enable_id=21,
    ble_cmd_test_phy_tx_id=0,
    ble_cmd_test_phy_rx_id=1,
    ble_cmd_test_phy_end_id=2,
    ble_cmd_test_phy_reset_id=3,
    ble_cmd_test_get_channel_map_id=4,
    ble_cmd_test_debug_id=5,
    ble_cmd_test_channel_mode_id=6,
    ble_cmd_dfu_reset_id=0,
    ble_cmd_dfu_flash_set_address_id=1,
    ble_cmd_dfu_flash_upload_id=2,
    ble_cmd_dfu_flash_upload_finish_id=3
};
enum ble_response_ids
{
    ble_rsp_system_reset_id=0,
    ble_rsp_system_hello_id=1,
    ble_rsp_system_address_get_id=2,
    ble_rsp_system_reg_write_id=3,
    ble_rsp_system_reg_read_id=4,
    ble_rsp_system_get_counters_id=5,
    ble_rsp_system_get_connections_id=6,
    ble_rsp_system_read_memory_id=7,
    ble_rsp_system_get_info_id=8,
    ble_rsp_system_endpoint_tx_id=9,
    ble_rsp_system_whitelist_append_id=10,
    ble_rsp_system_whitelist_remove_id=11,
    ble_rsp_system_whitelist_clear_id=12,
    ble_rsp_system_endpoint_rx_id=13,
    ble_rsp_system_endpoint_set_watermarks_id=14,
    ble_rsp_system_aes_setkey_id=15,
    ble_rsp_system_aes_encrypt_id=16,
    ble_rsp_system_aes_decrypt_id=17,
    ble_rsp_flash_ps_defrag_id=0,
    ble_rsp_flash_ps_dump_id=1,
    ble_rsp_flash_ps_erase_all_id=2,
    ble_rsp_flash_ps_save_id=3,
    ble_rsp_flash_ps_load_id=4,
    ble_rsp_flash_ps_erase_id=5,
    ble_rsp_flash_erase_page_id=6,
    ble_rsp_flash_write_data_id=7,
    ble_rsp_flash_read_data_id=8,
    ble_rsp_attributes_write_id=0,
    ble_rsp_attributes_read_id=1,
    ble_rsp_attributes_read_type_id=2,
    ble_rsp_attributes_user_read_response_id=3,
    ble_rsp_attributes_user_write_response_id=4,
    ble_rsp_attributes_send_id=5,
    ble_rsp_connection_disconnect_id=0,
    ble_rsp_connection_get_rssi_id=1,
    ble_rsp_connection_update_id=2,
    ble_rsp_connection_version_update_id=3,
    ble_rsp_connection_channel_map_get_id=4,
    ble_rsp_connection_channel_map_set_id=5,
    ble_rsp_connection_features_get_id=6,
    ble_rsp_connection_get_status_id=7,
    ble_rsp_connection_raw_tx_id=8,
    ble_rsp_connection_slave_latency_disable_id=9,
    ble_rsp_attclient_find_by_type_value_id=0,
    ble_rsp_attclient_read_by_group_type_id=1,
    ble_rsp_attclient_read_by_type_id=2,
    ble_rsp_attclient_find_information_id=3,
    ble_rsp_attclient_read_by_handle_id=4,
    ble_rsp_attclient_attribute_write_id=5,
    ble_rsp_attclient_write_command_id=6,
    ble_rsp_attclient_indicate_confirm_id=7,
    ble_rsp_attclient_read_long_id=8,
    ble_rsp_attclient_prepare_write_id=9,
    ble_rsp_attclient_execute_write_id=10,
    ble_rsp_attclient_read_multiple_id=11,
    ble_rsp_sm_encrypt_start_id=0,
    ble_rsp_sm_set_bondable_mode_id=1,
    ble_rsp_sm_delete_bonding_id=2,
    ble_rsp_sm_set_parameters_id=3,
    ble_rsp_sm_passkey_entry_id=4,
    ble_rsp_sm_get_bonds_id=5,
    ble_rsp_sm_set_oob_data_id=6,
    ble_rsp_sm_whitelist_bonds_id=7,
    ble_rsp_sm_set_pairing_distribution_keys_id=8,
    ble_rsp_gap_set_privacy_flags_id=0,
    ble_rsp_gap_set_mode_id=1,
    ble_rsp_gap_discover_id=2,
    ble_rsp_gap_connect_direct_id=3,
    ble_rsp_gap_end_procedure_id=4,
    ble_rsp_gap_connect_selective_id=5,
    ble_rsp_gap_set_filtering_id=6,
    ble_rsp_gap_set_scan_parameters_id=7,
    ble_rsp_gap_set_adv_parameters_id=8,
    ble_rsp_gap_set_adv_data_id=9,
    ble_rsp_gap_set_directed_connectable_mode_id=10,
    ble_rsp_gap_set_initiating_con_parameters_id=11,
    ble_rsp_gap_set_nonresolvable_address_id=12,
    ble_rsp_hardware_io_port_config_irq_id=0,
    ble_rsp_hardware_set_soft_timer_id=1,
    ble_rsp_hardware_adc_read_id=2,
    ble_rsp_hardware_io_port_config_direction_id=3,
    ble_rsp_hardware_io_port_config_function_id=4,
    ble_rsp_hardware_io_port_config_pull_id=5,
    ble_rsp_hardware_io_port_write_id=6,
    ble_rsp_hardware_io_port_read_id=7,
    ble_rsp_hardware_spi_config_id=8,
    ble_rsp_hardware_spi_transfer_id=9,
    ble_rsp_hardware_i2c_read_id=10,
    ble_rsp_hardware_i2c_write_id=11,
    ble_rsp_hardware_set_txpower_id=12,
    ble_rsp_hardware_timer_comparator_id=13,
    ble_rsp_hardware_io_port_irq_enable_id=14,
    ble_rsp_hardware_io_port_irq_direction_id=15,
    ble_rsp_hardware_analog_comparator_enable_id=16,
    ble_rsp_hardware_analog_comparator_read_id=17,
    ble_rsp_hardware_analog_comparator_config_irq_id=18,
    ble_rsp_hardware_set_rxgain_id=19,
    ble_rsp_hardware_usb_enable_id=20,
    ble_rsp_hardware_sleep_enable_id=21,
    ble_rsp_test_phy_tx_id=0,
    ble_rsp_test_phy_rx_id=1,
    ble_rsp_test_phy_end_id=2,
    ble_rsp_test_phy_reset_id=3,
    ble_rsp_test_get_channel_map_id=4,
    ble_rsp_test_debug_id=5,
    ble_rsp_test_channel_mode_id=6,
    ble_rsp_dfu_reset_id=0,
    ble_rsp_dfu_flash_set_address_id=1,
    ble_rsp_dfu_flash_upload_id=2,
    ble_rsp_dfu_flash_upload_finish_id=3
};
enum ble_event_ids
{
    ble_evt_system_boot_id=0,
    ble_evt_system_debug_id=1,
    ble_evt_system_endpoint_watermark_rx_id=2,
    ble_evt_system_endpoint_watermark_tx_id=3,
    ble_evt_system_script_failure_id=4,
    ble_evt_system_no_license_key_id=5,
    ble_evt_system_protocol_error_id=6,
    ble_evt_flash_ps_key_id=0,
    ble_evt_attributes_value_id=0,
    ble_evt_attributes_user_read_request_id=1,
    ble_evt_attributes_status_id=2,
    ble_evt_connection_status_id=0,
    ble_evt_connection_version_ind_id=1,
    ble_evt_connection_feature_ind_id=2,
    ble_evt_connection_raw_rx_id=3,
    ble_evt_connection_disconnected_id=4,
    ble_evt_attclient_indicated_id=0,
    ble_evt_attclient_procedure_completed_id=1,
    ble_evt_attclient_group_found_id=2,
    ble_evt_attclient_attribute_found_id=3,
    ble_evt_attclient_find_information_found_id=4,
    ble_evt_attclient_attribute_value_id=5,
    ble_evt_attclient_read_multiple_response_id=6,
    ble_evt_sm_smp_data_id=0,
    ble_evt_sm_bonding_fail_id=1,
    ble_evt_sm_passkey_display_id=2,
    ble_evt_sm_passkey_request_id=3,
    ble_evt_sm_bond_status_id=4,
    ble_evt_gap_scan_response_id=0,
    ble_evt_gap_mode_changed_id=1,
    ble_evt_hardware_io_port_status_id=0,
    ble_evt_hardware_soft_timer_id=1,
    ble_evt_hardware_adc_result_id=2,
    ble_evt_hardware_analog_comparator_status_id=3,
    ble_evt_dfu_boot_id=0
};
enum ble_msg_idx
{
    ble_cmd_system_reset_idx =0,
    ble_cmd_system_hello_idx =1,
    ble_cmd_system_address_get_idx =2,
    ble_cmd_system_reg_write_idx =3,
    ble_cmd_system_reg_read_idx =4,
    ble_cmd_system_get_counters_idx =5,
    ble_cmd_system_get_connections_idx =6,
    ble_cmd_system_read_memory_idx =7,
    ble_cmd_system_get_info_idx =8,
    ble_cmd_system_endpoint_tx_idx =9,
    ble_cmd_system_whitelist_append_idx =10,
    ble_cmd_system_whitelist_remove_idx =11,
    ble_cmd_system_whitelist_clear_idx =12,
    ble_cmd_system_endpoint_rx_idx =13,
    ble_cmd_system_endpoint_set_watermarks_idx =14,
    ble_cmd_system_aes_setkey_idx =15,
    ble_cmd_system_aes_encrypt_idx =16,
    ble_cmd_system_aes_decrypt_idx =17,
    ble_cmd_flash_ps_defrag_idx =18,
    ble_cmd_flash_ps_dump_idx =19,
    ble_cmd_flash_ps_erase_all_idx =20,
    ble_cmd_flash_ps_save_idx =21,
    ble_cmd_flash_ps_load_idx =22,
    ble_cmd_flash_ps_erase_idx =23,
    ble_cmd_flash_erase_page_idx =24,
    ble_cmd_flash_write_data_idx =25,
    ble_cmd_flash_read_data_idx =26,
    ble_cmd_attributes_write_idx =27,
    ble_cmd_attributes_read_idx =28,
    ble_cmd_attributes_read_type_idx =29,
    ble_cmd_attributes_user_read_response_idx =30,
    ble_cmd_attributes_user_write_response_idx =31,
    ble_cmd_attributes_send_idx =32,
    ble_cmd_connection_disconnect_idx =33,
    ble_cmd_connection_get_rssi_idx =34,
    ble_cmd_connection_update_idx =35,
    ble_cmd_connection_version_update_idx =36,
    ble_cmd_connection_channel_map_get_idx =37,
    ble_cmd_connection_channel_map_set_idx =38,
    ble_cmd_connection_features_get_idx =39,
    ble_cmd_connection_get_status_idx =40,
    ble_cmd_connection_raw_tx_idx =41,
    ble_cmd_connection_slave_latency_disable_idx =42,
    ble_cmd_attclient_find_by_type_value_idx =43,
    ble_cmd_attclient_read_by_group_type_idx =44,
    ble_cmd_attclient_read_by_type_idx =45,
    ble_cmd_attclient_find_information_idx =46,
    ble_cmd_attclient_read_by_handle_idx =47,
    ble_cmd_attclient_attribute_write_idx =48,
    ble_cmd_attclient_write_command_idx =49,
    ble_cmd_attclient_indicate_confirm_idx =50,
    ble_cmd_attclient_read_long_idx =51,
    ble_cmd_attclient_prepare_write_idx =52,
    ble_cmd_attclient_execute_write_idx =53,
    ble_cmd_attclient_read_multiple_idx =54,
    ble_cmd_sm_encrypt_start_idx =55,
    ble_cmd_sm_set_bondable_mode_idx =56,
    ble_cmd_sm_delete_bonding_idx =57,
    ble_cmd_sm_set_parameters_idx =58,
    ble_cmd_sm_passkey_entry_idx =59,
    ble_cmd_sm_get_bonds_idx =60,
    ble_cmd_sm_set_oob_data_idx =61,
    ble_cmd_sm_whitelist_bonds_idx =62,
    ble_cmd_sm_set_pairing_distribution_keys_idx =63,
    ble_cmd_gap_set_privacy_flags_idx =64,
    ble_cmd_gap_set_mode_idx =65,
    ble_cmd_gap_discover_idx =66,
    ble_cmd_gap_connect_direct_idx =67,
    ble_cmd_gap_end_procedure_idx =68,
    ble_cmd_gap_connect_selective_idx =69,
    ble_cmd_gap_set_filtering_idx =70,
    ble_cmd_gap_set_scan_parameters_idx =71,
    ble_cmd_gap_set_adv_parameters_idx =72,
    ble_cmd_gap_set_adv_data_idx =73,
    ble_cmd_gap_set_directed_connectable_mode_idx =74,
    ble_cmd_gap_set_initiating_con_parameters_idx =75,
    ble_cmd_gap_set_nonresolvable_address_idx =76,
    ble_cmd_hardware_io_port_config_irq_idx =77,
    ble_cmd_hardware_set_soft_timer_idx =78,
    ble_cmd_hardware_adc_read_idx =79,
    ble_cmd_hardware_io_port_config_direction_idx =80,
    ble_cmd_hardware_io_port_config_function_idx =81,
    ble_cmd_hardware_io_port_config_pull_idx =82,
    ble_cmd_hardware_io_port_write_idx =83,
    ble_cmd_hardware_io_port_read_idx =84,
    ble_cmd_hardware_spi_config_idx =85,
    ble_cmd_hardware_spi_transfer_idx =86,
    ble_cmd_hardware_i2c_read_idx =87,
    ble_cmd_hardware_i2c_write_idx =88,
    ble_cmd_hardware_set_txpower_idx =89,
    ble_cmd_hardware_timer_comparator_idx =90,
    ble_cmd_hardware_io_port_irq_enable_idx =91,
    ble_cmd_hardware_io_port_irq_direction_idx =92,
    ble_cmd_hardware_analog_comparator_enable_idx =93,
    ble_cmd_hardware_analog_comparator_read_idx =94,
    ble_cmd_hardware_analog_comparator_config_irq_idx =95,
    ble_cmd_hardware_set_rxgain_idx =96,
    ble_cmd_hardware_usb_enable_idx =97,
    ble_cmd_hardware_sleep_enable_idx =98,
    ble_cmd_test_phy_tx_idx =99,
    ble_cmd_test_phy_rx_idx =100,
    ble_cmd_test_phy_end_idx =101,
    ble_cmd_test_phy_reset_idx =102,
    ble_cmd_test_get_channel_map_idx =103,
    ble_cmd_test_debug_idx =104,
    ble_cmd_test_channel_mode_idx =105,
    ble_cmd_dfu_reset_idx =106,
    ble_cmd_dfu_flash_set_address_idx =107,
    ble_cmd_dfu_flash_upload_idx =108,
    ble_cmd_dfu_flash_upload_finish_idx =109,
    ble_rsp_system_reset_idx =110,
    ble_rsp_system_hello_idx =111,
    ble_rsp_system_address_get_idx =112,
    ble_rsp_system_reg_write_idx =113,
    ble_rsp_system_reg_read_idx =114,
    ble_rsp_system_get_counters_idx =115,
    ble_rsp_system_get_connections_idx =116,
    ble_rsp_system_read_memory_idx =117,
    ble_rsp_system_get_info_idx =118,
    ble_rsp_system_endpoint_tx_idx =119,
    ble_rsp_system_whitelist_append_idx =120,
    ble_rsp_system_whitelist_remove_idx =121,
    ble_rsp_system_whitelist_clear_idx =122,
    ble_rsp_system_endpoint_rx_idx =123,
    ble_rsp_system_endpoint_set_watermarks_idx =124,
    ble_rsp_system_aes_setkey_idx =125,
    ble_rsp_system_aes_encrypt_idx =126,
    ble_rsp_system_aes_decrypt_idx =127,
    ble_rsp_flash_ps_defrag_idx =128,
    ble_rsp_flash_ps_dump_idx =129,
    ble_rsp_flash_ps_erase_all_idx =130,
    ble_rsp_flash_ps_save_idx =131,
    ble_rsp_flash_ps_load_idx =132,
    ble_rsp_flash_ps_erase_idx =133,
    ble_rsp_flash_erase_page_idx =134,
    ble_rsp_flash_write_data_idx =135,
    ble_rsp_flash_read_data_idx =136,
    ble_rsp_attributes_write_idx =137,
    ble_rsp_attributes_read_idx =138,
    ble_rsp_attributes_read_type_idx =139,
    ble_rsp_attributes_user_read_response_idx =140,
    ble_rsp_attributes_user_write_response_idx =141,
    ble_rsp_attributes_send_idx =142,
    ble_rsp_connection_disconnect_idx =143,
    ble_rsp_connection_get_rssi_idx =144,
    ble_rsp_connection_update_idx =145,
    ble_rsp_connection_version_update_idx =146,
    ble_rsp_connection_channel_map_get_idx =147,
    ble_rsp_connection_channel_map_set_idx =148,
    ble_rsp_connection_features_get_idx =149,
    ble_rsp_connection_get_status_idx =150,
    ble_rsp_connection_raw_tx_idx =151,
    ble_rsp_connection_slave_latency_disable_idx =152,
    ble_rsp_attclient_find_by_type_value_idx =153,
    ble_rsp_attclient_read_by_group_type_idx =154,
    ble_rsp_attclient_read_by_type_idx =155,
    ble_rsp_attclient_find_information_idx =156,
    ble_rsp_attclient_read_by_handle_idx =157,
    ble_rsp_attclient_attribute_write_idx =158,
    ble_rsp_attclient_write_command_idx =159,
    ble_rsp_attclient_indicate_confirm_idx =160,
    ble_rsp_attclient_read_long_idx =161,
    ble_rsp_attclient_prepare_write_idx =162,
    ble_rsp_attclient_execute_write_idx =163,
    ble_rsp_attclient_read_multiple_idx =164,
    ble_rsp_sm_encrypt_start_idx =165,
    ble_rsp_sm_set_bondable_mode_idx =166,
    ble_rsp_sm_delete_bonding_idx =167,
    ble_rsp_sm_set_parameters_idx =168,
    ble_rsp_sm_passkey_entry_idx =169,
    ble_rsp_sm_get_bonds_idx =170,
    ble_rsp_sm_set_oob_data_idx =171,
    ble_rsp_sm_whitelist_bonds_idx =172,
    ble_rsp_sm_set_pairing_distribution_keys_idx =173,
    ble_rsp_gap_set_privacy_flags_idx =174,
    ble_rsp_gap_set_mode_idx =175,
    ble_rsp_gap_discover_idx =176,
    ble_rsp_gap_connect_direct_idx =177,
    ble_rsp_gap_end_procedure_idx =178,
    ble_rsp_gap_connect_selective_idx =179,
    ble_rsp_gap_set_filtering_idx =180,
    ble_rsp_gap_set_scan_parameters_idx =181,
    ble_rsp_gap_set_adv_parameters_idx =182,
    ble_rsp_gap_set_adv_data_idx =183,
    ble_rsp_gap_set_directed_connectable_mode_idx =184,
    ble_rsp_gap_set_initiating_con_parameters_idx =185,
    ble_rsp_gap_set_nonresolvable_address_idx =186,
    ble_rsp_hardware_io_port_config_irq_idx =187,
    ble_rsp_hardware_set_soft_timer_idx =188,
    ble_rsp_hardware_adc_read_idx =189,
    ble_rsp_hardware_io_port_config_direction_idx =190,
    ble_rsp_hardware_io_port_config_function_idx =191,
    ble_rsp_hardware_io_port_config_pull_idx =192,
    ble_rsp_hardware_io_port_write_idx =193,
    ble_rsp_hardware_io_port_read_idx =194,
    ble_rsp_hardware_spi_config_idx =195,
    ble_rsp_hardware_spi_transfer_idx =196,
    ble_rsp_hardware_i2c_read_idx =197,
    ble_rsp_hardware_i2c_write_idx =198,
    ble_rsp_hardware_set_txpower_idx =199,
    ble_rsp_hardware_timer_comparator_idx =200,
    ble_rsp_hardware_io_port_irq_enable_idx =201,
    ble_rsp_hardware_io_port_irq_direction_idx =202,
    ble_rsp_hardware_analog_comparator_enable_idx =203,
    ble_rsp_hardware_analog_comparator_read_idx =204,
    ble_rsp_hardware_analog_comparator_config_irq_idx =205,
    ble_rsp_hardware_set_rxgain_idx =206,
    ble_rsp_hardware_usb_enable_idx =207,
    ble_rsp_hardware_sleep_enable_idx =208,
    ble_rsp_test_phy_tx_idx =209,
    ble_rsp_test_phy_rx_idx =210,
    ble_rsp_test_phy_end_idx =211,
    ble_rsp_test_phy_reset_idx =212,
    ble_rsp_test_get_channel_map_idx =213,
    ble_rsp_test_debug_idx =214,
    ble_rsp_test_channel_mode_idx =215,
    ble_rsp_dfu_reset_idx =216,
    ble_rsp_dfu_flash_set_address_idx =217,
    ble_rsp_dfu_flash_upload_idx =218,
    ble_rsp_dfu_flash_upload_finish_idx =219,
    ble_evt_system_boot_idx =220,
    ble_evt_system_debug_idx =221,
    ble_evt_system_endpoint_watermark_rx_idx =222,
    ble_evt_system_endpoint_watermark_tx_idx =223,
    ble_evt_system_script_failure_idx =224,
    ble_evt_system_no_license_key_idx =225,
    ble_evt_system_protocol_error_idx =226,
    ble_evt_flash_ps_key_idx =227,
    ble_evt_attributes_value_idx =228,
    ble_evt_attributes_user_read_request_idx =229,
    ble_evt_attributes_status_idx =230,
    ble_evt_connection_status_idx =231,
    ble_evt_connection_version_ind_idx =232,
    ble_evt_connection_feature_ind_idx =233,
    ble_evt_connection_raw_rx_idx =234,
    ble_evt_connection_disconnected_idx =235,
    ble_evt_attclient_indicated_idx =236,
    ble_evt_attclient_procedure_completed_idx =237,
    ble_evt_attclient_group_found_idx =238,
    ble_evt_attclient_attribute_found_idx =239,
    ble_evt_attclient_find_information_found_idx =240,
    ble_evt_attclient_attribute_value_idx =241,
    ble_evt_attclient_read_multiple_response_idx =242,
    ble_evt_sm_smp_data_idx =243,
    ble_evt_sm_bonding_fail_idx =244,
    ble_evt_sm_passkey_display_idx =245,
    ble_evt_sm_passkey_request_idx =246,
    ble_evt_sm_bond_status_idx =247,
    ble_evt_gap_scan_response_idx =248,
    ble_evt_gap_mode_changed_idx =249,
    ble_evt_hardware_io_port_status_idx =250,
    ble_evt_hardware_soft_timer_idx =251,
    ble_evt_hardware_adc_result_idx =252,
    ble_evt_hardware_analog_comparator_status_idx =253,
    ble_evt_dfu_boot_idx =254
};

enum ble_error_spaces
{
    ble_errspc_bt=512,
    ble_errspc_att=1024,
    ble_errspc_bg=256,
    ble_errspc_smp=768,
};
enum ble_error
{
    ble_err_bt_error_success                                    =ble_errspc_bt+0,   //Command completed succesfully
    ble_err_bt_bt_error_authentication_failure                  =ble_errspc_bt+5,   //Pairing or authentication failed due to incorrect results in the pairing or authentication procedure. This could be due to an incorrect PIN or Link Key
    ble_err_bt_pin_or_key_missing                               =ble_errspc_bt+6,   //Pairing failed because of missing PIN, or authentication failed because of missing Key
    ble_err_bt_bt_error_memory_capacity_exceeded                =ble_errspc_bt+7,   //Controller is out of memory.
    ble_err_bt_connection_timeout                               =ble_errspc_bt+8,   //Link supervision timeout has expired.
    ble_err_bt_connection_limit_exceeded                        =ble_errspc_bt+9,   //Controller is at limit of connections it can support.
    ble_err_bt_bt_error_command_disallowed                      =ble_errspc_bt+12,  //Command requested cannot be executed because the Controller is in a state where it cannot process this command at this time.
    ble_err_bt_bt_error_invalid_command_parameters              =ble_errspc_bt+18,  //Command contained invalid parameters.
    ble_err_bt_bt_error_remote_user_terminated                  =ble_errspc_bt+19,  //User on the remote device terminated the connection.
    ble_err_bt_bt_error_connection_terminated_by_local_host     =ble_errspc_bt+22,  //Local device terminated the connection.
    ble_err_bt_bt_error_ll_response_timeout                     =ble_errspc_bt+34,  //Connection terminated due to link-layer procedure timeout.
    ble_err_bt_bt_error_ll_instant_passed                       =ble_errspc_bt+40,  //Received link-layer control packet where instant was in the past.
    ble_err_bt_bt_error_controller_busy                         =ble_errspc_bt+58,  //Operation was rejected because the controller is busy and unable to process the request.
    ble_err_bt_bt_error_unacceptable_connection_interval        =ble_errspc_bt+59,  //Remote evice terminated the connection because of an unacceptable connection interval.
    ble_err_bt_bt_error_directed_advertising_timeout            =ble_errspc_bt+60,  //Directed advertising completed without a connection being created.
    ble_err_bt_bt_error_connection_terminated_due_to_mic_failure=ble_errspc_bt+61,  //Connection was terminated because the Message Integrity Check (MIC) failed on a received packet.
    ble_err_bt_bt_error_connection_failed_to_be_established     =ble_errspc_bt+62,  //LL initiated a connection but the connection has failed to be established. Controller did not receive any packets from remote end.
    ble_err_att_invalid_handle                                  =ble_errspc_att+1,  //The attribute handle given was not valid on this server
    ble_err_att_read_not_permitted                              =ble_errspc_att+2,  //The attribute cannot be read
    ble_err_att_write_not_permitted                             =ble_errspc_att+3,  //The attribute cannot be written
    ble_err_att_invalid_pdu                                     =ble_errspc_att+4,  //The attribute PDU was invalid
    ble_err_att_insufficient_authentication                     =ble_errspc_att+5,  //The attribute requires authentication before it can be read or written.
    ble_err_att_request_not_supported                           =ble_errspc_att+6,  //Attribute Server does not support the request received from the client.
    ble_err_att_invalid_offset                                  =ble_errspc_att+7,  //Offset specified was past the end of the attribute
    ble_err_att_insufficient_authorization                      =ble_errspc_att+8,  //The attribute requires authorization before it can be read or written.
    ble_err_att_prepare_queue_full                              =ble_errspc_att+9,  //Too many prepare writes have been queueud
    ble_err_att_att_not_found                                   =ble_errspc_att+10, //No attribute found within the given attribute handle range.
    ble_err_att_att_not_long                                    =ble_errspc_att+11, //The attribute cannot be read or written using the Read Blob Request
    ble_err_att_insufficient_enc_key_size                       =ble_errspc_att+12, //The Encryption Key Size used for encrypting this link is insufficient.
    ble_err_att_invalid_att_length                              =ble_errspc_att+13, //The attribute value length is invalid for the operation
    ble_err_att_unlikely_error                                  =ble_errspc_att+14, //The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested.
    ble_err_att_insufficient_encryption                         =ble_errspc_att+15, //The attribute requires encryption before it can be read or written.
    ble_err_att_unsupported_group_type                          =ble_errspc_att+16, //The attribute type is not a supported grouping attribute as defined by a higher layer specification.
    ble_err_att_insufficient_resources                          =ble_errspc_att+17, //Insufficient Resources to complete the request
    ble_err_att_application                                     =ble_errspc_att+128,//Application error code defined by a higher layer specification.
    ble_err_success                                             =0,                 //No error
    ble_err_invalid_param                                       =ble_errspc_bg+128, //Command contained invalid parameter
    ble_err_wrong_state                                         =ble_errspc_bg+129, //Device is in wrong state to receive command
    ble_err_out_of_memory                                       =ble_errspc_bg+130, //Device has run out of memory
    ble_err_not_implemented                                     =ble_errspc_bg+131, //Feature is not implemented
    ble_err_invalid_command                                     =ble_errspc_bg+132, //Command was not recognized
    ble_err_timeout                                             =ble_errspc_bg+133, //Command or Procedure failed due to timeout
    ble_err_not_connected                                       =ble_errspc_bg+134, //Connection handle passed is to command is not a valid handle
    ble_err_flow                                                =ble_errspc_bg+135, //Command would cause either underflow or overflow error
    ble_err_user_attribute                                      =ble_errspc_bg+136, //User attribute was accessed through API which is not supported
    ble_err_invalid_license_key                                 =ble_errspc_bg+137, //No valid license key found
    ble_err_command_too_long                                    =ble_errspc_bg+138, //Command maximum length exceeded
    ble_err_out_of_bonds                                        =ble_errspc_bg+139, //Bonding procedure can't be started because device has no space left for bond.
    ble_err_smp_passkey_entry_failed                            =ble_errspc_smp+1,  //The user input of passkey failed, for example, the user cancelled the operation
    ble_err_smp_oob_not_available                               =ble_errspc_smp+2,  //Out of Band data is not available for authentication
    ble_err_smp_authentication_requirements                     =ble_errspc_smp+3,  //The pairing procedure cannot be performed as authentication requirements cannot be met due to IO capabilities of one or both devices
    ble_err_smp_confirm_value_failed                            =ble_errspc_smp+4,  //The confirm value does not match the calculated compare value
    ble_err_smp_pairing_not_supported                           =ble_errspc_smp+5,  //Pairing is not supported by the device
    ble_err_smp_encryption_key_size                             =ble_errspc_smp+6,  //The resultant encryption key size is insufficient for the security requirements of this device
    ble_err_smp_command_not_supported                           =ble_errspc_smp+7,  //The SMP command received is not supported on this device
    ble_err_smp_unspecified_reason                              =ble_errspc_smp+8,  //Pairing failed due to an unspecified reason
    ble_err_smp_repeated_attempts                               =ble_errspc_smp+9,  //Pairing or authentication procedure is disallowed because too little time has elapsed since last pairing request or security request
    ble_err_smp_invalid_parameters                              =ble_errspc_smp+10, //The Invalid Parameters error code indicates: the command length is invalid or a parameter is outside of the specified range.
    ble_err_last
};
typedef enum ble_error errorcode_t;

PACKSTRUCT(struct ble_msg_system_reset_cmd_t
{
    uint8_t	boot_in_dfu;
});

PACKSTRUCT(struct ble_msg_system_address_get_rsp_t
{
    bd_addr	address;
});

PACKSTRUCT(struct ble_msg_system_reg_write_cmd_t
{
    uint16_t	address;
    uint8_t	value;
});

PACKSTRUCT(struct ble_msg_system_reg_write_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_system_reg_read_cmd_t
{
    uint16_t	address;
});

PACKSTRUCT(struct ble_msg_system_reg_read_rsp_t
{
    uint16_t	address;
    uint8_t	value;
});

PACKSTRUCT(struct ble_msg_system_get_counters_rsp_t
{
    uint8_t	txok;
    uint8_t	txretry;
    uint8_t	rxok;
    uint8_t	rxfail;
    uint8_t	mbuf;
});

PACKSTRUCT(struct ble_msg_system_get_connections_rsp_t
{
    uint8_t	maxconn;
});

PACKSTRUCT(struct ble_msg_system_read_memory_cmd_t
{
    uint32_t	address;
    uint8_t	length;
});

PACKSTRUCT(struct ble_msg_system_read_memory_rsp_t
{
    uint32_t	address;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_get_info_rsp_t
{
    uint16_t	major;
    uint16_t	minor;
    uint16_t	patch;
    uint16_t	build;
    uint16_t	ll_version;
    uint8_t	protocol_version;
    uint8_t	hw;
});

PACKSTRUCT(struct ble_msg_system_endpoint_tx_cmd_t
{
    uint8_t	endpoint;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_endpoint_tx_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_system_whitelist_append_cmd_t
{
    bd_addr	address;
    uint8_t	address_type;
});

PACKSTRUCT(struct ble_msg_system_whitelist_append_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_system_whitelist_remove_cmd_t
{
    bd_addr	address;
    uint8_t	address_type;
});

PACKSTRUCT(struct ble_msg_system_whitelist_remove_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_system_endpoint_rx_cmd_t
{
    uint8_t	endpoint;
    uint8_t	size;
});

PACKSTRUCT(struct ble_msg_system_endpoint_rx_rsp_t
{
    uint16_t	result;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_endpoint_set_watermarks_cmd_t
{
    uint8_t	endpoint;
    uint8_t	rx;
    uint8_t	tx;
});

PACKSTRUCT(struct ble_msg_system_endpoint_set_watermarks_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_system_aes_setkey_cmd_t
{
    uint8array	key;
});

PACKSTRUCT(struct ble_msg_system_aes_encrypt_cmd_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_aes_encrypt_rsp_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_aes_decrypt_cmd_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_aes_decrypt_rsp_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_boot_evt_t
{
    uint16_t	major;
    uint16_t	minor;
    uint16_t	patch;
    uint16_t	build;
    uint16_t	ll_version;
    uint8_t	protocol_version;
    uint8_t	hw;
});

PACKSTRUCT(struct ble_msg_system_debug_evt_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_system_endpoint_watermark_rx_evt_t
{
    uint8_t	endpoint;
    uint8_t	data;
});

PACKSTRUCT(struct ble_msg_system_endpoint_watermark_tx_evt_t
{
    uint8_t	endpoint;
    uint8_t	data;
});

PACKSTRUCT(struct ble_msg_system_script_failure_evt_t
{
    uint16_t	address;
    uint16_t	reason;
});

PACKSTRUCT(struct ble_msg_system_protocol_error_evt_t
{
    uint16_t	reason;
});

PACKSTRUCT(struct ble_msg_flash_ps_save_cmd_t
{
    uint16_t	key;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_flash_ps_save_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_flash_ps_load_cmd_t
{
    uint16_t	key;
});

PACKSTRUCT(struct ble_msg_flash_ps_load_rsp_t
{
    uint16_t	result;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_flash_ps_erase_cmd_t
{
    uint16_t	key;
});

PACKSTRUCT(struct ble_msg_flash_erase_page_cmd_t
{
    uint8_t	page;
});

PACKSTRUCT(struct ble_msg_flash_erase_page_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_flash_write_data_cmd_t
{
    uint32_t	address;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_flash_write_data_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_flash_read_data_cmd_t
{
    uint32_t	address;
    uint8_t	length;
});

PACKSTRUCT(struct ble_msg_flash_read_data_rsp_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_flash_ps_key_evt_t
{
    uint16_t	key;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_write_cmd_t
{
    uint16_t	handle;
    uint8_t	offset;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_write_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attributes_read_cmd_t
{
    uint16_t	handle;
    uint16_t	offset;
});

PACKSTRUCT(struct ble_msg_attributes_read_rsp_t
{
    uint16_t	handle;
    uint16_t	offset;
    uint16_t	result;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_read_type_cmd_t
{
    uint16_t	handle;
});

PACKSTRUCT(struct ble_msg_attributes_read_type_rsp_t
{
    uint16_t	handle;
    uint16_t	result;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_user_read_response_cmd_t
{
    uint8_t	connection;
    uint8_t	att_error;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_user_write_response_cmd_t
{
    uint8_t	connection;
    uint8_t	att_error;
});

PACKSTRUCT(struct ble_msg_attributes_send_cmd_t
{
    uint8_t	connection;
    uint16_t	handle;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_send_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attributes_value_evt_t
{
    uint8_t	connection;
    uint8_t	reason;
    uint16_t	handle;
    uint16_t	offset;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attributes_user_read_request_evt_t
{
    uint8_t	connection;
    uint16_t	handle;
    uint16_t	offset;
    uint8_t	maxsize;
});

PACKSTRUCT(struct ble_msg_attributes_status_evt_t
{
    uint16_t	handle;
    uint8_t	flags;
});

PACKSTRUCT(struct ble_msg_connection_disconnect_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_disconnect_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_connection_get_rssi_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_get_rssi_rsp_t
{
    uint8_t	connection;
    int8_t	rssi;
});

PACKSTRUCT(struct ble_msg_connection_update_cmd_t
{
    uint8_t	connection;
    uint16_t	interval_min;
    uint16_t	interval_max;
    uint16_t	latency;
    uint16_t	timeout;
});

PACKSTRUCT(struct ble_msg_connection_update_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_connection_version_update_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_version_update_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_connection_channel_map_get_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_channel_map_get_rsp_t
{
    uint8_t	connection;
    uint8array	map;
});

PACKSTRUCT(struct ble_msg_connection_channel_map_set_cmd_t
{
    uint8_t	connection;
    uint8array	map;
});

PACKSTRUCT(struct ble_msg_connection_channel_map_set_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_connection_features_get_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_features_get_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_connection_get_status_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_get_status_rsp_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_raw_tx_cmd_t
{
    uint8_t	connection;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_connection_raw_tx_rsp_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_connection_slave_latency_disable_cmd_t
{
    uint8_t	disable;
});

PACKSTRUCT(struct ble_msg_connection_slave_latency_disable_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_connection_status_evt_t
{
    uint8_t	connection;
    uint8_t	flags;
    bd_addr	address;
    uint8_t	address_type;
    uint16_t	conn_interval;
    uint16_t	timeout;
    uint16_t	latency;
    uint8_t	bonding;
});

PACKSTRUCT(struct ble_msg_connection_version_ind_evt_t
{
    uint8_t	connection;
    uint8_t	vers_nr;
    uint16_t	comp_id;
    uint16_t	sub_vers_nr;
});

PACKSTRUCT(struct ble_msg_connection_feature_ind_evt_t
{
    uint8_t	connection;
    uint8array	features;
});

PACKSTRUCT(struct ble_msg_connection_raw_rx_evt_t
{
    uint8_t	connection;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_connection_disconnected_evt_t
{
    uint8_t	connection;
    uint16_t	reason;
});

PACKSTRUCT(struct ble_msg_attclient_find_by_type_value_cmd_t
{
    uint8_t	connection;
    uint16_t	start;
    uint16_t	end;
    uint16_t	uuid;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attclient_find_by_type_value_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_read_by_group_type_cmd_t
{
    uint8_t	connection;
    uint16_t	start;
    uint16_t	end;
    uint8array	uuid;
});

PACKSTRUCT(struct ble_msg_attclient_read_by_group_type_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_read_by_type_cmd_t
{
    uint8_t	connection;
    uint16_t	start;
    uint16_t	end;
    uint8array	uuid;
});

PACKSTRUCT(struct ble_msg_attclient_read_by_type_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_find_information_cmd_t
{
    uint8_t	connection;
    uint16_t	start;
    uint16_t	end;
});

PACKSTRUCT(struct ble_msg_attclient_find_information_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_read_by_handle_cmd_t
{
    uint8_t	connection;
    uint16_t	chrhandle;
});

PACKSTRUCT(struct ble_msg_attclient_read_by_handle_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_attribute_write_cmd_t
{
    uint8_t	connection;
    uint16_t	atthandle;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_attclient_attribute_write_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_write_command_cmd_t
{
    uint8_t	connection;
    uint16_t	atthandle;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_attclient_write_command_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_indicate_confirm_cmd_t
{
    uint8_t	connection;
});

PACKSTRUCT(struct ble_msg_attclient_indicate_confirm_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_read_long_cmd_t
{
    uint8_t	connection;
    uint16_t	chrhandle;
});

PACKSTRUCT(struct ble_msg_attclient_read_long_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_prepare_write_cmd_t
{
    uint8_t	connection;
    uint16_t	atthandle;
    uint16_t	offset;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_attclient_prepare_write_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_execute_write_cmd_t
{
    uint8_t	connection;
    uint8_t	commit;
});

PACKSTRUCT(struct ble_msg_attclient_execute_write_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_read_multiple_cmd_t
{
    uint8_t	connection;
    uint8array	handles;
});

PACKSTRUCT(struct ble_msg_attclient_read_multiple_rsp_t
{
    uint8_t	connection;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_attclient_indicated_evt_t
{
    uint8_t	connection;
    uint16_t	attrhandle;
});

PACKSTRUCT(struct ble_msg_attclient_procedure_completed_evt_t
{
    uint8_t	connection;
    uint16_t	result;
    uint16_t	chrhandle;
});

PACKSTRUCT(struct ble_msg_attclient_group_found_evt_t
{
    uint8_t	connection;
    uint16_t	start;
    uint16_t	end;
    uint8array	uuid;
});

PACKSTRUCT(struct ble_msg_attclient_attribute_found_evt_t
{
    uint8_t	connection;
    uint16_t	chrdecl;
    uint16_t	value;
    uint8_t	properties;
    uint8array	uuid;
});

PACKSTRUCT(struct ble_msg_attclient_find_information_found_evt_t
{
    uint8_t	connection;
    uint16_t	chrhandle;
    uint8array	uuid;
});

PACKSTRUCT(struct ble_msg_attclient_attribute_value_evt_t
{
    uint8_t	connection;
    uint16_t	atthandle;
    uint8_t	type;
    uint8array	value;
});

PACKSTRUCT(struct ble_msg_attclient_read_multiple_response_evt_t
{
    uint8_t	connection;
    uint8array	handles;
});

PACKSTRUCT(struct ble_msg_sm_encrypt_start_cmd_t
{
    uint8_t	handle;
    uint8_t	bonding;
});

PACKSTRUCT(struct ble_msg_sm_encrypt_start_rsp_t
{
    uint8_t	handle;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_sm_set_bondable_mode_cmd_t
{
    uint8_t	bondable;
});

PACKSTRUCT(struct ble_msg_sm_delete_bonding_cmd_t
{
    uint8_t	handle;
});

PACKSTRUCT(struct ble_msg_sm_delete_bonding_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_sm_set_parameters_cmd_t
{
    uint8_t	mitm;
    uint8_t	min_key_size;
    uint8_t	io_capabilities;
});

PACKSTRUCT(struct ble_msg_sm_passkey_entry_cmd_t
{
    uint8_t	handle;
    uint32_t	passkey;
});

PACKSTRUCT(struct ble_msg_sm_passkey_entry_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_sm_get_bonds_rsp_t
{
    uint8_t	bonds;
});

PACKSTRUCT(struct ble_msg_sm_set_oob_data_cmd_t
{
    uint8array	oob;
});

PACKSTRUCT(struct ble_msg_sm_whitelist_bonds_rsp_t
{
    uint16_t	result;
    uint8_t	count;
});

PACKSTRUCT(struct ble_msg_sm_set_pairing_distribution_keys_cmd_t
{
    uint8_t	initiator_keys;
    uint8_t	responder_keys;
});

PACKSTRUCT(struct ble_msg_sm_set_pairing_distribution_keys_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_sm_smp_data_evt_t
{
    uint8_t	handle;
    uint8_t	packet;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_sm_bonding_fail_evt_t
{
    uint8_t	handle;
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_sm_passkey_display_evt_t
{
    uint8_t	handle;
    uint32_t	passkey;
});

PACKSTRUCT(struct ble_msg_sm_passkey_request_evt_t
{
    uint8_t	handle;
});

PACKSTRUCT(struct ble_msg_sm_bond_status_evt_t
{
    uint8_t	bond;
    uint8_t	keysize;
    uint8_t	mitm;
    uint8_t	keys;
});

PACKSTRUCT(struct ble_msg_gap_set_privacy_flags_cmd_t
{
    uint8_t	peripheral_privacy;
    uint8_t	central_privacy;
});

PACKSTRUCT(struct ble_msg_gap_set_mode_cmd_t
{
    uint8_t	discover;
    uint8_t	connect;
});

PACKSTRUCT(struct ble_msg_gap_set_mode_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_discover_cmd_t
{
    uint8_t	mode;
});

PACKSTRUCT(struct ble_msg_gap_discover_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_connect_direct_cmd_t
{
    bd_addr	address;
    uint8_t	addr_type;
    uint16_t	conn_interval_min;
    uint16_t	conn_interval_max;
    uint16_t	timeout;
    uint16_t	latency;
});

PACKSTRUCT(struct ble_msg_gap_connect_direct_rsp_t
{
    uint16_t	result;
    uint8_t	connection_handle;
});

PACKSTRUCT(struct ble_msg_gap_end_procedure_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_connect_selective_cmd_t
{
    uint16_t	conn_interval_min;
    uint16_t	conn_interval_max;
    uint16_t	timeout;
    uint16_t	latency;
});

PACKSTRUCT(struct ble_msg_gap_connect_selective_rsp_t
{
    uint16_t	result;
    uint8_t	connection_handle;
});

PACKSTRUCT(struct ble_msg_gap_set_filtering_cmd_t
{
    uint8_t	scan_policy;
    uint8_t	adv_policy;
    uint8_t	scan_duplicate_filtering;
});

PACKSTRUCT(struct ble_msg_gap_set_filtering_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_set_scan_parameters_cmd_t
{
    uint16_t	scan_interval;
    uint16_t	scan_window;
    uint8_t	active;
});

PACKSTRUCT(struct ble_msg_gap_set_scan_parameters_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_set_adv_parameters_cmd_t
{
    uint16_t	adv_interval_min;
    uint16_t	adv_interval_max;
    uint8_t	adv_channels;
});

PACKSTRUCT(struct ble_msg_gap_set_adv_parameters_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_set_adv_data_cmd_t
{
    uint8_t	set_scanrsp;
    uint8array	adv_data;
});

PACKSTRUCT(struct ble_msg_gap_set_adv_data_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_set_directed_connectable_mode_cmd_t
{
    bd_addr	address;
    uint8_t	addr_type;
});

PACKSTRUCT(struct ble_msg_gap_set_directed_connectable_mode_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_set_initiating_con_parameters_cmd_t
{
    uint16_t	scan_interval;
    uint16_t	scan_window;
});

PACKSTRUCT(struct ble_msg_gap_set_initiating_con_parameters_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_set_nonresolvable_address_cmd_t
{
    bd_addr	address;
});

PACKSTRUCT(struct ble_msg_gap_set_nonresolvable_address_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_gap_scan_response_evt_t
{
    int8_t	rssi;
    uint8_t	packet_type;
    bd_addr	sender;
    uint8_t	address_type;
    uint8_t	bond;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_gap_mode_changed_evt_t
{
    uint8_t	discover;
    uint8_t	connect;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_irq_cmd_t
{
    uint8_t	port;
    uint8_t	enable_bits;
    uint8_t	falling_edge;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_irq_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_set_soft_timer_cmd_t
{
    uint32_t	time;
    uint8_t	handle;
    uint8_t	single_shot;
});

PACKSTRUCT(struct ble_msg_hardware_set_soft_timer_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_adc_read_cmd_t
{
    uint8_t	input;
    uint8_t	decimation;
    uint8_t	reference_selection;
});

PACKSTRUCT(struct ble_msg_hardware_adc_read_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_direction_cmd_t
{
    uint8_t	port;
    uint8_t	direction;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_direction_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_function_cmd_t
{
    uint8_t	port;
    uint8_t	function;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_function_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_pull_cmd_t
{
    uint8_t	port;
    uint8_t	tristate_mask;
    uint8_t	pull_up;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_config_pull_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_write_cmd_t
{
    uint8_t	port;
    uint8_t	mask;
    uint8_t	data;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_write_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_read_cmd_t
{
    uint8_t	port;
    uint8_t	mask;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_read_rsp_t
{
    uint16_t	result;
    uint8_t	port;
    uint8_t	data;
});

PACKSTRUCT(struct ble_msg_hardware_spi_config_cmd_t
{
    uint8_t	channel;
    uint8_t	polarity;
    uint8_t	phase;
    uint8_t	bit_order;
    uint8_t	baud_e;
    uint8_t	baud_m;
});

PACKSTRUCT(struct ble_msg_hardware_spi_config_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_spi_transfer_cmd_t
{
    uint8_t	channel;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_hardware_spi_transfer_rsp_t
{
    uint16_t	result;
    uint8_t	channel;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_hardware_i2c_read_cmd_t
{
    uint8_t	address;
    uint8_t	stop;
    uint8_t	length;
});

PACKSTRUCT(struct ble_msg_hardware_i2c_read_rsp_t
{
    uint16_t	result;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_hardware_i2c_write_cmd_t
{
    uint8_t	address;
    uint8_t	stop;
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_hardware_i2c_write_rsp_t
{
    uint8_t	written;
});

PACKSTRUCT(struct ble_msg_hardware_set_txpower_cmd_t
{
    uint8_t	power;
});

PACKSTRUCT(struct ble_msg_hardware_timer_comparator_cmd_t
{
    uint8_t	timer;
    uint8_t	channel;
    uint8_t	mode;
    uint16_t	comparator_value;
});

PACKSTRUCT(struct ble_msg_hardware_timer_comparator_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_irq_enable_cmd_t
{
    uint8_t	port;
    uint8_t	enable_bits;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_irq_enable_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_irq_direction_cmd_t
{
    uint8_t	port;
    uint8_t	falling_edge;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_irq_direction_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_analog_comparator_enable_cmd_t
{
    uint8_t	enable;
});

PACKSTRUCT(struct ble_msg_hardware_analog_comparator_read_rsp_t
{
    uint16_t	result;
    uint8_t	output;
});

PACKSTRUCT(struct ble_msg_hardware_analog_comparator_config_irq_cmd_t
{
    uint8_t	enabled;
});

PACKSTRUCT(struct ble_msg_hardware_analog_comparator_config_irq_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_set_rxgain_cmd_t
{
    uint8_t	gain;
});

PACKSTRUCT(struct ble_msg_hardware_usb_enable_cmd_t
{
    uint8_t	enable;
});

PACKSTRUCT(struct ble_msg_hardware_usb_enable_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_sleep_enable_cmd_t
{
    uint8_t	enable;
});

PACKSTRUCT(struct ble_msg_hardware_sleep_enable_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_hardware_io_port_status_evt_t
{
    uint32_t	timestamp;
    uint8_t	port;
    uint8_t	irq;
    uint8_t	state;
});

PACKSTRUCT(struct ble_msg_hardware_soft_timer_evt_t
{
    uint8_t	handle;
});

PACKSTRUCT(struct ble_msg_hardware_adc_result_evt_t
{
    uint8_t	input;
    int16_t	value;
});

PACKSTRUCT(struct ble_msg_hardware_analog_comparator_status_evt_t
{
    uint32_t	timestamp;
    uint8_t	output;
});

PACKSTRUCT(struct ble_msg_test_phy_tx_cmd_t
{
    uint8_t	channel;
    uint8_t	length;
    uint8_t	type;
});

PACKSTRUCT(struct ble_msg_test_phy_rx_cmd_t
{
    uint8_t	channel;
});

PACKSTRUCT(struct ble_msg_test_phy_end_rsp_t
{
    uint16_t	counter;
});

PACKSTRUCT(struct ble_msg_test_get_channel_map_rsp_t
{
    uint8array	channel_map;
});

PACKSTRUCT(struct ble_msg_test_debug_cmd_t
{
    uint8_t	opcode;
    uint8array	input;
});

PACKSTRUCT(struct ble_msg_test_debug_rsp_t
{
    uint8_t	opcode;
    uint8array	output;
});

PACKSTRUCT(struct ble_msg_test_channel_mode_cmd_t
{
    uint8_t	mode;
});

PACKSTRUCT(struct ble_msg_dfu_reset_cmd_t
{
    uint8_t	dfu;
});

PACKSTRUCT(struct ble_msg_dfu_flash_set_address_cmd_t
{
    uint32_t	address;
});

PACKSTRUCT(struct ble_msg_dfu_flash_set_address_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_dfu_flash_upload_cmd_t
{
    uint8array	data;
});

PACKSTRUCT(struct ble_msg_dfu_flash_upload_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_dfu_flash_upload_finish_rsp_t
{
    uint16_t	result;
});

PACKSTRUCT(struct ble_msg_dfu_boot_evt_t
{
    uint32_t	version;
});

PACKSTRUCT(
struct ble_cmd_packet
{
	ble_header header;

union{
	uint8_t handle;

	ble_msg_system_reset_cmd_t                          system_reset_cmd;
	ble_msg_system_reg_write_cmd_t                      system_reg_write_cmd;
	ble_msg_system_reg_read_cmd_t                       system_reg_read_cmd;
	ble_msg_system_read_memory_cmd_t                    system_read_memory_cmd;
	ble_msg_system_endpoint_tx_cmd_t                    system_endpoint_tx_cmd;
	ble_msg_system_whitelist_append_cmd_t               system_whitelist_append_cmd;
	ble_msg_system_whitelist_remove_cmd_t               system_whitelist_remove_cmd;
	ble_msg_system_endpoint_rx_cmd_t                    system_endpoint_rx_cmd;
	ble_msg_system_endpoint_set_watermarks_cmd_t        system_endpoint_set_watermarks_cmd;
	ble_msg_system_aes_setkey_cmd_t                     system_aes_setkey_cmd;
	ble_msg_system_aes_encrypt_cmd_t                    system_aes_encrypt_cmd;
	ble_msg_system_aes_decrypt_cmd_t                    system_aes_decrypt_cmd;
	ble_msg_system_boot_evt_t                           system_boot_evt;
	ble_msg_system_debug_evt_t                          system_debug_evt;
	ble_msg_system_endpoint_watermark_rx_evt_t          system_endpoint_watermark_rx_evt;
	ble_msg_system_endpoint_watermark_tx_evt_t          system_endpoint_watermark_tx_evt;
	ble_msg_system_script_failure_evt_t                 system_script_failure_evt;
	ble_msg_system_protocol_error_evt_t                 system_protocol_error_evt;
	ble_msg_system_address_get_rsp_t                    system_address_get_rsp;
	ble_msg_system_reg_write_rsp_t                      system_reg_write_rsp;
	ble_msg_system_reg_read_rsp_t                       system_reg_read_rsp;
	ble_msg_system_get_counters_rsp_t                   system_get_counters_rsp;
	ble_msg_system_get_connections_rsp_t                system_get_connections_rsp;
	ble_msg_system_read_memory_rsp_t                    system_read_memory_rsp;
	ble_msg_system_get_info_rsp_t                       system_get_info_rsp;
	ble_msg_system_endpoint_tx_rsp_t                    system_endpoint_tx_rsp;
	ble_msg_system_whitelist_append_rsp_t               system_whitelist_append_rsp;
	ble_msg_system_whitelist_remove_rsp_t               system_whitelist_remove_rsp;
	ble_msg_system_endpoint_rx_rsp_t                    system_endpoint_rx_rsp;
	ble_msg_system_endpoint_set_watermarks_rsp_t        system_endpoint_set_watermarks_rsp;
	ble_msg_system_aes_encrypt_rsp_t                    system_aes_encrypt_rsp;
	ble_msg_system_aes_decrypt_rsp_t                    system_aes_decrypt_rsp;
	ble_msg_flash_ps_save_cmd_t                         flash_ps_save_cmd;
	ble_msg_flash_ps_load_cmd_t                         flash_ps_load_cmd;
	ble_msg_flash_ps_erase_cmd_t                        flash_ps_erase_cmd;
	ble_msg_flash_erase_page_cmd_t                      flash_erase_page_cmd;
	ble_msg_flash_write_data_cmd_t                      flash_write_data_cmd;
	ble_msg_flash_read_data_cmd_t                       flash_read_data_cmd;
	ble_msg_flash_ps_key_evt_t                          flash_ps_key_evt;
	ble_msg_flash_ps_save_rsp_t                         flash_ps_save_rsp;
	ble_msg_flash_ps_load_rsp_t                         flash_ps_load_rsp;
	ble_msg_flash_erase_page_rsp_t                      flash_erase_page_rsp;
	ble_msg_flash_write_data_rsp_t                      flash_write_data_rsp;
	ble_msg_flash_read_data_rsp_t                       flash_read_data_rsp;
	ble_msg_attributes_write_cmd_t                      attributes_write_cmd;
	ble_msg_attributes_read_cmd_t                       attributes_read_cmd;
	ble_msg_attributes_read_type_cmd_t                  attributes_read_type_cmd;
	ble_msg_attributes_user_read_response_cmd_t         attributes_user_read_response_cmd;
	ble_msg_attributes_user_write_response_cmd_t        attributes_user_write_response_cmd;
	ble_msg_attributes_send_cmd_t                       attributes_send_cmd;
	ble_msg_attributes_value_evt_t                      attributes_value_evt;
	ble_msg_attributes_user_read_request_evt_t          attributes_user_read_request_evt;
	ble_msg_attributes_status_evt_t                     attributes_status_evt;
	ble_msg_attributes_write_rsp_t                      attributes_write_rsp;
	ble_msg_attributes_read_rsp_t                       attributes_read_rsp;
	ble_msg_attributes_read_type_rsp_t                  attributes_read_type_rsp;
	ble_msg_attributes_send_rsp_t                       attributes_send_rsp;
	ble_msg_connection_disconnect_cmd_t                 connection_disconnect_cmd;
	ble_msg_connection_get_rssi_cmd_t                   connection_get_rssi_cmd;
	ble_msg_connection_update_cmd_t                     connection_update_cmd;
	ble_msg_connection_version_update_cmd_t             connection_version_update_cmd;
	ble_msg_connection_channel_map_get_cmd_t            connection_channel_map_get_cmd;
	ble_msg_connection_channel_map_set_cmd_t            connection_channel_map_set_cmd;
	ble_msg_connection_features_get_cmd_t               connection_features_get_cmd;
	ble_msg_connection_get_status_cmd_t                 connection_get_status_cmd;
	ble_msg_connection_raw_tx_cmd_t                     connection_raw_tx_cmd;
	ble_msg_connection_slave_latency_disable_cmd_t      connection_slave_latency_disable_cmd;
	ble_msg_connection_status_evt_t                     connection_status_evt;
	ble_msg_connection_version_ind_evt_t                connection_version_ind_evt;
	ble_msg_connection_feature_ind_evt_t                connection_feature_ind_evt;
	ble_msg_connection_raw_rx_evt_t                     connection_raw_rx_evt;
	ble_msg_connection_disconnected_evt_t               connection_disconnected_evt;
	ble_msg_connection_disconnect_rsp_t                 connection_disconnect_rsp;
	ble_msg_connection_get_rssi_rsp_t                   connection_get_rssi_rsp;
	ble_msg_connection_update_rsp_t                     connection_update_rsp;
	ble_msg_connection_version_update_rsp_t             connection_version_update_rsp;
	ble_msg_connection_channel_map_get_rsp_t            connection_channel_map_get_rsp;
	ble_msg_connection_channel_map_set_rsp_t            connection_channel_map_set_rsp;
	ble_msg_connection_features_get_rsp_t               connection_features_get_rsp;
	ble_msg_connection_get_status_rsp_t                 connection_get_status_rsp;
	ble_msg_connection_raw_tx_rsp_t                     connection_raw_tx_rsp;
	ble_msg_connection_slave_latency_disable_rsp_t      connection_slave_latency_disable_rsp;
	ble_msg_attclient_find_by_type_value_cmd_t          attclient_find_by_type_value_cmd;
	ble_msg_attclient_read_by_group_type_cmd_t          attclient_read_by_group_type_cmd;
	ble_msg_attclient_read_by_type_cmd_t                attclient_read_by_type_cmd;
	ble_msg_attclient_find_information_cmd_t            attclient_find_information_cmd;
	ble_msg_attclient_read_by_handle_cmd_t              attclient_read_by_handle_cmd;
	ble_msg_attclient_attribute_write_cmd_t             attclient_attribute_write_cmd;
	ble_msg_attclient_write_command_cmd_t               attclient_write_command_cmd;
	ble_msg_attclient_indicate_confirm_cmd_t            attclient_indicate_confirm_cmd;
	ble_msg_attclient_read_long_cmd_t                   attclient_read_long_cmd;
	ble_msg_attclient_prepare_write_cmd_t               attclient_prepare_write_cmd;
	ble_msg_attclient_execute_write_cmd_t               attclient_execute_write_cmd;
	ble_msg_attclient_read_multiple_cmd_t               attclient_read_multiple_cmd;
	ble_msg_attclient_indicated_evt_t                   attclient_indicated_evt;
	ble_msg_attclient_procedure_completed_evt_t         attclient_procedure_completed_evt;
	ble_msg_attclient_group_found_evt_t                 attclient_group_found_evt;
	ble_msg_attclient_attribute_found_evt_t             attclient_attribute_found_evt;
	ble_msg_attclient_find_information_found_evt_t      attclient_find_information_found_evt;
	ble_msg_attclient_attribute_value_evt_t             attclient_attribute_value_evt;
	ble_msg_attclient_read_multiple_response_evt_t      attclient_read_multiple_response_evt;
	ble_msg_attclient_find_by_type_value_rsp_t          attclient_find_by_type_value_rsp;
	ble_msg_attclient_read_by_group_type_rsp_t          attclient_read_by_group_type_rsp;
	ble_msg_attclient_read_by_type_rsp_t                attclient_read_by_type_rsp;
	ble_msg_attclient_find_information_rsp_t            attclient_find_information_rsp;
	ble_msg_attclient_read_by_handle_rsp_t              attclient_read_by_handle_rsp;
	ble_msg_attclient_attribute_write_rsp_t             attclient_attribute_write_rsp;
	ble_msg_attclient_write_command_rsp_t               attclient_write_command_rsp;
	ble_msg_attclient_indicate_confirm_rsp_t            attclient_indicate_confirm_rsp;
	ble_msg_attclient_read_long_rsp_t                   attclient_read_long_rsp;
	ble_msg_attclient_prepare_write_rsp_t               attclient_prepare_write_rsp;
	ble_msg_attclient_execute_write_rsp_t               attclient_execute_write_rsp;
	ble_msg_attclient_read_multiple_rsp_t               attclient_read_multiple_rsp;
	ble_msg_sm_encrypt_start_cmd_t                      sm_encrypt_start_cmd;
	ble_msg_sm_set_bondable_mode_cmd_t                  sm_set_bondable_mode_cmd;
	ble_msg_sm_delete_bonding_cmd_t                     sm_delete_bonding_cmd;
	ble_msg_sm_set_parameters_cmd_t                     sm_set_parameters_cmd;
	ble_msg_sm_passkey_entry_cmd_t                      sm_passkey_entry_cmd;
	ble_msg_sm_set_oob_data_cmd_t                       sm_set_oob_data_cmd;
	ble_msg_sm_set_pairing_distribution_keys_cmd_t      sm_set_pairing_distribution_keys_cmd;
	ble_msg_sm_smp_data_evt_t                           sm_smp_data_evt;
	ble_msg_sm_bonding_fail_evt_t                       sm_bonding_fail_evt;
	ble_msg_sm_passkey_display_evt_t                    sm_passkey_display_evt;
	ble_msg_sm_passkey_request_evt_t                    sm_passkey_request_evt;
	ble_msg_sm_bond_status_evt_t                        sm_bond_status_evt;
	ble_msg_sm_encrypt_start_rsp_t                      sm_encrypt_start_rsp;
	ble_msg_sm_delete_bonding_rsp_t                     sm_delete_bonding_rsp;
	ble_msg_sm_passkey_entry_rsp_t                      sm_passkey_entry_rsp;
	ble_msg_sm_get_bonds_rsp_t                          sm_get_bonds_rsp;
	ble_msg_sm_whitelist_bonds_rsp_t                    sm_whitelist_bonds_rsp;
	ble_msg_sm_set_pairing_distribution_keys_rsp_t      sm_set_pairing_distribution_keys_rsp;
	ble_msg_gap_set_privacy_flags_cmd_t                 gap_set_privacy_flags_cmd;
	ble_msg_gap_set_mode_cmd_t                          gap_set_mode_cmd;
	ble_msg_gap_discover_cmd_t                          gap_discover_cmd;
	ble_msg_gap_connect_direct_cmd_t                    gap_connect_direct_cmd;
	ble_msg_gap_connect_selective_cmd_t                 gap_connect_selective_cmd;
	ble_msg_gap_set_filtering_cmd_t                     gap_set_filtering_cmd;
	ble_msg_gap_set_scan_parameters_cmd_t               gap_set_scan_parameters_cmd;
	ble_msg_gap_set_adv_parameters_cmd_t                gap_set_adv_parameters_cmd;
	ble_msg_gap_set_adv_data_cmd_t                      gap_set_adv_data_cmd;
	ble_msg_gap_set_directed_connectable_mode_cmd_t     gap_set_directed_connectable_mode_cmd;
	ble_msg_gap_set_initiating_con_parameters_cmd_t     gap_set_initiating_con_parameters_cmd;
	ble_msg_gap_set_nonresolvable_address_cmd_t         gap_set_nonresolvable_address_cmd;
	ble_msg_gap_scan_response_evt_t                     gap_scan_response_evt;
	ble_msg_gap_mode_changed_evt_t                      gap_mode_changed_evt;
	ble_msg_gap_set_mode_rsp_t                          gap_set_mode_rsp;
	ble_msg_gap_discover_rsp_t                          gap_discover_rsp;
	ble_msg_gap_connect_direct_rsp_t                    gap_connect_direct_rsp;
	ble_msg_gap_end_procedure_rsp_t                     gap_end_procedure_rsp;
	ble_msg_gap_connect_selective_rsp_t                 gap_connect_selective_rsp;
	ble_msg_gap_set_filtering_rsp_t                     gap_set_filtering_rsp;
	ble_msg_gap_set_scan_parameters_rsp_t               gap_set_scan_parameters_rsp;
	ble_msg_gap_set_adv_parameters_rsp_t                gap_set_adv_parameters_rsp;
	ble_msg_gap_set_adv_data_rsp_t                      gap_set_adv_data_rsp;
	ble_msg_gap_set_directed_connectable_mode_rsp_t     gap_set_directed_connectable_mode_rsp;
	ble_msg_gap_set_initiating_con_parameters_rsp_t     gap_set_initiating_con_parameters_rsp;
	ble_msg_gap_set_nonresolvable_address_rsp_t         gap_set_nonresolvable_address_rsp;
	ble_msg_hardware_io_port_config_irq_cmd_t           hardware_io_port_config_irq_cmd;
	ble_msg_hardware_set_soft_timer_cmd_t               hardware_set_soft_timer_cmd;
	ble_msg_hardware_adc_read_cmd_t                     hardware_adc_read_cmd;
	ble_msg_hardware_io_port_config_direction_cmd_t     hardware_io_port_config_direction_cmd;
	ble_msg_hardware_io_port_config_function_cmd_t      hardware_io_port_config_function_cmd;
	ble_msg_hardware_io_port_config_pull_cmd_t          hardware_io_port_config_pull_cmd;
	ble_msg_hardware_io_port_write_cmd_t                hardware_io_port_write_cmd;
	ble_msg_hardware_io_port_read_cmd_t                 hardware_io_port_read_cmd;
	ble_msg_hardware_spi_config_cmd_t                   hardware_spi_config_cmd;
	ble_msg_hardware_spi_transfer_cmd_t                 hardware_spi_transfer_cmd;
	ble_msg_hardware_i2c_read_cmd_t                     hardware_i2c_read_cmd;
	ble_msg_hardware_i2c_write_cmd_t                    hardware_i2c_write_cmd;
	ble_msg_hardware_set_txpower_cmd_t                  hardware_set_txpower_cmd;
	ble_msg_hardware_timer_comparator_cmd_t             hardware_timer_comparator_cmd;
	ble_msg_hardware_io_port_irq_enable_cmd_t           hardware_io_port_irq_enable_cmd;
	ble_msg_hardware_io_port_irq_direction_cmd_t        hardware_io_port_irq_direction_cmd;
	ble_msg_hardware_analog_comparator_enable_cmd_t     hardware_analog_comparator_enable_cmd;
	ble_msg_hardware_analog_comparator_config_irq_cmd_t hardware_analog_comparator_config_irq_cmd;
	ble_msg_hardware_set_rxgain_cmd_t                   hardware_set_rxgain_cmd;
	ble_msg_hardware_usb_enable_cmd_t                   hardware_usb_enable_cmd;
	ble_msg_hardware_sleep_enable_cmd_t                 hardware_sleep_enable_cmd;
	ble_msg_hardware_io_port_status_evt_t               hardware_io_port_status_evt;
	ble_msg_hardware_soft_timer_evt_t                   hardware_soft_timer_evt;
	ble_msg_hardware_adc_result_evt_t                   hardware_adc_result_evt;
	ble_msg_hardware_analog_comparator_status_evt_t     hardware_analog_comparator_status_evt;
	ble_msg_hardware_io_port_config_irq_rsp_t           hardware_io_port_config_irq_rsp;
	ble_msg_hardware_set_soft_timer_rsp_t               hardware_set_soft_timer_rsp;
	ble_msg_hardware_adc_read_rsp_t                     hardware_adc_read_rsp;
	ble_msg_hardware_io_port_config_direction_rsp_t     hardware_io_port_config_direction_rsp;
	ble_msg_hardware_io_port_config_function_rsp_t      hardware_io_port_config_function_rsp;
	ble_msg_hardware_io_port_config_pull_rsp_t          hardware_io_port_config_pull_rsp;
	ble_msg_hardware_io_port_write_rsp_t                hardware_io_port_write_rsp;
	ble_msg_hardware_io_port_read_rsp_t                 hardware_io_port_read_rsp;
	ble_msg_hardware_spi_config_rsp_t                   hardware_spi_config_rsp;
	ble_msg_hardware_spi_transfer_rsp_t                 hardware_spi_transfer_rsp;
	ble_msg_hardware_i2c_read_rsp_t                     hardware_i2c_read_rsp;
	ble_msg_hardware_i2c_write_rsp_t                    hardware_i2c_write_rsp;
	ble_msg_hardware_timer_comparator_rsp_t             hardware_timer_comparator_rsp;
	ble_msg_hardware_io_port_irq_enable_rsp_t           hardware_io_port_irq_enable_rsp;
	ble_msg_hardware_io_port_irq_direction_rsp_t        hardware_io_port_irq_direction_rsp;
	ble_msg_hardware_analog_comparator_read_rsp_t       hardware_analog_comparator_read_rsp;
	ble_msg_hardware_analog_comparator_config_irq_rsp_t hardware_analog_comparator_config_irq_rsp;
	ble_msg_hardware_usb_enable_rsp_t                   hardware_usb_enable_rsp;
	ble_msg_hardware_sleep_enable_rsp_t                 hardware_sleep_enable_rsp;
	ble_msg_test_phy_tx_cmd_t                           test_phy_tx_cmd;
	ble_msg_test_phy_rx_cmd_t                           test_phy_rx_cmd;
	ble_msg_test_debug_cmd_t                            test_debug_cmd;
	ble_msg_test_channel_mode_cmd_t                     test_channel_mode_cmd;
	ble_msg_test_phy_end_rsp_t                          test_phy_end_rsp;
	ble_msg_test_get_channel_map_rsp_t                  test_get_channel_map_rsp;
	ble_msg_test_debug_rsp_t                            test_debug_rsp;
	ble_msg_dfu_reset_cmd_t                             dfu_reset_cmd;
	ble_msg_dfu_flash_set_address_cmd_t                 dfu_flash_set_address_cmd;
	ble_msg_dfu_flash_upload_cmd_t                      dfu_flash_upload_cmd;
	ble_msg_dfu_boot_evt_t                              dfu_boot_evt;
	ble_msg_dfu_flash_set_address_rsp_t                 dfu_flash_set_address_rsp;
	ble_msg_dfu_flash_upload_rsp_t                      dfu_flash_upload_rsp;
	ble_msg_dfu_flash_upload_finish_rsp_t               dfu_flash_upload_finish_rsp;

	uint8_t payload[128];/*TODO: fix this for getting command size larger*/
};

}ALIGNED);

} // namespace bglib


#ifdef ALIGNED
#undef ALIGNED
#endif
#undef PACKSTRUCT
