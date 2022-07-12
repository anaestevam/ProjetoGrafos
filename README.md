# ProjetoGrafos
 Disciplina de Grafos 2022.1

Para o código implementado, foi utilizado o seguinte grafo abaixo:

<p align="center">
  <img src="https://github.com/anaestevam/ProjetoGrafos/blob/main/img/graph.jpeg">
</p>

Na imagem, existem três componentes no grafo, que no código está apresentado através de uma Matriz de Adjacência, os componentes, chamaremos de A, B e C. 
No componente A os caminhos mais curtos são:
- A distância mais curta entre 4 e 5 é igual a 5.
- A distância mais curta entre 4 e 2 é 1+5 = 6.
- A distância mais curta entre 4 e 6 é 5+3 = 8.
- A distância mais curta entre 2 e 5 é 1.
- A distância mais curta entre 2 e 6 é 1+3 = 4.
- A distância mais curta entre 5 e 6 é de 3.

Em B a distância mais curta entre 3 e 7 é 11. E por fim, o C que contém apenas o vértice 8, será igual a 0.
	
` Sendo assim, a distância máxima mais curta no componente A é de 8 entre o nó 4 e o nó 6. Da mesma forma, a distância máxima mais curta no componente B é 0. E a distância máxima mais curta no componente C é de 11 entre os nós 3 e 7. `

