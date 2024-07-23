#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    fstream f;
    f.open("output.txt", ios::out);

    clock_t startTime;
    long int freeBytes;
    int freePage;
    int freeVirtual;

    MEMORYSTATUS MemoryInfo;
    GlobalMemoryStatus(&MemoryInfo);
    freeBytes = MemoryInfo.dwAvailPhys;
    freePage = MemoryInfo.dwAvailPageFile;
    freeVirtual = MemoryInfo.dwAvailVirtual;

    cout << "Available Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
    cout << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
    cout << "Available Virtual Memory: " << MemoryInfo.dwAvailVirtual << endl;

    f << "Available Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
    f << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
    f << "Available Virtual Memory: " << MemoryInfo.dwAvailVirtual << endl;

    double Cache_size[15] = { 0.5, 0.6, 0.7, 0.8, 0.9, 0.95, 0.99, 1.0, 1.01, 1.1, 1.5, 2, 5, 10, 50 };
    long int num_of_Bytes;
    int* num_array;

    for (int i = 0; i < 15; i++)
    {
        cout << "Cache Size: " << Cache_size[i] << "*M" << endl;
        f << "Cache Size: " << Cache_size[i] << "*M" << endl;

        startTime = clock();
        num_of_Bytes = abs((int)(Cache_size[i] * (freeBytes)));

        int size = num_of_Bytes / sizeof(int);
        num_array = new int[size];

        GlobalMemoryStatus(&MemoryInfo);

        cout << "Available Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
        cout << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
        cout << "Available Virtual Memory: " << MemoryInfo.dwAvailVirtual << endl;

        f << "Available Physical Memory: " << MemoryInfo.dwAvailPhys << endl;
        f << "Available Page File: " << MemoryInfo.dwAvailPageFile << endl;
        f << "Available Virtual Memory: " << MemoryInfo.dwAvailVirtual << endl;

        for (int i = 0; i < size; i++)
        {
            num_array[i] = i;
        }

        for (int i = 0; i < size; i++)
        {
            num_array[i] += i;
        }

        delete[] num_array;

        cout << "Time elapsed: " << ((double)(clock() - startTime) / (double)CLOCKS_PER_SEC) << " seconds " << endl;
        f << "Time elapsed: " << ((double)(clock() - startTime) / (double)CLOCKS_PER_SEC) << " seconds " << endl;
    }

    f.close();

    system("pause");
    return 0;
}
/*Output
Output:
Available Physical Memory: 22287347712
Available Page File: 17866129408
Available Virtual Memory: 140733103943680
Cache Size: 0.5*M

Available Physical Memory: 21870755840
Available Page File: 17459245056
Available Virtual Memory: 140732697620480
Time elapsed: 0.679 seconds
Cache Size: 0.6*M

Available Physical Memory: 21805023232
Available Page File: 17414365184
Available Virtual Memory: 140732616392704
Time elapsed: 0.855 seconds
Cache Size: 0.7*M

Available Physical Memory: 21653893120
Available Page File: 17245097984
Available Virtual Memory: 140732535152640
Time elapsed: 1.14 seconds
Cache Size: 0.8*M

Available Physical Memory: 21575061504
Available Page File: 17162346496
Available Virtual Memory: 140732453912576
Time elapsed: 1.329 seconds
Cache Size: 0.9*M

Available Physical Memory: 21494538240
Available Page File: 17098399744
Available Virtual Memory: 140732372615168
Time elapsed: 1.54 seconds
Cache Size: 0.95*M

Available Physical Memory: 21479731200
Available Page File: 17082793984
Available Virtual Memory: 140732332040192
Time elapsed: 1.597 seconds
Cache Size: 0.99*M

Available Physical Memory: 21446746112
Available Page File: 17053081600
Available Virtual Memory: 140732299497472
Time elapsed: 1.672 seconds
Cache Size: 1*M

Available Physical Memory: 21440892928
Available Page File: 17041469440
Available Virtual Memory: 140732291391488
Time elapsed: 1.68 seconds
Cache Size: 1.01*M

Available Physical Memory: 21440073728
Available Page File: 17028513792
Available Virtual Memory: 140732283260928
Time elapsed: 1.699 seconds
Cache Size: 1.1*M

Available Physical Memory: 21383577600
Available Page File: 16970248192
Available Virtual Memory: 140732210122752
Time elapsed: 1.816 seconds
Cache Size: 1.5*M

Available Physical Memory: 21086740480
Available Page File: 16680374272
Available Virtual Memory: 140731885113344
Time elapsed: 2.557 seconds
Cache Size: 2*M

Available Physical Memory: 20679503872
Available Page File: 16269254656
Available Virtual Memory: 140731478913024
Time elapsed: 3.36 seconds
Cache Size: 5*M
*/
