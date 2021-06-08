#include "cpu_usage.h"
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <vector>
#include <bits/stdc++.h>
#include <unistd.h> // sleep()

namespace helper
{
    void stringCounter(int &c, char x[])
    {
        while (x[c] != '\0')
            c++;
    }

    void concateArray(char x[], int i, int j)
    {
        for (int m = 0; m < 5; m++)
        {
            for (int index = 0; index <= j; ++index)
                x[index] = x[index + 1];
        }
    }

    Vals monitor()
    {

        //init and concate char array
        FILE *fp = fopen("/proc/stat", "r");
        char str[100];
        fgets(str, 100, fp);
        fclose(fp);
        int c = 0, sum = 0, idle = 0;
        stringCounter(c, str);
        concateArray(str, 0, c);

        //init stats array and convert chars to int
        char *token;
        const size_t stat_count = 11;
        int stats[stat_count];
        size_t current_stat = 0;

        token = strtok(str, " ");

        while (token != NULL)
        {
            // std::cout << "  Processing token " << current_stat << ": '" << std::string(token) << "'\n";
            int i = atoi(token);
            stats[current_stat] = i;
            token = strtok(NULL, " ");
            current_stat++;
            // Prevent writing to invalid memory.
            if (current_stat == stat_count)
            {
                printf("Stat token count exceeds allocated memory.\n");
                exit(1);
                break;
            }
        }

        //calculate usage
        for (int index = 0; index < 10; index++)
        {
            sum += stats[index];
            if (index == 3)
                idle = stats[index];
        }

        const double d_idle = idle;
        const double d_sum = sum;
        const Vals valx = {d_idle, d_sum};

        return valx;
    }

    void cpuTracker()
    {
        int iteration = 0;
        helper::Vals last_monitor = helper::monitor();
        
        // Make space for the 'usage' line.
        printf( "\n" );

        for (;;)
        {
            helper::Vals monitor1 = helper::monitor();

            const double idle_delta = last_monitor.val1 - monitor1.val1;
            const double total_delta = last_monitor.val2 - monitor1.val2;

            printf("\e[AUsage percent: %f (%i)\n", 100.0 * (1.0 - idle_delta / total_delta), iteration);
            last_monitor = monitor1;
            iteration++;
            sleep(1); // Sleep for one second.
        }
    }
}