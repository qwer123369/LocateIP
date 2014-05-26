#include <stdio.h>
#include "cz_update.h"
#include "cz_update.c"
#include "loci.c"
#include "qqwry.c"

//#include <windows.h>
uint8_t* readfile(const char *path, uint32_t *length)
{
    FILE *fp = fopen(path, "rb");
    if(fp)
    {
        fseek(fp, 0, SEEK_END);
        *length = ftell(fp);
        uint8_t* buffer = (uint8_t*)malloc(*length);

        fseek(fp, 0, SEEK_SET);
        fread(buffer, *length, 1, fp);
        fclose(fp);
        return buffer;
    }
    /*
    HANDLE hfile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if(hfile!=INVALID_HANDLE_VALUE)
    {
        *length = GetFileSize(hfile, NULL);

        HANDLE hfilemap = CreateFileMapping(hfile, NULL, PAGE_READONLY, 0, 0, NULL);
        CloseHandle(hfile);

        const uint8_t* buffer = (const uint8_t*) MapViewOfFile(hfilemap, FILE_MAP_READ, 0, 0, 0);
        CloseHandle(hfilemap);
        return buffer;
    }
    */
    return 0;
}


int main()
{
    uint32_t length = 0;
    uint8_t *buffer = readfile("qqwry.dat", &length);
    loci *qqwry = qqwry_create(buffer, length);
    printf("%d %d\n", qqwry->count, qqwry->date);

    //loci_dump(qqwry, "1.txt");

    loci_item item;
    loci_find(qqwry, &item, "112.121.182.84");

    char ip1[16];
    char ip2[16];

    char *ip1_t = ip2str(ip1, sizeof(ip1), item.lower);
    char *ip2_t = ip2str(ip2, sizeof(ip2), item.upper);
    printf("%-16s%-16s%s%s%s\r\n", ip1_t, ip2_t, item.zone, strlen(item.area)>0?" ":"", item.area);

    free(buffer);
    loci_release(qqwry);
    //getchar();
    return 0;
}
