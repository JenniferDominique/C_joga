# :building_construction: Jogo da Forca

O computador escolherá, de maneira randômica, uma palavra que está salva em um arquivo de palavras, e o jogador deve chutar, letra por letra, até adivinhar a palavra. Se o jogador chutar 5 letras erradas, ele perde. Ao final, o computador oferecerá a possibilidade do usuário inserir uma nova palavra no banco de dados.
E aí, aceita o desafio de acertar a palavra secreta antes que você seja enforcado?

Para compilar e executar o programa siga os seguintes passos:

1. Clone o repositório:

```
git clone https://github.com/JenniferDominique/C_joga.git
```

2. Tenha o compilador gcc instalado na sua máquina. Se você ainda não tem, pode baixar pelo seguinte [link](https://www.mingw-w64.org).<br>

3. No terminal dentro da pasta do projeto `.\Forca`, compile o projeto com o seguinte comando:

   :window: Windowns:
```
  gcc .\forca.c -o .\forca.exe
```

   :penguin: Linux:
```
  gcc -o forca forca.c
```

   :apple: Mac:
```
  gcc .\forca.c -o .\forca.out
```

4. Depois de ter compilado o código, execute o programa com o seguinte código:
   :window: Windows:
```
  .\forca.exe
```

   :penguin: Linux:
```
  ./forca
```

   :apple: Mac:
```
  .\forca.out
```

5. Agora se divirta tentando adivinhas a palavra secreta. :video_game:

## :book: Material de estudo
- [Alura](https://cursos.alura.com.br) 
  - [C II: Avançando na linguagem](https://cursos.alura.com.br/course/introducao-a-programacao-com-c-parte-2)