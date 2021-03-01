//
// Bluegiga’s Bluetooth Smart Demo Application
// Contact: support@bluegiga.com.
//
// This is free software distributed under the terms of the MIT license reproduced below.
//
// Copyright (c) 2012, Bluegiga Technologies
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

#include "../bglib++/cmd_def.hpp"

class ScanExample : public bglib::ble
{
public:
    void init(int serial_handle)
    {
        this->serial_handle = serial_handle;

        //stop previous operation
        cmd_gap_end_procedure();

        //get connection status,current command will be handled in response
        cmd_connection_get_status(0);
    }

    void evt_connection_status(const struct bglib::ble_msg_connection_status_evt_t *msg)
    {
        if(msg->flags&bglib::connection_connected)
        {
            printf("#connected -> disconnect\n");
            cmd_connection_disconnect(msg->connection);
        }else
        {
            printf("#Not connected -> Scan\n");
            cmd_gap_discover(1);
        }
    }
    
    void evt_connection_disconnected(const struct bglib::ble_msg_connection_disconnected_evt_t *msg)
    {
        cmd_connection_get_status(0);
    }
    
    void evt_gap_scan_response(const struct bglib::ble_msg_gap_scan_response_evt_t *msg)
    {
        int i;
        for(i=0;i<6;i++)
            printf("%02x%s",msg->sender.addr[5-i],i<5?":":"");
        printf("\t%d\n",msg->rssi);
    }

    int read_message()
    {
        int rread;
        const struct bglib::ble_msg *apimsg;
        struct bglib::ble_header apihdr;
        unsigned char data[256];//enough for BLE
        //read header
    
        if((rread = read(serial_handle, (unsigned char*)&apihdr, 4)) != 4)
            {
                return rread;
            }
        //read rest if needed
        if(apihdr.lolen)
        {
            if((rread = read(serial_handle, 
                       data,
                       apihdr.lolen)) != apihdr.lolen)
                {
                    return rread;
                }
        }
        apimsg=ble_get_msg_hdr(apihdr);
        if(!apimsg)
        {
            printf("ERROR: Message not found:%d:%d\n",(int)apihdr.cls,(int)apihdr.command);
            return -1;
        }
        (this->*(apimsg->handler))(data);
    
        return 0;
    }

    void run()
    {
        //Message loop
        while(1)
        {
            if(read_message())
            {
                printf("Error reading message\n");
                break;
            }
        }
    }

    void output(uint8 len1,uint8* data1,uint16 len2,uint8* data2)
    {
        int result;
        if((result = write(serial_handle, data1, len1)) != len1)
            {
                printf("ERROR: Writing data. %d\n",result);
                exit(-1);
            }
    
        if((result = write(serial_handle, data2, len2)) != len2)
            {
                printf("ERROR: Writing data. %d\n",result);
                exit(-1);
            }
    }

    int serial_handle;
} scanexample;


void print_help()
{
    printf("Demo application to scan devices\n");
    printf("\tscan_example\tCOM-port\n");
}

int main(int argc, char *argv[] )
{    
    //char str[80];

    if(argc<2)
    {
        print_help();
        exit(-1);
    }
    //snprintf(str,sizeof(str)-1,"\\\\.\\%s",argv[1]);
    int serial_handle = open(argv[1], O_RDWR | O_NOCTTY);


    if (serial_handle < 0)
    {
        printf("Error opening serialport %s. %s\n",argv[1],strerror(errno));
        return -1;
    }

    struct termios options;
    tcgetattr (serial_handle, &options);
    cfsetispeed (&options, B230400);
    cfsetospeed (&options, B230400);

    options.c_cflag &= ~(PARENB | CSTOPB | CSIZE | CRTSCTS | HUPCL);
    options.c_cflag |= (CS8 | CLOCAL | CREAD);
    options.c_lflag &=
        ~(ICANON | ISIG | ECHO | ECHOE | ECHOK | ECHONL | ECHOCTL | ECHOPRT | ECHOKE | IEXTEN);
    options.c_iflag &= ~(INPCK | IXON | IXOFF | IXANY | ICRNL);
    options.c_oflag &= ~(OPOST | ONLCR);

    for (int i = 0; i < sizeof (options.c_cc); i++)
        options.c_cc[i] = _POSIX_VDISABLE;

    options.c_cc[VTIME] = 0;
    options.c_cc[VMIN] = 1;
    
    tcsetattr (serial_handle, TCSAFLUSH, &options);

    scanexample.init(serial_handle);

    scanexample.run();

    return 0;
}
