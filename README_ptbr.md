# 🎮 so_long

Este é um jogo 2D em homenagem ao **Ayrton Senna** 🏎️ e
desenvolvido como parte do currículo da 42 São Paulo.
  
  ![Grade](https://img.shields.io/badge/Grade-100-sucess)
  ![Language](https://img.shields.io/badge/Language-C-blue)
  ![Norminette](https://img.shields.io/badge/Norminette-Passing-success)
  

---

## 📋 Sobre o Projeto

**So Long** é um jogo 2D desenvolvido em C utilizando a biblioteca gráfica MiniLibX. O objetivo é coletar todos os itens do mapa e escapar pela saída usando o menor número de movimentos possível.

Este projeto faz parte do common core da [42 São Paulo](https://www.42sp.org.br/) e tem como foco o aprendizado de:
- Gerenciamento de janelas e eventos
- Manipulação de texturas e sprites
- Algoritmos de pathfinding e validação de mapas
- Gerenciamento de memória em C

---

## 🎯 Características

### Parte Obrigatória
- ✅ Movimento do personagem com teclas **W, A, S, D**
- ✅ Colisão com paredes
- ✅ Coleta de itens obrigatórios
- ✅ Sistema de saída após coletar todos os itens
- ✅ Contador de movimentos exibido no terminal
- ✅ Validação completa de mapas (.ber)
- ✅ Gerenciamento adequado de memória (sem vazamentos)
- ✅ Tratamento de erros robusto

### Validações de Mapa
O jogo valida os seguintes aspectos do mapa:
- Formato retangular
- Cercado por paredes ('1')
- Contém exatamente 1 jogador ('P')
- Contém pelo menos 1 item coletável ('C')
- Contém exatamente 1 saída ('E')
- Possui caminho válido entre jogador, itens e saída
- Extensão .ber obrigatória

---

## 🚀 Como Jogar

### Pré-requisitos
- Sistema operacional: Linux ou macOS
- Compilador: `gcc` com flags `-Wall -Wextra -Werror`
- MiniLibX instalada

### Compilação
```bash
# Clone o repositório

$>git clone https://github.com/lucabarbosa/so_long.git
$>cd so_long

# Compile o projeto

$>make

# Execute o jogo com um mapa
$>./so_long maps/<escolha um mapa>
```

### Comandos Makefile
```bash
make        # Compila o projeto
make clean  # Remove arquivos objeto
make fclean # Remove executável e arquivos objeto
make re     # Recompila do zero
```

---

## 🗺️ Formato do Mapa

Os mapas devem ter extensão **.ber** e conter apenas os seguintes caracteres:

| Caractere | Significado |
|-----------|-------------|
| `0` | Espaço vazio |
| `1` | Parede |
| `C` | Item coletável |
| `E` | Saída |
| `P` | Posição inicial do jogador |

### Exemplo de Mapa Válido
```
1111111111111
1P01000000001
100001111C001
10001100000E1
1111111111111
```

---

## 🎨 Assets e Design

O projeto utiliza sprites e texturas customizadas que eu mesmo desenhei usando ferramentas de pixelart visando melhorar a experiência visual do jogo. Você pode encontrar:

### 🎮 Gameplay
![Gameplay Screenshot](images/42_game.png)
*O jogo foi pensado para ser uma pista de corrida com o iconico carro de F1 de Ayrton Senna indo até a linha de chegada.*

### 🏁 Victory Screen
Quando voce coleta todos os trofeis e cruza a linha de chegada uma mensagem personalizada aparece no terminal:

![Victory Screen](images/you_won.png)

> *"If a person has no dreams, they no longer have any reason to live."*

Uma homenagem ao maior piloto brasileiro de todos os tempos e um lembrete de que devemos sempre perseguir nossos sonhos.


---

## 📁 Estrutura do Projeto

```
so_long/
├── src/                  # Código-fonte principal
│   ├── main.c
│   ├── map_validation.c
│   ├── game_loop.c
│   ├── player_movement.c
│   └── ...
├── mlx/                  # MiniLibX (biblioteca gráfica da 42)
├── images/               # Screenshots e assets visuais
├── maps/                 # Mapas de teste (.ber)
├── includes/             # Headers (.h)
├── Makefile
└── README.md
```

---

## 🎮 Controles

| Tecla | Ação |
|-------|------|
| **W** ou **↑** | Mover para cima |
| **A** ou **←** | Mover para esquerda |
| **S** ou **↓** | Mover para baixo |
| **D** ou **→** | Mover para direita |
| **ESC** | Fechar o jogo |

---

## 🧪 Testando o Jogo

### Testes Recomendados
1. **Mapas válidos**: Teste diferentes tamanhos e configurações
2. **Mapas inválidos**: Verifique tratamento de erros
   - Sem caminho válido
   - Sem itens coletáveis
   - Múltiplos jogadores ou saídas
   - Não retangular
   - Não cercado por paredes
3. **Colisões**: Tente mover através de paredes
4. **Contador de movimentos**: Verifique se incrementa corretamente
5. **Memória**: Use Valgrind para detectar vazamentos

```bash
# Exemplo de teste com Valgrind
valgrind --leak-check=full ./so_long maps/map.ber
```

---

## 📚 Conceitos Aplicados

### Algoritmos
- Flood Fill para validação de caminhos
- Sistema de colisão tile-based
- Parsing e validação de arquivos

### Gerenciamento Gráfico
- Renderização de sprites com MiniLibX
- Sistema de coordenadas 2D
- Event handling (teclado e janela)

### Boas Práticas
- Código modular e organizado
- Conformidade com a Norminette (42)
- Gerenciamento adequado de memória
- Tratamento de erros consistente

---

## 🐛 Tratamento de Erros

O programa exibe `"Error\n"` seguido de uma mensagem específica para:
- Arquivo de mapa não encontrado
- Extensão incorreta (não .ber)
- Mapa com caracteres inválidos
- Mapa não retangular
- Falta de elementos obrigatórios
- Duplicação de jogador/saída
- Caminho inválido entre elementos
- Mapa não cercado por paredes

---

## 📖 Recursos e Referências

### Documentação Oficial
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 Norminette](https://github.com/42School/norminette)

### Assets Gráficos
- [itch.io](https://itch.io/) - Sprites e tilesets gratuitos
- [OpenGameArt](https://opengameart.org/) - Assets open source

### Tutoriais Úteis
- Guias sobre a MiniLibX
- Algoritmos de pathfinding

---

## 📝 Licença

Este projeto foi desenvolvido para fins educacionais como parte do currículo da 42 São Paulo.

---

## 🙏 Agradecimentos

- À **42 São Paulo** pela oportunidade de aprendizado
- Aos **colegas** que ajudaram com peer reviews e debugging
- À comunidade **42** por compartilhar conhecimento


---

#### **"So Long, and Thanks for All the Fish!"** 🐬🐟