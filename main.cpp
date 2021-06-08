#include <iostream>

#include "cpu_usage.h"
#include "sys_info.h"

int main()
{

    sysInfo sysInfox;

    sysInfo::impSysInfo Container = sysInfox.getValues();
    const std::string NiceUptime = sysInfox.uptime(sysInfox.info.uptime);
    
    printf( "Total ram:       %lu\n", Container.totalram );
    printf( "Total processes: %lu\n", Container.procs );
    printf( "Uptime:          %ld\n", Container.uptime );
    printf( "Nice uptime:     %s\n",  NiceUptime.c_str() );
    printf( "\n" );


    helper::cpuTracker();

    
}
