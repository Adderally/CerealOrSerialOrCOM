#include "flashgod.h"



inline HANDLE
return_COMfilehandle() {

    HANDLE serial = CreateFileA(
        "COM1",                     //      Default for now, need to find a way to replace this with 
                                    //      The port a certain modem is using ...

        GENERIC_WRITE,
        0,
        0,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        0
    );

    return serial;
}




inline bool 
is_COMconfigSetup() {

    SecureZeroMemory(&serial_conf, sizeof(DCB));
    serial_conf.DCBlength = sizeof(serial_conf);

    if (GetCommState(return_COMfilehandle, &serial_conf)) {


        serial_conf.BaudRate = CBR_9600;
        serial_conf.ByteSize = 8;
        serial_conf.StopBits = TWOSTOPBITS;
        serial_conf.Parity   = 0;

        return TRUE;
    }
    else
        return FALSE;
}




HANDLE
return_file_for_reading(const char* file) {

    DWORD err;

    
    HANDLE file_for_reading = CreateFileA(
        file,
        GENERIC_READ,               //      * We just need the minimum ...

        0,                          //      Not that this will happen, but incase another process 
                                    //      is trying to modify data we entend to write 
                                    //      elsewhere, this will stay 0 ( ZERO ).
        0,
        OPEN_EXISTING,              //      *
        FILE_ATTRIBUTE_NORMAL,      //      *
        0
    );
    err = ::GetLastError();




    if (err == 2)                   //      File does not exist.
        return;                     



        
    return file_for_reading;        //      This return is our file / data we will be writing to a specific
                                    //      COM port ( In the future ).
}








int main()
{

    FBRAIN brain = { 0 };
    const char* file = "file";
    bool is_write;

    brain.max_bytes_to_read = GetFileSize(return_file_for_reading(file), NULL);

    if (is_COMconfigSetup)

        if (SetCommState(return_COMfilehandle, &serial_conf)) 

            /* Afer some Warzone games ill finish this part Lolol */
         
}

