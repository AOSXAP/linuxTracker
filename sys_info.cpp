#include <iostream>
#include <sys/utsname.h>
#include <iomanip>
#include <fstream>

//LINUX GENERAL SYSTEM AND KERNEL INFO

class linuxInfo
{
private:
    struct utsname uts;

public:
    linuxInfo()
    {
        uname(&uts);
    }

    void KAV()
    {
        //kernel and version
        std::cout << uts.sysname << " " << uts.release << " ";
    }

    void Arhitecture()
    {
        //arhitecture
        std::cout << uts.machine << " ";
    }

    void distroName()
    {
        //use command and store output in temp.txt
        system("cat /etc/os-release | grep -w 'NAME' > temp.txt");

        //init file and read everything from it
        std::ifstream f("temp.txt");

        std::string str((std::istreambuf_iterator<char>(f)),
                        std::istreambuf_iterator<char>());

        //close stream , remove the file and format output
        f.close();
        remove("temp.txt");
        std::cout << str.erase(0, 5);
    }
};

//UPTIME , RAM , NUMBER OF PROCESSES

#include <sys/sysinfo.h>

class sysInfo
{
public:
    struct sysinfo info;

    struct impSysInfo
    {
        unsigned long totalram;
        unsigned long procs;
        long uptime;
    };
    sysInfo()
    {
        sysinfo(&info);
    }

    void uptime(int s)
    {
        //seconds to time
        int minutes = 0, hours = 0;

        minutes = s / 60, s -= (minutes * 60);

        hours = minutes / 60, minutes -= (hours * 60);

        std::cout << hours << " hours " << minutes << " minutes " << s << " seconds ";
    }

    impSysInfo getValues()
    {
        impSysInfo Container;

        Container.totalram = info.totalram;

        Container.procs = info.procs, Container.uptime = info.uptime;

        return Container;
    }
};

/*
int main()
{


    sysInfo sysInfox;

    sysInfox.uptime(sysInfox.info.uptime);

    sysInfo::impSysInfo Container = sysInfox.getValues();

    std::cout << std::endl
              << Container.totalram << " " << Container.procs << " " << Container.uptime;
}
*/