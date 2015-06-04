/**********************************************************************
 * 
 *  Toby Opferman
 *
 *  Example Dynamic Loading a Driver
 *
 *  This example is for educational purposes only.  I license this source
 *  out for use in learning how to write a device driver.
 *
 *    
 **********************************************************************/


#include <windows.h>
#include <stdio.h>

/*********************************************************
 *   Main Function Entry
 *
 *********************************************************/
int _cdecl main(void)
{
    HANDLE hSCManager;
    HANDLE hService;
    SERVICE_STATUS ss;

    hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
    
    printf("Load Driver\n");

    if(hSCManager)
    {
        printf("Create Service\n");

        hService = CreateService(hSCManager, TEXT("Example"), TEXT("Example Driver")
			, SERVICE_START | DELETE | SERVICE_STOP, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE
			, TEXT("C:\\Users\\yongyang\\Documents\\GitHub\\Sample\\DriverSample\\FromCodeProject\\DriverDevelopmentSerial\\Part1\\Debug\\example.sys"), NULL, NULL, NULL, NULL, NULL);

        if(!hService)
        {
            hService = OpenService(hSCManager, TEXT("Example"), SERVICE_START | DELETE | SERVICE_STOP);
        }

        if(hService)
        {
            printf("Start Service\n");

            StartService(hService, 0, NULL);
            printf("Press Enter to close service\r\n");
            getchar();
            ControlService(hService, SERVICE_CONTROL_STOP, &ss);
            DeleteService(hService);
        }

        CloseServiceHandle(hSCManager);
    }
    
    return 0;
}


