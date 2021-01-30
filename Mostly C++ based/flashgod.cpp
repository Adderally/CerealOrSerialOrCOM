#include "flashgod.h"



HANDLE
return_COMfilehandle() {

    HANDLE serial = CreateFileA(
        "COM1",     //      Default for now, need to find a way to replace this with 
                    //      The port a certain modem is using ...

        GENERIC_READ | GENERIC_WRITE,
        0,
        0,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        0
    );

    return serial;
}




bool 
is_COMconfigSetup() {

    SecureZeroMemory(&serial_conf, sizeof(DCB));    //  Zero-out
    serial_conf.DCBlength = sizeof(serial_conf);

    if (GetCommState(return_COMfilehandle, &serial_conf)) {

        /* Build ...    //     just the defaults listed in COM1 prop*/

        serial_conf.BaudRate = CBR_9600;
        serial_conf.ByteSize = 8;
        serial_conf.StopBits = TWOSTOPBITS;
        serial_conf.Parity   = 0;

        return TRUE;
    }
    else
        return FALSE;
}




int main()
{
    if(is_COMconfigSetup)

        if (SetCommState(return_COMfilehandle, &serial_conf)) {

            //  TODO
        }
}

