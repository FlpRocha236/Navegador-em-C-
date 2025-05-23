
# 🚀 Simulador de Navegador Web – Estrutura de Dados em C++

### 📚 Disciplina: Estrutura de Dados  
### 🎯 Curso: Desenvolvimento de Software Multiplataforma (2º semestre)  
### 👨‍💻 Autor: Felipe Rocha  

---

## 📝 Descrição do Projeto

Este projeto simula o comportamento básico de um navegador web, permitindo ao usuário:

- Acessar novas páginas;
- Voltar para páginas anteriores;
- Avançar para páginas seguintes (quando houver);
- Visualizar o histórico completo de navegação.

O sistema foi desenvolvido em **C++**, sem utilização de bibliotecas da STL para estruturas de dados, implementando manualmente uma **lista encadeada simples** (para o histórico) e duas **pilhas** (para navegação: voltar e avançar).

---

## 🏗️ Estruturas de Dados Implementadas

### 🔗 Lista Encadeada
- Utilizada para armazenar o **histórico completo** de páginas acessadas.
- Cada nó da lista contém:
  - O nome/URL da página.
  - Ponteiro para o próximo nó.

### 🗂️ Pilha
- Duas pilhas foram implementadas:
  - **Pilha Voltar:** Armazena as páginas anteriores.
  - **Pilha Avançar:** Armazena as páginas futuras após o comando "voltar".
- Ambas são pilhas encadeadas, implementadas manualmente.

---

## ⚙️ Funcionalidades do Sistema

| Opção | Descrição |
|-------|-----------|
| 1 | **Acessar nova página:** Empilha a página atual na pilha de voltar, limpa a pilha de avançar e adiciona a nova página ao histórico. |
| 2 | **Voltar:** Move a página atual para a pilha de avançar e retorna para a página anterior da pilha de voltar. |
| 3 | **Avançar:** Move a página atual para a pilha de voltar e avança para a próxima página na pilha de avançar. |
| 4 | **Exibir histórico:** Mostra todas as páginas acessadas desde o início da navegação. |
| 5 | **Sair:** Encerra o programa e libera toda a memória alocada. |

---

## 💡 Conceitos Praticados

- Alocação e desalocação dinâmica de memória com `new` e `delete`.
- Implementação de pilhas e listas encadeadas manualmente.
- Manipulação de ponteiros.
- Simulação de um sistema real usando estruturas de dados.
- Organização de código de forma estruturada e legível.

---

## 🚀 Como Executar o Projeto

1. Clone ou baixe este repositório.
2. Compile o arquivo:

```bash
g++ mainNav.cpp -o navegador
```

3. Execute:

```bash
./navegador
```

> 🛠️ **Obs.:** Se preferir, utilize uma IDE como Code::Blocks, Dev-C++ ou Visual Studio.

---

## 📂 Estrutura dos Arquivos

```
/projeto-navegador
├── mainNav.cpp       // Arquivo principal com o código-fonte
├── README.md         // Documentação do projeto
├── navegador.exe         // Arquivo executável do projeto
├── navegador.dev         // Arquivo de compilação do projeto
├── navegador.layout         // Layout de interface utilizado no DevC++
├── mainNav.o         // Arquivo objeto do compilador
```

---

## 🏆 Créditos

Projeto desenvolvido para a disciplina de **Estrutura de Dados**, como parte da formação no curso de **Desenvolvimento de Software Multiplataforma - 2º semestre** na **FATEC Araras**.

---

## 🔗 Licença

Este projeto é de uso acadêmico e livre para fins educacionais.
