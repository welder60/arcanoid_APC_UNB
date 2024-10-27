# 🎮 Projeto Final APC - Jogo de Quebra de Blocos

## 🏫 Universidade de Brasília  
**Disciplina**: Algoritmos e Programação de Computadores - 2024  
**Professor**: Clênio Emídio  
**Aluno**: Welder Rodrigues de Medeiros - 241012409  

---

## 📝 Descrição do Projeto

Este é o projeto final da disciplina APC, um jogo em C inspirado no clássico "Breakout". O jogador controla uma barra para rebater uma bola e quebrar blocos no topo da tela. O objetivo é destruir todos os blocos sem deixar a bola cair.

## ⚙️ Funcionalidades

- **Controles**:  
  - ⬅️➡️: Move a barra.
  - ⏸️ **ESPAÇO**: Ativa o modo automático.
  - ⚫ **F1**: Ativa o modo preto e branco.

- **Dificuldade**:  
  Ajustável pela constante `DIFICULDADE` no código, que controla a velocidade da bola e o desafio dos níveis.

- **Elementos do Jogo**:  
  - 🟦 **Barra**: Controlada pelo jogador para rebater a bola.
  - ⚪ **Bola**: Rebate nas bordas e na barra, destruindo blocos ao contato.
  - 🟥 **Blocos**: Dispostos em um array bidimensional, representando o campo de jogo.

## 🛠️ Como Compilar e Executar

1. **Pré-requisitos**: É necessário um compilador de C, como GCC, e uma IDE compatível, como Code::Blocks.
2. **Compilação**: Compile o código usando um comando como `gcc main.c -o jogo`.
3. **Execução**: Rode o jogo com `./jogo` no terminal.

## 📂 Estrutura do Código

- `main.c`: Arquivo principal que contém a lógica do jogo.
- `desenho.h`: Biblioteca auxiliar para desenhos e layouts na tela.
- Variáveis globais e macros configuráveis para ajustar o comportamento do jogo.

## 🚀 Melhorias Futuras

- 🔢 Adicionar níveis progressivos.
- 🏆 Implementar pontuação e sistema de vidas.
- 🎨 Criar uma interface gráfica com cores e animações adicionais.

---

### 🔍 Termos de Busca

- "Block Breaker game C language tutorial"
- "Breakout game C programming"
- "Beginner game development C language"
- "Simple game mechanics in C language"
