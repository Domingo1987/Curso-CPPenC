#include <stdio.h>
#include <windows.h>

int main() {
    // Obtener el ID del proceso actual
    DWORD pid = GetCurrentProcessId();
    
    // Obtener el handle del proceso actual
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
    
    // Obtener el ID del proceso padre
    DWORD ppid;
    GetProcessId(GetProcessParentProcessId(hProcess, &ppid));
    
    // Imprimir el ID del proceso padre
    printf("El ID del proceso padre es: %d\n", ppid);
    
    // Cerrar el handle del proceso actual
    CloseHandle(hProcess);
    
    return 0;
}
