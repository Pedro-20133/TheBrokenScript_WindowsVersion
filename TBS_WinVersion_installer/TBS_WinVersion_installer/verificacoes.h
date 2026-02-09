#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <intrin.h>
#include <cstring>

namespace fs = std::filesystem;

inline bool esta_no_win() {
#ifdef _WIN32
    return true;
#else
    return false;
#endif
}

inline bool esta_numa_vm() {
    int cpuInfo[4];
    // 1. Checagem básica do bit de Hypervisor
    __cpuid(cpuInfo, 1);
    if (!(cpuInfo[2] & (1 << 31))) return false;

    // 2. Checagem da Assinatura do Hypervisor (Leaf 0x40000000)
    __cpuid(cpuInfo, 0x40000000);

    char vendor[13];
    memcpy(vendor + 0, &cpuInfo[1], 4); // EBX
    memcpy(vendor + 4, &cpuInfo[2], 4); // ECX
    memcpy(vendor + 8, &cpuInfo[3], 4); // EDX
    vendor[12] = '\0';

    std::string s_vendor = vendor;

    // Lista branca baseada no seu README: VirtualBox, VMware e QEMU (KVM)
    // Nota: "Microsoft Hv" é ignorado para evitar rodar no seu PC real com Hyper-V ativo
    if (s_vendor == "VBoxVBoxVBox" || // Oracle VM VirtualBox
        s_vendor == "VMwareVMware" || // VMware Workstation
        s_vendor == "KVMKVMKVM" || // QEMU (KVM)
        s_vendor == "TCGTCGTCGTCG")   // QEMU (TCG)
    {
        return true;
    }

    return false;
}

inline bool dependencias() {
    // Busca os arquivos no diretório onde o instalador está rodando
    return fs::exists("Resources") && fs::exists("TBS_WinVersion.exe");
}

inline std::vector<std::string> verificacoes_gerais() {
    std::vector<std::string> falhas;

    if (!esta_no_win()) falhas.push_back("Incompatível: Requer Windows.");
    if (!esta_numa_vm()) falhas.push_back("SEGURANÇA: VM não detectada. Hardware real detectado!");
    if (!dependencias()) falhas.push_back("Arquivos ausentes: Resources ou TBS_WinVersion.exe.");

    return falhas;
}