# Network Adapter Information Tool

A lightweight Windows utility to list network interfaces and their traffic statistics, using the Windows IP Helper API.

## Features

- Lists all network interfaces (Ethernet, Wi-Fi, virtual adapters)
- Shows bytes sent/received for each interface
- Displays interface names and types
- Requires no external dependencies (uses built-in Windows APIs)

## Prerequisites

- Windows 7 or later
- MinGW-w64 or Visual Studio (for compilation)
- Administrator privileges (for accurate interface data)

## Installation

### Option 1: Precompiled Binary
1. Download `ds.exe` from Releases (if exist)
2. Run in Command Prompt/PowerShell (as Admin)

### Option 2: Compile from Source
```bash
# Install compiler (if needed)
choco install mingw -y
```
## Compile
```bash
g++ adapter_info.cpp -o adapter_info.exe -liphlpapi -lws2_32
```

## Usage

### Run normally (may miss some interfaces)
```bash
.\adapter_info.exe
```

### Run as Administrator (recommended for complete data)
```bash
Start-Process powershell -Verb RunAs -ArgumentList "-NoExit", "-Command", "cd '$pwd'; .\adapter_info.exe"
```

## Sample Output
```bash
Found 4 interfaces:

Interface 1:
  Name: Ethernet0
  Type: 6 (Ethernet)
  Received: 12582912 bytes
  Sent: 4194304 bytes

Interface 2:
  Name: Wi-Fi0
  Type: 71 (Wireless)
  Received: 67108864 bytes
  Sent: 33554432 bytes
```