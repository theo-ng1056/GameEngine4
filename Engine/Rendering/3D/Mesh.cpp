#include "Mesh.h"

//                                                                    emty vector
Mesh::Mesh(vector<Vertex>& vertexList_) : VAO(0), VBO(0), vertexList(vector<Vertex>())
{
	vertexList = vertexList_;
	GenerateBuffers();
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	vertexList.clear();
}

void Mesh::Render()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, vertexList.size());
	
	glBindVertexArray(0);
}

void Mesh::GenerateBuffers()
{
	glGenVertexArrays(1, &VAO); // create VAO
	glGenBuffers(1, &VBO); // create VBO
	glBindVertexArray(VAO); // bind VAO to GPU
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind VBO to GPU as buffer
	//            buffer type   / size of array = vector size*byte size of each vertex element                      
	glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(Vertex),                           &vertexList[0], GL_STATIC_DRAW);

	//POSITION
	glEnableVertexAttribArray(0); // fisrt
	//                   lcation / size of vertex (vec3) / <-3 float values / normalize? /space between vertecies, 
	glVertexAttribPointer(  0,             3,               GL_FLOAT,       GL_FALSE,      sizeof(Vertex),       (GLvoid*)0);
	
	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	//TEX COORDS
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoordinates));

	//COLOUR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}