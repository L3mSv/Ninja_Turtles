# Ninja Turtles Game in Terminal (CLI)

![ninja-turtle-pixel](images/ninjas.png)

## Programmers
- [Lucas Lemes](https://github.com/L3mSv) 
- Felipe 

## Introduction
O objetivo deste projeto é construir um jogo das tartarugas ninjas no terminal, você o **jogador** irá ajudar as tartarugas a restaurarem a paz na cidade de Nova York dando suporte a elas em batalhas contra seus clássicos vilões dos desenhos como _O Destruidor_, _Krang_, _Clã do Pé_, _Bebop_ e _Rocksteady_ e outros novos inimigos, por meio de um sistema de computador avançado construido pelo _Donatello_ a **Central de Comando**, onde você irá gerenciar as missões, catalogar os vilões e otimizar as operações do time.

## Descrição Funcional do Sistema

***1.Entidades do Sistema:***

:pizza: Tartaruga:<br/>
- **Nome:** Leonardo, Donatello, Raphael, Michelangelo<br/>
- **Status:** Disponível, Em Missão, Ferido.<br/>
- **Nível:** 1-10<br/>

:pizza: Vilão:<br/>
- **Nome:** Destruidor, Krang, Bebop, etc...<br/>
- **Nível:** 1-10<br/>
- **Ponto Fraco**: texto<br/>

:pizza: Missão:<br/> 
- **Descrição:** Assalto ao Banco Central, Sequestro do presidente, etc...<br/>
- **Local:** Centro da cidade, Casa branca, etc...<br/>
- **Nível:** 1-10<br/>
>OBS: Descrição de missões e seus respectivos níveis de ameaça são aleatórios, não há um padrão neles.

:pizza: Equipamento:<br/>
- **Nome:** Katanas, Bō, Nunchakus, Sai, Bumerangue-Pizza, Comunicador-Casco<br/>


***2. Módulos da Central de Comando:***
<br/>Aqui estão as funcionalidades que sua Central de Comando deve ter.<br/>

- :pizza: ***Módulo 2.1: O Painel de Alertas de Missões***

    Novas missões são reportadas para a Central a todo momento.<br/>
    Elas chegam de fontes como April O'Neil ou de scanners da polícia.<br/>

- :pizza: ***Módulo 2.2: Os Arquivos de Vilões do Donatello***

    Donatello mantém um banco de dados sobre cada vilão que já enfrentaram.<br/>

    Tornando possível buscar informações sobre um vilão, pois as Tartarugas
    podem precisar consultar informações sobre um inimigo no meio de uma
    batalha.

- :pizza: ***Módulo 2.3: O Diário de Bordo do Mestre Splinter***

    Mestre Splinter exige um relatório de todas as missões concluídas para
    analisar o desempenho de seus filhos.

- :pizza: ***Módulo 2.4: O Arsenal e o Plano de Ação***

    Para cada missão iniciada, as Tartarugas precisam de um plano.<br/>
    A jogador deve poder montar uma lista de equipamentos do arsenal para levar àquela missão especíca.⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀






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