# 👁️ The BrokenScript: Windows Version

> **"O sistema não está apenas processando dados. Ele está observando você."**

**The BrokenScript** é uma experiência de terror psicológico imersiva baseada em software, inspirada no conceito original do mod *Broken Script* para Minecraft. Ao contrário de um software comum, este programa evolui silenciosamente ao longo de **180 dias**, simulando um estado de paranoia digital e degradação sistêmica.

---

## ⚠️ AVISO DE SEGURANÇA CRÍTICO
**ESTE SOFTWARE FOI PROJETADO PARA AGIR COMO UM MALWARE EXPERIMENTAL.**

* **APENAS EM VM:** Este programa **NUNCA** deve ser executado em seu computador físico (Host). Ele foi desenvolvido para rodar exclusivamente em ambientes virtuais isolados.
* **DANOS PERMANENTES:** O software irá modificar, ocultar e deletar arquivos dentro da VM. No final do ciclo, o sistema operacional da VM será inutilizado (Shutdown permanente).
* **ISENÇÃO DE RESPONSABILIDADE:** Sob os termos da **Licença MIT**, o autor não se responsabiliza por quaisquer danos causados por uso negligente fora de uma Máquina Virtual. Você o executa por sua conta e risco.

---

## 🖥️ Compatibilidade e Trava de Segurança
Para evitar acidentes, o executável possui uma trava de hardware em C++ que detecta o ambiente. O BrokenScript **só funcionará** se detectar:

* **[Oracle VM VirtualBox](https://www.virtualbox.org/wiki/Downloads)**
* **[VMware Workstation](https://www.vmware.com/products/desktop-hypervisor/workstation-and-fusion)**
* **[QEMU](https://www.qemu.org/download/)**

*Se executado em hardware real, o programa encerrará o processo imediatamente para proteger seu PC.*

---

## 🌑 A Progressão da Paranoia
A experiência foi desenhada para ser lenta e perturbadora:

1.  **Fase de Latência:** O programa se instala na inicialização. Pequenas alterações em arquivos começam a ocorrer.
2.  **Fase de Vigilância:** O LED da webcam pisca aleatoriamente. Arquivos deletados retornam sozinhos.
3.  **Fase de Interação:** Notificações do sistema exibem mensagens ambíguas. Janelas fecham sozinhas.
4.  **O Evento Final (Dia 180):** O ciclo termina. O Windows é desligado e o registro de boot é comprometido.

---

## 🛠️ Detalhes Técnicos
* **Linguagem:** C++ (Win32 API)
* **Licença:** MIT
* **Persistência:** O software cria uma entrada no Registro do Windows (`HKCU\Software\Microsoft\Windows\CurrentVersion\Run`) para garantir a continuidade da experiência.

---

## ⬇️ Como Instalar
1. Baixe a release mais recente (Dentro da VM)
2. Execute o **TheBrokenScript_WinVersion.exe** como Admin
3. Concorde com os termos e click para instalar
4. Tudo pronto para sua experiencia

### ✍️ Créditos
* Créditos totais aos criadores originais de The Broken Script: **wedigodrip** & **redstonewizard**
* Eles quem tiveram a ideia original, eu só adaptei para Windows
