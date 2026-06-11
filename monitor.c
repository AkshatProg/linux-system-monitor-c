#include <stdio.h>
#include <string.h>

/*
 * Reads CPU model information from /proc/cpuinfo
 */
void get_cpu_info()
{
    FILE *fp;
    char line[256];
    char cpu_name[128];

    fp = fopen("/proc/cpuinfo", "r");

    if (fp == NULL)
    {
        printf("Failed to open /proc/cpuinfo\n");
        return;
    }

    // Read file line by line
    while (fgets(line, sizeof(line), fp))
    {
        // Look for the line starting with "model name"
        if (strncmp(line, "model name", 10) == 0)
        {
            /*
             * Example line:
             * model name : AMD Ryzen 5 7235HS
             *
             * Extract only:
             * AMD Ryzen 5 7235HS
             */
            sscanf(line, "model name : %[^\n]", cpu_name);

            printf("%s\n", cpu_name);
            break;
        }
    }

    fclose(fp);
}

/*
 * Reads memory information from /proc/meminfo
 */
void get_memory_info()
{
    long total_memory = 0;
    long free_memory = 0;

    FILE *fp;
    char line[256];

    fp = fopen("/proc/meminfo", "r");

    if (fp == NULL)
    {
        printf("Failed to open /proc/meminfo\n");
        return;
    }

    // Read file line by line
    while (fgets(line, sizeof(line), fp))
    {
        // Extract total memory
        if (strncmp(line, "MemTotal", 8) == 0)
        {
            sscanf(line, "MemTotal: %ld kB", &total_memory);
        }

        // Extract free memory
        if (strncmp(line, "MemFree", 7) == 0)
        {
            sscanf(line, "MemFree: %ld kB", &free_memory);
            break;
        }
    }

    fclose(fp);

    // Calculate used memory
    long used_memory = total_memory - free_memory;

    // Convert kB to MB
    double total_mb = total_memory / 1024.0;
    double free_mb = free_memory / 1024.0;
    double used_mb = used_memory / 1024.0;

    printf("Total Memory : %.2f MB\n", total_mb);
    printf("Free Memory  : %.2f MB\n", free_mb);
    printf("Used Memory  : %.2f MB\n", used_mb);
}

/*
 * Reads uptime information from /proc/uptime
 */
void get_uptime_info()
{
    FILE *fp;
    double uptime_seconds;

    fp = fopen("/proc/uptime", "r");

    if (fp == NULL)
    {
        printf("Failed to open /proc/uptime\n");
        return;
    }

    /*
     * Example:
     * 4256.78 12345.90
     *
     * First value = uptime in seconds
     */
    fscanf(fp, "%lf", &uptime_seconds);

    fclose(fp);

    int hours = (int)uptime_seconds / 3600;
    int minutes = ((int)uptime_seconds % 3600) / 60;

    printf("%d hours %d minutes\n", hours, minutes);
}

int main()
{
    printf("=====================================\n");
    printf("      Linux System Monitor v1\n");
    printf("=====================================\n\n");

    printf("CPU Information\n");
    printf("-----------------------------\n");
    get_cpu_info();

    printf("\n");

    printf("Memory Information\n");
    printf("-----------------------------\n");
    get_memory_info();

    printf("\n");

    printf("System Uptime\n");
    printf("-----------------------------\n");
    get_uptime_info();

    printf("\n=====================================\n");

    return 0;
}