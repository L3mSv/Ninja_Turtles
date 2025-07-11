# Ninja Turtles Game in Terminal (CLI)

![ninja-turtle-pixel](images/ninjas.png)

## Programmers
- [Lucas Lemes](https://github.com/L3mSv) 
- Felipe 

## Introduction
O objetivo deste projeto é construir um jogo das tartarugas ninjas no terminal, você o **jogador** irá ajudar as tartarugas a restaurarem a paz na cidade de Nova York dando suporte a elas em batalhas contra seus vilões dos desenhos mais marcantes como _O Destruidor_, _Krang_, _Clã do Pé_, _Bebop_ e _Rocksteady_ e outros novos inimigos, por meio de um sistema de computador avançado construido pelo _Donatello_ chamado de **A Central de Comando**, onde você irá gerenciar as missões, catalogar os vilões e otimizar as operações do time.

## Descrição Funcional do Sistema

### 1.Entidades do Sistema:

:pizza: ***Tartaruga:***<br/>
- **Nome:** Leonardo, Donatello, Raphael, Michelangelo<br/>
- **Status:** Disponível, Em Missão, Ferido.<br/>
- **Nível:** 1-10<br/>

:pizza: ***Vilão:***<br/>
- **Nome:** Destruidor, Krang, Bebop, etc...<br/>
- **Nível:** 1-10<br/>
- **Ponto Fraco**: texto<br/>

:pizza: ***Missão:***<br/> 
- **Descrição:** Assalto ao Banco Central, Sequestro do presidente, etc...<br/>
- **Local:** Centro da cidade, Casa branca, etc...<br/>
- **Nível:** 1-10<br/>
>OBS: Descrição de missões e seus respectivos níveis de ameaça são aleatórios, não há um padrão neles.

:pizza: ***Equipamento:***<br/>
- **Nome:** Katanas, Bō, Nunchakus, Sai, Bumerangue-Pizza, Comunicador-Casco<br/>


### 2. Módulos da Central de Comando:
Aqui estão as funcionalidades que sua Central de Comando deve ter.<br/>

#### :pizza: (Módulo 2.1) O Painel de Alertas de Missões

Novas missões são reportadas para a Central a todo momento.<br/>
Elas chegam de fontes como April O'Neil ou de scanners da polícia.<br/>

#### :pizza: (Módulo 2.2) Os Arquivos de Vilões do Donatello

Donatello mantém um banco de dados sobre cada vilão que já enfrentaram.<br/>

Tornando possível buscar informações sobre um vilão, pois as Tartarugas
podem precisar consultar informações sobre um inimigo no meio de uma
batalha.

#### :pizza: (Módulo 2.3) O Diário de Bordo do Mestre Splinter

Mestre Splinter exige um relatório de todas as missões concluídas para
analisar o desempenho de seus filhos.

#### :pizza: (Módulo 2.4) O Arsenal e o Plano de Ação

Para cada missão iniciada, as Tartarugas precisam de um plano. O jogador deve poder montar uma lista de equipamentos do arsenal para levar aquela missão específica.⠀⠀⠀⠀

## Mecânica de Batalhas⠀⠀⠀⠀⠀⠀

A batalha não é algo que o jogador "joga", mas sim um evento que o programa resolve com base em uma
estratégia denida na implementação. O processo é dividido em duas fases: Preparação e Resolução.

### 1. Fase de Preparação⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

Antes de a batalha ser resolvida, o jogador usa a Central de Comando para se preparar:<br/>

:pizza: Escolhe a Missão<br/>
:pizza: Consulta os Arquivos dos Vilões<br/>
:pizza: Monta a Equipe<br/>
:pizza: Seleciona o Equipamento(até dois)<br/>

### 2. Fase de Resolução

Uma vez que o jogador envia a equipe, o programa calcula o resultado instantaneamente.<br/>
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
>![NOTE] 
> _Força da Equipe:_ Calculada a partir da média da habilidade dos membros
>da equipe. Quando um membro da equipe está equipado com a sua arma
>favorita (Leonardo - Katanas; Donatello - Bō; Michelangelo - Nunchakus;
>Raphael - Sai) é somado uma habilidade bônus de +0.5 a força da equipe.

:pizza: ***Vencedor (com um fator de sorte):***

O programa calcula o resultado com uma fórmula simples, 
adicionando um pequeno elemento aleatório para simular o caos de uma luta.

- Resultado Final = Força da Equipe - Nível de Desao + Sorte (um número 
aleatório de -2 a +2) - Caos Mutante (número aleatório entre
1 e 0)

:pizza: ***As Consequências (O Resultado da batalha):***

Com base no Resultado Final, o sistema determina o que aconteceu e atualiza o estado do jogo.

- Se Resultado Final for alto (ex: > 3): Vitória Perfeita!
    - A missão é considerada um sucesso e movida para o Diário de Bordo do Mestre Splinter _(a pilha de missões concluídas)_.
    - Todas as Tartarugas da equipe retornam com o status *"Disponível"* e aumentam seu nível em *+0.3*.

- Se Resultado Final for médio (ex: de 0 a 3): Vitória com Custo.
    - A missão é um sucesso e vai para o Diário de Bordo.
    - Porém, uma das Tartarugas se feriu! Seu status muda para *"Ferido"* e ela fica indisponível pelas próximas 2 missões.
    - Tartarugas que não se feriram aumentam seu nível em *+0.2*.

- Se Resultado Final for baixo (ex: < 0): Derrota!
    - A missão falhou. Ela não vai para o Diário de Bordo. _(Pode até voltar para o painel de alertas)_.
    -Toda a equipe enviada retorna com o status *"Ferido"* e fica indisponível por um tempo _(definido pelo programador)_. Não há aumento de nível nesse caso.










⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⠀⠀⠀⠀⠀⠀⠀⠀⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣽⡯⡝⡿⢿⢇⣀⣀⣀⣸⣿⣹⣺⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣟⢜⣮⡇⡟⣟⢿⡻⡟⡟⡟⣟⢯⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⢯⣺⡸⢽⡳⡕⣕⢵⢱⢝⢜⢎⢮⢫⢿⣆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡪⣣⢣⡳⡵⣕⡧⡯⣮⡣⣳⢵⣣⢿⣗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡿⣪⡎⡮⡪⠈⠈⢸⣿⣾⣞⢼⣿⠈⢹⣗⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣴⣿⣏⢮⢺⢤⠀⠈⠛⠛⢱⠝⠛⢤⣺⣿⣿⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣷⣷⢯⡫⡝⡾⣷⣱⢕⢵⣱⣱⣱⢕⢇⢧⣓⣎⣞⢿⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡒⣕⢵⢱⢕⢵⢸⠻⣮⡟⡟⡟⡟⣯⣮⣮⢟⢿⣗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣞⢝⢼⣸⣘⣮⣿⡧⡣⡫⢝⢵⡫⣗⢯⢭⢹⣿⡣⡫⡳⡷⣷⢇⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣤⣿⣗⢝⢜⢞⢿⣿⣿⣇⢏⡎⣇⢇⢇⢇⢇⢇⢿⣿⢪⢪⢺⡸⡜⡽⣳⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣀⣶⣟⣟⣽⢿⣗⡵⣹⣜⢽⢿⣿⡷⡷⣟⡾⡾⡾⡾⡾⡷⣿⣿⣱⡱⣕⡕⣗⣇⣗⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠨⣿⣮⣻⣿⠛⣻⣾⣻⣿⡛⢣⣤⡟⡗⡵⡱⡕⡵⡱⡱⡱⡕⡵⡻⣿⣿⣿⣪⣷⡝⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⠉⡾⡎⠉⠀⢿⢗⣗⣿⣶⡮⠩⡺⡸⡪⡺⡜⡎⡕⣕⢵⢹⢸⢱⠩⣹⣿⡪⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣼⣿⡟⡿⡫⣔⠠⢂⢸⣼⢮⢮⣮⣮⣮⡆⡐⡐⡔⣼⣿⡺⣿⣧⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣏⢏⡟⣜⢎⡇⣗⢜⣲⣸⣿⣿⠍⠉⠉⣿⡗⣆⢖⣕⣽⣿⡺⣿⣟⢵⣶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⠻⠛⠟⠛⠟⠻⠛⠟⠛⠛⠛⠀⠀⠀⠀⠻⠛⠟⠛⠛⠛⠛⠛⠟⠻⠛⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀