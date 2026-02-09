#include "verificacoes.h"

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	// Bem Vindo Tab
	system("cls");
	printf("Bem Vindo ao Instalador do TBS_WinVersion\n");
	printf("==============================================\n\n");
	printf("Aqui você instala-rá o seu TBS_WinVersion.  Assim você podera instalar e usufluir da experiência de terror\n\n");

	system("pause");

	// Termos de Uso
	system("cls");
	printf("Termos de Uso\n");
	printf("==============================================\n\n");
	printf("Ao instalar o TBS_WinVersion, você concorda com os seguintes termos de uso: \n");

	const char* termos = R"(
Termos de Uso
============================================================

Ao instalar o TBS_WinVersion, voce concorda com os seguintes termos:

1. ISENÇÃO DE RESPONSABILIDADE:
   Sob a Licença MIT, este software é fornecido "como está".
   O autor não se responsabiliza por qualquer dano ao sistema.

2. AMBIENTE DE EXECUÇÃO:
   Este programa simula malware e DEVE ser rodado apenas em VM.
   O uso em hardware real é de sua inteira responsabilidade.

3. COMPORTAMENTO:
   O software modificará arquivos e inutilizará o sistema 
   operacional da VM após o ciclo de 180 dias.

============================================================
)";

	std::cout << termos << std::endl;

	system("pause");

	// Verificações para Instalação Tab
	system("cls");
	printf("Verificações para Instalação\n");
	printf("==============================================\n\n");

	std::vector<std::string> verificacoes = verificacoes_gerais();

	if (verificacoes.empty()) {
		printf("Todas as verificações foram concluídas com sucesso. Você pode prosseguir com a instalação.\n\n");
	}
	else {
		printf("As seguintes verificações falharam:\n");
		for (const std::string& verificacao : verificacoes) {
			printf("- %s\n", verificacao.c_str());
		}
		printf("\nPor favor, corrija os problemas acima e tente novamente.\n\n");
		system("pause");
		return 1;
	}

	system("pause");

	// Instalação Tab
	system("cls");
	printf("Instalação em Andamento\n");
	printf("==============================================\n\n");

	fs::path destinoPath = "C:\\TBS_WinVersion";

	fs::path pastaDependenciasPath = "Resources";
	fs::path exePath = "TBS_WinVersion.exe";

	if (!fs::exists(pastaDependenciasPath)) {
		printf("[ERRO] Pasta 'Resources' não encontrada!\n");
	}
	else if (!fs::exists(exePath)) {
		printf("[ERRO] Executável 'TBS_WinVersion.exe' não encontrado!\n");
	}
	else {
		printf("[1/3] Verificando integridade dos arquivos...\n");
		if (!fs::exists(destinoPath)) {
			fs::create_directory(destinoPath);
		}

		printf("[2/3] Copiando aqrquivos...\n");
		fs::copy(pastaDependenciasPath, destinoPath / pastaDependenciasPath.filename(), fs::copy_options::recursive);
		fs::copy(exePath, destinoPath / exePath.filename(), fs::copy_options::overwrite_existing);
		
		printf("[3/3] Configurando ambiente...\n\n");
		std::string comando = "schtasks /Create /TN \"TBS_AutoStart\" /TR \"'" + (destinoPath / exePath.filename()).string() + "'\" /SC ONLOGON /RL HIGHEST /F";

		int result = system(comando.c_str());

		if (result == 0) {
			printf("Configuração de inicialização concluída!\n");
		}
		else {
			printf("[AVISO] Falha ao configurar inicialização automática. Rode como Admin.\n");
		}

		printf("Sucesso: Instalação concluída com êxito!\n");
	}

	system("pause");

	// Finalização Tab
	system("cls");
	printf("Instalação Concluída\n\n\n");
	system("pause");

	return 0;
}
