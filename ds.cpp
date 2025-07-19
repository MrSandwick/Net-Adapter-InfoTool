#include <iostream>
#include <winsock2.h>
#include <iphlpapi.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

int main() {
    PMIB_IFTABLE pIfTable = NULL;
    DWORD dwSize = 0;
    DWORD dwRetVal = 0;

    // First call to get buffer size
    if (GetIfTable(NULL, &dwSize, TRUE) != ERROR_INSUFFICIENT_BUFFER) {
        std::cerr << "Error getting buffer size\n";
        return 1;
    }

    // Allocate memory
    pIfTable = (PMIB_IFTABLE)malloc(dwSize);
    if (!pIfTable) {
        std::cerr << "Memory allocation failed\n";
        return 1;
    }

    // Second call to get data
    if ((dwRetVal = GetIfTable(pIfTable, &dwSize, TRUE)) != NO_ERROR) {
        std::cerr << "GetIfTable failed: " << dwRetVal << "\n";
        free(pIfTable);
        return 1;
    }

    // Print results
    std::cout << "Found " << pIfTable->dwNumEntries << " interfaces:\n";
    for (DWORD i = 0; i < pIfTable->dwNumEntries; i++) {
        std::cout << "Interface " << i+1 << ":\n"
                  << "  Name: " << pIfTable->table[i].wszName << "\n"
                  << "  Type: " << pIfTable->table[i].dwType << "\n"
                  << "  Received: " << pIfTable->table[i].dwInOctets << " bytes\n"
                  << "  Sent: " << pIfTable->table[i].dwOutOctets << " bytes\n\n";
    }

    free(pIfTable);
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    return 0;
}